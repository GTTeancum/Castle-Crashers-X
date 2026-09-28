DEFINE_REX_FUNC(sub_8210B1B8) {
	REX_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// b 0x820fdad8
	sub_820FDAD8(ctx, base);
	return;
}
