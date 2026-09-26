#!/usr/bin/env python3
"""Extract a call closure of byte-exact bodies into runtime021/generated.

Usage: python tools/extract_closure021.py sub_82070908 [more roots...]

Repeatedly extracts sealed bodies for every direct callee not yet present in
the bridge translation unit (runtime008/010/011/021 includes and static
definitions), until the closure converges. Prints the ordered include list,
declarations, and every __imp__ the new bodies reference so the shims can be
reviewed by hand. Never edits bodies.inc/decls.inc itself.
"""
import re
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(root / 'tools'))
from extract_generated021 import expected  # noqa: E402

gen = root / 'runtime021/generated'
included = set()
defined = set()
for rt in ('runtime008', 'runtime010', 'runtime011', 'runtime021'):
    bodies_path = root / rt / 'bodies.inc'
    if not bodies_path.exists():
        continue
    bodies = bodies_path.read_text()
    included |= set(re.findall(r'#include "generated/([^"]+)\.inc"', bodies))
    defined |= set(re.findall(r'static void (\w+)\(', bodies))
    defined |= set(re.findall(r'HARD_\w+\((\w+),', bodies))

satisfied = included | defined
todo = list(sys.argv[1:])
new_order = []  # dependency-ish order: callees before callers not guaranteed; decls cover it
imports = set()
seen = set(satisfied)
while todo:
    n = todo.pop(0)
    if n in seen:
        continue
    seen.add(n)
    body = expected(n)
    (gen / (n + '.inc')).write_bytes(body)
    new_order.append(n)
    for c in set(re.findall(r'\t(\w+)\(ctx, base\);', body.decode())):
        if c.startswith('__imp__'):
            imports.add(c)
        elif c not in seen:
            todo.append(c)

print('extracted %d bodies:' % len(new_order))
for n in new_order:
    print('#include "generated/%s.inc"' % n)
print('--- decls ---')
for n in sorted(new_order):
    print('static void %s(Context&, Machine&);' % n)
print('--- imports referenced ---')
for i in sorted(imports):
    flag = '' if i in defined else '   <-- NO SHIM YET'
    print(i + flag)
