DEFINE_REX_FUNC(sub_820BCD08) {
	REX_FUNC_PROLOGUE();
	// lbz r11,10556(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 10556);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// rlwimi r11,r10,0,24,29
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFC) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF03);
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}
