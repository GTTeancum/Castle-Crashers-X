DEFINE_REX_FUNC(sub_8208CF90) {
	REX_FUNC_PROLOGUE();
	// li r3,128
	ctx.r3.s64 = 128;
	// blr 
	return;
}
