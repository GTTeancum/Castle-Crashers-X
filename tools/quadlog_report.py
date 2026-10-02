#!/usr/bin/env python3
"""Fold the host quad probe (CC_QUADLOG) into a rule for the native quad
emitter: for each QUADIN/QUADOUT pair, check which input point and uv
each output vertex came from and how the colour was transformed.

Usage: quadlog_report.py <run log>
"""
import re
import sys
from collections import Counter

log = open(sys.argv[1], errors="replace").read()
ins = re.findall(r"QUADIN frame=(\d+) count=(\d+) colour=([0-9a-f]{8})((?: p\d=\([^)]*\))+)((?: uv\d=\([^)]*\))+) ring=(\d+)", log)
outs = re.findall(r"QUADOUT prim=(\d+) count=(\d+) stride=(\d+)((?: v\d=\([^)]*\))+)", log)
print(f"QUADIN {len(ins)}  QUADOUT {len(outs)}")
n = min(len(ins), len(outs))
pos_map = Counter(); uv_map = Counter(); col_rule = Counter(); prims = Counter(); zs = Counter()
examples = []
for k in range(n):
    frame, count, colour, pstr, uvstr, ring = ins[k]
    prim, ocount, stride, vstr = outs[k]
    pts = [tuple(float(x) for x in m) for m in re.findall(r"p\d=\(([^,]*),([^,]*),([^)]*)\)", pstr)]
    uvs = [tuple(float(x) for x in m) for m in re.findall(r"uv\d=\(([^,]*),([^)]*)\)", uvstr)]
    verts = [m for m in re.findall(r"v\d=\(([^,]*),([^,]*),([^,]*),([^,]*),([^,]*),([0-9a-f]{8})\)", vstr)]
    prims[(prim, ocount, stride)] += 1
    cin = int(colour, 16)
    for i, v in enumerate(verts):
        x, y, z, u, w, c = float(v[0]), float(v[1]), float(v[2]), float(v[3]), float(v[4]), int(v[5], 16)
        zs[z] += 1
        src = [j for j, p in enumerate(pts) if abs(p[0] - x) < 1e-4 and abs(p[1] - y) < 1e-4]
        pos_map[(i, tuple(src))] += 1
        usrc = [j for j, q in enumerate(uvs) if abs(q[0] - u) < 1e-6 and abs(q[1] - w) < 1e-6]
        uv_map[(i, tuple(usrc))] += 1
        a = cin >> 24
        R, G, B = (cin >> 16) & 255, (cin >> 8) & 255, cin & 255
        cands = {
            "same": cin,
            "premul/255": (a << 24) | ((R * a // 255) << 16) | ((G * a // 255) << 8) | (B * a // 255),
            "premul>>8": (a << 24) | ((R * a >> 8) << 16) | ((G * a >> 8) << 8) | (B * a >> 8),
            "premul>>8 ABGR": (a << 24) | ((B * a >> 8) << 16) | ((G * a >> 8) << 8) | (R * a >> 8),
            "ABGR": (a << 24) | (B << 16) | (G << 8) | R,
            "RGBA": (R << 24) | (G << 16) | (B << 8) | a,
            "premul>>8 RGBA": ((R * a >> 8) << 24) | ((G * a >> 8) << 16) | ((B * a >> 8) << 8) | a,
            "premul>>8 BGRA": ((B * a >> 8) << 24) | ((G * a >> 8) << 16) | ((R * a >> 8) << 8) | a,
        }
        rule = next((k for k, v in cands.items() if v == c), "other")
        col_rule[rule] += 1
        if rule == "other" and len(examples) < 6:
            examples.append((colour, v[5]))
print("prim/count/stride:", prims.most_common(4))
print("z values:", zs.most_common(4))
print("vertex i <- input point j:", sorted(pos_map.items()))
print("vertex i <- input uv j:", sorted(uv_map.items()))
print("colour rule:", col_rule.most_common(), "examples(other):", examples)
