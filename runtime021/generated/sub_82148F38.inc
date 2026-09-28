DEFINE_REX_FUNC(sub_82148F38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,6676(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6676);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82148f6c
	if (!ctx.cr6.gt) goto loc_82148F6C;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f13,6672(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6672);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,6668(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 6668);
	ctx.f12.f64 = double(temp.f32);
	// fnmsubs f12,f0,f13,f12
	ctx.f12.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f13.f64, -ctx.f12.f64)));
	// lfs f13,6664(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6664);
	ctx.f13.f64 = double(temp.f32);
	// b 0x82148f88
	goto loc_82148F88;
loc_82148F6C:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f13,6660(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6660);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,6656(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 6656);
	ctx.f12.f64 = double(temp.f32);
	// fnmsubs f12,f0,f13,f12
	ctx.f12.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f13.f64, -ctx.f12.f64)));
	// lfs f13,6652(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6652);
	ctx.f13.f64 = double(temp.f32);
loc_82148F88:
	// fmadds f0,f12,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f0,4(r4)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bgt cr6,0x82148fa0
	if (ctx.cr6.gt) goto loc_82148FA0;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82148FA0:
	// stb r11,19(r4)
	REX_STORE_U8(ctx.r4.u32 + 19, ctx.r11.u8);
	// blr 
	return;
}
