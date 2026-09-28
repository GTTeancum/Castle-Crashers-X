DEFINE_REX_FUNC(sub_820BC0E8) {
	REX_FUNC_PROLOGUE();
	// lbz r3,10497(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 10497);
	// blr 
	return;
}
