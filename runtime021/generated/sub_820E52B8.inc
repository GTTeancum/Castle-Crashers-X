DEFINE_REX_FUNC(sub_820E52B8) {
	REX_FUNC_PROLOGUE();
	// stw r4,100(r3)
	REX_STORE_U32(ctx.r3.u32 + 100, ctx.r4.u32);
	// blr 
	return;
}
