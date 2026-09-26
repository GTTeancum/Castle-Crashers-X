// Passive snapshots one caller level above the 006 quad entry.
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
 char stem[48];std::snprintf(stem,sizeof stem,"parent-%05u",id);
 blob(dir+"/"+stem+".bin",data.data(),data.size());
 FILE* f=std::fopen((dir+"/"+stem+".json").c_str(),"w");if(!f){++read_failures;return 0xffffffffu;}
 std::fprintf(f,"{\"format\":\"CC-CALLER-INPUT-007\",\"index\":%u,\"shader\":%u,\"gpr\":[",id,shader);
 const uint64_t gpr[]={ctx.r0.u64,ctx.r1.u64,ctx.r2.u64,ctx.r3.u64,ctx.r4.u64,ctx.r5.u64,ctx.r6.u64,ctx.r7.u64,ctx.r8.u64,ctx.r9.u64,ctx.r10.u64,ctx.r11.u64,ctx.r12.u64,ctx.r13.u64,ctx.r14.u64,ctx.r15.u64,ctx.r16.u64,ctx.r17.u64,ctx.r18.u64,ctx.r19.u64,ctx.r20.u64,ctx.r21.u64,ctx.r22.u64,ctx.r23.u64,ctx.r24.u64,ctx.r25.u64,ctx.r26.u64,ctx.r27.u64,ctx.r28.u64,ctx.r29.u64,ctx.r30.u64,ctx.r31.u64};for(unsigned i=0;i<32;++i)std::fprintf(f,"%s%llu",i?",":"",(unsigned long long)gpr[i]);
 const uint64_t fpr[]={ctx.f0.u64,ctx.f1.u64,ctx.f2.u64,ctx.f3.u64,ctx.f4.u64,ctx.f5.u64,ctx.f6.u64,ctx.f7.u64,ctx.f8.u64,ctx.f9.u64,ctx.f10.u64,ctx.f11.u64,ctx.f12.u64,ctx.f13.u64,ctx.f14.u64,ctx.f15.u64,ctx.f16.u64,ctx.f17.u64,ctx.f18.u64,ctx.f19.u64,ctx.f20.u64,ctx.f21.u64,ctx.f22.u64,ctx.f23.u64,ctx.f24.u64,ctx.f25.u64,ctx.f26.u64,ctx.f27.u64,ctx.f28.u64,ctx.f29.u64,ctx.f30.u64,ctx.f31.u64};std::fprintf(f,"],\"fpr\":[");for(unsigned i=0;i<32;++i)std::fprintf(f,"%s%llu",i?",":"",(unsigned long long)fpr[i]);
 const uint32_t cr[]={ctx.cr0.raw(),ctx.cr1.raw(),ctx.cr2.raw(),ctx.cr3.raw(),ctx.cr4.raw(),ctx.cr5.raw(),ctx.cr6.raw(),ctx.cr7.raw()};std::fprintf(f,"],\"cr\":[");for(unsigned i=0;i<8;++i)std::fprintf(f,"%s%u",i?",":"",cr[i]);
 std::fprintf(f,"],\"lr\":%llu,\"ctr\":%llu,\"xer\":[%u,%u,%u],\"fpscr\":%u,\"ranges\":[",(unsigned long long)ctx.lr,(unsigned long long)ctx.ctr.u64,ctx.xer.so,ctx.xer.ov,ctx.xer.ca,ctx.fpscr.csr);
 size_t off=0;for(size_t i=0;i<merged.size();++i){auto s=merged[i];std::fprintf(f,"%s{\"address\":%u,\"bytes\":%u,\"offset\":%zu}",i?",":"",s.first,s.second,off);off+=s.second;}
 std::fprintf(f,"],\"entry\":%u,\"initial_texture\":%u}\n",entry,texture);std::fclose(f);active_parent=id;return id;
}

void parent_end(uint32_t id,uint32_t entry,uint32_t sprite,PPCContext& ctx,uint8_t* base) {
 if(id==0xffffffffu)return;
 uint32_t count=0;word(base,0x8228a7c4u,count);
 uint8_t flags=0;if(entry==0x820855d8u)read(base,sprite+86,&flags,1);
 char stem[64];std::snprintf(stem,sizeof stem,"parent-%05u-post.json",id);
 FILE* f=std::fopen((dir+"/"+stem).c_str(),"w");
 if(f){std::fprintf(f,"{\"index\":%u,\"entry\":%u,\"r3\":%llu,\"counter\":%u,\"sprite_flags\":%u,\"texture\":%u}\n",id,entry,(unsigned long long)ctx.r3.u64,count,flags,texture);std::fclose(f);}else ++read_failures;
 active_parent=0xffffffffu;
}
