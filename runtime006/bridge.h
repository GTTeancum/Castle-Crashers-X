// SPDX-License-Identifier: MIT
// Bounded scalar adapter for this game's generated quad routine, NOT a full PPC
// runtime.
#pragma once
#include "../xbox-runtime/guest_memory.h"
#include <cstddef>
#include <cstdint>
namespace cc::quad {
union Register {
  uint64_t u64;
  int64_t s64;
  uint32_t u32;
  int32_t s32;
  uint16_t u16;
  int16_t s16;
  uint8_t u8;
  int8_t s8;
  float f32;
  double f64;
};
union alignas(0x10) VRegister {
  int8_t s8[16];
  uint8_t u8[16];
  int16_t s16[8];
  uint16_t u16[8];
  int32_t s32[4];
  uint32_t u32[4];
  int64_t s64[2];
  uint64_t u64[2];
  float f32[4];
  double f64[2];
};
struct XER {
  uint8_t so{}, ov{}, ca{};
};
struct CR {
  uint8_t lt{}, gt{}, eq{};
  union {
    uint8_t so{};
    uint8_t un;
  };
  template <class T> void compare(T a, T b, const XER &x) noexcept {
    lt = a < b;
    gt = a > b;
    eq = a == b;
    so = x.so;
  }
  void compare(double a, double b) noexcept {
    un = __builtin_isnan(a) || __builtin_isnan(b);
    lt = !un && a < b;
    gt = !un && a > b;
    eq = !un && a == b;
  }
  uint32_t raw() const noexcept {
    return (lt << 3) | (gt << 2) | (eq << 1) | so;
  }
  void raw(uint32_t v) noexcept {
    lt = (v >> 3) & 1;
    gt = (v >> 2) & 1;
    eq = (v >> 1) & 1;
    so = v & 1;
  }
};
struct FPState {
  uint32_t csr{};
  void disableFlushMode() noexcept;
  void disableFlushModeUnconditional() noexcept;
  void enableFlushModeUnconditional() noexcept;
  void enableFlushMode() noexcept;
  uint32_t loadFromHost() noexcept;
  void storeFromGuest(uint32_t value) noexcept;
};
struct Context {
  Register r0{};
  Register r1{};
  Register r2{};
  Register r3{};
  Register r4{};
  Register r5{};
  Register r6{};
  Register r7{};
  Register r8{};
  Register r9{};
  Register r10{};
  Register r11{};
  Register r12{};
  Register r13{};
  Register r14{};
  Register r15{};
  Register r16{};
  Register r17{};
  Register r18{};
  Register r19{};
  Register r20{};
  Register r21{};
  Register r22{};
  Register r23{};
  Register r24{};
  Register r25{};
  Register r26{};
  Register r27{};
  Register r28{};
  Register r29{};
  Register r30{};
  Register r31{};
  Register f0{};
  Register f1{};
  Register f2{};
  Register f3{};
  Register f4{};
  Register f5{};
  Register f6{};
  Register f7{};
  Register f8{};
  Register f9{};
  Register f10{};
  Register f11{};
  Register f12{};
  Register f13{};
  Register f14{};
  Register f15{};
  Register f16{};
  Register f17{};
  Register f18{};
  Register f19{};
  Register f20{};
  Register f21{};
  Register f22{};
  Register f23{};
  Register f24{};
  Register f25{};
  Register f26{};
  Register f27{};
  Register f28{};
  Register f29{};
  Register f30{};
  Register f31{};
  uint64_t lr{};
  // Machine-state register mirror for generated mfmsr/mtmsrd interrupt-mask
  // sequences (WIP 022 audio-driver family). The single-threaded host makes
  // the mask itself semantically inert; the field only preserves the exact
  // generated data flow.
  uint64_t msr{0x8020};
  Register ctr{};
  XER xer{};
  Register reserved{};
  CR cr0{};
  CR cr1{};
  CR cr2{};
  CR cr3{};
  CR cr4{};
  CR cr5{};
  CR cr6{};
  CR cr7{};
  FPState fpscr{};
  VRegister v0{};
  VRegister v1{};
  VRegister v2{};
  VRegister v3{};
  VRegister v4{};
  VRegister v5{};
  VRegister v6{};
  VRegister v7{};
  VRegister v8{};
  VRegister v9{};
  VRegister v10{};
  VRegister v11{};
  VRegister v12{};
  VRegister v13{};
  VRegister v14{};
  VRegister v15{};
  VRegister v16{};
  VRegister v17{};
  VRegister v18{};
  VRegister v19{};
  VRegister v20{};
  VRegister v21{};
  VRegister v22{};
  VRegister v23{};
  VRegister v24{};
  VRegister v25{};
  VRegister v26{};
  VRegister v27{};
  VRegister v28{};
  VRegister v29{};
  VRegister v30{};
  VRegister v31{};
  VRegister v32{};
  VRegister v33{};
  VRegister v34{};
  VRegister v35{};
  VRegister v36{};
  VRegister v37{};
  VRegister v38{};
  VRegister v39{};
  VRegister v40{};
  VRegister v41{};
  VRegister v42{};
  VRegister v43{};
  VRegister v44{};
  VRegister v45{};
  VRegister v46{};
  VRegister v47{};
  VRegister v48{};
  VRegister v49{};
  VRegister v50{};
  VRegister v51{};
  VRegister v52{};
  VRegister v53{};
  VRegister v54{};
  VRegister v55{};
  VRegister v56{};
  VRegister v57{};
  VRegister v58{};
  VRegister v59{};
  VRegister v60{};
  VRegister v61{};
  VRegister v62{};
  VRegister v63{};
  VRegister v64{};
  VRegister v65{};
  VRegister v66{};
  VRegister v67{};
  VRegister v68{};
  VRegister v69{};
  VRegister v70{};
  VRegister v71{};
  VRegister v72{};
  VRegister v73{};
  VRegister v74{};
  VRegister v75{};
  VRegister v76{};
  VRegister v77{};
  VRegister v78{};
  VRegister v79{};
  VRegister v80{};
  VRegister v81{};
  VRegister v82{};
  VRegister v83{};
  VRegister v84{};
  VRegister v85{};
  VRegister v86{};
  VRegister v87{};
  VRegister v88{};
  VRegister v89{};
  VRegister v90{};
  VRegister v91{};
  VRegister v92{};
  VRegister v93{};
  VRegister v94{};
  VRegister v95{};
  VRegister v96{};
  VRegister v97{};
  VRegister v98{};
  VRegister v99{};
  VRegister v100{};
  VRegister v101{};
  VRegister v102{};
  VRegister v103{};
  VRegister v104{};
  VRegister v105{};
  VRegister v106{};
  VRegister v107{};
  VRegister v108{};
  VRegister v109{};
  VRegister v110{};
  VRegister v111{};
  VRegister v112{};
  VRegister v113{};
  VRegister v114{};
  VRegister v115{};
  VRegister v116{};
  VRegister v117{};
  VRegister v118{};
  VRegister v119{};
  VRegister v120{};
  VRegister v121{};
  VRegister v122{};
  VRegister v123{};
  VRegister v124{};
  VRegister v125{};
  VRegister v126{};
  VRegister v127{};
};
Register &gpr(Context &, unsigned) noexcept;
Register &fpr(Context &, unsigned) noexcept;
CR &cr(Context &, unsigned) noexcept;
struct Draw {
  uint32_t device{}, primitive{}, count{}, stride{}, source{}, blend{};
  uint8_t vertices[96]{};
  uint32_t projection[16]{};
};
struct Sink {
  void *user{};
  bool (*submit)(void *, const Draw &){};
};
enum class Error : uint32_t {
  ok,
  entry,
  context,
  memory,
  shader,
  capacity,
  nonfinite,
  alias,
  sink,
  contract
};
const char *name(Error) noexcept;
// Only address 0x820A9308, shader ID 0/5, four 24-byte vertices and nearest FP.
// Preflights the supported capture contract. Caller memory must be coherent and
// immutable during a call. A sink failure can occur after the generated routine
// wrote its output. An unexpected internal dependency is a hard failure, never
// a fake successful service.
Error invoke(uint32_t, Context &, cc::xbox::AddressSpace &, Sink,
             unsigned *submitted = nullptr) noexcept;
} // namespace cc::quad
