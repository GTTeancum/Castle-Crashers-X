#!/usr/bin/env python3
"""Package Checkpoint 012 using the sealed 011 payload selection plus the 012 delta."""
from __future__ import annotations
from pathlib import Path
import argparse, hashlib, json, zipfile

W = Path(__file__).resolve().parents[1]
PREFIX = "CastleCrashers-Checkpoint-012"
BASE = json.loads((W / "package-manifest011.json").read_text())
BASE_PATHS = {x["path"] for x in BASE["files"]}

NEW_EXACT = {
    "CHECKSUMS-011.sha256",
    "package-manifest011.json",
    "CHECKPOINT-012.md",
    "README-012.md",
    "WORKLOG-012.md",
    "README.md",
    "build-status012.json",
    "build_update012.sh",
    "renderer012/CMakeLists.txt",
    "tools/package012.py",
}
NEW_PREFIXES = (
    "runtime012/",
    "nxdk-update012/",
    "host-bin012/",
    "logs/checkpoint012/build-final/",
)


def digest(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for block in iter(lambda: f.read(4 * 1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def selected(path: Path) -> bool:
    if not path.is_file() or path.is_symlink():
        return False
    rel = path.relative_to(W).as_posix()
    if rel in {"CHECKSUMS.sha256", "CHECKSUMS-012.sha256", "package-manifest012.json"}:
        return False
    if rel in BASE_PATHS or rel in NEW_EXACT or rel.startswith(NEW_PREFIXES):
        parts = path.relative_to(W).parts
        if "__pycache__" in parts:
            return False
        if rel.startswith("runtime012/") and any(x.startswith("build") for x in parts[1:-1]):
            return False
        if rel.startswith("nxdk-update012/") and path.suffix in {".o", ".obj", ".a", ".lib", ".iso"}:
            return False
        return True
    return False


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--output", type=Path, default=W.parent / f"{PREFIX}.zip")
    args = ap.parse_args()
    files = sorted((p for p in W.rglob("*") if selected(p)), key=lambda p: p.relative_to(W).as_posix())
    records = [
        {"path": p.relative_to(W).as_posix(), "bytes": p.stat().st_size, "sha256": digest(p)}
        for p in files
    ]
    manifest = {
        "format": "cc-checkpoint012-inventory",
        "base_checkpoint": "011",
        "files": records,
        "file_count": len(records),
        "uncompressed_bytes": sum(r["bytes"] for r in records),
        "excludes": [
            "BIOS/MCPX/EEPROM/HDD",
            "full extracted game and original LIVE container",
            "external SDK/tool source snapshots including nxdk",
            "build caches/intermediate objects",
            "installed font files",
        ],
        "scope": "Private cumulative original-code port checkpoint. 012 host update-boundary acceptance; 011 remains latest native Xbox/xemu acceptance.",
    }
    mp = W / "package-manifest012.json"
    mp.write_text(json.dumps(manifest, indent=2) + "\n")
    checksum = W / "CHECKSUMS-012.sha256"
    checksum.write_text(
        "".join(f"{r['sha256']}  {r['path']}\n" for r in records)
        + f"{digest(mp)}  package-manifest012.json\n"
    )
    args.output.parent.mkdir(parents=True, exist_ok=True)
    with zipfile.ZipFile(args.output, "w", zipfile.ZIP_DEFLATED, compresslevel=6, allowZip64=True) as z:
        for p in files + [mp, checksum]:
            z.write(p, f"{PREFIX}/{p.relative_to(W).as_posix()}")
    result = {
        "archive": str(args.output),
        "bytes": args.output.stat().st_size,
        "sha256": digest(args.output),
        "included_files": len(files) + 2,
        "payload_bytes": manifest["uncompressed_bytes"],
    }
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
