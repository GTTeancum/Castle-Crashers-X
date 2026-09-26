#!/usr/bin/env python3
"""Compare the independent Python and C++ probe output; no third-party packages."""
import json
from pathlib import Path
from audit_assets import TAGS
r=Path(__file__).resolve().parent.parent
p=json.loads((r/'reports/asset_manifest.json').read_text());c=json.loads((r/'reports/cpp_asset_probe.json').read_text())
for key in ('pak_count','member_count','swf_count','brec_types'):
    if p[key]!=c[key]:raise SystemExit(f'Mismatch: {key}')
if {TAGS.get(int(k),f'Tag{k}'):v for k,v in c['tags'].items()}!=p['swf_tags']:raise SystemExit('Tag counter mismatch')
message='PASS: independent Python/C++ inventories and every tag counter agree'
(r/'logs/cross-check.log').write_text(message+'\n');print(message)
