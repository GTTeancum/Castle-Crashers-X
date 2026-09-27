DEFINE_REX_FUNC(sub_82090448) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x82090450;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// lwz r3,72(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82090480
	if (ctx.cr6.eq) goto loc_82090480;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8209047C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r27,72(r30)
	REX_STORE_U32(ctx.r30.u32 + 72, ctx.r27.u32);
loc_82090480:
	// lwz r3,10316(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 10316);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820904a0
	if (ctx.cr6.eq) goto loc_820904A0;
	// lbz r11,112(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820904a0
	if (!ctx.cr6.eq) goto loc_820904A0;
	// bl 0x820a7400
	ctx.lr = 0x8209049C;
	sub_820A7400(ctx, base);
	// stw r27,10316(r30)
	REX_STORE_U32(ctx.r30.u32 + 10316, ctx.r27.u32);
loc_820904A0:
	// lwz r31,10320(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 10320);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// lis r24,-32215
	ctx.r24.s64 = -2111242240;
	// addi r25,r11,29632
	ctx.r25.s64 = ctx.r11.s64 + 29632;
	// addi r23,r10,-1768
	ctx.r23.s64 = ctx.r10.s64 + -1768;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820904f8
	if (ctx.cr6.eq) goto loc_820904F8;
	// lbz r11,-22601(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820904e0
	if (!ctx.cr6.eq) goto loc_820904E0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820904E0;
	sub_820A71E8(ctx, base);
loc_820904E0:
	// bl 0x820b5eb8
	ctx.lr = 0x820904E4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bf18
	ctx.lr = 0x820904F4;
	sub_8209BF18(ctx, base);
	// stw r27,10320(r30)
	REX_STORE_U32(ctx.r30.u32 + 10320, ctx.r27.u32);
loc_820904F8:
	// lwz r31,10324(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 10324);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8209053c
	if (ctx.cr6.eq) goto loc_8209053C;
	// lbz r11,-22601(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82090524
	if (!ctx.cr6.eq) goto loc_82090524;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82090524;
	sub_820A71E8(ctx, base);
loc_82090524:
	// bl 0x820b5eb8
	ctx.lr = 0x82090528;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bf18
	ctx.lr = 0x82090538;
	sub_8209BF18(ctx, base);
	// stw r27,10324(r30)
	REX_STORE_U32(ctx.r30.u32 + 10324, ctx.r27.u32);
loc_8209053C:
	// lwz r31,10328(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 10328);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82090580
	if (ctx.cr6.eq) goto loc_82090580;
	// lbz r11,-22601(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82090568
	if (!ctx.cr6.eq) goto loc_82090568;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82090568;
	sub_820A71E8(ctx, base);
loc_82090568:
	// bl 0x820b5eb8
	ctx.lr = 0x8209056C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8209057C;
	sub_8209BF18(ctx, base);
	// stw r27,10328(r30)
	REX_STORE_U32(ctx.r30.u32 + 10328, ctx.r27.u32);
loc_82090580:
	// lwz r31,10356(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 10356);
	// addi r28,r30,10352
	ctx.r28.s64 = ctx.r30.s64 + 10352;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820905c8
	if (ctx.cr6.eq) goto loc_820905C8;
	// lbz r11,-22601(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820905b0
	if (!ctx.cr6.eq) goto loc_820905B0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820905B0;
	sub_820A71E8(ctx, base);
loc_820905B0:
	// bl 0x820b5eb8
	ctx.lr = 0x820905B4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bf18
	ctx.lr = 0x820905C4;
	sub_8209BF18(ctx, base);
	// stw r27,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r27.u32);
loc_820905C8:
	// stw r27,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r27.u32);
	// addi r26,r30,10372
	ctx.r26.s64 = ctx.r30.s64 + 10372;
	// stw r27,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r27.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82079b48
	ctx.lr = 0x820905DC;
	sub_82079B48(ctx, base);
	// lwz r31,108(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 108);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82090634
	if (ctx.cr6.eq) goto loc_82090634;
loc_820905E8:
	// lwz r29,84(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// bl 0x820b6190
	ctx.lr = 0x820905F4;
	sub_820B6190(ctx, base);
	// lbz r11,-22601(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82090614
	if (!ctx.cr6.eq) goto loc_82090614;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82090614;
	sub_820A71E8(ctx, base);
loc_82090614:
	// bl 0x820b5eb8
	ctx.lr = 0x82090618;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bf18
	ctx.lr = 0x82090628;
	sub_8209BF18(ctx, base);
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x820905e8
	if (!ctx.cr6.eq) goto loc_820905E8;
loc_82090634:
	// stw r27,108(r30)
	REX_STORE_U32(ctx.r30.u32 + 108, ctx.r27.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82079b48
	ctx.lr = 0x82090640;
	sub_82079B48(ctx, base);
	// lwz r31,4(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82090684
	if (ctx.cr6.eq) goto loc_82090684;
	// lbz r11,-22601(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209066c
	if (!ctx.cr6.eq) goto loc_8209066C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209066C;
	sub_820A71E8(ctx, base);
loc_8209066C:
	// bl 0x820b5eb8
	ctx.lr = 0x82090670;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bf18
	ctx.lr = 0x82090680;
	sub_8209BF18(ctx, base);
	// stw r27,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r27.u32);
loc_82090684:
	// stw r27,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r27.u32);
	// addi r31,r30,80
	ctx.r31.s64 = ctx.r30.s64 + 80;
	// stw r27,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r27.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820842f0
	ctx.lr = 0x82090698;
	sub_820842F0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820845c0
	ctx.lr = 0x820906A0;
	sub_820845C0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
