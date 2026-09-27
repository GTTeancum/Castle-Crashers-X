DEFINE_REX_FUNC(sub_8208CF98) {
	REX_FUNC_PROLOGUE();
	// lis r3,2
	ctx.r3.s64 = 131072;
	// blr 
	return;
}
