DEFINE_REX_FUNC(sub_82121210) {
	REX_FUNC_PROLOGUE();
	// stw r3,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
