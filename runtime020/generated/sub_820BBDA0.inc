DEFINE_REX_FUNC(sub_820BBDA0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,23980(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 23980);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820bbdb4
	if (ctx.cr6.eq) goto loc_820BBDB4;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// b 0x820bbdb8
	goto loc_820BBDB8;
loc_820BBDB4:
	// rlwinm r11,r11,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
loc_820BBDB8:
	// stw r11,23980(r3)
	REX_STORE_U32(ctx.r3.u32 + 23980, ctx.r11.u32);
	// blr 
	return;
}
