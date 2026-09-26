#!/usr/bin/env python3
"""Boundary-driven recovery loop for WIP 023.

Repeats: run cc_update_boundary_tests, parse the caller_post_init boundary,
and when it is a game-code body (never a platform import) remove any stale
HARD_BOUNDARY line, extract the byte-exact closure from the sealed corpus,
wire includes/decls/dispatch, add fail-closed stubs for new imports, rebuild,
and run again. Stops when the boundary is a platform import thunk (manual
shim review required), when the run passes, or when no progress is made.
Bodies are always byte-exact; this loop never writes a shim.
"""
import re
import subprocess
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(root / 'tools'))
from extract_generated021 import expected  # noqa: E402

EXE = root / 'renderer021/build-release/cc_update_boundary_tests.exe'
ARGS = [str(root / 'renderer011/startup.cct'),
        str(root / 'castle-crashers-port/reference/default.image.bin'),
        str(root / 'game-data/extracted')]
BODIES = root / 'runtime021/bodies.inc'
DECLS = root / 'runtime021/decls.inc'
DISPATCH = root / 'runtime021/dispatch.inc'
ANCHOR = '#include "generated/sub_820A7470.inc"'
GEN = root / 'runtime021/generated'

register = (root / 'pc/generated/default/castle_crashers_register.cpp').read_bytes().decode('latin1')
import_addrs = set(int(a, 16) for a in re.findall(
    r'SetFunction\(0x([0-9A-Fa-f]+), __imp__', register))


def build():
    r = subprocess.run(['cmake', '--build', str(root / 'renderer021/build-release'), '-j8'],
                       capture_output=True, text=True)
    if r.returncode != 0:
        print(r.stdout[-4000:])
        print(r.stderr[-4000:])
        sys.exit('BUILD FAILED')


def run():
    r = subprocess.run([str(EXE)] + ARGS, capture_output=True, text=True)
    m = re.search(r'caller_post_init result=(\w+)@([0-9a-f]+) funcs=(\d+) memops=(\d+)',
                  r.stdout + r.stderr)
    return r.returncode, m


def all_dispatch_cases():
    txt = ''
    for rt in ('runtime008', 'runtime010', 'runtime011', 'runtime021'):
        p = root / rt / 'dispatch.inc'
        if p.exists():
            txt += p.read_bytes().decode('latin1')
    return {c.lower() for c in re.findall(r'case (0x[0-9A-Fa-f]+)', txt)}


def satisfied_names():
    names = set()
    for rt in ('runtime008', 'runtime010', 'runtime011', 'runtime021'):
        p = root / rt / 'bodies.inc'
        if p.exists():
            t = p.read_bytes().decode('latin1')
            names |= set(re.findall(r'#include "generated/([^"]+)\.inc"', t))
            names |= set(re.findall(r'static void (\w+)\(', t))
            names |= set(re.findall(r'HARD_\w+\((\w+),', t))
    return names


def wire(name, add_dispatch_addr=None):
    # Drop any stale hard-boundary line for this name.
    s = BODIES.read_bytes().decode('latin1')
    lines = s.splitlines(keepends=True)
    kept = [l for l in lines if not re.search(r'HARD_\w+\(%s\b' % name, l)]
    if len(kept) != len(lines):
        BODIES.write_bytes(''.join(kept).encode())
        print('  removed hard boundary for', name)

    satisfied = satisfied_names() - {name}
    todo, order, imports, seen = [name], [], set(), set(satisfied)
    while todo:
        n = todo.pop(0)
        if n in seen:
            continue
        seen.add(n)
        body = expected(n)
        (GEN / (n + '.inc')).write_bytes(body)
        order.append(n)
        for c in set(re.findall(r'\t(\w+)\(ctx, base\);', body.decode())):
            if c.startswith('__imp__'):
                imports.add(c)
            elif c not in seen:
                todo.append(c)
    s = BODIES.read_bytes().decode('latin1')
    d = DECLS.read_bytes().decode('latin1')
    for n in order:
        inc = '#include "generated/%s.inc"' % n
        if inc not in s:
            s = s.replace(ANCHOR, ANCHOR + '\n' + inc, 1)
        decl = 'static void %s(Context&, Machine&);' % n
        if decl not in d:
            d += decl + '\n'
    BODIES.write_bytes(s.encode())
    DECLS.write_bytes(d.encode())
    print('  wired %d bodies: %s' % (len(order), ','.join(order)))

    if add_dispatch_addr is not None:
        cases = all_dispatch_cases()
        key = ('0x%08x' % add_dispatch_addr).lower()
        if key not in cases:
            with DISPATCH.open('a', newline='\n') as f:
                f.write('case 0x%08X: sub_%08X(ctx,base); return;\n'
                        % (add_dispatch_addr, add_dispatch_addr))
            print('  added dispatch case 0x%08X' % add_dispatch_addr)

    # New imports referenced by the closure get fail-closed stubs.
    missing = [i for i in sorted(imports) if i not in satisfied_names()]
    if missing:
        r = subprocess.run([sys.executable, str(root / 'tools/gen_stubs021.py')],
                           capture_output=True, text=True)
        print('  gen_stubs:', (r.stdout + r.stderr).strip())


last = None
for iteration in range(80):
    build()
    rc, m = run()
    if not m:
        print('no caller_post_init line; rc=%d' % rc)
        break
    err, addr_s, funcs, memops = m.group(1), m.group(2), m.group(3), m.group(4)
    addr = int(addr_s, 16)
    print('[%d] %s@%08x funcs=%s memops=%s' % (iteration, err, addr, funcs, memops))
    if err in ('ok', 'capacity'):
        print('STOP: reached bounded completion (%s)' % err)
        break
    if (err, addr) == last:
        print('STOP: no progress at %s@%08x' % (err, addr))
        break
    last = (err, addr)
    if addr in import_addrs or addr >= 0x82140000:
        print('STOP: platform import boundary 0x%08x - manual shim review' % addr)
        break
    name = 'sub_%08X' % addr
    if 'SetFunction(0x%08X, %s)' % (addr, name) not in register:
        print('STOP: 0x%08x is not a registered game body' % addr)
        break
    shim_defined = False
    for rt in ('runtime008', 'runtime010', 'runtime011', 'runtime021'):
        bp = root / rt / 'bodies.inc'
        if bp.exists() and re.search(r'static void %s\(' % name, bp.read_bytes().decode('latin1')):
            shim_defined = True
    if shim_defined:
        print('STOP: %s is a hand shim - new observed shape needs manual review' % name)
        break
    wire(name, add_dispatch_addr=addr if err == 'dispatch' else None)
else:
    print('STOP: iteration cap')
