DEFINE_REX_FUNC(sub_821150A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x821150A8;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// li r26,0
	ctx.r26.s64 = 0;
	// bl 0x82136f58
	ctx.lr = 0x821150BC;
	sub_82136F58(ctx, base);
	// add r25,r3,r27
	ctx.r25.u64 = ctx.r3.u64 + ctx.r27.u64;
loc_821150C0:
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// li r28,0
	ctx.r28.s64 = 0;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82115100
	if (!ctx.cr6.gt) goto loc_82115100;
	// li r30,0
	ctx.r30.s64 = 0;
loc_821150D8:
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// bl 0x821179c0
	ctx.lr = 0x821150E8;
	sub_821179C0(ctx, base);
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// or r28,r3,r28
	ctx.r28.u64 = ctx.r3.u64 | ctx.r28.u64;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x821150d8
	if (ctx.cr6.lt) goto loc_821150D8;
loc_82115100:
	// cmpwi cr6,r27,-1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, -1, ctx.xer);
	// beq cr6,0x82115114
	if (ctx.cr6.eq) goto loc_82115114;
	// bl 0x82136f58
	ctx.lr = 0x8211510C;
	sub_82136F58(ctx, base);
	// subf. r11,r3,r25
	ctx.r11.u64 = ctx.r25.u64 - ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x8211512c
	if (!ctx.cr0.gt) goto loc_8211512C;
loc_82115114:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x82115124
	if (ctx.cr6.eq) goto loc_82115124;
	// li r26,1
	ctx.r26.s64 = 1;
	// b 0x821150c0
	goto loc_821150C0;
loc_82115124:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x821150c0
	if (ctx.cr6.eq) goto loc_821150C0;
loc_8211512C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
