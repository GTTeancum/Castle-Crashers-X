#!/usr/bin/env python3
"""Serialize complete passive pre-call snapshots and matching PC emissions.
Not a source of final geometry for the target: the target regenerates it using game code.
Expected output is retained only for the acceptance comparison.
"""
from pathlib import Path
import argparse,collections,hashlib,json,struct,sys
sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'renderer004'))
from compile_capture import compile_frame,local
MAGIC=b'CCQF006\0'; FIXED=720

def compile_inputs(root):
    rec=[json.loads(x) for x in (root/'draws.jsonl').read_text().splitlines()]
    # The independent replay converter is also the existing full-frame contract validator.
    scene,scene_manifest=compile_frame(root)
    texture_ids={}; calls=[]; sources=[]; used=set(); max_scratch=0
    for d in rec[1:-1]:
        ix=d['input_index']
        if not isinstance(ix,int) or ix<0 or ix>=4096 or ix in used:raise ValueError('Missing/duplicate quad input')
        used.add(ix);stem=f'input-{ix:05d}'
        m=json.loads(local(root,stem+'.json').read_text());data=local(root,stem+'.bin').read_bytes()
        if m.get('format')!='CC-QUAD-INPUT-006' or m['index']!=ix or m['shader']!=d['shader']:raise ValueError('Input identity mismatch')
        if len(data)>16384 or not 1<=len(m['ranges'])<=32:raise ValueError('Input workspace limit')
        max_scratch=max(max_scratch,len(data));ranges=[];offset=0;last_end=0
        for r in m['ranges']:
            a,n,o=r['address'],r['bytes'],r['offset']
            if not all(isinstance(x,int) for x in (a,n,o)) or n<=0 or a<last_end or a+n>2**32 or o!=offset:raise ValueError('Invalid range plan')
            ranges.append(struct.pack('<III',a,n,o));last_end=a+n;offset+=n
        if offset!=len(data):raise ValueError('Range byte count')
        if len(m['gpr'])!=32 or len(m['fpr'])!=32 or len(m['xer'])!=3 or len(m['cr'])!=8:raise ValueError('Context shape')
        if any(x not in range(16) for x in m['cr']) or any(x not in (0,1) for x in m['xer']):raise ValueError('Context flags')
        ctx=struct.pack('<66Q4B8BI',*m['gpr'],*m['fpr'],m['lr'],m['ctr'],*m['xer'],0,*m['cr'],m['fpscr'])
        if len(ctx)!=544:raise AssertionError('context width')
        expected=local(root,d['vertices_file']).read_bytes()
        if len(expected)!=96:raise ValueError('Expected vertex size')
        head=struct.pack('<4I',len(ranges),len(data),m['shader'],0)
        record=head+ctx+expected+struct.pack('<16I',*d['matrix_words'])+b''.join(ranges)+data
        if len(record)!=FIXED+12*len(ranges)+len(data):raise AssertionError('record layout')
        if d['texture_file'] not in texture_ids:texture_ids[d['texture_file']]=len(texture_ids)
        calls.append((record,texture_ids[d['texture_file']],d['blend_control']))
        sources.append({'input_index':ix,'input_sha256':hashlib.sha256(data).hexdigest(),'expected_sha256':hashlib.sha256(expected).hexdigest(),'regions':len(ranges),'scratch_bytes':len(data),'shader':m['shader']})
    if len(used)!=len(list(root.glob('input-*.json'))):raise ValueError('Unpaired generated routine call in frame')
    offset=32+16*len(calls);table=[]
    for c,tex,blend in calls:table.append(struct.pack('<4I',offset,len(c),tex,blend));offset+=len(c)
    result=struct.pack('<8s6I',MAGIC,offset,len(calls),32,16,max_scratch,0)+b''.join(table)+b''.join(c for c,_,_ in calls)
    manifest={'format':'CCQF006','capture_frame':rec[0]['frame'],'calls':len(calls),'max_scratch':max_scratch,'total_bytes':len(result),'sha256':hashlib.sha256(result).hexdigest(),'scene_sha256':scene_manifest['replay_sha256'],'sources':sources,'scope':'Observed input snapshots and exact generated-function output oracle, not a live game update loop.'}
    return result,manifest,scene,scene_manifest

def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('capture',type=Path);ap.add_argument('stem',type=Path);a=ap.parse_args()
    data,m,scene,sm=compile_inputs(a.capture);a.stem.parent.mkdir(parents=True,exist_ok=True)
    a.stem.with_suffix('.ccq').write_bytes(data);a.stem.with_suffix('.ccr').write_bytes(scene)
    a.stem.with_suffix('.json').write_text(json.dumps(m,indent=2)+'\n');a.stem.with_suffix('.scene.json').write_text(json.dumps(sm,indent=2)+'\n')
    print(json.dumps({k:v for k,v in m.items() if k!='sources'},indent=2))
if __name__=='__main__':main()
