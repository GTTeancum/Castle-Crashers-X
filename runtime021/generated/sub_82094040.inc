DEFINE_REX_FUNC(sub_82094040) {
	REX_FUNC_PROLOGUE();
	// li r3,64
	ctx.r3.s64 = 64;
	// blr 
	return;
}
