DEFINE_REX_FUNC(sub_820817B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x820817C0;
	__savegprlr_26(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r4,8(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,156(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// lwz r3,10316(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 10316);
	// bl 0x8209d948
	ctx.lr = 0x820817E8;
	sub_8209D948(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r26,r28,44
	ctx.r26.s64 = ctx.r28.s64 + 44;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82082390
	ctx.lr = 0x820817FC;
	sub_82082390(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8208182c
	if (ctx.cr6.eq) goto loc_8208182C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r4,8(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// addi r3,r11,-7236
	ctx.r3.s64 = ctx.r11.s64 + -7236;
	// bl 0x820798d8
	ctx.lr = 0x82081818;
	sub_820798D8(ctx, base);
	// bl 0x8208c5d8
	ctx.lr = 0x8208181C;
	sub_8208C5D8(ctx, base);
	// lhz r10,30(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 30);
	// extsh r3,r10
	ctx.r3.s64 = ctx.r10.s16;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_8208182C:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r10,-6648(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -6648);
	// lhz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 16);
	// addi r7,r9,26607
	ctx.r7.s64 = ctx.r9.s64 + 26607;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r10
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// lhz r4,24(r5)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r5.u32 + 24);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820818a4
	if (ctx.cr6.eq) goto loc_820818A4;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r3,r11,-5368
	ctx.r3.s64 = ctx.r11.s64 + -5368;
loc_82081860:
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// clrlwi r9,r11,16
	ctx.r9.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r9,16(r10)
	REX_STORE_U16(ctx.r10.u32 + 16, ctx.r9.u16);
	// cmplwi cr6,r9,1000
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1000, ctx.xer);
	// bne cr6,0x82081878
	if (!ctx.cr6.eq) goto loc_82081878;
	// sth r7,16(r10)
	REX_STORE_U16(ctx.r10.u32 + 16, ctx.r7.u16);
loc_82081878:
	// lhz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 16);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x82081888
	if (!ctx.cr6.eq) goto loc_82081888;
	// bl 0x8208c5d8
	ctx.lr = 0x82081888;
	sub_8208C5D8(ctx, base);
loc_82081888:
	// lhz r11,16(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 16);
	// addi r11,r11,26607
	ctx.r11.s64 = ctx.r11.s64 + 26607;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r10
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// lhz r4,24(r5)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r5.u32 + 24);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82081860
	if (!ctx.cr6.eq) goto loc_82081860;
loc_820818A4:
	// lhz r11,16(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 16);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r11,r11,26607
	ctx.r11.s64 = ctx.r11.s64 + 26607;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r10
	ctx.r31.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82066ea8
	ctx.lr = 0x820818C0;
	sub_82066EA8(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,8(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r7,76(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 76);
	// lwz r4,156(r7)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r7.u32 + 156);
	// bl 0x82079d50
	ctx.lr = 0x820818D8;
	sub_82079D50(ctx, base);
	// lwz r6,0(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r11,76(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 76);
	// lwz r10,156(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// lwz r11,8248(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8248);
	// addi r9,r11,1998
	ctx.r9.s64 = ctx.r11.s64 + 1998;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r10
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// stw r7,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r7.u32);
	// lwz r6,4(r28)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// stw r6,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r6.u32);
	// bl 0x820936b0
	ctx.lr = 0x82081910;
	sub_820936B0(ctx, base);
	// lhz r5,30(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 30);
	// extsh r3,r5
	ctx.r3.s64 = ctx.r5.s16;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
