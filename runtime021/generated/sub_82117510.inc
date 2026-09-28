DEFINE_REX_FUNC(sub_82117510) {
	REX_FUNC_PROLOGUE();
	// stw r5,24(r4)
	REX_STORE_U32(ctx.r4.u32 + 24, ctx.r5.u32);
	// stw r6,28(r4)
	REX_STORE_U32(ctx.r4.u32 + 28, ctx.r6.u32);
	// b 0x82115e60
	sub_82115E60(ctx, base);
	return;
}
