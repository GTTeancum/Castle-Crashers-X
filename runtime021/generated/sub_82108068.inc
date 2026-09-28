DEFINE_REX_FUNC(sub_82108068) {
	REX_FUNC_PROLOGUE();
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lbz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 8);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x821080b8
	if (ctx.cr6.eq) goto loc_821080B8;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x821080a4
	if (ctx.cr6.eq) goto loc_821080A4;
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// beq cr6,0x821080a4
	if (ctx.cr6.eq) goto loc_821080A4;
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// beq cr6,0x821080ac
	if (ctx.cr6.eq) goto loc_821080AC;
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// beq cr6,0x821080b8
	if (ctx.cr6.eq) goto loc_821080B8;
	// cmpwi cr6,r10,6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 6, ctx.xer);
	// beq cr6,0x821080ac
	if (ctx.cr6.eq) goto loc_821080AC;
loc_821080A4:
	// li r5,8
	ctx.r5.s64 = 8;
	// b 0x821080bc
	goto loc_821080BC;
loc_821080AC:
	// lwz r6,20(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r5,16(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// b 0x821080c0
	goto loc_821080C0;
loc_821080B8:
	// li r5,4
	ctx.r5.s64 = 4;
loc_821080BC:
	// addi r6,r11,16
	ctx.r6.s64 = ctx.r11.s64 + 16;
loc_821080C0:
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x820b59f0
	sub_820B59F0(ctx, base);
	return;
}
