#!/usr/bin/env python3
"""Convert Castle Crashers' 360 audio to Xbox ADPCM for the original Xbox port.

The 360 game plays sound effects from game:\\sounds\\<name>.xma (registered by
name through PlatformAudio::RegisterSound, sub_8209EA18) and music from
game:\\music\\<name>.xma (RegisterMusic, sub_8209ED28); the XMA hardware
decodes both. The port plays Xbox ADPCM on the MCPX instead:

  sfx.xab           the 420 game:\\sounds effects, mono, 22,050 Hz (or the
                    source rate when it is lower), looked up by name
  music/<name>.xad  one file per music track, 44,100 Hz stereo, streamed

Inputs are retail data under game-data/extracted/ (never committed); outputs
go to git-ignored game-data/converted/audio/.

sfx.xab layout (little-endian, as the Xbox reads it):
  'XAB2' u32 count, then count entries of
    char name[32] (lower case, no extension, NUL padded),
    u32 rate, u32 channels, u32 samples, u32 offset, u32 bytes
  sorted by name, followed by the ADPCM blocks (offsets from file start).
<name>.xad layout: 'XAD1' u32 rate, u32 channels, u32 samples, then blocks.

Requires ffmpeg on PATH (XMA2 decode) and tools/bin/xadpcm.exe
(build: clang++ -O2 -std=c++17 tools/xadpcm.cpp -o tools/bin/xadpcm.exe).
"""
import glob
import os
import shutil
import struct
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, 'game-data', 'extracted')
OUT = os.path.join(ROOT, 'game-data', 'converted', 'audio')
XADPCM = os.path.join(ROOT, 'tools', 'bin', 'xadpcm.exe')
FFMPEG = shutil.which('ffmpeg')
FFPROBE = shutil.which('ffprobe')
SFX_MAX_RATE = 22050


def run(args):
    subprocess.run(args, check=True)


def probe(path):
    out = subprocess.run([FFPROBE, '-v', 'error', '-show_entries', 'stream=sample_rate,channels',
                          '-of', 'csv=p=0', path], capture_output=True, text=True, check=True)
    rate, channels = out.stdout.strip().split(',')[:2]
    return int(rate), int(channels)


def convert(src, rate, channels, tmp):
    pcm = os.path.join(tmp, 'a.pcm')
    xad = os.path.join(tmp, 'a.xad')
    run([FFMPEG, '-v', 'error', '-y', '-i', src, '-ac', str(channels), '-ar', str(rate),
         '-f', 's16le', pcm])
    run([XADPCM, 'encode', pcm, xad, str(channels)])
    samples = os.path.getsize(pcm) // (2 * channels)
    with open(xad, 'rb') as f:
        return samples, f.read()


def main():
    if not FFMPEG or not FFPROBE or not os.path.exists(XADPCM):
        raise SystemExit('need ffmpeg/ffprobe on PATH and tools/bin/xadpcm.exe')
    os.makedirs(os.path.join(OUT, 'music'), exist_ok=True)
    only = set(sys.argv[1:]) or {'sfx', 'music'}
    with tempfile.TemporaryDirectory(dir=os.path.join(ROOT, 'game-data', 'converted')) as tmp:
        if 'sfx' in only:
            entries = []
            for src in sorted(glob.glob(os.path.join(SRC, 'sounds', '*.xma'))):
                name = os.path.splitext(os.path.basename(src))[0].lower()
                if len(name) >= 32:
                    raise SystemExit('sound name too long: ' + name)
                src_rate, _ = probe(src)
                rate = min(src_rate, SFX_MAX_RATE)
                samples, data = convert(src, rate, 1, tmp)
                entries.append((name, rate, 1, samples, data))
            entries.sort()
            table_size = 8 + 52 * len(entries)
            head = struct.pack('<4sI', b'XAB2', len(entries))
            table, blobs, off = b'', b'', table_size
            for name, rate, ch, samples, data in entries:
                table += name.encode().ljust(32, b'\0') + struct.pack('<5I', rate, ch, samples, off, len(data))
                blobs += data
                off += len(data)
            dst = os.path.join(OUT, 'sfx.xab')
            with open(dst, 'wb') as f:
                f.write(head + table + blobs)
            print('sfx.xab: %d sounds, %.2f MB' % (len(entries), os.path.getsize(dst) / 1e6))
        if 'music' in only:
            total = 0
            for src in sorted(glob.glob(os.path.join(SRC, 'music', '*.xma'))):
                name = os.path.splitext(os.path.basename(src))[0]
                samples, data = convert(src, 44100, 2, tmp)
                dst = os.path.join(OUT, 'music', name + '.xad')
                with open(dst, 'wb') as f:
                    f.write(struct.pack('<4s3I', b'XAD1', 44100, 2, samples) + data)
                total += os.path.getsize(dst)
            print('music: %.1f MB' % (total / 1e6))


if __name__ == '__main__':
    main()
