DEFINE_REX_FUNC(sub_8210B1D0) {
	REX_FUNC_PROLOGUE();
	// stw r4,80(r3)
	REX_STORE_U32(ctx.r3.u32 + 80, ctx.r4.u32);
	// blr 
	return;
}
