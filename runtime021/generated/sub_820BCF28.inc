DEFINE_REX_FUNC(sub_820BCF28) {
	REX_FUNC_PROLOGUE();
	// lwz r3,13596(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 13596);
	// blr 
	return;
}
