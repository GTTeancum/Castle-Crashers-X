DEFINE_REX_FUNC(sub_82093F98) {
	REX_FUNC_PROLOGUE();
	// li r3,4096
	ctx.r3.s64 = 4096;
	// blr 
	return;
}
