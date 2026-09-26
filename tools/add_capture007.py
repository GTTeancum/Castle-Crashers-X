#!/usr/bin/env python3
"""One-time observer migration from the unmodified 006 source. Normal builds use
already-migrated source; refuse a second application instead of duplicating hooks.
"""
from pathlib import Path
r=Path(__file__).resolve().parents[1]
if 'caller_capture007.inc' in (r/'pc/src/render_capture004.cpp').read_text():
 raise SystemExit('007 observer already present; no changes made')
old=(r/'pc/src/quad_capture006.inc').read_text()
serializer=old[old.index(' char stem[48]'):]
serializer=serializer.replace('input-%05u','parent-%05u').replace('CC-QUAD-INPUT-006','CC-CALLER-INPUT-007')
serializer=serializer.replace('id,shader);','id,shader);')
serializer=serializer.replace('size_t off=0;', 'size_t off=0;')
serializer=serializer.replace('std::fprintf(f,"]}\\n");std::fclose(f);active_quad=id;', '''std::fprintf(f,"],\\\"entry\\\":%u,\\\"initial_texture\\\":%u}\\n",entry,texture);std::fclose(f);active_parent=id;return id;''')
serializer=serializer.replace('if(!f){++read_failures;return;}','if(!f){++read_failures;return 0xffffffffu;}')
body=r'''// Passive snapshots one caller level above the 006 quad entry.
uint32_t parent_sequence=0, active_parent=0xffffffffu;
uint32_t parent_begin(uint32_t entry,PPCContext& ctx,uint8_t* base) {
 if(!meta || !std::getenv("CC_CALLER_CAPTURE"))return 0xffffffffu;
 const uint32_t id=parent_sequence++;
 const uint32_t sp=ctx.r1.u32,obj=entry==0x820a9068u?ctx.r3.u32:ctx.r5.u32;
 uint32_t device=0,si=0,shader_ptr=0,rt=0,count=0,vt=0;
 bool ok=sp>=1024&&sp<=0xffffff8fu&&obj<=0xffff89efu;
 ok=ok&&word(base,obj,vt)&&word(base,obj+4,device)&&word(base,obj+30208,si)&&si<8;
 ok=ok&&word(base,obj+30176+si*4,shader_ptr)&&word(base,shader_ptr,shader);
 ok=ok&&word(base,obj+29124,rt)&&rt<32&&word(base,0x8228a7c4u,count)&&count<6000;
 std::vector<std::pair<uint32_t,uint32_t>> spans;
 auto add=[&](uint32_t a,uint32_t n){if(!n||uint64_t(a)+n>0x100000000ull){ok=false;return;}spans.emplace_back(a,n);};
 if(ok){
  add(sp-1024,1136);add(obj,8);add(vt,120);add(obj+28715,1);add(obj+29124,4);
  add(obj+30176,36);add(shader_ptr,20);add(obj+28744+rt*24,24);
  add(0x8201473cu,16);add(0x82042540u,256);add(0x820a9634u,68);
  add(0x821576c8u,120);add(0x82157d70u,8);
  add(0x8228a7c4u,4);add(0x822673d8u+count*24,96);
  add(device+1920,64);add(device+10552,4);
  if(entry==0x820a9068u){
   add(ctx.r4.u32,12);add(ctx.r5.u32,12);add(ctx.r6.u32,8);add(ctx.r7.u32,8);add(ctx.r8.u32,8);add(ctx.r9.u32,8);
   if(texture)add(texture,80);
  }else{
   uint32_t tex=0,mi=0,ci=0;uint32_t sprite=ctx.r3.u32,state=ctx.r4.u32;
   ok=word(base,sprite+92,tex)&&word(base,state+9532,mi)&&mi<32&&word(base,state+10048,ci)&&ci<32;
   add(sprite,112);add(state+9532,4);add(state+10048,4);
   add(state+8252+mi*40,40);add(state+(ci+596)*16,16);
   if(tex)add(tex,80);
  }
 }
 if(!ok){++read_failures;return 0xffffffffu;}
 std::sort(spans.begin(),spans.end());std::vector<std::pair<uint32_t,uint32_t>> merged;
 for(auto s:spans){if(!merged.empty()&&uint64_t(s.first)<=uint64_t(merged.back().first)+merged.back().second){auto& a=merged.back();a.second=uint32_t(std::max(uint64_t(a.first)+a.second,uint64_t(s.first)+s.second)-a.first);}else merged.push_back(s);}
 if(merged.size()>32){++read_failures;return 0xffffffffu;}
 std::vector<uint8_t> data;
 for(auto s:merged){size_t at=data.size();data.resize(at+s.second);if(!read(base,s.first,data.data()+at,s.second))return 0xffffffffu;}
'''
body+=serializer
body+=r'''
void parent_end(uint32_t id,uint32_t entry,uint32_t sprite,PPCContext& ctx,uint8_t* base) {
 if(id==0xffffffffu)return;
 uint32_t count=0;word(base,0x8228a7c4u,count);
 uint8_t flags=0;if(entry==0x820855d8u)read(base,sprite+86,&flags,1);
 char stem[64];std::snprintf(stem,sizeof stem,"parent-%05u-post.json",id);
 FILE* f=std::fopen((dir+"/"+stem).c_str(),"w");
 if(f){std::fprintf(f,"{\"index\":%u,\"entry\":%u,\"r3\":%llu,\"counter\":%u,\"sprite_flags\":%u,\"texture\":%u}\n",id,entry,(unsigned long long)ctx.r3.u64,count,flags,texture);std::fclose(f);}else ++read_failures;
 active_parent=0xffffffffu;
}
'''
(r/'pc/src/caller_capture007.inc').write_text(body)
p=r/'pc/src/render_capture004.cpp';s=p.read_text();s=s.replace(' #include "quad_capture006.inc"',' #include "quad_capture006.inc"\n #include "caller_capture007.inc"')
s=s.replace('quad_sequence=0;active_quad=0xffffffffu;','quad_sequence=0;active_quad=0xffffffffu;parent_sequence=0;active_parent=0xffffffffu;')
s=s.replace('\\\"input_index\\\":%u,','\\\"input_index\\\":%u,\\\"parent_index\\\":%u,').replace('draw++,active_quad,ctx.r4','draw++,active_quad,active_parent,ctx.r4')
for name in ['sub_820A9068','sub_820855D8']:
 s+='\nREX_EXTERN(__imp__'+name+');\nREX_HOOK_RAW('+name+') {\n'
 s+=' auto& c=capture();uint32_t id=0xffffffffu;const uint32_t sprite=ctx.r3.u32;\n'
 s+=' if(!c.root.empty()){std::lock_guard lock(c.mutex);id=c.parent_begin(0x'+name[4:]+'u,ctx,base);}\n'
 s+=' __imp__'+name+'(ctx,base);\n'
 s+=' if(!c.root.empty()){std::lock_guard lock(c.mutex);c.parent_end(id,0x'+name[4:]+'u,sprite,ctx,base);}\n}\n'
p.write_text(s)
