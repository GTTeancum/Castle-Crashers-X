DEFINE_REX_FUNC(sub_82139AB8) {
	REX_FUNC_PROLOGUE();
	// addi r11,r4,278
	ctx.r11.s64 = ctx.r4.s64 + 278;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r3
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82139ae0
	if (ctx.cr6.eq) goto loc_82139AE0;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82139ae0
	if (ctx.cr6.eq) goto loc_82139AE0;
	// lwz r3,144(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 144);
	// blr 
	return;
loc_82139AE0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
