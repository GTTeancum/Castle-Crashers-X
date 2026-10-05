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

void cc_xbox_audio_stats(unsigned* started, unsigned* submitted, unsigned* callbacks,
                         unsigned* underruns, unsigned* dropped);

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
  uint32_t sig = 0;         // converted copies: sample hash of the source
  uint32_t checked = 0xFFFFFFFFu;  // frame of the last signature check
  uint32_t slice_sig[8] = {};      // per-slice sample hashes (rows split in 8)
  uint32_t slice_next = 0;         // slice checked next frame
};

bool g_init = false, g_failed = false, g_in_frame = false, g_shown = false;
// Submissions share one open push-buffer block: pbkit's pb_end kicks the GPU
// (write-combine flush with a busy wait, then the DMA put), which per sprite
// and per counter segment cost hundreds of kicks a frame on the console. The
// block is kicked every 32 submissions, before any wait for the GPU and before
// pbkit's own drawing calls.
uint32_t* g_open = nullptr;
unsigned g_open_n = 0;
uint32_t* xr_begin() { return g_open ? g_open : pb_begin(); }
void xr_flush() {
  if (!g_open) return;
  pb_end(g_open);
  g_open = nullptr;
  g_open_n = 0;
}
void xr_end(uint32_t* p) {
  g_open = p;
  if (++g_open_n >= 32u) xr_flush();
}
// pbkit keeps three framebuffers and shows one queued frame per vertical
// blank; it only refuses a fourth queued frame, so a game finishing frames
// faster than the display would draw into the buffer still on screen
// (parts of the menus flickered). present() queues at most one frame per
// vertical blank, which keeps the buffer being drawn off screen.
// Frames are also held to 30 per second (two vertical blanks each): the
// game's Flash movies are authored at 30 fps (menus, levels, characters)
// and advance one frame per game frame, so at 60 the menus ran at double
// speed; the 360 version is reported to run at 30. Slower frames show at the
// next vertical blank as before.
constexpr DWORD kPresentVblanks = 2;
DWORD g_present_vbl = 0;
void present() {
  while (pb_get_vbl_counter() - g_present_vbl < kPresentVblanks) pb_wait_for_vbl();
  while (pb_finished()) {}
  g_present_vbl = pb_get_vbl_counter();
}
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
  auto* p = xr_begin();
  p = pb_push1(p, NV097_SET_TRANSFORM_PROGRAM_START, 0);
  p = pb_push1(p, NV097_SET_TRANSFORM_EXECUTION_MODE,
               NV097_SET_TRANSFORM_EXECUTION_MODE_MODE_PROGRAM |
                   (NV097_SET_TRANSFORM_EXECUTION_MODE_RANGE_MODE_PRIV << 2));
  p = pb_push1(p, NV097_SET_TRANSFORM_PROGRAM_CXT_WRITE_EN, 0);
  p = pb_push1(p, NV097_SET_TRANSFORM_PROGRAM_LOAD, 0);
  xr_end(p);
  for (size_t i = 0; i < sizeof(program) / sizeof(program[0]); i += 4) {
    p = xr_begin();
    pb_push(p++, NV097_SET_TRANSFORM_PROGRAM, 4);
    std::memcpy(p, program + i, 16);
    p += 4;
    xr_end(p);
  }
  p = xr_begin();
#include "ps.inl"
  xr_end(p);
}

void set_attributes() {
  auto* p = xr_begin();
  pb_push(p++, NV097_SET_VERTEX_DATA_ARRAY_FORMAT, 16);
  for (int i = 0; i < 16; ++i) *p++ = NV097_SET_VERTEX_DATA_ARRAY_FORMAT_TYPE_F;
  xr_end(p);
  struct Attribute { uint32_t index, components, offset; };
  const Attribute attrs[] = {{0, 4, 0}, {3, 4, 16}, {9, 2, 32}};
  for (const Attribute& a : attrs) {
    p = xr_begin();
    p = pb_push1(p, NV097_SET_VERTEX_DATA_ARRAY_FORMAT + 4 * a.index,
                 NV097_SET_VERTEX_DATA_ARRAY_FORMAT_TYPE_F | (a.components << 4) |
                     (sizeof(GpuVertex) << 8));
    p = pb_push1(p, NV097_SET_VERTEX_DATA_ARRAY_OFFSET + 4 * a.index,
                 physical(reinterpret_cast<const uint8_t*>(g_vb) + a.offset));
    xr_end(p);
  }
}

