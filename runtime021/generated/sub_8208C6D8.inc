DEFINE_REX_FUNC(sub_8208C6D8) {
	REX_FUNC_PROLOGUE();
	// lis r3,1
	ctx.r3.s64 = 65536;
	// blr 
	return;
}
