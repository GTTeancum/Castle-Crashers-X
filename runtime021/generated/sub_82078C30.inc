DEFINE_REX_FUNC(sub_82078C30) {
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
	// blt cr6,0x82078c4c
	if (ctx.cr6.lt) goto loc_82078C4C;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
	// b 0x82078c5c
	goto loc_82078C5C;
loc_82078C4C:
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
loc_82078C5C:
	// lbz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 44);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82078c80
	if (ctx.cr6.eq) goto loc_82078C80;
	// lfs f13,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x82078c80
	if (ctx.cr6.gt) goto loc_82078C80;
	// fneg f13,f13
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82078c90
	if (!ctx.cr6.lt) goto loc_82078C90;
loc_82078C80:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x82078c90
	if (!ctx.cr6.lt) goto loc_82078C90;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82078C90:
	// lbz r11,202(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 202);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82078ca4
	if (!ctx.cr6.eq) goto loc_82078CA4;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82078CA4:
	// lbz r3,203(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 203);
	// blr 
	return;
}
