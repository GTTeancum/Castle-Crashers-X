DEFINE_REX_FUNC(sub_8210B958) {
	REX_FUNC_PROLOGUE();
	// lbz r3,394(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 394);
	// blr 
	return;
}
