// Native submission retained from the now boot-tested 004 backend.
static void shader(){
 static const uint32_t program[]={
 #include "vs.inl"
 };
 auto*p=pb_begin();p=pb_push1(p,NV097_SET_TRANSFORM_PROGRAM_START,0);
 p=pb_push1(p,NV097_SET_TRANSFORM_EXECUTION_MODE,NV097_SET_TRANSFORM_EXECUTION_MODE_MODE_PROGRAM|(NV097_SET_TRANSFORM_EXECUTION_MODE_RANGE_MODE_PRIV<<2));
 p=pb_push1(p,NV097_SET_TRANSFORM_PROGRAM_CXT_WRITE_EN,0);p=pb_push1(p,NV097_SET_TRANSFORM_PROGRAM_LOAD,0);pb_end(p);
 for(size_t i=0;i<sizeof(program)/sizeof(program[0]);i+=4){p=pb_begin();pb_push(p++,NV097_SET_TRANSFORM_PROGRAM,4);std::memcpy(p,program+i,16);p+=4;pb_end(p);}
 p=pb_begin();
 #include "ps.inl"
 pb_end(p);
}
static void attributes(const cc::stream::Scene&scene){
 auto*p=pb_begin();pb_push(p++,NV097_SET_VERTEX_DATA_ARRAY_FORMAT,16);for(int i=0;i<16;++i)*p++=NV097_SET_VERTEX_DATA_ARRAY_FORMAT_TYPE_F;pb_end(p);
 struct Attribute{uint32_t index,components,offset;};
 for(auto a:{Attribute{0,4,0},Attribute{3,4,16},Attribute{9,2,32}}){p=pb_begin();p=pb_push1(p,NV097_SET_VERTEX_DATA_ARRAY_FORMAT+4*a.index,NV097_SET_VERTEX_DATA_ARRAY_FORMAT_TYPE_F|(a.components<<4)|(sizeof(GpuVertex)<<8));p=pb_push1(p,NV097_SET_VERTEX_DATA_ARRAY_OFFSET+4*a.index,physical(reinterpret_cast<const uint8_t*>(scene.vertices())+a.offset));pb_end(p);}
}

static void render(const cc::stream::Scene&scene,uint32_t draw_count){
  pb_wait_for_vbl();pb_reset();pb_target_back_buffer();pb_erase_depth_stencil_buffer(0,0,640,480);pb_fill(0,0,640,480,0xff000000);while(pb_busy()){}
  shader();attributes(scene);auto*p=pb_begin();
  p=pb_push1(p,NV097_SET_DEPTH_TEST_ENABLE,0);p=pb_push1(p,NV097_SET_DEPTH_MASK,0);p=pb_push1(p,NV097_SET_STENCIL_TEST_ENABLE,0);p=pb_push1(p,NV097_SET_CULL_FACE_ENABLE,0);p=pb_push1(p,NV097_SET_FOG_ENABLE,0);p=pb_push1(p,NV097_SET_ALPHA_TEST_ENABLE,0);p=pb_push1(p,NV097_SET_BLEND_ENABLE,1);p=pb_push1(p,NV097_SET_BLEND_FUNC_SFACTOR,NV097_SET_BLEND_FUNC_SFACTOR_V_ONE);p=pb_push1(p,NV097_SET_BLEND_EQUATION,NV097_SET_BLEND_EQUATION_V_FUNC_ADD);p=pb_push1(p,NV097_SET_COLOR_MASK,0x01010101);
  for(unsigned i=1;i<4;++i)p=pb_push1(p,NV097_SET_TEXTURE_CONTROL0+64*i,0);
  pb_end(p);
  for(uint32_t i=0;i<draw_count;++i){const auto&cmd=scene.command(i);const auto&g=scene.texture(cmd.texture);p=pb_begin();
   // Linear A8R8G8B8, 2D, one mip, DMA context 2; samples use unnormalized UVs.
   p=pb_push1(p,NV097_SET_TEXTURE_OFFSET,physical(g.data));p=pb_push1(p,NV097_SET_TEXTURE_FORMAT,0x0001122a);
   p=pb_push1(p,NV097_SET_TEXTURE_CONTROL1,g.pitch<<16);p=pb_push1(p,NV097_SET_TEXTURE_IMAGE_RECT,(g.width<<16)|g.height);
   p=pb_push1(p,NV097_SET_TEXTURE_ADDRESS,0x00050505); // clamp-to-edge in U/V/P
   p=pb_push1(p,NV097_SET_TEXTURE_CONTROL0,0x40000000); // enabled, LOD 0 only
   p=pb_push1(p,NV097_SET_TEXTURE_FILTER,0x02022000); // linear min/mag, no mipmaps
   p=pb_push1(p,NV097_SET_BLEND_FUNC_DFACTOR,cmd.blend==0x07010701?NV097_SET_BLEND_FUNC_DFACTOR_V_ONE_MINUS_SRC_ALPHA:NV097_SET_BLEND_FUNC_DFACTOR_V_ZERO);
   p=pb_push1(p,NV097_SET_BEGIN_END,NV097_SET_BEGIN_END_OP_TRIANGLES);p=pb_push1(p,0x40000000|NV097_DRAW_ARRAYS,(5u<<24)|(6*i));p=pb_push1(p,NV097_SET_BEGIN_END,NV097_SET_BEGIN_END_OP_END);pb_end(p);
  }
  while(pb_busy()){}while(pb_finished()){}
}
