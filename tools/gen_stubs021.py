#!/usr/bin/env python3
"""Emit fail-closed shim definitions and declarations for every __imp__
referenced by runtime021 generated includes but not yet defined anywhere in
the bridge translation unit. Definitions are inserted into bodies.inc at the
STUB-ANCHOR comment; declarations are appended to decls.inc."""
import re
from pathlib import Path

root = Path(__file__).resolve().parents[1]
bodies_path = root / 'runtime021/bodies.inc'
bodies = bodies_path.read_text()
defined = set(re.findall(r'static void (__imp__\w+)\(', bodies))
for rt in ('runtime008', 'runtime010', 'runtime011'):
    p = root / rt / 'bodies.inc'
    if p.exists():
        defined |= set(re.findall(r'static void (__imp__\w+)\(', p.read_text()))

included = re.findall(r'#include "generated/([^"]+)\.inc"', bodies)
needed = set()
for name in included:
    p = root / 'runtime021/generated' / (name + '.inc')
    if p.exists():
        needed |= set(re.findall(r'(__imp__\w+)\(ctx, base\)', p.read_text()))
missing = sorted(needed - defined)

reg = (root / 'pc/generated/default/castle_crashers_register.cpp').read_text()
thunk = {}
for m in re.finditer(r'SetFunction\((0x[0-9A-F]+), (__imp__\w+)\)', reg):
    thunk.setdefault(m.group(2), m.group(1))

stub_defs = '\n'.join(
    'static void %s([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, %su); }'
    % (n, thunk.get(n, '0xFFFFFFFF')) for n in missing)
anchor = '// actually reaches it.\n'
assert anchor in bodies
bodies = bodies.replace(anchor, anchor + stub_defs + '\n', 1)
bodies_path.write_text(bodies)
with (root / 'runtime021/decls.inc').open('a') as f:
    f.write('\n'.join('static void %s(Context&, Machine&);' % n for n in missing) + '\n')
print('added %d fail-closed import stubs' % len(missing))
