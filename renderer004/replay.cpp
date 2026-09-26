#include "replay.h"
#include <string.h>
#include <math.h>
namespace cc::replay {
namespace {
uint32_t u32(const uint8_t*p){return uint32_t(p[0])|(uint32_t(p[1])<<8)|(uint32_t(p[2])<<16)|(uint32_t(p[3])<<24);}
float f32(const uint8_t*p){uint32_t u=u32(p);float v;memcpy(&v,&u,4);return v;}
float minf(float a,float b){return a<b?a:b;}float maxf(float a,float b){return a>b?a:b;}
float clamp(float v,float lo,float hi){return maxf(lo,minf(hi,v));}
struct Color {float c[4];};
Color sample(Texture t,float u,float v){
 // Bilinear, clamp-to-edge. Texture payloads are RGBA8 and already normalized.
 float x=clamp(u*float(t.width)-.5f,0,float(t.width-1));
 float y=clamp(v*float(t.height)-.5f,0,float(t.height-1));
 uint32_t x0=uint32_t(x),y0=uint32_t(y),x1=x0+1<t.width?x0+1:x0,y1=y0+1<t.height?y0+1:y0;
 float fx=x-float(x0),fy=y-float(y0);Color out{};
 for(int c=0;c<4;++c){float a=t.rgba[(y0*t.width+x0)*4+c],b=t.rgba[(y0*t.width+x1)*4+c],d=t.rgba[(y1*t.width+x0)*4+c],e=t.rgba[(y1*t.width+x1)*4+c];out.c[c]=((a+(b-a)*fx)*(1-fy)+(d+(e-d)*fx)*fy)/255.f;}return out;
}
float edge(const Vertex&a,const Vertex&b,float x,float y){return (b.x-a.x)*(y-a.y)-(b.y-a.y)*(x-a.x);}
bool top_left(const Vertex&a,const Vertex&b){return b.y<a.y||(b.y==a.y&&b.x>a.x);}
void triangle(const View&view,Texture tex,Vertex a,Vertex b,Vertex c,uint32_t blend,uint8_t*out){
 float area=edge(a,b,c.x,c.y);if(fabsf(area)<1e-8f)return;
 if(area<0){Vertex temp=b;b=c;c=temp;area=-area;}
 int minx=int(floorf(clamp(minf(a.x,minf(b.x,c.x)),0,float(view.width))));
 int miny=int(floorf(clamp(minf(a.y,minf(b.y,c.y)),0,float(view.height))));
 int maxx=int(ceilf(clamp(maxf(a.x,maxf(b.x,c.x)),0,float(view.width))));
 int maxy=int(ceilf(clamp(maxf(a.y,maxf(b.y,c.y)),0,float(view.height))));
 const bool ab=top_left(a,b),bc=top_left(b,c),ca=top_left(c,a);
 const int shifts[4]={16,8,0,24};
 for(int y=miny;y<maxy;++y)for(int x=minx;x<maxx;++x){
  float px=float(x)+.5f,py=float(y)+.5f;
  float e0=edge(b,c,px,py),e1=edge(c,a,px,py),e2=edge(a,b,px,py);
  if(e0<0||(e0==0&&!bc)||e1<0||(e1==0&&!ca)||e2<0||(e2==0&&!ab))continue;
  float w0=e0/area,w1=e1/area,w2=e2/area;
  Color s=sample(tex,a.u*w0+b.u*w1+c.u*w2,a.v*w0+b.v*w1+c.v*w2);
  for(int k=0;k<4;++k){int shift=shifts[k];float col=float((a.argb>>shift)&255)*w0+float((b.argb>>shift)&255)*w1+float((c.argb>>shift)&255)*w2;s.c[k]*=col/255.f;}
  auto*dst=out+(size_t(y)*view.width+size_t(x))*4;
  // Observed blend controls: ONE/INV_SRC_ALPHA or ONE/ZERO, ADD for RGB/alpha.
  float df=blend==0x07010701u?1-s.c[3]:0.f;
  for(int k=0;k<4;++k)dst[k]=uint8_t(clamp(s.c[k]*255.f+float(dst[k])*df,0,255)+.5f);
 }
}
}
const char* name(Error e) noexcept {switch(e){case Error::ok:return "ok";case Error::header:return "header";case Error::size:return "size";case Error::counts:return "counts";case Error::range:return "range";case Error::texture:return "texture";case Error::draw:return "draw";case Error::blend:return "blend";case Error::nonfinite:return "nonfinite";}return "unknown";}
Texture texture(const View&v,uint32_t i) noexcept {if(i>=v.textures||!v.bytes)return {};const auto*p=v.bytes+v.texture_table+i*16;return {u32(p),u32(p+4),v.bytes+u32(p+8)};}
Draw draw(const View&v,uint32_t i) noexcept {Draw d{};if(i>=v.draws||!v.bytes)return d;const auto*p=v.bytes+v.draw_table+i*104;d.texture=u32(p);d.blend=u32(p+4);p+=8;for(auto&x:d.vertices){ x.x=f32(p);x.y=f32(p+4);x.z=f32(p+8);x.u=f32(p+12);x.v=f32(p+16);x.argb=u32(p+20);p+=24;}return d;}
Error parse(const uint8_t*b,size_t n,View&out) noexcept {
 out={};if(!b||n<36||memcmp(b,"CCRP004\0",8))return Error::header;
 if(n>max_bytes||u32(b+32)!=n)return Error::size;
 View v{b,uint32_t(n),u32(b+8),u32(b+12),u32(b+16),u32(b+20),u32(b+24),u32(b+28)};
 if(!v.width||!v.height||v.width>1920||v.height>1080||!v.textures||v.textures>max_textures||!v.draws||v.draws>max_draws)return Error::counts;
 uint32_t end=36+v.textures*16+v.draws*104;
 if(v.texture_table!=36||v.draw_table!=36+v.textures*16||end>n)return Error::range;
 uint32_t cursor=end;
 for(uint32_t i=0;i<v.textures;++i){const auto*p=b+v.texture_table+i*16;uint32_t w=u32(p),h=u32(p+4),off=u32(p+8),bytes=u32(p+12);
  if(!w||!h||w>2048||h>2048||(w&(w-1))||(h&(h-1))||bytes!=w*h*4)return Error::texture;
  if(off!=cursor||uint64_t(off)+bytes>n)return Error::range;cursor+=bytes;
 }
 if(cursor!=n)return Error::size;
 for(uint32_t i=0;i<v.draws;++i){auto d=draw(v,i);if(d.texture>=v.textures)return Error::draw;if(d.blend!=0x07010701u&&d.blend!=0x00010001u)return Error::blend;
  for(auto&x:d.vertices){if(!isfinite(x.x)||!isfinite(x.y)||!isfinite(x.z)||!isfinite(x.u)||!isfinite(x.v)||fabsf(x.x)>1e6f||fabsf(x.y)>1e6f||fabsf(x.u)>32||fabsf(x.v)>32)return Error::nonfinite;}
 }
 out=v;return Error::ok;
}
Error render(const View&v,uint8_t*out,size_t n) noexcept {
 if(!v.bytes||!out||n!=size_t(v.width)*v.height*4)return Error::size;
 memset(out,0,n);for(size_t i=3;i<n;i+=4)out[i]=255;
 for(uint32_t i=0;i<v.draws;++i){auto d=draw(v,i);auto t=texture(v,d.texture);triangle(v,t,d.vertices[0],d.vertices[1],d.vertices[2],d.blend,out);triangle(v,t,d.vertices[0],d.vertices[2],d.vertices[3],d.blend,out);}return Error::ok;
}
}
