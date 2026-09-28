// SPDX-License-Identifier: MIT (adapter; includes are unchanged user-game code)
#include "../runtime008/bridge.h"
#include <climits>
#include <array>
#include <algorithm>
#include <cmath>
#include <csetjmp>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#ifdef CC_XBOX_DRIVER
#include <nxdk/mount.h>
#endif
#ifdef CC_XBOX_DRIVER
// nxdk-checkpoint022/xbox_audio.cpp: AC97 output for the port mixer.
void cc_xbox_audio_submit(const int16_t* frame, int samples);
void cc_xbox_audio_stats(unsigned* started, unsigned* submitted, unsigned* callbacks,
                         unsigned* underruns, unsigned* dropped);
// nxdk-checkpoint022/xbox_render.cpp: NV2A renderer for the game's draw calls.
void cc_xr_bind(uint32_t key, const void* data, uint32_t w, uint32_t h, int kind);
void cc_xr_draw(uint32_t prim, uint32_t count, const void* vertices, uint32_t stride, uint32_t blend);
void cc_xr_frame_end();
#endif
#include <map>
#include <set>
#include "cc_log.h"
#ifndef CC_XBOX_DRIVER
#include <atomic>
#include <unordered_map>
#include <chrono>
#include <thread>
// Host sampling profiler (CC_SAMPLE=1): a background thread records which
// generated function was most recently entered, once per millisecond, and
// prints the top entries at exit. Approximate self time at function-entry
// granularity; port-side work shows up under the guest function that called it.
static std::atomic<const char*> g_sample_fn{nullptr};
namespace {
struct CcSampler {
  std::atomic<bool> stop{false};
  std::thread worker;
  std::unordered_map<const char*, unsigned> counts;
  unsigned total = 0;
  CcSampler() {
    if (!std::getenv("CC_SAMPLE")) return;
    worker = std::thread([this] {
      while (!stop.load()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        if (const char* f = g_sample_fn.load(std::memory_order_relaxed)) { ++counts[f]; ++total; }
      }
    });
  }
  ~CcSampler() {
    if (!worker.joinable()) return;
    stop = true;
    worker.join();
    std::vector<std::pair<unsigned, const char*>> v;
    for (const auto& [f, c] : counts) v.push_back({c, f});
    std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) { return a.first > b.first; });
    std::fprintf(stderr, "SAMPLE total=%u\n", total);
    for (size_t i = 0; i < v.size() && i < 30; ++i)
      std::fprintf(stderr, "SAMPLE %5.1f%% %s\n", 100.0 * v[i].first / (total ? total : 1), v[i].second);
  }
};
CcSampler g_sampler;
}  // namespace
#endif
#include <string>
#include <vector>
namespace cc::tree {
// WIP 021 bounded shader-file platform contract: host directory holding the
// files extracted from the retail container (set by the test harness; the
// contract fails closed when unset).
// Fixed buffer (no libc++ heap string) so the identical runtime links on
// the original-Xbox target against nxdk without extern string templates.
static char g_game_root[260] = {0};
void set_game_root(const char* p) noexcept {
  unsigned i = 0;
  if (p) for (; i + 1 < sizeof(g_game_root) && p[i]; ++i) g_game_root[i] = p[i];
  g_game_root[i] = 0;
}
// WIP 021 persistent kernel-fixture state. Unlike per-invoke Machine state,
// these model kernel-side facts that survive between diagnostic invocations
// exactly as they would across calls on hardware: TLS slot values, critical
// sections created by exact code, and the virtual-memory cursor backing the
// exact CRT heap's reservations.
static uint32_t g_tls_slots[64]{};
// Statically allocated critical sections in the sealed image's data segment
// (initialized by XAPI process startup on hardware, not by any code on the
// recovered path): the notification-listener lock used by exact
// sub_820D84A8. Registered up front like a loader fixture.
static uint32_t g_registered_cs[64] = { 0x82151A6Cu, 0x82235A5Cu };
static bool g_registered_cs_locked[64] = { false, false };
static uint32_t g_registered_cs_count = 2;
[[maybe_unused]] static uint32_t g_valloc_cursor = 0x04000000u;
// Raised-IRQL balance flag for the single-threaded spinlock model.
static uint32_t g_irql_level = 0; // 0=PASSIVE, 2=DISPATCH
// One-shot XAudio render-driver client registration.
static bool g_xaudio_client_registered = false;
// Bounded semaphore-token registry for the exact event wrappers.
static uint32_t g_semaphore_count = 0;
static uint32_t g_semaphore_value[8] = {};
static uint32_t g_semaphore_limit[8] = {};
static uint64_t g_tls_allocated = 0;  // bitmap over the 64 fixture TLS slots
// WIP 023: first-fit allocator over the physical cursor arena. Freed
// ranges are kept sorted by address and merged with their neighbours; a
// range touching the cursor gives its space back to the cursor. Live and
// peak byte counts show the game's real physical-memory footprint.
struct PhysRange { uint32_t addr, size; };
static std::vector<PhysRange> g_phys_free_ranges;  // sorted by addr
static std::vector<PhysRange> g_phys_live_blocks;
// Textures the port stored DXT5-compressed (see cc_compress_texture_dxt5).
// data: the game's texture pointer (identity; the game's own block is cut
// to 16 bytes), cache: guest address of the DXT5 pixels or 0 when evicted,
// job: snapshot of the rasterizer job that regenerates the pixels.
struct CcDxtTexture {
  uint32_t data = 0, w = 0, h = 0, cache = 0, last_use = 0, hash = 0;
  bool hashed = false;  // hash holds the first compression's hash
  int64_t swap_off = -1;  // copy of the DXT5 pixels in the scratch swap file
  std::vector<uint8_t> job;
};
static std::vector<CcDxtTexture> g_dxt_textures;
// data pointer -> index into g_dxt_textures (textures are looked up on every
// bind, ~250 times a frame, among ~2,800 entries). Open addressing with
// linear probing; the nxdk C++ runtime has no std::unordered_map support.
struct CcDxtIndex {
  static constexpr uint32_t kEmpty = 0u, kGone = 1u;  // texture pointers are never 0 or 1
  std::vector<uint32_t> keys, values;
  uint32_t used = 0;  // live + tombstones
  static uint32_t hash(uint32_t k) { return (k >> 4) * 2654435761u; }
  void rebuild(uint32_t capacity, const std::vector<CcDxtTexture>& live) {
    keys.assign(capacity, kEmpty);
    values.assign(capacity, 0u);
    used = 0;
    for (uint32_t i = 0; i < live.size(); ++i) set(live[i].data, i);
  }
  void set(uint32_t k, uint32_t v) {
    const uint32_t mask = uint32_t(keys.size()) - 1u;
    for (uint32_t i = hash(k) & mask;; i = (i + 1u) & mask) {
      if (keys[i] == k) { values[i] = v; return; }
      if (keys[i] == kEmpty || keys[i] == kGone) {
        if (keys[i] == kEmpty) ++used;
        keys[i] = k; values[i] = v; return;
      }
    }
  }
  int64_t get(uint32_t k) const {
    if (keys.empty()) return -1;
    const uint32_t mask = uint32_t(keys.size()) - 1u;
    for (uint32_t i = hash(k) & mask;; i = (i + 1u) & mask) {
      if (keys[i] == k) return values[i];
      if (keys[i] == kEmpty) return -1;
    }
  }
  void remove(uint32_t k) {
    const uint32_t mask = uint32_t(keys.size()) - 1u;
    for (uint32_t i = hash(k) & mask;; i = (i + 1u) & mask) {
      if (keys[i] == k) { keys[i] = kGone; return; }
      if (keys[i] == kEmpty) return;
    }
  }
};
static CcDxtIndex g_dxt_index;
[[maybe_unused]] static CcDxtTexture* cc_dxt_lookup(uint32_t data) {
  const int64_t i = g_dxt_index.get(data);
  return i < 0 ? nullptr : &g_dxt_textures[size_t(i)];
}
[[maybe_unused]] static void cc_dxt_add(CcDxtTexture&& t) {
  g_dxt_textures.push_back(std::move(t));
  if ((g_dxt_index.used + 1u) * 2u > g_dxt_index.keys.size()) {
    uint32_t cap = 8192u;
    while (cap < g_dxt_textures.size() * 4u) cap *= 2u;
    g_dxt_index.rebuild(cap, g_dxt_textures);
  } else {
    g_dxt_index.set(g_dxt_textures.back().data, uint32_t(g_dxt_textures.size() - 1u));
  }
}
// Remove by swapping the last entry into its place.
[[maybe_unused]] static void cc_dxt_erase(uint32_t data) {
  const int64_t found = g_dxt_index.get(data);
  if (found < 0) return;
  const uint32_t k = uint32_t(found);
  g_dxt_index.remove(data);
  if (k + 1u != g_dxt_textures.size()) {
    g_dxt_textures[k] = std::move(g_dxt_textures.back());
    g_dxt_index.set(g_dxt_textures[k].data, k);
  }
  g_dxt_textures.pop_back();
}
static std::vector<CcDxtTexture> g_pending_textures;  // allocated, not yet rasterized
[[maybe_unused]] static const CcDxtTexture* cc_find_dxt_texture(uint32_t data) {
  return cc_dxt_lookup(data);
}
// Guest return address of the allocation currently being served (set by the
// allocator shims just before cc_phys_alloc), and, host only, each live
// block's owner for the CC_MEM_REPORT breakdown.
static uint32_t g_phys_tag = 0;
#ifndef CC_XBOX_DRIVER
static std::map<uint32_t, uint32_t> g_phys_owner;
static std::map<uint32_t, uint64_t> g_phys_owner2;
static uint32_t g_phys_tag2 = 0, g_phys_tag3 = 0;
static std::map<uint32_t, uint32_t> g_bound_textures; // data -> w|h<<16
static std::map<uint32_t, uint32_t> g_tex_last_bound; // data -> last frame bound
#endif
static uint64_t g_phys_live_bytes = 0, g_phys_peak_bytes = 0;
// One-shot XAM notification listener.
static bool g_xam_listener_created = false;
static uint32_t g_xam_listener_count = 0;
// The physical graphics allocator is one durable kernel-side allocator: its
// sequence position and cursor survive between diagnostic invocations exactly
// as physical allocations do on hardware.
static uint32_t g_graphics_alloc_index = 0;
static uint32_t g_graphics_alloc_cursor = 0x02000000u;
// The title's single observed 16 MiB main-pool physical allocation.
static bool g_main_pool_allocated = false;
// Cursor for the smaller observed physical blocks (font/texture memory).
static uint32_t g_phys_cursor = 0x12000000u;
#include "../runtime007/float_scope.inc"
struct Machine;
static void (*g_drain_workers)(Machine&, uint32_t) = nullptr;
// WIP 023: the frame loop executes exact sub_820A89F8 for texture binds;
// the earlier widget checkpoints keep their modeled sink case.
static bool g_use_exact_texture_bind = false;
// Host-only frame capture (CC_CAPTURE_FRAMES / CC_CAPTURE_DIR), defined
// after Machine. Read-only: uses raw address-space reads, never counted.
static void cc_capture_on_function(const char* name, const Context& ctx,
                                   cc::xbox::AddressSpace& mem);
static void cc_capture_end_frame(cc::xbox::AddressSpace& mem, uint32_t frame);
void set_exact_texture_bind(bool v) noexcept { g_use_exact_texture_bind = v; }
struct Machine {
  struct ThreadSlot {
    bool allocated{};
    bool suspended{};
    bool runnable{};
    uint32_t handle{};
    uint32_t object{};
    uint32_t startup_thunk{};
    uint32_t start_routine{};
    uint32_t parameter{};
    int32_t priority{};
    uint32_t affinity{0x3fu};
  };
  AddressSpace &memory;
  Sink sink;
  Result result{};
  std::array<ThreadSlot,32> threads{};
  uint32_t thread_count{};
  // Checkpoint 020's graphics allocator is a deliberately tiny platform/runtime
  // contract. It accepts only the fifteen allocation shapes reached by the sealed
  // 640x480 device-init path; all other sizes/flags fail closed.


