// SPDX-License-Identifier: MIT
// Local profiles and saved progress (included by bodies.inc before the Xam
// account stubs).
//
// PORT POLICY (2026-10-17, replaces "nobody signs in"): every controller is a
// local profile. User 0 is signed in from boot; users 1-3 sign in when a
// controller first appears in their slot (all four from boot in the
// four-player test build). Each is "Player N" with a stable offline XUID
// 0xE000000000000000 | N, signed in locally (state 1, never Live). A sign-in
// after boot is announced to the game's system notification listeners as
// XN_SYS_SIGNINCHANGED (0x0A), as on a real console.
//
// Castle Crashers keeps all of a player's progress in one 768-byte block,
// the profile's title-specific setting 1 (id 0x63E83FFF), read and written
// through XamUserReadProfileSettings / XamUserWriteProfileSettings. Here it
// lives in the original Xbox's saved-game area, one folder per player:
//   E:\UDATA\584108b7\TitleMeta.xbx, TitleImage.xbx
//   E:\UDATA\584108b7\00000000000N\SaveMeta.xbx, SaveImage.xbx,
//                                  progress0.bin, progress1.bin
// The two progress files are written alternately, each with a sequence
// number and a CRC32, so a power cut mid-write loses at most the newest
// save: loading takes the newest copy whose CRC holds. Host runs keep
// progress in memory unless CC_SAVE_DIR names a folder.

static uint32_t g_cc_signed = 0;          // signed-in users (bit per user)
static uint32_t g_cc_notify_pending = 0;  // listeners (bit per index) owed XN_SYS_SIGNINCHANGED
static bool g_cc_signin_read = false;     // the game has read the sign-in state (boot done)
static uint32_t g_xam_listener_area[8];   // area mask per listener (XamNotifyCreateListener)

static void cc_sign_in(uint32_t user) {
  if (user > 3u || (g_cc_signed & (1u << user))) return;
  g_cc_signed |= 1u << user;
  if (g_cc_signin_read) g_cc_notify_pending = 0xFFu;
#ifdef CC_XBOX_DRIVER
  ::DbgPrint("PROFILE Player %u signed in\n", unsigned(user + 1u));
#endif
}
static void cc_profiles_boot() {
  cc_sign_in(0u);
  if (cc_four_players()) for (uint32_t u = 1; u < 4u; ++u) cc_sign_in(u);
}
static bool cc_signed_in(uint32_t user) {
  cc_profiles_boot();
  return user <= 3u && (g_cc_signed & (1u << user)) != 0u;
}
// A real controller in slot `user` (play build); the host and the
// four-player test build have none beyond the scripted pads.
static bool cc_real_pad([[maybe_unused]] uint32_t user) {
#ifdef CC_XBOX_DRIVER
  uint32_t pb = 0; int16_t lx = 0, ly = 0, rx = 0, ry = 0; uint8_t lt = 0, rt = 0;
  return ::cc_xbox_pad_port(user, &pb, &lx, &ly, &rx, &ry, &lt, &rt);
#else
  return false;
#endif
}
static uint64_t cc_profile_xuid(uint32_t user) { return 0xE000000000000000ull | (user + 1u); }
// "Player N" at a guest buffer of n bytes (NUL-terminated).
static void cc_profile_name(Machine& base, uint32_t user, uint32_t out, uint32_t n) {
  const char name[] = {'P', 'l', 'a', 'y', 'e', 'r', ' ', char('1' + user), 0};
  for (uint32_t k = 0; k < 9u && k < n; ++k) base.store(out + k, 1, uint8_t(name[k]));
  if (n && n < 9u) base.store(out + n - 1u, 1, 0u);
}

// ---- Saved progress ---------------------------------------------------------
constexpr uint32_t kCcProgressId = 0x63E83FFFu;  // XPROFILE_TITLE_SPECIFIC1
constexpr uint32_t kCcProgressMax = 1000u;       // the profile setting's limit
struct CcProgress {
  bool loaded = false;
  uint32_t len = 0, seq = 0;
  uint8_t data[kCcProgressMax] = {};
};
static CcProgress g_cc_progress[4];

