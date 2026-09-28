DEFINE_REX_FUNC(sub_820BC360) {
	REX_FUNC_PROLOGUE();
	// lwz r3,10752(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 10752);
	// blr 
	return;
}
