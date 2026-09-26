#!/usr/bin/env python3
"""Produce a conservative header/import/string inventory from XEX and mapped PE.
No function-name recovery or exhaustive control-flow analysis is claimed.
"""
from __future__ import annotations
import argparse
import csv
import hashlib
import json
from pathlib import Path
import re
import struct

def analyze(xex_path: Path,image_path: Path,out: Path) -> dict:
    b=xex_path.read_bytes();image=image_path.read_bytes();out.mkdir(parents=True,exist_ok=True)
    def be(o: int,n: int=4) -> int:
        if o<0 or o+n>len(b):raise ValueError('XEX read exceeds bounds')
        return int.from_bytes(b[o:o+n],'big')
    if b[:4]!=b'XEX2' or image[:2]!=b'MZ':raise ValueError('Incorrect input signature')
    opts={be(24+i*8):be(28+i*8) for i in range(be(20))}
    base=opts[0x10201];entry=opts[0x10100]
    pe=struct.unpack_from('<I',image,0x3c)[0]
    if image[pe:pe+4]!=b'PE\0\0':raise ValueError('Invalid mapped PE')
    machine,nsec,timestamp,_,_,optlen,flags=struct.unpack_from('<HHIIIHH',image,pe+4)
    sections=[];table=pe+24+optlen
    for i in range(nsec):
        o=table+40*i;name=image[o:o+8].split(b'\0')[0].decode('ascii')
        vsize,rva,rawsize,raw=struct.unpack_from('<IIII',image,o+8)
        sections.append(dict(name=name,virtual_size=vsize,rva=rva,raw_size=rawsize,raw_offset=raw,flags=f'{struct.unpack_from("<I",image,o+36)[0]:08X}'))
    text=next(s for s in sections if s['name']=='.text');pd=next(s for s in sections if s['name']=='.pdata')
    starts=[]
    if pd['virtual_size']%8:raise ValueError('Unexpected .pdata size')
    for o in range(pd['rva'],pd['rva']+pd['virtual_size'],8):
        address,packed=struct.unpack_from('>II',image,o)
        starts.append(dict(metadata_address=f'0x{base+o:08X}',candidate_start=f'0x{address:08X}',packed_metadata=f'0x{packed:08X}',in_text=base+text['rva']<=address<base+text['rva']+text['virtual_size']))
    with (out/'pdata_candidates.csv').open('w',newline='') as f:
        w=csv.DictWriter(f,fieldnames=list(starts[0]));w.writeheader();w.writerows(starts)
    imports=[];i=opts[0x103ff];end=i+be(i);string_len=be(i+4);lib_count=be(i+8)
    names=[n.decode('ascii') for n in b[i+12:i+12+string_len].split(b'\0') if n];p=i+12+string_len
    for _ in range(lib_count):
        size=be(p);name_index=be(p+36,2);count=be(p+38,2)
        if size!=40+4*count or p+size>end:raise ValueError('Import library size inconsistent')
        records=[]
        for j in range(count):
            address=be(p+40+j*4);rva=address-base
            if rva<0 or rva+4>len(image):raise ValueError('Import record not mapped')
            word=struct.unpack_from('>I',image,rva)[0]
            records.append(dict(address=f'{address:08X}',record_type=word>>24,ordinal=word&65535))
        imports.append(dict(library=names[name_index],record_count=count,unique_ordinals=sorted({r['ordinal'] for r in records}),records=records,
                            version_raw=f'{be(p+28):08X}',minimum_version_raw=f'{be(p+32):08X}'))
        p+=size
    if p!=end:raise ValueError('Import table end inconsistent')
    libraries=[];i=opts[0x200ff]
    for p in range(i+4,i+be(i),16):
        libraries.append(dict(name=b[p:p+8].rstrip(b'\0').decode('ascii'),major=be(p+8,2),minor=be(p+10,2),build=be(p+12,2),qfe_approval_raw=f'{be(p+14,2):04X}'))
    needles=('FlashParser','ActionScript','VectorRender','PlatformRenderer','InternalFlash','FlashGlobal','FlashController','.pdb','Premultiplied','PreMultiplied','PushShader')
    strings=[]
    for match in re.finditer(rb'[\x20-\x7e]{6,}',image):
        text_value=match.group().decode('ascii')
        if any(n in text_value for n in needles):strings.append(dict(image_offset=f'0x{match.start():X}',guest_address=f'0x{base+match.start():08X}',text=text_value))
    summary=dict(xex_sha256=hashlib.sha256(b).hexdigest(),image_sha256=hashlib.sha256(image).hexdigest(),
        machine=f'0x{machine:04X}',image_base=f'0x{base:08X}',entry_point=f'0x{entry:08X}',
        xex_declared_image_bytes=be(be(16)+4),pe_size_of_image=struct.unpack_from('<I',image,pe+24+56)[0],
        text_bytes=next(s['virtual_size'] for s in sections if s['name']=='.text'),
        pdata_record_count=len(starts),pdata_candidates_in_text=sum(s['in_text'] for s in starts),
        unique_library_ordinal_dependencies=sum(len(l['unique_ordinals']) for l in imports),
        libraries=[dict(library=l['library'],records=l['record_count'],unique_ordinals=len(l['unique_ordinals'])) for l in imports],
        static_libraries=libraries,not_a_pc_executable=True,
        caveats=['.pdata entries are candidate function starts, not an exhaustive recovered function list.',
                 'PE section raw offsets differ from mapped-image RVAs. Use RVAs with default.image.bin.',
                 'Strings are identifiers/diagnostics, not recovered C++ symbols or available source.',
                 'Image size is not runtime memory consumption or a recompiled-size estimate.'])
    for name,value in [('binary_analysis.json',summary),('pe_sections.json',sections),('imports.json',imports),('engine_strings.json',strings)]:
        (out/name).write_text(json.dumps(value,indent=2)+'\n')
    return summary

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('xex',type=Path);p.add_argument('image',type=Path);p.add_argument('--reports',required=True,type=Path);a=p.parse_args()
    print(json.dumps(analyze(a.xex,a.image,a.reports),indent=2))
if __name__=='__main__':main()
