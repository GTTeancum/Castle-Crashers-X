DEFINE_REX_FUNC(sub_82109F48) {
	REX_FUNC_PROLOGUE();
	// lis r4,-32761
	ctx.r4.s64 = -2147024896;
	// ori r4,r4,1235
	ctx.r4.u64 = ctx.r4.u64 | 1235;
	// b 0x82109a50
	sub_82109A50(ctx, base);
	return;
}
