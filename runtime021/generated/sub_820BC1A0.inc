DEFINE_REX_FUNC(sub_820BC1A0) {
	REX_FUNC_PROLOGUE();
	// lwz r3,11856(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 11856);
	// blr 
	return;
}
