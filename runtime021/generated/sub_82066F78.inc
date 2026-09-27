DEFINE_REX_FUNC(sub_82066F78) {
	REX_FUNC_PROLOGUE();
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
}
