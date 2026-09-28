DEFINE_REX_FUNC(sub_820BC420) {
	REX_FUNC_PROLOGUE();
	// lwz r3,11868(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 11868);
	// blr 
	return;
}
