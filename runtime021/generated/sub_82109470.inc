DEFINE_REX_FUNC(sub_82109470) {
	REX_FUNC_PROLOGUE();
	// clrlwi r11,r4,27
	ctx.r11.u64 = ctx.r4.u32 & 0x1F;
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 31, ctx.xer);
	// bge cr6,0x8210949c
	if (!ctx.cr6.lt) goto loc_8210949C;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r3
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// ble cr6,0x8210949c
	if (!ctx.cr6.gt) goto loc_8210949C;
	// lbz r9,394(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 394);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x821094a0
	if (ctx.cr6.eq) goto loc_821094A0;
loc_8210949C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821094A0:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}
