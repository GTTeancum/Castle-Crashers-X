DEFINE_REX_FUNC(sub_82086270) {
	REX_FUNC_PROLOGUE();
	// lhz r3,80(r3)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r3.u32 + 80);
	// blr 
	return;
}
