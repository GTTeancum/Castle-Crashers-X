DEFINE_REX_FUNC(sub_8212F2F8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,32712
	ctx.r11.s64 = ctx.r11.s64 + 32712;
	// lwzx r3,r10,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// b 0x8214a444
	__imp__RtlLeaveCriticalSection(ctx, base);
	return;
}
