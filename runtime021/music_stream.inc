// SPDX-License-Identifier: MIT
// Music streaming on the Xbox (included by audio.inc inside namespace
// ccaudio, after the voice helpers).
//
// The mixer runs on the audio thread and must never wait for the disk: a
// music read issued from the mixer queued behind the texture pack's large
// reads (up to ~50 ms on the book menu, which reloads ~9 textures a second)
// and the ~33 ms output queue ran dry (music stutter, 2026-10-17). Here a
// reader thread keeps a ring of the playing song's ADPCM blocks filled ahead
// of the mixer (1024 blocks, ~1.5 s at 44.1 kHz), in play order: block
// numbers are a sequence that keeps counting across loop passes, so a
// looping song's start is read ahead of its end. The mixer only takes
// blocks from the ring; one that has not arrived plays as silence and is
// counted (cc_audio_music_starved). File handles belong to the reader
// thread; the mixer and the game thread only set what to play, under the
// mixer's lock. The host keeps the direct reads in block_bytes.
#ifdef CC_XBOX_DRIVER
constexpr uint32_t kRingBlocks = 1024;
constexpr uint32_t kRingSlotBytes = 2u * kBlock;  // a stereo block
struct MusicStream {
  uint32_t gen = 0;          // bumped by every start and stop: the reader drops stale work
  bool want = false;         // a song is playing
  char path[400] = {};
  uint32_t data_start = 16, block_bytes = 0, total = 0;  // blocks in the song
  bool loop = false;
  uint64_t consumer = 0;     // lowest sequence the mixer may still need
  uint64_t tag[kRingBlocks]; // sequence each slot holds
  uint8_t ring[kRingBlocks * kRingSlotBytes];
  uint32_t starved = 0;      // blocks the mixer needed before they arrived
};
static MusicStream g_music;
static bool g_music_reader_started = false;

static DWORD WINAPI music_reader(LPVOID) {
  std::FILE* f = nullptr;
  uint32_t f_gen = 0xFFFFFFFFu;
  uint64_t fill = 0;                       // next sequence to read
  uint64_t file_seq = ~0ull;               // sequence the file position is at
  static uint8_t buf[256 * kRingSlotBytes];
  for (;;) {
    cc_xbox_audio_lock();
    const uint32_t gen = g_music.gen;
    const bool want = g_music.want, loop = g_music.loop;
    char path[400];
    std::memcpy(path, g_music.path, sizeof(path));
    const uint32_t ds = g_music.data_start, bb = g_music.block_bytes, total = g_music.total;
    const uint64_t consumer = g_music.consumer;
    cc_xbox_audio_unlock();
    if (gen != f_gen) {
      if (f) { std::fclose(f); f = nullptr; }
      f_gen = gen;
      fill = 0;
      file_seq = ~0ull;
      if (want) {
        f = std::fopen(path, "rb");
        if (!f) ::DbgPrint("FAIL music: cannot open %s\n", path);
      }
    }
    uint32_t n = 0;
    if (f && total && bb && bb <= kRingSlotBytes) {
      const uint64_t limit = consumer + kRingBlocks - 8u;
      if (fill < limit && (loop || fill < total)) {
        const uint32_t block = uint32_t(fill % total);
        uint64_t want_n = limit - fill;
        if (want_n > 256u) want_n = 256u;
        if (want_n > total - block) want_n = total - block;  // not across the loop point
        if (file_seq != fill) std::fseek(f, long(ds + uint64_t(block) * bb), SEEK_SET);
        n = uint32_t(std::fread(buf, bb, size_t(want_n), f));
        file_seq = (n && block + n < total) ? fill + n : ~0ull;
        if (!n) ::DbgPrint("FAIL music: read failed in %s at block %u\n", path, unsigned(block));
      }
    }
    if (n) {
      cc_xbox_audio_lock();
      if (g_music.gen == gen)
        for (uint32_t i = 0; i < n; ++i) {
          const uint64_t s = fill + i;
          const uint32_t slot = uint32_t(s % kRingBlocks);
          std::memcpy(g_music.ring + size_t(slot) * kRingSlotBytes, buf + size_t(i) * bb, bb);
          g_music.tag[slot] = s;
        }
      cc_xbox_audio_unlock();
      fill += n;  // a new song resets it on the next pass
      continue;   // keep reading while behind
    }
    LARGE_INTEGER t;
    t.QuadPart = -40000;  // 4 ms
    KeDelayExecutionThread(KernelMode, FALSE, &t);
  }
  return 0;
}

// Start streaming `path` (mixer lock held by the caller).
static void music_start(const char* path, uint32_t data_start, uint32_t channels, uint32_t samples, bool loop) {
  if (!g_music_reader_started) {
    g_music_reader_started = true;
    for (auto& t : g_music.tag) t = ~0ull;
    HANDLE h = CreateThread(nullptr, 64 * 1024, &music_reader, nullptr, 0, nullptr);
    if (h) SetThreadPriority(h, THREAD_PRIORITY_HIGHEST);
    else ::DbgPrint("FAIL music: reader thread could not start\n");
  }
  ++g_music.gen;
  g_music.want = true;
  std::snprintf(g_music.path, sizeof(g_music.path), "%s", path);
  g_music.data_start = data_start;
  g_music.block_bytes = uint32_t(kBlock) * channels;
  g_music.total = (samples + kSpb - 1) / kSpb;
  g_music.loop = loop;
  g_music.consumer = 0;
  for (auto& t : g_music.tag) t = ~0ull;
}
static void music_stop() {
  ++g_music.gen;
  g_music.want = false;
}
// Raw bytes of the music voice's block `block` from the ring, or nullptr
// (past the song, or not arrived yet: silence, counted).
static const uint8_t* music_block(Voice& v, uint32_t block) {
  const uint32_t total = g_music.total;
  if (!total || block >= total) return nullptr;
  const uint64_t s = v.seq_base + block;
  if (s >= 1u && s - 1u > g_music.consumer) g_music.consumer = s - 1u;
  const uint32_t slot = uint32_t(s % kRingBlocks);
  if (g_music.tag[slot] != s) { ++g_music.starved; return nullptr; }
  return g_music.ring + size_t(slot) * kRingSlotBytes;
}
// The block the music voice plays next has arrived (a song waits for its
// first block instead of starting on silence).
static bool music_ready(const Voice& v) {
  const uint32_t total = g_music.total;
  if (!total) return false;
  const uint64_t s = v.seq_base + uint32_t(v.pos >> 32) / kSpb;
  return g_music.tag[uint32_t(s % kRingBlocks)] == s;
}
#endif
