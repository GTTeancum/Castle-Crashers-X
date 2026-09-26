#include "gpu_staging.h"
#include <string.h>
namespace cc::replay {
uint32_t gpu_pitch(Texture t) noexcept {return t.width&&t.width<=2048?(t.width*4+63)&~63u:0;}
bool bgra_texture(Texture t,uint8_t*out,size_t n) noexcept {
 uint32_t pitch=gpu_pitch(t);if(!pitch||!t.height||t.height>2048||!t.rgba||!out||n!=size_t(pitch)*t.height)return false;
 memset(out,0,n);for(uint32_t y=0;y<t.height;++y)for(uint32_t x=0;x<t.width;++x){const auto*s=t.rgba+(size_t(y)*t.width+x)*4;auto*d=out+size_t(y)*pitch+x*4;d[0]=s[2];d[1]=s[1];d[2]=s[0];d[3]=s[3];}return true;
}
bool gpu_vertices(const View&v,uint32_t index,GpuVertex*out,size_t count) noexcept {
 if(!v.bytes||index>=v.draws||!out||count!=6)return false;
 auto d=draw(v,index);auto t=texture(v,d.texture);if(!t.rgba)return false;
 const unsigned ix[6]={0,1,2,0,2,3};
 for(unsigned i=0;i<6;++i){const auto&p=d.vertices[ix[i]];auto&o=out[i];o.position[0]=p.x;o.position[1]=p.y;o.position[2]=0.f;o.position[3]=1.f;
 o.color[0]=float((p.argb>>16)&255)/255.f;o.color[1]=float((p.argb>>8)&255)/255.f;o.color[2]=float(p.argb&255)/255.f;o.color[3]=float(p.argb>>24)/255.f;
 // Linear NV2A textures use pixel rather than normalized texture coordinates.
 o.uv[0]=p.u*float(t.width);o.uv[1]=p.v*float(t.height);}
 return true;
}
}
