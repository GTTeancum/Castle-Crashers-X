DEFINE_REX_FUNC(sub_820862A0) {
	REX_FUNC_PROLOGUE();
	// li r3,2048
	ctx.r3.s64 = 2048;
	// blr 
	return;
}
