DEFINE_REX_FUNC(sub_8213BBA0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32236
	ctx.r11.s64 = -2112618496;
	// addi r3,r11,-17528
	ctx.r3.s64 = ctx.r11.s64 + -17528;
	// blr 
	return;
}
