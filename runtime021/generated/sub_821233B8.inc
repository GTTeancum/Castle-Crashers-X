DEFINE_REX_FUNC(sub_821233B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x821233C0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r9,564(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 564);
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// stw r10,564(r11)
	REX_STORE_U32(ctx.r11.u32 + 564, ctx.r10.u32);
	// beq cr6,0x821233f4
	if (ctx.cr6.eq) goto loc_821233F4;
	// lwz r10,568(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 568);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,568(r11)
	REX_STORE_U32(ctx.r11.u32 + 568, ctx.r10.u32);
loc_821233F4:
	// lwz r11,48(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// addi r28,r29,48
	ctx.r28.s64 = ctx.r29.s64 + 48;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x8212340c
	if (ctx.cr6.eq) goto loc_8212340C;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8212340C:
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r8,8(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r30,r31,12
	ctx.r30.s64 = ctx.r31.s64 + 12;
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// rlwinm r27,r10,27,31,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x821234fc
	if (ctx.cr6.eq) goto loc_821234FC;
	// lwz r11,72(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 72);
	// addi r10,r29,72
	ctx.r10.s64 = ctx.r29.s64 + 72;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82123460
	if (!ctx.cr6.eq) goto loc_82123460;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82123460:
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x821234dc
	if (!ctx.cr6.eq) goto loc_821234DC;
	// lwz r11,172(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 172);
	// rlwinm. r11,r11,0,5,5
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x821234dc
	if (!ctx.cr0.eq) goto loc_821234DC;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82123488
	if (ctx.cr6.eq) goto loc_82123488;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
loc_82123488:
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82123498
	if (!ctx.cr6.eq) goto loc_82123498;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82123498:
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x821234ac
	if (!ctx.cr6.eq) goto loc_821234AC;
	// addi r3,r29,80
	ctx.r3.s64 = ctx.r29.s64 + 80;
	// bl 0x82122310
	ctx.lr = 0x821234A8;
	sub_82122310(ctx, base);
	// b 0x821234dc
	goto loc_821234DC;
loc_821234AC:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x821234bc
	if (!ctx.cr6.eq) goto loc_821234BC;
	// li r11,0
	ctx.r11.s64 = 0;
loc_821234BC:
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r10,32(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x821234dc
	if (ctx.cr6.eq) goto loc_821234DC;
	// lwz r10,140(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 140);
	// addi r3,r29,80
	ctx.r3.s64 = ctx.r29.s64 + 80;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x82122768
	ctx.lr = 0x821234DC;
	sub_82122768(ctx, base);
loc_821234DC:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r30,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r30.u32);
	// stw r30,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r30.u32);
loc_821234FC:
	// bl 0x82136f58
	ctx.lr = 0x82123500;
	sub_82136F58(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r29,184
	ctx.r3.s64 = ctx.r29.s64 + 184;
	// bl 0x82122640
	ctx.lr = 0x82123514;
	sub_82122640(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r29,248
	ctx.r3.s64 = ctx.r29.s64 + 248;
	// lwz r4,60(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// bl 0x82122640
	ctx.lr = 0x82123524;
	sub_82122640(ctx, base);
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x821235a4
	if (ctx.cr6.eq) goto loc_821235A4;
	// lwz r11,172(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 172);
	// rlwinm. r11,r11,0,5,5
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x821235a4
	if (!ctx.cr0.eq) goto loc_821235A4;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x82123554
	if (!ctx.cr6.eq) goto loc_82123554;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,16(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// bl 0x82122ef8
	ctx.lr = 0x82123550;
	sub_82122EF8(ctx, base);
	// b 0x821235a4
	goto loc_821235A4;
loc_82123554:
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplw cr6,r10,r28
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x82123564
	if (!ctx.cr6.eq) goto loc_82123564;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82123564:
	// lwz r9,16(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// addi r11,r29,32
	ctx.r11.s64 = ctx.r29.s64 + 32;
	// ld r10,20(r10)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r10.u32 + 20);
	// ld r8,40(r29)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r29.u32 + 40);
	// addi r3,r9,536
	ctx.r3.s64 = ctx.r9.s64 + 536;
	// li r9,1
	ctx.r9.s64 = 1;
	// cmpld cr6,r8,r10
	ctx.cr6.compare<uint64_t>(ctx.r8.u64, ctx.r10.u64, ctx.xer);
	// blt cr6,0x82123588
	if (ctx.cr6.lt) goto loc_82123588;
	// li r9,0
	ctx.r9.s64 = 0;
loc_82123588:
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// std r10,8(r11)
	REX_STORE_U64(ctx.r11.u32 + 8, ctx.r10.u64);
	// beq cr6,0x821235a0
	if (ctx.cr6.eq) goto loc_821235A0;
	// bl 0x8211aab0
	ctx.lr = 0x8212359C;
	sub_8211AAB0(ctx, base);
	// b 0x821235a4
	goto loc_821235A4;
loc_821235A0:
	// bl 0x82122708
	ctx.lr = 0x821235A4;
	sub_82122708(ctx, base);
loc_821235A4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
