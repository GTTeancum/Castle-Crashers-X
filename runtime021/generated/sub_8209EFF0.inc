DEFINE_REX_FUNC(sub_8209EFF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x8209EFF8;
	__savegprlr_24(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// clrlwi r4,r5,16
	ctx.r4.u64 = ctx.r5.u32 & 0xFFFF;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,512
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 512, ctx.xer);
	// blt cr6,0x8209f038
	if (ctx.cr6.lt) goto loc_8209F038;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,1840
	ctx.r3.s64 = ctx.r11.s64 + 1840;
	// bl 0x8208c5d8
	ctx.lr = 0x8209F01C;
	sub_8208C5D8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r9,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
loc_8209F038:
	// rlwinm r24,r4,2,0,29
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r26,r24,r25
	ctx.r26.u64 = REX_LOAD_U32(ctx.r24.u32 + ctx.r25.u32);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x8209f070
	if (!ctx.cr6.eq) goto loc_8209F070;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,1884
	ctx.r3.s64 = ctx.r11.s64 + 1884;
	// bl 0x8208c5d8
	ctx.lr = 0x8209F054;
	sub_8208C5D8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r9,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
loc_8209F070:
	// addi r31,r25,2308
	ctx.r31.s64 = ctx.r25.s64 + 2308;
	// li r27,256
	ctx.r27.s64 = 256;
	// li r29,0
	ctx.r29.s64 = 0;
loc_8209F07C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x8209f0e8
	if (!ctx.cr6.eq) goto loc_8209F0E8;
	// lwz r30,-4(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + -4);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d8370
	ctx.lr = 0x8209F098;
	sub_820D8370(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d8210
	ctx.lr = 0x8209F0A4;
	sub_820D8210(ctx, base);
	// lbz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8209f0d8
	if (ctx.cr6.eq) goto loc_8209F0D8;
loc_8209F0B4:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x820b6068
	ctx.lr = 0x8209F0BC;
	sub_820B6068(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d8210
	ctx.lr = 0x8209F0C8;
	sub_820D8210(ctx, base);
	// lbz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8209f0b4
	if (!ctx.cr6.eq) goto loc_8209F0B4;
loc_8209F0D8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d8088
	ctx.lr = 0x8209F0E0;
	sub_820D8088(ctx, base);
	// stw r29,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r29.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
loc_8209F0E8:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r31,r31,12
	ctx.r31.s64 = ctx.r31.s64 + 12;
	// bne 0x8209f07c
	if (!ctx.cr0.eq) goto loc_8209F07C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8209ecb0
	ctx.lr = 0x8209F100;
	sub_8209ECB0(ctx, base);
	// stwx r29,r24,r25
	REX_STORE_U32(ctx.r24.u32 + ctx.r25.u32, ctx.r29.u32);
	// stw r29,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r29.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r29,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r29.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
