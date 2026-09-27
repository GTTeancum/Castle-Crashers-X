DEFINE_REX_FUNC(sub_820B5788) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,16(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// lfs f11,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lwz r8,20(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// lfs f12,8(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// fmuls f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// lfs f7,0(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// std r9,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f8,-16(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// std r7,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f6,-16(r1)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// lfs f9,12(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f9.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// fcfid f2,f8
	ctx.f2.f64 = double(ctx.f8.s64);
	// fmsubs f4,f7,f9,f10
	ctx.f4.f64 = double(float(std::fma(ctx.f7.f64, ctx.f9.f64, -ctx.f10.f64)));
	// lfs f0,9540(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,9536(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 9536);
	ctx.f13.f64 = double(temp.f32);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// stfs f13,8(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f13,4(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// fdivs f1,f0,f4
	ctx.f1.f64 = double(float(ctx.f0.f64 / ctx.f4.f64));
	// frsp f3,f5
	ctx.f3.f64 = double(float(ctx.f5.f64));
	// frsp f0,f2
	ctx.f0.f64 = double(float(ctx.f2.f64));
	// fmuls f13,f1,f11
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// fmuls f11,f1,f7
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f7.f64));
	// stfs f11,12(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// fmuls f10,f1,f12
	ctx.f10.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// fmuls f9,f1,f9
	ctx.f9.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// stfs f9,0(r3)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fneg f8,f13
	ctx.f8.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f8,4(r3)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// fmuls f7,f3,f11
	ctx.f7.f64 = double(float(ctx.f3.f64 * ctx.f11.f64));
	// fneg f6,f10
	ctx.f6.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// stfs f6,8(r3)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// fmuls f5,f3,f8
	ctx.f5.f64 = double(float(ctx.f3.f64 * ctx.f8.f64));
	// fmadds f4,f0,f6,f7
	ctx.f4.f64 = double(float(std::fma(ctx.f0.f64, ctx.f6.f64, ctx.f7.f64)));
	// fmadds f3,f0,f9,f5
	ctx.f3.f64 = double(float(std::fma(ctx.f0.f64, ctx.f9.f64, ctx.f5.f64)));
	// fctiwz f2,f4
	ctx.f2.s64 = std::isnan(ctx.f4.f64) ? int64_t(0x80000000U) : (ctx.f4.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f2,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f2.u64);
	// lwz r5,-12(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// neg r4,r5
	ctx.r4.s64 = static_cast<int64_t>(-ctx.r5.u64);
	// fctiwz f1,f3
	ctx.f1.s64 = std::isnan(ctx.f3.f64) ? int64_t(0x80000000U) : (ctx.f3.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f1,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f1.u64);
	// lwz r11,-12(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// neg r10,r11
	ctx.r10.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// stw r10,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// stw r4,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// blr 
	return;
}
