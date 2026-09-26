DEFINE_REX_FUNC(sub_820868D0) {
	REX_FUNC_PROLOGUE();
	// lwz r3,96(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// blr 
	return;
}
