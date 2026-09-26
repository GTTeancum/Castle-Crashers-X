#include "replay.h"
#include <stdio.h>
#include <vector>
#include <chrono>
int main(int argc,char**argv){
 if(argc!=3){fprintf(stderr,"Usage: cc_replay input.ccr output.ppm\n");return 2;}
 FILE*f=fopen(argv[1],"rb");if(!f){perror("input");return 1;}fseek(f,0,SEEK_END);long n=ftell(f);rewind(f);
 if(n<0||n>long(cc::replay::max_bytes)){fclose(f);return 1;}std::vector<uint8_t>b(static_cast<size_t>(n));if(fread(b.data(),1,b.size(),f)!=b.size()){fclose(f);return 1;}fclose(f);
 cc::replay::View v;auto err=cc::replay::parse(b.data(),b.size(),v);if(err!=cc::replay::Error::ok){fprintf(stderr,"Invalid replay: %s\n",cc::replay::name(err));return 1;}
 std::vector<uint8_t>pixels(size_t(v.width)*v.height*4);auto start=std::chrono::steady_clock::now();err=cc::replay::render(v,pixels.data(),pixels.size());auto elapsed=std::chrono::duration<double>(std::chrono::steady_clock::now()-start).count();
 if(err!=cc::replay::Error::ok)return 1;f=fopen(argv[2],"wb");if(!f){perror("output");return 1;}fprintf(f,"P6\n%u %u\n255\n",v.width,v.height);bool ok=true;
 for(size_t i=0;i<pixels.size();i+=4)if(fwrite(pixels.data()+i,1,3,f)!=3){ok=false;break;}if(fclose(f))ok=false;
 printf("Replay: %u draws, %u textures, %ux%u; host render %.6f seconds. Not Xbox execution.\n",v.draws,v.textures,v.width,v.height,elapsed);return ok?0:1;
}
