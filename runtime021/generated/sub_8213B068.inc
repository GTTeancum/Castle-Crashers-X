DEFINE_REX_FUNC(sub_8213B068) {
	REX_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8213afe8
	sub_8213AFE8(ctx, base);
	return;
}
