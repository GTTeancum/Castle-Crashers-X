DEFINE_REX_FUNC(sub_820B5698) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r5,32(r1)
	REX_STORE_U64(ctx.r1.u32 + 32, ctx.r5.u64);
	// lfs f12,32(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// std r6,40(r1)
	REX_STORE_U64(ctx.r1.u32 + 40, ctx.r6.u64);
	// lfs f0,40(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// std r7,48(r1)
	REX_STORE_U64(ctx.r1.u32 + 48, ctx.r7.u64);
	// lfs f13,44(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lwz r6,52(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 52);
	// lfs f11,36(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 36);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,48(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 48);
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// lwz r10,16(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// extsw r11,r6
	ctx.r11.s64 = ctx.r6.s32;
	// lwz r8,20(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// lfs f10,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// std r9,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f8,-16(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// extsw r5,r8
	ctx.r5.s64 = ctx.r8.s32;
	// std r7,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f7,-16(r1)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// std r5,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfd f6,-16(r1)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// std r11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f5,-16(r1)
	ctx.f5.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f7,f7
	ctx.f7.f64 = double(ctx.f7.s64);
	// lfs f9,12(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f9.f64 = double(temp.f32);
	// fcfid f8,f8
	ctx.f8.f64 = double(ctx.f8.s64);
	// lfs f3,0(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// lfs f1,8(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// fcfid f6,f6
	ctx.f6.f64 = double(ctx.f6.s64);
	// li r10,16
	ctx.r10.s64 = 16;
	// fmuls f5,f10,f0
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// li r9,20
	ctx.r9.s64 = 20;
	// fmuls f0,f9,f0
	ctx.f0.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// frsp f8,f8
	ctx.f8.f64 = double(float(ctx.f8.f64));
	// frsp f2,f4
	ctx.f2.f64 = double(float(ctx.f4.f64));
	// fmuls f4,f10,f13
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fmuls f13,f9,f13
	ctx.f13.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fmuls f10,f2,f10
	ctx.f10.f64 = double(float(ctx.f2.f64 * ctx.f10.f64));
	// fmuls f2,f2,f9
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f9.f64));
	// frsp f9,f7
	ctx.f9.f64 = double(float(ctx.f7.f64));
	// frsp f7,f6
	ctx.f7.f64 = double(float(ctx.f6.f64));
	// fmadds f6,f3,f12,f5
	ctx.f6.f64 = double(float(std::fma(ctx.f3.f64, ctx.f12.f64, ctx.f5.f64)));
	// stfs f6,0(r3)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fmadds f5,f3,f11,f4
	ctx.f5.f64 = double(float(std::fma(ctx.f3.f64, ctx.f11.f64, ctx.f4.f64)));
	// stfs f5,4(r3)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// fmadds f4,f1,f12,f0
	ctx.f4.f64 = double(float(std::fma(ctx.f1.f64, ctx.f12.f64, ctx.f0.f64)));
	// stfs f4,8(r3)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// fmadds f0,f1,f11,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f1.f64, ctx.f11.f64, ctx.f13.f64)));
	// stfs f0,12(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// fmadds f13,f8,f3,f10
	ctx.f13.f64 = double(float(std::fma(ctx.f8.f64, ctx.f3.f64, ctx.f10.f64)));
	// fmadds f12,f8,f1,f2
	ctx.f12.f64 = double(float(std::fma(ctx.f8.f64, ctx.f1.f64, ctx.f2.f64)));
	// fadds f11,f13,f9
	ctx.f11.f64 = double(float(ctx.f13.f64 + ctx.f9.f64));
	// fadds f10,f12,f7
	ctx.f10.f64 = double(float(ctx.f12.f64 + ctx.f7.f64));
	// fctiwz f9,f11
	ctx.f9.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfiwx f9,r3,r10
	REX_STORE_U32(ctx.r3.u32 + ctx.r10.u32, ctx.f9.u32);
	// fctiwz f8,f10
	ctx.f8.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x80000000U) : (ctx.f10.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfiwx f8,r3,r9
	REX_STORE_U32(ctx.r3.u32 + ctx.r9.u32, ctx.f8.u32);
	// blr 
	return;
}
