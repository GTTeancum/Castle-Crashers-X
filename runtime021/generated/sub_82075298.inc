DEFINE_REX_FUNC(sub_82075298) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x820752A0;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r25,-32215
	ctx.r25.s64 = -2111242240;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r24,r11,-1768
	ctx.r24.s64 = ctx.r11.s64 + -1768;
	// lbz r11,-22601(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820752d4
	if (!ctx.cr6.eq) goto loc_820752D4;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820752D4;
	sub_820A71E8(ctx, base);
loc_820752D4:
	// bl 0x820b5eb8
	ctx.lr = 0x820752D8;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r11,29632
	ctx.r29.s64 = ctx.r11.s64 + 29632;
	// li r4,264
	ctx.r4.s64 = 264;
	// lwzx r3,r10,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820752F0;
	sub_8209BDD8(ctx, base);
	// li r26,0
	ctx.r26.s64 = 0;
	// stw r3,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r3.u32);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r26,256(r3)
	REX_STORE_U32(ctx.r3.u32 + 256, ctx.r26.u32);
	// addi r28,r11,-8196
	ctx.r28.s64 = ctx.r11.s64 + -8196;
	// lwz r31,0(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82127778
	ctx.lr = 0x82075314;
	sub_82127778(ctx, base);
	// li r30,127
	ctx.r30.s64 = 127;
loc_82075318:
	// lbz r11,-22601(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82075338
	if (!ctx.cr6.eq) goto loc_82075338;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82075338;
	sub_820A71E8(ctx, base);
loc_82075338:
	// bl 0x820b5eb8
	ctx.lr = 0x8207533C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,264
	ctx.r4.s64 = 264;
	// lwzx r3,r11,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8207534C;
	sub_8209BDD8(ctx, base);
	// stw r3,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r3.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82127778
	ctx.lr = 0x82075358;
	sub_82127778(ctx, base);
	// lwz r10,260(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r31,256(r10)
	REX_STORE_U32(ctx.r10.u32 + 256, ctx.r31.u32);
	// lwz r31,260(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// bne 0x82075318
	if (!ctx.cr0.eq) goto loc_82075318;
	// stw r26,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r26.u32);
	// stw r31,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r31.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
