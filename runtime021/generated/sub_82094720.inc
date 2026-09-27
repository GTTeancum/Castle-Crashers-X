DEFINE_REX_FUNC(sub_82094720) {
	REX_FUNC_PROLOGUE();
	// stw r4,156(r3)
	REX_STORE_U32(ctx.r3.u32 + 156, ctx.r4.u32);
	// blr 
	return;
}
