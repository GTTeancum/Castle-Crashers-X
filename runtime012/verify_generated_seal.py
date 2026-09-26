#!/usr/bin/env python3
from __future__ import annotations
import hashlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
checksums = ROOT / "CHECKSUMS.sha256"
expected = {}
for raw in checksums.read_text().splitlines():
    raw = raw.strip()
    if not raw or "  " not in raw:
        continue
    digest, rel = raw.split("  ", 1)
    expected[rel] = digest.lower()
files = sorted((ROOT / "pc/generated/default").glob("castle_crashers_recomp.*.cpp"))
assert len(files) == 17, f"expected 17 sealed generated translation units, got {len(files)}"
for p in files:
    rel = p.relative_to(ROOT).as_posix()
    want = expected.get(rel)
    if want is None:
        raise SystemExit(f"missing sealed hash for {rel}")
    got = hashlib.sha256(p.read_bytes()).hexdigest()
    if got != want:
        raise SystemExit(f"generated source changed: {rel}: {got} != {want}")
print(f"PASS generated-seal translation_units={len(files)} source=CHECKSUMS.sha256")
