// SPDX-License-Identifier: MIT
#include "asset_reader.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <stdexcept>
struct Total { uint64_t members=0,swfs=0; std::array<uint64_t,1024> tags{}; std::map<std::string,uint64_t> types; };
static cc::Error member(const cc::Member& m,void* ctx) {
    auto& total=*static_cast<Total*>(ctx); ++total.members;
    if(m.data.size<4) return cc::Error::truncated;
    const std::string magic(reinterpret_cast<const char*>(m.data.data),4); ++total.types[magic];
    if(magic=="COK6") {
        cc::SwfStats s{}; auto error=cc::scan_cok6(m.data,s);
        if(error!=cc::Error::ok) {
            std::cerr<<std::string(reinterpret_cast<const char*>(m.name.data),m.name.size)<<": "<<cc::error_name(error)<<'\n';
            return error;
        }
        ++total.swfs; for(size_t i=0;i<1024;++i) total.tags[i]+=s.tags[i];
    }
    return cc::Error::ok;
}
int main(int argc,char** argv) {
    if(argc!=2) { std::cerr<<"Usage: cc_asset_probe EXTRACTED_DIRECTORY\n"; return 2; }
    try {
        Total total; uint64_t packages=0;
        for(const auto& entry:std::filesystem::recursive_directory_iterator(argv[1])) {
            if(!entry.is_regular_file() || entry.path().extension()!=".pak") continue;
            const auto size=entry.file_size();
            if(size>256*1024*1024) throw std::runtime_error("Probe package exceeds 256 MiB host safety limit");
            std::vector<uint8_t> bytes(static_cast<size_t>(size));
            std::ifstream file(entry.path(),std::ios::binary);
            if(!file.read(reinterpret_cast<char*>(bytes.data()),static_cast<std::streamsize>(bytes.size()))) throw std::runtime_error("File read failed: "+entry.path().string());
            const auto result=cc::visit_pak({bytes.data(),bytes.size()},member,&total);
            if(result!=cc::Error::ok) throw std::runtime_error(entry.path().string()+": "+cc::error_name(result));
            ++packages;
        }
        if(packages==0) throw std::runtime_error("No .pak files found");
        std::cout<<"{\n  \"pak_count\": "<<packages<<",\n  \"member_count\": "<<total.members
                 <<",\n  \"swf_count\": "<<total.swfs<<",\n  \"tags\": {";
        bool first=true;
        for(size_t i=0;i<1024;++i) if(total.tags[i]) { std::cout<<(first?"":",")<<"\n    \""<<i<<"\": "<<total.tags[i]; first=false; }
        std::cout<<"\n  },\n  \"brec_types\": {"; first=true;
        for(const auto& [name,n]:total.types) { std::cout<<(first?"":",")<<"\n    \""<<name<<"\": "<<n; first=false; }
        std::cout<<"\n  }\n}\n"; return 0;
    } catch(const std::exception& e) { std::cerr<<e.what()<<'\n'; return 1; }
}
