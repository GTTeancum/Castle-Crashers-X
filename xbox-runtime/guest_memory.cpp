// SPDX-License-Identifier: MIT
#include "guest_memory.h"
#include <string.h>
namespace cc::xbox {
static bool valid_access(uint32_t v) { return v && !(v & ~(read_access|write_access)); }
MemoryError AddressSpace::map(uint32_t guest, uint32_t bytes, void* host, uint32_t access) {
  if (!bytes || !host || !valid_access(access)) return MemoryError::invalid;
  const uint64_t end=uint64_t(guest)+bytes;
  if (end>0x100000000ull) return MemoryError::wrap;
  for (size_t i=0;i<count_;++i)
    if (guest<uint64_t(regions_[i].guest)+regions_[i].bytes && regions_[i].guest<end)
      return MemoryError::overlap;
  if (count_==capacity) return MemoryError::capacity;
  size_t i=count_++;
  while (i && regions_[i-1].guest>guest) { regions_[i]=regions_[i-1]; --i; }
  regions_[i]={guest,bytes,static_cast<uint8_t*>(host),access};
  return MemoryError::ok;
}
const Region* AddressSpace::find(uint32_t guest) const {
  size_t lo=0,hi=count_;
  while (lo<hi) { const size_t mid=lo+(hi-lo)/2; if (regions_[mid].guest<=guest) lo=mid+1; else hi=mid; }
  if (!lo) return nullptr;
  const Region* r=&regions_[lo-1];
  return uint64_t(guest)-r->guest<r->bytes ? r : nullptr;
}
MemoryError AddressSpace::check(uint32_t guest,size_t bytes,uint32_t access) const {
  if (!valid_access(access)) return MemoryError::invalid;
  if (bytes>0x100000000ull-guest) return MemoryError::wrap;
  uint64_t pos=guest,end=pos+bytes;
  while (pos<end) {
    const Region* r=find(static_cast<uint32_t>(pos));
    if (!r) return MemoryError::unmapped;
    if ((r->access&access)!=access) return MemoryError::readonly;
    const uint64_t limit=uint64_t(r->guest)+r->bytes;
    pos=limit<end?limit:end;
  }
  return MemoryError::ok;
}
uint8_t* AddressSpace::contiguous(uint32_t guest,size_t bytes,uint32_t access) const {
  if (!bytes || !valid_access(access) || bytes>0x100000000ull-guest) return nullptr;
  const Region* r=find(guest);
  if (!r || (r->access&access)!=access || bytes>uint64_t(r->bytes)-(guest-r->guest)) return nullptr;
  return r->host+(guest-r->guest);
}
MemoryError AddressSpace::read(uint32_t guest,void* dst,size_t bytes) const {
  if (bytes && !dst) return MemoryError::invalid;
  const auto e=check(guest,bytes,read_access); if(e!=MemoryError::ok) return e;
  auto* out=static_cast<uint8_t*>(dst);uint64_t pos=guest;size_t left=bytes;
  while(left) { const Region* r=find(static_cast<uint32_t>(pos));
    size_t n=size_t(uint64_t(r->guest)+r->bytes-pos);if(n>left)n=left;
    memcpy(out,r->host+size_t(pos-r->guest),n);out+=n;pos+=n;left-=n;
  } return MemoryError::ok;
}
MemoryError AddressSpace::write(uint32_t guest,const void* src,size_t bytes) {
  if (bytes && !src) return MemoryError::invalid;
  // Preflight every region: invalid/unmapped/read-only writes do not partially mutate RAM.
  const auto e=check(guest,bytes,write_access); if(e!=MemoryError::ok) return e;
  const auto* in=static_cast<const uint8_t*>(src);uint64_t pos=guest;size_t left=bytes;
  while(left) { const Region* r=find(static_cast<uint32_t>(pos));
    size_t n=size_t(uint64_t(r->guest)+r->bytes-pos);if(n>left)n=left;
    memcpy(r->host+size_t(pos-r->guest),in,n);in+=n;pos+=n;left-=n;
  } return MemoryError::ok;
}
MemoryError AddressSpace::load_be(uint32_t guest,unsigned bytes,uint64_t& value) const {
  if(bytes!=1 && bytes!=2 && bytes!=4 && bytes!=8) return MemoryError::invalid;
  uint8_t b[8]{};const auto e=read(guest,b,bytes);if(e!=MemoryError::ok)return e;
  uint64_t v=0;for(unsigned i=0;i<bytes;++i)v=(v<<8)|b[i];value=v;return MemoryError::ok;
}
MemoryError AddressSpace::store_be(uint32_t guest,unsigned bytes,uint64_t value) {
  if(bytes!=1 && bytes!=2 && bytes!=4 && bytes!=8) return MemoryError::invalid;
  uint8_t b[8]{};for(unsigned i=0;i<bytes;++i){b[bytes-i-1]=uint8_t(value);value>>=8;}
  return write(guest,b,bytes);
}
} // namespace cc::xbox
