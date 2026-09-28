DEFINE_REX_FUNC(sub_82130280) {
	REX_FUNC_PROLOGUE();
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// cmpwi cr6,r11,101
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 101, ctx.xer);
	// beq cr6,0x821302c8
	if (ctx.cr6.eq) goto loc_821302C8;
	// cmpwi cr6,r11,69
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 69, ctx.xer);
	// beq cr6,0x821302c8
	if (ctx.cr6.eq) goto loc_821302C8;
	// cmpwi cr6,r11,102
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 102, ctx.xer);
	// bne cr6,0x821302b0
	if (!ctx.cr6.eq) goto loc_821302B0;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// b 0x82130048
	sub_82130048(ctx, base);
	return;
loc_821302B0:
	// cmpwi cr6,r11,97
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 97, ctx.xer);
	// beq cr6,0x821302c4
	if (ctx.cr6.eq) goto loc_821302C4;
	// cmpwi cr6,r11,65
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 65, ctx.xer);
	// beq cr6,0x821302c4
	if (ctx.cr6.eq) goto loc_821302C4;
	// b 0x82130130
	sub_82130130(ctx, base);
	return;
loc_821302C4:
	// b 0x8212fa38
	sub_8212FA38(ctx, base);
	return;
loc_821302C8:
	// b 0x8212f920
	sub_8212F920(ctx, base);
	return;
}
