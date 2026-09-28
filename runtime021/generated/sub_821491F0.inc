DEFINE_REX_FUNC(sub_821491F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// extsh r11,r4
	ctx.r11.s64 = ctx.r4.s16;
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// blt cr6,0x82149200
	if (ctx.cr6.lt) goto loc_82149200;
	// li r4,255
	ctx.r4.s64 = 255;
loc_82149200:
	// lbz r11,20(r6)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r6.u32 + 20);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82149248
	if (!ctx.cr6.eq) goto loc_82149248;
	// lbz r11,21(r6)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r6.u32 + 21);
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,16(r6)
	REX_STORE_U16(ctx.r6.u32 + 16, ctx.r10.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821492b0
	if (!ctx.cr6.eq) goto loc_821492B0;
	// extsh r11,r4
	ctx.r11.s64 = ctx.r4.s16;
	// std r11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x821492b0
	if (ctx.cr6.lt) goto loc_821492B0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,21(r6)
	REX_STORE_U8(ctx.r6.u32 + 21, ctx.r11.u8);
	// b 0x821492b0
	goto loc_821492B0;
loc_82149248:
	// clrlwi r8,r5,16
	ctx.r8.u64 = ctx.r5.u32 & 0xFFFF;
	// lfs f13,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lhz r9,16(r6)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r6.u32 + 16);
	// std r8,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f0,-16(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// frsp f12,f0
	ctx.f12.f64 = double(float(ctx.f0.f64));
	// lfs f0,4852(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4852);
	ctx.f0.f64 = double(temp.f32);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// sth r11,16(r6)
	REX_STORE_U16(ctx.r6.u32 + 16, ctx.r11.u16);
	// fmadds f0,f13,f12,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f12.f64, ctx.f0.f64)));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// lha r11,-10(r1)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r1.u32 + -10));
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x821492b0
	if (!ctx.cr6.gt) goto loc_821492B0;
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,32700
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32700, ctx.xer);
	// stb r10,21(r6)
	REX_STORE_U8(ctx.r6.u32 + 21, ctx.r10.u8);
	// ble cr6,0x821492b0
	if (!ctx.cr6.gt) goto loc_821492B0;
	// li r11,32700
	ctx.r11.s64 = 32700;
	// sth r11,16(r6)
	REX_STORE_U16(ctx.r6.u32 + 16, ctx.r11.u16);
loc_821492B0:
	// lbz r11,21(r6)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r6.u32 + 21);
	// extsb r3,r11
	ctx.r3.s64 = ctx.r11.s8;
	// blr 
	return;
}
