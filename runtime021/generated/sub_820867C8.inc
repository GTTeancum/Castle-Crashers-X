DEFINE_REX_FUNC(sub_820867C8) {
	REX_FUNC_PROLOGUE();
	// lhz r3,100(r3)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r3.u32 + 100);
	// blr 
	return;
}
