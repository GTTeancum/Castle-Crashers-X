#!/usr/bin/env python3
"""Wire every remaining recompiled function of the sealed corpus into
runtime021 in one pass, instead of one boundary miss per harness run.

- Every function registered in castle_crashers_register.cpp that is not yet
  defined (by a generated include, a hand shim, or a HARD_ boundary) gets its
  byte-exact body extracted (extract_generated021.expected) into
  runtime021/generated, an include after the anchor, and a declaration.
- Every defined guest function gets an indirect-call dispatch case.
- HARD_ boundaries and hand shims are left exactly as they are.

Run tools/gen_stubs021.py afterwards for the imports the new bodies use.
"""
import re
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(root / 'tools'))
from extract_generated021 import expected  # noqa: E402

RUNTIMES = ('runtime008', 'runtime010', 'runtime011', 'runtime021')


def rd(p):
    return (root / p).read_bytes().decode('latin1').replace('\r\n', '\n')


def wr(p, s):
    (root / p).write_bytes(s.encode('latin1'))


reg = rd('pc/generated/default/castle_crashers_register.cpp')
funcs = [(int(a, 16), n) for a, n in
         re.findall(r'SetFunction\((0x[0-9A-Fa-f]+), ((?!__imp__)\w+)\)', reg)]

defined = set()
hard = set()
for rt in RUNTIMES:
    t = rd(rt + '/bodies.inc')
    defined |= set(re.findall(r'#include "generated/([^"]+)\.inc"', t))
    defined |= set(re.findall(r'static void (\w+)\(\s*(?:\[\[maybe_unused\]\]\s*)?Context\s*&', t))
    hard |= set(re.findall(r'HARD_\w+\((sub_[0-9A-Fa-f]+)\b', t))
defined |= hard

new = []
for _, name in funcs:
    if name in defined:
        continue
    (root / 'runtime021/generated' / (name + '.inc')).write_bytes(expected(name))
    new.append(name)
    defined.add(name)

s = rd('runtime021/bodies.inc')
anchor = '#include "generated/sub_820A7470.inc"'
assert anchor in s
if new:
    s = s.replace(anchor, anchor + '\n' + '\n'.join(
        '#include "generated/%s.inc"' % n for n in new), 1)
    wr('runtime021/bodies.inc', s)

d = rd('runtime021/decls.inc')
declared = set(re.findall(r'static void (\w+)\(Context&', d))
for rt in RUNTIMES[:-1]:
    declared |= set(re.findall(
        r'static void (\w+)\(\s*(?:\[\[maybe_unused\]\]\s*)?Context\s*&',
        rd(rt + '/bodies.inc')))
included = re.findall(r'#include "generated/(\w+)\.inc"', rd('runtime021/bodies.inc'))
d += ''.join('static void %s(Context&, Machine&);\n' % n
             for n in dict.fromkeys(included) if n not in declared)
wr('runtime021/decls.inc', d)

have = set()
for rt in RUNTIMES:
    p = root / rt / 'dispatch.inc'
    if p.exists():
        have |= {int(x, 16) for x in re.findall(r'case (0x[0-9A-Fa-f]+)', rd(rt + '/dispatch.inc'))}
have |= {int(x, 16) for x in re.findall(r'\bcase (0x[0-9A-Fa-f]+)\s*:', rd('runtime021/bridge.cpp'))}
cases = [(a, n) for a, n in funcs if a not in have and n in defined]
if cases:
    wr('runtime021/dispatch.inc', rd('runtime021/dispatch.inc') + ''.join(
        'case 0x%08X: %s(ctx,base); return;\n' % (a, n) for a, n in cases))
print('wired %d new bodies, added %d dispatch cases (%d hard boundaries kept)'
      % (len(new), len(cases), len(hard)))
