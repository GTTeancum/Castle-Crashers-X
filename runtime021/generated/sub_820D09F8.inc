DEFINE_REX_FUNC(sub_820D09F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stfd f29,-32(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f29.u64);
	// stfd f30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f30.u64);
	// stfd f31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,9540(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// fabs f13,f31
	ctx.f13.u64 = ctx.f31.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x820d0a74
	if (!ctx.cr6.lt) goto loc_820D0A74;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fabs f1,f31
	ctx.f1.u64 = ctx.f31.u64 & ~0x8000000000000000;
	// lfs f2,5928(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5928);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x820d0008
	ctx.lr = 0x820D0A38;
	sub_820D0008(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lfs f2,9632(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9632);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x820d0008
	ctx.lr = 0x820D0A4C;
	sub_820D0008(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,9656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9656);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// lfs f0,14448(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14448);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,14636(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14636);
	ctx.f13.f64 = double(temp.f32);
	// fmsubs f0,f30,f0,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f30.f64, ctx.f0.f64, -ctx.f12.f64)));
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// b 0x820d0ae0
	goto loc_820D0AE0;
loc_820D0A74:
	// fabs f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f31.u64 & ~0x8000000000000000;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f2,9632(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9632);
	ctx.f2.f64 = double(temp.f32);
	// fcmpu cr6,f0,f2
	ctx.cr6.compare(ctx.f0.f64, ctx.f2.f64);
	// bge cr6,0x820d0ad8
	if (!ctx.cr6.lt) goto loc_820D0AD8;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x820d0008
	ctx.lr = 0x820D0A90;
	sub_820D0008(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f1.f64;
	// fabs f1,f31
	ctx.f1.u64 = ctx.f31.u64 & ~0x8000000000000000;
	// lfs f30,5928(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5928);
	ctx.f30.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// bl 0x820d0008
	ctx.lr = 0x820D0AA8;
	sub_820D0008(ctx, base);
	// fmuls f11,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// fabs f10,f31
	ctx.f10.u64 = ctx.f31.u64 & ~0x8000000000000000;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,9656(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9656);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,14632(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14632);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,14628(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14628);
	ctx.f12.f64 = double(temp.f32);
	// fmsubs f0,f29,f0,f11
	ctx.f0.f64 = double(float(std::fma(ctx.f29.f64, ctx.f0.f64, -ctx.f11.f64)));
	// fnmsubs f0,f10,f13,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f10.f64, ctx.f13.f64, -ctx.f0.f64)));
	// fadds f1,f0,f12
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// b 0x820d0ae0
	goto loc_820D0AE0;
loc_820D0AD8:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f1,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f1.f64 = double(temp.f32);
loc_820D0AE0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f29,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f30,-24(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// lfd f31,-16(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
