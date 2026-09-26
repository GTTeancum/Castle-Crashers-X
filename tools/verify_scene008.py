#!/usr/bin/env python3
"""Verify unchanged scene bodies against the supplied game and generated PC source."""
from pathlib import Path
import argparse, csv, hashlib, json, re
R=Path(__file__).resolve().parents[1]
def sha(b):return hashlib.sha256(b).hexdigest()
def verify(root=R):
 image=(root/'castle-crashers-port/reference/default.image.bin').read_bytes()
 pdata={int(x['candidate_start'],16):((int(x['packed_metadata'],16)>>8)&0x3fffff)*4 for x in csv.DictReader((root/'castle-crashers-port/reports/pdata_candidates.csv').open())}
 functions={};duplicates=[];checks=[]
 for folder in ('runtime008','runtime006'):
  m=json.loads((root/folder/'provenance.json').read_text())
  if sha(image)!=m['image_sha256']:raise ValueError('Wrong supplied image')
  for f in m['functions']:
   a=int(f['address'],16) if isinstance(f['address'],str) else f['address'];n=f['original_bytes'];name=f['symbol']
   raw=image[a-0x82000000:a-0x82000000+n]
   if len(raw)!=n or sha(raw)!=f['original_sha256']:raise ValueError('Original extent mismatch: '+name)
   source=(root/f['generated_source']).read_text();pattern=r'DEFINE_REX_FUNC\('+re.escape(name)+r'\)'
   found=list(re.finditer(pattern,source))
   if len(found)!=1:raise ValueError('Missing/duplicate body: '+name)
   start=found[0].start();end=source.find('\nDEFINE_REX_FUNC(',start+1);body=(source[start:end if end>=0 else len(source)].rstrip()+'\n').encode()
   stored=root/folder/'generated'/f'{name}.inc'
   if not stored.exists():stored=root/folder/f'{name}.inc'
   if sha(body)!=f['body_sha256'] or body!=stored.read_bytes():raise ValueError('Changed generated body: '+name)
   if a in pdata and pdata[a]!=n:raise ValueError('Original pdata mismatch: '+name)
   if name in functions:
    if functions[name]!=f['body_sha256']:raise ValueError('Conflicting included body')
    duplicates.append(name)
   functions[name]=f['body_sha256'];checks.append(dict(symbol=name,address=hex(a),bytes=n,source_adapter=folder,pdata=pdata.get(a),sha256=f['body_sha256']))
 prior=set()
 for folder in ('runtime007','runtime006'):prior.update(x['symbol']for x in json.loads((root/folder/'provenance.json').read_text())['functions'])
 return dict(result='passed',unique_original_entries=len(functions),new_relative_to_007=sorted(set(functions)-prior),new_entry_count=len(set(functions)-prior),duplicate_included_helper_entries=duplicates,checks=checks,scope='Entry/body counts include overlapping compiler helpers, not disjoint native bytes or a game-coverage percentage.')
if __name__=='__main__':
 ap=argparse.ArgumentParser();ap.add_argument('--root',type=Path,default=R);a=ap.parse_args();print(json.dumps(verify(a.root),indent=2))
