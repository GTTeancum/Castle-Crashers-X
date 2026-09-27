DEFINE_REX_FUNC(sub_820868C8) {
	REX_FUNC_PROLOGUE();
	// stw r4,96(r3)
	REX_STORE_U32(ctx.r3.u32 + 96, ctx.r4.u32);
	// blr 
	return;
}
