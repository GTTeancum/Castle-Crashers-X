DEFINE_REX_FUNC(sub_8207A4C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8207A4C8;
	__savegprlr_27(ctx, base);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// addi r27,r29,4
	ctx.r27.s64 = ctx.r29.s64 + 4;
	// stw r28,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r28.u32);
	// stb r28,4(r29)
	REX_STORE_U8(ctx.r29.u32 + 4, ctx.r28.u8);
	// lhz r11,28(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r10,10316(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 10316);
	// bne cr6,0x8207a500
	if (!ctx.cr6.eq) goto loc_8207A500;
	// addi r4,r10,12
	ctx.r4.s64 = ctx.r10.s64 + 12;
	// b 0x8207a50c
	goto loc_8207A50C;
loc_8207A500:
	// lwz r10,28(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_8207A50C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82053a00
	ctx.lr = 0x8207A514;
	sub_82053A00(ctx, base);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x8207a540
	if (ctx.cr6.lt) goto loc_8207A540;
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge cr6,0x8207a534
	if (!ctx.cr6.lt) goto loc_8207A534;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8207a560
	goto loc_8207A560;
loc_8207A534:
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r31,r30
	ctx.r11.u64 = ctx.r31.u64 + ctx.r30.u64;
	// b 0x8207a554
	goto loc_8207A554;
loc_8207A540:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// add r9,r11,r31
	ctx.r9.u64 = ctx.r11.u64 + ctx.r31.u64;
	// blt cr6,0x8207a560
	if (ctx.cr6.lt) goto loc_8207A560;
	// add r10,r9,r30
	ctx.r10.u64 = ctx.r9.u64 + ctx.r30.u64;
loc_8207A554:
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8207a560
	if (ctx.cr6.lt) goto loc_8207A560;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_8207A560:
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8207a588
	if (!ctx.cr6.lt) goto loc_8207A588;
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// subf r31,r9,r11
	ctx.r31.u64 = ctx.r11.u64 - ctx.r9.u64;
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82129ef8
	ctx.lr = 0x8207A580;
	sub_82129EF8(ctx, base);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// add r8,r31,r11
	ctx.r8.u64 = ctx.r31.u64 + ctx.r11.u64;
loc_8207A588:
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// stb r28,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r28.u8);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8207A594:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8207a594
	if (!ctx.cr6.eq) goto loc_8207A594;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r5,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r5.u32);
	// bl 0x82129a70
	ctx.lr = 0x8207A5C0;
	sub_82129A70(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// add r10,r11,r29
	ctx.r10.u64 = ctx.r11.u64 + ctx.r29.u64;
	// stb r28,4(r10)
	REX_STORE_U8(ctx.r10.u32 + 4, ctx.r28.u8);
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
