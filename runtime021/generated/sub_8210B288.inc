DEFINE_REX_FUNC(sub_8210B288) {
	REX_FUNC_PROLOGUE();
	// stw r4,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r4.u32);
	// stw r3,84(r4)
	REX_STORE_U32(ctx.r4.u32 + 84, ctx.r3.u32);
	// blr 
	return;
}
