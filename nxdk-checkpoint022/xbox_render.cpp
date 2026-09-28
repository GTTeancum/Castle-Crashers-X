// SPDX-License-Identifier: MIT
// Original-Xbox renderer for the port: draws the game's own draw calls on the
// NV2A with pbkit.
//
// Castle Crashers draws everything as textured, vertex-coloured quads in
// 640x480 screen pixels (its vertex constants are a fixed 640x480
// orthographic projection), so a pass-through vertex program and a
// texture*colour pixel program reproduce it. The game thread calls:
//   cc_xr_bind     at each texture bind (exact sub_820A89F8),
//   cc_xr_draw     at each draw (exact sub_820C1980),
//   cc_xr_frame_end at the frame boundary (KeDelayExecutionThread),
// and the renderer submits one pbkit frame per game frame.
#include <hal/debug.h>
#include <hal/video.h>
#include <pbkit/pbkit.h>
#include <windows.h>
#include <xboxkrnl/xboxkrnl.h>
#include <cstdint>
#include <cstring>
#include <vector>

namespace {
constexpr uint32_t kMaxGpuAddress = 0x03FFAFFFu;
struct GpuVertex { float pos[4], col[4], uv[2]; };
static_assert(sizeof(GpuVertex) == 40, "vertex layout");
constexpr uint32_t kMaxVertices = 16384;  // per frame (~640 KB)

uint32_t physical(const void* p) { return uint32_t(reinterpret_cast<uintptr_t>(p)) & 0x03FFFFFFu; }

struct Texture {
  uint32_t key = 0, w = 0, h = 0, format = 0, pitch = 0;
  const void* gpu = nullptr;
  bool normalized = false;  // swizzled/compressed textures take 0..1 UVs
};

bool g_init = false, g_failed = false, g_in_frame = false, g_shown = false;
GpuVertex* g_vb = nullptr;
uint32_t g_vb_used = 0;
Texture g_cur;
bool g_have_tex = false;
std::vector<Texture> g_converted;  // linear LE copies of big-endian formats
uint32_t g_frames = 0, g_draws = 0;

uint32_t log2u(uint32_t v) { uint32_t n = 0; while ((1u << n) < v) ++n; return n; }
uint32_t be32(const uint8_t* p) { return uint32_t(p[0]) << 24 | uint32_t(p[1]) << 16 | uint32_t(p[2]) << 8 | p[3]; }
float bef(const uint8_t* p) { const uint32_t u = be32(p); float f; std::memcpy(&f, &u, 4); return f; }

void upload_shaders() {
  static const uint32_t program[] = {
#include "vs.inl"
  };
  auto* p = pb_begin();
  p = pb_push1(p, NV097_SET_TRANSFORM_PROGRAM_START, 0);
  p = pb_push1(p, NV097_SET_TRANSFORM_EXECUTION_MODE,
               NV097_SET_TRANSFORM_EXECUTION_MODE_MODE_PROGRAM |
                   (NV097_SET_TRANSFORM_EXECUTION_MODE_RANGE_MODE_PRIV << 2));
  p = pb_push1(p, NV097_SET_TRANSFORM_PROGRAM_CXT_WRITE_EN, 0);
  p = pb_push1(p, NV097_SET_TRANSFORM_PROGRAM_LOAD, 0);
  pb_end(p);
  for (size_t i = 0; i < sizeof(program) / sizeof(program[0]); i += 4) {
    p = pb_begin();
    pb_push(p++, NV097_SET_TRANSFORM_PROGRAM, 4);
    std::memcpy(p, program + i, 16);
    p += 4;
    pb_end(p);
  }
  p = pb_begin();
#include "ps.inl"
  pb_end(p);
}

void set_attributes() {
  auto* p = pb_begin();
  pb_push(p++, NV097_SET_VERTEX_DATA_ARRAY_FORMAT, 16);
  for (int i = 0; i < 16; ++i) *p++ = NV097_SET_VERTEX_DATA_ARRAY_FORMAT_TYPE_F;
  pb_end(p);
  struct Attribute { uint32_t index, components, offset; };
  const Attribute attrs[] = {{0, 4, 0}, {3, 4, 16}, {9, 2, 32}};
  for (const Attribute& a : attrs) {
    p = pb_begin();
    p = pb_push1(p, NV097_SET_VERTEX_DATA_ARRAY_FORMAT + 4 * a.index,
                 NV097_SET_VERTEX_DATA_ARRAY_FORMAT_TYPE_F | (a.components << 4) |
                     (sizeof(GpuVertex) << 8));
    p = pb_push1(p, NV097_SET_VERTEX_DATA_ARRAY_OFFSET + 4 * a.index,
                 physical(reinterpret_cast<const uint8_t*>(g_vb) + a.offset));
    pb_end(p);
  }
}

bool init() {
  if (g_init) return !g_failed;
  g_init = true;
  if (pb_init() != 0) { g_failed = true; debugPrint("RENDER pb_init failed\n"); return false; }
  g_vb = static_cast<GpuVertex*>(MmAllocateContiguousMemoryEx(
      kMaxVertices * sizeof(GpuVertex), 0, kMaxGpuAddress, 0, PAGE_READWRITE | PAGE_WRITECOMBINE));
  if (!g_vb) { g_failed = true; debugPrint("RENDER no vertex memory\n"); return false; }
  return true;
}

void begin_frame() {
  pb_reset();
  pb_target_back_buffer();
  pb_erase_depth_stencil_buffer(0, 0, 640, 480);
  pb_fill(0, 0, 640, 480, 0xff000000);
  upload_shaders();
  set_attributes();
  auto* p = pb_begin();
  p = pb_push1(p, NV097_SET_DEPTH_TEST_ENABLE, 0);
  p = pb_push1(p, NV097_SET_DEPTH_MASK, 0);
  p = pb_push1(p, NV097_SET_STENCIL_TEST_ENABLE, 0);
  p = pb_push1(p, NV097_SET_CULL_FACE_ENABLE, 0);
  p = pb_push1(p, NV097_SET_FOG_ENABLE, 0);
  p = pb_push1(p, NV097_SET_ALPHA_TEST_ENABLE, 0);
  p = pb_push1(p, NV097_SET_BLEND_ENABLE, 1);
  p = pb_push1(p, NV097_SET_BLEND_EQUATION, NV097_SET_BLEND_EQUATION_V_FUNC_ADD);
  p = pb_push1(p, NV097_SET_COLOR_MASK, 0x01010101);
  for (unsigned i = 1; i < 4; ++i) p = pb_push1(p, NV097_SET_TEXTURE_CONTROL0 + 64 * i, 0);
  pb_end(p);
  g_vb_used = 0;
  g_in_frame = true;
}

// Xenos blend factor (0 zero, 1 one, 4/5 src colour, 6/7 src alpha, 8/9 dst
// colour, 10/11 dst alpha, 16 src alpha saturate) to the NV2A's GL values.
uint32_t blend_factor(uint32_t x) {
  switch (x) {
    case 0: return NV097_SET_BLEND_FUNC_SFACTOR_V_ZERO;
    case 1: return NV097_SET_BLEND_FUNC_SFACTOR_V_ONE;
    case 4: return NV097_SET_BLEND_FUNC_SFACTOR_V_SRC_COLOR;
    case 5: return NV097_SET_BLEND_FUNC_SFACTOR_V_ONE_MINUS_SRC_COLOR;
    case 6: return NV097_SET_BLEND_FUNC_SFACTOR_V_SRC_ALPHA;
    case 7: return NV097_SET_BLEND_FUNC_SFACTOR_V_ONE_MINUS_SRC_ALPHA;
    case 8: return NV097_SET_BLEND_FUNC_SFACTOR_V_DST_COLOR;
    case 9: return NV097_SET_BLEND_FUNC_SFACTOR_V_ONE_MINUS_DST_COLOR;
    case 10: return NV097_SET_BLEND_FUNC_SFACTOR_V_DST_ALPHA;
    case 11: return NV097_SET_BLEND_FUNC_SFACTOR_V_ONE_MINUS_DST_ALPHA;
    case 16: return NV097_SET_BLEND_FUNC_SFACTOR_V_SRC_ALPHA_SATURATE;
    default: return NV097_SET_BLEND_FUNC_SFACTOR_V_ONE;
  }
}

// Linear little-endian copy of a big-endian A8R8G8B8 (kind 1) or A4R4G4B4
// (kind 5) texture, made once per texture pointer.
const Texture* converted(uint32_t key, const uint8_t* src, uint32_t w, uint32_t h, int kind) {
  for (const Texture& t : g_converted) if (t.key == key && t.w == w && t.h == h) return &t;
  const uint32_t bpp = kind == 1 ? 4u : 2u;
  const uint32_t bytes = w * h * bpp;
  uint8_t* dst = static_cast<uint8_t*>(MmAllocateContiguousMemoryEx(
      bytes, 0, kMaxGpuAddress, 0, PAGE_READWRITE | PAGE_WRITECOMBINE));
  if (!dst) return nullptr;
  if (kind == 1) {
    for (uint32_t i = 0; i < w * h; ++i) {  // A R G B -> B G R A
      dst[i * 4 + 0] = src[i * 4 + 3]; dst[i * 4 + 1] = src[i * 4 + 2];
      dst[i * 4 + 2] = src[i * 4 + 1]; dst[i * 4 + 3] = src[i * 4 + 0];
    }
  } else {
    for (uint32_t i = 0; i < w * h; ++i) { dst[i * 2 + 0] = src[i * 2 + 1]; dst[i * 2 + 1] = src[i * 2 + 0]; }
  }
  Texture t;
  t.key = key; t.w = w; t.h = h; t.gpu = dst; t.pitch = w * bpp; t.normalized = false;
  t.format = 0x0000002Au |
             ((kind == 1 ? NV097_SET_TEXTURE_FORMAT_COLOR_LU_IMAGE_A8R8G8B8
                         : NV097_SET_TEXTURE_FORMAT_COLOR_LU_IMAGE_A4R4G4B4) << 8) |
             (1u << 16);
  g_converted.push_back(t);
  return &g_converted.back();
}
}  // namespace

