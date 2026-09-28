#!/usr/bin/env python3
"""Walk the Xenos command stream between captured draws and list the shader
constant writes that precede each one.

usage: ring_consts.py <frame.ccframe> <ring.bin> [first_draw] [last_draw]

The capture stores, per draw, the command-ring write cursor (device+13444)
at the moment the game's draw call was entered; ring.bin is guest memory
0x02000000..0x0220F000.
"""
import struct
import sys

RING_BASE = 0x02000000

def draws(path):
    d = open(path, 'rb').read()
    _, nt, nd = struct.unpack_from('<III', d, 8)
    off = 20
    for _ in range(nt):
        nb = struct.unpack_from('<IIIII', d, off)[4]
        off += 20 + nb
    out = []
    for _ in range(nd):
        prim, count, stride, blend, tex = struct.unpack_from('<IIIII', d, off)
        off += 20
        m = struct.unpack_from('<16I', d, off)
        off += 64
        vb, = struct.unpack_from('<I', d, off)
        off += 4
        v0 = struct.unpack_from('>5fI', d, off) if vb >= 24 else None
        off += vb
        out.append((m[0], tex, v0))
    return out

def walk(ring, start, end):
    """Yield (kind, info) for PM4 packets in [start, end)."""
    a = start
    while a + 4 <= end:
        h, = struct.unpack_from('>I', ring, a - RING_BASE)
        t = h >> 30
        if t == 0:
            n = ((h >> 16) & 0x3FFF) + 1
            reg = h & 0x7FFF
            vals = struct.unpack_from('>%dI' % n, ring, a + 4 - RING_BASE)
            yield ('reg', reg, vals)
            a += 4 + 4 * n
        elif t == 3:
            n = ((h >> 16) & 0x3FFF) + 1
            op = (h >> 8) & 0x7F
            vals = struct.unpack_from('>%dI' % n, ring, a + 4 - RING_BASE)
            yield ('op', op, vals)
            a += 4 + 4 * n
        elif t == 2:
            a += 4
        else:
            n = 2
            yield ('t1', h, ())
            a += 4 + 4 * n

def f32(u):
    return struct.unpack('>f', struct.pack('>I', u))[0]

def main():
    fr, rp = sys.argv[1], sys.argv[2]
    lo = int(sys.argv[3]) if len(sys.argv) > 3 else 0
    hi = int(sys.argv[4]) if len(sys.argv) > 4 else lo + 5
    ds = draws(fr)
    ring = open(rp, 'rb').read()
    for i in range(max(lo, 1), min(hi, len(ds))):
        s, e = ds[i - 1][0], ds[i][0]
        print('draw %d tex=%08x v0=%s cursor %08x..%08x' % (i, ds[i][1], ds[i][2], s, e))
        if not (RING_BASE <= s < e <= RING_BASE + len(ring)):
            print('  (cursor wrapped or out of range)')
            continue
        for kind, a, vals in walk(ring, s, e):
            if kind == 'reg':
                if 0x4000 <= a < 0x4900:
                    c = (a - 0x4000) // 4
                    fl = ['%.5g' % f32(x) for x in vals]
                    print('  const c%d (+%d) = %s' % (c, (a - 0x4000) % 4, ' '.join(fl)))
                else:
                    print('  reg %04x = %s' % (a, ' '.join('%08x' % x for x in vals[:6])))
            elif kind == 'op':
                extra = ''
                if a == 0x2D and vals:  # SET_CONSTANT
                    kind_off = vals[0]
                    fl = ['%.5g' % f32(x) for x in vals[1:17]]
                    extra = ' set_constant type=%d off=%d: %s' % (kind_off >> 16, kind_off & 0x7FF, ' '.join(fl))
                print('  op %02x n=%d%s' % (a, len(vals), extra))
            else:
                print('  type1 %08x' % a)

if __name__ == '__main__':
    main()
