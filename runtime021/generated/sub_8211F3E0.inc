DEFINE_REX_FUNC(sub_8211F3E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x8211F3E8;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r4,1192
	ctx.r4.s64 = 1192;
	// li r3,2
	ctx.r3.s64 = 2;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// mr r27,r9
	ctx.r27.u64 = ctx.r9.u64;
	// mr r23,r10
	ctx.r23.u64 = ctx.r10.u64;
	// bl 0x82108f48
	ctx.lr = 0x8211F418;
	sub_82108F48(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8211f42c
	if (!ctx.cr0.eq) goto loc_8211F42C;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x8211f538
	goto loc_8211F538;
loc_8211F42C:
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211dfa0
	ctx.lr = 0x8211F448;
	sub_8211DFA0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r31,532
	ctx.r9.s64 = ctx.r31.s64 + 532;
	// li r10,2
	ctx.r10.s64 = 2;
loc_8211F454:
	// lhz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + 0);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// bne 0x8211f454
	if (!ctx.cr0.eq) goto loc_8211F454;
	// lwz r10,92(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8211f480
	if (!ctx.cr6.gt) goto loc_8211F480;
	// lis r30,-32646
	ctx.r30.s64 = -2139488256;
	// ori r30,r30,4101
	ctx.r30.u64 = ctx.r30.u64 | 4101;
	// b 0x8211f518
	goto loc_8211F518;
loc_8211F480:
	// lwz r9,144(r26)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r26.u32 + 144);
	// add r30,r9,r11
	ctx.r30.u64 = ctx.r9.u64 + ctx.r11.u64;
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8211f494
	if (!ctx.cr6.gt) goto loc_8211F494;
	// mr r30,r10
	ctx.r30.u64 = ctx.r10.u64;
loc_8211F494:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8211f4e8
	if (ctx.cr6.eq) goto loc_8211F4E8;
	// lwz r11,544(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 544);
	// addi r3,r31,536
	ctx.r3.s64 = ctx.r31.s64 + 536;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8211f4bc
	if (!ctx.cr6.gt) goto loc_8211F4BC;
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8211aa40
	ctx.lr = 0x8211F4B8;
	sub_8211AA40(ctx, base);
	// b 0x8211f4c0
	goto loc_8211F4C0;
loc_8211F4BC:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8211F4C0:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8211f4dc
	if (ctx.cr6.eq) goto loc_8211F4DC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r31,472
	ctx.r3.s64 = ctx.r31.s64 + 472;
	// bl 0x82121d28
	ctx.lr = 0x8211F4D4;
	sub_82121D28(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8211f4e8
	if (!ctx.cr0.eq) goto loc_8211F4E8;
loc_8211F4DC:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x8211f518
	goto loc_8211F518;
loc_8211F4E8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82121210
	ctx.lr = 0x8211F4F0;
	sub_82121210(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8211f518
	if (ctx.cr0.lt) goto loc_8211F518;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211e358
	ctx.lr = 0x8211F508;
	sub_8211E358(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x8211f534
	if (!ctx.cr0.lt) goto loc_8211F534;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82121220
	ctx.lr = 0x8211F518;
	sub_82121220(ctx, base);
loc_8211F518:
	// li r11,3
	ctx.r11.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// bl 0x821180d8
	ctx.lr = 0x8211F52C;
	sub_821180D8(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x8211f538
	goto loc_8211F538;
loc_8211F534:
	// li r30,0
	ctx.r30.s64 = 0;
loc_8211F538:
	// stw r31,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r31.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
