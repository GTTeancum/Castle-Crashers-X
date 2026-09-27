DEFINE_REX_FUNC(sub_820868B8) {
	REX_FUNC_PROLOGUE();
	// lbz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 140);
	// rlwimi r11,r4,0,31,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x1) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFFE);
	// stb r11,140(r3)
	REX_STORE_U8(ctx.r3.u32 + 140, ctx.r11.u8);
	// blr 
	return;
}
