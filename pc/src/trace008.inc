// Opt-in read-only first-touch snapshots for original scene traversal.
// Memory records are captured BEFORE each original generated load/store.
namespace cc_trace008 {
thread_local bool enabled=false;
struct Page {
 uint32_t address=0;
 std::array<uint8_t,4096> before{}, touched{}, written{};
};
struct Trace {
 uint32_t id=0,entry=0,initial_texture=0,draw_begin=0;
 uint64_t reads=0,writes=0,errors=0;
 std::vector<uint64_t> context;
 std::map<uint32_t,Page> pages;
 std::map<std::string,uint64_t> functions;
 std::map<uint32_t,uint64_t> indirects;
};
thread_local Trace* current=nullptr;
thread_local unsigned nesting=0;
void function(const char* name){ if(current)++current->functions[name]; }
void indirect(uint32_t address){ if(current)++current->indirects[address]; }
void access(uint8_t* base,uint32_t address,unsigned size,bool write){
 if(!current)return; auto& t=*current;
 if(uint64_t(address)+size>0x100000000ull||size>65536){++t.errors;return;}
 if(write)++t.writes;else ++t.reads;
 for(uint64_t a=address;a<uint64_t(address)+size;){
  uint32_t page=uint32_t(a)&~4095u,off=uint32_t(a)&4095u,n=std::min<uint64_t>(4096-off,uint64_t(address)+size-a);
  auto it=t.pages.find(page);
  if(it==t.pages.end()){
   if(t.pages.size()>=2048){++t.errors;return;}
   Page p;p.address=page;
   if(!capture().read(base,page,p.before.data(),p.before.size())){++t.errors;return;}
   it=t.pages.emplace(page,std::move(p)).first;
  }
  for(uint32_t i=off;i<off+n;++i){it->second.touched[i]=1;if(write)it->second.written[i]=1;}
  a+=n;
 }
}
static void context_json(FILE* f,PPCContext& ctx){
 const uint64_t g[]={ctx.r0.u64,ctx.r1.u64,ctx.r2.u64,ctx.r3.u64,ctx.r4.u64,ctx.r5.u64,ctx.r6.u64,ctx.r7.u64,ctx.r8.u64,ctx.r9.u64,ctx.r10.u64,ctx.r11.u64,ctx.r12.u64,ctx.r13.u64,ctx.r14.u64,ctx.r15.u64,ctx.r16.u64,ctx.r17.u64,ctx.r18.u64,ctx.r19.u64,ctx.r20.u64,ctx.r21.u64,ctx.r22.u64,ctx.r23.u64,ctx.r24.u64,ctx.r25.u64,ctx.r26.u64,ctx.r27.u64,ctx.r28.u64,ctx.r29.u64,ctx.r30.u64,ctx.r31.u64};const uint64_t v[]={ctx.f0.u64,ctx.f1.u64,ctx.f2.u64,ctx.f3.u64,ctx.f4.u64,ctx.f5.u64,ctx.f6.u64,ctx.f7.u64,ctx.f8.u64,ctx.f9.u64,ctx.f10.u64,ctx.f11.u64,ctx.f12.u64,ctx.f13.u64,ctx.f14.u64,ctx.f15.u64,ctx.f16.u64,ctx.f17.u64,ctx.f18.u64,ctx.f19.u64,ctx.f20.u64,ctx.f21.u64,ctx.f22.u64,ctx.f23.u64,ctx.f24.u64,ctx.f25.u64,ctx.f26.u64,ctx.f27.u64,ctx.f28.u64,ctx.f29.u64,ctx.f30.u64,ctx.f31.u64};
 std::fprintf(f,"\"gpr\":[");for(unsigned i=0;i<32;++i)std::fprintf(f,"%s%llu",i?",":"",(unsigned long long)g[i]);
 std::fprintf(f,"],\"fpr\":[");for(unsigned i=0;i<32;++i)std::fprintf(f,"%s%llu",i?",":"",(unsigned long long)v[i]);
 const uint32_t cr[]={ctx.cr0.raw(),ctx.cr1.raw(),ctx.cr2.raw(),ctx.cr3.raw(),ctx.cr4.raw(),ctx.cr5.raw(),ctx.cr6.raw(),ctx.cr7.raw()};std::fprintf(f,"],\"cr\":[");for(unsigned i=0;i<8;++i)std::fprintf(f,"%s%u",i?",":"",cr[i]);
 std::fprintf(f,"],\"lr\":%llu,\"ctr\":%llu,\"xer\":[%u,%u,%u],\"fpscr\":%u",(unsigned long long)ctx.lr,(unsigned long long)ctx.ctr.u64,ctx.xer.so,ctx.xer.ov,ctx.xer.ca,ctx.fpscr.csr);
}
static void start_trace(uint32_t entry,PPCContext& ctx,uint8_t* base){
 auto& c=capture();
 auto* t=new Trace;t->id=c.tree_sequence++;t->entry=entry;t->draw_begin=c.draw;t->initial_texture=c.texture;
 current=t;c.active_tree=t->id;
 char name[80];std::snprintf(name,sizeof name,"/tree-%05u-pre.json",t->id);
 FILE* f=std::fopen((c.dir+name).c_str(),"w");
 if(f){std::fprintf(f,"{\"format\":\"CC-SCENE-TRACE-008\",\"entry\":%u,\"index\":%u,\"initial_texture\":%u,\"draw_begin\":%u,",entry,t->id,c.texture,c.draw);context_json(f,ctx);std::fprintf(f,"}\n");std::fclose(f);}else ++t->errors;
 // Capture full stack capacity required by nested original scalar helpers.
 if(ctx.r1.u32>=16384)access(base,ctx.r1.u32-16384,16384+128,false);else ++t->errors;
 enabled=true;
}
void begin(uint32_t entry,PPCContext& ctx,uint8_t* base){
 if(nesting++){return;}
 auto& c=capture();
 if(!c.meta||!std::getenv("CC_SCENE_CAPTURE"))return;
 start_trace(entry,ctx,base);
}
void begin_update(uint32_t entry,PPCContext& ctx,uint8_t* base){
 if(nesting++){return;}
 auto& c=capture();
 if(c.root.empty()||!std::getenv("CC_UPDATE_CAPTURE"))return;
 const std::string marker_path=c.root+"/capture-update-next";
 FILE* marker=std::fopen(marker_path.c_str(),"r");
 if(!marker)return;
 std::fclose(marker);std::filesystem::remove(marker_path);
 char name[64];std::snprintf(name,sizeof name,"update-%06u",c.update_sequence++);
 c.dir=c.root+"/"+name;std::filesystem::create_directories(c.dir);
 c.tree_sequence=0;c.active_tree=0xffffffffu;
 start_trace(entry,ctx,base);
}
void end(PPCContext& ctx,uint8_t* base){
 if(--nesting)return;if(!current)return;
 enabled=false;auto& c=capture();auto& t=*current;
 char stem[64];std::snprintf(stem,sizeof stem,"/tree-%05u",t.id);std::string name=c.dir+stem;
 FILE* f=std::fopen((name+"-post.json").c_str(),"w");
 if(f){std::fprintf(f,"{\"draw_end\":%u,\"texture\":%u,",c.draw,c.texture);context_json(f,ctx);std::fprintf(f,"}\n");std::fclose(f);}else ++t.errors;
 std::vector<uint8_t> before,after,mask,writes;
 for(auto& [address,page]:t.pages){
  std::array<uint8_t,4096> post{};if(!c.read(base,address,post.data(),4096))++t.errors;
  before.insert(before.end(),page.before.begin(),page.before.end());after.insert(after.end(),post.begin(),post.end());mask.insert(mask.end(),page.touched.begin(),page.touched.end());writes.insert(writes.end(),page.written.begin(),page.written.end());
 }
 c.blob(name+"-before.bin",before.data(),before.size());c.blob(name+"-after.bin",after.data(),after.size());c.blob(name+"-mask.bin",mask.data(),mask.size());c.blob(name+"-writes.bin",writes.data(),writes.size());
 f=std::fopen((name+".json").c_str(),"w");if(f){
  std::fprintf(f,"{\"format\":\"CC-SCENE-PAGES-008\",\"entry\":%u,\"index\":%u,\"reads\":%llu,\"writes\":%llu,\"errors\":%llu,\"pages\":[",t.entry,t.id,(unsigned long long)t.reads,(unsigned long long)t.writes,(unsigned long long)t.errors);
  unsigned i=0;for(auto& [address,p]:t.pages)std::fprintf(f,"%s%u",i++?",":"",address);
  std::fprintf(f,"],\"functions\":{");i=0;for(auto& [n,count]:t.functions)std::fprintf(f,"%s\"%s\":%llu",i++?",":"",n.c_str(),(unsigned long long)count);
  std::fprintf(f,"},\"indirects\":{");i=0;for(auto& [a,count]:t.indirects)std::fprintf(f,"%s\"%08x\":%llu",i++?",":"",a,(unsigned long long)count);
  std::fprintf(f,"}}\n");std::fclose(f);
 }else ++t.errors;
 c.read_failures+=t.errors;delete current;current=nullptr;c.active_tree=0xffffffffu;
}
}
REX_EXTERN(__imp__sub_8208A7A0);
REX_HOOK_RAW(sub_8208A7A0){cc_trace008::begin(0x8208a7a0,ctx,base);__imp__sub_8208A7A0(ctx,base);cc_trace008::end(ctx,base);}
REX_EXTERN(__imp__sub_820A8FF8);
REX_HOOK_RAW(sub_820A8FF8){cc_trace008::begin(0x820a8ff8,ctx,base);__imp__sub_820A8FF8(ctx,base);cc_trace008::end(ctx,base);}

