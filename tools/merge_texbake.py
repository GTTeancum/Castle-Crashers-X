# SPDX-License-Identifier: MIT
"""Merge baked texture packs (runtime021 CC_TEX_BAKE output, "TXB1").

usage: merge_texbake.py <out.pak> <in.pak>...

Entries {u32 key0, full, len, w, h, offset} (little-endian) are combined,
duplicates (same key0 and full key) kept once, sorted by key0 as the
loader's binary search expects, and the DXT5 pixels rewritten after the
index.
"""
import struct
import sys


def read_pack(path):
    d = open(path, "rb").read()
    if d[:4] != b"TXB1":
        raise SystemExit("%s: not a texture pack" % path)
    n = struct.unpack_from("<I", d, 4)[0]
    out = []
    for i in range(n):
        key0, full, ln, w, h, off = struct.unpack_from("<6I", d, 8 + 24 * i)
        out.append((key0, full, ln, w, h, d[off:off + w * h]))
    return out


def main(argv):
    out_path, ins = argv[0], argv[1:]
    seen, entries = set(), []
    for p in ins:
        for e in read_pack(p):
            if (e[0], e[1]) in seen:
                continue
            seen.add((e[0], e[1]))
            entries.append(e)
    entries.sort(key=lambda e: e[0])
    offset = 8 + 24 * len(entries)
    with open(out_path, "wb") as f:
        f.write(b"TXB1" + struct.pack("<I", len(entries)))
        for key0, full, ln, w, h, px in entries:
            f.write(struct.pack("<6I", key0, full, ln, w, h, offset))
            offset += len(px)
        for e in entries:
            f.write(e[5])
    print("%s: %d textures, %d bytes" % (out_path, len(entries), offset))


if __name__ == "__main__":
    main(sys.argv[1:])
