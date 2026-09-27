DEFINE_REX_FUNC(sub_82086808) {
	REX_FUNC_PROLOGUE();
	// lhz r3,148(r3)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r3.u32 + 148);
	// blr 
	return;
}
