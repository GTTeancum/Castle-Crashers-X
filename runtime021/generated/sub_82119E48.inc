DEFINE_REX_FUNC(sub_82119E48) {
	REX_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,36(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// b 0x82118928
	sub_82118928(ctx, base);
	return;
}
