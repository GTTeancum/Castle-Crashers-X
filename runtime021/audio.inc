// SPDX-License-Identifier: MIT
// ---- Port audio: PlatformAudio replacement ---------------------------------
// The 360 game's PlatformAudio layer loads each sound effect / song as a
// whole XMA file and plays it on XAudio voices decoded by the XMA hardware.
// The original Xbox has no XMA decoder, so the port replaces the layer's
// functions with its own, playing Xbox ADPCM converted offline by
// tools/convert_audio.py:
//   <audio root>/sfx.xab           effects by name (loaded on register)
//   <audio root>/music/<name>.xad  songs (streamed from disc)
// and mixing in software to 48 kHz stereo (AC97 output on the Xbox; on the
// host, CC_AUDIO_WAV=<file> records the session).
//
// Contracts kept (callers are exact code; layout from the game's manager):
//   table = PlatformAudio table (manager [0x8225E62C] + 4):
//     +0      u32 object[512]      effect slots, +2048 u32 object[64] songs
//     +2304   256 x {u32 voice, u32 object, u32 unused}
//     +5376   u32 pointer to the music voice's entry
//     +5380   u8  user-music mute flag, +5384 f32 music volume
//   results are {u32 code, u32 0}: 0 ok, 1 failure.
// Objects and voices stored in guest memory are port handles:
//   0xA0F00000 | effect object, 0xA0E00000 | song id, 0xA0D00000 | voice.

