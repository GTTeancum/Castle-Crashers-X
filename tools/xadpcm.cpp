// SPDX-License-Identifier: MIT
// Xbox ADPCM (WAVE_FORMAT_XBOX_ADPCM, 0x0069) encoder/decoder for the port's
// audio conversion. Xbox ADPCM is IMA ADPCM in fixed 36-byte blocks per
// channel: int16 first sample (little-endian; it is output as-is and seeds
// the predictor), uint8 step index, uint8 reserved, then 32 bytes holding
// 64 4-bit codes (low nibble first) for the following samples. The MCPX
// plays 64 samples per block (xemu: header sample + the first 63 codes);
// the encoder makes the 64th code the true next sample, so a 65-sample
// reading only repeats one sample per block.
//
//   xadpcm encode <in.s16le> <out.xadpcm> <channels>
//   xadpcm decode <in.xadpcm> <out.s16le> <channels>
//
// Raw files only: interleaved signed 16-bit little-endian PCM in, raw
// blocks (channel-interleaved per block, as the MCPX voice reads them) out.
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace {
const int kStep[89] = {
    7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23, 25, 28, 31, 34, 37, 41, 45,
    50, 55, 60, 66, 73, 80, 88, 97, 107, 118, 130, 143, 157, 173, 190, 209, 230,
    253, 279, 307, 337, 371, 408, 449, 494, 544, 598, 658, 724, 796, 876, 963,
    1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066, 2272, 2499, 2749, 3024, 3327,
    3660, 4026, 4428, 4871, 5358, 5894, 6484, 7132, 7845, 8630, 9493, 10442,
    11487, 12635, 13899, 15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794,
    32767};
const int kIndexAdj[8] = {-1, -1, -1, -1, 2, 4, 6, 8};
constexpr int kSamplesPerBlock = 64;
constexpr int kBlockBytes = 36;

int clamp16(int v) { return v < -32768 ? -32768 : (v > 32767 ? 32767 : v); }

struct State { int pred = 0, index = 0; };

// Decode one nibble, updating the state; returns the reconstructed sample.
int step_decode(State& s, int code) {
  const int step = kStep[s.index];
  int diff = step >> 3;
  if (code & 4) diff += step;
  if (code & 2) diff += step >> 1;
  if (code & 1) diff += step >> 2;
  s.pred = clamp16(code & 8 ? s.pred - diff : s.pred + diff);
  s.index += kIndexAdj[code & 7];
  s.index = s.index < 0 ? 0 : (s.index > 88 ? 88 : s.index);
  return s.pred;
}

// Choose the code for `target`, looking one sample ahead: the code whose
// reconstruction plus the best possible follow-up (for `next`) has the
// smallest squared error. Plain greedy choice drives the step index into
// states it cannot recover from quickly; the lookahead avoids most of that.
int step_encode(State& s, int target, int next) {
  int best = 0;
  long long best_err = -1;
  for (int code = 0; code < 16; ++code) {
    State t = s;
    const long long e1 = step_decode(t, code) - target;
    long long e2best = -1;
    for (int c2 = 0; c2 < 16; ++c2) {
      State u = t;
      const long long e2 = step_decode(u, c2) - next;
      if (e2best < 0 || e2 * e2 < e2best) e2best = e2 * e2;
    }
    const long long err = e1 * e1 + e2best;
    if (best_err < 0 || err < best_err) { best_err = err; best = code; }
  }
  step_decode(s, best);
  return best;
}

std::vector<uint8_t> read_file(const char* path) {
  std::vector<uint8_t> d;
  if (std::FILE* f = std::fopen(path, "rb")) {
    std::fseek(f, 0, SEEK_END);
    d.resize(size_t(std::ftell(f)));
    std::fseek(f, 0, SEEK_SET);
    if (!d.empty() && std::fread(d.data(), 1, d.size(), f) != d.size()) d.clear();
    std::fclose(f);
  }
  return d;
}

bool write_file(const char* path, const std::vector<uint8_t>& d) {
  std::FILE* f = std::fopen(path, "wb");
  if (!f) return false;
  const bool ok = d.empty() || std::fwrite(d.data(), 1, d.size(), f) == d.size();
  return std::fclose(f) == 0 && ok;
}
}  // namespace

int main(int argc, char** argv) {
  if (argc != 5) {
    std::fprintf(stderr, "usage: xadpcm encode|decode <in> <out> <channels>\n");
    return 2;
  }
  const int ch = std::atoi(argv[4]);
  if (ch < 1 || ch > 2) return 2;
  const std::vector<uint8_t> in = read_file(argv[2]);
  std::vector<uint8_t> out;
  if (!std::strcmp(argv[1], "encode")) {
    const size_t frames = in.size() / (2u * ch);
    const size_t blocks = (frames + kSamplesPerBlock - 1) / kSamplesPerBlock;
    auto sample = [&](size_t frame, int c) -> int {
      if (frame >= frames) return 0;
      const size_t o = (frame * ch + c) * 2;
      return int16_t(in[o] | in[o + 1] << 8);
    };
    std::vector<State> st(ch);
    out.resize(blocks * kBlockBytes * ch);
    for (size_t b = 0; b < blocks; ++b) {
      for (int c = 0; c < ch; ++c) {
        uint8_t* blk = out.data() + (b * ch + c) * kBlockBytes;
        State& s = st[c];
        const size_t first = b * kSamplesPerBlock;
        s.pred = sample(first, c);
        blk[0] = uint8_t(s.pred); blk[1] = uint8_t(s.pred >> 8);
        blk[2] = uint8_t(s.index); blk[3] = 0;
        for (int i = 0; i < kSamplesPerBlock; i += 2) {
          const int lo = step_encode(s, sample(first + 1 + i, c), sample(first + 2 + i, c));
          const int hi = step_encode(s, sample(first + 2 + i, c), sample(first + 3 + i, c));
          blk[4 + i / 2] = uint8_t(lo | hi << 4);
        }
      }
    }
  } else if (!std::strcmp(argv[1], "decode")) {
    const size_t blocks = in.size() / (size_t(kBlockBytes) * ch);
    out.resize(blocks * kSamplesPerBlock * ch * 2);
    for (size_t b = 0; b < blocks; ++b) {
      for (int c = 0; c < ch; ++c) {
        const uint8_t* blk = in.data() + (b * ch + c) * kBlockBytes;
        State s;
        s.pred = int16_t(blk[0] | blk[1] << 8);
        s.index = blk[2] > 88 ? 88 : blk[2];
        for (int i = 0; i < kSamplesPerBlock; ++i) {
          int v = s.pred;
          if (i > 0) {
            const int code = (blk[4 + (i - 1) / 2] >> (((i - 1) & 1) * 4)) & 15;
            v = step_decode(s, code);
          }
          const size_t o = ((b * kSamplesPerBlock + i) * ch + c) * 2;
          out[o] = uint8_t(v); out[o + 1] = uint8_t(v >> 8);
        }
      }
    }
  } else {
    return 2;
  }
  if (!write_file(argv[3], out)) { std::perror(argv[3]); return 1; }
  return 0;
}
