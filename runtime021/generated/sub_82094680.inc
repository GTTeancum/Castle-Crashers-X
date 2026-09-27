DEFINE_REX_FUNC(sub_82094680) {
	REX_FUNC_PROLOGUE();
	// lis r3,4
	ctx.r3.s64 = 262144;
	// blr 
	return;
}