// 010: the actual enclosing scene owner; nested lower roots remain inside this trace.
REX_EXTERN(__imp__sub_82091248);
REX_HOOK_RAW(sub_82091248){cc_trace008::begin(0x82091248,ctx,base);__imp__sub_82091248(ctx,base);cc_trace008::end(ctx,base);}

// 011: widget renderer and child-list owner. Lower hooks nest inside these roots.
REX_EXTERN(__imp__sub_8209DF48);
REX_HOOK_RAW(sub_8209DF48){cc_trace008::begin(0x8209DF48,ctx,base);__imp__sub_8209DF48(ctx,base);cc_trace008::end(ctx,base);}
REX_EXTERN(__imp__sub_8209CD08);
REX_HOOK_RAW(sub_8209CD08){cc_trace008::begin(0x8209CD08,ctx,base);__imp__sub_8209CD08(ctx,base);cc_trace008::end(ctx,base);}


// 012: one-shot update capture.  The marker is consumed only by the real widget
// update virtual target, then tracing remains passive through all nested original
// generated code (including sub_820915F0 and sub_8209CC98).  No guest state is
// edited and the original function always executes.
REX_EXTERN(__imp__sub_8209DE50);
REX_HOOK_RAW(sub_8209DE50){cc_trace008::begin_update(0x8209DE50,ctx,base);__imp__sub_8209DE50(ctx,base);cc_trace008::end(ctx,base);}
