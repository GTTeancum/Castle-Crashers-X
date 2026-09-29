#!/usr/bin/env python3
"""Fold the host sampler's STACK lines (inclusive counts per guest return
address, CC_SAMPLE=1) into inclusive percentages per containing function.

Usage: stack_report.py <run log> [top]
Function starts come from pc/generated/default/castle_crashers_init.cpp.
"""
import bisect
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
starts = sorted({int(m, 16) for m in re.findall(
    r"\{ 0x([0-9A-Fa-f]{8}), sub_",
    (ROOT / "pc/generated/default/castle_crashers_init.cpp").read_text())})

per_fn = {}
total = 0
for line in Path(sys.argv[1]).read_text(errors="replace").splitlines():
    m = re.match(r"STACK total=(\d+)", line)
    if m:
        total = int(m.group(1))
        continue
    m = re.match(r"STACK\s+([\d.]+)% ret=([0-9A-F]{8})", line)
    if not m:
        continue
    ra = int(m.group(2), 16)
    i = bisect.bisect_right(starts, ra - 4) - 1  # the call sits just before ra
    fn = starts[i] if i >= 0 else 0
    per_fn[fn] = per_fn.get(fn, 0.0) + float(m.group(1))

top = int(sys.argv[2]) if len(sys.argv) > 2 else 60
print(f"stacks={total}")
for fn, pct in sorted(per_fn.items(), key=lambda kv: -kv[1])[:top]:
    print(f"{pct:6.1f}%  sub_{fn:08X}")
