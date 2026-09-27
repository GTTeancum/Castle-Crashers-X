DEFINE_REX_FUNC(sub_8208C5E0) {
	REX_FUNC_PROLOGUE();
	// li r3,16384
	ctx.r3.s64 = 16384;
	// blr 
	return;
}
