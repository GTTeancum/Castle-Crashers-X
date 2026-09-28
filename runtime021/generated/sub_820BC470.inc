DEFINE_REX_FUNC(sub_820BC470) {
	REX_FUNC_PROLOGUE();
	// lwz r3,11884(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 11884);
	// blr 
	return;
}
