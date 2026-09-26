// SPDX-License-Identifier: MIT
// Allocation-free format probe; NOT a Flash interpreter or game renderer.
#pragma once
#include <stdint.h>
#include <stddef.h>
namespace cc {
struct Bytes { const uint8_t* data; size_t size; };
enum class Error { ok, truncated, signature, unsupported, corrupt, crc, depth, missing_end };
const char* error_name(Error e);
uint32_t crc32(Bytes bytes);
struct Member { Bytes name; Bytes data; uint32_t crc; };
using Visitor = Error (*)(const Member&, void* context);
// Classic single-disk ZIP, stored entries, flags==0 only. No file writes.
Error visit_pak(Bytes archive, Visitor visitor, void* context);
struct SwfStats {
    uint64_t tags[1024]{};
    uint32_t declared_bytes{};
    uint32_t wrapper_payload_bytes{};
    uint32_t consumed_bytes{};
    uint32_t max_depth{};
    uint8_t version{};
};
// Structural tag walk of one COK6 BREC. Counts recursively nested sprite tags.
// Unknown tags are counted/skipped, never assumed to be implemented.
// Uses wrapper length, not the sometimes-stale embedded SWF declared length.
Error scan_cok6(Bytes record, SwfStats& stats);
}
