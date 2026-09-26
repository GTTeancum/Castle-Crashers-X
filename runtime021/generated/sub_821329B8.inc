DEFINE_REX_FUNC(sub_821329B8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32234
	ctx.r11.s64 = -2112487424;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// lwz r11,-31264(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -31264);
	// lwz r10,23748(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 23748);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}
