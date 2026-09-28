DEFINE_REX_FUNC(sub_8211E358) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x8211E360;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// cmplwi cr6,r27,1200
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 1200, ctx.xer);
	// ble cr6,0x8211e384
	if (!ctx.cr6.gt) goto loc_8211E384;
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4102
	ctx.r3.u64 = ctx.r3.u64 | 4102;
	// b 0x8211e460
	goto loc_8211E460;
loc_8211E384:
	// addi r30,r31,40
	ctx.r30.s64 = ctx.r31.s64 + 40;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a434
	ctx.lr = 0x8211E390;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r29,r31,416
	ctx.r29.s64 = ctx.r31.s64 + 416;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821212c8
	ctx.lr = 0x8211E39C;
	sub_821212C8(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bge 0x8211e3b4
	if (!ctx.cr0.lt) goto loc_8211E3B4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a444
	ctx.lr = 0x8211E3AC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x8211e460
	goto loc_8211E460;
loc_8211E3B4:
	// lwz r11,1148(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1148);
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// lhz r7,1036(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 1036);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// lhz r6,1034(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 1034);
	// lhz r5,1040(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 1040);
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// beq 0x8211e418
	if (ctx.cr0.eq) goto loc_8211E418;
	// addi r30,r31,28
	ctx.r30.s64 = ctx.r31.s64 + 28;
	// lwz r10,424(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// addi r28,r31,532
	ctx.r28.s64 = ctx.r31.s64 + 532;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r28,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r28.u32);
	// bl 0x82121428
	ctx.lr = 0x8211E3F8;
	sub_82121428(ctx, base);
	// lis r11,32512
	ctx.r11.s64 = 2130706432;
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8211e438
	if (ctx.cr6.eq) goto loc_8211E438;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x820d7ef8
	ctx.lr = 0x8211E414;
	sub_820D7EF8(ctx, base);
	// b 0x8211e438
	goto loc_8211E438;
loc_8211E418:
	// lwz r28,424(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// addi r30,r31,532
	ctx.r30.s64 = ctx.r31.s64 + 532;
	// addi r4,r31,28
	ctx.r4.s64 = ctx.r31.s64 + 28;
	// lwz r10,428(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 428);
	// stw r30,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r28,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// bl 0x821214a8
	ctx.lr = 0x8211E438;
	sub_821214A8(ctx, base);
loc_8211E438:
	// lhz r11,1042(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1042);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r10,1144(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 1144);
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stb r10,1144(r31)
	REX_STORE_U8(ctx.r31.u32 + 1144, ctx.r10.u8);
	// sth r11,1042(r31)
	REX_STORE_U16(ctx.r31.u32 + 1042, ctx.r11.u16);
	// bl 0x8211c7f8
	ctx.lr = 0x8211E45C;
	sub_8211C7F8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8211E460:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
