DEFINE_REX_FUNC(sub_820A1720) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lhz r11,128(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 128);
	// li r10,0
	ctx.r10.s64 = 0;
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a1738
	if (ctx.cr6.eq) goto loc_820A1738;
	// li r10,1
	ctx.r10.s64 = 1;
loc_820A1738:
	// rlwinm r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a174c
	if (ctx.cr6.eq) goto loc_820A174C;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
loc_820A174C:
	// rlwinm r9,r11,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a1760
	if (ctx.cr6.eq) goto loc_820A1760;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// ori r10,r10,4
	ctx.r10.u64 = ctx.r10.u64 | 4;
loc_820A1760:
	// rlwinm r9,r11,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a1774
	if (ctx.cr6.eq) goto loc_820A1774;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// ori r10,r10,8
	ctx.r10.u64 = ctx.r10.u64 | 8;
loc_820A1774:
	// rlwinm r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a1788
	if (ctx.cr6.eq) goto loc_820A1788;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// ori r10,r10,16
	ctx.r10.u64 = ctx.r10.u64 | 16;
loc_820A1788:
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a179c
	if (ctx.cr6.eq) goto loc_820A179C;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// ori r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 | 32;
loc_820A179C:
	// rlwinm r9,r11,0,23,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a17b0
	if (ctx.cr6.eq) goto loc_820A17B0;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// ori r10,r10,256
	ctx.r10.u64 = ctx.r10.u64 | 256;
loc_820A17B0:
	// rlwinm r9,r11,0,22,22
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a17c4
	if (ctx.cr6.eq) goto loc_820A17C4;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// ori r10,r10,512
	ctx.r10.u64 = ctx.r10.u64 | 512;
loc_820A17C4:
	// rlwinm r9,r11,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a17d8
	if (ctx.cr6.eq) goto loc_820A17D8;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// ori r10,r10,8192
	ctx.r10.u64 = ctx.r10.u64 | 8192;
loc_820A17D8:
	// rlwinm r9,r11,0,18,18
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a17ec
	if (ctx.cr6.eq) goto loc_820A17EC;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// ori r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 32768;
loc_820A17EC:
	// rlwinm r9,r11,0,17,17
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a1800
	if (ctx.cr6.eq) goto loc_820A1800;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// ori r10,r10,16384
	ctx.r10.u64 = ctx.r10.u64 | 16384;
loc_820A1800:
	// rlwinm r11,r11,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a1814
	if (ctx.cr6.eq) goto loc_820A1814;
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// ori r10,r11,4096
	ctx.r10.u64 = ctx.r11.u64 | 4096;
loc_820A1814:
	// lbz r11,130(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 130);
	// cmplwi cr6,r11,64
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64, ctx.xer);
	// ble cr6,0x820a1828
	if (!ctx.cr6.gt) goto loc_820A1828;
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// ori r10,r11,1024
	ctx.r10.u64 = ctx.r11.u64 | 1024;
loc_820A1828:
	// lbz r11,131(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 131);
	// cmplwi cr6,r11,64
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64, ctx.xer);
	// ble cr6,0x820a183c
	if (!ctx.cr6.gt) goto loc_820A183C;
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// ori r10,r11,2048
	ctx.r10.u64 = ctx.r11.u64 | 2048;
loc_820A183C:
	// lhz r11,132(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 132);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// extsh r5,r11
	ctx.r5.s64 = ctx.r11.s16;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// std r5,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f11,9560(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9560);
	ctx.f11.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f10,9556(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9556);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,9552(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 9552);
	ctx.f9.f64 = double(temp.f32);
	// li r11,0
	ctx.r11.s64 = 0;
	// fmuls f0,f12,f11
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x820a1884
	if (!ctx.cr6.lt) goto loc_820A1884;
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x820a1890
	goto loc_820A1890;
loc_820A1884:
	// fcmpu cr6,f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f9.f64);
	// bge cr6,0x820a1890
	if (!ctx.cr6.lt) goto loc_820A1890;
	// li r11,64
	ctx.r11.s64 = 64;
loc_820A1890:
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r8,r9,17912
	ctx.r8.s64 = ctx.r9.s64 + 17912;
	// lfs f12,17912(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 17912);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x820a18b4
	if (!ctx.cr6.gt) goto loc_820A18B4;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// ori r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 8;
	// b 0x820a18c4
	goto loc_820A18C4;
loc_820A18B4:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x820a18c4
	if (!ctx.cr6.gt) goto loc_820A18C4;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// ori r11,r11,128
	ctx.r11.u64 = ctx.r11.u64 | 128;
loc_820A18C4:
	// lhz r9,134(r3)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r3.u32 + 134);
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// std r7,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f8,f0
	ctx.f8.f64 = double(ctx.f0.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmuls f0,f7,f11
	ctx.f0.f64 = double(float(ctx.f7.f64 * ctx.f11.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x820a18f4
	if (!ctx.cr6.gt) goto loc_820A18F4;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// b 0x820a1904
	goto loc_820A1904;
loc_820A18F4:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x820a1904
	if (!ctx.cr6.gt) goto loc_820A1904;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// ori r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 16;
loc_820A1904:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// sth r10,32(r3)
	REX_STORE_U16(ctx.r3.u32 + 32, ctx.r10.u16);
	// bge cr6,0x820a1920
	if (!ctx.cr6.lt) goto loc_820A1920;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// ori r10,r11,2
	ctx.r10.u64 = ctx.r11.u64 | 2;
	// stb r10,34(r3)
	REX_STORE_U8(ctx.r3.u32 + 34, ctx.r10.u8);
	// blr 
	return;
loc_820A1920:
	// fcmpu cr6,f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f9.f64);
	// bge cr6,0x820a1938
	if (!ctx.cr6.lt) goto loc_820A1938;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// ori r10,r11,32
	ctx.r10.u64 = ctx.r11.u64 | 32;
	// stb r10,34(r3)
	REX_STORE_U8(ctx.r3.u32 + 34, ctx.r10.u8);
	// blr 
	return;
loc_820A1938:
	// stb r11,34(r3)
	REX_STORE_U8(ctx.r3.u32 + 34, ctx.r11.u8);
	// blr 
	return;
}
