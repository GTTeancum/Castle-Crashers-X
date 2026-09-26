// SPDX-License-Identifier: MIT
#pragma once
#include "../renderer005/stream_loader.h"
#include "../runtime008/fixtures.h"
namespace cc::owner010 {
// The complete captured owner's memory is restored once. Entry registers and
// the output cursor are reset per frame; this is NOT the original update loop.
struct Resident {
  cc::tree::Workspace work;
  cc::tree::Case root;
  uint32_t child_slot{}, child_head{}, frames{}, restores{};
  const uint8_t* fixture_source{};
  size_t fixture_size{};
  bool ready{}, hidden{};
  void reset() noexcept { ready=false;hidden=false;frames=restores=child_slot=child_head=0;fixture_source=nullptr;fixture_size=0; }
};
struct Result {
  uint32_t roots{}, draws{}, visits{}, dispatches{}, binds{}, matches{},
    raw_hash=2166136261u,error{},failed_root=0,address{},quad_error{},
    resident_frames{},resident_restores{},checked_writes{};
};
Result frame(const cc::tree::Fixtures&, cc::tree::Workspace&, cc::stream::Scene&, Resident&, bool hide,
             cc::replay::Vertex* normalized=nullptr,size_t normalized_count=0) noexcept;
}
