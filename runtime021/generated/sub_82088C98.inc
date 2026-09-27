DEFINE_REX_FUNC(sub_82088C98) {
	REX_FUNC_PROLOGUE();
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lhz r10,148(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 148);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x82088cb8
	if (!ctx.cr6.gt) goto loc_82088CB8;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
loc_82088CB8:
	// lhz r11,146(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 146);
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82088cd4
	if (!ctx.cr6.eq) goto loc_82088CD4;
	// lbz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 140);
	// ori r10,r11,4
	ctx.r10.u64 = ctx.r11.u64 | 4;
	// stb r10,140(r3)
	REX_STORE_U8(ctx.r3.u32 + 140, ctx.r10.u8);
loc_82088CD4:
	// lbz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 140);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r10,r10,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stb r10,140(r3)
	REX_STORE_U8(ctx.r3.u32 + 140, ctx.r10.u8);
	// b 0x82087f70
	sub_82087F70(ctx, base);
	return;
}
