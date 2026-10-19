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
#include <cstdio>
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
  uint32_t slice_next = 0;         // slice checked next
  uint32_t stable = 0;             // slice checks in a row that found no change
};

bool g_init = false, g_failed = false, g_in_frame = false, g_shown = false;
// Submissions share one open push-buffer block: pbkit's pb_end kicks the GPU
// (write-combine flush with a busy wait, an uncached GPU register read, then
// the DMA put), which per sprite and per counter segment cost hundreds of
// kicks a frame on the console. The block is kicked every 128 submissions,
// before any wait for the GPU and before pbkit's own drawing calls (pbkit
// rewinds to the 512 KB push buffer's head every frame, so a longer open
// block only delays when the GPU starts on it; it waits ~0.1 ms a frame).
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
  if (++g_open_n >= 128u) xr_flush();
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
uint64_t now_us();
// The last present's two waits (PERF line, slowest frame): for the frame's
// vertical blanks, and for pbkit to accept the frame (all three
// framebuffers queued).
uint64_t g_present_vbl_us = 0, g_present_queue_us = 0;
void present() {
  // (Audio is fed by its own thread, xbox_audio.cpp.)
  const uint64_t t0 = now_us();
  while (pb_get_vbl_counter() - g_present_vbl < kPresentVblanks) pb_wait_for_vbl();
  const uint64_t t1 = now_us();
  while (pb_finished()) {}
  g_present_vbl_us = t1 - t0;
  g_present_queue_us = now_us() - t1;
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
struct PushedState {
  bool valid = false; const void* tex = nullptr; uint32_t format = 0, rect = 0, sf = 0, df = 0;
  uint32_t mask = 0, mask_id = 0;  // stencil use (kMask*) and the mask's stencil value
};
PushedState g_ps;
// Masks. The game draws through materials, the modes its renderer keeps on
// a stack (renderer slots 32 / 36; runtime021 passes the top one with each
// draw, cc_xr_set_material). The display-list walk pushes material 11 for a
// clip-depth child (the mask shape) and 10 for the children it clips; the
// 360 draws the shape into a mask image and clips with it in a shader. Here
// each mask (cc_xr_mask_begin) gets its own stencil value: material 11
// writes it where the shape's pixels are opaque (alpha test, no colour),
// material 10 draws only where the stencil holds it. Drawing the shape in
// colour instead cut rectangles out of the loading screen's wipe. The
// stencil is cleared with the depth buffer at each frame's start.
constexpr uint32_t kMaskOff = 0, kMaskWrite = 1, kMaskTest = 2;
uint32_t g_material = 0, g_mask_id = 0;
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

// Waits until the GPU has finished everything handed to it. pbkit's
// pb_busy() only checks that the DMA engine has fetched up to the put
// pointer and that PGRAPH is busy at that instant; fetched methods wait in
// the PFIFO's CACHE1 in between, so between two queued draws pb_busy() can
// read idle with draws still to run. Idle here means: fetched (pb_busy's
// first test), the DMA pusher stopped, CACHE1 and the runout queue empty,
// then PGRAPH idle (nv2a registers as pbkit's pb_wait_until_tiles_not_busy
// checks them). Texture memory and the vertex buffer are reused only after
// this; with the weaker wait, draws still queued sampled textures already
// overwritten (the book menu's one-frame wrong pictures).
static inline uint32_t nv_reg(uint32_t off) { return *reinterpret_cast<volatile uint32_t*>(0xFD000000u + off); }
static inline uint8_t nv_reg8(uint32_t off) { return *reinterpret_cast<volatile uint8_t*>(0xFD000000u + off); }
// Strict idle test (no waiting).
static bool gpu_strict_idle() {
  return !pb_busy() && !(nv_reg8(0x3220) & 0x10) && (nv_reg8(0x3214) & 0x10) && (nv_reg8(0x2400) & 0x10) &&
         nv_reg(0x400700) == 0;
}
// Diagnostics on the PERF line: gpi = waits where pb_busy() reported idle
// while queued work remained (WEAKIDLE builds), gpb = frames that began with
// the previous frame's draws still queued.
unsigned g_gpu_premature = 0, g_gpu_busy_at_begin = 0;
// Frames whose drawing began in the buffer the screen was showing
// (PCRTC_START, 0xFD600800): drawn while scanned out, partly drawn pictures
// reach the TV (ONSCR line).
unsigned g_draw_on_screen = 0;
// Idle epoch: bumped each time the GPU has been seen fully idle, so
// everything queued before that point is drawn. A texture last bound at
// epoch E is no longer sampled once the epoch has moved past E (runtime021's
// texture eviction, cc_xr_gpu_epoch).
uint32_t g_gpu_epoch = 1;
void gpu_wait_idle() {
#ifdef CC_XR_WEAK_IDLE
  // A/B build (make WEAKIDLE=1): pbkit's pb_busy() alone, as before (the
  // epoch never moves: no texture counts as finished).
  while (pb_busy()) {}
  if (!gpu_strict_idle()) ++g_gpu_premature;
  return;
#endif
  for (;;) {
    if (pb_busy()) continue;
    if (nv_reg8(0x3220) & 0x10) continue;          // NV_PFIFO_CACHE1_DMA_PUSH: pusher busy
    if (!(nv_reg8(0x3214) & 0x10)) continue;       // NV_PFIFO_CACHE1_STATUS: not empty
    if (!(nv_reg8(0x2400) & 0x10)) continue;       // NV_PFIFO_RUNOUT_STATUS: not empty
    if (nv_reg(0x400700) != 0) continue;           // NV_PGRAPH_STATUS: busy
    ++g_gpu_epoch;
    return;
  }
}
// This frame's GPU waits (PERF line, slowest frame): begin_frame's, and the
// texture evictions' (count and time).
uint64_t g_frame_begin_wait_us = 0, g_frame_tex_wait_us = 0;
unsigned g_frame_tex_waits = 0, g_tex_waits = 0;
uint64_t g_tex_wait_us = 0;

#ifdef CC_WRAP_TEST
void pb_fill_quad(int x, int y, int w, int h, DWORD color);
void flush_overlay();
#endif
void begin_frame() {
  g_ps = PushedState();
  g_mask_id = 0;
  xr_flush();
  pb_reset();
  if (!gpu_strict_idle()) ++g_gpu_busy_at_begin;
  // The previous frame's draws (the frame end does not wait) must be done
  // before this frame rewrites the vertex buffer from its start. The game's
  // update has run since, so this is normally already true.
  const uint64_t w0 = now_us();
  gpu_wait_idle();
  g_frame_begin_wait_us += now_us() - w0;
  pb_target_back_buffer();
  if ((reinterpret_cast<uintptr_t>(pb_back_buffer()) & 0x03FFFFFFu) == (nv_reg(0x600800) & 0x03FFFFFFu)) ++g_draw_on_screen;
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
#ifdef CC_WRAP_TEST
  // Off-screen quads first: does a quad wholly outside the 640x480 surface
  // disturb the draws after it? (They themselves must not show.)
  // Every other second (as the Quaff menu's scrolling tiles do), two extra
  // quads ahead of the frame's sprites shift every later sprite 8 vertices.
  if ((g_frames / 30u) & 1u) {
    pb_fill_quad(800, 100, 200, 200, 0xFFFF0000);   // fully right of the surface
    pb_fill_quad(886, -34, 170, 280, 0xFFFF0000);   // where the Quaff tiles sit
    flush_overlay();
  }
#endif
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
      // every frame was ~34K cache misses per frame on the console. After
      // 64 slice checks in a row without a change (the font block never
      // changed after load in host runs through menus, two levels and the
      // map), a slice is checked only every 8th frame; a change found goes
      // back to every frame. Glyphs the game adds show within 8 frames, or
      // 64 after a long quiet stretch. (Even one slice a frame was ~3% of
      // the CPU in the four-player marsh fight.)
      if (t.checked != g_frames && (t.stable < 64u || (g_frames & 7u) == (t.key & 7u))) {
        t.checked = g_frames;
        const uint32_t k = t.slice_next++ & 7u;
        const uint32_t row0 = h * k / 8u, row1 = h * (k + 1u) / 8u;
        const uint32_t off = row0 * w * bpp, len = (row1 - row0) * w * bpp;
        const uint32_t sig = sample_sig(src + off, len);
        if (t.slice_sig[k] != sig) {
          convert_into(static_cast<uint8_t*>(const_cast<void*>(t.gpu)) + off, src + off, w, row1 - row0, kind);
          t.slice_sig[k] = sig;
          t.stable = 0;
        } else if (t.stable < 64u) {
          ++t.stable;
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

// Texture and blend state (only what changed since the last draw), then one
// draw of `count` vertices from g_vb[first] with primitive `op`.
void emit_draw(uint32_t op, uint32_t first, uint32_t count, uint32_t blend) {
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
  const uint32_t mask = g_material == 11u ? kMaskWrite : g_material == 10u ? kMaskTest : kMaskOff;
  if (!g_ps.valid || mask != g_ps.mask || (mask != kMaskOff && g_mask_id != g_ps.mask_id)) {
    if (mask == kMaskOff) {
      p = pb_push1(p, NV097_SET_STENCIL_TEST_ENABLE, 0);
      p = pb_push1(p, NV097_SET_ALPHA_TEST_ENABLE, 0);
      p = pb_push1(p, NV097_SET_COLOR_MASK, 0x01010101);
    } else {
      const bool write = mask == kMaskWrite;
      p = pb_push1(p, NV097_SET_STENCIL_TEST_ENABLE, 1);
      p = pb_push1(p, NV097_SET_STENCIL_MASK, 0xFF);
      p = pb_push1(p, NV097_SET_STENCIL_FUNC, write ? NV097_SET_ALPHA_FUNC_V_ALWAYS : NV097_SET_ALPHA_FUNC_V_EQUAL);
      p = pb_push1(p, NV097_SET_STENCIL_FUNC_REF, g_mask_id);
      p = pb_push1(p, NV097_SET_STENCIL_FUNC_MASK, 0xFF);
      p = pb_push1(p, NV097_SET_STENCIL_OP_FAIL, NV097_SET_STENCIL_OP_V_KEEP);
      p = pb_push1(p, NV097_SET_STENCIL_OP_ZFAIL, NV097_SET_STENCIL_OP_V_KEEP);
      p = pb_push1(p, NV097_SET_STENCIL_OP_ZPASS, write ? NV097_SET_STENCIL_OP_V_REPLACE : NV097_SET_STENCIL_OP_V_KEEP);
      p = pb_push1(p, NV097_SET_ALPHA_TEST_ENABLE, write ? 1 : 0);
      if (write) {
        p = pb_push1(p, NV097_SET_ALPHA_FUNC, NV097_SET_ALPHA_FUNC_V_GREATER);
        p = pb_push1(p, NV097_SET_ALPHA_REF, 0x7F);
      }
      p = pb_push1(p, NV097_SET_COLOR_MASK, write ? 0u : 0x01010101u);
    }
    g_ps.mask = mask; g_ps.mask_id = g_mask_id;
  }
  g_ps.valid = true;
  p = pb_push1(p, NV097_SET_BEGIN_END, op);
  for (uint32_t k = 0; k < count; k += 256) {
    const uint32_t n = count - k < 256 ? count - k : 256;
    p = pb_push1(p, 0x40000000 | NV097_DRAW_ARRAYS, ((n - 1) << 24) | (first + k));
  }
  p = pb_push1(p, NV097_SET_BEGIN_END, NV097_SET_BEGIN_END_OP_END);
  xr_end(p);
  ++g_draws;
}
// GPU vertex from a game vertex {x, y, z, u, v, argb} (z unused), uv scaled
// by the texture size for unnormalized textures.
inline void put_vertex(GpuVertex& o, float x, float y, float u, float v, uint32_t argb, float su, float sv) {
  constexpr float k = 1.0f / 255.0f;
  o.pos[0] = x; o.pos[1] = y; o.pos[2] = 0.0f; o.pos[3] = 1.0f;
  o.col[0] = float((argb >> 16) & 255) * k; o.col[1] = float((argb >> 8) & 255) * k;
  o.col[2] = float(argb & 255) * k; o.col[3] = float(argb >> 24) * k;
  o.uv[0] = u * su; o.uv[1] = v * sv;
}
// Quads from the native sprite path (cc_xr_quad) collect in one open batch
// of consecutive vertices while texture and blend factors stay the same.
// The batch is drawn as one quad-list draw before any other draw, texture
// change, overlay or GPU wait and at the frame end: the same vertices and
// states, in the same order, as one draw per quad.
uint32_t g_batch_first = 0, g_batch_n = 0, g_batch_blend = 0;
void flush_batch() {
  if (!g_batch_n) return;
  const uint32_t n = g_batch_n;
  g_batch_n = 0;
  emit_draw(NV097_SET_BEGIN_END_OP_QUADS, g_batch_first, n, g_batch_blend);
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
  flush_batch();
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
  p = pb_push1(p, NV097_SET_STENCIL_TEST_ENABLE, 0);
  p = pb_push1(p, NV097_SET_ALPHA_TEST_ENABLE, 0);
  p = pb_push1(p, NV097_SET_COLOR_MASK, 0x01010101);
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
// Microseconds from the kernel's performance counter, for the per-frame
// timing counters (scaled by the counter's frequency in Hz: an integer MHz
// divisor read a 3.375 MHz counter 12.5% high). Each call costs ~0.5 us on
// the console (a port read in the kernel), so per-draw timing uses the CPU's
// time-stamp counter instead.
uint64_t now_us() {
  static uint64_t freq = 0;
  if (!freq) freq = KeQueryPerformanceFrequency();
  const uint64_t c = KeQueryPerformanceCounter();
  return (c / freq) * 1000000u + (c % freq) * 1000000u / freq;
}
inline uint64_t cycles() {
  uint32_t lo, hi;
  asm volatile("rdtsc" : "=a"(lo), "=d"(hi));
  return (uint64_t(hi) << 32) | lo;
}
// Draw hand-off time this frame in CPU cycles, converted to microseconds at
// the frame end with the cycle rate measured against now_us() (733 MHz on
// the console; the measured rate also holds under emulation).
uint64_t g_draw_cycles = 0;
uint64_t draw_cycles_to_us(uint64_t c) {
  static uint64_t c0 = 0, u0 = 0, per_us = 733;
  const uint64_t cn = cycles(), un = now_us();
  if (!c0) { c0 = cn; u0 = un; }
  else if (un - u0 >= 1000000u) {  // re-measured each second
    per_us = (cn - c0) / (un - u0);
    if (!per_us) per_us = 1;
    c0 = cn; u0 = un;
  }
  return c / per_us;
}
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
  // Rebinding the texture already current this frame (consecutive sprites
  // mostly share one) changes nothing: g_cur would be rebuilt from the same
  // inputs, and a converted texture has had this frame's sample check.
  static struct { uint32_t key, w, h, frame; const void* data; int kind; } last{};
  if (g_have_tex && key == last.key && data == last.data && w == last.w && h == last.h && kind == last.kind &&
      last.frame == g_frames)
    return;
  flush_batch();  // the open batch draws with the texture it was built for
  g_have_tex = false;
  if (!data || !w || !h || w > 4096 || h > 4096) return;
  if (kind == 100) {
    g_cur = Texture();
    g_cur.key = key; g_cur.w = w; g_cur.h = h; g_cur.gpu = data; g_cur.normalized = true;
    g_cur.format = 0x0000002Au | (NV097_SET_TEXTURE_FORMAT_COLOR_L_DXT45_A8R8G8B8 << 8) |
                   (1u << 16) | (log2u(w) << 20) | (log2u(h) << 24);
    g_have_tex = true;
  } else if (kind == 1 || kind == 5) {
    if (const Texture* t = converted(key, static_cast<const uint8_t*>(data), w, h, kind)) {
      g_cur = *t;
      g_have_tex = true;
    }
  }
  if (g_have_tex) { last.key = key; last.w = w; last.h = h; last.frame = g_frames; last.data = data; last.kind = kind; }
}

// One draw of the game's: prim 13 quad list, 4 triangle list, 5 strip;
// vertices are big-endian {x, y, z, u, v, argb} (stride 24) or, for the
// quad emitter's effect modes (stride 32), {x, y, z, u, v, u2, v2, argb}
// whose second coordinate pair feeds the 360 effect shaders (not drawn
// here).
#ifdef CC_DRAW_DIAG
// Draw diagnostics (make DRAWDIAG=1): per frame, draws per material (quads
// through cc_xr_quad, others through cc_xr_draw) and every primitive whose
// corners span over 600 px, with its first four corners, printed as DRAW
// lines for frames that have a material other than 0/1/3/5/7/8/9/12/16 or a
// big primitive (cc_draw_diag_frame).
unsigned g_dd_mat[32], g_dd_big = 0;
struct DdBig { uint32_t mat, path, count; float xy[8]; };
DdBig g_dd_samples[6];
void dd_note(uint32_t path, uint32_t count, const float* xy, unsigned n) {
  ++g_dd_mat[g_material < 31u ? g_material : 31u];
  float x0 = 1e30f, x1 = -1e30f, y0 = 1e30f, y1 = -1e30f;
  for (unsigned i = 0; i < n; ++i) {
    const float x = xy[2 * i], y = xy[2 * i + 1];
    if (!(x == x) || !(y == y)) { x0 = -1e30f; x1 = 1e30f; break; }  // NaN: counts as big
    if (x < x0) x0 = x; if (x > x1) x1 = x; if (y < y0) y0 = y; if (y > y1) y1 = y;
  }
  if (x1 - x0 > 600.0f || y1 - y0 > 600.0f) {
    if (g_dd_big < 6u) {
      DdBig& b = g_dd_samples[g_dd_big];
      b.mat = g_material; b.path = path; b.count = count;
      for (unsigned i = 0; i < 8; ++i) b.xy[i] = i < 2 * n ? xy[i] : 0.0f;
    }
    ++g_dd_big;
  }
}
void cc_draw_diag_frame() {
  static unsigned frame = 0;
  ++frame;
  bool odd = g_dd_big != 0;
  for (unsigned m = 0; m < 32; ++m)
    if (g_dd_mat[m] && !(m == 0 || m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 9 || m == 12 || m == 16)) odd = true;
  if (odd) {
    DbgPrint("DRAW f=%u m0=%u m2=%u m6=%u m10=%u m11=%u m14=%u m15=%u other=%u big=%u\n", frame, g_dd_mat[0], g_dd_mat[2],
             g_dd_mat[6], g_dd_mat[10], g_dd_mat[11], g_dd_mat[14], g_dd_mat[15],
             g_dd_mat[1] + g_dd_mat[3] + g_dd_mat[5] + g_dd_mat[7] + g_dd_mat[8] + g_dd_mat[9] + g_dd_mat[12] + g_dd_mat[16],
             g_dd_big);
    for (unsigned i = 0; i < g_dd_big && i < 6u; ++i) {
      const DdBig& b = g_dd_samples[i];
      DbgPrint("DRAW big f=%u mat=%u path=%u n=%u (%d,%d) (%d,%d) (%d,%d) (%d,%d)\n", frame, b.mat, b.path, b.count,
               int(b.xy[0]), int(b.xy[1]), int(b.xy[2]), int(b.xy[3]), int(b.xy[4]), int(b.xy[5]), int(b.xy[6]), int(b.xy[7]));
    }
  }
  __builtin_memset(g_dd_mat, 0, sizeof(g_dd_mat));
  g_dd_big = 0;
}
#endif
#ifdef CC_DRAW_DUMP
// Draw dump (make DRAWDUMP=1): holding LT+RT starts a dump of every draw of
// the next 70 frames to D:\drawdump.txt, one line per draw: frame, index,
// path (q = quad batch entry, d = cc_xr_draw), material, blend word, texture
// key / size / gpu address, vertex count, bounding box of the positions and
// the first vertex's uv and colour.
bool cc_xbox_triggers_held();
std::FILE* g_dump = nullptr;
unsigned g_dump_frames = 0, g_dump_frame = 0, g_dump_index = 0;
bool g_dump_was_held = false;
// (nxdk's printf has no %f: positions are whole pixels, uv and colour in
// thousandths.) hash: a sample of the texture's pixels (every 61st word).
int dump_i(float f) { return f != f ? -999999 : f > 1e6f ? 999999 : f < -1e6f ? -999999 : int(f); }
void dump_draw(char path, uint32_t blend, uint32_t n, const GpuVertex* v) {
  if (!g_dump) return;
  uint32_t hash = 2166136261u;
  if (g_have_tex && g_cur.gpu) {
    const uint32_t* w = static_cast<const uint32_t*>(g_cur.gpu);
    const uint32_t words = g_cur.w * g_cur.h / 4u;  // DXT5: one byte per pixel
    for (uint32_t i = 0; i < words; i += 61u) hash = (hash ^ w[i]) * 16777619u;
  }
  std::fprintf(g_dump, "%u %u %c m%u b%08x tex %08x %ux%u g%08x h%08x n%u", g_dump_frame, g_dump_index++, path,
               unsigned(g_material), unsigned(blend), g_have_tex ? unsigned(g_cur.key) : 0u, g_have_tex ? unsigned(g_cur.w) : 0u,
               g_have_tex ? unsigned(g_cur.h) : 0u, unsigned(reinterpret_cast<uintptr_t>(g_have_tex ? g_cur.gpu : nullptr)),
               unsigned(hash), unsigned(n));
  for (uint32_t i = 0; i < n && i < 4u; ++i)
    std::fprintf(g_dump, " (%d,%d uv%d,%d)", dump_i(v[i].pos[0]), dump_i(v[i].pos[1]), dump_i(v[i].uv[0] * 1000.0f),
                 dump_i(v[i].uv[1] * 1000.0f));
  std::fprintf(g_dump, " a%d\n", dump_i(v[0].col[3] * 1000.0f));
}
// Armed by the runtime when the game opens a given file (quoff.pak):
// the dump starts that many frames later.
int g_dump_arm = -1;
void cc_xr_dump_arm(int frames) { if (g_dump_arm < 0) g_dump_arm = frames; }
void dump_frame_end() {
  const bool held = cc_xbox_triggers_held();
  const bool armed = g_dump_arm == 0;
  if (g_dump_arm > 0) --g_dump_arm;
  if (armed) g_dump_arm = -2;  // once
  if (((held && !g_dump_was_held) || armed) && !g_dump) {
    g_dump = std::fopen("D:\\drawdump.txt", "w");
    g_dump_frames = 0;
    DbgPrint("DRAWDUMP start %s\n", g_dump ? "D:\\drawdump.txt" : "(cannot open)");
  } else if (g_dump && ++g_dump_frames >= 240u) {
    std::fclose(g_dump);
    g_dump = nullptr;
    DbgPrint("DRAWDUMP done\n");
  }
  g_dump_was_held = held;
  ++g_dump_frame;
  g_dump_index = 0;
}
#endif
#ifdef CC_REPLAY_QUAFF
#include "replay_quaff.inl"
bool g_replaying = false;
void cc_xr_quad(const uint32_t* v, uint32_t blend);
// Replays list A or B (alternating each second): per draw a plain 4x4 white
// texture standing in for the recorded one (a texture change wherever the
// recorded key changes, so batches split as in the game) and one colour per
// draw index.
void replay_quaff() {
  const bool a = ((g_frames / 30u) & 1u) != 0u;
  const ReplayDraw* d = a ? kReplayA : kReplayB;
  const unsigned n = a ? sizeof(kReplayA) / sizeof(kReplayA[0]) : sizeof(kReplayB) / sizeof(kReplayB[0]);
  g_replaying = true;
  uint32_t last_key = 0;
  for (unsigned i = 0; i < n; ++i) {
    if (d[i].key != last_key) {
      flush_batch();
      // One DXT5 texture per recorded key, of the recorded size, filled
      // with a solid colour of its own (as the game's textures, distinct
      // addresses and formats, so the texture state changes as in the game).
      static struct { uint32_t key; void* gpu; } tex[16];
      static unsigned ntex = 0;
      void* gpu = nullptr;
      for (unsigned t = 0; t < ntex; ++t) if (tex[t].key == d[i].key) gpu = tex[t].gpu;
      if (!gpu && ntex < 16u) {
        gpu = MmAllocateContiguousMemoryEx(d[i].w * d[i].h, 0, kMaxGpuAddress, 4096, PAGE_READWRITE | PAGE_WRITECOMBINE);
        static const uint16_t kRgb565[8] = {0xF800u, 0x07E0u, 0x001Fu, 0xFFE0u, 0xF81Fu, 0x07FFu, 0x8410u, 0xFC00u};
        const uint16_t c = kRgb565[ntex & 7u];
        uint8_t blk[16] = {0xFF, 0xFF, 0, 0, 0, 0, 0, 0, uint8_t(c), uint8_t(c >> 8), uint8_t(c), uint8_t(c >> 8), 0, 0, 0, 0};
        uint8_t* q = static_cast<uint8_t*>(gpu);
        if (q) for (uint32_t o = 0; o < d[i].w * d[i].h; o += 16) std::memcpy(q + o, blk, 16);
        tex[ntex].key = d[i].key; tex[ntex].gpu = gpu; ++ntex;
        DbgPrint("REPLAY texture %08x %ux%u colour %u at %08x\n", unsigned(d[i].key), unsigned(d[i].w), unsigned(d[i].h), ntex - 1u, unsigned(reinterpret_cast<uintptr_t>(gpu)));
      }
      g_cur = Texture();
      g_cur.key = d[i].key; g_cur.w = d[i].w; g_cur.h = d[i].h; g_cur.gpu = gpu; g_cur.normalized = true;
      g_cur.format = 0x0000002Au | (NV097_SET_TEXTURE_FORMAT_COLOR_L_DXT45_A8R8G8B8 << 8) |
                     (1u << 16) | (log2u(d[i].w) << 20) | (log2u(d[i].h) << 24);
      g_have_tex = gpu != nullptr;
      last_key = d[i].key;
    }
    static const uint32_t kColours[8] = {0xFFFF4040u, 0xFF40FF40u, 0xFF4040FFu, 0xFFFFFF40u,
                                         0xFFFF40FFu, 0xFF40FFFFu, 0xFFFFFFFFu, 0xFF808080u};
    uint32_t q[24];
    for (unsigned k = 0; k < 4; ++k) {
      const float x = float(d[i].v[k][0]), y = float(d[i].v[k][1]), u = float(d[i].v[k][2]) / 1000.0f, w = float(d[i].v[k][3]) / 1000.0f;
      std::memcpy(&q[k * 6 + 0], &x, 4); std::memcpy(&q[k * 6 + 1], &y, 4); q[k * 6 + 2] = 0u;
      std::memcpy(&q[k * 6 + 3], &u, 4); std::memcpy(&q[k * 6 + 4], &w, 4); q[k * 6 + 5] = 0xFFFFFFFFu; (void)kColours;
    }
    cc_xr_quad(q, d[i].blend);
  }
  flush_batch();
  g_replaying = false;
  if (a) pb_fill_quad(600, 440, 30, 30, 0xFFFF0000);  // marker: list A frames show a red square
  flush_overlay();
}
#endif
void cc_xr_draw(uint32_t prim, uint32_t count, const void* vertices, uint32_t stride, uint32_t blend) {
#ifdef CC_REPLAY_QUAFF
  if (!g_replaying) return;
#endif
  if (!init() || !vertices || stride < 24 || !count) return;
  struct Tally { uint64_t t0; ~Tally() { g_draw_cycles += cycles() - t0; } } tally{cycles()};
  uint32_t op;
  if (prim == 13) op = NV097_SET_BEGIN_END_OP_QUADS;
  else if (prim == 4) op = NV097_SET_BEGIN_END_OP_TRIANGLES;
  else if (prim == 5) op = NV097_SET_BEGIN_END_OP_TRIANGLE_STRIP;
  else return;
  flush_batch();
  if (!g_in_frame) begin_frame();
  if (g_vb_used + count > kMaxVertices) return;
  const uint8_t* v = static_cast<const uint8_t*>(vertices);
  const float su = g_have_tex && !g_cur.normalized ? float(g_cur.w) : 1.0f;
  const float sv = g_have_tex && !g_cur.normalized ? float(g_cur.h) : 1.0f;
  GpuVertex* out = g_vb + g_vb_used;
#ifdef CC_COLOUR20_BUILD
  const uint32_t at = 20u;  // bisect build: colour read at +20 for every stride (before the fix)
#else
  const uint32_t at = stride >= 32u ? 28u : 20u;  // colour
#endif
  for (uint32_t i = 0; i < count; ++i, v += stride)
    put_vertex(out[i], bef(v), bef(v + 4), bef(v + 12), bef(v + 16), be32(v + at), su, sv);
#ifdef CC_DRAW_DUMP
  dump_draw('d', blend, count, out);
#endif
#ifdef CC_DRAW_DIAG
  {
    float xy[8];
    const unsigned n = count < 4u ? count : 4u;
    for (unsigned i = 0; i < n; ++i) { xy[2 * i] = out[i].pos[0]; xy[2 * i + 1] = out[i].pos[1]; }
    dd_note(1u, count, xy, n);
  }
#endif
  emit_draw(op, g_vb_used, count, blend);
  g_vb_used += count;
}

// One quad from the native sprite path: four game vertices {x, y, z, u, v,
// argb} as host-order words (the float bit patterns the game would have
// written to its vertex ring), drawn like cc_xr_draw(13, 4, ...) with the
// same blend word, through the open batch.
void cc_xr_quad(const uint32_t* v, uint32_t blend) {
#ifdef CC_REPLAY_QUAFF
  if (!g_replaying) return;
#endif
  if (!init()) return;
  struct Tally { uint64_t t0; ~Tally() { g_draw_cycles += cycles() - t0; } } tally{cycles()};
  if (g_batch_n && ((blend ^ g_batch_blend) & 0x1F1Fu)) flush_batch();
  if (!g_in_frame) begin_frame();
  if (g_vb_used + 4 > kMaxVertices) return;
  if (!g_batch_n) { g_batch_first = g_vb_used; g_batch_blend = blend; }
  const float su = g_have_tex && !g_cur.normalized ? float(g_cur.w) : 1.0f;
  const float sv = g_have_tex && !g_cur.normalized ? float(g_cur.h) : 1.0f;
  auto f = [](uint32_t b) { float x; std::memcpy(&x, &b, 4); return x; };
  GpuVertex* out = g_vb + g_vb_used;
  for (uint32_t i = 0; i < 4; ++i, v += 6) put_vertex(out[i], f(v[0]), f(v[1]), f(v[3]), f(v[4]), v[5], su, sv);
#ifdef CC_DRAW_DUMP
  dump_draw('q', blend, 4u, out);
#endif
#ifdef CC_DRAW_DIAG
  {
    float xy[8];
    for (unsigned i = 0; i < 4; ++i) { xy[2 * i] = out[i].pos[0]; xy[2 * i + 1] = out[i].pos[1]; }
    dd_note(0u, 4u, xy, 4u);
  }
#endif
  g_vb_used += 4;
  g_batch_n += 4;
}

// Wait for the GPU to finish everything queued so far (called before a
// texture still referenced by this frame's draws is evicted and its zone
// block reused).
// Waits until the GPU has finished everything queued, including the
// previous frame's draws between frames (the frame end does not wait for
// the GPU), so texture memory those draws sample can be reused. Returning
// early between frames let a texture evicted before the next frame's first
// draw be overwritten while the GPU still drew the last frame with it (the
// book menu's one-frame wrong pictures).
void cc_xr_gpu_idle() {
  const uint64_t w0 = now_us();
  if (g_in_frame) flush_batch();
  xr_flush();
  gpu_wait_idle();
  const uint64_t w = now_us() - w0;
  g_frame_tex_wait_us += w; ++g_frame_tex_waits;
  g_tex_wait_us += w; ++g_tex_waits;
}
// The GPU's idle epoch (see gpu_wait_idle).
uint32_t cc_xr_gpu_epoch() { return g_gpu_epoch; }
// The material of the draws that follow (see g_material): an open quad
// batch is drawn with the one it was built under first.
void cc_xr_set_material(uint32_t material) {
  if (material == g_material) return;
  flush_batch();
  g_material = material;
}
// A new mask: its shape and the children it clips use the next stencil
// value (the stencil is cleared again when 255 masks have been drawn).
void cc_xr_mask_begin() {
  flush_batch();
  if (++g_mask_id > 255u) {
    xr_flush();
    pb_erase_depth_stencil_buffer(0, 0, 640, 480);
    g_mask_id = 1;
  }
}

// Harness failure on the Xbox: show the error code and guest address as
// digits (the debug text console is hidden behind the pbkit display) and
// present that frame, so a stopped game reports why on screen.
void cc_xr_show_fail_where(uint32_t code, uint32_t addr, const uint32_t* where, unsigned n);
void cc_xr_show_fail(uint32_t code, uint32_t addr) { cc_xr_show_fail_where(code, addr, nullptr, 0); }
// Also `where`: up to four console code addresses (the faulting instruction
// and return addresses found on the stack), one 8-digit row each under the
// bar, to be looked up in the build's main.map.
void cc_xr_show_fail_where(uint32_t code, uint32_t addr, const uint32_t* where, unsigned n) {
  DbgPrint("FAIL code=%u addr=%08x\n", unsigned(code), unsigned(addr));
  for (unsigned i = 0; i < n; ++i) DbgPrint("FAIL where %u: %08x\n", i, unsigned(where[i]));
  if (!init()) return;
  if (!g_in_frame) begin_frame();
  pb_fill_quad(8, 300, 400, 40 + 36 * (n < 4 ? n : 4), 0xFF400000);
  draw_number(16, 310, code, 0xFFFFFFFF);
  for (int k = 0; k < 8; ++k) draw_hex_digit(80 + k * 15, 310, (addr >> (28 - 4 * k)) & 15u, 0xFFFFFF40);
  for (unsigned i = 0; i < n && i < 4; ++i)
    for (int k = 0; k < 8; ++k) draw_hex_digit(80 + k * 15, 346 + 36 * int(i), (where[i] >> (28 - 4 * k)) & 15u, 0xFF80FFFF);
  flush_overlay();
  xr_flush(); gpu_wait_idle();
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
#ifdef CC_REPLAY_QUAFF
  if (init() && !g_in_frame) begin_frame();  // the game draws nothing in replay builds
#endif
  if (!g_in_frame) return;
#ifdef CC_DRAW_DUMP
  dump_frame_end();
#endif
#ifdef CC_DRAW_DIAG
  cc_draw_diag_frame();
#endif
  // On-screen counters, averaged over each second of real time. Top row:
  // frames per second, ms per frame, audio buffers mixed/s, silent/s.
  // Bottom row, ms per frame: game update, game render (includes the
  // draw hand-off), draw hand-off to the GPU, waiting for the GPU.
  static DWORD window_start = 0;
  static unsigned window_frames = 0, shown_fps = 0, shown_ms = 0;
  static uint64_t sum_update = 0, sum_render = 0, sum_draw = 0, sum_wait = 0, last_wait = 0;
  static unsigned shown_update = 0, shown_render = 0, shown_draw = 0, shown_wait = 0;
  sum_update += update_us; sum_render += render_us; sum_draw += draw_cycles_to_us(g_draw_cycles); sum_wait += last_wait;
  g_draw_cycles = 0;
  // Longest frame of the window (frame end to frame end: the previous
  // present, then this frame's update and render) and where its time went.
  static uint64_t last_end_us = 0, max_frame_us = 0;
  // update, render, begin wait, texture waits (time, count), vblank wait,
  // queue wait, other, texture pack reads, their disk time, the game's file
  // reads, their bytes and time
  static uint64_t slow[13];
  {
    const uint64_t t = now_us();
    void cc_xbox_io_totals(uint32_t* bake_reads, uint32_t* disk_us, uint32_t* game_reads, uint32_t* game_bytes,
                           uint32_t* game_us);
    static uint32_t last_reads = 0, last_disk = 0, last_gr = 0, last_gb = 0, last_gu = 0;
    uint32_t reads = 0, disk = 0, gr = 0, gb = 0, gu = 0;
    cc_xbox_io_totals(&reads, &disk, &gr, &gb, &gu);
    if (last_end_us && t - last_end_us > max_frame_us) {
      slow[8] = reads - last_reads; slow[9] = disk - last_disk;
      slow[10] = gr - last_gr; slow[11] = gb - last_gb; slow[12] = gu - last_gu;
      max_frame_us = t - last_end_us;
      const uint64_t known = uint64_t(update_us) + render_us + g_present_vbl_us + g_present_queue_us;
      slow[0] = update_us; slow[1] = render_us; slow[2] = g_frame_begin_wait_us; slow[3] = g_frame_tex_wait_us;
      slow[4] = g_frame_tex_waits; slow[5] = g_present_vbl_us; slow[6] = g_present_queue_us;
      slow[7] = max_frame_us > known ? max_frame_us - known : 0;
    }
    last_end_us = t;
    last_reads = reads; last_disk = disk; last_gr = gr; last_gb = gb; last_gu = gu;
    g_frame_begin_wait_us = g_frame_tex_wait_us = 0;
    g_frame_tex_waits = 0;
  }
  const DWORD now = GetTickCount();
  if (!window_start) window_start = now;
  ++window_frames;
  if (now - window_start >= 1000) {
    // The same window on the debug channel (XBDM debug strings, read on the
    // PC by tools/xbox_console.py): times in 0.1 ms.
    {
      // dbg: how long the previous second's debug lines took to send (they
      // go out over the debug monitor's network channel), in 0.1 ms.
      static uint64_t dbg_us = 0;
      const uint64_t d0 = now_us();
      const unsigned el = now - window_start;
      // und: audio queue run-dry checks in the second (each replays stale
      // buffers: an audible stutter).
      unsigned ast = 0, afed = 0, acb = 0, aur = 0, adr = 0;
      cc_xbox_audio_stats(&ast, &afed, &acb, &aur, &adr);
      static unsigned last_ur = 0, last_ms = 0, last_gpi = 0, last_gpb = 0;
      // mst: music blocks that reached the mixer late (runtime021/music_stream.inc).
      uint32_t cc_audio_music_starved();
      const unsigned ms_now = cc_audio_music_starved();
      // sfl / sfx: sound effects read from disk at play time this second and
      // the longest read (0.1 ms; that sound started that much late).
      void cc_audio_sfx_reads(uint32_t* reads, uint32_t* max_us);
      uint32_t sfl = 0, sfx_us = 0;
      cc_audio_sfx_reads(&sfl, &sfx_us);
      DbgPrint("PERF t=%u fps=%u ms=%u max=%u upd=%u ren=%u draw=%u wait=%u dbg=%u und=%u mst=%u gpi=%u gpb=%u sfl=%u sfx=%u\n", unsigned(now), window_frames * 1000u / el,
               el * 10u / window_frames, unsigned(max_frame_us / 100u), unsigned(sum_update / window_frames / 100u),
               unsigned(sum_render / window_frames / 100u), unsigned(sum_draw / window_frames / 100u),
               unsigned(sum_wait / window_frames / 100u), unsigned(dbg_us / 100u), aur - last_ur, ms_now - last_ms,
               g_gpu_premature - last_gpi, g_gpu_busy_at_begin - last_gpb, sfl, sfx_us / 100u);
      // SLOW: the second's longest frame split up, 0.1 ms: u update, r render
      // (includes b and t), b begin_frame's GPU wait, t texture evictions'
      // GPU waits (n of them), v present's vertical-blank wait, q present's
      // wait for a free framebuffer, o the rest, pk textures read from the
      // pack in that frame and pkt their disk time, gr / gk / grt the game's
      // own file reads in that frame, their KiB and time. tw / twt:
      // texture-eviction GPU waits in the second and their total time.
      static unsigned last_onscr = 0;
      DbgPrint("ONSCR t=%u n=%u\n", unsigned(now), g_draw_on_screen - last_onscr);
      last_onscr = g_draw_on_screen;
      DbgPrint("SLOW t=%u u=%u r=%u b=%u t=%u n=%u v=%u q=%u o=%u pk=%u pkt=%u gr=%u gk=%u grt=%u tw=%u twt=%u\n",
               unsigned(now), unsigned(slow[0] / 100u), unsigned(slow[1] / 100u), unsigned(slow[2] / 100u),
               unsigned(slow[3] / 100u), unsigned(slow[4]), unsigned(slow[5] / 100u), unsigned(slow[6] / 100u),
               unsigned(slow[7] / 100u), unsigned(slow[8]), unsigned(slow[9] / 100u), unsigned(slow[10]),
               unsigned(slow[11] >> 10), unsigned(slow[12] / 100u), g_tex_waits, unsigned(g_tex_wait_us / 100u));
      g_tex_waits = 0; g_tex_wait_us = 0;
      last_gpi = g_gpu_premature;
      last_gpb = g_gpu_busy_at_begin;
      last_ur = aur;
      last_ms = ms_now;
      max_frame_us = 0;
      { void cc_xbox_perf_second(unsigned frames); cc_xbox_perf_second(window_frames); }  // xbox_perf.cpp
      dbg_us = now_us() - d0;
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
  // On-screen numbers (make OVERLAY=1; always in BENCH and profiler
  // builds): drawn as seven-segment digits with a few fills each (pbkit's
  // text overlay issues ~1,000 fills a frame and slows the game down). The
  // play build shows none; the same figures go out on the debug channel
  // (PERF lines).
#if defined(CC_OVERLAY) || defined(CC_BENCH) || defined(CC_XBOX_PROFILE)
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
#endif
  // The frame's last open sprite batch (often the text drawn on top, such
  // as the menu's button labels); the overlay used to flush it as a side
  // effect, so without the overlay those labels were never drawn.
  flush_batch();
#ifdef CC_DRAW_DUMP
  if (g_dump) {  // the dump's frame number, bottom left, so a screenshot names its frame
    pb_fill_quad(8, 440, 90, 30, 0xFF000000);
    draw_number(12, 445, g_dump_frame, 0xFFFFFFFF);
    flush_overlay();
  }
#endif
#ifdef CC_REPLAY_QUAFF
  replay_quaff();
#endif

  const uint64_t w0 = now_us();
  // No wait for the GPU here: the flip is queued behind this frame's draws,
  // and the next frame's begin_frame (pb_reset jumps the push buffer back
  // to its head and waits for the GPU to get there) is the first point that
  // reuses push-buffer, vertex or texture memory the GPU may still read. So
  // the game's next update runs while the GPU draws this frame (the wait
  // here was ~15% of the CPU in the four-player marsh fight). XRSERIAL=1
  // waits here as before.
#ifdef CC_XR_SERIAL
  xr_flush(); gpu_wait_idle();
#else
  xr_flush();
#endif
  present();
  last_wait = now_us() - w0;
  if (!g_shown) { pb_show_front_screen(); g_shown = true; }
  g_in_frame = false;
  ++g_frames;
}
