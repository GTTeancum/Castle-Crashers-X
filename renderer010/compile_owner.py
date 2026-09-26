#!/usr/bin/env python3
"""Compile real before/after rooted traces. Never synthesize absent memory or draws."""
from pathlib import Path
import argparse,hashlib,json,struct,sys
sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'renderer004'))
from compile_capture import compile_frame,local
CTX=544; FIXED=48+2*CTX; DRAW=176

def context(m):
 if len(m['gpr'])!=32 or len(m['fpr'])!=32 or len(m['cr'])!=8 or len(m['xer'])!=3:raise ValueError('Context shape')
 if any(x not in range(16) for x in m['cr']) or any(x not in (0,1) for x in m['xer']):raise ValueError('Context flags')
 return struct.pack('<66Q4B8BI',*m['gpr'],*m['fpr'],m['lr'],m['ctr'],*m['xer'],0,*m['cr'],m['fpscr'])

def compact(pages,before,after,mask,writes,sp):
 if not pages or len(pages)>2048 or pages!=sorted(set(pages)) or any(x%4096 or x<0 or x>0xfffff000 for x in pages):raise ValueError('Page plan')
 if not len(before)==len(after)==len(mask)==len(writes)==len(pages)*4096:raise ValueError('Page bytes')
 if any(x not in (0,1) for x in mask+writes):raise ValueError('Invalid access masks')
 # Retain the real working stack and a checked-call margin, not the 16 KiB
 # capture-only prefetch on every glyph. Missing accesses still fail at runtime.
 low=sp-2048
 for i,p in enumerate(pages):
  if sp-16384<=p<sp+128:
   ws=writes[i*4096:(i+1)*4096]
   found=ws.find(b'\1')
   if found>=0:low=min(low,p+found-512)
 low=(low//16)*16
 segments=[];blocks=[]
 for i,p in enumerate(pages):
  if blocks and blocks[-1][1]==p:blocks[-1][1]+=4096
  else:blocks.append([p,p+4096])
  m=bytearray(mask[i*4096:(i+1)*4096])
  for j in range(4096):
   a=p+j
   if sp-16384<=a<sp+128:m[j]=int(low<=a<sp+128)
  # Legacy validated quad contract requires the complete 16-byte constant span.
  for a,n in [(0x8201473c,16)]:
   for off in range(max(p,a),min(p+4096,a+n)):m[off-p]=1
  j=0
  while j<4096:
   if not m[j]:j+=1;continue
   start=j
   while j<4096 and m[j]:j+=1
   a=p+start//16*16;b=p+(j+15)//16*16
   if segments and a<=segments[-1][1]:segments[-1][1]=max(b,segments[-1][1])
   else:segments.append([a,b])
 while len(segments)>64:
  candidates=[]
  for i in range(len(segments)-1):
   a,b=segments[i][1],segments[i+1][0]
   if any(lo<=a<=b<=hi for lo,hi in blocks):candidates.append((b-a,i))
  if not candidates:raise ValueError('Too many discontiguous regions')
  _,i=min(candidates);segments[i][1]=segments[i+1][1];del segments[i+1]
 index={p:i for i,p in enumerate(pages)}
 def take(data,a,b):
  out=bytearray()
  while a<b:
   page=a&~4095;amount=min(b-a,4096-(a-page));off=index[page]*4096+a-page;out+=data[off:off+amount];a+=amount
  return bytes(out)
 bs=b''.join(take(before,a,b) for a,b in segments);es=b''.join(take(after,a,b) for a,b in segments);ws=bytearray(b''.join(take(writes,a,b) for a,b in segments));off=0;rs=[]
 for a,b in segments:
  for j in range(b-a):
   if sp-16384<=a+j<sp+128:ws[off+j]=0 # ABI/callee-save checks cover stack, not omitted GPU callees' scratch bytes.
  rs.append((a,b-a,off));off+=b-a
 if off>262144:raise ValueError('Scratch capacity')
 return rs,bs,es,bytes(ws)

def compile_scene(root):
 scene,sm=compile_frame(root);rows=[json.loads(x) for x in (root/'draws.jsonl').read_text().splitlines()];draws=rows[1:-1]
 textures={};bytree={}
 for d in draws:
  k=d.get('tree_index');
  if type(k)!=int or k==0xffffffff:raise ValueError('Draw outside captured roots')
  bytree.setdefault(k,[]).append(d)
  if d['texture_file'] not in textures:textures[d['texture_file']]=len(textures)
 records=[];report=[];cursor_draw=0;maxmem=0
 paths=sorted(root.glob('tree-[0-9][0-9][0-9][0-9][0-9].json'))
 if not 0<len(paths)<=4096:raise ValueError('Root count')
 for ix,p in enumerate(paths):
  m=json.loads(p.read_text());stem=p.stem;pre=json.loads(local(root,stem+'-pre.json').read_text());post=json.loads(local(root,stem+'-post.json').read_text())
  if m['errors'] or m['index']!=ix or pre['index']!=ix or m['entry']!=pre['entry'] or m['entry'] not in (0x8208a7a0,0x820a8ff8,0x82091248):raise ValueError('Root identity/errors')
  ds=bytree.get(ix,[])
  if pre['draw_begin']!=cursor_draw or post['draw_end']!=cursor_draw+len(ds):raise ValueError('Missing root emissions')
  mem=[local(root,stem+'-'+k+'.bin').read_bytes() for k in ('before','after','mask','writes')]
  rs,b,a,w=compact(m['pages'],*mem,pre['gpr'][1]&0xffffffff);maxmem=max(maxmem,len(b))
  def be(addr,data=b):
   for lo,n,off in rs:
    if lo<=addr and addr+4<=lo+n:return int.from_bytes(data[off+addr-lo:off+addr-lo+4],'big')
   raise ValueError(f'Missing counter {addr:08x}')
  counter_observed=any(lo<=0x8228a7c4 and 0x8228a7c8<=lo+n for lo,n,off in rs)
  if not counter_observed and ds:raise ValueError('Missing emitting-root counter')
  count0,count1=(be(0x8228a7c4),be(0x8228a7c4,a)) if counter_observed else (0,0)
  if count1!=count0+4*len(ds):raise ValueError('Counter transition')
  ddata=bytearray()
  for d in ds:
   vertices=local(root,d['vertices_file']).read_bytes()
   if len(vertices)!=96:raise ValueError('Vertex length')
   ddata+=struct.pack('<4I16I',d['texture'],textures[d['texture_file']],d['blend_control'],0,*d['matrix_words'])+vertices
  head=struct.pack('<12I',m['entry'],len(rs),len(b),len(ds),pre['initial_texture'],count0,count1,m['functions'].get('__imp__sub_8208A7A0',0),sum(m['indirects'].values()),m['indirects'].get('820a89f8',0),int(not counter_observed),0)
  record=head+context(pre)+context(post)+b''.join(struct.pack('<3I',*x) for x in rs)+b+a+w+ddata
  assert len(record)==FIXED+12*len(rs)+3*len(b)+DRAW*len(ds)
  records.append((record,cursor_draw,ix));cursor_draw+=len(ds)
  report.append(dict(index=ix,entry=hex(m['entry']),draws=len(ds),scratch=len(b),regions=len(rs),tree_visits=m['functions'].get('__imp__sub_8208A7A0',0),write_check_bytes=sum(w),input_sha256=hashlib.sha256(b).hexdigest(),counter_before=count0 if counter_observed else None,counter_after=count1 if counter_observed else None,counter_observed=counter_observed))
 if cursor_draw!=len(draws):raise ValueError('Unmatched draws')
 cursor=32+16*len(records);table=[]
 for rec,ds,ix in records:table.append(struct.pack('<4I',cursor,len(rec),ds,ix));cursor+=len(rec)
 blob=struct.pack('<8s6I',b'CCST008\0',cursor,len(records),32,16,maxmem,len(draws))+b''.join(table)+b''.join(x[0] for x in records)
 if len(blob)>32*1024*1024:raise ValueError('Snapshot size')
 return blob,dict(format='CCST008',frame=rows[0]['frame'],calls=len(records),draws=len(draws),max_scratch=maxmem,bytes=len(blob),sha256=hashlib.sha256(blob).hexdigest(),cases=report),scene,sm

def main():
 ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('capture',type=Path);ap.add_argument('stem',type=Path);a=ap.parse_args()
 b,m,s,sm=compile_scene(a.capture);a.stem.parent.mkdir(parents=True,exist_ok=True)
 for ext,data in [('.cct',b),('.ccr',s),('.json',(json.dumps(m,indent=2)+'\n').encode()),('.scene.json',(json.dumps(sm,indent=2)+'\n').encode())]:a.stem.with_suffix(ext).write_bytes(data)
 print(json.dumps({k:v for k,v in m.items() if k!='cases'},indent=2))
if __name__=='__main__':main()
