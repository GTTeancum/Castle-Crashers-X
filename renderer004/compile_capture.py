#!/usr/bin/env python3
"""Normalize the observed quad/texture subset. Refuses unsupported or incomplete captures."""
import argparse,hashlib,json,math,re,struct
from pathlib import Path
MAGIC=b'CCRP004\0'

def local(root,name):
    if not isinstance(name,str) or not re.fullmatch(r'[a-zA-Z0-9_.-]+',name):raise ValueError('Unsafe capture member')
    p=root/name
    if not p.resolve().is_relative_to(root.resolve()):raise ValueError("Capture member leaves root")
    return p

def decode_texture(root,stem):
    m=json.loads(local(root,stem+'.json').read_text());raw=local(root,stem+'.bin').read_bytes()
    w,h=m['padded_width'],m['padded_height'];fmt=m['format']
    if not 0<w<=2048 or not 0<h<=2048 or w&(w-1) or h&(h-1):raise ValueError('Unsupported texture dimensions')
    if len(raw)!=m['bytes']:raise ValueError('Texture size mismatch')
    if fmt==1:
        if len(raw)!=w*h*4:raise ValueError('RGBA size mismatch')
        # Game format 1 is big-endian A8R8G8B8; preserve D3D channel swizzle.
        rgba=bytearray(len(raw))
        for k,source in enumerate((1,2,3,0)):rgba[k::4]=raw[source::4]
    elif fmt==5:
        if len(raw)!=w*h*2:raise ValueError('RGBA4444 size mismatch')
        # Format register 0x1828004F: k_4_4_4_4 + k8in16, NOT alpha8.
        # Game format 5 is big-endian A4R4G4B4 (the D3D R/B swizzle matters).
        rgba=bytearray(w*h*4)
        for i,(word,) in enumerate(struct.iter_unpack('>H',raw)):
            rgba[i*4:i*4+4]=bytes(((word>>shift)&15)*17 for shift in (8,4,0,12))
    else:raise ValueError(f'Unsupported texture format {fmt}; not silently replaced')
    return w,h,bytes(rgba),m

def compile_frame(root,width=640,height=480):
    if not 1<=width<=1920 or not 1<=height<=1080:raise ValueError('Invalid output size')
    records=[json.loads(s) for s in (root/'draws.jsonl').read_text().splitlines()]
    if not records or records[0]['event']!='begin' or records[-1]['event']!='end':raise ValueError('Incomplete frame')
    if any(r.get('event')!='draw' for r in records[1:-1]):raise ValueError('Unknown or misplaced capture event')
    ds=records[1:-1]
    if records[-1]['draws']!=len(ds) or records[-1]['read_failures']!=0:raise ValueError('Capture read/count failure')
    texs=[];tex_ids={};commands=[];sources=[]
    if not 0<len(ds)<=4096:raise ValueError('Invalid draw count')
    for d in ds:
        if d['index']!=len(commands):raise ValueError('Nonsequential draws')
        if (d['primitive'],d['count'],d['stride'])!=(13,4,24) or d['shader'] not in (0,5):raise ValueError(f'Unsupported draw {d["index"]}: {d}')
        blend=d['blend_control']
        if blend not in (0x07010701,0x00010001):raise ValueError(f'Unsupported blend {blend:08x}')
        stem=d['texture_file']
        if not stem:raise ValueError('Missing captured texture')
        if stem not in tex_ids:
            tex_ids[stem]=len(texs);w,h,rgba,m=decode_texture(root,stem);texs.append((w,h,rgba));sources.append({'capture_name':stem,'width':w,'height':h,'format':m['format'],'raw_sha256':hashlib.sha256(local(root,stem+'.bin').read_bytes()).hexdigest(),'rgba_sha256':hashlib.sha256(rgba).hexdigest()})
        matrix=[struct.unpack('>f',struct.pack('>I',u))[0] for u in d['matrix_words']]
        if len(matrix)!=16 or not all(math.isfinite(v) for v in matrix) or not any(matrix):raise ValueError('Invalid/uninitialized projection')
        raw=local(root,d['vertices_file']).read_bytes()
        if len(raw)!=96:raise ValueError('Vertex size mismatch')
        vertices=[]
        for v in struct.iter_unpack('>5fI',raw):
            x,y,z,u,vv,argb=v
            if not all(math.isfinite(f) for f in (x,y,z,u,vv)):raise ValueError('Nonfinite vertex')
            p=[sum(c*matrix[i*4+j] for i,c in enumerate((x,y,z,1))) for j in range(4)]
            # The accepted fixture is affine. Perspective would require W-correct interpolation.
            if abs(p[3]-1)>1e-6:raise ValueError('Perspective projection not implemented')
            px=(p[0]+1)*width*.5;py=(1-p[1])*height*.5
            if abs(px)>1e6 or abs(py)>1e6 or abs(u)>32 or abs(vv)>32:raise ValueError('Out of limits')
            vertices.append((px,py,p[2],u,vv,argb))
        commands.append(struct.pack('<II',tex_ids[stem],blend)+b''.join(struct.pack('<5fI',*v) for v in vertices))
    if len(texs)>512:raise ValueError('Too many textures')
    tt=36;dt=tt+len(texs)*16;cursor=dt+len(commands)*104;table=[]
    for w,h,rgba in texs:table.append(struct.pack('<IIII',w,h,cursor,len(rgba)));cursor+=len(rgba)
    if cursor>32*1024*1024:raise ValueError('Replay exceeds 32 MiB limit')
    blob=struct.pack('<8s7I',MAGIC,width,height,len(texs),len(commands),tt,dt,cursor)+b''.join(table)+b''.join(commands)+b''.join(t[2] for t in texs)
    if len(blob)!=cursor:raise AssertionError('Serialization size mismatch')
    manifest={'format':'CCRP004','capture_frame':records[0]['frame'],'draws':len(commands),'triangles':len(commands)*2,'textures':len(texs),'texture_bytes':sum(len(t[2]) for t in texs),'replay_bytes':len(blob),'replay_sha256':hashlib.sha256(blob).hexdigest(),'width':width,'height':height,'sources':sources,'limitations':['Frozen observed quad subset, not a running game.','Only shader IDs 0 and 5 with 24-byte vertices and additive ONE/ZERO or ONE/INV_SRC_ALPHA blends.','No stencil/depth/extra render target/effect recreation.','Color space and half-pixel fidelity not certified.']}
    return blob,manifest

def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('capture',type=Path);ap.add_argument('output',type=Path);ap.add_argument('--width',type=int,default=640);ap.add_argument('--height',type=int,default=480);a=ap.parse_args()
    blob,m=compile_frame(a.capture,a.width,a.height);a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_bytes(blob);a.output.with_suffix('.json').write_text(json.dumps(m,indent=2)+'\n');print(json.dumps({k:v for k,v in m.items() if k!='sources'},indent=2))
if __name__=='__main__':main()