// 4x4 opaque white texture bound for untextured draws: the pixel program
// always samples stage 0, so it must never be left disabled.
uint32_t* g_white = nullptr;

bool init() {
  if (g_init) return !g_failed;
  g_init = true;
  if (pb_init() != 0) { g_failed = true; debugPrint("RENDER pb_init failed\n"); return false; }
  g_vb = static_cast<GpuVertex*>(MmAllocateContiguousMemoryEx(
      kMaxVertices * sizeof(GpuVertex), 0, kMaxGpuAddress, 0, PAGE_READWRITE | PAGE_WRITECOMBINE));
  if (!g_vb) { g_failed = true; debugPrint("RENDER no vertex memory\n"); return false; }
  g_white = static_cast<uint32_t*>(MmAllocateContiguousMemoryEx(
      64, 0, kMaxGpuAddress, 0, PAGE_READWRITE | PAGE_WRITECOMBINE));
  if (!g_white) { g_failed = true; return false; }
  for (int i = 0; i < 16; ++i) g_white[i] = 0xFFFFFFFFu;
  return true;
}
// Texture and blend state last sent to the GPU this frame; draws only
// send what changed (a level frame has ~236 draws over ~82 textures).
struct PushedState { bool valid = false; const void* tex = nullptr; uint32_t format = 0, rect = 0, sf = 0, df = 0; };
PushedState g_ps;
uint32_t* push_white(uint32_t* p) {
  p = pb_push1(p, NV097_SET_TEXTURE_OFFSET, physical(g_white));
  p = pb_push1(p, NV097_SET_TEXTURE_FORMAT,
               0x0000002Au | (NV097_SET_TEXTURE_FORMAT_COLOR_LU_IMAGE_A8R8G8B8 << 8) | (1u << 16));
  p = pb_push1(p, NV097_SET_TEXTURE_CONTROL1, 16u << 16);
  p = pb_push1(p, NV097_SET_TEXTURE_IMAGE_RECT, (4u << 16) | 4u);
  p = pb_push1(p, NV097_SET_TEXTURE_ADDRESS, 0x00050505);
  p = pb_push1(p, NV097_SET_TEXTURE_CONTROL0, 0x40000000);
  p = pb_push1(p, NV097_SET_TEXTURE_FILTER, 0x02022000);
  return p;
}

