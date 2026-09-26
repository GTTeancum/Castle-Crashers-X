#!/usr/bin/env python3
"""Report the include/import closure for runtime021 bodies.

Usage: python tools/closure021.py sub_820B9958 [more roots...]

Walks direct calls from each root across runtime021/generated/*.inc, treating
functions already included by runtime021/bodies.inc (or defined as shims/stubs
there) as satisfied. Prints the generated bodies that still need includes, the
roots that have no extracted body yet, and every __imp__ the closure touches.
"""
import re
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[1]
gen = root / 'runtime021/generated'
bodies = (root / 'runtime021/bodies.inc').read_text()
included = set(re.findall(r'#include "generated/([^"]+)\.inc"', bodies))
defined = set(re.findall(r'static void (\w+)\(', bodies))
defined |= set(re.findall(r'HARD_\w+\((\w+),', bodies))
have = {p.stem: p for p in gen.glob('*.inc')}

todo = list(sys.argv[1:])
seen = set(included) | defined
need_inc, need_imp, missing = [], set(), []
while todo:
    n = todo.pop()
    if n in seen:
        continue
    seen.add(n)
    if n not in have:
        missing.append(n)
        continue
    need_inc.append(n)
    for c in set(re.findall(r'\t(\w+)\(ctx, base\);', have[n].read_text())):
        if c.startswith('__imp__'):
            need_imp.add(c)
        elif c not in seen:
            todo.append(c)

# imports referenced by bodies we newly include
print('includes needed:', need_inc)
print('no extracted body:', missing)
print('imports referenced by new includes:', sorted(need_imp))
undefined_imports = [i for i in sorted(need_imp) if i not in defined]
print('imports lacking a shim in bodies.inc:', undefined_imports)
