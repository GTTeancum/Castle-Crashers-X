DEFINE_REX_FUNC(sub_8212BF08) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r3,r11,31272
	ctx.r3.s64 = ctx.r11.s64 + 31272;
	// blr 
	return;
}
