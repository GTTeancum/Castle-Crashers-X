DEFINE_REX_FUNC(sub_820A0988) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x820A0990;
	__savegprlr_25(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32218
	ctx.r27.s64 = -2111438848;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r28,1
	ctx.r28.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// slw r11,r28,r29
	ctx.r11.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r29.u8 & 0x3F));
	// lwz r10,-6628(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + -6628);
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// lwz r9,36(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// and r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 & ctx.r11.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x820a09d4
	if (!ctx.cr6.eq) goto loc_820A09D4;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_820A09D4:
	// lis r30,-32215
	ctx.r30.s64 = -2111242240;
	// li r26,0
	ctx.r26.s64 = 0;
	// lbz r11,2704(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 2704);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a09f0
	if (ctx.cr6.eq) goto loc_820A09F0;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// b 0x820a0a28
	goto loc_820A0A28;
loc_820A09F0:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820b6818
	ctx.lr = 0x820A09FC;
	sub_820B6818(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820a0a24
	if (!ctx.cr6.eq) goto loc_820A0A24;
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a0a24
	if (ctx.cr6.eq) goto loc_820A0A24;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stb r10,2704(r30)
	REX_STORE_U8(ctx.r30.u32 + 2704, ctx.r10.u8);
	// b 0x820a0a28
	goto loc_820A0A28;
loc_820A0A24:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_820A0A28:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a0a48
	if (!ctx.cr6.eq) goto loc_820A0A48;
loc_820A0A34:
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r26,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r26.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_820A0A48:
	// lwz r3,-6628(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + -6628);
	// bl 0x820a3900
	ctx.lr = 0x820A0A50;
	sub_820A3900(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820a0a70
	if (ctx.cr6.eq) goto loc_820A0A70;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,-6628(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + -6628);
	// bl 0x820a39f0
	ctx.lr = 0x820A0A64;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a0a34
	if (ctx.cr6.eq) goto loc_820A0A34;
loc_820A0A70:
	// addi r11,r29,5
	ctx.r11.s64 = ctx.r29.s64 + 5;
	// lis r10,25576
	ctx.r10.s64 = 1676148736;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r8,r10,16383
	ctx.r8.u64 = ctx.r10.u64 | 16383;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwzx r7,r9,r25
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r25.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,8(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r10,4(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// stw r29,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r29.u32);
	// stw r8,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r8.u32);
	// stw r28,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r28.u32);
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// stw r10,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r10.u32);
	// bl 0x820fc240
	ctx.lr = 0x820A0AB4;
	sub_820FC240(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820a0ae0
	if (ctx.cr6.eq) goto loc_820A0AE0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,2688
	ctx.r3.s64 = ctx.r11.s64 + 2688;
	// bl 0x8208c5d8
	ctx.lr = 0x820A0AC8;
	sub_8208C5D8(ctx, base);
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r26,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r26.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_820A0AE0:
	// stw r26,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r26,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r26.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
