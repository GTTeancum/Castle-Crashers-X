// SPDX-License-Identifier: MIT
#include "asset_reader.h"
namespace cc {
namespace {
bool span(Bytes b, size_t pos, size_t n) { return pos <= b.size && n <= b.size-pos; }
uint16_t le16(const uint8_t* p) { return uint16_t(p[0]) | uint16_t(uint16_t(p[1])<<8); }
uint32_t le32(const uint8_t* p) { return uint32_t(p[0]) | (uint32_t(p[1])<<8) | (uint32_t(p[2])<<16) | (uint32_t(p[3])<<24); }
uint32_t be32(const uint8_t* p) { return (uint32_t(p[0])<<24) | (uint32_t(p[1])<<16) | (uint32_t(p[2])<<8) | uint32_t(p[3]); }
bool equal(const uint8_t* a, const uint8_t* b, size_t n) { for(size_t i=0;i<n;++i) if(a[i]!=b[i]) return false; return true; }
Error walk(Bytes bytes, size_t& pos, size_t end, unsigned depth, SwfStats& s) {
    if(depth>64) return Error::depth;
    if(depth>s.max_depth) s.max_depth=depth;
    while(pos<end) {
        if(end-pos<2) return Error::truncated;
        const uint16_t h=le16(bytes.data+pos); pos+=2;
        const unsigned tag=h>>6;
        size_t length=h&63;
        if(length==63) { if(end-pos<4) return Error::truncated; length=le32(bytes.data+pos); pos+=4; }
        if(length>end-pos) return Error::truncated;
        ++s.tags[tag];
        const size_t next=pos+length;
        if(tag==0) { if(length!=0) return Error::corrupt; return Error::ok; }
        if(tag==39) {
            if(length<4) return Error::corrupt;
            size_t nested=pos+4;
            Error e=walk(bytes,nested,next,depth+1,s);
            if(e!=Error::ok) return e;
            // Cooked streams can contain padding after End. Never execute it.
        }
        pos=next;
    }
    return Error::missing_end;
}
}
const char* error_name(Error e) {
    switch(e) {
    case Error::ok:return "ok"; case Error::truncated:return "truncated";
    case Error::signature:return "signature"; case Error::unsupported:return "unsupported";
    case Error::corrupt:return "corrupt"; case Error::crc:return "crc";
    case Error::depth:return "depth"; case Error::missing_end:return "missing_end";
    }
    return "invalid_error";
}
uint32_t crc32(Bytes b) {
    uint32_t c=0xffffffffu;
    for(size_t i=0;i<b.size;++i) {
        c^=b.data[i];
        for(unsigned bit=0;bit<8;++bit) c=(c>>1)^((0u-(c&1u))&0xedb88320u);
    }
    return c^0xffffffffu;
}
Error visit_pak(Bytes b, Visitor visitor, void* context) {
    if(b.size<22) return Error::truncated;
    size_t eocd=b.size-22;
    const size_t floor=b.size>65557?b.size-65557:0;
    for(;;) {
        if(le32(b.data+eocd)==0x06054b50u && le16(b.data+eocd+20)==b.size-eocd-22) break;
        if(eocd==floor) return Error::signature;
        --eocd;
    }
    const uint8_t* e=b.data+eocd;
    const uint16_t count=le16(e+10);
    if(le16(e+4)||le16(e+6)||le16(e+8)!=count ||count==65535) return Error::unsupported;
    const size_t size=le32(e+12), offset=le32(e+16);
    if(!span(b,offset,size) || offset>eocd || size!=eocd-offset) return Error::corrupt;
    size_t p=offset;
    for(unsigned i=0;i<count;++i) {
        if(p>eocd || eocd-p<46) return Error::truncated;
        const uint8_t* c=b.data+p;
        if(le32(c)!=0x02014b50u) return Error::signature;
        if(le16(c+8)!=0 || le16(c+10)!=0 || le16(c+34)!=0) return Error::unsupported;
        const size_t packed=le32(c+20), unpacked=le32(c+24);
        if(packed!=unpacked || packed==0xffffffffu) return Error::unsupported;
        const size_t nlen=le16(c+28), xlen=le16(c+30), clen=le16(c+32);
        const size_t total=46+nlen+xlen+clen;
        if(total>eocd-p) return Error::truncated;
        const size_t local=le32(c+42);
        if(local>offset || offset-local<30) return Error::truncated;
        const uint8_t* l=b.data+local;
        if(le32(l)!=0x04034b50u) return Error::signature;
        if(le16(l+6)!=0 || le16(l+8)!=0) return Error::unsupported;
        if(le32(l+14)!=le32(c+16) || le32(l+18)!=packed || le32(l+22)!=unpacked || le16(l+26)!=nlen) return Error::corrupt;
        const size_t header=30+nlen+le16(l+28);
        if(header>offset-local) return Error::truncated;
        const size_t start=local+header;
        if(packed>offset-start) return Error::truncated;
        if(!equal(l+30,c+46,nlen)) return Error::corrupt;
        Member m{{c+46,nlen},{b.data+start,packed},le32(c+16)};
        if(crc32(m.data)!=m.crc) return Error::crc;
        if(visitor) { Error result=visitor(m,context); if(result!=Error::ok) return result; }
        p+=total;
    }
    return p==eocd?Error::ok:Error::corrupt;
}
Error scan_cok6(Bytes b, SwfStats& s) {
    for(unsigned i=0;i<1024;++i) s.tags[i]=0;
    s.declared_bytes=0; s.wrapper_payload_bytes=0; s.consumed_bytes=0;
    s.max_depth=0; s.version=0;
    if(b.size<24) return Error::truncated;
    if(be32(b.data)!=0x434f4b36u) return Error::signature;
    const size_t size=be32(b.data+16), offset=be32(b.data+20);
    if(offset<24 || !span(b,offset,size)) return Error::truncated;
    if(size<13) return Error::truncated;
    Bytes swf{b.data+offset,size};
    if(swf.data[0]!='F'||swf.data[1]!='W'||swf.data[2]!='S') return Error::signature;
    if(swf.data[3]!=6) return Error::unsupported;
    s.version=swf.data[3]; s.declared_bytes=le32(swf.data+4); s.wrapper_payload_bytes=uint32_t(size);
    const unsigned bits=swf.data[8]>>3;
    const size_t rectangle=(5+4*bits+7)/8;
    size_t pos=8+rectangle+4;
    if(pos>size) return Error::truncated;
    Error result=walk(swf,pos,size,0,s);
    s.consumed_bytes=uint32_t(pos);
    return result;
}
}
