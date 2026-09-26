"""Extract the observed scalar slice; absent direct callees remain explicit failures."""
from pathlib import Path
import re,json,hashlib,csv
r=Path(__file__).resolve().parents[1];out=r/'runtime008';(out/'generated').mkdir(parents=True,exist_ok=True)
fs={};src={}
for p in (r/'pc/generated/default').glob('*recomp.*.cpp'):
 t=p.read_text();ms=list(re.finditer(r'DEFINE_REX_FUNC\((\w+)\)',t))
 for i,m in enumerate(ms):fs[m[1]]=t[m.start():ms[i+1].start() if i+1<len(ms) else len(t)].rstrip()+'\n';src[m[1]]=p.relative_to(r).as_posix()
seen=set();indirects=set()
for d in ('frame-001105','frame-001829'):
 for p in (r/'renderer008/captures'/d).glob('tree-[0-9][0-9][0-9][0-9][0-9].json'):
  m=json.loads(p.read_text());assert not m['errors'];seen|={n.removeprefix('__imp__') for n in m['functions']};indirects|={int(n,16) for n in m['indirects']}
# The previously verified quad adapter keeps its original four helpers separate.
seen-= {'sub_820A9308','__savefpr_20','__restfpr_20'}
seen|={'sub_820A7488'} # Original getter kept from 007; supported dispatch contract.
# infer helper entry addresses from original direct branch instructions/comments
addrs={n:int(n[4:],16) for n in seen if n.startswith('sub_')}
for b in fs.values():
 for a,n in re.findall(r'// b(?:l)? (0x[0-9a-f]+)\n\s*(?:ctx\.lr = [^;]+;\n\s*)?(\w+)\(ctx, base\)',b):
  if n in seen:
   v=int(a,16)
   if n in addrs and addrs[n]!=v:raise ValueError('conflicting helper address')
   addrs[n]=v
image=(r/'castle-crashers-port/reference/default.image.bin').read_bytes()
pdata={int(x['candidate_start'],16):((int(x['packed_metadata'],16)>>8)&0x3fffff)*4 for x in csv.DictReader((r/'castle-crashers-port/reports/pdata_candidates.csv').open())}
records=[];missing=set()
for n in sorted(seen):
 b=fs[n];a=addrs[n];nbytes=len(re.findall(r'^\s*// [a-z]',b,re.M))*4
 if a in pdata and pdata[a]!=nbytes:raise ValueError(f'Extent mismatch {n}: {nbytes} != {pdata[a]}')
 (out/'generated'/f'{n}.inc').write_text(b)
 records.append(dict(symbol=n,address=a,original_bytes=nbytes,original_sha256=hashlib.sha256(image[a-0x82000000:a-0x82000000+nbytes]).hexdigest(),generated_source=src[n],body_sha256=hashlib.sha256(b.encode()).hexdigest()))
 missing|=set(re.findall(r'(\w+)\(ctx, base\)',b))-seen
missing-={'sub_820A9308'}
(out/'provenance.json').write_text(json.dumps({'image_sha256':hashlib.sha256(image).hexdigest(),'functions':records,'unsupported_direct':sorted(missing),'observed_indirects':sorted(indirects)},indent=2)+'\n')
(out/'bodies.inc').write_text('\n'.join(f'static void {n}(Context&, Machine&);' for n in sorted(seen|missing))+'\n'+'\n'.join(f'#include "generated/{n}.inc"' for n in sorted(seen))+'\n'+'\n'.join(f'static void {n}(Context&, Machine& base) {{ base.fail(Error::unsupported, 0x{n[4:]}u); }}' for n in sorted(missing))+'\n')
(out/'dispatch.inc').write_text('\n'.join(f'case 0x{a:08x}: {"sub_"+format(a,"08X")}(ctx,base); return;' for a in sorted(indirects|{0x820a7488}) if a not in (0x820a9308,0x820a89f8))+'\n')
print('Extracted',len(records),'unchanged bodies; unsupported direct callees',sorted(missing))
