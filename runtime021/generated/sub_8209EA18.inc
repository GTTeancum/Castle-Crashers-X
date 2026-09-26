DEFINE_REX_FUNC(sub_8209EA18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x8209EA20;
	__savegprlr_25(ctx, base);
	// stwu r1,-704(r1)
	ea = -704 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// lwz r4,-6628(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8209ea54
	if (ctx.cr6.eq) goto loc_8209EA54;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f1,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x820a2150
	ctx.lr = 0x8209EA54;
	sub_820A2150(ctx, base);
loc_8209EA54:
	// clrlwi r11,r31,16
	ctx.r11.u64 = ctx.r31.u32 & 0xFFFF;
	// cmplwi cr6,r11,512
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 512, ctx.xer);
	// blt cr6,0x8209ea88
	if (ctx.cr6.lt) goto loc_8209EA88;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,1380
	ctx.r3.s64 = ctx.r11.s64 + 1380;
	// bl 0x8208c5d8
	ctx.lr = 0x8209EA6C;
	sub_8208C5D8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r9,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r9.u32);
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_8209EA88:
	// rlwinm r25,r11,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r25,r26
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + ctx.r26.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209eaa8
	if (ctx.cr6.eq) goto loc_8209EAA8;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8209eff0
	ctx.lr = 0x8209EAA8;
	sub_8209EFF0(ctx, base);
loc_8209EAA8:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r27,r30,4
	ctx.r27.s64 = ctx.r30.s64 + 4;
	// addi r4,r11,1428
	ctx.r4.s64 = ctx.r11.s64 + 1428;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82127778
	ctx.lr = 0x8209EAC0;
	sub_82127778(ctx, base);
	// lbz r10,128(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 128);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8209eaf8
	if (ctx.cr6.eq) goto loc_8209EAF8;
loc_8209EAD4:
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,46
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 46, ctx.xer);
	// bne cr6,0x8209eae8
	if (!ctx.cr6.eq) goto loc_8209EAE8;
	// stb r30,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r30.u8);
	// b 0x8209eaec
	goto loc_8209EAEC;
loc_8209EAE8:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_8209EAEC:
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209ead4
	if (!ctx.cr6.eq) goto loc_8209EAD4;
loc_8209EAF8:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r28,r11,1444
	ctx.r28.s64 = ctx.r11.s64 + 1444;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82127778
	ctx.lr = 0x8209EB08;
	sub_82127778(ctx, base);
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lbz r10,-22601(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8209eb30
	if (!ctx.cr6.eq) goto loc_8209EB30;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r3,r11,-1768
	ctx.r3.s64 = ctx.r11.s64 + -1768;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209EB30;
	sub_820A71E8(ctx, base);
loc_8209EB30:
	// bl 0x820b5eb8
	ctx.lr = 0x8209EB34;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,29632
	ctx.r9.s64 = ctx.r11.s64 + 29632;
	// li r4,168
	ctx.r4.s64 = 168;
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8209EB4C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8209eb64
	if (ctx.cr6.eq) goto loc_8209EB64;
	// bl 0x8209e270
	ctx.lr = 0x8209EB58;
	sub_8209E270(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8209eb88
	if (!ctx.cr6.eq) goto loc_8209EB88;
loc_8209EB64:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,1456
	ctx.r3.s64 = ctx.r11.s64 + 1456;
	// bl 0x8208c5d8
	ctx.lr = 0x8209EB70;
	sub_8208C5D8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r30,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_8209EB88:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8209e448
	ctx.lr = 0x8209EB98;
	sub_8209E448(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x8209ec3c
	if (!ctx.cr6.lt) goto loc_8209EC3C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// addi r4,r11,1524
	ctx.r4.s64 = ctx.r11.s64 + 1524;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82127778
	ctx.lr = 0x8209EBB4;
	sub_82127778(ctx, base);
	// lbz r10,128(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 128);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8209ebe8
	if (ctx.cr6.eq) goto loc_8209EBE8;
loc_8209EBC4:
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,46
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 46, ctx.xer);
	// bne cr6,0x8209ebd8
	if (!ctx.cr6.eq) goto loc_8209EBD8;
	// stb r30,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r30.u8);
	// b 0x8209ebdc
	goto loc_8209EBDC;
loc_8209EBD8:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_8209EBDC:
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209ebc4
	if (!ctx.cr6.eq) goto loc_8209EBC4;
loc_8209EBE8:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82127778
	ctx.lr = 0x8209EBF0;
	sub_82127778(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8209e448
	ctx.lr = 0x8209EC00;
	sub_8209E448(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x8209ec3c
	if (!ctx.cr6.lt) goto loc_8209EC3C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r11,1544
	ctx.r3.s64 = ctx.r11.s64 + 1544;
	// bl 0x8208c5d8
	ctx.lr = 0x8209EC18;
	sub_8208C5D8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8209ecb0
	ctx.lr = 0x8209EC24;
	sub_8209ECB0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r30,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_8209EC3C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8209e6c8
	ctx.lr = 0x8209EC44;
	sub_8209E6C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x8209ec80
	if (!ctx.cr6.lt) goto loc_8209EC80;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,1584
	ctx.r3.s64 = ctx.r11.s64 + 1584;
	// bl 0x8208c5d8
	ctx.lr = 0x8209EC5C;
	sub_8208C5D8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8209ecb0
	ctx.lr = 0x8209EC68;
	sub_8209ECB0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r30,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_8209EC80:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8209ec98
	if (ctx.cr6.eq) goto loc_8209EC98;
	// bl 0x820b6498
	ctx.lr = 0x8209EC90;
	sub_820B6498(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8209EC98:
	// stwx r31,r25,r26
	REX_STORE_U32(ctx.r25.u32 + ctx.r26.u32, ctx.r31.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r30,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
	// stw r30,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r30.u32);
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
