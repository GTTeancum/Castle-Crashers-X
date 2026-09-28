DEFINE_REX_FUNC(sub_8213CE48) {
	REX_FUNC_PROLOGUE();
	// lis r4,25738
	ctx.r4.s64 = 1686765568;
	// ori r4,r4,24
	ctx.r4.u64 = ctx.r4.u64 | 24;
	// b 0x82136708
	sub_82136708(ctx, base);
	return;
}
