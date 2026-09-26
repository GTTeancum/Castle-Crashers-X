#!/usr/bin/env python3
"""Pair observed caller entries/exits with original lower-level draw emissions.
Only captured outputs are oracles. Missing/unsupported calls are rejected.
"""
from pathlib import Path
import argparse,collections,hashlib,json,struct,sys,re
sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'renderer004'))
from compile_capture import compile_frame,local
FIXED=752

def compile_callers(root):
    scene,sm=compile_frame(root)
    rows=[json.loads(x) for x in (root/'draws.jsonl').read_text().splitlines()]
    draws=rows[1:-1]; paired={};texids={}
    for d in draws:
        ix=d.get('parent_index')
        if not isinstance(ix,int) or ix<0 or ix>=4096 or ix in paired:raise ValueError('Missing/duplicate parent for emitted draw')
        paired[ix]=d
        if d['texture_file'] not in texids:texids[d['texture_file']]=len(texids)
    paths=sorted(root.glob('parent-[0-9][0-9][0-9][0-9][0-9].json'))
    if not 0<len(paths)<=4096:raise ValueError('Parent count')
    records=[];summary=[];scratch=0;matched=0
    for ix,path in enumerate(paths):
        m=json.loads(path.read_text());stem=path.stem;data=local(root,stem+'.bin').read_bytes()
        post=json.loads(local(root,stem+'-post.json').read_text())
        entry=m.get('entry')
        if m.get('format')!='CC-CALLER-INPUT-007' or m['index']!=ix or post['index']!=ix or post['entry']!=entry or entry not in (0x820a9068,0x820855d8):raise ValueError('Parent identity')
        ranges=[];off=0;end=0
        if not 0<len(m['ranges'])<=32 or not 0<len(data)<=16384:raise ValueError('Capacity')
        for item in m['ranges']:
            a,n,o=item['address'],item['bytes'],item['offset']
            if any(type(v)!=int for v in (a,n,o)) or a<end or n<=0 or a+n>2**32 or o!=off:raise ValueError('Range plan')
            ranges.append(struct.pack('<III',a,n,o));end=a+n;off+=n
        if off!=len(data):raise ValueError('Data size')
        def be(a,n=4):
            for item in m['ranges']:
                lo=item['address'];length=item['bytes']
                if lo<=a and a+n<=lo+length:
                    p=item['offset']+a-lo;return int.from_bytes(data[p:p+n],'big')
            raise ValueError(f'Missing input {a:08x}')
        if m.get('shader') not in (0,5):raise ValueError('Unsupported shader')
        if len(m['gpr'])!=32 or len(m['fpr'])!=32 or len(m['xer'])!=3 or len(m['cr'])!=8:raise ValueError('Context shape')
        if any(x not in (0,1) for x in m['xer']) or any(x not in range(16) for x in m['cr']):raise ValueError('Flags')
        ctx=struct.pack('<66Q4B8BI',*m['gpr'],*m['fpr'],m['lr'],m['ctr'],*m['xer'],0,*m['cr'],m['fpscr'])
        obj=m['gpr'][3 if entry==0x820a9068 else 5]&0xffffffff
        device=be(obj+4);descriptor=m['initial_texture'] if entry==0x820a9068 else be((m['gpr'][3]&0xffffffff)+92)
        d=paired.get(ix);n=1 if d else 0
        if d:
            expected=local(root,d['vertices_file']).read_bytes();matrix=d['matrix_words'];tex=texids[d['texture_file']];blend=d['blend_control'];matched+=1
            if len(expected)!=96 or descriptor!=d['texture'] or m['shader']!=d['shader']:raise ValueError('Descriptor/emission mismatch')
        else:
            expected=bytes(96);matrix=[be(device+1920+j*4) for j in range(16)];tex=0;blend=be(device+10552)
        if post['counter']!=be(0x8228a7c4)+n*4:raise ValueError('Unexpected counter transition')
        ret=post['r3'];flags=post['sprite_flags']
        if type(ret)!=int or ret<0 or ret>=2**64 or flags not in range(256):raise ValueError('Post state')
        head=struct.pack('<12I',len(ranges),len(data),m['shader'],entry,n,descriptor,m['initial_texture'],ret&0xffffffff,ret>>32,flags,post['counter'],0)
        record=head+ctx+expected+struct.pack('<16I',*matrix)+b''.join(ranges)+data
        assert len(record)==FIXED+len(ranges)*12+len(data)
        scratch=max(scratch,len(data));records.append((record,tex,blend))
        summary.append(dict(index=ix,entry=f'{entry:08X}',emissions=n,scratch=len(data),regions=len(ranges),input_sha256=hashlib.sha256(data).hexdigest(),output_sha256=hashlib.sha256(expected).hexdigest(),return_value=ret,sprite_flags=flags))
    if matched!=len(draws):raise ValueError('Unmatched draw')
    cursor=32+len(records)*16;table=[]
    for b,t,blend in records:table.append(struct.pack('<4I',cursor,len(b),t,blend));cursor+=len(b)
    blob=struct.pack('<8s6I',b'CCPF007\0',cursor,len(records),32,16,scratch,0)+b''.join(table)+b''.join(x[0] for x in records)
    if len(blob)>16*1024*1024:raise ValueError('Fixture size')
    manifest=dict(format='CCPF007',frame=rows[0]['frame'],calls=len(records),emissions=len(draws),no_draw_calls=len(records)-len(draws),entry_counts=dict(collections.Counter(s['entry'] for s in summary)),bytes=len(blob),max_scratch=scratch,sha256=hashlib.sha256(blob).hexdigest(),sources=summary,scope='Captured caller entries/exits and original draw emissions; not a live game loop.')
    return blob,manifest,scene,sm

def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('capture',type=Path);ap.add_argument('stem',type=Path);a=ap.parse_args()
    b,m,s,sm=compile_callers(a.capture);a.stem.parent.mkdir(parents=True,exist_ok=True)
    for ext,data in [('.ccp',b),('.ccr',s),('.json',(json.dumps(m,indent=2)+'\n').encode()),('.scene.json',(json.dumps(sm,indent=2)+'\n').encode())]:a.stem.with_suffix(ext).write_bytes(data)
    print(json.dumps({k:v for k,v in m.items() if k!='sources'},indent=2))
if __name__=='__main__':main()
