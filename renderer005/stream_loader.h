// SPDX-License-Identifier: MIT
#pragma once
#include "../renderer004/gpu_staging.h"
namespace cc::stream {
using cc::replay::GpuVertex;
// Source must remain unchanged during load. Reads must fill the requested
// range.
struct Source {
  void *context{};
  uint32_t length{};
  bool (*read)(void *, uint32_t, void *, size_t){};
};
// GPU allocations must satisfy the target's contiguous/accessible-address
// contract.
struct Memory {
  void *context{};
  void *(*allocate)(void *, size_t, bool gpu){};
  void (*release)(void *, void *, bool gpu){};
};
struct GpuTexture {
  void *data{};
  uint32_t width{}, height{}, pitch{};
};
struct Command {
  uint32_t texture{}, blend{};
};
enum class Error {
  ok,
  busy,
  header,
  size,
  counts,
  range,
  texture,
  draw,
  blend,
  nonfinite,
  read,
  allocator,
  budget,
  allocation
};
const char *name(Error) noexcept;
class Scene {
public:
  Scene() noexcept = default;
  ~Scene() { reset(); }
  Scene(const Scene &) = delete;
  Scene &operator=(const Scene &) = delete;
  void reset() noexcept;
  uint32_t width() const noexcept { return width_; }
  uint32_t height() const noexcept { return height_; }
  uint32_t texture_count() const noexcept { return nt_; }
  uint32_t draw_count() const noexcept { return nd_; }
  uint32_t gpu_bytes() const noexcept { return gpu_bytes_; }
  uint32_t command_bytes() const noexcept { return nd_ * sizeof(Command); }
  const GpuTexture &texture(uint32_t i) const noexcept { return textures_[i]; }
  const Command &command(uint32_t i) const noexcept { return commands_[i]; }
  const GpuVertex *vertices() const noexcept { return vertices_; }
  // Live producer owns writes only while the GPU is idle; submit after a complete successful frame.
  GpuVertex *writable_vertices() noexcept { return vertices_; }
  // Live producer owns command updates under the same GPU-idle contract.
  Command *writable_commands() noexcept { return commands_; }

private:
  friend Error load(Source, Memory, Scene &, uint32_t) noexcept;
  Memory memory_{};
  GpuTexture textures_[cc::replay::max_textures]{};
  GpuVertex *vertices_{};
  Command *commands_{};
  uint32_t width_{}, height_{}, nt_{}, nd_{}, gpu_bytes_{};
};
// Validates all metadata before allocation. Converts each RGBA row in a bounded
// 8 KiB cached scratch buffer before writing final GPU storage, avoiding
// readback from write-combined memory. No normalized-scene-sized temporary.
// Failure leaves a previously empty destination empty and releases allocations.
// Nonempty destinations are refused; synchronize the GPU BEFORE calling
// reset().
Error load(Source, Memory, Scene &,
           uint32_t gpu_budget = 32 * 1024 * 1024) noexcept;
} // namespace cc::stream
