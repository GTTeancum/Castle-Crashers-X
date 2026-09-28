DEFINE_REX_FUNC(sub_82106110) {
	REX_FUNC_PROLOGUE();
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x82105c40
	sub_82105C40(ctx, base);
	return;
}
