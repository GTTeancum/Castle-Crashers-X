# SPDX-License-Identifier: MIT
"""Console profile report: symbolise tools/xbox_console.py profile samples.

usage: xbox_symbolize.py <samples> <main.map> <main.exe> [top]

Each sample holds the stopped thread's stack copy; the interrupted Eip is
the word before the CS (8) / EFLAGS pair of the interrupt frame (the thread
itself is parked in the debug monitor when stopped). Self time: the function
containing that Eip. Inclusive: that function plus every function owning a
return address found in the rest of the stack copy (a word inside .text
whose preceding bytes are a call instruction).
"""
import bisect
import re
import struct
import sys
from collections import Counter


def load_map(path):
    syms = []
    # code symbols only (section 0001), publics and statics alike
    pat = re.compile(r"^\s*0001:[0-9a-fA-F]{8}\s+(\S+)\s+([0-9a-fA-F]{8,16})\s")
    for line in open(path, encoding="latin-1"):
        m = pat.match(line)
        if m:
            syms.append((int(m.group(2), 16), m.group(1)))
    syms.sort()
    return [a for a, _ in syms], [n for _, n in syms]


def load_text(exe):
    d = open(exe, "rb").read()
    pe = struct.unpack_from("<I", d, 0x3C)[0]
    nsec = struct.unpack_from("<H", d, pe + 6)[0]
    optsz = struct.unpack_from("<H", d, pe + 20)[0]
    imagebase = struct.unpack_from("<I", d, pe + 24 + 28)[0]
    sec = pe + 24 + optsz
    for i in range(nsec):
        name = d[sec + i * 40:sec + i * 40 + 8].rstrip(b"\0")
        vsize, va, rawsize, raw = struct.unpack_from("<IIII", d, sec + i * 40 + 8)
        if name == b".text":
            return imagebase + va, d[raw:raw + rawsize]
    raise SystemExit("no .text")


def demangle(n):
    m = re.match(r"\?([A-Za-z_][A-Za-z0-9_]*)@", n)
    if m:
        return m.group(1)
    return n.lstrip("_")


def main(argv):
    samples, mapf, exe = argv[:3]
    top = int(argv[3]) if len(argv) > 3 else 40
    addrs, names = load_map(mapf)
    tbase, text = load_text(exe)
    tend = tbase + len(text)

    def fn(a):
        i = bisect.bisect_right(addrs, a) - 1
        return demangle(names[i]) if i >= 0 else "?"

    def is_ret(a):
        if not (tbase + 6 <= a < tend):
            return False
        o = a - tbase
        if text[o - 5] == 0xE8:
            return True
        # call r/m32 (FF /2) of 2, 3, 6 or 7 bytes
        for k in (2, 3, 6, 7):
            if text[o - k] == 0xFF and ((text[o - k + 1] >> 3) & 7) == 2:
                return True
        return False

    self_c, incl_c = Counter(), Counter()
    n = 0
    for line in open(samples):
        p = line.split()
        if len(p) < 64:
            continue
        ws = [int(w, 16) for w in p[3:]]
        k = next((i for i in range(len(ws) - 2) if ws[i + 1] == 8 and (ws[i + 2] & 0xFFFF0002) == 2), None)
        if k is None:
            continue
        eip = ws[k]
        n += 1
        f = "kernel" if eip >= 0x80000000 else fn(eip)
        self_c[f] += 1
        seen = {f}
        for w in ws[k + 3:]:
            if is_ret(w):
                seen.add(fn(w))
        for s in seen:
            incl_c[s] += 1
    print("samples %d" % n)
    print("--- self")
    for f, c in self_c.most_common(top):
        print("%5.1f%%  %s" % (100.0 * c / n, f))
    print("--- inclusive")
    for f, c in incl_c.most_common(top):
        print("%5.1f%%  %s" % (100.0 * c / n, f))


if __name__ == "__main__":
    main(sys.argv[1:])
