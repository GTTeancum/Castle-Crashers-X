DEFINE_REX_FUNC(sub_82125E28) {
	REX_FUNC_PROLOGUE();
	// stw r4,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
}
