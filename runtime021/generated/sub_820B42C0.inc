DEFINE_REX_FUNC(sub_820B42C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// extsw r11,r5
	ctx.r11.s64 = ctx.r5.s32;
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// std r11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// std r10,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f10,f0
	ctx.f10.f64 = double(ctx.f0.s64);
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r8,16(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lwz r7,20(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 20);
	// lfs f9,8(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// lfs f8,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// frsp f3,f10
	ctx.f3.f64 = double(float(ctx.f10.f64));
	// std r6,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r6.u64);
	// lfd f7,-16(r1)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// std r5,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfd f6,-16(r1)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f0,f7
	ctx.f0.f64 = double(ctx.f7.s64);
	// lfs f4,12(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f4.f64 = double(temp.f32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lfs f2,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// stw r11,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// frsp f10,f0
	ctx.f10.f64 = double(float(ctx.f0.f64));
	// stw r11,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r11.u32);
	// fmuls f1,f9,f11
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// fmuls f13,f8,f11
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// frsp f12,f5
	ctx.f12.f64 = double(float(ctx.f5.f64));
	// fmadds f11,f4,f3,f1
	ctx.f11.f64 = double(float(std::fma(ctx.f4.f64, ctx.f3.f64, ctx.f1.f64)));
	// fmadds f9,f2,f3,f13
	ctx.f9.f64 = double(float(std::fma(ctx.f2.f64, ctx.f3.f64, ctx.f13.f64)));
	// fadds f8,f11,f12
	ctx.f8.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// fadds f7,f9,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 + ctx.f10.f64));
	// fctiwz f6,f8
	ctx.f6.s64 = std::isnan(ctx.f8.f64) ? int64_t(0x80000000U) : (ctx.f8.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f6,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f6.u64);
	// lwz r4,-12(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// fctiwz f5,f7
	ctx.f5.s64 = std::isnan(ctx.f7.f64) ? int64_t(0x80000000U) : (ctx.f7.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// li r12,32
	ctx.r12.s64 = 32;
	// stfiwx f5,r3,r12
	REX_STORE_U32(ctx.r3.u32 + ctx.r12.u32, ctx.f5.u32);
	// stw r4,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r4.u32);
	// blr 
	return;
}
