DEFINE_REX_FUNC(sub_820B20C8) {
	REX_FUNC_PROLOGUE();
	// std r4,24(r1)
	REX_STORE_U64(ctx.r1.u32 + 24, ctx.r4.u64);
	// lbz r9,25(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 25);
	// lbz r3,26(r1)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r1.u32 + 26);
	// lbz r11,24(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 24);
	// lbz r10,27(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 27);
	// rlwimi r11,r10,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r8,r11,16
	ctx.r8.u64 = ctx.r11.u32 & 0xFFFF;
	// rlwimi r9,r8,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r3,r9,8,0,23
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r3.u64 & 0xFFFFFFFF000000FF);
	// blr 
	return;
}
