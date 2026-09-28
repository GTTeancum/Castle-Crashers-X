DEFINE_REX_FUNC(sub_820BCD78) {
	REX_FUNC_PROLOGUE();
	// lwz r3,10692(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 10692);
	// blr 
	return;
}
