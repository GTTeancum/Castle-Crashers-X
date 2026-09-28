DEFINE_REX_FUNC(sub_820CB060) {
	REX_FUNC_PROLOGUE();
	// addis r11,r3,8178
	ctx.r11.s64 = ctx.r3.s64 + 535953408;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// blr 
	return;
}
