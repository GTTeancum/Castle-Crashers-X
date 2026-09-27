DEFINE_REX_FUNC(sub_82093A60) {
	REX_FUNC_PROLOGUE();
	// li r3,8192
	ctx.r3.s64 = 8192;
	// blr 
	return;
}
