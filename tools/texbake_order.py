# SPDX-License-Identifier: MIT
"""Lay a baked texture pack ("TXB1") out in first-use order; estimate seeks.

usage:
  texbake_order.py write <in.pak> <out.pak> <order.log>...
  texbake_order.py seeks <pack.pak> <order.log> [buffer KiB ...]

On the console every baked texture read was its own seek, because the pack
keeps its pixels in key order. `write` copies the pack with the same index
(same entries, same key order, so the loader's binary search and every
entry number stay the same) but with the pixel blocks in the order the runs
first read them: the textures of the first log in its order, then those of
the next log not yet placed, and so on; textures no log read follow in
their old order. Every block is copied byte for byte and checked after
writing. The input pack is never overwritten.

Order logs come from the host harness: CC_TEX_ORDER=<file> appends one line
per baked-texture read (runtime021/bodies.inc, cc_bake_read):
  TEXREAD frame=<n> entry=<i> key0=<hex> full=<hex> bytes=<n> first=<0|1> from=<disk|buffer>

`seeks` replays a log's reads against a pack's layout with the port's
read-ahead policy (cc_bake_fetch: a first read that misses the buffer fills
it with that block and the whole blocks after it, up to the buffer size,
unless the previous fill served nothing and the read does not continue
where the last one stopped; re-reads go straight to the cache block) and
prints disk reads, seeks (disk reads that do not start where the previous
one ended), bytes read and an estimated disk time (8.5 ms per seek and
25 MB/s, fitted to the console's worst second: 36 reads of 1.5 MB in one
370 ms frame), in total and for the worst frame. Buffer size 0 is the port
without read-ahead.
"""
import os
import re
import struct
import sys

SEEK_MS = 8.5
MB_PER_S = 25.0


def read_pack(path):
    d = open(path, "rb").read()
    if d[:4] != b"TXB1":
        raise SystemExit("%s: not a texture pack" % path)
    n = struct.unpack_from("<I", d, 4)[0]
    index = [struct.unpack_from("<6I", d, 8 + 24 * i) for i in range(n)]
    return d, index


def read_log(path):
    out = []
    pat = re.compile(r"TEXREAD frame=(\d+) entry=(\d+) key0=([0-9a-f]+) full=([0-9a-f]+) bytes=(\d+) first=(\d)")
    for line in open(path, errors="replace"):
        m = pat.search(line)
        if m:
            out.append((int(m[1]), int(m[3], 16), int(m[4], 16), int(m[5]), m[6] == "1"))
    return out


def cmd_write(argv):
    src, dst, logs = argv[0], argv[1], argv[2:]
    if os.path.exists(dst) and os.path.samefile(src, dst):
        raise SystemExit("refusing to overwrite the input pack")
    d, index = read_pack(src)
    by_key = {}
    for i, (key0, full, ln, w, h, off) in enumerate(index):
        by_key.setdefault((key0, full), i)
    placed, order = set(), []
    for log in logs:
        for frame, key0, full, nbytes, first in read_log(log):
            i = by_key.get((key0, full))
            if i is None:
                raise SystemExit("%s: texture %08x/%08x not in %s" % (log, key0, full, src))
            if i not in placed:
                placed.add(i)
                order.append(i)
        print("%s: %d textures placed so far" % (log, len(order)))
    seen = len(order)
    order += sorted((i for i in range(len(index)) if i not in placed), key=lambda i: index[i][5])
    offset = 8 + 24 * len(index)
    new_off = [0] * len(index)
    for i in order:
        new_off[i] = offset
        offset += index[i][3] * index[i][4]
    with open(dst, "wb") as f:
        f.write(b"TXB1" + struct.pack("<I", len(index)))
        for i, (key0, full, ln, w, h, off) in enumerate(index):
            f.write(struct.pack("<6I", key0, full, ln, w, h, new_off[i]))
        for i in order:
            key0, full, ln, w, h, off = index[i]
            f.write(d[off:off + w * h])
    # Check: same index apart from the offsets, every block identical.
    d2, index2 = read_pack(dst)
    assert len(index2) == len(index) and len(d2) == offset
    for a, b in zip(index, index2):
        assert a[:5] == b[:5]
        assert d[a[5]:a[5] + a[3] * a[4]] == d2[b[5]:b[5] + b[3] * b[4]]
    print("%s: %d textures (%d in first-use order), %d bytes, every block identical to %s"
          % (dst, len(index), seen, offset, src))


def simulate(index, reads, buf):
    """Replay reads with cc_bake_read's policy; returns per-frame disk use."""
    by_key = {}
    for i, e in enumerate(index):
        by_key.setdefault((e[0], e[1]), i)
    rank = sorted(range(len(index)), key=lambda i: index[i][5])
    pos = {i: k for k, i in enumerate(rank)}
    size = [e[3] * e[4] for e in index]
    lo = hi = 0
    hits, filled, last_end = 0, False, -1
    read_before = set()
    frames = {}
    for frame, key0, full, nbytes, first in reads:
        i = by_key[(key0, full)]
        o, s = index[i][5], size[i]
        is_first = i not in read_before
        read_before.add(i)
        if lo <= o and o + s <= hi:
            hits += 1
            continue
        if buf and is_first and s <= buf and (not filled or hits > 0 or o == last_end):
            end = o + s
            k = pos[i] + 1
            while k < len(rank) and index[rank[k]][5] + size[rank[k]] - o <= buf:
                end = index[rank[k]][5] + size[rank[k]]
                k += 1
            start, stop = o, end
            lo, hi, hits, filled = o, end, 0, True
        else:
            start, stop = o, o + s
        f = frames.setdefault(frame, [0, 0, 0])
        f[0] += 1
        f[1] += start != last_end
        f[2] += stop - start
        last_end = stop
    return frames


def cmd_seeks(argv):
    _, index = read_pack(argv[0])
    reads = read_log(argv[1])
    sizes = [int(x) for x in argv[2:]] or [0, 256, 512]
    nfirst = sum(1 for r in reads if r[4])
    print("%s: %d reads (%d first reads, %d KB) on %s" % (argv[1], len(reads), nfirst,
          sum(r[3] for r in reads) >> 10, argv[0]))
    for kb in sizes:
        frames = simulate(index, reads, kb << 10)
        disk = sum(f[0] for f in frames.values())
        seeks = sum(f[1] for f in frames.values())
        nbytes = sum(f[2] for f in frames.values())
        cost = {fr: f[1] * SEEK_MS + f[2] / (MB_PER_S * 1000.0) for fr, f in frames.items()}
        worst = max(cost, key=cost.get) if cost else 0
        print("  buffer %4d KiB: disk reads %5d  seeks %5d  read %7d KB  est. disk time %6.0f ms"
              "  worst frame %d: %d seeks, %d KB, est. %.0f ms"
              % (kb, disk, seeks, nbytes >> 10, sum(cost.values()), worst,
                 frames[worst][1] if cost else 0, (frames[worst][2] >> 10) if cost else 0,
                 cost.get(worst, 0.0)))


def main(argv):
    if len(argv) >= 4 and argv[0] == "write":
        cmd_write(argv[1:])
    elif len(argv) >= 3 and argv[0] == "seeks":
        cmd_seeks(argv[1:])
    else:
        print(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
