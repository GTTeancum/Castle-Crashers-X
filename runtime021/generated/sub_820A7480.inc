DEFINE_REX_FUNC(sub_820A7480) {
	REX_FUNC_PROLOGUE();
	// lbz r3,28712(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 28712);
	// blr 
	return;
}
