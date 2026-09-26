DEFINE_REX_FUNC(sub_82120AE0) {
	REX_FUNC_PROLOGUE();
	// stw r5,21(r3)
	REX_STORE_U32(ctx.r3.u32 + 21, ctx.r5.u32);
	// stw r4,17(r3)
	REX_STORE_U32(ctx.r3.u32 + 17, ctx.r4.u32);
	// blr 
	return;
}
