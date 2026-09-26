// SPDX-License-Identifier: MIT
struct FloatScope {
  uint32_t mx;
  uint16_t cw;
  FloatScope() {
    asm volatile("stmxcsr %0" : "=m"(mx));
    asm volatile("fnstcw %0" : "=m"(cw));
    uint32_t next = (mx & ~uint32_t(0xe040)) | 0x1f80;
    uint16_t word = uint16_t((cw & ~0x0f00) | 0x023f);
    asm volatile("ldmxcsr %0" ::"m"(next));
    asm volatile("fldcw %0" ::"m"(word));
  }
  ~FloatScope() {
    asm volatile("ldmxcsr %0" ::"m"(mx));
    asm volatile("fldcw %0" ::"m"(cw));
  }
};
