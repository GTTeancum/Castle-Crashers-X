DEFINE_REX_FUNC(sub_820A85E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lbz r11,28715(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 28715);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,9544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9544);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// fmuls f13,f4,f0
	ctx.f13.f64 = double(float(ctx.f4.f64 * ctx.f0.f64));
	// fmuls f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 * ctx.f0.f64));
	// fmuls f10,f3,f0
	ctx.f10.f64 = double(float(ctx.f3.f64 * ctx.f0.f64));
	// fctidz f8,f12
	ctx.f8.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f8,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f8.u64);
	// lbz r9,-17(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + -17);
	// fctidz f9,f13
	ctx.f9.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// fctidz f7,f11
	ctx.f7.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f9,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f9.u64);
	// fctidz f6,f10
	ctx.f6.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f7,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f7.u64);
	// stfd f6,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f6.u64);
	// lbz r10,-25(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + -25);
	// lbz r8,-9(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + -9);
	// lbz r7,-17(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + -17);
	// stb r9,28736(r3)
	REX_STORE_U8(ctx.r3.u32 + 28736, ctx.r9.u8);
	// stb r10,28739(r3)
	REX_STORE_U8(ctx.r3.u32 + 28739, ctx.r10.u8);
	// stb r8,28737(r3)
	REX_STORE_U8(ctx.r3.u32 + 28737, ctx.r8.u8);
	// stb r7,28738(r3)
	REX_STORE_U8(ctx.r3.u32 + 28738, ctx.r7.u8);
	// blr 
	return;
}
