DEFINE_REX_FUNC(sub_8206F0F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lfs f0,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r11,r11,-22612
	ctx.r11.s64 = ctx.r11.s64 + -22612;
	// fsubs f7,f0,f12
	ctx.f7.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// lfs f13,8(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f6,f13,f9
	ctx.f6.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// lfs f1,9536(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9536);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,-16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,-24(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// lfs f13,-12(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,-20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f13,f13,f10
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f10.f64));
	// fmuls f8,f7,f0
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// fmsubs f8,f6,f13,f8
	ctx.f8.f64 = double(float(std::fma(ctx.f6.f64, ctx.f13.f64, -ctx.f8.f64)));
	// fcmpu cr6,f8,f1
	ctx.cr6.compare(ctx.f8.f64, ctx.f1.f64);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// fsubs f5,f9,f11
	ctx.f5.f64 = double(float(ctx.f9.f64 - ctx.f11.f64));
	// fsubs f4,f12,f10
	ctx.f4.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fmuls f3,f5,f13
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// fmsubs f2,f4,f0,f3
	ctx.f2.f64 = double(float(std::fma(ctx.f4.f64, ctx.f0.f64, -ctx.f3.f64)));
	// fdivs f8,f2,f8
	ctx.f8.f64 = double(float(ctx.f2.f64 / ctx.f8.f64));
	// fcmpu cr6,f8,f1
	ctx.cr6.compare(ctx.f8.f64, ctx.f1.f64);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f5,9540(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9540);
	ctx.f5.f64 = double(temp.f32);
	// fcmpu cr6,f8,f5
	ctx.cr6.compare(ctx.f8.f64, ctx.f5.f64);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// fmuls f13,f6,f13
	ctx.f13.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// fmsubs f0,f7,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f7.f64, ctx.f0.f64, -ctx.f13.f64)));
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// fsubs f13,f11,f9
	ctx.f13.f64 = double(float(ctx.f11.f64 - ctx.f9.f64));
	// fsubs f12,f10,f12
	ctx.f12.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fmuls f11,f13,f7
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f7.f64));
	// fmsubs f10,f12,f6,f11
	ctx.f10.f64 = double(float(std::fma(ctx.f12.f64, ctx.f6.f64, -ctx.f11.f64)));
	// fdivs f0,f10,f0
	ctx.f0.f64 = double(float(ctx.f10.f64 / ctx.f0.f64));
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// fcmpu cr6,f0,f5
	ctx.cr6.compare(ctx.f0.f64, ctx.f5.f64);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// lwz r10,16(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// fdivs f13,f7,f6
	ctx.f13.f64 = double(float(ctx.f7.f64 / ctx.f6.f64));
	// lwz r9,28(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// stw r10,-8(r11)
	REX_STORE_U32(ctx.r11.u32 + -8, ctx.r10.u32);
	// stw r9,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r9.u32);
	// blr 
	return;
}
