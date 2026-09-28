#!/usr/bin/env python3
"""Rewrite game:\\GAME\\SOUNDS.PAK without the unused MP3 payloads.

SOUNDS.PAK is a stored ZIP. Its member SOUNDS.COK6.BREC is a 'COK6' cooked
image around an uncompressed SWF whose 342 DefineSound tags carry 9.8 MB of
MP3 data. The 360 game never plays that data: sound effects are registered by
linkage name and played from game:\\sounds\\<name>.xma (PlatformAudio::
RegisterSound, sub_8209EA18). The game loads the whole member into its main
pool, so the MP3 data costs 9.8 MB of a retail Xbox's 64 MB.

This keeps every tag and every DefineSound header (character id, format
flags, sample count) and empties only the sound data, so every export name
and character id the scripts use is unchanged.

Output: game-data/converted/data/game/sounds.pak (git-ignored), which the
host harness prefers over the original (port data overlay in bridge.cpp).
"""
import os
import struct
import zipfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, 'game-data', 'extracted', 'game', 'sounds.pak')
DST = os.path.join(ROOT, 'game-data', 'converted', 'data', 'game', 'sounds.pak')
BANK = 'SOUNDS.COK6.BREC'
COOK_HEADER = 128


def strip_swf(swf):
    nbits = swf[8] >> 3
    p = 8 + (5 + 4 * nbits + 7) // 8 + 4
    out = bytearray(swf[:p])
    removed = 0
    while p < len(swf):
        h, = struct.unpack_from('<H', swf, p)
        code, length = h >> 6, h & 63
        hp = p
        p += 2
        if length == 63:
            length, = struct.unpack_from('<I', swf, p)
            p += 4
        body = swf[p:p + length]
        if code == 14:
            # SoundId u16, flags u8, SoundSampleCount u32, then SoundData
            # (MP3: SeekSamples s16 + frames). Keep the header and SeekSamples.
            new = body[:9]
            removed += len(body) - len(new)
            out += struct.pack('<HI', (code << 6) | 63, len(new)) + new
        else:
            out += swf[hp:p + length]
        p += length
        if code == 0:
            out += swf[p:]  # trailing cooked bytes after the End tag
            break
    struct.pack_into('<I', out, 4, struct.unpack_from('<I', swf, 4)[0] - removed)
    return bytes(out), removed


def main():
    src = zipfile.ZipFile(SRC)
    bank = src.read(BANK)
    swf, removed = strip_swf(bank[COOK_HEADER:])
    new_bank = bytearray(bank[:COOK_HEADER]) + swf
    # Cooked header: big-endian size at +16 is the image size minus 136 in
    # the retail file; keep that relation.
    assert struct.unpack_from('>I', bank, 16)[0] == len(bank) - 136
    struct.pack_into('>I', new_bank, 16, len(new_bank) - 136)
    os.makedirs(os.path.dirname(DST), exist_ok=True)
    with zipfile.ZipFile(DST, 'w', zipfile.ZIP_STORED) as out:
        for info in src.infolist():
            data = bytes(new_bank) if info.filename == BANK else src.read(info.filename)
            zi = zipfile.ZipInfo(info.filename, date_time=info.date_time)
            zi.compress_type = zipfile.ZIP_STORED
            zi.external_attr = info.external_attr
            zi.create_system = info.create_system
            out.writestr(zi, data)
    print('%s: %d -> %d bytes (%d bytes of MP3 data removed)' %
          (BANK, len(bank), len(new_bank), removed))
    print('sounds.pak: %d -> %d bytes' % (os.path.getsize(SRC), os.path.getsize(DST)))


if __name__ == '__main__':
    main()
