DEFINE_REX_FUNC(sub_82146810) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// fadds f0,f1,f3
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f3.f64));
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fsubs f12,f3,f1
	ctx.f12.f64 = double(float(ctx.f3.f64 - ctx.f1.f64));
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f13,4852(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4852);
	ctx.f13.f64 = double(temp.f32);
	// lfs f1,9536(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9536);
	ctx.f1.f64 = double(temp.f32);
	// fmsubs f0,f0,f13,f2
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, -ctx.f2.f64)));
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// beq cr6,0x8214684c
	if (ctx.cr6.eq) goto loc_8214684C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f12,9632(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9632);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f0,f12
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// fdivs f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// fneg f1,f12
	ctx.f1.u64 = ctx.f12.u64 ^ 0x8000000000000000;
loc_8214684C:
	// fmadds f0,f1,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(std::fma(ctx.f1.f64, ctx.f0.f64, ctx.f13.f64)));
	// fmadds f0,f0,f1,f2
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f1.f64, ctx.f2.f64)));
	// stfs f0,0(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// blr 
	return;
}
