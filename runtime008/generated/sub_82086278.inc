DEFINE_REX_FUNC(sub_82086278) {
	REX_FUNC_PROLOGUE();
	// lbz r11,86(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 86);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r10,r10,0,26,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stb r10,86(r3)
	REX_STORE_U8(ctx.r3.u32 + 86, ctx.r10.u8);
	// blr 
	return;
}
