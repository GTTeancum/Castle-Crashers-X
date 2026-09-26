#!/usr/bin/env python3
"""Extract a byte-exact DEFINE_REX_FUNC body from the sealed generated corpus.

Usage: python tools/extract_generated021.py sub_820AA5B8 [more names...]

Writes runtime021/generated/<name>.inc with exactly the bytes that
runtime021/verify_provenance.py expects (sealed body text + trailing newline).
Never edits the corpus; refuses to overwrite an existing file whose bytes
already differ from the sealed source (manual review required in that case).
"""
import hashlib
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[1]
sources = [p.read_text() for p in sorted((root / 'pc/generated/default').glob('castle_crashers_recomp.*.cpp'))]


def expected(name: str) -> bytes:
    needle = f'DEFINE_REX_FUNC({name}) {{'
    for src in sources:
        if needle not in src:
            continue
        start = src.index(needle)
        level = 0
        seen = False
        for pos in range(start, len(src)):
            if src[pos] == '{':
                level += 1
                seen = True
            elif src[pos] == '}':
                level -= 1
                if seen and level == 0:
                    return (src[start:pos + 1] + '\n').encode()
    raise SystemExit(f'{name}: not found in sealed corpus')


def main() -> None:
    if len(sys.argv) < 2:
        raise SystemExit(__doc__)
    for name in sys.argv[1:]:
        body = expected(name)
        out = root / 'runtime021/generated' / (name + '.inc')
        if out.exists() and out.read_bytes() != body:
            raise SystemExit(f'{name}: existing file differs from sealed corpus; not overwriting')
        out.write_bytes(body)
        print(f'{name}: bytes={len(body)} sha256={hashlib.sha256(body).hexdigest()}')


if __name__ == '__main__':
    main()
