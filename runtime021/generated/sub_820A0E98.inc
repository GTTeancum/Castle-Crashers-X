DEFINE_REX_FUNC(sub_820A0E98) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x820A0EA0;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32215
	ctx.r30.s64 = -2111242240;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// lbz r9,2704(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 2704);
	// li r25,0
	ctx.r25.s64 = 0;
	// lwz r31,-6596(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + -6596);
	// li r28,1
	ctx.r28.s64 = 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a0ed8
	if (ctx.cr6.eq) goto loc_820A0ED8;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// b 0x820a0f10
	goto loc_820A0F10;
loc_820A0ED8:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820b6818
	ctx.lr = 0x820A0EE4;
	sub_820B6818(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820a0f0c
	if (!ctx.cr6.eq) goto loc_820A0F0C;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a0f0c
	if (ctx.cr6.eq) goto loc_820A0F0C;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stb r10,2704(r30)
	REX_STORE_U8(ctx.r30.u32 + 2704, ctx.r10.u8);
	// b 0x820a0f10
	goto loc_820A0F10;
loc_820A0F0C:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_820A0F10:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a0f30
	if (!ctx.cr6.eq) goto loc_820A0F30;
	// stw r28,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r28.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// stw r25,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r25.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_820A0F30:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,-6628(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// bl 0x820a39f0
	ctx.lr = 0x820A0F40;
	sub_820A39F0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a0f74
	if (ctx.cr6.eq) goto loc_820A0F74;
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// addi r10,r11,16
	ctx.r10.s64 = ctx.r11.s64 + 16;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r28,r9,r31
	REX_STORE_U32(ctx.r9.u32 + ctx.r31.u32, ctx.r28.u32);
	// lwz r11,256(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 256);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r8.u32);
loc_820A0F74:
	// stw r25,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r25.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// stw r25,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r25.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
