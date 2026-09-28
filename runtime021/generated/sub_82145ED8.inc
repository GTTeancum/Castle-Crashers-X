DEFINE_REX_FUNC(sub_82145ED8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// fmr f13,f4
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f4.f64;
	// lfs f0,9836(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9836);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// fcmpu cr6,f2,f0
	ctx.cr6.compare(ctx.f2.f64, ctx.f0.f64);
	// bgt cr6,0x82145f18
	if (ctx.cr6.gt) goto loc_82145F18;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,-11332(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11332);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// fcmpu cr6,f2,f0
	ctx.cr6.compare(ctx.f2.f64, ctx.f0.f64);
	// blt cr6,0x82145f18
	if (ctx.cr6.lt) goto loc_82145F18;
	// fadds f13,f1,f2
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,4852(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4852);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// b 0x82145f74
	goto loc_82145F74;
loc_82145F18:
	// fcmpu cr6,f3,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f3.f64, ctx.f13.f64);
	// ble cr6,0x82145f2c
	if (!ctx.cr6.gt) goto loc_82145F2C;
	// fmr f0,f1
	ctx.f0.f64 = ctx.f1.f64;
	// fmr f13,f3
	ctx.f13.f64 = ctx.f3.f64;
	// b 0x82145f30
	goto loc_82145F30;
loc_82145F2C:
	// fmr f0,f2
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f2.f64;
loc_82145F30:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f12,9868(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9868);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x82145f74
	if (!ctx.cr6.lt) goto loc_82145F74;
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f13,4852(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4852);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9540(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9540);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x82145f74
	if (!ctx.cr6.lt) goto loc_82145F74;
	// fcmpu cr6,f2,f1
	ctx.cr6.compare(ctx.f2.f64, ctx.f1.f64);
	// ble cr6,0x82145f70
	if (!ctx.cr6.gt) goto loc_82145F70;
	// fmr f0,f2
	ctx.f0.f64 = ctx.f2.f64;
	// b 0x82145f74
	goto loc_82145F74;
loc_82145F70:
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f1.f64;
loc_82145F74:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f0.f64;
	// blr 
	return;
}
