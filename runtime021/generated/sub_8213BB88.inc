DEFINE_REX_FUNC(sub_8213BB88) {
	REX_FUNC_PROLOGUE();
	// clrlwi. r5,r5,24
	ctx.r5.u64 = ctx.r5.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x8213bb98
	if (!ctx.cr0.eq) goto loc_8213BB98;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8213bab0
	sub_8213BAB0(ctx, base);
	return;
loc_8213BB98:
	// b 0x8213bab0
	sub_8213BAB0(ctx, base);
	return;
}
