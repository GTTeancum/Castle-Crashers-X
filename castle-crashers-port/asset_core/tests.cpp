// SPDX-License-Identifier: MIT
#include "asset_reader.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using V=std::vector<uint8_t>;
static unsigned checks=0;
static void check(bool value,const char* label) { ++checks; if(!value) { std::cerr<<"FAIL: "<<label<<'\n'; std::exit(1); } }
static cc::Bytes view(const V& b) { return {b.data(),b.size()}; }
static void u16(V& b,size_t p,uint16_t n) { b[p]=uint8_t(n);b[p+1]=uint8_t(n>>8); }
static void u32(V& b,size_t p,uint32_t n) { for(unsigned i=0;i<4;++i) b[p+i]=uint8_t(n>>(8*i)); }
static void be32(V& b,size_t p,uint32_t n) { for(unsigned i=0;i<4;++i)b[p+i]=uint8_t(n>>(24-8*i)); }
static V pak() {
    const V content{'a','b','c'}; const uint32_t crc=cc::crc32(view(content));
    V z(31,0);u32(z,0,0x04034b50);u16(z,4,20);u32(z,14,crc);u32(z,18,3);u32(z,22,3);u16(z,26,1);z[30]='x';
    z.insert(z.end(),content.begin(),content.end()); const auto start=z.size();z.resize(start+47);
    u32(z,start,0x02014b50);u16(z,start+4,20);u16(z,start+6,20);u32(z,start+16,crc);u32(z,start+20,3);u32(z,start+24,3);u16(z,start+28,1);z[start+46]='x';
    const auto end=z.size();z.resize(end+22);u32(z,end,0x06054b50);u16(z,end+8,1);u16(z,end+10,1);u32(z,end+12,47);u32(z,end+16,uint32_t(start));return z;
}
static V cok(V tags) {
    V b(24+13,0); b[0]='C';b[1]='O';b[2]='K';b[3]='6';be32(b,20,24);
    b[24]='F';b[25]='W';b[26]='S';b[27]=6;b.insert(b.end(),tags.begin(),tags.end());
    be32(b,16,uint32_t(b.size()-24));u32(b,28,uint32_t(b.size()-24));return b;
}
static cc::Error visitor(const cc::Member& m,void* count) { ++*static_cast<unsigned*>(count);return m.data.size==3?cc::Error::ok:cc::Error::corrupt; }
int main() {
    const std::string known="123456789";
    check(cc::crc32({reinterpret_cast<const uint8_t*>(known.data()),known.size()})==0xcbf43926u,"CRC32 known vector");
    V z=pak();unsigned visited=0;
    check(cc::visit_pak(view(z),visitor,&visited)==cc::Error::ok && visited==1,"stored ZIP member");
    for(size_t n=0;n<z.size();++n) check(cc::visit_pak({z.data(),n},nullptr,nullptr)!=cc::Error::ok,"truncated ZIP rejected");
    auto bad=z;bad[31]^=1;check(cc::visit_pak(view(bad),nullptr,nullptr)==cc::Error::crc,"CRC damage rejected");
    bad=z;bad[34+8]=1;check(cc::visit_pak(view(bad),nullptr,nullptr)==cc::Error::unsupported,"encrypted entry rejected");
    bad=z;bad[34+10]=8;check(cc::visit_pak(view(bad),nullptr,nullptr)==cc::Error::unsupported,"compressed entry rejected");
    bad=z;u32(bad,34+42,0xffffffff);check(cc::visit_pak(view(bad),nullptr,nullptr)!=cc::Error::ok,"invalid local offset rejected");
    cc::SwfStats s{};V c=cok({0x40,0x00,0x00,0x00});
    check(cc::scan_cok6(view(c),s)==cc::Error::ok && s.tags[1]==1 && s.tags[0]==1,"basic SWF tag walk");
    for(size_t n=0;n<c.size();++n) check(cc::scan_cok6({c.data(),n},s)!=cc::Error::ok,"truncated COK6 rejected");
    bad=c;bad[24]='C';check(cc::scan_cok6(view(bad),s)==cc::Error::signature,"compressed Flash unsupported");
    bad=c;be32(bad,20,0xfffffff0);check(cc::scan_cok6(view(bad),s)==cc::Error::truncated,"wrapper offset rejected");
    bad=cok({0x40,0x00});check(cc::scan_cok6(view(bad),s)==cc::Error::missing_end,"missing End rejected");
    bad=cok({0x3f,0x00,0xff,0xff,0xff,0xff});check(cc::scan_cok6(view(bad),s)==cc::Error::truncated,"extended length overflow rejected");
    bad=cok({0x80,0x23,0x00,0x00});check(cc::scan_cok6(view(bad),s)==cc::Error::ok && s.tags[142]==1,"unknown cooked tag counted without interpreting");
    V tags{0,0};
    for(unsigned i=0;i<66;++i) {
        V next(10,0);u16(next,0,uint16_t((39<<6)|63));u32(next,2,uint32_t(4+tags.size()));
        next.insert(next.end(),tags.begin(),tags.end());next.insert(next.end(),{0,0});tags=next;
    }
    bad=cok(tags);check(cc::scan_cok6(view(bad),s)==cc::Error::depth,"sprite recursion limited");
    // Deterministic malformed-input smoke test; not a security certification.
    uint32_t seed=0xC0456u;
    for(unsigned i=0;i<10000;++i) {
        V m=(i&1)?c:z;
        seed=1664525u*seed+1013904223u;size_t at=seed%m.size();
        seed=1664525u*seed+1013904223u;m[at]^=uint8_t(seed>>24);
        if(i&1) (void)cc::scan_cok6(view(m),s);else (void)cc::visit_pak(view(m),nullptr,nullptr);
    }
    std::cout<<"PASS: "<<checks<<" assertions, 10000 deterministic malformed-input probes\n";
}