void begin_frame() {
  g_ps = PushedState();
  xr_flush();
  pb_reset();
  pb_target_back_buffer();
  pb_erase_depth_stencil_buffer(0, 0, 640, 480);
  pb_fill(0, 0, 640, 480, 0xff000000);
  upload_shaders();
  set_attributes();
  auto* p = xr_begin();
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
  xr_end(p);
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
// (kind 5) texture. The game draws into some of these after the first bind
// (the font atlas gains glyphs as text appears) and reuses freed blocks for
// new textures, so each bind samples the source (every 61st byte, ~2 KB for
// a 128 KB atlas) and reconverts in place when the sample changes.
uint32_t sample_sig(const uint8_t* src, uint32_t bytes) {
  uint32_t h = 2166136261u;
  for (uint32_t i = 0; i < bytes; i += 61u) { h ^= src[i]; h *= 16777619u; }
  return h ^ bytes;
}
void convert_into(uint8_t* dst, const uint8_t* src, uint32_t w, uint32_t h, int kind) {
  if (kind == 1) {
    for (uint32_t i = 0; i < w * h; ++i) {  // A R G B -> B G R A
      dst[i * 4 + 0] = src[i * 4 + 3]; dst[i * 4 + 1] = src[i * 4 + 2];
      dst[i * 4 + 2] = src[i * 4 + 1]; dst[i * 4 + 3] = src[i * 4 + 0];
    }
  } else {
    for (uint32_t i = 0; i < w * h; ++i) { dst[i * 2 + 0] = src[i * 2 + 1]; dst[i * 2 + 1] = src[i * 2 + 0]; }
  }
}
const Texture* converted(uint32_t key, const uint8_t* src, uint32_t w, uint32_t h, int kind) {
  const uint32_t bpp = kind == 1 ? 4u : 2u;
  const uint32_t bytes = w * h * bpp;
  // Most recent hit first (the same few linear textures are bound over and
  // over), then the full list.
  static size_t last = 0;
  if (last < g_converted.size()) {
    const Texture& c = g_converted[last];
    if (!(c.key == key && c.w == w && c.h == h && c.pitch == w * bpp)) last = g_converted.size();
  }
  if (last >= g_converted.size())
    for (size_t i = 0; i < g_converted.size(); ++i) {
      const Texture& c = g_converted[i];
      if (c.key == key && c.w == w && c.h == h && c.pitch == w * bpp) { last = i; break; }
    }
  if (last < g_converted.size()) {
    Texture& t = g_converted[last];
    {
      // The source is sampled once per frame per texture: the font atlas
      // (1024x1024 A4R4G4B4, 2 MB, ~34K samples) is bound several times a
      // frame, and glyphs added mid-frame show from the next frame on.
      // One eighth of the rows is sampled per frame (round robin) and only
      // a changed slice is converted again: sampling the whole 2 MB atlas
      // every frame was ~34K cache misses per frame on the console. Glyphs
      // the game adds show within 8 frames.
      if (t.checked != g_frames) {
        t.checked = g_frames;
        const uint32_t k = t.slice_next++ & 7u;
        const uint32_t row0 = h * k / 8u, row1 = h * (k + 1u) / 8u;
        const uint32_t off = row0 * w * bpp, len = (row1 - row0) * w * bpp;
        const uint32_t sig = sample_sig(src + off, len);
        if (t.slice_sig[k] != sig) {
          convert_into(static_cast<uint8_t*>(const_cast<void*>(t.gpu)) + off, src + off, w, row1 - row0, kind);
          t.slice_sig[k] = sig;
        }
      }
      return &t;
    }
  }
  const uint32_t sig = sample_sig(src, bytes);
  uint8_t* dst = static_cast<uint8_t*>(MmAllocateContiguousMemoryEx(
      bytes, 0, kMaxGpuAddress, 0, PAGE_READWRITE | PAGE_WRITECOMBINE));
  if (!dst) return nullptr;
  convert_into(dst, src, w, h, kind);
  Texture t;
  t.key = key; t.w = w; t.h = h; t.gpu = dst; t.pitch = w * bpp; t.normalized = false; t.sig = sig; t.checked = g_frames;
  for (uint32_t k = 0; k < 8u; ++k) {
    const uint32_t row0 = h * k / 8u, row1 = h * (k + 1u) / 8u;
    t.slice_sig[k] = sample_sig(src + row0 * w * bpp, (row1 - row0) * w * bpp);
  }
  t.format = 0x0000002Au |
             ((kind == 1 ? NV097_SET_TEXTURE_FORMAT_COLOR_LU_IMAGE_A8R8G8B8
                         : NV097_SET_TEXTURE_FORMAT_COLOR_LU_IMAGE_A4R4G4B4) << 8) |
             (1u << 16);
  g_converted.push_back(t);
  return &g_converted.back();
}

// Overlay rectangles are queued as untextured quads and drawn in one batch
// (pbkit clears are very slow under XEMU).
struct OverlayRect { float x, y, w, h; DWORD color; };
OverlayRect g_rects[2048];
unsigned g_rect_count = 0;
void pb_fill_quad(int x, int y, int w, int h, DWORD color) {
  if (g_rect_count < 2048) g_rects[g_rect_count++] = OverlayRect{float(x), float(y), float(w), float(h), color};
}
void flush_overlay() {
  if (!g_rect_count || g_vb_used + g_rect_count * 4 > kMaxVertices) { g_rect_count = 0; return; }
  GpuVertex* out = g_vb + g_vb_used;
  for (unsigned i = 0; i < g_rect_count; ++i) {
    const OverlayRect& r = g_rects[i];
    const float xs[4] = {r.x, r.x + r.w, r.x + r.w, r.x}, ys[4] = {r.y, r.y, r.y + r.h, r.y + r.h};
    for (int k = 0; k < 4; ++k) {
      GpuVertex& o = out[i * 4 + k];
      o.pos[0] = xs[k]; o.pos[1] = ys[k]; o.pos[2] = 0.0f; o.pos[3] = 1.0f;
      o.col[0] = float((r.color >> 16) & 255) / 255.0f; o.col[1] = float((r.color >> 8) & 255) / 255.0f;
      o.col[2] = float(r.color & 255) / 255.0f; o.col[3] = 1.0f;
      o.uv[0] = o.uv[1] = 0.0f;
    }
  }
  auto* p = xr_begin();
  g_ps = PushedState();
  p = push_white(p);
  p = pb_push1(p, NV097_SET_BLEND_FUNC_SFACTOR, NV097_SET_BLEND_FUNC_SFACTOR_V_ONE);
  p = pb_push1(p, NV097_SET_BLEND_FUNC_DFACTOR, NV097_SET_BLEND_FUNC_SFACTOR_V_ZERO);
  p = pb_push1(p, NV097_SET_BEGIN_END, NV097_SET_BEGIN_END_OP_QUADS);
  const uint32_t count = g_rect_count * 4;
  for (uint32_t first = 0; first < count; first += 256) {
    const uint32_t n = count - first < 256 ? count - first : 256;
    p = pb_push1(p, 0x40000000 | NV097_DRAW_ARRAYS, ((n - 1) << 24) | (g_vb_used + first));
  }
  p = pb_push1(p, NV097_SET_BEGIN_END, NV097_SET_BEGIN_END_OP_END);
  xr_end(p);
  g_vb_used += count;
  g_rect_count = 0;
}
// Seven-segment digit at (x, y), 12x20 pixels, one rectangle per lit segment.
void draw_digit(int x, int y, unsigned d, DWORD color) {
  static const uint8_t seg[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
  const uint8_t m = seg[d % 10];
  if (m & 0x01) pb_fill_quad(x + 2, y, 8, 2, color);        // a
  if (m & 0x02) pb_fill_quad(x + 10, y + 2, 2, 7, color);   // b
  if (m & 0x04) pb_fill_quad(x + 10, y + 11, 2, 7, color);  // c
  if (m & 0x08) pb_fill_quad(x + 2, y + 18, 8, 2, color);   // d
  if (m & 0x10) pb_fill_quad(x, y + 11, 2, 7, color);       // e
  if (m & 0x20) pb_fill_quad(x, y + 2, 2, 7, color);        // f
  if (m & 0x40) pb_fill_quad(x + 2, y + 9, 8, 2, color);    // g
}
// Microseconds from the CPU cycle counter, for the timing counters.
uint64_t now_us() {
  static uint64_t freq = 0;
  if (!freq) freq = KeQueryPerformanceFrequency() / 1000000u;
  return KeQueryPerformanceCounter() / freq;
}
uint64_t g_draw_us = 0;
// Hexadecimal digit (0-15) in the same seven-segment style.
void draw_hex_digit(int x, int y, unsigned d, DWORD color) {
  static const uint8_t seg[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
                                   0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
  const uint8_t m = seg[d & 15];
  if (m & 0x01) pb_fill_quad(x + 2, y, 8, 2, color);
  if (m & 0x02) pb_fill_quad(x + 10, y + 2, 2, 7, color);
  if (m & 0x04) pb_fill_quad(x + 10, y + 11, 2, 7, color);
  if (m & 0x08) pb_fill_quad(x + 2, y + 18, 8, 2, color);
  if (m & 0x10) pb_fill_quad(x, y + 11, 2, 7, color);
  if (m & 0x20) pb_fill_quad(x, y + 2, 2, 7, color);
  if (m & 0x40) pb_fill_quad(x + 2, y + 9, 8, 2, color);
}
void draw_number(int x, int y, unsigned v, DWORD color) {
  char buf[8];
  int n = 0;
  do { buf[n++] = char(v % 10); v /= 10; } while (v && n < 4);
  for (int i = 0; i < n; ++i) draw_digit(x + (n - 1 - i) * 15, y, unsigned(buf[i]), color);
}
}  // namespace

#ifdef CC_XBOX_PROFILE
bool cc_xprof_top(unsigned kind, unsigned i, uint32_t* addr, unsigned* permille);
#endif

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
  const uint64_t t0 = now_us();
  struct Tally { uint64_t t0; ~Tally() { g_draw_us += now_us() - t0; } } tally{t0};
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
    constexpr float k = 1.0f / 255.0f;
    o.col[0] = float((argb >> 16) & 255) * k; o.col[1] = float((argb >> 8) & 255) * k;
    o.col[2] = float(argb & 255) * k; o.col[3] = float(argb >> 24) * k;
    o.uv[0] = bef(v + 12) * su; o.uv[1] = bef(v + 16) * sv;
  }
  auto* p = xr_begin();
  const void* tex = g_have_tex ? g_cur.gpu : static_cast<const void*>(g_white);
  const uint32_t fmt = g_have_tex ? g_cur.format : 0u;
  const uint32_t rect = g_have_tex ? ((g_cur.w << 16) | g_cur.h) ^ (g_cur.pitch << 3) : 0u;
  if (!g_ps.valid || g_ps.tex != tex || g_ps.format != fmt || g_ps.rect != rect) {
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
      p = push_white(p);
    }
    g_ps.tex = tex; g_ps.format = fmt; g_ps.rect = rect;
  }
  const uint32_t sf = blend_factor(blend & 0x1F), df = blend_factor((blend >> 8) & 0x1F);
  if (!g_ps.valid || g_ps.sf != sf || g_ps.df != df) {
    p = pb_push1(p, NV097_SET_BLEND_FUNC_SFACTOR, sf);
    p = pb_push1(p, NV097_SET_BLEND_FUNC_DFACTOR, df);
    g_ps.sf = sf; g_ps.df = df;
  }
  g_ps.valid = true;
  p = pb_push1(p, NV097_SET_BEGIN_END, op);
  for (uint32_t first = 0; first < count; first += 256) {
    const uint32_t n = count - first < 256 ? count - first : 256;
    p = pb_push1(p, 0x40000000 | NV097_DRAW_ARRAYS, ((n - 1) << 24) | (g_vb_used + first));
  }
  p = pb_push1(p, NV097_SET_BEGIN_END, NV097_SET_BEGIN_END_OP_END);
  xr_end(p);
  g_vb_used += count;
  ++g_draws;
}

