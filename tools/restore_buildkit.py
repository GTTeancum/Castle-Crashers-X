#!/usr/bin/env python3
"""Verify/reassemble the Windows collector's ZIP volumes, then restore Linux Git trees.

Usage: python3 restore_buildkit.py /path/to/uploaded-zips --output ./cc-buildkit
No downloads, package installs, builds, or execution of downloaded programs occur.
Requires Python 3.9+ and Git for --checkout. Generated source is deliberately NOT run.
"""
from __future__ import annotations
import argparse
import hashlib
import json
import os
from pathlib import Path, PurePosixPath
import shutil
import stat
import subprocess
import sys
import zipfile

BUF = 4 * 1024 * 1024
PREFIX = "CastleCrashers-BuildKit"


def sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(BUF), b""):
            h.update(block)
    return h.hexdigest()


def safe_name(name: str) -> PurePosixPath:
    p = PurePosixPath(name)
    if not name or "\\" in name or "\x00" in name or p.is_absolute() or any(x in ("..",) or ":" in x for x in p.parts):
        raise ValueError(f"Unsafe archive path: {name!r}")
    return p


def safe_destination(root: Path, name: str) -> Path:
    p = safe_name(name)
    dest = root.joinpath(*p.parts)
    if not dest.resolve().is_relative_to(root.resolve()):
        raise ValueError(f"Path leaves destination: {name!r}")
    return dest


def extract_regular_zip(archive: Path, root: Path) -> None:
    """The collector's own ZIPs contain regular files only, never worktree symlinks."""
    root.mkdir(parents=True, exist_ok=True)
    seen: set[str] = set()
    with zipfile.ZipFile(archive) as z:
        for info in z.infolist():
            safe_name(info.filename)
            if info.filename in seen:
                raise ValueError(f"Duplicate ZIP entry: {info.filename}")
            seen.add(info.filename)
            if stat.S_ISLNK(info.external_attr >> 16):
                raise ValueError(f"Unexpected symlink in collector ZIP: {info.filename}")
            dest = safe_destination(root, info.filename)
            if info.is_dir():
                dest.mkdir(parents=True, exist_ok=True)
                continue
            if dest.is_symlink():
                raise ValueError(f"Refusing existing symlink: {dest}")
            dest.parent.mkdir(parents=True, exist_ok=True)
            with z.open(info) as src, dest.open("wb") as out:
                shutil.copyfileobj(src, out, BUF)


def run_git(*args: str, cwd: Path | None = None) -> str:
    # Do not consult the recipient's credential helpers or execute checkout hooks.
    env = dict(os.environ)
    env.update(GIT_TERMINAL_PROMPT="0", GIT_CONFIG_NOSYSTEM="1", GIT_CONFIG_GLOBAL=os.devnull)
    proc = subprocess.run(
        ["git", "-c", "core.hooksPath=/dev/null", "-c", "core.autocrlf=false", "-c", "core.symlinks=true", *args],
        cwd=cwd, env=env, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
    )
    if proc.returncode:
        raise RuntimeError(f"Git command failed ({proc.returncode}): {proc.stderr.strip()}")
    return proc.stdout.strip()


def restore_sources(root: Path, manifest: dict) -> None:
    if os.name == "nt":
        raise RuntimeError("--checkout is intended for Linux so executable bits and symlinks are restored correctly.")
    if shutil.which("git") is None:
        raise RuntimeError("Git must be available for --checkout.")
    bare_root = root / "git-cache"
    # Each selected Git snapshot retains shallow boundaries, refs, tags, and objects.
    for repo in manifest["repositories"]:
        rid = repo["id"]
        if not isinstance(rid, str) or len(rid) != 24 or any(c not in "0123456789abcdef" for c in rid):
            raise ValueError("Invalid repository ID")
        bare = bare_root / (rid + ".git")
        archive = safe_destination(root, repo["archive"])
        if sha256(archive) != repo["sha256"]:
            raise ValueError(f"Source snapshot checksum mismatch: {repo['archive']}")
        if not bare.exists():
            bare.mkdir(parents=True)
            extract_regular_zip(archive, bare)
        # A fresh minimal config avoids transporting user-specific Git configuration.
        (bare / "config").write_text("[core]\n\trepositoryformatversion = 0\n\tbare = true\n", encoding="utf-8")
        actual = run_git("--git-dir", str(bare), "rev-parse", "refs/heads/cc-bundle^{commit}")
        if actual != repo["commit"]:
            raise ValueError(f"Commit mismatch for {repo['url']}")
        run_git("--git-dir", str(bare), "fsck", "--connectivity-only", "--no-dangling")
    # Parent repositories must be checked out before their nested submodules.
    for mount in sorted(manifest["mounts"], key=lambda m: (m["path"].count("/"), m["path"])):
        rel = "sources/" + mount["path"]
        dest = safe_destination(root, rel)
        bare = bare_root / (mount["repository_id"] + ".git")
        if dest.is_symlink():
            raise ValueError(f"Refusing source symlink: {dest}")
        if (dest / ".git").exists():
            actual = run_git("-C", str(dest), "rev-parse", "HEAD")
            if actual != mount["commit"]:
                raise ValueError(f"Existing checkout has a different commit: {dest}")
            # Never reset a user's already-restored worktree.
            print(f"Keeping existing checkout: {mount['path']}")
            continue
        if dest.exists() and any(dest.iterdir()):
            raise ValueError(f"Refusing to overwrite a nonempty directory: {dest}")
        dest.parent.mkdir(parents=True, exist_ok=True)
        run_git("clone", "--quiet", "--no-hardlinks", "--no-checkout", str(bare), str(dest))
        run_git("-C", str(dest), "checkout", "--quiet", "--detach", mount["commit"])
        run_git("-C", str(dest), "config", "core.autocrlf", "false")
        run_git("-C", str(dest), "config", "core.symlinks", "true")
        print(f"Restored {mount['path']} @ {mount['commit'][:12]}")
    # Initialize parent submodule registrations without fetching or updating them.
    for mount in manifest["mounts"]:
        dest = safe_destination(root, "sources/" + mount["path"])
        if (dest / ".gitmodules").exists():
            run_git("-C", str(dest), "submodule", "init")
    print("Source snapshots restored. No build or upstream program was executed.")


