DEFINE_REX_FUNC(sub_82148FA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lbz r11,19(r6)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r6.u32 + 19);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8214901c
	if (ctx.cr6.eq) goto loc_8214901C;
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// std r11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// frsp f12,f0
	ctx.f12.f64 = double(float(ctx.f0.f64));
	// lfs f0,6684(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 6684);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,6680(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6680);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f2,f0
	ctx.f0.f64 = double(float(ctx.f2.f64 - ctx.f0.f64));
	// fsubs f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82148fec
	if (!ctx.cr6.lt) goto loc_82148FEC;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_82148FEC:
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x8214901c
	if (ctx.cr6.lt) goto loc_8214901C;
	// lhz r11,14(r6)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r6.u32 + 14);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// sth r11,14(r6)
	REX_STORE_U16(ctx.r6.u32 + 14, ctx.r11.u16);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x82149014
	if (!ctx.cr6.gt) goto loc_82149014;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82149020
	goto loc_82149020;
loc_82149014:
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82149024
	goto loc_82149024;
loc_8214901C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82149020:
	// sth r11,14(r6)
	REX_STORE_U16(ctx.r6.u32 + 14, ctx.r11.u16);
loc_82149024:
	// stb r11,20(r6)
	REX_STORE_U8(ctx.r6.u32 + 20, ctx.r11.u8);
	// blr 
	return;
}