namespace ccaudio {

constexpr uint32_t kObjTag = 0xA0F00000u, kSongTag = 0xA0E00000u, kVoiceTag = 0xA0D00000u;
constexpr uint32_t kTagMask = 0xFFF00000u;
constexpr int kOutRate = 48000;
constexpr int kSpb = 64, kBlock = 36;

// Effects are registered from the bank index only; their ADPCM data is read
// from the hard drive on first play and kept in a small LRU cache.
struct Sound {
  bool used = false; char name[32] = {};
  uint32_t rate = 0, samples = 0, offset = 0, bytes = 0, last_use = 0;
  std::vector<uint8_t> data;  // empty while not resident
};
struct Song { bool used = false; char file[64] = {}; };
struct Voice {
  bool active = false, loop = false, music = false;
  uint32_t object = 0;           // guest object handle
  float vol = 1.0f, left = 1.0f, right = 1.0f;
  // Effects: decoded from Sound::data. Songs: streamed from `stream`.
  int sound = -1;
  std::FILE* stream = nullptr;
  uint32_t rate = 0, channels = 1, samples = 0, data_start = 0;
  double pos = 0.0;               // source sample position
  uint32_t cached_block = 0xFFFFFFFFu;
  int16_t cache[2][kSpb] = {};
};

struct State {
  bool index_loaded = false;
  std::vector<uint8_t> index;     // sfx.xab header + table
  std::vector<Sound> sounds = std::vector<Sound>(512);
  Song songs[64];
  Voice voices[256];
  std::FILE* wav = nullptr;
  uint32_t wav_frames = 0;
};
static State g;

static void audio_root(char* out, size_t n) {
#ifdef CC_XBOX_DRIVER
  std::snprintf(out, n, "%s\\audio", g_game_root);
#else
  if (const char* e = std::getenv("CC_AUDIO_ROOT")) { std::snprintf(out, n, "%s", e); return; }
  std::snprintf(out, n, "%s", g_game_root);
  const size_t len = std::strlen(out);
  if (len >= 9 && !std::strcmp(out + len - 9, "extracted"))
    std::snprintf(out + len - 9, n - (len - 9), "converted/audio");
#endif
}

static uint32_t rd32(const uint8_t* p) { return uint32_t(p[0]) | uint32_t(p[1]) << 8 | uint32_t(p[2]) << 16 | uint32_t(p[3]) << 24; }

static bool load_index() {
  if (g.index_loaded) return !g.index.empty();
  g.index_loaded = true;
  char root[300], path[340];
  audio_root(root, sizeof(root));
  std::snprintf(path, sizeof(path), "%s/sfx.xab", root);
#ifdef CC_XBOX_DRIVER
  for (char* p = path; *p; ++p) if (*p == '/') *p = '\\';
#endif
  std::FILE* f = std::fopen(path, "rb");
  if (!f) { cc_elog("AUDIO no effect bank at %s\n", path); return false; }
  uint8_t head[8];
  if (std::fread(head, 1, 8, f) == 8 && !std::memcmp(head, "XAB2", 4)) {
    const uint32_t count = rd32(head + 4);
    g.index.resize(8 + size_t(count) * 52);
    std::memcpy(g.index.data(), head, 8);
    if (std::fread(g.index.data() + 8, 1, size_t(count) * 52, f) != size_t(count) * 52) g.index.clear();
  }
  std::fclose(f);
  return !g.index.empty();
}

// Guest string object: u32 length, then the characters at +4.
static void guest_name(Machine& base, uint32_t str, char* out, size_t n) {
  size_t i = 0;
  for (; i + 1 < n; ++i) {
    uint64_t c = 0;
    if (base.memory.load_be(str + 4u + uint32_t(i), 1, c) != cc::xbox::MemoryError::ok || !c) break;
    out[i] = char(c);
  }
  out[i] = 0;
}
static void lower_stem(char* s) {
  for (char* p = s; *p; ++p) {
    if (*p == '.') { *p = 0; break; }
    if (*p >= 'A' && *p <= 'Z') *p = char(*p + 32);
  }
}

static uint64_t g_sfx_bytes = 0;
static uint32_t g_sfx_clock = 0, g_sfx_loads = 0;
static uint64_t sfx_cache_limit() {
#ifndef CC_XBOX_DRIVER
  static uint64_t lim = 0;
  if (!lim) { const char* e = std::getenv("CC_SFX_CACHE_KB"); lim = uint64_t(e ? std::strtoul(e, nullptr, 10) : 2048u) << 10; }
  return lim;
#else
  return uint64_t(2048u) << 10;
#endif
}

// Register one effect from the bank index; returns its sound index or -1.
static int load_sound(const char* stem) {
  if (!load_index()) return -1;
  const uint32_t count = rd32(g.index.data() + 4);
  for (uint32_t i = 0; i < count; ++i) {
    const uint8_t* e = g.index.data() + 8 + size_t(i) * 52;
    if (std::strncmp(reinterpret_cast<const char*>(e), stem, 32)) continue;
    int slot = -1;
    for (size_t k = 0; k < g.sounds.size(); ++k) if (!g.sounds[k].used) { slot = int(k); break; }
    if (slot < 0) return -1;
    Sound& s = g.sounds[size_t(slot)];
    s = Sound();
    s.used = true;
    std::snprintf(s.name, sizeof(s.name), "%s", stem);
    s.rate = rd32(e + 32);
    s.samples = rd32(e + 40);
    s.offset = rd32(e + 44);
    s.bytes = rd32(e + 48);
    return slot;
  }
  return -1;
}

static bool sound_playing(int k) {
  for (const Voice& v : g.voices) if (v.active && !v.music && v.sound == k) return true;
  return false;
}

// Make an effect's data resident, evicting least recently played effects
// that are not playing until the cache fits.
static bool make_resident(int k) {
  Sound& s = g.sounds[size_t(k)];
  s.last_use = ++g_sfx_clock;
  if (!s.data.empty()) return true;
  static std::FILE* bank = nullptr;
  if (!bank) {
    char root[300], path[340];
    audio_root(root, sizeof(root));
    std::snprintf(path, sizeof(path), "%s/sfx.xab", root);
#ifdef CC_XBOX_DRIVER
    for (char* p = path; *p; ++p) if (*p == '/') *p = '\\';
#endif
    bank = std::fopen(path, "rb");
    if (!bank) return false;
  }
  s.data.resize(s.bytes);
  if (std::fseek(bank, long(s.offset), SEEK_SET) != 0 ||
      std::fread(s.data.data(), 1, s.data.size(), bank) != s.data.size()) {
    s.data.clear();
    return false;
  }
  g_sfx_bytes += s.bytes;
  ++g_sfx_loads;
  while (g_sfx_bytes > sfx_cache_limit()) {
    int victim = -1;
    for (size_t j = 0; j < g.sounds.size(); ++j) {
      const Sound& c = g.sounds[j];
      if (!c.used || c.data.empty() || int(j) == k || sound_playing(int(j))) continue;
      if (victim < 0 || c.last_use < g.sounds[size_t(victim)].last_use) victim = int(j);
    }
    if (victim < 0) break;
    g_sfx_bytes -= g.sounds[size_t(victim)].data.size();
    std::vector<uint8_t>().swap(g.sounds[size_t(victim)].data);
  }
  return true;
}

static void decode_block(const uint8_t* blk, int16_t* out) {
  static const int step_tab[89] = {
      7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23, 25, 28, 31, 34, 37, 41, 45,
      50, 55, 60, 66, 73, 80, 88, 97, 107, 118, 130, 143, 157, 173, 190, 209, 230,
      253, 279, 307, 337, 371, 408, 449, 494, 544, 598, 658, 724, 796, 876, 963,
      1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066, 2272, 2499, 2749, 3024, 3327,
      3660, 4026, 4428, 4871, 5358, 5894, 6484, 7132, 7845, 8630, 9493, 10442,
      11487, 12635, 13899, 15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794,
      32767};
  static const int adj[8] = {-1, -1, -1, -1, 2, 4, 6, 8};
  int pred = int16_t(blk[0] | blk[1] << 8), idx = blk[2] > 88 ? 88 : blk[2];
  out[0] = int16_t(pred);
  for (int i = 1; i < kSpb; ++i) {
    const int code = (blk[4 + (i - 1) / 2] >> (((i - 1) & 1) * 4)) & 15;
    const int step = step_tab[idx];
    int diff = step >> 3;
    if (code & 4) diff += step;
    if (code & 2) diff += step >> 1;
    if (code & 1) diff += step >> 2;
    pred += (code & 8) ? -diff : diff;
    pred = pred < -32768 ? -32768 : (pred > 32767 ? 32767 : pred);
    idx += adj[code & 7];
    idx = idx < 0 ? 0 : (idx > 88 ? 88 : idx);
    out[i] = int16_t(pred);
  }
}

// Source sample `s` of channel `c`, decoding (and for songs reading) the
// containing block on demand.
static int sample_at(Voice& v, uint32_t s, uint32_t c) {
  if (s >= v.samples) return 0;
  const uint32_t block = s / kSpb;
  if (block != v.cached_block) {
    uint8_t raw[2 * kBlock];
    const size_t bytes = size_t(kBlock) * v.channels;
    if (v.music) {
      if (!v.stream || std::fseek(v.stream, long(v.data_start + block * bytes), SEEK_SET) ||
          std::fread(raw, 1, bytes, v.stream) != bytes) return 0;
    } else {
      const Sound& snd = g.sounds[size_t(v.sound)];
      if ((block + 1) * bytes > snd.data.size()) return 0;
      std::memcpy(raw, snd.data.data() + block * bytes, bytes);
    }
    for (uint32_t ch = 0; ch < v.channels; ++ch) decode_block(raw + ch * kBlock, v.cache[ch]);
    v.cached_block = block;
  }
  return v.cache[c][s % kSpb];
}

static void stop_voice(Voice& v) {
  v.active = false;
  if (v.stream) { std::fclose(v.stream); v.stream = nullptr; }
}

static int free_entry(Machine& base, uint32_t table) {
  for (int i = 0; i < 256; ++i)
    if (!base.load(table + 2304u + uint32_t(i) * 12u, 4)) return i;
  return -1;
}

static float f32_of(uint64_t bits) { float f; const uint32_t b = uint32_t(bits); std::memcpy(&f, &b, 4); return f; }
static uint32_t bits_of(float f) { uint32_t b; std::memcpy(&b, &f, 4); return b; }

static void set_pan(Voice& v, float pan) {
  v.left = 1.0f - pan > 1.0f ? 1.0f : 1.0f - pan;
  v.right = 1.0f + pan > 1.0f ? 1.0f : 1.0f + pan;
}

static void result(Machine& base, uint32_t out, uint32_t code) {
  base.store(out + 0u, 4, code);
  base.store(out + 4u, 4, 0u);
}

// Mix one frame's worth of output (48 kHz / 60) and hand it to the backend.
static uint32_t g_mixed_frames = 0;
static void mix_frame() {
  constexpr int n = kOutRate / 60;
  ++g_mixed_frames;
  static int32_t acc[n * 2];
  std::memset(acc, 0, sizeof(acc));
  for (Voice& v : g.voices) {
    if (!v.active) continue;
    const double step = double(v.rate) / kOutRate;
    for (int i = 0; i < n; ++i) {
      if (v.pos >= v.samples) {
        if (v.loop && v.samples) v.pos -= v.samples;
        else { stop_voice(v); break; }
      }
      const uint32_t s0 = uint32_t(v.pos);
      const double t = v.pos - s0;
      for (uint32_t c = 0; c < 2; ++c) {
        const uint32_t sc = v.channels == 2 ? c : 0;
        const uint32_t s1 = s0 + 1 < v.samples ? s0 + 1 : (v.loop ? 0 : s0);
        const double a = sample_at(v, s0, sc), b = sample_at(v, s1, sc);
        acc[i * 2 + int(c)] += int32_t((a + (b - a) * t) * v.vol * (c ? v.right : v.left));
      }
      v.pos += step;
    }
  }
  static int16_t out[n * 2];
  for (int i = 0; i < n * 2; ++i) out[i] = int16_t(acc[i] < -32768 ? -32768 : (acc[i] > 32767 ? 32767 : acc[i]));
#ifdef CC_XBOX_DRIVER
  ::cc_xbox_audio_submit(out, n);
#else
  static bool tried = false;
  if (!tried) {
    tried = true;
    if (const char* p = std::getenv("CC_AUDIO_WAV")) {
      g.wav = std::fopen(p, "wb");
      if (g.wav) { uint8_t hdr[44] = {}; std::fwrite(hdr, 1, 44, g.wav); }
    }
  }
  if (g.wav) {
    std::fwrite(out, 2, size_t(n) * 2, g.wav);
    g.wav_frames += n;
    // Keep the RIFF header current so the file is valid at any point.
    const uint32_t data = g.wav_frames * 4u;
    uint8_t h[44];
    std::memcpy(h, "RIFF", 4); const uint32_t riff = 36 + data; std::memcpy(h + 4, &riff, 4);
    std::memcpy(h + 8, "WAVEfmt ", 8); const uint32_t fl = 16; std::memcpy(h + 16, &fl, 4);
    const uint16_t pcm = 1, ch = 2, bits = 16, align = 4; const uint32_t rate = kOutRate, bps = kOutRate * 4;
    std::memcpy(h + 20, &pcm, 2); std::memcpy(h + 22, &ch, 2); std::memcpy(h + 24, &rate, 4);
    std::memcpy(h + 28, &bps, 4); std::memcpy(h + 32, &align, 2); std::memcpy(h + 34, &bits, 2);
    std::memcpy(h + 36, "data", 4); std::memcpy(h + 40, &data, 4);
    const long end = std::ftell(g.wav);
    std::fseek(g.wav, 0, SEEK_SET); std::fwrite(h, 1, 44, g.wav); std::fseek(g.wav, end, SEEK_SET);
  }
#endif
}

static Voice* port_voice(uint32_t handle) {
  if ((handle & kTagMask) != kVoiceTag || (handle & 0xFFFFFu) >= 256u) return nullptr;
  return &g.voices[handle & 0xFFFFFu];
}

}  // namespace ccaudio

