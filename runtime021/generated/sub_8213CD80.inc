DEFINE_REX_FUNC(sub_8213CD80) {
	REX_FUNC_PROLOGUE();
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// lis r4,25738
	ctx.r4.s64 = 1686765568;
	// mullw r3,r3,r11
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r11.s32);
	// ori r4,r4,24
	ctx.r4.u64 = ctx.r4.u64 | 24;
	// b 0x82136670
	sub_82136670(ctx, base);
	return;
}