// GPU-readable (physically contiguous) memory for guest regions the NV2A
// samples directly (the DXT5 texture cache zone).
void* cc_xr_alloc_gpu(uint32_t bytes) {
  return MmAllocateContiguousMemoryEx(bytes, 0, kMaxGpuAddress, 0, PAGE_READWRITE | PAGE_WRITECOMBINE);
}

// kind: 100 port DXT5 (standard blocks, contiguous), 1 A8R8G8B8 BE, 5 A4R4G4B4 BE.
void cc_xr_bind(uint32_t key, const void* data, uint32_t w, uint32_t h, int kind) {
  g_have_tex = false;
  if (!data || !w || !h || w > 4096 || h > 4096) return;
  if (kind == 100) {
    g_cur = Texture();
    g_cur.key = key; g_cur.w = w; g_cur.h = h; g_cur.gpu = data; g_cur.normalized = true;
    g_cur.format = 0x0000002Au | (NV097_SET_TEXTURE_FORMAT_COLOR_L_DXT45_A8R8G8B8 << 8) |
                   (1u << 16) | (log2u(w) << 20) | (log2u(h) << 24);
    g_have_tex = true;
    return;
  }
  if (kind != 1 && kind != 5) return;
  if (const Texture* t = converted(key, static_cast<const uint8_t*>(data), w, h, kind)) {
    g_cur = *t;
    g_have_tex = true;
  }
}

