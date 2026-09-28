DEFINE_REX_FUNC(sub_820BCDA0) {
	REX_FUNC_PROLOGUE();
	// lwz r3,10704(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 10704);
	// blr 
	return;
}
