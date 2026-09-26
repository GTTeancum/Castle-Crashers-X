#pragma once
#include "replay.h"
namespace cc::replay {
// Shared CPU->NV2A staging, tested on host and compiled unchanged with nxdk.
struct GpuVertex {float position[4],color[4],uv[2];};
static_assert(sizeof(GpuVertex)==40);
uint32_t gpu_pitch(Texture) noexcept;
bool bgra_texture(Texture,uint8_t*,size_t) noexcept;
bool gpu_vertices(const View&,uint32_t,GpuVertex*,size_t) noexcept;
}
