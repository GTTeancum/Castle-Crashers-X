DEFINE_REX_FUNC(sub_820814A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x820814A8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lhz r11,4(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 4);
	// lwz r27,8(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208158c
	if (ctx.cr6.eq) goto loc_8208158C;
loc_820814CC:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,156(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// addi r3,r11,10372
	ctx.r3.s64 = ctx.r11.s64 + 10372;
	// bl 0x82082488
	ctx.lr = 0x820814E0;
	sub_82082488(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207aa50
	ctx.lr = 0x820814F8;
	sub_8207AA50(ctx, base);
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// lwz r6,76(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 76);
	// and r7,r8,r12
	ctx.r7.u64 = ctx.r8.u64 & ctx.r12.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// lwz r11,156(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 156);
	// addi r30,r11,10372
	ctx.r30.s64 = ctx.r11.s64 + 10372;
	// beq cr6,0x82081564
	if (ctx.cr6.eq) goto loc_82081564;
	// lwz r28,4(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lhz r11,24(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82081564
	if (ctx.cr6.eq) goto loc_82081564;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82081544;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// and r9,r3,r12
	ctx.r9.u64 = ctx.r3.u64 & ctx.r12.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82081564
	if (ctx.cr6.eq) goto loc_82081564;
	// lhz r11,24(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,24(r28)
	REX_STORE_U16(ctx.r28.u32 + 24, ctx.r11.u16);
loc_82081564:
	// lwz r11,5024(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 5024);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r31,r9,r30
	REX_STORE_U32(ctx.r9.u32 + ctx.r30.u32, ctx.r31.u32);
	// lwz r11,5024(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 5024);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,5024(r30)
	REX_STORE_U32(ctx.r30.u32 + 5024, ctx.r8.u32);
	// lhz r7,4(r26)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r26.u32 + 4);
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x820814cc
	if (ctx.cr6.lt) goto loc_820814CC;
loc_8208158C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
