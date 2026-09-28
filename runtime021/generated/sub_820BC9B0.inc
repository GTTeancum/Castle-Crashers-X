DEFINE_REX_FUNC(sub_820BC9B0) {
	REX_FUNC_PROLOGUE();
	// lwz r3,12028(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12028);
	// blr 
	return;
}