  bool graphics_engines_initialized{};
  uint32_t terminate_notifications{};
  bool graphics_interrupt_installed{};
  bool system_identifier_cleared{};
  bool ring_initialized{};
  bool ring_writeback_enabled{};
  bool system_identifier_set{};
  bool video_mode_queried{};
  bool video_flags_queried{};
  uint32_t graphics_last_alloc_size{};
  uint32_t graphics_last_alloc_flags{};
  uint32_t tile_allocator{};
  bool tile_cs_locked{};
  bool hsio_cs_locked{};
  uint32_t critical_region_depth{};
  uint32_t edram_worker_calls{};
  uint32_t edram_retrain_calls{};
  bool edram_suffix021_shape{};
  bool edram_frame022_shape{};
  uint32_t hsio_status_calls{};
  uint32_t tile_next{};
  bool graphics_notification_sent{};
  bool display_gamma_queried{};
  bool system_command_buffer_queried{};
  bool vd_swap_called{};
  bool display_mode_set{};
  bool display_info_queried{};
  bool scaler_command_buffer_initialized{};
  bool persist_display_called{};
  bool persist_display_freed{};
  uint32_t persist_display_allocation{};
  // WIP 021 shader-file fixture: exactly one file open at a time, read-only,
  // backed by the extracted container bytes. All other shapes fail closed.
  // WIP 023: the frame loop keeps several files open at once (a streamed
  // XMA sound bank stays open across pak opens), so the single-file
  // fixture became a bounded 8-slot handle table.
  // Open game files are read from disk on demand (the original Xbox cannot
  // afford whole-file copies next to the game's own buffers).
  struct FileSlot { bool open{}; uint32_t handle{}; uint32_t pos{}; uint32_t size{}; std::FILE* fp{}; };
  std::array<FileSlot,8> files{};
  FileSlot* find_file(uint32_t h) {
    for (auto &f : files) if (f.open && f.handle==h) return &f;
    return nullptr;
  }
  unsigned open_files() const {
    unsigned n=0; for (auto &f : files) if (f.open) ++n; return n;
  }
  uint32_t ring_virtual{};
  uint32_t ring_physical{};
  uint32_t ring_descriptor{};
  uint32_t graphics_allocate(uint32_t size, uint32_t flags) {
    static constexpr uint32_t sizes[] = {24192u, 4800u, 32768u, 2097152u, 96u, 32u,
                                         672u, 512u, 200u, 8192u, 52u, 0x12C000u, 48u, 804u, 48u};
    static constexpr uint32_t flagv[] = {0x24800000u, 0xB5800000u, 0xB5800000u,
                                         0x87800000u, 0xA5800000u, 0x95800000u,
                                         0xB5800000u, 0x64800000u, 0xB5800000u, 0xB5800000u, 0x64800000u, 0xBC800000u, 0x64800000u, 0x64800000u, 0x64800000u};
    graphics_last_alloc_size=size; graphics_last_alloc_flags=flags;
    if (g_graphics_alloc_index >= 15u) {
      // WIP 021 shader-creation phase: after the fifteen sealed device-init
      // shapes, exact sub_820C0440/sub_820C0330/sub_820C01C0 allocate shader
      // and declaration objects (flag 0x24800000) and their physical
      // microcode blocks (flag 0xB5800000) with small sizes derived from the
      // container's shader files, and the Init tail's exact sub_820C44A0
      // creates one more 640x480 resource (52-byte header, flag 0x64800000,
      // plus its 0x12C000-byte backing, flag 0xBC800000). Only those shapes
      // are accepted.
      const bool shader_shape =
          (flags == 0x24800000u || flags == 0xB5800000u) &&
          size >= 16u && size <= 65536u;
      const bool resource_header_shape = flags == 0x64800000u && size == 52u;
      const bool resource_backing_shape =
          flags == 0xBC800000u && size == 0x12C000u;
      // WIP 022: exact sub_8213ACB0 allocates its small notification-
      // listener records (8- and 60-byte shapes observed) with this exact
      // flag word.
      const bool notify_record_shape =
          flags == 0x608A2002u && size >= 8u && size <= 256u;
      // WIP 022: the exact XAudio driver init (sub_820E35E8 family)
      // allocates its mixing/XMA work buffers with this exact flag word.
      // WIP 023: the music streamer also takes small stream records with
      // the same flag words (observed 808 bytes).
      const bool audio_buffer_shape =
          (flags == 0x61820005u || flags == 0x61820006u ||
           flags == 0xA7820007u) &&
          size >= 16u && size <= 0x40000u;
      // WIP 023: any other allocation-attribute shape (the game's general
      // XMemAlloc traffic, dozens of allocator ids) is served by the
      // sub_82136670 shim from the physical arena, which supports free and
      // reuse. Signalled to the shim with an all-ones sentinel.
      if (!shader_shape && !resource_header_shape &&
          !resource_backing_shape && !notify_record_shape &&
          !audio_buffer_shape)
        return 0xFFFFFFFFu;
      const uint32_t p=(g_graphics_alloc_cursor + 15u) & ~15u;
      if (p > 0xffffffffu-size || memory.check(p,size,3) != cc::xbox::MemoryError::ok)
        fail(Error::memory,p);
#ifndef CC_XBOX_DRIVER
      if (std::getenv("CC_GFX_LAYOUT")) cc_log("GFXALLOC late addr=%08x size=%u flags=%08x%c", p, size, flags, 10);
#endif
      g_graphics_alloc_cursor=p+size;
      ++g_graphics_alloc_index;
      return p;
    }
    if (size != sizes[g_graphics_alloc_index] ||
        flags != flagv[g_graphics_alloc_index])
      fail(Error::unsupported, 0x82136670u);
    uint32_t p=(g_graphics_alloc_cursor + 15u) & ~15u;
    if (p > 0xffffffffu-size || memory.check(p,size,3) != cc::xbox::MemoryError::ok)
      fail(Error::memory,p);
#ifndef CC_XBOX_DRIVER
    if (std::getenv("CC_GFX_LAYOUT")) cc_log("GFXALLOC %u addr=%08x size=%u flags=%08x%c", g_graphics_alloc_index, p, size, flags, 10);
#endif
    if (g_graphics_alloc_index == 2u) ring_virtual=p;
    if (g_graphics_alloc_index == 4u) ring_descriptor=p;
    if (g_graphics_alloc_index == 13u) tile_allocator=p;
    g_graphics_alloc_cursor=p+size;
    ++g_graphics_alloc_index;
    return p;
  }
  ThreadSlot* by_handle(uint32_t handle) noexcept {
    for (auto &t: threads) if (t.allocated && t.handle==handle) return &t;
    return nullptr;
  }
  ThreadSlot* by_object(uint32_t object) noexcept {
    for (auto &t: threads) if (t.allocated && t.object==object) return &t;
    return nullptr;
  }
  std::jmp_buf escape{};
  uint32_t budget = 200000, depth = 0;
  uint32_t cp_rb_wptr = 0, cp_rb_wptr_writes = 0;
  const char* last_function = "<none>";
  std::array<const char*,32> recent_functions{};
  std::array<uint32_t,32> recent_r1{};
  uint32_t recent_pos{};
  static constexpr uint64_t timebase_hz = 49875000ull;
  // WIP 023: deterministic virtual timebase. The native Xbox run reproduced
  // the frame loop with funcs identical to the host but one memory op fewer,
  // because raw clock magnitudes differ between platforms and one recovered
  // path stores a value derived from them. The diagnostic timebase therefore
  // advances a fixed 1 ms (49,875 ticks) per guest read, making every
  // time-derived value -" and thus the measured op counts -" identical on the
  // host and on the Xbox target. Real hosts reintroduce a real clock only at
  // the eventual product presentation layer, never in this harness.
  uint64_t timebase_virtual_ticks = 0;
  uint64_t query_timebase() noexcept {
    timebase_virtual_ticks += timebase_hz / 1000ull;  // 1 ms per read
    return timebase_virtual_ticks;
  }
  const Context* last_ctx{};
  bool trace_one_frame = false;
  bool frame_probe_log = false;
  bool drain_active = false;
  const char* prof_names[512] = {};
  uint64_t prof_counts[512] = {};
  void prof_hit(const char* name) {
    for (unsigned i = 0; i < 512; ++i) {
      if (prof_names[i] == name) { ++prof_counts[i]; return; }
      if (!prof_names[i]) { prof_names[i] = name; prof_counts[i] = 1; return; }
    }
  }
  void prof_dump() {
    for (unsigned pass = 0; pass < 12; ++pass) {
      uint64_t best = 0; unsigned bi = 512;
      for (unsigned i = 0; i < 512 && prof_names[i]; ++i)
        if (prof_counts[i] > best) { best = prof_counts[i]; bi = i; }
      if (bi == 512) break;
      cc_elog("PROF %10llu %s\n", (unsigned long long)prof_counts[bi], prof_names[bi]);
      prof_counts[bi] = 0;
    }
  }
  const char* trace_names[256] = {};
  unsigned trace_count = 0;
  // Hook flags per generated function, resolved once from its name and then
  // looked up by the name pointer (each function's __func__ is a distinct
  // static string), so the common case costs one small hash probe instead of
  // a string comparison per hook.
  enum : uint32_t { kHookAny = 1u };
  struct HookSlot { const char* name; uint32_t flags; };
  HookSlot hook_slots[16384] = {};
  uint32_t hook_flags(const char* name) {
    uint32_t h = uint32_t(reinterpret_cast<uintptr_t>(name) >> 3) * 2654435761u;
    for (uint32_t i = 0;; ++i) {
      HookSlot& s = hook_slots[(h + i) & 16383u];
      if (s.name == name) return s.flags;
      if (!s.name) {
        static const char* const hooked[] = {
          "sub_8209CD08", "sub_8209CC98", "sub_8209DE50", "sub_8209DF48", "sub_82091248",
          "sub_820B0F18", "sub_8208A7A0", "sub_820A1BF8", "sub_820FBF50", "sub_82104FD0",
          "sub_820FBF60", "sub_820B6CA0", "sub_820D7E90", "sub_82077CE0", "sub_820915F0",
          "sub_82075C88", "sub_820BE9F0", "sub_820C5E50", "sub_820C5EE8", "sub_820A89F8",
          "sub_820C1980"};
        uint32_t f = 0;
        for (const char* hn : hooked)
          if (!std::strncmp(name, hn, 12)) f = kHookAny;
        s.name = name;
        s.flags = f;
        return f;
      }
    }
  }
  bool prof_enabled = false;
  void prologue(const char *name, const Context& ctx) {
    last_function = name;
#ifndef CC_XBOX_DRIVER
    g_sample_fn.store(name, std::memory_order_relaxed);
#endif
    last_ctx = &ctx;
    recent_functions[recent_pos & 31u] = name;
    recent_r1[recent_pos & 31u] = ctx.r1.u32;
    ++recent_pos;
#ifndef CC_FAST
    if (++result.functions > 500000000u && budget != 0xFFFFFFFFu) capacity_stop();
#endif
    if (prof_enabled) prof_hit(name);
    if (trace_one_frame && trace_count < 2000) {
      ++trace_count;
      cc_elog("FT %s r3=%08x r4=%08x r5=%08x lr=%08x\n",
              name, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, uint32_t(ctx.lr));
    }
    if (!(hook_flags(name) & kHookAny)) return;
    hooked_prologue(name, ctx);
  }
  void capacity_stop() {
    prof_dump();
    uint64_t pend=0,done=0,b=0;
    memory.load_be(0x8228A770u,4,pend); memory.load_be(0x8228A764u,4,done);
    char busy[6]{};
    for (unsigned i=0;i<5;++i){ memory.load_be(0x8228A768u+i,1,b); busy[i]=char('0'+(b&1)); }
    cc_elog("WORKERSTATE pend=%08x done=%08x busy=%s\n",uint32_t(pend),uint32_t(done),busy);
    fail(Error::capacity);
  }
  void hooked_prologue(const char *name, const Context& ctx) {
    if (!std::strcmp(name,"sub_8209CD08") || !std::strcmp(name,"sub_8209CC98")) validate_widget_list(ctx.r3.u32);
    if (!std::strcmp(name,"sub_8209DE50")) validate_widget_update(ctx.r3.u32);
    if (!std::strcmp(name,"sub_8209DF48")) validate_widget_owner(ctx.r3.u32);
    if (!std::strcmp(name,"sub_82091248")) validate_owner(ctx.r3.u32);
    // WIP 023: the exact in-frame waits poll sub_820B0F18 ("all workers
    // quiet?") while jobs sit in the pending lists; the bounded worker
    // model drains them synchronously at that poll, exactly as at the
    // frame boundary. Guarded against re-entry from the drained jobs.
    if (g_drain_workers && !drain_active && !std::strcmp(name, "sub_820B0F18")) {
      drain_active = true;
      g_drain_workers(*this, ctx.r13.u32);
      drain_active = false;
    }
    if (!std::strcmp(name, "sub_8208A7A0"))
      ++result.tree_visits;
    // WIP 023: the fixture Xenos consumes synchronously, so by the time the
    // CPU enters the exact ring-space wait (sub_820BE9F0) the hardware
    // read-index writeback has always caught up with the device's current
    // submission phase. Refresh the same writeback word the doorbell
    // contract publishes; the exact wait code then observes a caught-up GPU.
    if (!std::strcmp(name, "sub_820A1BF8") || !std::strcmp(name, "sub_820FBF50") ||
        !std::strcmp(name, "sub_82104FD0") || !std::strcmp(name, "sub_820FBF60") ||
        !std::strcmp(name, "sub_820B6CA0") || !std::strcmp(name, "sub_820D7E90"))
      cc_log("profile_init step %s r3=%08x lr=%08x\n", name, ctx.r3.u32, uint32_t(ctx.lr));
    cc_capture_on_function(name, ctx, memory);
    if (!std::strcmp(name, "sub_82077CE0")) {
      // Screen probe: the game's screen system names each transition; log
      // only changes so the session reads as a screen-by-screen map.
      static char last_screen[48] = "";
      char nm[48]{}; uint64_t bv=0;
      for (unsigned i=0;i<47u;++i) {
        if (memory.load_be(ctx.r4.u32+4u+i,1,bv)!=cc::xbox::MemoryError::ok || !bv) break;
        nm[i]=char(bv);
      }
      if (std::strcmp(nm, last_screen)) {
        std::strcpy(last_screen, nm);
        cc_log("screen '%s'\n", nm);
      }
    }
    if (!std::strcmp(name, "sub_8209DE50") && (result.functions & 0xFFFFFu) < 6u)
      cc_elog("DE50 fn=%u widget=%08x\n", result.functions, ctx.r3.u32);
    if (!std::strcmp(name, "sub_820915F0") && (result.functions & 0xFFFFFu) < 12u)
      { uint64_t pd=0,dn=0,b0=0,b1=0,b2=0,b3=0,b4=0,f0=0,f1v=0,f2=0; memory.load_be(0x8228A770u,4,pd); memory.load_be(0x8228A764u,4,dn); memory.load_be(0x8228A768u,1,b0); memory.load_be(0x8228A769u,1,b1); memory.load_be(0x8228A76Au,1,b2); memory.load_be(0x8228A76Bu,1,b3); memory.load_be(0x8228A76Cu,1,b4); memory.load_be(ctx.r3.u32+10344u,1,f0); memory.load_be(ctx.r3.u32+10345u,1,f1v); memory.load_be(ctx.r3.u32+10346u,1,f2); cc_elog("915F0 fn=%u obj=%08x pend=%08x done=%08x busy=%u%u%u%u%u flags=%u%u%u\n", result.functions, ctx.r3.u32, uint32_t(pd), uint32_t(dn), unsigned(b0),unsigned(b1),unsigned(b2),unsigned(b3),unsigned(b4),unsigned(f0),unsigned(f1v),unsigned(f2)); }
    if (frame_probe_log && !std::strcmp(name, "sub_82075C88")) {
      cc_elog("UPDATE dt=%f obj=%08x\n", ctx.f1.f64, ctx.r3.u32);
      frame_probe_log = false;
    }
    // Writeback publishes below use the raw address space: they model the
    // GPU's own memory traffic, which never counts as guest CPU memory ops,
    // so the sealed startup/init measurements stay untouched.
    if (!std::strcmp(name, "sub_820BE9F0")) {
      const uint32_t dev = 0x02000080u;
      uint64_t desc = 0, phase = 0, wb = 0;
      if (memory.load_be(dev + 10896u, 4, desc) == cc::xbox::MemoryError::ok &&
          memory.load_be(dev + 10908u, 4, phase) == cc::xbox::MemoryError::ok &&
          desc && memory.load_be(uint32_t(desc), 4, wb) == cc::xbox::MemoryError::ok) {
        if (wb == phase) {
          // GPU already caught up yet the CPU still waits: the outstanding
          // fence belongs to a submission the graphics worker thread would
          // kick on hardware. Retire exactly one step per poll; the exact
          // wait exits as soon as its fence value is reached, so this can
          // never run ahead of what the guest actually submitted.
          memory.store_be(dev + 10908u, 4, uint32_t(phase) + 1u);
          memory.store_be(uint32_t(desc), 4, uint32_t(phase) + 1u);
        } else {
          memory.store_be(uint32_t(desc), 4, uint32_t(phase));
        }
      }
    }
    // WIP 023: the same instant-consumption contract for the other two
    // writeback words the exact ring waiters poll. Each publish happens at
    // the waiter's entry, where the caught-up value is an argument:
    // sub_820C5E50 waits until the tagged read cursor [desc+4] reaches its
    // r5, and sub_820C5EE8 waits until the read address [desc+60] leaves
    // the region starting at its r4. A parked, caught-up GPU reads at the
    // submission cursor, so both waits observe completion immediately.
    if (!std::strcmp(name, "sub_820C5E50") ||
        !std::strcmp(name, "sub_820C5EE8")) {
      // Publish only when the exact wait would actually block; a waiter
      // that already sees no conflict leaves every sealed init value alone.
      const uint32_t dev = ctx.r3.u32;
      uint64_t desc = 0;
      if (dev == 0x02000080u &&
          memory.load_be(dev + 10896u, 4, desc) == cc::xbox::MemoryError::ok &&
          desc) {
        if (name[10] == '5') {  // sub_820C5E50(dev, addr=r4, cursor=r5)
          uint64_t cur = 0;
          if (memory.load_be(uint32_t(desc) + 4u, 4, cur) == cc::xbox::MemoryError::ok) {
            const uint32_t diff = (ctx.r5.u32 - uint32_t(cur)) & 3u;
            const bool blocks = diff != 0u &&
                (diff != 1u || ctx.r4.u32 > (uint32_t(cur) & ~3u));
            if (blocks)
              memory.store_be(uint32_t(desc) + 4u, 4, ctx.r5.u32);
          }
        } else {                // sub_820C5EE8(dev, start=r4, len=r5)
          uint64_t mask = 0, ra = 0;
          if (memory.load_be(dev + 14900u, 4, mask) == cc::xbox::MemoryError::ok &&
              memory.load_be(uint32_t(desc) + 60u, 4, ra) == cc::xbox::MemoryError::ok) {
            const uint32_t start = ctx.r4.u32;
            const uint32_t end = (start + ctx.r5.u32) & uint32_t(mask);
            const uint32_t r11 = uint32_t(ra);
            const bool blocks = start < end
                ? (start < r11 && r11 <= end)
                : (start < r11 || r11 <= end);
            if (blocks)
              memory.store_be(uint32_t(desc) + 60u, 4, start);
          }
        }
      }
    }
  }
  void tick([[maybe_unused]] uint32_t a) {
#ifndef CC_FAST
    // Verification builds count every guest memory access; the fast (play)
    // build does not.
    if (++result.memory_ops > budget && budget != 0xFFFFFFFFu)
      fail(Error::capacity, a);
#endif
  }
  [[noreturn]] void fail(Error e, uint32_t a = 0) {
    result.error = e;
    result.address = a;
    cc_elog("TRACE020 fail error=%u address=%08x last=%s funcs=%u memops=%u",unsigned(e),a,last_function,result.functions,result.memory_ops);
    if (last_ctx)
      cc_elog(" r1=%08x r3=%08x r4=%08x r5=%08x r6=%08x r11=%08x lr=%08x",
                   last_ctx->r1.u32,last_ctx->r3.u32,last_ctx->r4.u32,last_ctx->r5.u32,
                   last_ctx->r6.u32,last_ctx->r11.u32,uint32_t(last_ctx->lr));
    cc_elog(" recent=");
    for (unsigned k=0;k<32;++k) { const char* n=recent_functions[(recent_pos+k)&31u]; if(n) cc_elog("%s%s@%08x",k?",":"",n,recent_r1[(recent_pos+k)&31u]); }
    cc_elog("\n");
    std::longjmp(escape, 1);
  }
  // The original widget list uses +12 for its head and +20 for siblings.
  // Visibility gates are honored before following fields that the original would
  // never touch. No absent input pages are synthesized by this preflight.
  void validate_widget_list(uint32_t object) {
    if (object > 0xffffffe7u) fail(Error::context,object);
    if (!load(object+24,1)) return;
    uint32_t slow=uint32_t(load(object+12,4)),fast=slow;
    auto next=[&](uint32_t node)->uint32_t {
      if (!node) return 0;
      if (node>0xffffffebu) fail(Error::context,node);
      return uint32_t(load(node+20,4));
    };
    for(unsigned i=0;fast;++i) {
      if(i>=4096) fail(Error::capacity,object);
      slow=next(slow);fast=next(next(fast));
      if(fast && fast==slow) fail(Error::cycle,fast);
    }
  }
  void validate_widget_update(uint32_t object) {
    if(object>0xffffff9fu) fail(Error::context,object);
    if(!load(object+24,1)) return;
    const uint32_t owner=uint32_t(load(object+96,4));
    if(owner>0xffffd7b7u) fail(Error::context,owner);
  }
  void validate_widget_owner(uint32_t object) {
    if(object>0xffffff9fu) fail(Error::context,object);
    if(!load(object+24,1)) return;
    uint32_t owner=uint32_t(load(object+96,4));
    if(owner>0xffffd796u) fail(Error::context,owner);
    if(load(owner+10345,1)) {
      // Original owner stack occupies [7992,8248); its next push must fit.
      int32_t index=int32_t(uint32_t(load(owner+8248,4)));
      if(index < -1 || index >= 63) fail(Error::context,owner+8248);
    }
  }
  void validate_list(uint32_t object) {
    if (object > 0xffffff97u)
      fail(Error::context, object);
    uint32_t slow = uint32_t(load(object + 104, 4)), fast = slow;
    auto next = [&](uint32_t node) -> uint32_t {
      if (!node)
        return 0;
      if (node > 0xffffffa7u)
        fail(Error::context, node);
      return uint32_t(load(node + 88, 4));
    };
    for (unsigned i = 0; fast; ++i) {
      if (i >= 4096)
        fail(Error::capacity, object);
      slow = next(slow);
      fast = next(next(fast));
      if (fast && fast == slow)
        fail(Error::cycle, fast);
    }
  }
  void validate_owner(uint32_t owner) {
    if (owner > 0xffffd7b7u) fail(Error::context, owner);
    const uint32_t object = uint32_t(load(owner + 72, 4));
    if (object > 0xffffff97u) fail(Error::context, object);
    const uint32_t vt = uint32_t(load(object, 4));
    if (vt > 0xffffff9bu) fail(Error::context, vt);
    const uint32_t getter = uint32_t(load(vt + 100, 4));
    // Original sub_82086810 returns object + 104. Reject unknown contracts.
    if (getter != 0x82086810u) fail(Error::dispatch, getter);
    validate_list(object);
  }
  // Recently used regions (most recent first). A hit resolves a guest
  // access to host memory without searching the region table; misses take
  // the checked path and refill the cache. Same results either way.
  struct RegionHit { uint32_t lo = 0, hi = 0, access = 0; uint8_t* host = nullptr; };
  RegionHit region_cache[4];
  uint8_t* fast_host(uint32_t a, unsigned n, uint32_t access) {
    for (unsigned i = 0; i < 4; ++i) {
      const RegionHit& r = region_cache[i];
      if (a >= r.lo && a - r.lo <= r.hi - r.lo - n && r.hi - r.lo >= n && (r.access & access) == access) {
        if (i) { const RegionHit t = r; for (unsigned k = i; k; --k) region_cache[k] = region_cache[k - 1]; region_cache[0] = t; }
        return region_cache[0].host + (a - region_cache[0].lo);
      }
    }
    const cc::xbox::Region* rs = memory.regions();
    for (size_t i = 0; i < memory.region_count(); ++i) {
      const cc::xbox::Region& r = rs[i];
      if (a >= r.guest && uint64_t(a) - r.guest + n <= r.bytes && (r.access & access) == access) {
        for (unsigned k = 3; k; --k) region_cache[k] = region_cache[k - 1];
        region_cache[0] = RegionHit{r.guest, uint32_t(r.guest + (r.bytes - 1u)) + 1u, r.access, r.host};
        if (region_cache[0].hi < region_cache[0].lo) region_cache[0].hi = 0xFFFFFFFFu;
        return r.host + (a - r.guest);
      }
    }
    return nullptr;
  }
  // Hot path: the last region read from and the last written to (mostly the
  // stack) are checked inline with one comparison; everything else takes
  // the cached/checked path, which also refreshes the hot entry.
  struct HotRegion { uint32_t lo = 0, span = 0; uint8_t* host = nullptr; };
  HotRegion hot_read, hot_write;
  static uint64_t get_be(const uint8_t* p, unsigned n) {
    switch (n) {
      case 1: return p[0];
      case 2: { uint16_t x; std::memcpy(&x, p, 2); return __builtin_bswap16(x); }
      case 4: { uint32_t x; std::memcpy(&x, p, 4); return __builtin_bswap32(x); }
      default: { uint64_t x; std::memcpy(&x, p, 8); return __builtin_bswap64(x); }
    }
  }
  static void put_be(uint8_t* p, unsigned n, uint64_t v) {
    switch (n) {
      case 1: p[0] = uint8_t(v); return;
      case 2: { const uint16_t x = __builtin_bswap16(uint16_t(v)); std::memcpy(p, &x, 2); return; }
      case 4: { const uint32_t x = __builtin_bswap32(uint32_t(v)); std::memcpy(p, &x, 4); return; }
      default: { const uint64_t x = __builtin_bswap64(v); std::memcpy(p, &x, 8); return; }
    }
  }
  void refresh_hot(HotRegion& h) {
    h.lo = region_cache[0].lo;
    h.span = region_cache[0].hi - region_cache[0].lo;
    h.host = region_cache[0].host;
  }
  uint64_t load(uint32_t a, unsigned n) {
    tick(a);
    const uint32_t off = a - hot_read.lo;
    if (off < hot_read.span && hot_read.span - off >= n) return get_be(hot_read.host + off, n);
    return load_slow(a, n);
  }
  void store(uint32_t a, unsigned n, uint64_t v) {
    tick(a);
    const uint32_t off = a - hot_write.lo;
    if (off < hot_write.span && hot_write.span - off >= n) { put_be(hot_write.host + off, n, v); return; }
    store_slow(a, n, v);
  }
  uint64_t load_slow(uint32_t a, unsigned n) {
    if (const uint8_t* p = fast_host(a, n, 1u)) {
      refresh_hot(hot_read);
      return get_be(p, n);
    }
    uint64_t v = 0;
    if (memory.load_be(a, n, v) != cc::xbox::MemoryError::ok)
      fail(Error::memory, a);
    return v;
  }
  void store_slow(uint32_t a, unsigned n, uint64_t v) {
    if (uint8_t* p = fast_host(a, n, 2u)) {
      refresh_hot(hot_write);
      put_be(p, n, v);
      return;
    }
    if (memory.store_be(a, n, v) != cc::xbox::MemoryError::ok)
      fail(Error::memory, a);
  }
};
// Minimal diagnostic-harness compatibility for the ReXGlue scalar/vector
// helpers reached by the exact recovered bodies. This is not a general SIMD
// runtime: implement only the lane semantics actually emitted by the sealed
// corpus and keep generated game bodies byte-exact. Nearest-even is established
// by FloatScope; nonfinite/out-of-range scalar converts use the intrinsic
// indefinite value.
struct ScalarDouble {
  double value;
};
static ScalarDouble simde_mm_load_sd(const double *p) { return {*p}; }
static int64_t convert(double x, bool nearest) {
  if (!std::isfinite(x))
    return INT64_MIN;
  double n = nearest ? std::nearbyint(x) : std::trunc(x);
  if (n < -0x1p63 || n >= 0x1p63)
    return INT64_MIN;
  return static_cast<int64_t>(n);
}
static int64_t simde_mm_cvtsd_si64(ScalarDouble d) {
  return convert(d.value, true);
}
static int64_t simde_mm_cvttsd_si64(ScalarDouble d) {
  return convert(d.value, false);
}
static int32_t simde_mm_cvttsd_si32(ScalarDouble d) {
  if (!std::isfinite(d.value) || d.value < double(INT_MIN) || d.value >= 2147483648.0)
    return INT_MIN;
  return static_cast<int32_t>(std::trunc(d.value));
}
using PPCVRegister = cc::quad::VRegister;
struct SimdI021 { uint8_t u8[16]; };
struct SimdF021 { float f32[4]; };
using simde__m128i = SimdI021;
using simde__m128 = SimdF021;
static simde__m128i simde_mm_load_si128(const simde__m128i* p) { simde__m128i v{}; std::memcpy(&v,p,16); return v; }
static void simde_mm_store_si128(simde__m128i* p, simde__m128i v) { std::memcpy(p,&v,16); }
static simde__m128 simde_mm_load_ps(const float* p) { simde__m128 v{}; std::memcpy(v.f32,p,16); return v; }
static void simde_mm_store_ps(float* p, simde__m128 v) { std::memcpy(p,v.f32,16); }
static simde__m128 simde_mm_permute_ps(simde__m128 a, int imm) {
  simde__m128 r{}; for(int i=0;i<4;++i) r.f32[i]=a.f32[(imm>>(i*2))&3]; return r;
}
static simde__m128 simde_mm_blend_ps(simde__m128 a, simde__m128 b, int mask) {
  simde__m128 r{}; for(int i=0;i<4;++i) r.f32[i]=(mask&(1<<i))?b.f32[i]:a.f32[i]; return r;
}
static simde__m128 simde_mm_add_ps(simde__m128 a, simde__m128 b) { simde__m128 r{}; for(int i=0;i<4;++i) r.f32[i]=a.f32[i]+b.f32[i]; return r; }
static simde__m128 simde_mm_sub_ps(simde__m128 a, simde__m128 b) { simde__m128 r{}; for(int i=0;i<4;++i) r.f32[i]=a.f32[i]-b.f32[i]; return r; }
static simde__m128 simde_mm_mul_ps(simde__m128 a, simde__m128 b) { simde__m128 r{}; for(int i=0;i<4;++i) r.f32[i]=a.f32[i]*b.f32[i]; return r; }
static simde__m128 simde_mm_div_ps(simde__m128 a, simde__m128 b) { simde__m128 r{}; for(int i=0;i<4;++i) r.f32[i]=a.f32[i]/b.f32[i]; return r; }
static simde__m128 simde_mm_set1_ps(float v) { simde__m128 r{}; for(int i=0;i<4;++i) r.f32[i]=v; return r; }
static simde__m128 simde_mm_max_ps(simde__m128 a, simde__m128 b) {
  simde__m128 r{}; for(int i=0;i<4;++i) r.f32[i]=(std::isnan(a.f32[i])||std::isnan(b.f32[i]))?b.f32[i]:(a.f32[i]>b.f32[i]?a.f32[i]:b.f32[i]); return r;
}
static simde__m128 simde_mm_min_ps(simde__m128 a, simde__m128 b) {
  simde__m128 r{}; for(int i=0;i<4;++i) r.f32[i]=(std::isnan(a.f32[i])||std::isnan(b.f32[i]))?b.f32[i]:(a.f32[i]<b.f32[i]?a.f32[i]:b.f32[i]); return r;
}
static simde__m128i simde_mm_set1_epi32(int v) { simde__m128i r{}; for(int i=0;i<4;++i) std::memcpy(r.u8+i*4,&v,4); return r; }
static simde__m128i simde_mm_set1_epi8(char v) { simde__m128i r{}; for(int i=0;i<16;++i) r.u8[i]=uint8_t(v); return r; }
static simde__m128i simde_mm_and_si128(simde__m128i a, simde__m128i b) { simde__m128i r{}; for(int i=0;i<16;++i) r.u8[i]=uint8_t(a.u8[i]&b.u8[i]); return r; }
static simde__m128i simde_mm_andnot_si128(simde__m128i a, simde__m128i b) { simde__m128i r{}; for(int i=0;i<16;++i) r.u8[i]=uint8_t((~a.u8[i])&b.u8[i]); return r; }
static simde__m128i simde_mm_or_si128(simde__m128i a, simde__m128i b) { simde__m128i r{}; for(int i=0;i<16;++i) r.u8[i]=uint8_t(a.u8[i]|b.u8[i]); return r; }
static simde__m128i simde_mm_add_epi32(simde__m128i a, simde__m128i b) {
  simde__m128i r{}; uint32_t av[4]{},bv[4]{},rv[4]{}; std::memcpy(av,a.u8,16); std::memcpy(bv,b.u8,16);
  for(int i=0;i<4;++i) rv[i]=av[i]+bv[i]; std::memcpy(r.u8,rv,16); return r;
}
static simde__m128i simde_mm_max_epi32(simde__m128i a, simde__m128i b) {
  // vmaxsw: per-lane signed 32-bit maximum.
  simde__m128i r{}; int32_t av[4]{},bv[4]{},rv[4]{}; std::memcpy(av,a.u8,16); std::memcpy(bv,b.u8,16);
  for(int i=0;i<4;++i) rv[i]=av[i]>bv[i]?av[i]:bv[i]; std::memcpy(r.u8,rv,16); return r;
}
static simde__m128i simde_mm_slli_epi32(simde__m128i a, int n) {
  simde__m128i r{}; uint32_t av[4]{},rv[4]{}; std::memcpy(av,a.u8,16);
  for(int i=0;i<4;++i) rv[i]=(n>=32)?0u:(av[i]<<n); std::memcpy(r.u8,rv,16); return r;
}
static simde__m128i simde_mm_sllv_epi32(simde__m128i a, simde__m128i b) {
  simde__m128i r{}; uint32_t av[4]{},bv[4]{},rv[4]{}; std::memcpy(av,a.u8,16); std::memcpy(bv,b.u8,16);
  for(int i=0;i<4;++i) rv[i]=(bv[i]>=32u)?0u:(av[i]<<bv[i]); std::memcpy(r.u8,rv,16); return r;
}
static simde__m128 simde_mm_castsi128_ps(simde__m128i a) { simde__m128 r{}; std::memcpy(r.f32,a.u8,16); return r; }
static simde__m128i simde_mm_cvttps_epi32(simde__m128 a) {
  simde__m128i r{}; int32_t out[4]{};
  for(int i=0;i<4;++i) { const float x=a.f32[i]; if(!std::isfinite(x)||x < -2147483648.0f || x >= 2147483648.0f) out[i]=INT32_MIN; else out[i]=static_cast<int32_t>(std::trunc(x)); }
  std::memcpy(r.u8,out,16); return r;
}
static simde__m128i simde_mm_shuffle_epi32(simde__m128i a, int imm) {
  simde__m128i r{}; uint32_t lanes[4]{}; std::memcpy(lanes,a.u8,16); uint32_t out[4]{};
  for(int i=0;i<4;++i) out[i]=lanes[(imm>>(i*2))&3]; std::memcpy(r.u8,out,16); return r;
}
static simde__m128i simde_mm_xor_si128(simde__m128i a, simde__m128i b) { simde__m128i r{}; for(int i=0;i<16;++i) r.u8[i]=a.u8[i]^b.u8[i]; return r; }
static simde__m128 simde_mm_xor_ps(simde__m128 a, simde__m128 b) { simde__m128 r{}; uint32_t av[4]{},bv[4]{},rv[4]{}; std::memcpy(av,a.f32,16); std::memcpy(bv,b.f32,16); for(int i=0;i<4;++i) rv[i]=av[i]^bv[i]; std::memcpy(r.f32,rv,16); return r; }
static simde__m128 simde_mm_cmpeq_ps(simde__m128 a, simde__m128 b) { simde__m128 r{}; uint32_t bits[4]{}; for(int i=0;i<4;++i) bits[i]=(!std::isnan(a.f32[i])&&!std::isnan(b.f32[i])&&a.f32[i]==b.f32[i])?0xffffffffu:0u; std::memcpy(r.f32,bits,16); return r; }
static simde__m128 simde_mm_cmpgt_ps(simde__m128 a, simde__m128 b) { simde__m128 r{}; uint32_t bits[4]{}; for(int i=0;i<4;++i) bits[i]=(!std::isnan(a.f32[i])&&!std::isnan(b.f32[i])&&a.f32[i]>b.f32[i])?0xffffffffu:0u; std::memcpy(r.f32,bits,16); return r; }
static constexpr int SIMDE_MM_FROUND_TO_NEAREST_INT=0x00;
static constexpr int SIMDE_MM_FROUND_TO_NEG_INF=0x01;
static constexpr int SIMDE_MM_FROUND_TO_ZERO=0x03;
static constexpr int SIMDE_MM_FROUND_NO_EXC=0x08;
static simde__m128 simde_mm_round_ps(simde__m128 a, int mode) {
  simde__m128 r{}; const int m=mode&0x07;
  for(int i=0;i<4;++i) { if(m==SIMDE_MM_FROUND_TO_NEG_INF) r.f32[i]=std::floor(a.f32[i]); else if(m==SIMDE_MM_FROUND_TO_ZERO) r.f32[i]=std::trunc(a.f32[i]); else r.f32[i]=std::nearbyint(a.f32[i]); }
  return r;
}
// PPC lvsl control table in ReXGlue host byte order. lvsl with shift sh must
// yield the big-endian control vector whose lane j equals sh+j; host lane i
// mirrors big-endian lane 15-i, so row sh holds [sh+15, sh+14, ..., sh]. The
// pairing with simde_mm_perm_epi8_ below reproduces exact vperm unaligned
// loads: be-lane j selects concat(vA,vB)[c_be[j] & 0x1F].
static constexpr uint8_t VectorShiftTableL[256] = {
  0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00,
  0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01,
  0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,
  0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,
  0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,
  0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,
  0x15,0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,
  0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,
  0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,
  0x18,0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,
  0x19,0x18,0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,
  0x1A,0x19,0x18,0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,
  0x1B,0x1A,0x19,0x18,0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,
  0x1C,0x1B,0x1A,0x19,0x18,0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,
  0x1D,0x1C,0x1B,0x1A,0x19,0x18,0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,
  0x1E,0x1D,0x1C,0x1B,0x1A,0x19,0x18,0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0F
};
namespace rex::ppc {
// Lanewise vector shift-left by per-byte counts (PPC vslb).
static simde__m128i simde_mm_sllv_epi8(simde__m128i a, simde__m128i b) {
  simde__m128i r{};
  for (int i=0;i<16;++i) {
    const unsigned n = b.u8[i] & 7u;
    r.u8[i] = uint8_t(a.u8[i] << n);
  }
  return r;
}
// PPC vperm in the host mirrored-lane representation: host lane i is
// big-endian lane 15-i, so the be-space select translates to
// d_host[i] = (c&0x10) ? b_host[31-c] : a_host[15-c] with c = c_host[i]&0x1F.
static simde__m128i simde_mm_perm_epi8_(simde__m128i a, simde__m128i b, simde__m128i c) {
  simde__m128i d{};
  for (int i=0;i<16;++i) {
    const uint8_t sel = uint8_t(c.u8[i] & 0x1F);
    d.u8[i] = sel < 16 ? a.u8[15 - sel] : b.u8[31 - sel];
  }
  return d;
}
static simde__m128i simde_mm_adds_epu32(simde__m128i a, simde__m128i b) {
  // vadduws: per-lane unsigned 32-bit saturating add.
  simde__m128i r{}; uint32_t av[4]{},bv[4]{},rv[4]{}; std::memcpy(av,a.u8,16); std::memcpy(bv,b.u8,16);
  for(int i=0;i<4;++i) { const uint64_t s=uint64_t(av[i])+bv[i]; rv[i]=s>0xFFFFFFFFull?0xFFFFFFFFu:uint32_t(s); }
  std::memcpy(r.u8,rv,16); return r;
}
static simde__m128i simde_mm_vctsxs(simde__m128 a) {
  simde__m128i r{}; int32_t out[4]{};
  for(int i=0;i<4;++i) {
    const float x=a.f32[i];
    if (std::isnan(x)) out[i]=0;
    else if (x>=float(INT32_MAX)) out[i]=INT32_MAX;
    else if (x<=float(INT32_MIN)) out[i]=INT32_MIN;
    else out[i]=static_cast<int32_t>(std::trunc(x));
  }
  std::memcpy(r.u8,out,16); return r;
}
// vcuxwfp128 source conversion: per-lane unsigned 32-bit to float.
static simde__m128 simde_mm_cvtepu32_ps_(simde__m128i a) {
  simde__m128 r{}; uint32_t v[4]{}; std::memcpy(v,a.u8,16);
  for(int i=0;i<4;++i) r.f32[i]=float(v[i]);
  return r;
}
// vsr: the whole 128-bit register shifted right by vB's low-order byte & 7.
// Host lanes mirror big-endian lanes, so the host little-endian 128-bit value
// equals the big-endian register value and big-endian byte 15 is host byte 0.
static simde__m128i simde_mm_vsr(simde__m128i a, simde__m128i b) {
  const unsigned sh = b.u8[0] & 7u;
  simde__m128i r{};
  for (int i=0;i<16;++i) {
    const unsigned hi = (i < 15) ? a.u8[i+1] : 0u;
    r.u8[i] = uint8_t(sh ? ((a.u8[i] >> sh) | (hi << (8 - sh))) : a.u8[i]);
  }
  return r;
}
// vavgsb / vavgsh: signed rounding average, (a + b + 1) >> 1 per lane.
static simde__m128i simde_mm_avg_epi8(simde__m128i a, simde__m128i b) {
  simde__m128i r{};
  for (int i=0;i<16;++i) r.u8[i]=uint8_t(int8_t((int(int8_t(a.u8[i]))+int(int8_t(b.u8[i]))+1)>>1));
  return r;
}
static simde__m128i simde_mm_avg_epi16(simde__m128i a, simde__m128i b) {
  simde__m128i r{}; int16_t av[8]{},bv[8]{},rv[8]{}; std::memcpy(av,a.u8,16); std::memcpy(bv,b.u8,16);
  for (int i=0;i<8;++i) rv[i]=int16_t((int(av[i])+int(bv[i])+1)>>1);
  std::memcpy(r.u8,rv,16); return r;
}
}
// SSE-semantics helpers on host lanes (the generated code maps AltiVec to
// these with the mirrored-lane layout already accounted for).
static simde__m128 simde_mm_dp_ps(simde__m128 a, simde__m128 b, int imm) {
  float p[4]{};
  for (int i=0;i<4;++i) p[i]=((imm>>(4+i))&1)?a.f32[i]*b.f32[i]:0.0f;
  const float s=(p[0]+p[1])+(p[2]+p[3]);
  simde__m128 r{};
  for (int i=0;i<4;++i) r.f32[i]=((imm>>i)&1)?s:0.0f;
  return r;
}
static simde__m128 simde_mm_cvtepi32_ps(simde__m128i a) {
  simde__m128 r{}; int32_t v[4]{}; std::memcpy(v,a.u8,16);
  for (int i=0;i<4;++i) r.f32[i]=float(v[i]);
  return r;
}
static simde__m128i simde_mm_add_epi8(simde__m128i a, simde__m128i b) {
  simde__m128i r{}; for (int i=0;i<16;++i) r.u8[i]=uint8_t(a.u8[i]+b.u8[i]); return r;
}
static simde__m128i simde_mm_cvtepi16_epi32(simde__m128i a) {
  simde__m128i r{}; int16_t v[8]{}; int32_t o[4]{}; std::memcpy(v,a.u8,16);
  for (int i=0;i<4;++i) o[i]=v[i];
  std::memcpy(r.u8,o,16); return r;
}
static simde__m128i simde_mm_cvtepi8_epi16(simde__m128i a) {
  simde__m128i r{}; int16_t o[8]{};
  for (int i=0;i<8;++i) o[i]=int8_t(a.u8[i]);
  std::memcpy(r.u8,o,16); return r;
}
static simde__m128i simde_mm_packs_epi32(simde__m128i a, simde__m128i b) {
  simde__m128i r{}; int32_t av[4]{},bv[4]{}; int16_t o[8]{};
  std::memcpy(av,a.u8,16); std::memcpy(bv,b.u8,16);
  auto sat=[](int32_t x){ return int16_t(x>32767?32767:(x<-32768?-32768:x)); };
  for (int i=0;i<4;++i) { o[i]=sat(av[i]); o[4+i]=sat(bv[i]); }
  std::memcpy(r.u8,o,16); return r;
}
template <int W>
static simde__m128i cc_unpack(simde__m128i a, simde__m128i b, bool high) {
  simde__m128i r{}; const int n=16/W/2, base=high?8:0;
  for (int i=0;i<n;++i) {
    std::memcpy(r.u8+(2*i)*W,a.u8+base+i*W,W);
    std::memcpy(r.u8+(2*i+1)*W,b.u8+base+i*W,W);
  }
  return r;
}
static simde__m128i simde_mm_unpacklo_epi8(simde__m128i a, simde__m128i b) { return cc_unpack<1>(a,b,false); }
static simde__m128i simde_mm_unpackhi_epi8(simde__m128i a, simde__m128i b) { return cc_unpack<1>(a,b,true); }
static simde__m128i simde_mm_unpacklo_epi16(simde__m128i a, simde__m128i b) { return cc_unpack<2>(a,b,false); }
static simde__m128i simde_mm_unpackhi_epi16(simde__m128i a, simde__m128i b) { return cc_unpack<2>(a,b,true); }
static simde__m128i simde_mm_unpacklo_epi32(simde__m128i a, simde__m128i b) { return cc_unpack<4>(a,b,false); }
static simde__m128i simde_mm_unpackhi_epi32(simde__m128i a, simde__m128i b) { return cc_unpack<4>(a,b,true); }
static simde__m128i simde_mm_unpackhi_epi64(simde__m128i a, simde__m128i b) { return cc_unpack<8>(a,b,true); }
static simde__m128i simde_mm_shuffle_epi8(simde__m128i a, simde__m128i m) { simde__m128i r{}; for(int i=0;i<16;++i) r.u8[i]=(m.u8[i]&0x80u)?0u:a.u8[m.u8[i]&15u]; return r; }
static simde__m128i simde_mm_alignr_epi8(simde__m128i a, simde__m128i b, int n) { simde__m128i r{}; uint8_t c[32]; std::memcpy(c,b.u8,16); std::memcpy(c+16,a.u8,16); for(int i=0;i<16;++i) r.u8[i]=(n+i<32)?c[n+i]:0u; return r; }
static constexpr uint8_t VectorMaskL[256] = {
  0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00,
  0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01,
  0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,
  0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,
  0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,
  0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F
};
// PPC lvrx shuffle table, the right-load counterpart of VectorMaskL: with
// shift sh the vector's low big-endian lanes 16-sh..15 receive block bytes
// 0..sh-1 and the rest are zero. In host mirrored-lane order that is
// m[i] = (i < sh) ? sh-1-i : 0xFF. Row 0 is unreachable (the generated code
// branches to setzero when the shift is zero).
static constexpr uint8_t VectorMaskR[256] = {
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x01,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x04,0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x05,0x04,0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x06,0x05,0x04,0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,
  0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,
  0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00,0xFF,0xFF,
  0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00,0xFF
};
static simde__m128i simde_mm_setzero_si128() { return simde__m128i{}; }
static uint8_t* raw_addr021(Machine& base,uint32_t a) { auto* p=base.fast_host(a,16,3); if(!p) p=base.memory.contiguous(a,16,3); if(!p) base.fail(Error::memory,a); return p; }
#define REX_RAW_ADDR(a) raw_addr021(base,uint32_t(a))
using PPCRegister = Register;
#define DEFINE_REX_FUNC(name)                                                  \
  static void name([[maybe_unused]] Context &ctx,                              \
                   [[maybe_unused]] Machine &base)
#define REX_FUNC_PROLOGUE() base.prologue(__func__,ctx)
#define REX_LOAD_U8(a) uint8_t(base.load(uint32_t(a), 1))
#define REX_LOAD_U16(a) uint16_t(base.load(uint32_t(a), 2))
#define REX_LOAD_U32(a) uint32_t(base.load(uint32_t(a), 4))
#define REX_LOAD_U64(a) base.load(uint32_t(a), 8)
#define REX_STORE_U8(a, v) base.store(uint32_t(a), 1, v)
#define REX_STORE_U16(a, v) base.store(uint32_t(a), 2, v)
#define REX_STORE_U32(a, v) base.store(uint32_t(a), 4, v)
#define REX_STORE_U64(a, v) base.store(uint32_t(a), 8, v)
// ---- Host-only frame capture -------------------------------------------
// Records, for selected frames, every draw the game submits through its
// final draw call (exact sub_820C1980: device, primitive, count, vertex
// pointer, stride) together with the projection matrix, blend state and the
// texture bound by the game's bind call (exact sub_820A89F8: the game's
// texture record carries width +16, height +20, format code +24 and the
// pixel pointer +36). Written as CCFRAME1 files for the host rasterizer
// (tools/render_capture.py). Raw address-space reads only: capture never
// changes a measured count or any guest state.
#ifndef CC_XBOX_DRIVER
struct CcCapTex { uint32_t data, w, h, fmt; std::vector<uint8_t> bytes; };
struct CcCapDraw {
  uint32_t prim, count, stride, blend, tex;
  uint32_t matrix[16];
  std::vector<uint8_t> verts;
};
static struct {
  bool init = false, enabled = false, active = false, mem_report = false, workset = false;
  uint32_t frame_now = 0;
  std::vector<uint32_t> frames;
  char dir[512] = {};
  uint32_t cur_tex = 0, cur_w = 0, cur_h = 0, cur_fmt = 0, cur_src = 0;
  std::vector<CcCapTex> texs;
  std::vector<CcCapDraw> draws;
} g_cap;
static uint32_t cc_pow2(uint32_t v) { uint32_t p = 1; while (p < v && p) p <<= 1; return p; }
static uint32_t cc_rd32(cc::xbox::AddressSpace& mem, uint32_t a) {
  uint64_t v = 0; mem.load_be(a, 4, v); return uint32_t(v);
}
static void cc_capture_init(uint32_t first_frame) {
  g_cap.init = true;
  g_cap.mem_report = std::getenv("CC_MEM_REPORT") != nullptr;
  g_cap.workset = std::getenv("CC_WORKSET") != nullptr;
  const char* f = std::getenv("CC_CAPTURE_FRAMES");
  const char* d = std::getenv("CC_CAPTURE_DIR");
  if (!f || !d) return;
  std::snprintf(g_cap.dir, sizeof(g_cap.dir), "%s", d);
  for (const char* p = f; *p;) {
    char* end = nullptr;
    const unsigned long n = std::strtoul(p, &end, 10);
    if (end == p) break;
    g_cap.frames.push_back(uint32_t(n));
    p = (*end == ',') ? end + 1 : end;
  }
  g_cap.enabled = !g_cap.frames.empty();
  for (uint32_t fr : g_cap.frames) if (fr == first_frame) g_cap.active = true;
}
static void cc_capture_on_function(const char* name, const Context& ctx,
                                   cc::xbox::AddressSpace& mem) {
  if (!g_cap.init) cc_capture_init(1u);
  if (!g_cap.enabled && !g_cap.mem_report && !g_cap.workset) return;
  if (name[0] != 's' || name[4] != '8' || name[5] != '2') return;
  if (!std::strncmp(name, "sub_820A89F8", 12)) {
    const uint32_t d = ctx.r4.u32;
    if (std::getenv("CC_MEM_REPORT"))
      g_bound_textures[cc_rd32(mem, d + 36)] = cc_rd32(mem, d + 16) | (cc_rd32(mem, d + 20) << 16);
    if (g_cap.workset) g_tex_last_bound[cc_rd32(mem, d + 36)] = g_cap.frame_now;
    g_cap.cur_w = cc_rd32(mem, d + 16); g_cap.cur_h = cc_rd32(mem, d + 20);
    g_cap.cur_fmt = cc_rd32(mem, d + 24); g_cap.cur_tex = cc_rd32(mem, d + 36);
    // Capture format 100: the port's DXT5 (standard block layout), read from
    // the streaming cache rather than the game's (cut-down) block.
    g_cap.cur_src = g_cap.cur_tex;
    if (const CcDxtTexture* t = cc_find_dxt_texture(g_cap.cur_tex)) { g_cap.cur_fmt = 100u; g_cap.cur_src = t->cache; }
    return;
  }
  if (!g_cap.enabled || !g_cap.active || std::strncmp(name, "sub_820C1980", 12)) return;
  CcCapDraw dr{};
  const uint32_t dev = ctx.r3.u32;
  dr.prim = ctx.r4.u32; dr.count = ctx.r5.u32; dr.stride = ctx.r7.u32;
  dr.blend = cc_rd32(mem, dev + 10552);
  dr.tex = g_cap.cur_tex;
  // Diagnostic words: [0] command-ring write cursor (device+13444) at the
  // draw, [1] device+13448; the rest are zero. Constants live in the ring.
  dr.matrix[0] = cc_rd32(mem, dev + 13444);
  dr.matrix[1] = cc_rd32(mem, dev + 13448);
  const uint32_t n = dr.count * dr.stride;
  if (n && n <= 65536u) {
    dr.verts.resize(n);
    if (mem.read(ctx.r6.u32, dr.verts.data(), n) != cc::xbox::MemoryError::ok) dr.verts.clear();
  }
  g_cap.draws.push_back(std::move(dr));
  if (std::getenv("CC_CAPTURE_DEVDUMP")) {
    // Diagnostic: the first 16 KiB of the device object at every draw.
    char path[640];
    std::snprintf(path, sizeof(path), "%s/dev_%05u.bin", g_cap.dir,
                  unsigned(g_cap.draws.size() - 1));
    std::vector<uint8_t> blob(16384);
    if (mem.read(dev, blob.data(), blob.size()) == cc::xbox::MemoryError::ok)
      if (std::FILE* f = std::fopen(path, "wb")) {
        std::fwrite(blob.data(), 1, blob.size(), f);
        std::fclose(f);
      }
  }
  if (!g_cap.cur_tex) return;
  for (const auto& t : g_cap.texs) if (t.data == g_cap.cur_tex) return;
  CcCapTex t{g_cap.cur_tex, g_cap.cur_w, g_cap.cur_h, g_cap.cur_fmt, {}};
  // Pixel bytes: power-of-two padded, 32-texel aligned; 4 bpp for code 1,
  // 2 for code 5; DXT codes 7..11 are 4x4 blocks of 8 (7) or 16 bytes.
  const uint32_t W = (cc_pow2(t.w) + 31u) & ~31u, H = (cc_pow2(t.h) + 31u) & ~31u;
  uint32_t bytes = 0;
  if (t.fmt == 1) bytes = W * H * 4u;
  else if (t.fmt == 100) bytes = t.w * t.h;
  else if (t.fmt == 5) bytes = W * H * 2u;
  else if (t.fmt >= 7 && t.fmt <= 11) bytes = (W / 4u) * (H / 4u) * (t.fmt == 7 ? 8u : 16u);
  if (bytes && bytes <= 16u * 1024u * 1024u) {
    t.bytes.resize(bytes);
    if (mem.read(g_cap.cur_src ? g_cap.cur_src : t.data, t.bytes.data(), bytes) != cc::xbox::MemoryError::ok) t.bytes.clear();
  }
  g_cap.texs.push_back(std::move(t));
}
static void cc_capture_end_frame(cc::xbox::AddressSpace& mem, uint32_t frame) {
  if (!g_cap.init) cc_capture_init(frame);
  if (g_cap.workset) {
    // Texture working set (DXT5 bytes = w*h): drawn this frame, within the
    // last 60 and 600 frames, and all compressed textures resident.
    g_cap.frame_now = frame;
    if (frame % 250u == 0u) {
      uint64_t now = 0, w60 = 0, w600 = 0, resident = 0;
      for (const auto& t : g_dxt_textures) {
        const uint64_t b = uint64_t(t.w) * t.h;
        resident += b;
        const auto it = g_tex_last_bound.find(t.data);
        if (it == g_tex_last_bound.end()) continue;
        const uint32_t age = frame - it->second;
        if (age <= 1u) now += b;
        if (age <= 60u) w60 += b;
        if (age <= 600u) w600 += b;
      }
      cc_log("WORKSET frame=%u drawn_now=%lluK last_60=%lluK last_600=%lluK resident=%lluK textures=%u\n",
             frame, (unsigned long long)(now >> 10), (unsigned long long)(w60 >> 10),
             (unsigned long long)(w600 >> 10), (unsigned long long)(resident >> 10),
             unsigned(g_dxt_textures.size()));
    }
  }
  if (!g_cap.enabled) return;
  if (g_cap.active) {
    char path[640];
    std::snprintf(path, sizeof(path), "%s/frame_%05u.ccframe", g_cap.dir, frame);
    if (std::FILE* f = std::fopen(path, "wb")) {
      auto w32 = [&](uint32_t v) { std::fwrite(&v, 4, 1, f); };
      std::fwrite("CCFRAME1", 1, 8, f);
      w32(frame); w32(uint32_t(g_cap.texs.size())); w32(uint32_t(g_cap.draws.size()));
      for (const auto& t : g_cap.texs) {
        w32(t.data); w32(t.w); w32(t.h); w32(t.fmt); w32(uint32_t(t.bytes.size()));
        if (!t.bytes.empty()) std::fwrite(t.bytes.data(), 1, t.bytes.size(), f);
      }
      for (const auto& d : g_cap.draws) {
        w32(d.prim); w32(d.count); w32(d.stride); w32(d.blend); w32(d.tex);
        for (uint32_t m : d.matrix) w32(m);
        w32(uint32_t(d.verts.size()));
        if (!d.verts.empty()) std::fwrite(d.verts.data(), 1, d.verts.size(), f);
      }
      std::fclose(f);
      if (std::getenv("CC_CAPTURE_RING")) {
        // Command arena [0x0200F140, 0x0220F000) as raw guest bytes.
        std::snprintf(path, sizeof(path), "%s/ring_%05u.bin", g_cap.dir, frame);
        std::vector<uint8_t> ring(0x0220F000u - 0x02000000u);
        if (mem.read(0x02000000u, ring.data(), ring.size()) == cc::xbox::MemoryError::ok)
          if (std::FILE* rf = std::fopen(path, "wb")) {
            std::fwrite(ring.data(), 1, ring.size(), rf);
            std::fclose(rf);
          }
      }
      cc_log("capture frame=%u draws=%u textures=%u -> %s\n", frame,
             unsigned(g_cap.draws.size()), unsigned(g_cap.texs.size()), path);
    }
  }
  g_cap.texs.clear(); g_cap.draws.clear();
  g_cap.active = false;
  for (uint32_t fr : g_cap.frames) if (fr == frame + 1u) g_cap.active = true;
}
#else
static void cc_capture_on_function(const char*, const Context&, cc::xbox::AddressSpace&) {}
static void cc_capture_end_frame(cc::xbox::AddressSpace&, uint32_t) {}
#endif
static void dispatch(uint32_t, Context &, Machine &);
#define REX_CALL_INDIRECT_FUNC(a) dispatch(uint32_t(a), ctx, base)
#include "decls.inc"
#define sub_8208C5D8 sub_8208C5D8_unsupported008
#include "../runtime008/bodies.inc"
#undef sub_8208C5D8
#include "../runtime010/bodies.inc"
#include "../runtime011/bodies.inc"
#include "bodies.inc"
static bool submit(void *ptr, const Draw &d) {
  auto &m = *static_cast<Machine *>(ptr);
  if (!m.sink.submit || !m.sink.submit(m.sink.user, d))
    return false;
  ++m.result.submits;
  return true;
}
static void dispatch_impl(uint32_t address, Context &ctx, Machine &base) {
  if (++base.result.dispatches > 2000000000u)
    base.fail(Error::capacity, address);
  if (address == 0x82091248)
    base.validate_owner(ctx.r3.u32);
  if (address == 0x8208a7a0)
    base.validate_list(ctx.r3.u32);
  switch (address) {
#include "../runtime008/dispatch.inc"
#include "../runtime010/dispatch.inc"
#include "../runtime011/dispatch.inc"
#include "dispatch.inc"
  case 0x8214a534: {
    // NtCreateFile ??? bounded shader-file platform contract. Accept only the
    // observed synchronous read-only open (access 0x80100080, OBJ root -3,
    // OBJ_CASE_INSENSITIVE, FILE_OPEN, options 0x60) of "game:\shaders\<name>"
    // backed by the extracted retail-container files.
    const uint32_t handle_out=ctx.r3.u32, oa=ctx.r5.u32, iosb=ctx.r6.u32;
    // Two observed open shapes share access 0x80100080, OBJ root -3,
    // OBJ_CASE_INSENSITIVE, FILE_OPEN, options 0x60: the shader loader passes
    // FileAttributes=0/ShareAccess=0, the font loader passes 1/1.
    const bool shader_open_shape = ctx.r8.u32==0u && ctx.r9.u32==0u;
    const bool font_open_shape   = ctx.r8.u32==1u && ctx.r9.u32==1u;
    // WIP 023 third observed shape: the frame loop's pak loader opens
    // "game:\game\<name>.pak" with FILE_ATTRIBUTE_NORMAL (0x80) and
    // FILE_SHARE_READ (1); all other parameters identical.
    // WIP 023 fourth shape: the sound loader opens "game:\sounds\*.xma"
    // with FileAttributes 0 and FILE_SHARE_READ; path-selected directory
    // like the pak shape.
    const bool pak_open_shape    = (ctx.r8.u32==0x80u || ctx.r8.u32==0u) &&
                                   ctx.r9.u32==1u;
    Machine::FileSlot* slot=nullptr;
    for (auto &fs : base.files) if (!fs.open) { slot=&fs; break; }
    if (!slot || ctx.r4.u32!=0x80100080u || ctx.r7.u32!=0u ||
        (!shader_open_shape && !font_open_shape && !pak_open_shape) || ctx.r10.u32!=1u ||
        uint32_t(base.load(ctx.r1.u32+84,4))!=0x60u ||
        uint32_t(base.load(oa+0,4))!=0xFFFFFFFDu ||
        uint32_t(base.load(oa+8,4))!=0x40u) {
      cc_elog("NTCREATE reject open=%d r4=%08x r7=%08x r8=%08x r9=%08x r10=%08x s84=%08x oa0=%08x oa8=%08x\n",
        int(base.open_files()),ctx.r4.u32,ctx.r7.u32,ctx.r8.u32,ctx.r9.u32,ctx.r10.u32,
        uint32_t(base.load(ctx.r1.u32+84,4)),uint32_t(base.load(oa+0,4)),uint32_t(base.load(oa+8,4)));
      base.fail(Error::unsupported, address);
    }
    const uint32_t str=uint32_t(base.load(oa+4,4));
    const uint32_t len=uint32_t(base.load(str+0,2));
    const uint32_t buf=uint32_t(base.load(str+4,4));
    {
      char pth[96]{};
      for (uint32_t j=0;j<len && j<95u;++j) { uint64_t cv=0; base.memory.load_be(buf+j,1,cv); pth[j]=char(cv); }
      cc_log("file_open_request '%s' shape r8=%u r9=%u\n",pth,ctx.r8.u32,ctx.r9.u32);
    }
    // Accepted path prefixes, each mapped to its extracted-container
    // directory and its per-family size bound.
    static constexpr char shader_prefix[]="game:\\shaders\\";
    static constexpr char font_prefix[]="game:\\Fonts\\";
    // WIP 023: the pak-shaped open loads from a small set of observed
    // directories ("game", "sounds", "music"); pick the mapping by the
    // guest path's own directory segment, case-insensitively.
    char dseg[16]{}; unsigned dlen=0;
    if (pak_open_shape) {
      uint64_t chv=0;
      const uint32_t sp=uint32_t(base.load(uint32_t(base.load(ctx.r5.u32+4,4))+4,4));
      for (unsigned i=6;i<6+15u;++i) {
        if (base.memory.load_be(sp+i,1,chv)!=cc::xbox::MemoryError::ok) break;
        char c=char(chv);
        if (c>='A'&&c<='Z') c=char(c+32);
        if (c=='\\'||c==0) break;
        dseg[dlen++]=c;
      }
    }
    // Pak-style opens map game:\<folder>\<file> onto the extracted data
    // folder of the same name, for the folders the retail container has.
    static const char* const k_pak_dirs[] = {"game","sounds","music","levels","art","bsps"};
    bool pak_dir_known = false;
    for (const char* d : k_pak_dirs) if (pak_open_shape && !std::strcmp(dseg,d)) pak_dir_known = true;
    if (pak_open_shape && !pak_dir_known) {
      cc_elog("NTCREATE reject unknown folder '%s'\n", dseg);
      base.fail(Error::unsupported, address);
    }
    char dyn_prefix[32]{}, dyn_host[32]{};
    std::snprintf(dyn_prefix, sizeof(dyn_prefix), "game:\\%s\\", dseg);
    std::snprintf(dyn_host, sizeof(dyn_host), "/%s/", dseg);
    const char* prefix = shader_open_shape ? shader_prefix
                       : font_open_shape   ? font_prefix : dyn_prefix;
    const uint32_t plen = shader_open_shape ? uint32_t(sizeof(shader_prefix))-1u
                        : font_open_shape   ? uint32_t(sizeof(font_prefix))-1u
                                            : uint32_t(std::strlen(dyn_prefix));
    const char* host_dir = shader_open_shape ? "/shaders/"
                         : font_open_shape   ? "/Fonts/" : dyn_host;
    const long size_cap = shader_open_shape ? 65536
                        : font_open_shape   ? 4*1024*1024 : 64*1024*1024;
    char fname[80]{};
    if (len<=plen || len>=plen+64u) {
      cc_elog("NTCREATE reject len=%u plen=%u\n",len,plen);
      base.fail(Error::unsupported, address);
    }
    // The pak loader uppercases the whole path ("game:\GAME\LOGO.PAK") and
    // every observed open passes OBJ_CASE_INSENSITIVE, so the prefix match
    // is case-insensitive; the host/FATX filesystems resolve the filename
    // case-insensitively as the Xbox kernel would.
    auto lower=[](uint8_t chv){ return (chv>='A'&&chv<='Z')?uint8_t(chv+32u):chv; };
    for (uint32_t i=0;i<plen;++i)
      if (lower(uint8_t(base.load(buf+i,1)))!=lower(uint8_t(prefix[i]))) {
        char got[80]{};
        for (uint32_t j=0;j<len && j<79u;++j) got[j]=char(base.load(buf+j,1));
        cc_elog("NTCREATE reject prefix at %u path='%s'\n",i,got);
        base.fail(Error::unsupported, address);
      }
    for (uint32_t i=plen;i<len;++i) {
      const char chv=char(base.load(buf+i,1));
      if (!((chv>='A'&&chv<='Z')||(chv>='a'&&chv<='z')||(chv>='0'&&chv<='9')||chv=='.'||chv=='_')) {
        cc_elog("NTCREATE reject char 0x%02x at %u\n",uint8_t(chv),i);
        base.fail(Error::unsupported, address);
      }
      fname[i-plen]=chv;
    }
    if (!g_game_root[0]) {
      cc_elog("NTCREATE reject no game root\n");
      base.fail(Error::unsupported, address);
    }
    char host[360];
    std::snprintf(host,sizeof(host),"%s%s%s",g_game_root,host_dir,fname);
#ifdef CC_XBOX_DRIVER
    for (char* p=host; *p; ++p) if (*p=='/') *p='\\';
#endif
    std::FILE* f=nullptr;
#ifndef CC_XBOX_DRIVER
    // Port data overlay: files the port rewrites (e.g. the stripped sound
    // bank) live in game-data/converted/data/<folder>/ and take precedence.
    // The Xbox disc ships the rewritten files in place instead.
    {
      char port_root[300]{};
      if (const char* e = std::getenv("CC_PORT_DATA")) std::snprintf(port_root, sizeof(port_root), "%s", e);
      else {
        std::snprintf(port_root, sizeof(port_root), "%s", g_game_root);
        const size_t n = std::strlen(port_root);
        if (n >= 9 && !std::strcmp(port_root + n - 9, "extracted"))
          std::snprintf(port_root + n - 9, sizeof(port_root) - (n - 9), "converted/data");
        else port_root[0] = 0;
      }
      if (port_root[0] && std::strcmp(port_root, "none")) {
        char over[400];
        std::snprintf(over, sizeof(over), "%s%s%s", port_root, host_dir, fname);
        f = std::fopen(over, "rb");
        if (f) cc_log("port_data %s%c", over, 10);
      }
    }
#endif
    if (!f) f=std::fopen(host,"rb");
    if (!f) {
      // The sealed shader-name table requests SobelEdge.xpu (the container
      // ships SobelEdgePS.xpu) and VertexColorFillPS.xpu (absent from the
      // container entirely, per the sealed container manifest). The retail
      // game observes STATUS_OBJECT_NAME_NOT_FOUND for exactly these two and
      // continues. Any other miss is an environment problem and fails closed.
      if (std::strcmp(fname,"SobelEdge.xpu")!=0 &&
          std::strcmp(fname,"VertexColorFillPS.xpu")!=0) {
        cc_elog("NTCREATE miss name='%s' root='%s'\n",fname,g_game_root);
        base.fail(Error::unsupported, address);
      }
      ctx.r3.u64=0xC0000034u;
      return;
    }
    std::fseek(f,0,SEEK_END);
    const long sz=std::ftell(f);
    std::fseek(f,0,SEEK_SET);
    if (sz<=0 || sz>size_cap) {
      std::fclose(f);
      cc_elog("NTCREATE reject size name='%s' bytes=%ld cap=%ld\n",fname,sz,size_cap);
      base.fail(Error::unsupported, address);
    }
    slot->fp=f;
    slot->size=uint32_t(sz);
    if (pak_open_shape) cc_log("pak_open %s bytes=%ld\n",fname,sz);
    slot->open=true;
    slot->pos=0;
    slot->handle=0x0F11E001u+uint32_t(slot-&base.files[0]);
    base.store(handle_out,4,slot->handle);
    base.store(iosb+0,4,0u);
    base.store(iosb+4,4,1u); // FILE_OPENED
    ctx.r3.u64=0;
    return;
  }
  case 0x8214a5f4: {
    // NtSetInformationFile -" bounded to FilePositionInformation (class 14,
    // 8-byte LARGE_INTEGER) on the single open pak-fixture handle: the pak
    // loader seeks before each section read. Positions beyond EOF and every
    // other class stay fail-closed.
    const uint32_t iosb=ctx.r4.u32, info=ctx.r5.u32;
    auto* fsl=base.find_file(ctx.r3.u32);
    if (!fsl || ctx.r6.u32!=8u || ctx.r7.u32!=14u)
      base.fail(Error::unsupported, address);
    const uint64_t hi=base.load(info+0,4), lo=base.load(info+4,4);
    const uint64_t pos=(hi<<32)|lo;
    if (pos>fsl->size)
      base.fail(Error::unsupported, address);
    fsl->pos=uint32_t(pos);
    base.store(iosb+0,4,0u);
    base.store(iosb+4,4,0u);
    ctx.r3.u64=0u;
    return;
  }
  case 0x8214a624: {
    // NtQueryInformationFile ??? bounded to FileNetworkOpenInformation (class
    // 34, 56 bytes) on the single open shader-file fixture handle.
    const uint32_t iosb=ctx.r4.u32, buf=ctx.r5.u32;
    auto* fsl=base.find_file(ctx.r3.u32);
    if (!fsl)
      base.fail(Error::unsupported, address);
    // WIP 023: the pak loader also queries FilePositionInformation (class
    // 14, 8-byte LARGE_INTEGER) after seeking; report the fixture position.
    if (ctx.r6.u32==8u && ctx.r7.u32==14u) {
      base.store(buf,8,uint64_t(fsl->pos));
      base.store(iosb+0,4,0u);
      base.store(iosb+4,4,8u);
      ctx.r3.u64=0u;
      return;
    }
    if (ctx.r6.u32!=56u || ctx.r7.u32!=34u)
      base.fail(Error::unsupported, address);
    for (unsigned i=0;i<4;++i) base.store(buf+i*8u,8,0u); // four timestamps
    base.store(buf+32u,8,uint64_t(fsl->size)); // AllocationSize
    base.store(buf+40u,8,uint64_t(fsl->size)); // EndOfFile
    base.store(buf+48u,4,0x80u); // FILE_ATTRIBUTE_NORMAL
    base.store(buf+52u,4,0u);
    base.store(iosb+0,4,0u);
    base.store(iosb+4,4,56u);
    ctx.r3.u64=0;
    return;
  }
  case 0x8214a664: {
    // NtReadFile ??? bounded synchronous read of the single open shader-file
    // fixture from the current position (no event/APC/byte-offset observed).
    const uint32_t iosb=ctx.r7.u32, buf=ctx.r8.u32, len=ctx.r9.u32;
    // WIP 023 second observed read shape (sound loader, lr=0x820B6398):
    // ApcContext carries the IOSB pointer and an explicit 8-byte BE byte
    // offset may be supplied through the trailing pointer argument.
    const bool plain_shape = ctx.r6.u32==0u && ctx.r10.u32==0u;
    const bool apcctx_shape = ctx.r6.u32==iosb;
    auto* fsl=base.find_file(ctx.r3.u32);
    if (!fsl || ctx.r4.u32!=0u ||
        ctx.r5.u32!=0u || (!plain_shape && !apcctx_shape) ||
        fsl->pos>fsl->size)
      base.fail(Error::unsupported, address);
    if (apcctx_shape && ctx.r10.u32!=0u) {
      const uint64_t off=base.load(ctx.r10.u32,8);
      if (off>fsl->size) base.fail(Error::unsupported, address);
      fsl->pos=uint32_t(off);
    }
    const uint32_t avail=fsl->size-fsl->pos;
    const uint32_t take=len<avail?len:avail;
    if (take && std::fseek(fsl->fp,long(fsl->pos),SEEK_SET)!=0)
      base.fail(Error::unsupported, address);
    static uint8_t chunk[65536];
    for (uint32_t done=0; done<take; ) {
      const uint32_t n=(take-done)<uint32_t(sizeof(chunk))?(take-done):uint32_t(sizeof(chunk));
      if (std::fread(chunk,1,n,fsl->fp)!=n) base.fail(Error::unsupported, address);
      for (uint32_t i=0;i<n;++i) base.store(buf+done+i,1,chunk[i]);
      done+=n;
    }
    fsl->pos+=take;
    base.store(iosb+0,4,take?0u:0xC0000011u); // STATUS_END_OF_FILE when empty
    base.store(iosb+4,4,take);
    ctx.r3.u64=take?0u:0xC0000011u;
    return;
  }
  case 0x8214a584: {
    // NtClose ??? bounded to the single open shader-file fixture handle.
    auto* fsl=base.find_file(ctx.r3.u32);
    if (!fsl)
      base.fail(Error::unsupported, address);
    fsl->open=false;
    fsl->handle=0;
    fsl->pos=0;
    fsl->size=0;
    if (fsl->fp) { std::fclose(fsl->fp); fsl->fp=nullptr; }
    ctx.r3.u64=0;
    return;
  }
  case 0x820a89f8: {
    if (g_use_exact_texture_bind) { sub_820A89F8(ctx, base); return; }
    const uint32_t obj = ctx.r3.u32, desc = ctx.r4.u32;
    if (obj > 0xffff89efu || desc > 0xffffffafu)
      base.fail(Error::context, address);
    const uint32_t ix = uint32_t(base.load(obj + 30208, 4));
    if (ix >= 8)
      base.fail(Error::context, address);
    const uint32_t shader =
        uint32_t(base.load(uint32_t(base.load(obj + 30176 + ix * 4, 4)), 4));
    if (shader != 0 && shader != 5)
      base.fail(Error::context, address);
    uint32_t words[20];
    for (unsigned i = 0; i < 20; ++i)
      words[i] = uint32_t(base.load(desc + i * 4, 4));
    if (!words[4] || !words[5] || words[4] > 4096 || words[5] > 4096 ||
        (words[6] != 1 && words[6] != 5))
      base.fail(Error::texture, desc);
    if (!base.sink.bind || !base.sink.bind(base.sink.user, desc, words))
      base.fail(Error::texture, desc);
    ++base.result.bind_calls;
    return;
  }
  case 0x820a9308: {
    if (g_use_exact_texture_bind) { sub_820A9308(ctx, base); return; }
    ++base.result.quad_calls;
    unsigned emitted = 0;
    const auto e =
        cc::quad::invoke(address, ctx, base.memory, {&base, submit}, &emitted);
    if (e != cc::quad::Error::ok) {
      base.result.quad_error = uint32_t(e);
      base.fail(Error::quad, address);
    }
    return;
  }
  default:
    base.fail(Error::dispatch, address);
  }
}
static void dispatch(uint32_t a, Context &c, Machine &m) {
  if (++m.depth > 64)
    m.fail(Error::capacity, a);
  if (m.depth > m.result.deepest_dispatch)
    m.result.deepest_dispatch = m.depth;
  dispatch_impl(a, c, m);
  --m.depth;
}
// setjmp lives in a separate function; modified Machine/Context storage belongs
// to the caller, not to this setjmp frame. Generated callees are scalar/trivial
// and create no nontrivial automatic objects across a longjmp. FloatScope is
// outside this frame and always restores host FP controls normally.
static void execute(uint32_t entry, Context &ctx, Machine &m) {
  if (setjmp(m.escape))
    return;
  if (entry == 0x8208a7a0)
    m.validate_list(ctx.r3.u32);
  if (entry == 0x82091248)
    m.validate_owner(ctx.r3.u32);
  if(entry==0x8209ce40 || entry==0x8209ce48) {
    if(ctx.r3.u32>0xffffffe7u) m.fail(Error::context,ctx.r3.u32);
  }
  switch (entry) {
  case 0x820701d0: sub_820701D0_startup_full(ctx,m); break;
  case 0x820b7880: sub_820B7880(ctx,m); break;
  case 0x8212a630: sub_8212A630(ctx,m); break;
  case 0x82127e48: sub_82127E48(ctx,m); break;
  case 0x820b7730: sub_820B7730(ctx,m); break;
  case 0x820b7650: sub_820B7650(ctx,m); break;
  case 0x82070ba4: sub_82070AC8_post_init(ctx,m); break;
  case 0x82070ac8: sub_82070AC8_renderer_prefix(ctx,m); break;
  case 0x820a7990: sub_820A7990_platform_prefix(ctx,m); break;
  case 0x820a7b34: sub_820A7990_platform_post_graphics(ctx,m); break;
  case 0x820befd0: sub_820BEFD0(ctx,m); break;
  case 0x820c2c98: sub_820C2C98(ctx,m); break;
  case 0x820c13b8: sub_820C13B8(ctx,m); break;
  case 0x82070434: sub_820701D0_manager_slice(ctx,m); break;
  case 0x8209cc98: sub_8209CC98(ctx,m); break;
  case 0x8209de50: sub_8209DE50(ctx,m); break;
  case 0x82097720: sub_82097720(ctx,m); break;
  case 0x820915f0: sub_820915F0(ctx,m); break;
  case 0x820a1ac0: sub_820A1AC0(ctx,m); break;
  case 0x8209ce40: sub_8209CE40(ctx,m); break;
  case 0x8209ce48: sub_8209CE48(ctx,m); break;
  case 0x8209cd08: sub_8209CD08(ctx,m); break;
  case 0x8209df48: sub_8209DF48(ctx,m); break;
  case 0x8208a7a0:
    sub_8208A7A0(ctx, m);
    break;
  case 0x82091248:
    sub_82091248(ctx, m);
    break;
  case 0x820a8ff8:
    sub_820A8FF8(ctx, m);
    break;
  default:
    m.fail(Error::entry, entry);
  }
}
Result invoke(uint32_t entry, Context &ctx, AddressSpace &memory, Sink sink,
              uint32_t budget) noexcept {
  Result error;
  if (entry != 0x820b7730 && entry != 0x820b7650 && entry != 0x82127e48 && entry != 0x8212a630 && entry != 0x820c13b8 && entry != 0x820c2c98 && entry != 0x820befd0 && entry != 0x820a7b34 && entry != 0x820a7990 && entry != 0x82070ac8 && entry != 0x820701d0 && entry != 0x820b7880 && entry != 0x82070ba4 && entry != 0x82070434 && entry != 0x8208a7a0 && entry != 0x820a8ff8 && entry != 0x82091248 && entry != 0x8209cd08 && entry != 0x8209cc98 && entry != 0x8209de50 && entry != 0x82097720 && entry != 0x820915f0 && entry != 0x8209df48 && entry != 0x820a1ac0 && entry != 0x8209ce40 && entry != 0x8209ce48) {
    error.error = Error::entry;
    return error;
  }
  if (!sink.submit || !sink.bind || ctx.r1.u64 < 16384 ||
      ctx.r1.u64 > 0xffffff7f || budget < 1) {
    error.error = Error::context;
    return error;
  }
  if (memory.check(ctx.r1.u32 - 512, 640, 3) != cc::xbox::MemoryError::ok) {
    error.error = Error::memory;
    return error;
  }
  Machine m(memory, sink);
  m.budget = budget;
  FloatScope fp;
  execute(entry, ctx, m);
  return m.result;
}
const char *name(Error e) noexcept {
  switch (e) {
#define E(x)                                                                   \
  case Error::x:                                                               \
    return #x;
    E(ok)
    E(entry)
    E(context) E(memory) E(dispatch) E(texture) E(quad) E(sink) E(capacity)
        E(unsupported) E(cycle)
#undef E
  }
  return "unknown";
}
} // namespace cc::tree