// RegisterSound(out r3, table r4, slot r5, name r6)
static void sub_8209EFF0(Context& ctx, Machine& base);
static void sub_8209EA18(Context& ctx, Machine& base) {
  const uint32_t out = ctx.r3.u32, table = ctx.r4.u32, slot = ctx.r5.u32 & 0xFFFFu;
  if (slot >= 512u) { ccaudio::result(base, out, 1u); return; }
  if (base.load(table + slot * 4u, 4)) {
    Context c = ctx; c.r3.u64 = out; c.r4.u64 = table; c.r5.u64 = slot;
    sub_8209EFF0(c, base);
  }
  char name[64];
  ccaudio::guest_name(base, ctx.r6.u32, name, sizeof(name));
  ccaudio::lower_stem(name);
  const int s = ccaudio::load_sound(name);
  if (s < 0) {
    cc_elog("AUDIO effect '%s' not in the bank\n", name);
    ccaudio::result(base, out, 1u);
    ctx.r3.u64 = out;
    return;
  }
  base.store(table + slot * 4u, 4, ccaudio::kObjTag | uint32_t(s));
  ccaudio::result(base, out, 0u);
  ctx.r3.u64 = out;
}

// RegisterMusic(out r3, table r4, id r5, path r6)
static void sub_8209ED28(Context& ctx, Machine& base) {
  const uint32_t out = ctx.r3.u32, table = ctx.r4.u32, id = ctx.r5.u32 & 0xFFFFu;
  ctx.r3.u64 = out;
  if (id >= 64u || base.load(table + (512u + id) * 4u, 4)) { ccaudio::result(base, out, 1u); return; }
  char path[96];
  ccaudio::guest_name(base, ctx.r6.u32, path, sizeof(path));
  const char* file = path;
  for (const char* p = path; *p; ++p) if (*p == '/' || *p == '\\') file = p + 1;
  char stem[64];
  std::snprintf(stem, sizeof(stem), "%s", file);
  for (char* p = stem; *p; ++p) if (*p == '.') { *p = 0; break; }
  ccaudio::Song& s = ccaudio::g.songs[id];
  s.used = true;
  std::snprintf(s.file, sizeof(s.file), "%s", stem);
  base.store(table + (512u + id) * 4u, 4, ccaudio::kSongTag | id);
  ccaudio::result(base, out, 0u);
}

