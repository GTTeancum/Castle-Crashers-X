DEFINE_REX_FUNC(sub_820BC0A8) {
	REX_FUNC_PROLOGUE();
	// lbz r3,10499(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 10499);
	// blr 
	return;
}
