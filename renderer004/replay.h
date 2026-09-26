#pragma once
#include <stdint.h>
#include <stddef.h>
namespace cc::replay {
constexpr uint32_t max_bytes=32*1024*1024, max_textures=512, max_draws=4096;
struct Vertex {float x,y,z,u,v;uint32_t argb;};
struct Texture {uint32_t width,height;const uint8_t* rgba;};
struct Draw {uint32_t texture,blend;Vertex vertices[4];};
struct View {const uint8_t* bytes=nullptr;uint32_t length=0,width=0,height=0,textures=0,draws=0,texture_table=0,draw_table=0;};
enum class Error {ok,header,size,counts,range,texture,draw,blend,nonfinite};
const char* name(Error) noexcept;
Error parse(const uint8_t*,size_t,View&) noexcept;
Texture texture(const View&,uint32_t) noexcept;
Draw draw(const View&,uint32_t) noexcept;
// RGBA8 output. Supports the checked quad/modulate/premultiplied-blend subset only.
Error render(const View&,uint8_t* rgba,size_t bytes) noexcept;
}