// ClearSound(out r3, table r4, slot r5)
static void sub_8209EFF0(Context& ctx, Machine& base) {
  const uint32_t out = ctx.r3.u32, table = ctx.r4.u32, slot = ctx.r5.u32 & 0xFFFFu;
  ctx.r3.u64 = out;
  const uint32_t obj = slot < 512u ? uint32_t(base.load(table + slot * 4u, 4)) : 0u;
  if (!obj) { ccaudio::result(base, out, 1u); return; }
  for (uint32_t i = 0; i < 256u; ++i) {
    const uint32_t e = table + 2304u + i * 12u;
    if (uint32_t(base.load(e + 4u, 4)) != obj) continue;
    if (ccaudio::Voice* v = ccaudio::port_voice(uint32_t(base.load(e, 4)))) ccaudio::stop_voice(*v);
    base.store(e, 4, 0u); base.store(e + 4u, 4, 0u);
  }
  if ((obj & ccaudio::kTagMask) == ccaudio::kObjTag) {
    ccaudio::Sound& s = ccaudio::g.sounds[obj & 0xFFFFFu];
    ccaudio::g_sfx_bytes -= s.data.size();
    s = ccaudio::Sound();
  }
  base.store(table + slot * 4u, 4, 0u);
  ccaudio::result(base, out, 0u);
}

