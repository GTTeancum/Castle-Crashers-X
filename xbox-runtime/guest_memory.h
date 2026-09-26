// SPDX-License-Identifier: MIT
// Bounded guest-address bridge prototype. Not an Xbox 360 kernel/MMIO emulator.
#pragma once
#include <stddef.h>
#include <stdint.h>
namespace cc::xbox {
enum class MemoryError { ok, invalid, overlap, capacity, unmapped, readonly, wrap };
enum Access : uint32_t { read_access = 1, write_access = 2 };
struct Region { uint32_t guest, bytes; uint8_t* host; uint32_t access; };
class AddressSpace {
 public:
  static constexpr size_t capacity = 64;
  MemoryError map(uint32_t guest, uint32_t bytes, void* host, uint32_t access);
  MemoryError check(uint32_t guest, size_t bytes, uint32_t access) const;
  MemoryError read(uint32_t guest, void* dst, size_t bytes) const;
  MemoryError write(uint32_t guest, const void* src, size_t bytes);
  MemoryError load_be(uint32_t guest, unsigned bytes, uint64_t& value) const;
  MemoryError store_be(uint32_t guest, unsigned bytes, uint64_t value);
  // Returns nullptr unless the WHOLE request is in one host-contiguous region.
  // A recompiled raw/vector access must use this contract, not host+guest arithmetic.
  uint8_t* contiguous(uint32_t guest, size_t bytes, uint32_t access) const;
  size_t region_count() const { return count_; }
  const Region* regions() const { return regions_; }
 private:
  const Region* find(uint32_t guest) const;
  Region regions_[capacity]{};
  size_t count_{};
};
// Configure maps before concurrent use. Caller owns backing storage and synchronization.
// Read/write buffers must not overlap the mapped host spans (memcpy-like contract).
// Disjoint guest regions may intentionally alias the same live host storage.
// MMIO, allocation, reservation, access traps and page-fault handling are NOT implemented.
} // namespace cc::xbox
