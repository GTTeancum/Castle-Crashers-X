#!/usr/bin/env python3
"""Read-only STFS extraction with bounds, chains, paths and SHA-1 validation.

Independent Python implementation using the public on-disk definitions referenced
in SOURCES.md. Only the single-hash-table, read-only STFS layout is supported.
This is deliberately not a package editor, license patcher, or signature verifier.
Python 3.10+, standard library only.
"""
from __future__ import annotations
import argparse
from collections import Counter
import hashlib
import json
import mmap
from pathlib import Path
import sys

BLOCK = 4096
END = 0xFFFFFF

class FormatError(ValueError):
    pass

class STFS:
    def __init__(self, data: mmap.mmap):
        self.data = data
        if len(data) < 0x971A or data[:4] not in (b'LIVE', b'PIRS', b'CON '):
            raise FormatError('Not a complete supported STFS header')
        self.header_size = self.uint(0x340, 4)
        self.base = (self.header_size + BLOCK - 1) & ~(BLOCK - 1)
        if self.header_size < 0x971A or self.base > len(data):
            raise FormatError('Invalid header length')
        if self.uint(0x3A9, 4) != 0:
            raise FormatError('SVOD is not supported by this tool')
        if self.uint(0x379, 1) != 0x24 or not self.uint(0x37B, 1) & 1:
            raise FormatError('Only read-only, single-copy STFS hash tables supported')
        self.total = self.uint(0x395, 4)
        if self.total < 1 or self.total > 170**3:
            raise FormatError('Data block count out of supported range')
        self.verified: set[int] = set()

    def read(self, offset: int, size: int) -> bytes:
        if offset < 0 or size < 0 or offset + size > len(self.data):
            raise FormatError(f'Out-of-bounds read: 0x{offset:X} + {size}')
        return self.data[offset:offset + size]

    def uint(self, offset: int, size: int, endian: str = 'big') -> int:
        return int.from_bytes(self.read(offset, size), endian)

    def data_offset(self, block: int) -> int:
        if not 0 <= block < self.total:
            raise FormatError(f'Invalid data block {block}')
        physical = block
        span = 170
        for _ in range(3):
            physical += (block + span) // span
            if block < span:
                break
            span *= 170
        return self.base + physical * BLOCK

    def hash_table_offset(self, block: int, level: int) -> int:
        if level == 0:
            n = 0 if block < 170 else ((block // 170) * 171 + (block // 28900) + 1 + (1 if block >= 28900 else 0))
        elif level == 1:
            n = 171 if block < 28900 else (block // 28900) * 29071 + 1
        elif level == 2:
            n = 29071
        else:
            raise FormatError('Invalid hash level')
        return self.base + n * BLOCK

    def hash_entry(self, block: int) -> bytes:
        return self.read(self.hash_table_offset(block, 0) + (block % 170) * 24, 24)

    def block(self, number: int) -> tuple[bytes, int]:
        raw = self.read(self.data_offset(number), BLOCK)
        entry = self.hash_entry(number)
        if hashlib.sha1(raw).digest() != entry[:20]:
            raise FormatError(f'SHA-1 mismatch at data block {number}')
        self.verified.add(number)
        return raw, int.from_bytes(entry[21:24], 'big')

    def chain(self, start: int, count: int) -> list[tuple[int, bytes]]:
        if count > self.total:
            raise FormatError('Chain too long')
        seen: set[int] = set()
        result = []
        current = start
        for _ in range(count):
            if current in seen:
                raise FormatError(f'Cycle at block {current}')
            seen.add(current)
            raw, nxt = self.block(current)
            result.append((current, raw))
            current = nxt
        if count and current != END:
            raise FormatError(f'Expected chain end, found {current}')
        return result

    def entries(self) -> list[dict]:
        count = self.uint(0x37C, 2, 'little')
        first = self.uint(0x37E, 3, 'little')
        records = []
        for page_index, (_, raw) in enumerate(self.chain(first, count)):
            for slot in range(64):
                e = raw[slot * 64:(slot + 1) * 64]
                if not e[0]:
                    continue
                n = e[40] & 63
                if not 1 <= n <= 40:
                    raise FormatError('Invalid name length')
                name = e[:n].decode('utf-8', errors='strict')
                if name in ('.', '..') or any(c in name for c in ('/', '\\', ':', '\0')):
                    raise FormatError(f'Unsafe filename: {name!r}')
                records.append(dict(index=page_index * 64 + slot, name=name,
                    directory=bool(e[40] & 0x80), contiguous=bool(e[40] & 0x40),
                    valid_blocks=int.from_bytes(e[41:44], 'little'),
                    allocated_blocks=int.from_bytes(e[44:47], 'little'),
                    start_block=int.from_bytes(e[47:50], 'little'),
                    parent=int.from_bytes(e[50:52], 'big'),
                    size=int.from_bytes(e[52:56], 'big')))
        lookup = {e['index']: e for e in records}
        def resolve(e: dict, ancestors: set[int]) -> str:
            if e['index'] in ancestors:
                raise FormatError('Directory cycle')
            if e['parent'] == 65535:
                return e['name']
            parent = lookup.get(e['parent'])
            if parent is None or not parent['directory']:
                raise FormatError('Missing parent directory')
            return resolve(parent, ancestors | {e['index']}) + '/' + e['name']
        used = set()
        for e in records:
            e['path'] = resolve(e, set())
            if e['path'].casefold() in used:
                raise FormatError('Duplicate output path')
            used.add(e['path'].casefold())
        return records

    def verify_tree(self) -> dict:
        # Check all stored data blocks, then every populated table up to the root.
        for b in range(self.total):
            self.block(b)
        l0_blocks = list(range(0, self.total, 170))
        if self.total > 170:
            for b in l0_blocks:
                table = self.read(self.hash_table_offset(b, 0), BLOCK)
                parent = self.hash_table_offset(b, 1) + ((b // 170) % 170) * 24
                if hashlib.sha1(table).digest() != self.read(parent, 20):
                    raise FormatError(f'Level-0 hash table mismatch at {b}')
        if self.total > 28900:
            for b in range(0, self.total, 28900):
                table = self.read(self.hash_table_offset(b, 1), BLOCK)
                parent = self.hash_table_offset(b, 2) + (b // 28900) * 24
                if hashlib.sha1(table).digest() != self.read(parent, 20):
                    raise FormatError(f'Level-1 hash table mismatch at {b}')
        root_level = 2 if self.total > 28900 else 1 if self.total > 170 else 0
        root = self.read(self.hash_table_offset(0, root_level), BLOCK)
        root_ok = hashlib.sha1(root).digest() == self.read(0x381, 20)
        if not root_ok:
            raise FormatError('Root hash table digest mismatch')
        return dict(data_blocks_checked=len(self.verified), data_block_mismatches=0,
                    l0_tables_checked=len(l0_blocks), root_level=root_level,
                    hash_tree_to_descriptor_verified=True, rsa_signature_checked=False)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('container', type=Path)
    ap.add_argument('--output', required=True, type=Path)
    ap.add_argument('--manifest', required=True, type=Path)
    args = ap.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    root = args.output.resolve()
    with args.container.open('rb') as stream, mmap.mmap(stream.fileno(), 0, access=mmap.ACCESS_READ) as raw:
        stfs = STFS(raw)
        entries = stfs.entries()
        occupied = set()
        for e in entries:
            dest = root / e['path']
            if not dest.resolve().is_relative_to(root):
                raise FormatError('Output path escapes root')
            if e['directory']:
                dest.mkdir(parents=True, exist_ok=True)
                continue
            n = (e['size'] + BLOCK - 1) // BLOCK
            if e['allocated_blocks'] != n or e['valid_blocks'] != n:
                raise FormatError(f'Allocation differs from file length: {e["path"]}')
            blocks = stfs.chain(e['start_block'], n)
            for block_id, _ in blocks:
                if block_id in occupied:
                    raise FormatError('Files share an allocated block')
                occupied.add(block_id)
            data = b''.join(b for _, b in blocks)[:e['size']]
            dest.parent.mkdir(parents=True, exist_ok=True)
            if dest.exists():
                if dest.is_symlink() or dest.read_bytes() != data:
                    raise FormatError(f'Refusing to overwrite different content: {dest}')
            else:
                dest.write_bytes(data)
            e['sha256'] = hashlib.sha256(data).hexdigest()
            e['first_16_bytes'] = data[:16].hex()
        integrity = stfs.verify_tree()
        files = [e for e in entries if not e['directory']]
        ext = Counter(Path(e['path']).suffix.lower() or '(none)' for e in files)
        manifest = dict(input_name=args.container.name, input_bytes=len(raw),
            input_sha256=hashlib.sha256(raw).hexdigest(), magic=raw[:4].decode('ascii'),
            title=stfs.read(0x411, 256).decode('utf-16-be').split('\0')[0],
            title_id=f'{stfs.uint(0x360,4):08X}', media_id=f'{stfs.uint(0x354,4):08X}',
            version_raw=f'{stfs.uint(0x358,4):08X}',
            content_type=f'{stfs.uint(0x344,4):08X}',
            file_count=len(files), directory_count=len(entries)-len(files),
            extracted_bytes=sum(e['size'] for e in files), extensions=dict(ext),
            integrity=integrity, entries=entries)
        args.manifest.parent.mkdir(parents=True, exist_ok=True)
        args.manifest.write_text(json.dumps(manifest, indent=2) + '\n', encoding='utf-8')
        print(json.dumps({k:v for k,v in manifest.items() if k != 'entries'}, indent=2))
        print('\nLargest files:')
        for e in sorted(files, key=lambda e:e['size'], reverse=True)[:20]:
            print(f'{e["size"]:12,d}  {e["path"]}')

if __name__ == '__main__':
    try:
        main()
    except (OSError, ValueError) as error:
        print(f'ERROR: {error}', file=sys.stderr)
        sys.exit(1)
