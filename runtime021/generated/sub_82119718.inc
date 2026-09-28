DEFINE_REX_FUNC(sub_82119718) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x82119720;
	__savegprlr_26(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
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
	// ble cr6,0x82119744
	if (!ctx.cr6.gt) goto loc_82119744;
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4102
	ctx.r3.u64 = ctx.r3.u64 | 4102;
	// b 0x82119834
	goto loc_82119834;
loc_82119744:
	// addi r30,r31,164
	ctx.r30.s64 = ctx.r31.s64 + 164;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a434
	ctx.lr = 0x82119750;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,288(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r8,20(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lhz r10,18(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 18);
	// sth r10,88(r1)
	REX_STORE_U16(ctx.r1.u32 + 88, ctx.r10.u16);
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// lwz r5,44(r9)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r9.u32 + 44);
	// lwz r4,40(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 40);
	// bl 0x82120960
	ctx.lr = 0x82119784;
	sub_82120960(ctx, base);
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r29,13(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 13);
	// bl 0x8214a444
	ctx.lr = 0x82119794;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821212c8
	ctx.lr = 0x8211979C;
	sub_821212C8(ctx, base);
	// addi r28,r31,236
	ctx.r28.s64 = ctx.r31.s64 + 236;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a434
	ctx.lr = 0x821197AC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82119820
	if (ctx.cr6.lt) goto loc_82119820;
	// lwz r11,440(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 440);
	// rlwinm. r11,r11,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82119820
	if (!ctx.cr0.eq) goto loc_82119820;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// bl 0x82121538
	ctx.lr = 0x821197D8;
	sub_82121538(ctx, base);
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r31,292
	ctx.r10.s64 = ctx.r31.s64 + 292;
	// addi r11,r9,8
	ctx.r11.s64 = ctx.r9.s64 + 8;
	// stw r10,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// lwz r10,296(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 296);
	// stw r10,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// lwz r10,296(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 296);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r11,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r11.u32);
	// lwz r11,380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 380);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82119810
	if (!ctx.cr6.eq) goto loc_82119810;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82118bc8
	ctx.lr = 0x82119810;
	sub_82118BC8(ctx, base);
loc_82119810:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a444
	ctx.lr = 0x82119818;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82119834
	goto loc_82119834;
loc_82119820:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x821180d8
	ctx.lr = 0x82119828;
	sub_821180D8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a444
	ctx.lr = 0x82119830;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82119834:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
