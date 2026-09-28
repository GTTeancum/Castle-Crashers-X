#!/usr/bin/env python3
"""Convert Castle Crashers' 360 audio to Xbox ADPCM for the original Xbox port.

Inputs (retail data, never committed): game-data/extracted/game/sounds.pak and
game-data/extracted/music/*.xma. Outputs go to game-data/converted/audio/
(git-ignored):

  sfx_swf.xab   the 342 MP3 DefineSound tags of SOUNDS.COK6.BREC's SWF,
                keyed by SWF character id, mono 22,050 Hz
  sfx_rsnd.xab  the 235 SOUNDS.SNDnn.RSND.BREC RIFF PCM sounds, keyed by nn,
                at their own rate (22,050 or 11,025 Hz), mono
  music/<name>.xad  one file per music track, 44,100 Hz stereo

.xab bank layout (little-endian, as the Xbox reads it):
  'XAB1' u32 count, then count entries of
    u32 key, u32 rate, u32 channels, u32 samples, u32 offset, u32 bytes
  followed by the ADPCM data (offsets from the start of the file; every entry
  36-byte-block aligned by construction).
.xad track layout: 'XAD1' u32 rate, u32 channels, u32 samples, then blocks.

Requires ffmpeg on PATH (MP3 and XMA2 decode) and tools/bin/xadpcm.exe
(build: clang++ -O2 -std=c++17 tools/xadpcm.cpp -o tools/bin/xadpcm.exe).
"""
import glob
import os
import shutil
import struct
import subprocess
import sys
import tempfile
import zipfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, 'game-data', 'extracted')
OUT = os.path.join(ROOT, 'game-data', 'converted', 'audio')
XADPCM = os.path.join(ROOT, 'tools', 'bin', 'xadpcm.exe')
FFMPEG = shutil.which('ffmpeg')
SFX_RATE = 22050
BLOCK, SPB = 36, 64


def run(args):
    subprocess.run(args, check=True)


def to_pcm(src_bytes, suffix, rate, channels, tmp, name):
    src = os.path.join(tmp, name + suffix)
    pcm = os.path.join(tmp, name + '.pcm')
    with open(src, 'wb') as f:
        f.write(src_bytes)
    run([FFMPEG, '-v', 'error', '-y', '-i', src, '-ac', str(channels), '-ar', str(rate),
         '-f', 's16le', pcm])
    return pcm


def encode(pcm, channels, tmp, name):
    xad = os.path.join(tmp, name + '.xad')
    run([XADPCM, 'encode', pcm, xad, str(channels)])
    samples = os.path.getsize(pcm) // (2 * channels)
    with open(xad, 'rb') as f:
        return samples, f.read()


def swf_sounds(cok):
    """(character id, raw MP3 frames) for every DefineSound in the bank's SWF."""
    swf = cok[cok.index(b'FWS'):]
    nbits = swf[8] >> 3
    p = 8 + (5 + 4 * nbits + 7) // 8 + 4
    out = []
    while p < len(swf):
        h, = struct.unpack_from('<H', swf, p)
        code, length = h >> 6, h & 63
        p += 2
        if length == 63:
            length, = struct.unpack_from('<I', swf, p)
            p += 4
        body = swf[p:p + length]
        if code == 14:
            cid, = struct.unpack_from('<H', body, 0)
            fmt = body[2] >> 4
            if fmt != 2:
                raise SystemExit('DefineSound %d: format %d is not MP3' % (cid, fmt))
            out.append((cid, body[7 + 2:]))  # skip SampleCount and SeekSamples
        if code == 0:
            break
        p += length
    return out


def write_bank(path, entries):
    head = struct.pack('<4sI', b'XAB1', len(entries))
    table_size = len(head) + 24 * len(entries)
    table, blobs, off = b'', b'', table_size
    for key, rate, ch, samples, data in entries:
        table += struct.pack('<6I', key, rate, ch, samples, off, len(data))
        blobs += data
        off += len(data)
    with open(path, 'wb') as f:
        f.write(head + table + blobs)
    return os.path.getsize(path)


def main():
    if not FFMPEG or not os.path.exists(XADPCM):
        raise SystemExit('need ffmpeg on PATH and tools/bin/xadpcm.exe')
    os.makedirs(os.path.join(OUT, 'music'), exist_ok=True)
    only = set(sys.argv[1:]) or {'swf', 'rsnd', 'music'}
    pak = zipfile.ZipFile(os.path.join(SRC, 'game', 'sounds.pak'))
    with tempfile.TemporaryDirectory(dir=os.path.join(ROOT, 'game-data', 'converted')) as tmp:
        if 'swf' in only:
            entries = []
            for cid, mp3 in swf_sounds(pak.read('SOUNDS.COK6.BREC')):
                pcm = to_pcm(mp3, '.mp3', SFX_RATE, 1, tmp, 'swf%d' % cid)
                samples, data = encode(pcm, 1, tmp, 'swf%d' % cid)
                entries.append((cid, SFX_RATE, 1, samples, data))
            size = write_bank(os.path.join(OUT, 'sfx_swf.xab'), entries)
            print('sfx_swf.xab: %d sounds, %.2f MB' % (len(entries), size / 1e6))
        if 'rsnd' in only:
            entries = []
            for name in pak.namelist():
                if not name.endswith('.RSND.BREC'):
                    continue
                key = int(name.split('.')[1][3:])  # SOUNDS.SNDnn.RSND.BREC
                brec = pak.read(name)
                wav = brec[brec.index(b'RIFF'):]  # 'RSND' cooked header, then RIFF
                rate, = struct.unpack_from('<I', wav, 24)
                pcm = to_pcm(wav, '.wav', rate, 1, tmp, 'rsnd%d' % key)
                samples, data = encode(pcm, 1, tmp, 'rsnd%d' % key)
                entries.append((key, rate, 1, samples, data))
            entries.sort()
            size = write_bank(os.path.join(OUT, 'sfx_rsnd.xab'), entries)
            print('sfx_rsnd.xab: %d sounds, %.2f MB' % (len(entries), size / 1e6))
        if 'music' in only:
            total = 0
            for src in sorted(glob.glob(os.path.join(SRC, 'music', '*.xma'))):
                name = os.path.splitext(os.path.basename(src))[0]
                with open(src, 'rb') as f:
                    pcm = to_pcm(f.read(), '.xma', 44100, 2, tmp, name)
                samples, data = encode(pcm, 2, tmp, name)
                dst = os.path.join(OUT, 'music', name + '.xad')
                with open(dst, 'wb') as f:
                    f.write(struct.pack('<4s3I', b'XAD1', 44100, 2, samples) + data)
                total += os.path.getsize(dst)
            print('music: %.1f MB' % (total / 1e6))


if __name__ == '__main__':
    main()
