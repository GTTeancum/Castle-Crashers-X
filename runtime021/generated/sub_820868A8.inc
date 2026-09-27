DEFINE_REX_FUNC(sub_820868A8) {
	REX_FUNC_PROLOGUE();
	// li r3,1024
	ctx.r3.s64 = 1024;
	// blr 
	return;
}
