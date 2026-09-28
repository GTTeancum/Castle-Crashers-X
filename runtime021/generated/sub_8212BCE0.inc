DEFINE_REX_FUNC(sub_8212BCE0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8212BCE8;
	__savegprlr_27(ctx, base);
	// addi r31,r1,-144
	ctx.r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r30,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r30.u32);
	// cntlzw r11,r27
	ctx.r11.u64 = ctx.r27.u32 == 0 ? 32 : __builtin_clz(ctx.r27.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8212bd3c
	if (!ctx.cr6.eq) goto loc_8212BD3C;
loc_8212BD10:
	// bl 0x821294e0
	ctx.lr = 0x8212BD14;
	sub_821294E0(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8212c298
	ctx.lr = 0x8212BD34;
	sub_8212C298(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8212bea8
	goto loc_8212BEA8;
loc_8212BD3C:
	// cntlzw r11,r30
	ctx.r11.u64 = ctx.r30.u32 == 0 ? 32 : __builtin_clz(ctx.r30.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8212bd10
	if (ctx.cr6.eq) goto loc_8212BD10;
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8212be24
	if (!ctx.cr0.eq) goto loc_8212BE24;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8212e910
	ctx.lr = 0x8212BD64;
	sub_8212E910(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8212bdb4
	if (ctx.cr6.eq) goto loc_8212BDB4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8212e910
	ctx.lr = 0x8212BD74;
	sub_8212E910(ctx, base);
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x8212bdb4
	if (ctx.cr6.eq) goto loc_8212BDB4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8212e910
	ctx.lr = 0x8212BD84;
	sub_8212E910(ctx, base);
	// srawi r10,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// rlwinm r28,r10,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r11,2976
	ctx.r29.s64 = ctx.r11.s64 + 2976;
	// bl 0x8212e910
	ctx.lr = 0x8212BD9C;
	sub_8212E910(ctx, base);
	// lwzx r11,r28,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r29.u32);
	// rlwinm r10,r3,6,21,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// lis r9,-32235
	ctx.r9.s64 = -2112552960;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r28,r9,32392
	ctx.r28.s64 = ctx.r9.s64 + 32392;
	// b 0x8212bdc8
	goto loc_8212BDC8;
loc_8212BDB4:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// addi r28,r10,32392
	ctx.r28.s64 = ctx.r10.s64 + 32392;
	// addi r29,r11,2976
	ctx.r29.s64 = ctx.r11.s64 + 2976;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_8212BDC8:
	// lbz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 40);
	// rlwinm. r11,r11,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8212bd10
	if (!ctx.cr0.eq) goto loc_8212BD10;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8212e910
	ctx.lr = 0x8212BDDC;
	sub_8212E910(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8212be18
	if (ctx.cr6.eq) goto loc_8212BE18;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8212e910
	ctx.lr = 0x8212BDEC;
	sub_8212E910(ctx, base);
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x8212be18
	if (ctx.cr6.eq) goto loc_8212BE18;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8212e910
	ctx.lr = 0x8212BDFC;
	sub_8212E910(ctx, base);
	// srawi r11,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 5;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// rlwinm r28,r11,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8212e910
	ctx.lr = 0x8212BE0C;
	sub_8212E910(ctx, base);
	// lwzx r10,r28,r29
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r29.u32);
	// rlwinm r11,r3,6,21,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// add r28,r11,r10
	ctx.r28.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_8212BE18:
	// lbz r11,40(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 40);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8212bd10
	if (!ctx.cr0.eq) goto loc_8212BD10;
loc_8212BE24:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8212BE28:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8212be28
	if (!ctx.cr6.eq) goto loc_8212BE28;
	// subf r11,r27,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r29,r11,0
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r29,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r29.u32);
	// bl 0x8212c078
	ctx.lr = 0x8212BE50;
	sub_8212C078(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8212e6a8
	ctx.lr = 0x8212BE5C;
	sub_8212E6A8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82129618
	ctx.lr = 0x8212BE74;
	sub_82129618(ctx, base);
	// stw r3,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8212e780
	ctx.lr = 0x8212BE84;
	sub_8212E780(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,144
	ctx.r12.s64 = ctx.r31.s64 + 144;
	// bl 0x8212bed0
	ctx.lr = 0x8212BE90;
	sub_8212BED0(ctx, base);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r10,84(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r3,r11,-1
	ctx.r3.s64 = ctx.r11.s64 + -1;
loc_8212BEA8:
	// addi r1,r31,144
	ctx.r1.s64 = ctx.r31.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