def assemble(volumes: Path, output: Path) -> Path:
    control = volumes / f"{PREFIX}-000.zip"
    with zipfile.ZipFile(control) as z:
        index = json.loads(z.read("upload-index.json"))
    if index.get("format") != "cc-buildkit-volumes-v1":
        raise ValueError("Unrecognized upload index format")
    if len(index["parts"]) > 10000:
        raise ValueError("Unreasonable part count")
    output.mkdir(parents=True, exist_ok=True)
    payload = output / "buildkit.payload.zip"
    if payload.is_file() and sha256(payload) == index["payload_sha256"]:
        print("Reusing verified assembled payload.")
    else:
        partial = output / "buildkit.payload.zip.partial"
        total_h = hashlib.sha256()
        total_size = 0
        try:
            with partial.open("wb") as target:
                for i, part in enumerate(index["parts"], 1):
                    archive = safe_destination(volumes, part["zip"])
                    if not archive.is_file():
                        raise FileNotFoundError(f"Missing volume: {archive.name}")
                    if sha256(archive) != part["zip_sha256"]:
                        raise ValueError(f"ZIP checksum mismatch: {archive.name}")
                    part_h = hashlib.sha256()
                    part_size = 0
                    with zipfile.ZipFile(archive) as z:
                        if z.namelist() != [part["entry"]]:
                            raise ValueError(f"Unexpected contents in {archive.name}")
                        with z.open(part["entry"]) as src:
                            for data in iter(lambda: src.read(BUF), b""):
                                target.write(data)
                                part_h.update(data)
                                total_h.update(data)
                                part_size += len(data)
                                total_size += len(data)
                    if part_size != part["bytes"] or part_h.hexdigest() != part["sha256"]:
                        raise ValueError(f"Part checksum/size mismatch: {archive.name}")
                    print(f"Verified volume {i}/{len(index['parts'])}: {archive.name}")
            if total_size != index["payload_bytes"] or total_h.hexdigest() != index["payload_sha256"]:
                raise ValueError("Assembled payload checksum/size mismatch")
            partial.replace(payload)
        except BaseException:
            partial.unlink(missing_ok=True)
            raise
    return payload


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("volumes", type=Path, help="Directory containing every numbered ZIP, including -000.zip")
    ap.add_argument("--output", type=Path, default=Path("cc-buildkit"))
    ap.add_argument("--checkout", action="store_true", help="Restore pinned source Git trees offline; use on Linux")
    ap.add_argument("--verify-only", action="store_true", help="Verify/reassemble without extracting the payload")
    args = ap.parse_args()
    try:
        root = args.output.resolve()
        payload = assemble(args.volumes.resolve(), root)
        if args.verify_only:
            print(f"Verified payload: {payload}")
            return 0
        extract_regular_zip(payload, root)
        manifest = json.loads((root / "manifest.json").read_text(encoding="utf-8-sig"))
        if manifest.get("format") != "cc-buildkit-v1":
            raise ValueError("Unrecognized payload manifest format")
        for item in manifest["downloads"]:
            path = safe_destination(root, item["path"])
            if sha256(path) != item["sha256"]:
                raise ValueError(f"Downloaded-file checksum mismatch: {item['path']}")
        for item in manifest["repositories"]:
            path = safe_destination(root, item["archive"])
            if sha256(path) != item["sha256"]:
                raise ValueError(f"Git-snapshot checksum mismatch: {item['archive']}")
        print(f"All payload checksums verified. Build kit: {root}")
        if args.checkout:
            restore_sources(root, manifest)
        else:
            print("Use --checkout on Linux to materialize sources with executable bits and symlinks.")
        return 0
    except (OSError, ValueError, RuntimeError, KeyError, TypeError, zipfile.BadZipFile) as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())