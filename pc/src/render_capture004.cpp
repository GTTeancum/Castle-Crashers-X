// Passive observation of verified entrypoints in the supplied Castle Crashers build.
// Every hook always calls the original body. Disabled unless CC_RENDER_CAPTURE_DIR is set.
// This is Linux-only diagnostic code; it is NOT included in the nxdk executable.
#include "generated/default/castle_crashers_pch.h"
#include <algorithm>
#include <map>
#include <array>
namespace cc_trace008 {extern thread_local bool enabled; void access(uint8_t*,uint32_t,unsigned,bool);}
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

REX_EXTERN(__imp__sub_820A7E80);
REX_EXTERN(__imp__sub_820A89F8);
REX_EXTERN(__imp__sub_820A9308);
REX_EXTERN(__imp__sub_820C1980);

namespace {
struct Capture {
 std::mutex mutex;
 std::string root;
 uint32_t tree_sequence=0, update_sequence=0, active_tree=0xffffffffu;
 uint32_t frame=0, object=0, texture=0, draw=0, shader=0;
 uint64_t total_draws=0, read_failures=0;
 int memfd=-1;
 FILE* meta=nullptr;
 std::string dir;
 struct TexSnapshot { std::string name; std::vector<uint8_t> data; uint32_t width,height,fmt; };
 std::unordered_map<uint32_t,TexSnapshot> textures;
 uint32_t texture_versions=0;
 Capture() { if(auto* p=std::getenv("CC_RENDER_CAPTURE_DIR")) { root=p;std::filesystem::create_directories(root);memfd=open("/proc/self/mem",O_RDONLY|O_CLOEXEC); } }
 ~Capture() { if(meta)std::fclose(meta);if(memfd>=0)close(memfd); }
 bool read(uint8_t* base,uint32_t addr,void* dst,size_t n) {
  if(uint64_t(addr)+n>0x100000000ull){++read_failures;return false;}
  // pread is non-faulting for unmapped guest spans and never changes guest bytes.
  const bool ok=memfd>=0 && pread(memfd,dst,n,off_t(reinterpret_cast<uintptr_t>(base)+addr))==ssize_t(n);
  if(!ok)++read_failures;
  return ok;
 }
 bool word(uint8_t* base,uint32_t addr,uint32_t& out) {
  uint32_t v;if(!read(base,addr,&v,4))return false;out=__builtin_bswap32(v);return true;
 }
 void blob(const std::string& path,const void* ptr,size_t n) {
  FILE* f=std::fopen(path.c_str(),"wb");if(!f){++read_failures;return;}
  if(std::fwrite(ptr,1,n,f)!=n)++read_failures;
  std::fclose(f);
 }
 std::string tex(uint8_t* base) {
  if(!texture)return "";
  uint32_t h[16]={}; if(!read(base,texture,h,sizeof h))return "";
  for(auto& w:h)w=__builtin_bswap32(w);
  uint32_t width=h[4],height=h[5],fmt=h[6],addr=h[9];
  uint32_t pw=1,ph=1;
  if(width==0||height==0||width>4096||height>4096)return "";
  while(pw<width)pw*=2;while(ph<height)ph*=2;
  // Padded linear/tiled source size, inferred from the texture setup's format switch.
  size_t n=0;
  if(fmt==1)n=size_t(pw)*ph*4;
  else if(fmt==5)n=size_t(pw)*ph*2; // k_4_4_4_4, endian 8-in-16
  else if(fmt>=7&&fmt<=11)n=size_t((pw+3)/4)*((ph+3)/4)*(fmt==7?8:16);
  if(n>16*1024*1024||!n)return "";
  std::vector<uint8_t> data(n);if(!read(base,addr,data.data(),n))return "";
  if(auto i=textures.find(texture);i!=textures.end() && i->second.width==width && i->second.height==height && i->second.fmt==fmt && i->second.data==data)return i->second.name;
  char name[64];std::snprintf(name,sizeof name,"tex-%08x-%04u",texture,texture_versions++);
  const std::string stem=name;blob(dir+"/"+stem+".bin",data.data(),n);
  FILE* f=std::fopen((dir+"/"+stem+".json").c_str(),"w");
  if(f){std::fprintf(f,"{\"address\":%u,\"width\":%u,\"height\":%u,\"padded_width\":%u,\"padded_height\":%u,\"format\":%u,\"data_address\":%u,\"bytes\":%zu,\"raw_words\":[",texture,width,height,pw,ph,fmt,addr,n);
   for(int i=0;i<16;++i)std::fprintf(f,"%s%u",i?",":"",h[i]);std::fprintf(f,"]}\n");std::fclose(f);}else{++read_failures;return "";}
  textures[texture]=TexSnapshot{stem,std::move(data),width,height,fmt};return stem;
 }
 #include "quad_capture006.inc"
 #include "caller_capture007.inc"
 void boundary(uint8_t* base,uint32_t obj) {
  tree_sequence=0;active_tree=0xffffffffu;quad_sequence=0;active_quad=0xffffffffu;parent_sequence=0;active_parent=0xffffffffu;
  ++frame;object=obj;
  if(meta){std::fprintf(meta,"{\"event\":\"end\",\"draws\":%u,\"read_failures\":%llu}\n",draw,(unsigned long long)read_failures);std::fclose(meta);meta=nullptr;}
  FILE* marker=std::fopen((root+"/capture-next").c_str(),"r");
  if(marker){std::fclose(marker);std::filesystem::remove(root+"/capture-next");
   char name[64];std::snprintf(name,sizeof name,"frame-%06u",frame);dir=root+"/"+name;
   std::filesystem::create_directories(dir);meta=std::fopen((dir+"/draws.jsonl").c_str(),"w");draw=0;textures.clear();texture_versions=0;
   if(meta){uint32_t vt=0;word(base,obj,vt);std::fprintf(meta,"{\"event\":\"begin\",\"frame\":%u,\"object\":%u,\"vtable\":%u}\n",frame,obj,vt);}
  }
  if(frame%30==0){FILE* f=std::fopen((root+"/status.json").c_str(),"w");if(f){std::fprintf(f,"{\"frame_boundaries\":%u,\"total_draws\":%llu,\"read_failures\":%llu}\n",frame,(unsigned long long)total_draws,(unsigned long long)read_failures);std::fclose(f);}}
 }
 void vertices(PPCContext& ctx,uint8_t* base) {
  ++total_draws;if(!meta)return;
  uint32_t count=ctx.r5.u32,stride=ctx.r7.u32,addr=ctx.r6.u32;
  size_t n=size_t(count)*stride;
  if(count>65536||stride>256||n>4*1024*1024){++read_failures;return;}
  std::vector<uint8_t> data(n);if(!read(base,addr,data.data(),n))return;
  auto texture_file=tex(base);char name[64];std::snprintf(name,sizeof name,"draw-%05u.bin",draw);
  blob(dir+"/"+name,data.data(),n);
  uint32_t matrix[16]={};read(base,ctx.r3.u32+1920,matrix,sizeof matrix);
  uint32_t blend=0;word(base,ctx.r3.u32+10552,blend);
  std::fprintf(meta,"{\"event\":\"draw\",\"index\":%u,\"input_index\":%u,\"parent_index\":%u,\"tree_index\":%u,\"primitive\":%u,\"count\":%u,\"stride\":%u,\"source\":%u,\"caller\":%llu,\"shader\":%u,\"texture\":%u,\"texture_file\":\"%s\",\"vertices_file\":\"%s\",\"blend_control\":%u,\"matrix_words\":[",draw++,active_quad,active_parent,active_tree,ctx.r4.u32,count,stride,addr,(unsigned long long)ctx.lr,shader,texture,texture_file.c_str(),name,blend);
  for(int i=0;i<16;++i)std::fprintf(meta,"%s%u",i?",":"",__builtin_bswap32(matrix[i]));std::fprintf(meta,"]}\n");std::fflush(meta);
 }
};
Capture& capture(){static Capture state;return state;}
}
REX_HOOK_RAW(sub_820A7E80) {
 auto& c=capture();if(!c.root.empty()){std::lock_guard lock(c.mutex);c.boundary(base,ctx.r3.u32);}
 __imp__sub_820A7E80(ctx,base);
}
REX_HOOK_RAW(sub_820A89F8) {
 auto& c=capture();if(!c.root.empty()){std::lock_guard lock(c.mutex);c.texture=ctx.r4.u32;c.object=ctx.r3.u32;}
 bool tracing=cc_trace008::enabled;
 if(tracing){cc_trace008::access(base,ctx.r4.u32,80,false);}
 cc_trace008::enabled=false; __imp__sub_820A89F8(ctx,base); cc_trace008::enabled=tracing;
}
REX_HOOK_RAW(sub_820A9308) {
 auto& c=capture();if(!c.root.empty()){std::lock_guard lock(c.mutex);c.object=ctx.r3.u32;
  uint32_t index=0,ptr=0;if(c.word(base,c.object+30208,index)&&index<8&&c.word(base,c.object+30176+index*4,ptr))c.word(base,ptr,c.shader);
  c.quad_input(ctx,base);
 }
 __imp__sub_820A9308(ctx,base);
}
REX_HOOK_RAW(sub_820C1980) {
 auto& c=capture();if(!c.root.empty()){std::lock_guard lock(c.mutex);c.vertices(ctx,base);}
 bool tracing=cc_trace008::enabled;
 if(tracing){cc_trace008::access(base,ctx.r3.u32+1920,64,false);cc_trace008::access(base,ctx.r3.u32+10552,4,false);}
 cc_trace008::enabled=false; __imp__sub_820C1980(ctx,base); cc_trace008::enabled=tracing;
}

REX_EXTERN(__imp__sub_820A9068);
REX_HOOK_RAW(sub_820A9068) {
 auto& c=capture();uint32_t id=0xffffffffu;const uint32_t sprite=ctx.r3.u32;
 if(!c.root.empty()){std::lock_guard lock(c.mutex);id=c.parent_begin(0x820A9068u,ctx,base);}
 __imp__sub_820A9068(ctx,base);
 if(!c.root.empty()){std::lock_guard lock(c.mutex);c.parent_end(id,0x820A9068u,sprite,ctx,base);}
}

REX_EXTERN(__imp__sub_820855D8);
REX_HOOK_RAW(sub_820855D8) {
 auto& c=capture();uint32_t id=0xffffffffu;const uint32_t sprite=ctx.r3.u32;
 if(!c.root.empty()){std::lock_guard lock(c.mutex);id=c.parent_begin(0x820855D8u,ctx,base);}
 __imp__sub_820855D8(ctx,base);
 if(!c.root.empty()){std::lock_guard lock(c.mutex);c.parent_end(id,0x820855D8u,sprite,ctx,base);}
}

#include "trace008.inc"
