#!/usr/bin/env python3
"""Wire an extracted closure into runtime021 bodies/decls.

Usage: python tools/wire_family021.py <marker-comment> sub_A [sub_B ...]

Runs the extractor closure over the roots, then inserts the include block
(bracketed by -Wunused-function suppression, since vtable-reached bodies are
referenced only via dispatch once observed) before the post-init slice
include, appends declarations, and prints every referenced __imp__ that has
no shim yet together with its real thunk address from the sealed register
map, as ready-to-paste fail-closed stubs.
"""
import re
import subprocess
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[1]
marker = sys.argv[1]
roots = sys.argv[2:]

out = subprocess.run(
    [sys.executable, str(root / 'tools/extract_closure021.py'), *roots],
    capture_output=True, text=True, check=True).stdout.splitlines()
includes = [l for l in out if l.startswith('#include')]
decls = [l for l in out if l.startswith('static void sub')]
missing = [l.split()[0] for l in out if 'NO SHIM YET' in l]

bodies_path = root / 'runtime021/bodies.inc'
bodies = bodies_path.read_text()
anchor = '#include "generated/sub_82070AC8_post_init.inc"'
block = ('// ' + marker + '\n'
         '#pragma clang diagnostic push\n'
         '#pragma clang diagnostic ignored "-Wunused-function"\n' +
         '\n'.join(includes) +
         '\n#pragma clang diagnostic pop\n' + anchor)
bodies = bodies.replace(anchor, block, 1)
bodies_path.write_text(bodies)

with (root / 'runtime021/decls.inc').open('a') as f:
    f.write('\n'.join(decls) + '\n')

reg = (root / 'pc/generated/default/castle_crashers_register.cpp').read_text()
thunk = {}
for m in re.finditer(r'SetFunction\((0x[0-9A-F]+), (__imp__\w+)\)', reg):
    thunk.setdefault(m.group(2), m.group(1))
print('wired %d includes, %d decls' % (len(includes), len(decls)))
print('--- fail-closed stubs needed ---')
for name in missing:
    print('static void %s([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, %su); }'
          % (name, thunk.get(name, '0xFFFFFFFF')))
print('--- stub decls ---')
for name in missing:
    print('static void %s(Context&, Machine&);' % name)
