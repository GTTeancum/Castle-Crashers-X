DEFINE_REX_FUNC(sub_820FC9B8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,720(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 720);
	// rlwinm r3,r11,2,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x1;
	// blr 
	return;
}