// Wait for the GPU to finish everything queued so far (called before a
// texture still referenced by this frame's draws is evicted and its zone
// block reused).
void cc_xr_gpu_idle() {
  if (!g_in_frame) return;
  xr_flush(); while (pb_busy()) {}
}

// Harness failure on the Xbox: show the error code and guest address as
// digits (the debug text console is hidden behind the pbkit display) and
// present that frame, so a stopped game reports why on screen.
void cc_xr_show_fail(uint32_t code, uint32_t addr) {
  DbgPrint("FAIL code=%u addr=%08x\n", unsigned(code), unsigned(addr));
  if (!init()) return;
  if (!g_in_frame) begin_frame();
  pb_fill_quad(8, 300, 400, 40, 0xFF400000);
  draw_number(16, 310, code, 0xFFFFFFFF);
  for (int k = 0; k < 8; ++k) draw_hex_digit(80 + k * 15, 310, (addr >> (28 - 4 * k)) & 15u, 0xFFFFFF40);
  flush_overlay();
  xr_flush(); while (pb_busy()) {}
  present();
  if (!g_shown) { pb_show_front_screen(); g_shown = true; }
  g_in_frame = false;
}

// Frame boundary: wait for the GPU and present.
// update_us/render_us: time in the game's update and render this frame.
// Benchmark windows (BENCH builds): average frame / update / render time in
// tenths of a millisecond, drawn under the live counters once complete.
unsigned g_bench[4][3];
bool g_bench_done[4];
void cc_xr_bench(unsigned window, unsigned frames, unsigned frame_us, unsigned update_us, unsigned render_us) {
  if (window >= 4 || !frames) return;
  g_bench[window][0] = frame_us / 100u; g_bench[window][1] = update_us / 100u; g_bench[window][2] = render_us / 100u;
  DbgPrint("BENCH window=%u frames=%u frame_us=%u update_us=%u render_us=%u\n", window, frames, frame_us, update_us, render_us);
  g_bench_done[window] = true;
}
void cc_xr_frame_end(uint32_t update_us, uint32_t render_us) {
  if (!g_in_frame) return;
  // On-screen counters, averaged over each second of real time. Top row:
  // frames per second, ms per frame, audio buffers mixed/s, silent/s.
  // Bottom row, ms per frame: game update, game render (includes the
  // draw hand-off), draw hand-off to the GPU, waiting for the GPU.
  static DWORD window_start = 0;
  static unsigned window_frames = 0, shown_fps = 0, shown_ms = 0;
  static uint64_t sum_update = 0, sum_render = 0, sum_draw = 0, sum_wait = 0, last_wait = 0;
  static unsigned shown_update = 0, shown_render = 0, shown_draw = 0, shown_wait = 0;
  sum_update += update_us; sum_render += render_us; sum_draw += g_draw_us; sum_wait += last_wait;
  g_draw_us = 0;
  // Longest frame of the window (frame end to frame end).
  static uint64_t last_end_us = 0, max_frame_us = 0;
  {
    const uint64_t t = now_us();
    if (last_end_us && t - last_end_us > max_frame_us) max_frame_us = t - last_end_us;
    last_end_us = t;
  }
  const DWORD now = GetTickCount();
  if (!window_start) window_start = now;
  ++window_frames;
  if (now - window_start >= 1000) {
    // The same window on the debug channel (XBDM debug strings, read on the
    // PC by tools/xbox_console.py): times in 0.1 ms.
    {
      const unsigned el = now - window_start;
      DbgPrint("PERF t=%u fps=%u ms=%u max=%u upd=%u ren=%u draw=%u wait=%u\n", unsigned(now), window_frames * 1000u / el,
               el * 10u / window_frames, unsigned(max_frame_us / 100u), unsigned(sum_update / window_frames / 100u),
               unsigned(sum_render / window_frames / 100u), unsigned(sum_draw / window_frames / 100u),
               unsigned(sum_wait / window_frames / 100u));
      max_frame_us = 0;
      { void cc_xbox_perf_second(unsigned frames); cc_xbox_perf_second(window_frames); }  // xbox_perf.cpp
    }
    shown_fps = window_frames * 1000u / (now - window_start);
    shown_ms = (now - window_start) / window_frames;
    shown_update = unsigned(sum_update / window_frames / 1000u);
    shown_render = unsigned(sum_render / window_frames / 1000u);
    shown_draw = unsigned(sum_draw / window_frames / 1000u);
    shown_wait = unsigned(sum_wait / window_frames / 1000u);
    sum_update = sum_render = sum_draw = sum_wait = 0;
    window_start = now;
    window_frames = 0;
  }
  // Numbers drawn as seven-segment digits with a few fills each (pbkit's
  // text overlay issues ~1,000 fills a frame and slows the game down).
  {
    unsigned st = 0, fed = 0, cb = 0, ur = 0, dr = 0;
    cc_xbox_audio_stats(&st, &fed, &cb, &ur, &dr);
    static unsigned last_fed = 0, last_ur = 0, shown_mixed = 0, shown_silent = 0;
    if (window_frames == 0) {  // refreshed once per second with the fps
      shown_mixed = fed - last_fed; shown_silent = ur - last_ur;
      last_fed = fed; last_ur = ur;
    }
    pb_fill_quad(8, 8, 300, 80, 0xFF202020);
    draw_number(16, 14, shown_fps, 0xFF40FF40);       // frames per second
    draw_number(80, 14, shown_ms, 0xFFFFFF40);        // ms per frame
    draw_number(160, 14, shown_mixed, 0xFF40C0FF);    // audio frames mixed/s
    draw_number(232, 14, shown_silent, 0xFFFF4040);   // silent buffers/s
    draw_number(16, 44, shown_update, 0xFFFFFFFF);    // update ms
    draw_number(80, 44, shown_render, 0xFFFFA040);    // render ms
    draw_number(160, 44, shown_draw, 0xFFC080FF);     // draw hand-off ms
    draw_number(232, 44, shown_wait, 0xFF80FFFF);     // GPU wait ms
    for (unsigned w = 0; w < 4; ++w)
      if (g_bench_done[w]) {
        const int y = 96 + int(w) * 34;
        pb_fill_quad(8, y - 4, 300, 32, 0xFF102040);
        draw_number(16, y, g_bench[w][0], 0xFFFFFF40);   // frame, 0.1 ms
        draw_number(112, y, g_bench[w][1], 0xFFFFFFFF);  // update, 0.1 ms
        draw_number(208, y, g_bench[w][2], 0xFFFFA040);  // render, 0.1 ms
      }
#ifdef CC_XBOX_PROFILE
    // Profiler: last 20 s window. Left column self time, right column
    // inclusive; each row: 6 hex digits of the address (0x82xxxxxx) and
    // per mille of samples.
    pb_fill_quad(8, 92, 400, 14 * 22 + 8, 0xFF202020);
    for (unsigned kind = 0; kind < 2; ++kind)
      for (unsigned i = 0; i < 14; ++i) {
        uint32_t a = 0; unsigned pm = 0;
        if (!cc_xprof_top(kind, i, &a, &pm)) break;
        const int x = 16 + int(kind) * 200, y = 98 + int(i) * 22;
        for (int k = 0; k < 6; ++k)
          draw_hex_digit(x + k * 15, y, (a >> (20 - 4 * k)) & 15u, kind ? 0xFFFFA040 : 0xFFFFFFFF);
        draw_number(x + 100, y, pm, 0xFF40FF40);
      }
#endif
    flush_overlay();
  }
  const uint64_t w0 = now_us();
  xr_flush(); while (pb_busy()) {}
  present();
  last_wait = now_us() - w0;
  if (!g_shown) { pb_show_front_screen(); g_shown = true; }
  g_in_frame = false;
  ++g_frames;
}