static uint32_t cc_crc32(const uint8_t* p, size_t n) {
  uint32_t c = 0xFFFFFFFFu;
  for (size_t i = 0; i < n; ++i) {
    c ^= p[i];
    for (int k = 0; k < 8; ++k) c = (c >> 1) ^ (0xEDB88320u & (0u - (c & 1u)));
  }
  return ~c;
}
// Folder of the saved-game area, or "" when there is none (host default).
static const char* cc_save_root() {
#ifdef CC_XBOX_DRIVER
  static bool mounted = false;
  if (!mounted) {
    mounted = true;
    if (!nxIsDriveMounted('E') && !nxMountDrive('E', "\\Device\\Harddisk0\\Partition1\\"))
      ::DbgPrint("FAIL save: E: could not be mounted; progress will not be kept\n");
  }
  return "E:\\UDATA\\584108b7";
#else
  const char* d = std::getenv("CC_SAVE_DIR");
  return d ? d : "";
#endif
}
static void cc_save_mkdir(const char* path) {
#ifdef CC_XBOX_DRIVER
  CreateDirectoryA(path, nullptr);  // fails harmlessly when it exists
#else
  std::error_code ec;
  std::filesystem::create_directories(path, ec);
#endif
}
static bool cc_save_write_file(const char* path, const void* p, size_t n) {
  std::FILE* f = std::fopen(path, "wb");
  if (!f) return false;
  const bool ok = std::fwrite(p, 1, n, f) == n;
  return std::fclose(f) == 0 && ok;
}
// UTF-16LE text file with a byte-order mark, as the dashboard reads
// TitleMeta.xbx / SaveMeta.xbx.
static bool cc_save_write_meta(const char* path, const char* text) {
  std::vector<uint8_t> b = {0xFF, 0xFE};
  for (const char* c = text; *c; ++c) { b.push_back(uint8_t(*c)); b.push_back(0); }
  return cc_save_write_file(path, b.data(), b.size());
}
// Title and player folders with their dashboard files (written with the
// first save; the title image comes from the installer's D:\data\TitleImage.xbx).
static void cc_save_prepare(uint32_t user, char* dir, size_t dn) {
  const char* root = cc_save_root();
  dir[0] = 0;
  if (!root[0]) return;
#ifdef CC_XBOX_DRIVER
  cc_save_mkdir("E:\\UDATA");
#endif
  cc_save_mkdir(root);
  char path[300];
  std::snprintf(path, sizeof(path), "%s\\TitleMeta.xbx", root);
  if (std::FILE* f = std::fopen(path, "rb")) std::fclose(f);
  else {
    cc_save_write_meta(path, "TitleName=Castle Crashers\r\n");
#ifdef CC_XBOX_DRIVER
    if (std::FILE* img = std::fopen("D:\\data\\TitleImage.xbx", "rb")) {
      std::vector<uint8_t> b(16384);
      const size_t n = std::fread(b.data(), 1, b.size(), img);
      std::fclose(img);
      b.resize(n);
      std::snprintf(path, sizeof(path), "%s\\TitleImage.xbx", root);
      if (n) cc_save_write_file(path, b.data(), n);
    }
#endif
  }
  std::snprintf(dir, dn, "%s\\%012X", root, unsigned(user + 1u));
  cc_save_mkdir(dir);
  std::snprintf(path, sizeof(path), "%s\\SaveMeta.xbx", dir);
  if (std::FILE* f = std::fopen(path, "rb")) std::fclose(f);
  else {
    char meta[64];
    std::snprintf(meta, sizeof(meta), "Name=Player %u\r\n", unsigned(user + 1u));
    cc_save_write_meta(path, meta);
#ifdef CC_XBOX_DRIVER
    char src[300];
    std::snprintf(src, sizeof(src), "%s\\TitleImage.xbx", root);
    if (std::FILE* img = std::fopen(src, "rb")) {
      std::vector<uint8_t> b(16384);
      const size_t n = std::fread(b.data(), 1, b.size(), img);
      std::fclose(img);
      b.resize(n);
      std::snprintf(path, sizeof(path), "%s\\SaveImage.xbx", dir);
      if (n) cc_save_write_file(path, b.data(), n);
    }
#endif
  }
}
// progressN.bin: 'CCXP', u32 version 1, u32 sequence, u32 setting id,
// u32 length, u32 CRC32 of the data, then the data.
static void cc_progress_load(uint32_t user) {
  CcProgress& p = g_cc_progress[user];
  if (p.loaded) return;
  p.loaded = true;
  const char* root = cc_save_root();
  if (!root[0]) return;
  for (int slot = 0; slot < 2; ++slot) {
    char path[300];
    std::snprintf(path, sizeof(path), "%s\\%012X\\progress%d.bin", root, unsigned(user + 1u), slot);
    std::FILE* f = std::fopen(path, "rb");
    if (!f) continue;
    uint32_t h[6] = {};
    uint8_t buf[kCcProgressMax];
    const bool head = std::fread(h, 4, 6, f) == 6;
    const bool body = head && h[4] <= kCcProgressMax && std::fread(buf, 1, h[4], f) == h[4];
    std::fclose(f);
    if (!body || h[0] != 0x50584343u || h[1] != 1u || h[3] != kCcProgressId || cc_crc32(buf, h[4]) != h[5]) {
#ifdef CC_XBOX_DRIVER
      ::DbgPrint("FAIL save: %s is damaged; using the other copy\n", path);
#else
      cc_elog("SAVE damaged copy %s\n", path);
#endif
      continue;
    }
    if (p.len == 0u || h[2] > p.seq) {
      p.seq = h[2];
      p.len = h[4];
      std::memcpy(p.data, buf, h[4]);
    }
  }
#ifdef CC_XBOX_DRIVER
  ::DbgPrint("SAVE Player %u: %s (%u bytes, save %u)\n", unsigned(user + 1u), p.len ? "progress loaded" : "no progress yet",
             unsigned(p.len), unsigned(p.seq));
#endif
}
// Keeps the new progress; true when it reached the disk (or there is no
// disk to keep it on, host default).
static bool cc_progress_store(uint32_t user, const uint8_t* data, uint32_t len) {
  cc_progress_load(user);
  CcProgress& p = g_cc_progress[user];
  p.len = len;
  ++p.seq;
  std::memcpy(p.data, data, len);
  char dir[300];
  cc_save_prepare(user, dir, sizeof(dir));
  if (!dir[0]) return true;
  char path[340];
  std::snprintf(path, sizeof(path), "%s\\progress%u.bin", dir, unsigned(p.seq & 1u));
  std::vector<uint8_t> b(24u + len);
  const uint32_t h[6] = {0x50584343u, 1u, p.seq, kCcProgressId, len, cc_crc32(data, len)};
  std::memcpy(b.data(), h, 24);
  std::memcpy(b.data() + 24, data, len);
  const bool ok = cc_save_write_file(path, b.data(), b.size());
#ifdef CC_XBOX_DRIVER
  if (ok) ::DbgPrint("SAVE Player %u: progress saved (%u bytes, save %u)\n", unsigned(user + 1u), unsigned(len), unsigned(p.seq));
  else ::DbgPrint("FAIL save: writing %s failed\n", path);
#else
  if (!ok) cc_elog("SAVE write failed %s\n", path);
#endif
  return ok;
}
