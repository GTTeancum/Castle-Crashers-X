DEFINE_REX_FUNC(sub_82145B18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f1.f64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f13,9588(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9588);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x82145b34
	if (ctx.cr6.gt) goto loc_82145B34;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f2,9536(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f2.f64 = double(temp.f32);
loc_82145B34:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f13,14640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14640);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4804);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82145b80
	if (ctx.cr6.lt) goto loc_82145B80;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f13,4852(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4852);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f4,f13
	ctx.f11.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// lfs f13,9540(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9540);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fcmpu cr6,f11,f13
	ctx.cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// bge cr6,0x82145b74
	if (!ctx.cr6.lt) goto loc_82145B74;
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
loc_82145B74:
	// fcmpu cr6,f0,f2
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f2.f64);
	// ble cr6,0x82145b80
	if (!ctx.cr6.gt) goto loc_82145B80;
	// fmr f2,f0
	ctx.f2.f64 = ctx.f0.f64;
loc_82145B80:
	// fcmpu cr6,f3,f2
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f3.f64, ctx.f2.f64);
	// ble cr6,0x82145bdc
	if (!ctx.cr6.gt) goto loc_82145BDC;
	// fcmpu cr6,f3,f12
	ctx.cr6.compare(ctx.f3.f64, ctx.f12.f64);
	// blt cr6,0x82145bdc
	if (ctx.cr6.lt) goto loc_82145BDC;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,9836(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9836);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f5,f0
	ctx.f0.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// fcmpu cr6,f4,f0
	ctx.cr6.compare(ctx.f4.f64, ctx.f0.f64);
	// bge cr6,0x82145bd0
	if (!ctx.cr6.lt) goto loc_82145BD0;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,-11332(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11332);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f5,f0
	ctx.f0.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// fcmpu cr6,f4,f0
	ctx.cr6.compare(ctx.f4.f64, ctx.f0.f64);
	// ble cr6,0x82145bd0
	if (!ctx.cr6.gt) goto loc_82145BD0;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f0,-27840(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27840);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f3,f0
	ctx.f13.f64 = double(float(ctx.f3.f64 * ctx.f0.f64));
	// lfs f0,9784(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9784);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f2,f2,f0,f13
	ctx.f2.f64 = double(float(std::fma(ctx.f2.f64, ctx.f0.f64, ctx.f13.f64)));
loc_82145BD0:
	// fcmpu cr6,f2,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f2.f64, ctx.f12.f64);
	// bge cr6,0x82145bdc
	if (!ctx.cr6.lt) goto loc_82145BDC;
	// fadds f2,f2,f12
	ctx.f2.f64 = double(float(ctx.f2.f64 + ctx.f12.f64));
loc_82145BDC:
	// fmr f1,f2
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f2.f64;
	// blr 
	return;
}
