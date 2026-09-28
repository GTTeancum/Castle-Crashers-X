DEFINE_REX_FUNC(sub_82145928) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,-4844(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4844);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x82145940
	if (!ctx.cr6.gt) goto loc_82145940;
	// li r3,261
	ctx.r3.s64 = 261;
	// blr 
	return;
loc_82145940:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,-4848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4848);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x82145958
	if (!ctx.cr6.gt) goto loc_82145958;
	// li r3,241
	ctx.r3.s64 = 241;
	// blr 
	return;
loc_82145958:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,-11316(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11316);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x82145970
	if (!ctx.cr6.gt) goto loc_82145970;
	// li r3,221
	ctx.r3.s64 = 221;
	// blr 
	return;
loc_82145970:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,-4852(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4852);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x82145988
	if (!ctx.cr6.gt) goto loc_82145988;
	// li r3,201
	ctx.r3.s64 = 201;
	// blr 
	return;
loc_82145988:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,9924(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9924);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x821459a0
	if (!ctx.cr6.gt) goto loc_821459A0;
	// li r3,181
	ctx.r3.s64 = 181;
	// blr 
	return;
loc_821459A0:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,-4856(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4856);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bgt cr6,0x821459c8
	if (ctx.cr6.gt) goto loc_821459C8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,9940(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9940);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bgt cr6,0x821459c8
	if (ctx.cr6.gt) goto loc_821459C8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,9932(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9932);
	ctx.f0.f64 = double(temp.f32);
loc_821459C8:
	// li r3,161
	ctx.r3.s64 = 161;
	// blr 
	return;
}
