DEFINE_REX_FUNC(sub_820FC9C8) {
	REX_FUNC_PROLOGUE();
	// lwz r3,396(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 396);
	// blr 
	return;
}
