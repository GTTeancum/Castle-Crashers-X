DEFINE_REX_FUNC(sub_82053AA0) {
	REX_FUNC_PROLOGUE();
	// li r3,5
	ctx.r3.s64 = 5;
	// blr 
	return;
}
