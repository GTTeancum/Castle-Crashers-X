DEFINE_REX_FUNC(sub_820DCAF8) {
	REX_FUNC_PROLOGUE();
	// lwz r3,32(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// blr 
	return;
}
