DEFINE_REX_FUNC(sub_82078BB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,40(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// lfs f12,9536(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9536);
	ctx.f12.f64 = double(temp.f32);
	// blt cr6,0x82078bcc
	if (ctx.cr6.lt) goto loc_82078BCC;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
	// b 0x82078bdc
	goto loc_82078BDC;
loc_82078BCC:
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lfs f0,108(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 108);
	ctx.f0.f64 = double(temp.f32);
loc_82078BDC:
	// lbz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 44);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82078c00
	if (ctx.cr6.eq) goto loc_82078C00;
	// lfs f13,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x82078c00
	if (ctx.cr6.gt) goto loc_82078C00;
	// fneg f13,f13
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82078c10
	if (!ctx.cr6.lt) goto loc_82078C10;
loc_82078C00:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x82078c10
	if (!ctx.cr6.gt) goto loc_82078C10;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82078C10:
	// lbz r11,166(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 166);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82078c24
	if (!ctx.cr6.eq) goto loc_82078C24;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82078C24:
	// lbz r3,167(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 167);
	// blr 
	return;
}