// One draw of the game's: prim 13 quad list, 4 triangle list, 5 strip;
// vertices are big-endian {x, y, z, u, v, argb} with the given stride.
void cc_xr_draw(uint32_t prim, uint32_t count, const void* vertices, uint32_t stride, uint32_t blend) {
  if (!init() || !vertices || stride < 24 || !count) return;
  uint32_t op;
  if (prim == 13) op = NV097_SET_BEGIN_END_OP_QUADS;
  else if (prim == 4) op = NV097_SET_BEGIN_END_OP_TRIANGLES;
  else if (prim == 5) op = NV097_SET_BEGIN_END_OP_TRIANGLE_STRIP;
  else return;
  if (!g_in_frame) begin_frame();
  if (g_vb_used + count > kMaxVertices) return;
  const uint8_t* v = static_cast<const uint8_t*>(vertices);
  const float su = g_have_tex && !g_cur.normalized ? float(g_cur.w) : 1.0f;
  const float sv = g_have_tex && !g_cur.normalized ? float(g_cur.h) : 1.0f;
  GpuVertex* out = g_vb + g_vb_used;
  for (uint32_t i = 0; i < count; ++i, v += stride) {
    GpuVertex& o = out[i];
    o.pos[0] = bef(v); o.pos[1] = bef(v + 4); o.pos[2] = 0.0f; o.pos[3] = 1.0f;
    const uint32_t argb = be32(v + 20);
    o.col[0] = float((argb >> 16) & 255) / 255.0f; o.col[1] = float((argb >> 8) & 255) / 255.0f;
    o.col[2] = float(argb & 255) / 255.0f; o.col[3] = float(argb >> 24) / 255.0f;
    o.uv[0] = bef(v + 12) * su; o.uv[1] = bef(v + 16) * sv;
  }
  auto* p = pb_begin();
  if (g_have_tex) {
    p = pb_push1(p, NV097_SET_TEXTURE_OFFSET, physical(g_cur.gpu));
    p = pb_push1(p, NV097_SET_TEXTURE_FORMAT, g_cur.format);
    if (!g_cur.normalized) {
      p = pb_push1(p, NV097_SET_TEXTURE_CONTROL1, g_cur.pitch << 16);
      p = pb_push1(p, NV097_SET_TEXTURE_IMAGE_RECT, (g_cur.w << 16) | g_cur.h);
    }
    p = pb_push1(p, NV097_SET_TEXTURE_ADDRESS, 0x00050505);  // clamp U/V/P
    p = pb_push1(p, NV097_SET_TEXTURE_CONTROL0, 0x40000000);  // enabled, LOD 0
    p = pb_push1(p, NV097_SET_TEXTURE_FILTER, 0x02022000);    // linear min/mag
  } else {
    p = pb_push1(p, NV097_SET_TEXTURE_CONTROL0, 0);
  }
  p = pb_push1(p, NV097_SET_BLEND_FUNC_SFACTOR, blend_factor(blend & 0x1F));
  p = pb_push1(p, NV097_SET_BLEND_FUNC_DFACTOR, blend_factor((blend >> 8) & 0x1F));
  p = pb_push1(p, NV097_SET_BEGIN_END, op);
  for (uint32_t first = 0; first < count; first += 256) {
    const uint32_t n = count - first < 256 ? count - first : 256;
    p = pb_push1(p, 0x40000000 | NV097_DRAW_ARRAYS, ((n - 1) << 24) | (g_vb_used + first));
  }
  p = pb_push1(p, NV097_SET_BEGIN_END, NV097_SET_BEGIN_END_OP_END);
  pb_end(p);
  g_vb_used += count;
  ++g_draws;
}

// Frame boundary: wait for the GPU and present.
void cc_xr_frame_end() {
  if (!g_in_frame) return;
  while (pb_busy()) {}
  while (pb_finished()) {}
  if (!g_shown) { pb_show_front_screen(); g_shown = true; }
  g_in_frame = false;
  ++g_frames;
}
