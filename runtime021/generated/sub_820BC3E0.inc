DEFINE_REX_FUNC(sub_820BC3E0) {
	REX_FUNC_PROLOGUE();
	// lwz r3,11864(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 11864);
	// blr 
	return;
}