// PlaySound(table r3, slot r4, vol f1, pan f2, loop r7) -> s16 entry or -1
static void sub_8209F118(Context& ctx, Machine& base) {
  const uint32_t table = ctx.r3.u32, slot = ctx.r4.u32 & 0xFFFFu;
  const uint32_t obj = slot < 512u ? uint32_t(base.load(table + slot * 4u, 4)) : 0u;
  const int entry = ccaudio::free_entry(base, table);
  if ((obj & ccaudio::kTagMask) != ccaudio::kObjTag || entry < 0) { ctx.r3.s64 = -1; return; }
  if (!ccaudio::make_resident(int(obj & 0xFFFFFu))) { ctx.r3.s64 = -1; return; }
  const ccaudio::Sound& s = ccaudio::g.sounds[obj & 0xFFFFFu];
  ccaudio::Voice& v = ccaudio::g.voices[entry];
  ccaudio::stop_voice(v);
  v = ccaudio::Voice();
  v.active = true; v.object = obj; v.sound = int(obj & 0xFFFFFu);
  v.rate = s.rate; v.channels = 1; v.samples = s.samples;
  v.loop = (ctx.r7.u32 & 0xFFu) != 0;
  v.vol = float(ctx.f1.f64);
  const float pan = float(ctx.f2.f64);
  if (pan != 0.0f) ccaudio::set_pan(v, pan);
  const uint32_t e = table + 2304u + uint32_t(entry) * 12u;
  base.store(e, 4, ccaudio::kVoiceTag | uint32_t(entry));
  base.store(e + 4u, 4, obj);
  ctx.r3.s64 = entry;
}

