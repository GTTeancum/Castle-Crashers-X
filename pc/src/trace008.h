#pragma once
#include <cstdint>
namespace cc_trace008 {
extern thread_local bool enabled;
void access(uint8_t*, uint32_t, unsigned, bool);
void function(const char*);
void indirect(uint32_t);
}
inline uint8_t cc008_original_load8(uint8_t* base,uint32_t a) { return REX_LOAD_U8(a); }
inline void cc008_original_store8(uint8_t* base,uint32_t a,uint8_t v) { REX_STORE_U8(a,v); }
#undef REX_LOAD_U8
#define REX_LOAD_U8(a) ([&]() { uint32_t t=uint32_t(a); if(cc_trace008::enabled)cc_trace008::access(base,t,1,false); return cc008_original_load8(base,t); }())
#undef REX_STORE_U8
#define REX_STORE_U8(a,v) ([&]() { uint32_t t=uint32_t(a); uint8_t u=(v); if(cc_trace008::enabled)cc_trace008::access(base,t,1,true); cc008_original_store8(base,t,u); }())
inline uint16_t cc008_original_load16(uint8_t* base,uint32_t a) { return REX_LOAD_U16(a); }
inline void cc008_original_store16(uint8_t* base,uint32_t a,uint16_t v) { REX_STORE_U16(a,v); }
#undef REX_LOAD_U16
#define REX_LOAD_U16(a) ([&]() { uint32_t t=uint32_t(a); if(cc_trace008::enabled)cc_trace008::access(base,t,2,false); return cc008_original_load16(base,t); }())
#undef REX_STORE_U16
#define REX_STORE_U16(a,v) ([&]() { uint32_t t=uint32_t(a); uint16_t u=(v); if(cc_trace008::enabled)cc_trace008::access(base,t,2,true); cc008_original_store16(base,t,u); }())
inline uint32_t cc008_original_load32(uint8_t* base,uint32_t a) { return REX_LOAD_U32(a); }
inline void cc008_original_store32(uint8_t* base,uint32_t a,uint32_t v) { REX_STORE_U32(a,v); }
#undef REX_LOAD_U32
#define REX_LOAD_U32(a) ([&]() { uint32_t t=uint32_t(a); if(cc_trace008::enabled)cc_trace008::access(base,t,4,false); return cc008_original_load32(base,t); }())
#undef REX_STORE_U32
#define REX_STORE_U32(a,v) ([&]() { uint32_t t=uint32_t(a); uint32_t u=(v); if(cc_trace008::enabled)cc_trace008::access(base,t,4,true); cc008_original_store32(base,t,u); }())
inline uint64_t cc008_original_load64(uint8_t* base,uint32_t a) { return REX_LOAD_U64(a); }
inline void cc008_original_store64(uint8_t* base,uint32_t a,uint64_t v) { REX_STORE_U64(a,v); }
#undef REX_LOAD_U64
#define REX_LOAD_U64(a) ([&]() { uint32_t t=uint32_t(a); if(cc_trace008::enabled)cc_trace008::access(base,t,8,false); return cc008_original_load64(base,t); }())
#undef REX_STORE_U64
#define REX_STORE_U64(a,v) ([&]() { uint32_t t=uint32_t(a); uint64_t u=(v); if(cc_trace008::enabled)cc_trace008::access(base,t,8,true); cc008_original_store64(base,t,u); }())
inline void cc008_original_prologue(uint8_t* base) { REX_FUNC_PROLOGUE(); }
#undef REX_FUNC_PROLOGUE
#define REX_FUNC_PROLOGUE() do { cc008_original_prologue(base); if(cc_trace008::enabled)cc_trace008::function(__func__); } while(0)
inline void cc008_original_dispatch(PPCContext& ctx,uint8_t* base,uint32_t address) { REX_CALL_INDIRECT_FUNC(address); }
#undef REX_CALL_INDIRECT_FUNC
#define REX_CALL_INDIRECT_FUNC(a) do { uint32_t address_=uint32_t(a); if(cc_trace008::enabled)cc_trace008::indirect(address_); cc008_original_dispatch(ctx,base,address_); } while(0)
