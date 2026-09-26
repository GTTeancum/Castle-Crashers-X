#include "replay.h"
#include "gpu_staging.h"
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace cc::replay;
static unsigned checks=0;
#define CHECK(x) do {++checks;if(!(x)){std::fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#x);std::exit(1);}}while(0)
static void word(std::vector<uint8_t>&b,size_t p,uint32_t x){for(int i=0;i<4;++i)b.at(p+i)=uint8_t(x>>(i*8));}
static void real(std::vector<uint8_t>&b,size_t p,float f){uint32_t u;std::memcpy(&u,&f,4);word(b,p,u);}
static std::vector<uint8_t> fixture(uint32_t color=0xffffffff,uint32_t blend=0x07010701){
 std::vector<uint8_t>b(160);std::memcpy(b.data(),"CCRP004\0",8);
 uint32_t h[]={8,8,1,1,36,52,160};for(unsigned i=0;i<7;++i)word(b,8+i*4,h[i]);
 uint32_t t[]={1,1,156,4};for(unsigned i=0;i<4;++i)word(b,36+i*4,t[i]);word(b,52,0);word(b,56,blend);
 float xy[8]={0,0,8,0,8,8,0,8};for(unsigned i=0;i<4;++i){size_t p=60+i*24;real(b,p,xy[2*i]);real(b,p+4,xy[2*i+1]);real(b,p+8,.5f);real(b,p+12,float(i==1||i==2));real(b,p+16,float(i>=2));word(b,p+20,color);}
 b[156]=255;b[157]=255;b[158]=255;b[159]=255;return b;
}
static void invalid(std::vector<uint8_t>b,Error want){View v;v.bytes=reinterpret_cast<const uint8_t*>(1);CHECK(parse(b.data(),b.size(),v)==want);CHECK(v.bytes==nullptr);}
static uint32_t next(uint32_t&s){s^=s<<13;s^=s>>17;s^=s<<5;return s;}
int main(){
 auto b=fixture();View v;CHECK(parse(b.data(),b.size(),v)==Error::ok);CHECK(v.width==8&&v.height==8&&v.draws==1&&v.textures==1);CHECK(texture(v,0).rgba==b.data()+156);CHECK(texture(v,1).rgba==nullptr);CHECK(draw(v,0).vertices[3].y==8);CHECK(draw(v,1).blend==0);
 std::vector<uint8_t>out(256+16,77);CHECK(render(v,out.data(),256)==Error::ok);for(unsigned i=0;i<256;++i)CHECK(out[i]==255);for(unsigned i=256;i<out.size();++i)CHECK(out[i]==77);
 CHECK(render(v,nullptr,256)==Error::size);CHECK(render(v,out.data(),255)==Error::size);CHECK(parse(nullptr,160,v)==Error::header);
 // Premultiplied red at half alpha: shared diagonal must be drawn exactly once.
 b=fixture();b[156]=128;b[157]=0;b[158]=0;b[159]=128;CHECK(parse(b.data(),b.size(),v)==Error::ok);CHECK(render(v,out.data(),256)==Error::ok);for(unsigned p=0;p<64;++p){CHECK(out[p*4]==128);CHECK(out[p*4+1]==0);CHECK(out[p*4+2]==0);CHECK(out[p*4+3]==255);}
 // Replacement must preserve source alpha rather than blend against opaque black.
 word(b,56,0x00010001);CHECK(parse(b.data(),b.size(),v)==Error::ok);CHECK(render(v,out.data(),256)==Error::ok);for(unsigned p=0;p<64;++p)CHECK(out[p*4+3]==128);
 // Reverse winding, same coverage and no repeated diagonal.
 for(unsigned j=0;j<24;++j)std::swap(b[84+j],b[132+j]);CHECK(parse(b.data(),b.size(),v)==Error::ok);CHECK(render(v,out.data(),256)==Error::ok);for(unsigned p=0;p<64;++p)CHECK(out[p*4]==128);
 // Clipped quad produces no out-of-bounds output and is clipped at half width.
 b=fixture();for(unsigned i=0;i<4;++i)real(b,60+i*24,i==1||i==2?4.f:-4.f);CHECK(parse(b.data(),b.size(),v)==Error::ok);CHECK(render(v,out.data(),256)==Error::ok);for(unsigned y=0;y<8;++y)for(unsigned x=0;x<8;++x)CHECK(out[(y*8+x)*4]==(x<4?255:0));
 // Bilinear centre of a 2x2 RGBA texture is the average of all four texels.
 b=fixture();b.resize(172);word(b,32,172);word(b,36,2);word(b,40,2);word(b,48,16);const uint8_t corners[16]={255,0,0,255,0,255,0,255,0,0,255,255,255,255,255,255};std::memcpy(b.data()+156,corners,16);for(unsigned i=0;i<4;++i){real(b,72+i*24,.5f);real(b,76+i*24,.5f);}CHECK(parse(b.data(),b.size(),v)==Error::ok);CHECK(render(v,out.data(),256)==Error::ok);CHECK(out[0]==128&&out[1]==128&&out[2]==128&&out[3]==255);
 for(size_t n=0;n<160;++n){auto t=fixture();t.resize(n);CHECK(parse(t.data(),t.size(),v)!=Error::ok);CHECK(v.bytes==nullptr);}
 b=fixture();b[0]='X';invalid(b,Error::header);
 b=fixture();word(b,32,159);invalid(b,Error::size);
 b=fixture();word(b,8,0);invalid(b,Error::counts);
 b=fixture();word(b,16,513);invalid(b,Error::counts);
 b=fixture();word(b,20,4097);invalid(b,Error::counts);
 b=fixture();word(b,24,40);invalid(b,Error::range);
 b=fixture();word(b,44,0xffffffff);invalid(b,Error::range);
 b=fixture();word(b,36,3);invalid(b,Error::texture);
 b=fixture();word(b,52,1);invalid(b,Error::draw);
 b=fixture();word(b,56,0);invalid(b,Error::blend);
 b=fixture();word(b,60,0x7fc00000);invalid(b,Error::nonfinite);
 b=fixture();word(b,64,0x7f800000);invalid(b,Error::nonfinite);
 b=fixture();real(b,72,33);invalid(b,Error::nonfinite);
 // CPU staging used unchanged by the NV2A target: padded BGRA and six vertices.
 b=fixture(0x80402010);CHECK(parse(b.data(),b.size(),v)==Error::ok);auto tex=texture(v,0);
 CHECK(gpu_pitch(tex)==64);std::vector<uint8_t>gpu(80,33);CHECK(bgra_texture(tex,gpu.data(),64));for(unsigned i=4;i<64;++i)CHECK(gpu[i]==0);for(unsigned i=64;i<80;++i)CHECK(gpu[i]==33);
 b[156]=10;b[157]=20;b[158]=30;b[159]=40;CHECK(bgra_texture(tex,gpu.data(),64));CHECK(gpu[0]==30&&gpu[1]==20&&gpu[2]==10&&gpu[3]==40);CHECK(!bgra_texture(tex,gpu.data(),63));CHECK(!bgra_texture(tex,nullptr,64));CHECK(!bgra_texture({},gpu.data(),64));
 GpuVertex gv[6]{};CHECK(gpu_vertices(v,0,gv,6));CHECK(gv[0].position[0]==0&&gv[0].position[3]==1);CHECK(gv[1].position[0]==8&&gv[1].uv[0]==1);CHECK(gv[2].position[1]==8&&gv[2].uv[1]==1);CHECK(std::memcmp(&gv[0],&gv[3],sizeof(GpuVertex))==0);CHECK(std::memcmp(&gv[2],&gv[4],sizeof(GpuVertex))==0);
 CHECK(gv[0].color[0]==64.f/255.f&&gv[0].color[1]==32.f/255.f&&gv[0].color[2]==16.f/255.f&&gv[0].color[3]==128.f/255.f);
 CHECK(!gpu_vertices(v,0,gv,5));CHECK(!gpu_vertices(v,1,gv,6));CHECK(!gpu_vertices(v,0,nullptr,6));
 uint32_t rng=0x004ca57e;unsigned accepted=0;
 for(unsigned trial=0;trial<20000;++trial){auto t=fixture();unsigned changes=1+next(rng)%5;for(unsigned j=0;j<changes;++j)t[next(rng)%t.size()]^=uint8_t(1+next(rng)%255);
  auto e=parse(t.data(),t.size(),v);CHECK(e==Error::ok||v.bytes==nullptr);
  if(e==Error::ok){++accepted;std::vector<uint8_t> image(size_t(v.width)*v.height*4+16,99);CHECK(render(v,image.data(),image.size()-16)==Error::ok);for(size_t k=image.size()-16;k<image.size();++k)CHECK(image[k]==99);}
 }
 std::printf("PASS %u assertions; 20000 deterministic malformed-input trials; %u accepted streams rendered with guard checks.\n",checks,accepted);return 0;
}
