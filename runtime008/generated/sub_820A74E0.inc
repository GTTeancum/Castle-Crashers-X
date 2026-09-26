DEFINE_REX_FUNC(sub_820A74E0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,30208(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 30208);
	// addi r11,r11,7544
	ctx.r11.s64 = ctx.r11.s64 + 7544;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
}
