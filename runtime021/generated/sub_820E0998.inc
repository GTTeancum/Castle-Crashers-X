DEFINE_REX_FUNC(sub_820E0998) {
	REX_FUNC_PROLOGUE();
	// stw r3,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r3.u32);
	// blr 
	return;
}
