DEFINE_REX_FUNC(sub_820BCF20) {
	REX_FUNC_PROLOGUE();
	// stw r4,13596(r3)
	REX_STORE_U32(ctx.r3.u32 + 13596, ctx.r4.u32);
	// blr 
	return;
}
