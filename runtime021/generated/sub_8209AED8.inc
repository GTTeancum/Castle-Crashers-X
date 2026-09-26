DEFINE_REX_FUNC(sub_8209AED8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x8209AEE0;
	__savegprlr_23(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r23,-32215
	ctx.r23.s64 = -2111242240;
	// lbz r11,-22602(r23)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r23.u32 + -22602);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209af00
	if (!ctx.cr6.eq) goto loc_8209AF00;
loc_8209AEF4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
loc_8209AF00:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r9,-22008
	ctx.r11.s64 = ctx.r9.s64 + -22008;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwzx r3,r10,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8209aef4
	if (ctx.cr6.eq) goto loc_8209AEF4;
	// bl 0x820b02b0
	ctx.lr = 0x8209AF28;
	sub_820B02B0(ctx, base);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r24,r11,-1768
	ctx.r24.s64 = ctx.r11.s64 + -1768;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// lis r25,-32215
	ctx.r25.s64 = -2111242240;
	// mr r27,r28
	ctx.r27.u64 = ctx.r28.u64;
	// addi r26,r10,29632
	ctx.r26.s64 = ctx.r10.s64 + 29632;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8209afb4
	if (!ctx.cr6.gt) goto loc_8209AFB4;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
loc_8209AF58:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8209afa0
	if (ctx.cr6.eq) goto loc_8209AFA0;
	// lbz r11,-22601(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209af8c
	if (!ctx.cr6.eq) goto loc_8209AF8C;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209AF8C;
	sub_820A71E8(ctx, base);
loc_8209AF8C:
	// bl 0x820b5eb8
	ctx.lr = 0x8209AF90;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r3,r11,r26
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8209AFA0;
	sub_8209BF18(ctx, base);
loc_8209AFA0:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r29,r29,140
	ctx.r29.s64 = ctx.r29.s64 + 140;
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8209af58
	if (ctx.cr6.lt) goto loc_8209AF58;
loc_8209AFB4:
	// lbz r11,-22601(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -22601);
	// lwz r30,8(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209afd8
	if (!ctx.cr6.eq) goto loc_8209AFD8;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209AFD8;
	sub_820A71E8(ctx, base);
loc_8209AFD8:
	// bl 0x820b5eb8
	ctx.lr = 0x8209AFDC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r3,r11,r26
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8209AFEC;
	sub_8209BF18(ctx, base);
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// lbz r8,-22602(r23)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r23.u32 + -22602);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stw r28,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// addi r10,r10,-16888
	ctx.r10.s64 = ctx.r10.s64 + -16888;
	// stw r28,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// mulli r11,r8,68
	ctx.r11.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(68));
	// stw r28,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r28.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r3,r9,-488
	ctx.r3.s64 = ctx.r9.s64 + -488;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x8209B01C;
	sub_8208C5D8(ctx, base);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,-22602(r23)
	REX_STORE_U8(ctx.r23.u32 + -22602, ctx.r11.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