// PlayMusic(out r3, table r4, id r5, vol f1, loop r7)
static void sub_8209F518(Context& ctx, Machine& base) {
  const uint32_t out = ctx.r3.u32, table = ctx.r4.u32, id = ctx.r5.u32 & 0xFFFFu;
  ctx.r3.u64 = out;
  const uint32_t cur = uint32_t(base.load(table + 5376u, 4));
  if (cur)
    if (ccaudio::Voice* v = ccaudio::port_voice(uint32_t(base.load(cur, 4)))) ccaudio::stop_voice(*v);
  const int entry = ccaudio::free_entry(base, table);
  if (id >= 64u || !ccaudio::g.songs[id].used || entry < 0) { ccaudio::result(base, out, 1u); return; }
  char root[300], path[400];
  ccaudio::audio_root(root, sizeof(root));
  std::snprintf(path, sizeof(path), "%s/music/%s.xad", root, ccaudio::g.songs[id].file);
#ifdef CC_XBOX_DRIVER
  for (char* p = path; *p; ++p) if (*p == '/') *p = '\\';
#endif
  std::FILE* f = std::fopen(path, "rb");
  uint8_t h[16];
  if (!f || std::fread(h, 1, 16, f) != 16 || std::memcmp(h, "XAD1", 4)) {
    if (f) std::fclose(f);
    cc_elog("AUDIO song '%s' missing\n", path);
    ccaudio::result(base, out, 1u);
    return;
  }
  ccaudio::Voice& v = ccaudio::g.voices[entry];
  ccaudio::stop_voice(v);
  v = ccaudio::Voice();
  v.active = true; v.music = true; v.stream = f; v.data_start = 16;
  v.rate = ccaudio::rd32(h + 4); v.channels = ccaudio::rd32(h + 8); v.samples = ccaudio::rd32(h + 12);
  v.loop = (ctx.r7.u32 & 0xFFu) != 0;
  v.object = ccaudio::kSongTag | id;
  const float vol = float(ctx.f1.f64);
  v.vol = base.load(table + 5380u, 1) ? 0.0f : vol;
  const uint32_t e = table + 2304u + uint32_t(entry) * 12u;
  base.store(e, 4, ccaudio::kVoiceTag | uint32_t(entry));
  base.store(e + 4u, 4, v.object);
  base.store(table + 5376u, 4, e);
  base.store(table + 5384u, 4, ccaudio::bits_of(vol));
  ccaudio::result(base, out, 0u);
}

// Update(table r3): release finished voices; the original Xbox has no
// user soundtrack playing over the game, so the music is never muted.
static void sub_8209E928(Context& ctx, Machine& base) {
  const uint32_t table = ctx.r3.u32;
  const uint32_t music = uint32_t(base.load(table + 5376u, 4));
  for (uint32_t i = 0; i < 256u; ++i) {
    const uint32_t e = table + 2304u + i * 12u;
    const uint32_t h = uint32_t(base.load(e, 4));
    ccaudio::Voice* v = ccaudio::port_voice(h);
    if (!v || v->active) continue;
    base.store(e, 4, 0u); base.store(e + 4u, 4, 0u);
    if (music == e) base.store(table + 5376u, 4, 0u);
  }
  base.store(table + 5380u, 1, 0u);
  const uint32_t m = uint32_t(base.load(table + 5376u, 4));
  if (m)
    if (ccaudio::Voice* v = ccaudio::port_voice(uint32_t(base.load(m, 4))))
      v->vol = ccaudio::f32_of(base.load(table + 5384u, 4));
}

// SetVolumePan(out r3, table r4, entry r5 s16, vol f1, pan f2)
static void sub_8209F400(Context& ctx, Machine& base) {
  const uint32_t out = ctx.r3.u32, table = ctx.r4.u32;
  const int idx = int16_t(ctx.r5.u16);
  ctx.r3.u64 = out;
  if (idx < 0 || idx > 255) { ccaudio::result(base, out, 1u); return; }
  if (ccaudio::Voice* v = ccaudio::port_voice(uint32_t(base.load(table + 2304u + uint32_t(idx) * 12u, 4)))) {
    v->vol = float(ctx.f1.f64);
    const float pan = float(ctx.f2.f64);
    if (pan != 0.0f) ccaudio::set_pan(*v, pan);
  }
  ccaudio::result(base, out, 0u);
}

static void cc_audio_frame() { ccaudio::mix_frame(); }
static uint32_t cc_audio_active_voices() {
  uint32_t n = 0;
  for (const auto& v : ccaudio::g.voices) n += v.active ? 1u : 0u;
  return n;
}
static uint32_t cc_audio_mixed_frames() { return ccaudio::g_mixed_frames; }
static uint32_t cc_audio_loaded_bytes() {
  uint32_t n = 0;
  for (const auto& s : ccaudio::g.sounds) n += uint32_t(s.data.size());
  return n;
}
static bool cc_audio_set_volume(uint32_t voice, float vol) {
  ccaudio::Voice* v = ccaudio::port_voice(voice);
  if (!v) return false;
  v->vol = vol;
  return true;
}
static bool cc_audio_stop(uint32_t voice) {
  ccaudio::Voice* v = ccaudio::port_voice(voice);
  if (!v) return false;
  ccaudio::stop_voice(*v);
  return true;
}
