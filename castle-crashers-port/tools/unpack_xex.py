#!/usr/bin/env python3
"""Unpack an AES-encrypted, normal-LZX XEX2 to its mapped PowerPC image.

Requires Python 3.10+, cryptography, and libarchive with CAB/LZX support.
Not a recompiler, signature verifier, license editor, or executable converter.
Format references and public Xenia key source are listed in SOURCES.md.
"""
from __future__ import annotations
import argparse
import ctypes
import ctypes.util
import hashlib
import json
from pathlib import Path
import struct
import sys
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes

class FormatError(ValueError):
    pass

def decrypt(key: bytes, data: bytes) -> bytes:
    if len(data) % 16:
        raise FormatError('AES input is not block aligned')
    ctx = Cipher(algorithms.AES(key), modes.CBC(bytes(16))).decryptor()
    return ctx.update(data) + ctx.finalize()

def decompress_lzx(chunks: list[bytes], image_size: int, window: int) -> bytes:
    if window < 32768 or window > 2097152 or window & (window - 1):
        raise FormatError('Unsupported LZX window')
    if len(chunks) != (image_size + 32767) // 32768 or len(chunks) > 65535:
        raise FormatError('Unexpected LZX frame/image-size relationship')
    record = struct.pack('<IIHHHH', image_size, 0, 0, 0, 0, 0x20) + b'default.exe\0'
    data = b''.join(struct.pack('<IHH', 0, len(c), min(32768, image_size-i*32768)) + c
                    for i,c in enumerate(chunks))
    start = 44 + len(record)
    header = struct.pack('<4sIIIIIBBHHHHH', b'MSCF', 0, start+len(data), 0, 44, 0, 3, 1, 1, 1, 0, 0, 0)
    cab = header + struct.pack('<IHH', start, len(chunks), ((window.bit_length()-1)<<8)|3) + record + data
    library = ctypes.util.find_library('archive')
    if not library:
        raise RuntimeError('libarchive was not found; install a build with CAB/LZX support')
    lib = ctypes.CDLL(library)
    ptr, integer, size = ctypes.c_void_p, ctypes.c_int, ctypes.c_size_t
    for name,args,ret in [
        ('archive_read_new',[],ptr), ('archive_read_support_format_cab',[ptr],integer),
        ('archive_read_open_memory',[ptr,ptr,size],integer),
        ('archive_read_next_header',[ptr,ctypes.POINTER(ptr)],integer),
        ('archive_read_data',[ptr,ptr,size],ctypes.c_ssize_t),
        ('archive_error_string',[ptr],ctypes.c_char_p), ('archive_read_free',[ptr],integer)]:
        func=getattr(lib,name);func.argtypes=args;func.restype=ret
    archive=lib.archive_read_new()
    if not archive:
        raise RuntimeError('libarchive allocation failed')
    def check(result: int) -> None:
        if result < 0:
            error=lib.archive_error_string(archive)
            raise FormatError(error.decode('utf-8','replace') if error else 'libarchive error')
    entry=ptr(); source=ctypes.create_string_buffer(cab)
    try:
        check(lib.archive_read_support_format_cab(archive))
        check(lib.archive_read_open_memory(archive,source,len(cab)))
        check(lib.archive_read_next_header(archive,ctypes.byref(entry)))
        out=bytearray();buf=ctypes.create_string_buffer(65536)
        while True:
            n=lib.archive_read_data(archive,buf,len(buf));check(n)
            if n==0:break
            out+=buf.raw[:n]
            if len(out)>image_size:raise FormatError('Decompression exceeds declared size')
        if len(out)!=image_size or out[:2]!=b'MZ':
            raise FormatError('Decoded image length or PE signature is unexpected')
        return bytes(out)
    finally:
        lib.archive_read_free(archive)

def unpack(path: Path) -> tuple[bytes,dict]:
    b=path.read_bytes()
    def read(o: int,n: int) -> bytes:
        if o<0 or n<0 or o+n>len(b):raise FormatError('XEX header read out of bounds')
        return b[o:o+n]
    def be(o: int,n: int=4) -> int:return int.from_bytes(read(o,n),'big')
    if read(0,4)!=b'XEX2':raise FormatError('Expected XEX2')
    count=be(20)
    if count>4096:raise FormatError('Unreasonable optional header count')
    opts={be(24+i*8):be(28+i*8) for i in range(count)}
    security=be(16);fmt=opts.get(0x3ff)
    if fmt is None:raise FormatError('No file-format optional header')
    image_size=be(security+4)
    if not 1<=image_size<=256*1024*1024:raise FormatError('Image outside probe safety limit')
    encryption,compression=be(fmt+4,2),be(fmt+6,2)
    if encryption!=1 or compression!=2:raise FormatError('Only AES + normal LZX is supported')
    # Public Xenia retail XEX key, not an account credential or per-user secret.
    root_key=bytes.fromhex('20b185a59d28fdc340583fbb0896bf91')
    key=decrypt(root_key,read(security+0x150,16))
    data_offset=be(8)
    plain=decrypt(key,read(data_offset,len(b)-data_offset))
    length=be(fmt+12);digest=read(fmt+16,20);pos=0;chunks=[];blocks=0
    while length:
        if length<26 or pos+length>len(plain):raise FormatError('Compressed block out of bounds')
        block=plain[pos:pos+length]
        if hashlib.sha1(block).digest()!=digest:raise FormatError(f'Compressed block SHA1 mismatch at {blocks}')
        next_length=int.from_bytes(block[:4],'big');next_digest=block[4:24];q=24
        while True:
            if q+2>len(block):raise FormatError('LZX frame header truncated')
            n=int.from_bytes(block[q:q+2],'big');q+=2
            if n==0:break
            if q+n>len(block):raise FormatError('LZX frame truncated')
            chunks.append(block[q:q+n]);q+=n
            if len(chunks)>(image_size+32767)//32768:raise FormatError('Too many LZX frames')
        pos+=length;length=next_length;digest=next_digest;blocks+=1
    out=decompress_lzx(chunks,image_size,be(fmt+8))
    return out,dict(input_sha256=hashlib.sha256(b).hexdigest(),hashed_compressed_blocks=blocks,
        lzx_frames=len(chunks),compressed_bytes=sum(map(len,chunks)),image_size=image_size,
        image_sha256=hashlib.sha256(out).hexdigest(),decompression='libarchive CAB/LZX adapter',
        method='AES-CBC then XEX hash-chain validation and LZX',rsa_signature_checked=False,
        note='Mapped PowerPC image; not a PC executable. Per-page security descriptors were not validated.')

def main() -> int:
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('xex',type=Path);p.add_argument('--output',required=True,type=Path);p.add_argument('--report',required=True,type=Path)
    args=p.parse_args()
    try:
        data,report=unpack(args.xex)
        for dest in (args.output,args.report):dest.parent.mkdir(parents=True,exist_ok=True)
        if args.output.exists() and args.output.read_bytes()!=data:raise FormatError('Refusing to replace different output bytes')
        args.output.write_bytes(data);args.report.write_text(json.dumps(report,indent=2)+'\n')
        print(json.dumps(report,indent=2));return 0
    except (OSError,ValueError,RuntimeError) as e:
        print(f'ERROR: {e}',file=sys.stderr);return 1
if __name__=='__main__':raise SystemExit(main())
