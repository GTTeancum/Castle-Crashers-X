DEFINE_REX_FUNC(sub_82078E38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x82078E40;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	ctx.r28.s64 = 0;
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// subfic r22,r3,8
	ctx.xer.ca = ctx.r3.u32 <= 8;
	ctx.r22.u64 = static_cast<uint64_t>(8) - ctx.r3.u64;
	// lis r23,-32215
	ctx.r23.s64 = -2111242240;
	// lis r25,-32218
	ctx.r25.s64 = -2111438848;
	// addi r24,r9,29632
	ctx.r24.s64 = ctx.r9.s64 + 29632;
	// addi r26,r10,-7824
	ctx.r26.s64 = ctx.r10.s64 + -7824;
	// addi r21,r11,-1768
	ctx.r21.s64 = ctx.r11.s64 + -1768;
loc_82078E74:
	// lbz r11,-22601(r23)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r23.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82078e94
	if (!ctx.cr6.eq) goto loc_82078E94;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82078E94;
	sub_820A71E8(ctx, base);
loc_82078E94:
	// bl 0x820b5eb8
	ctx.lr = 0x82078E98;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,888
	ctx.r4.s64 = 888;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82078EA8;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82078f18
	if (ctx.cr6.eq) goto loc_82078F18;
	// stw r26,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// addi r30,r31,8
	ctx.r30.s64 = ctx.r31.s64 + 8;
	// stw r28,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82072d00
	ctx.lr = 0x82078EC8;
	sub_82072D00(ctx, base);
	// lwz r11,-6652(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6652);
	// stw r29,876(r31)
	REX_STORE_U32(ctx.r31.u32 + 876, ctx.r29.u32);
	// stw r28,880(r31)
	REX_STORE_U32(ctx.r31.u32 + 880, ctx.r28.u32);
	// stb r28,884(r31)
	REX_STORE_U8(ctx.r31.u32 + 884, ctx.r28.u8);
	// lbz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82078efc
	if (!ctx.cr6.eq) goto loc_82078EFC;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82072eb0
	ctx.lr = 0x82078EF8;
	sub_82072EB0(ctx, base);
	// b 0x82078f1c
	goto loc_82078F1C;
loc_82078EFC:
	// add r10,r22,r27
	ctx.r10.u64 = ctx.r22.u64 + ctx.r27.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// bl 0x82072eb0
	ctx.lr = 0x82078F14;
	sub_82072EB0(ctx, base);
	// b 0x82078f1c
	goto loc_82078F1C;
loc_82078F18:
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
loc_82078F1C:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stw r31,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r31.u32);
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// cmpwi cr6,r29,4
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 4, ctx.xer);
	// blt cr6,0x82078e74
	if (ctx.cr6.lt) goto loc_82078E74;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
