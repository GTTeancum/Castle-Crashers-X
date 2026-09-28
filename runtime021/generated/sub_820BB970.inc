DEFINE_REX_FUNC(sub_820BB970) {
	REX_FUNC_PROLOGUE();
	// lwz r11,11848(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 11848);
	// rlwinm r3,r11,24,27,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0x1F;
	// blr 
	return;
}
