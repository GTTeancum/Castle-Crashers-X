# SPDX-License-Identifier: MIT
"""Turn recorded texture recipes into the installer's texture list.

usage: texrecipe_locate.py [--order <pack>] <game root> <out.txr> <recipe.bin>...

Recipes come from a host bake run with CC_TEX_RECIPE=<file> (runtime021
bodies.inc, cc_bake_record): per texture u32 key0, full, len, w, h, the
596-byte rasterizer job, then max(len, 64) shape bytes (the lookup key
covers 64 bytes even for a short shape, so those pin its location). The shape bytes
sit unchanged inside the game's files (paks are stored ZIPs of uncompressed
SWFs), so each texture is located as (file, offset) under the game root and
the list keeps only that: no game data. Duplicates (same key0 and full) are
kept once. Textures whose shape bytes are found in no file (shapes the game
builds at run time) are reported and left out.

--order: the list follows that pack's pixel layout (its first-use order,
tools/texbake_order.py), which the installer's pack then keeps; textures the
pack lacks follow. It also reports how many of the pack's textures the list
does not cover.

Output "TXR2" (read by the host CC_TEX_REPLAY mode): u32 file count, per file
u16 name length + name (relative, '/' separated); u32 count, per texture u32
key0, full, len, w, h, file, offset, u8 patch count, per patch u8 position
and u8 byte (applied over the bytes copied from the file), then the 596-byte
job.
"""
import os
import struct
import sys


def read_recipes(path):
    d = open(path, "rb").read()
    p = 0
    while p + 20 <= len(d):
        key0, full, ln, w, h = struct.unpack_from("<5I", d, p)
        p += 20
        job = d[p:p + 596]
        p += 596
        span = max(ln, 64)  # key0 covers 64 bytes even for a short shape
        shape = d[p:p + span]
        p += span
        yield key0, full, ln, w, h, job, shape


def locate(blobs, shape, ln):
    """(file, offset, patches): the exact bytes first; else, for a short
    shape, the place whose following bytes differ least (at most 4 bytes:
    the game rewrites the next tag's header in memory once it has read it,
    0x09 -> 0x3F, sometimes for two tags), the differences kept as
    (position, byte) patches."""
    for i, b in enumerate(blobs):
        o = b.find(shape)
        if o >= 0:
            return i, o, []
    if ln >= len(shape):
        return None
    best = None
    for i, b in enumerate(blobs):
        o = b.find(shape[:ln])
        while o >= 0:
            tail = b[o:o + len(shape)]
            if len(tail) == len(shape):
                diff = [(k, shape[k]) for k in range(ln, len(shape)) if tail[k] != shape[k]]
                if len(diff) <= 4 and (best is None or len(diff) < len(best[2])):
                    best = (i, o, diff)
            o = b.find(shape[:ln], o + 1)
    return best


def pack_offsets(path):
    d = open(path, "rb").read()
    n = struct.unpack_from("<I", d, 4)[0]
    return {struct.unpack_from("<2I", d, 8 + 24 * i): struct.unpack_from("<I", d, 8 + 24 * i + 20)[0] for i in range(n)}


def main(argv):
    order = None
    if argv and argv[0] == "--order":
        order = pack_offsets(argv[1])
        argv = argv[2:]
    root, out = argv[0], argv[1]
    names = []
    for dp, _, fs in os.walk(root):
        for f in fs:
            if f.lower().endswith(".pak"):
                names.append(os.path.relpath(os.path.join(dp, f), root).replace("\\", "/"))
    names.sort()
    blobs = [open(os.path.join(root, n), "rb").read() for n in names]
    seen = set()
    found = {}  # shape bytes -> (file, offset)
    rows, missing = [], 0
    for rp in argv[2:]:
        for key0, full, ln, w, h, job, shape in read_recipes(rp):
            if (key0, full) in seen:
                continue
            seen.add((key0, full))
            loc = found.get(shape)
            if loc is None:
                loc = locate(blobs, shape, ln)
                if loc is None:
                    missing += 1
                    print("not found: key0=%08x %ux%u len=%u" % (key0, w, h, ln))
                    continue
                found[shape] = loc
            rows.append((key0, full, ln, w, h, loc[0], loc[1], loc[2], job))
    if order is not None:
        rows.sort(key=lambda r: order.get((r[0], r[1]), 1 << 40))
        have = {(r[0], r[1]) for r in rows}
        print("order pack: %u textures, %u not in the list" % (len(order), sum(1 for k in order if k not in have)))
    used = sorted({r[5] for r in rows})
    remap = {f: k for k, f in enumerate(used)}
    with open(out, "wb") as f:
        f.write(b"TXR2")
        f.write(struct.pack("<I", len(used)))
        for i in used:
            n = names[i].encode()
            f.write(struct.pack("<H", len(n)) + n)
        f.write(struct.pack("<I", len(rows)))
        for key0, full, ln, w, h, fi, off, patches, job in rows:
            f.write(struct.pack("<7I", key0, full, ln, w, h, remap[fi], off))
            f.write(struct.pack("<B", len(patches)))
            for k, v in patches:
                f.write(struct.pack("<BB", k, v))
            f.write(job)
    print("%s: %u textures located in %u files, %u not found" % (out, len(rows), len(used), missing))


if __name__ == "__main__":
    main(sys.argv[1:])
