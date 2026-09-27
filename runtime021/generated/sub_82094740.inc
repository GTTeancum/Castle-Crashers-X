DEFINE_REX_FUNC(sub_82094740) {
	REX_FUNC_PROLOGUE();
	// lhz r3,150(r3)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r3.u32 + 150);
	// blr 
	return;
}
