DEFINE_REX_FUNC(sub_820B5D48) {
	REX_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8214a2f4
	__imp__XamShowAchievementsUI(ctx, base);
	return;
}
