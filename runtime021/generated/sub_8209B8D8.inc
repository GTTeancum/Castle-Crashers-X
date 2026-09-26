DEFINE_REX_FUNC(sub_8209B8D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stb r4,30(r3)
	REX_STORE_U8(ctx.r3.u32 + 30, ctx.r4.u8);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// rlwinm r7,r4,0,29,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x4;
	// clrlwi r11,r4,24
	ctx.r11.u64 = ctx.r4.u32 & 0xFF;
	// lfs f12,9568(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9568);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// lfs f13,9536(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9536);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,9564(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9564);
	ctx.f0.f64 = double(temp.f32);
	// beq cr6,0x8209b90c
	if (ctx.cr6.eq) goto loc_8209B90C;
	// stfs f0,104(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// b 0x8209b924
	goto loc_8209B924;
loc_8209B90C:
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8209b920
	if (ctx.cr6.eq) goto loc_8209B920;
	// stfs f12,104(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// b 0x8209b924
	goto loc_8209B924;
loc_8209B920:
	// stfs f13,104(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 104, temp.u32);
loc_8209B924:
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8209b938
	if (ctx.cr6.eq) goto loc_8209B938;
	// stfs f12,108(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// b 0x8209b950
	goto loc_8209B950;
loc_8209B938:
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8209b94c
	if (ctx.cr6.eq) goto loc_8209B94C;
	// stfs f0,108(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// b 0x8209b950
	goto loc_8209B950;
loc_8209B94C:
	// stfs f13,108(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 108, temp.u32);
loc_8209B950:
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8209b964
	if (ctx.cr6.eq) goto loc_8209B964;
	// stfs f12,116(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// b 0x8209b97c
	goto loc_8209B97C;
loc_8209B964:
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8209b978
	if (ctx.cr6.eq) goto loc_8209B978;
	// stfs f0,116(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// b 0x8209b97c
	goto loc_8209B97C;
loc_8209B978:
	// stfs f13,116(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 116, temp.u32);
loc_8209B97C:
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8209b990
	if (ctx.cr6.eq) goto loc_8209B990;
	// stfs f0,112(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// blr 
	return;
loc_8209B990:
	// rlwinm r11,r11,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209b9a4
	if (ctx.cr6.eq) goto loc_8209B9A4;
	// stfs f12,112(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// blr 
	return;
loc_8209B9A4:
	// stfs f13,112(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// blr 
	return;
}
