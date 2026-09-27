DEFINE_REX_FUNC(sub_82078910) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// lfs f12,9536(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9536);
	ctx.f12.f64 = double(temp.f32);
	// blt cr6,0x8207892c
	if (ctx.cr6.lt) goto loc_8207892C;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
	// b 0x8207893c
	goto loc_8207893C;
loc_8207892C:
	// addi r11,r11,13
	ctx.r11.s64 = ctx.r11.s64 + 13;
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lfsx f0,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	ctx.f0.f64 = double(temp.f32);
loc_8207893C:
	// lbz r11,64(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 64);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82078960
	if (ctx.cr6.eq) goto loc_82078960;
	// lfs f13,68(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x82078960
	if (ctx.cr6.gt) goto loc_82078960;
	// fneg f13,f13
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8207896c
	if (!ctx.cr6.lt) goto loc_8207896C;
loc_82078960:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// li r11,1
	ctx.r11.s64 = 1;
	// blt cr6,0x82078970
	if (ctx.cr6.lt) goto loc_82078970;
loc_8207896C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82078970:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}
