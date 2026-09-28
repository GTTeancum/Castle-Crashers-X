DEFINE_REX_FUNC(sub_82065418) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x82065420;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r30,r28,20
	ctx.r30.s64 = ctx.r28.s64 + 20;
	// addi r10,r11,18696
	ctx.r10.s64 = ctx.r11.s64 + 18696;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// li r29,64
	ctx.r29.s64 = 64;
	// lis r26,-32215
	ctx.r26.s64 = -2111242240;
	// addi r27,r11,29632
	ctx.r27.s64 = ctx.r11.s64 + 29632;
	// addi r25,r10,-1768
	ctx.r25.s64 = ctx.r10.s64 + -1768;
loc_82065450:
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82065490
	if (ctx.cr6.eq) goto loc_82065490;
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206547c
	if (!ctx.cr6.eq) goto loc_8206547C;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206547C;
	sub_820A71E8(ctx, base);
loc_8206547C:
	// bl 0x820b5eb8
	ctx.lr = 0x82065480;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bf18
	ctx.lr = 0x82065490;
	sub_8209BF18(ctx, base);
loc_82065490:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// bne 0x82065450
	if (!ctx.cr0.eq) goto loc_82065450;
	// addi r30,r28,276
	ctx.r30.s64 = ctx.r28.s64 + 276;
	// li r29,16
	ctx.r29.s64 = 16;
loc_820654A4:
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820654e4
	if (ctx.cr6.eq) goto loc_820654E4;
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820654d0
	if (!ctx.cr6.eq) goto loc_820654D0;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820654D0;
	sub_820A71E8(ctx, base);
loc_820654D0:
	// bl 0x820b5eb8
	ctx.lr = 0x820654D4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bf18
	ctx.lr = 0x820654E4;
	sub_8209BF18(ctx, base);
loc_820654E4:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// bne 0x820654a4
	if (!ctx.cr0.eq) goto loc_820654A4;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
