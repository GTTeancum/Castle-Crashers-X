DEFINE_REX_FUNC(sub_8208CB80) {
	REX_FUNC_PROLOGUE();
	// li r3,512
	ctx.r3.s64 = 512;
	// blr 
	return;
}
