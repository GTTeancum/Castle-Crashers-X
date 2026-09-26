#!/usr/bin/env python3
"""Independently audit ZIP PAKs and structurally scan cooked Flash-6 records.
Python 3.10+, standard library. This does not execute scripts or decode shapes.
"""
from __future__ import annotations
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import struct
import zipfile
TAGS={0:'End',1:'ShowFrame',2:'DefineShape',6:'DefineBits',8:'JPEGTables',9:'SetBackgroundColor',12:'DoAction',14:'DefineSound',20:'DefineBitsLossless',21:'DefineBitsJPEG2',22:'DefineShape2',26:'PlaceObject2',28:'RemoveObject2',32:'DefineShape3',34:'DefineButton2',35:'DefineBitsJPEG3',36:'DefineBitsLossless2',37:'DefineEditText',39:'DefineSprite',43:'FrameLabel',45:'SoundStreamHead2',48:'DefineFont2',56:'ExportAssets'}
def swf_scan(record: bytes) -> dict:
    if len(record)<24:raise ValueError('Short COK6 record')
    length,offset=struct.unpack_from('>II',record,16)
    if offset<24 or offset+length>len(record):raise ValueError('Wrapper out of bounds')
    b=record[offset:offset+length]
    if len(b)<13 or b[:4]!=b'FWS\x06':raise ValueError('Expected uncompressed Flash-6 header')
    counts=Counter();max_depth=0
    def walk(pos: int,end: int,depth: int=0) -> int:
        nonlocal max_depth
        if depth>64:raise ValueError('Sprite depth exceeds limit')
        max_depth=max(max_depth,depth)
        while pos<end:
            if pos+2>end:raise ValueError('Tag header truncated')
            h=struct.unpack_from('<H',b,pos)[0];pos+=2;code=h>>6;n=h&63
            if n==63:
                if pos+4>end:raise ValueError('Extended length truncated')
                n=struct.unpack_from('<I',b,pos)[0];pos+=4
            if n>end-pos:raise ValueError('Tag payload truncated')
            counts[code]+=1
            if code==0:
                if n:raise ValueError('Invalid End payload')
                return pos
            if code==39:
                if n<4:raise ValueError('Short sprite')
                walk(pos+4,pos+n,depth+1)
            pos+=n
        raise ValueError('No End tag')
    first=8+(5+4*(b[8]>>3)+7)//8+4
    end=walk(first,len(b))
    return dict(payload_offset=offset,payload_bytes=length,swf_version=b[3],declared_swf_bytes=struct.unpack_from('<I',b,4)[0],
                consumed_bytes=end,trailing_wrapper_payload_bytes=len(b)-end,max_depth=max_depth,status='ok',
                tags={TAGS.get(k,f'Tag{k}'):v for k,v in sorted(counts.items())})
def audit(root: Path) -> dict:
    members=[];swfs=[];methods=Counter();types=Counter();tags=Counter();failures=[]
    paks=sorted(root.rglob('*.pak'))
    for p in paks:
        with zipfile.ZipFile(p) as z:
            for info in z.infolist():
                data=z.read(info)  # Includes zipfile's CRC check.
                kind=data[:4].decode('ascii','replace');types[kind]+=1;methods[info.compress_type]+=1
                members.append(dict(pak=p.relative_to(root).as_posix(),member=info.filename,bytes=len(data),type=kind,
                                    crc32=f'{info.CRC:08x}',sha256=hashlib.sha256(data).hexdigest()))
                if kind=='COK6':
                    entry=dict(pak=p.relative_to(root).as_posix(),member=info.filename,bytes=len(data))
                    try:entry.update(swf_scan(data));tags.update(entry['tags'])
                    except ValueError as e:entry.update(status='error',error=str(e));failures.append(entry)
                    swfs.append(entry)
    if not paks:raise ValueError('No PAK files found')
    return dict(pak_count=len(paks),member_count=len(members),methods=dict(methods),brec_types=dict(types),
                zip_crc_failures=0,swf_count=len(swfs),swf_parse_status=dict(Counter(s['status'] for s in swfs)),
                swf_tags=dict(tags),swfs=swfs,members=members)
def main() -> int:
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('directory',type=Path);p.add_argument('--report',required=True,type=Path);a=p.parse_args()
    report=audit(a.directory);a.report.parent.mkdir(parents=True,exist_ok=True);a.report.write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps({k:v for k,v in report.items() if k not in ('swfs','members')},indent=2))
    return int(report['swf_parse_status'].get('error',0)!=0)
if __name__=='__main__':raise SystemExit(main())
