DEFINE_REX_FUNC(sub_8209A288) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x8209A290;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// addi r30,r11,-22032
	ctx.r30.s64 = ctx.r11.s64 + -22032;
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209a2c4
	if (ctx.cr6.eq) goto loc_8209A2C4;
loc_8209A2A8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209a2c0
	if (ctx.cr6.eq) goto loc_8209A2C0;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8209a2a8
	if (!ctx.cr0.eq) goto loc_8209A2A8;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r10.u32);
loc_8209A2C0:
	// stw r11,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
loc_8209A2C4:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// lwz r31,4(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lis r27,-32215
	ctx.r27.s64 = -2111242240;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r26,r9,29632
	ctx.r26.s64 = ctx.r9.s64 + 29632;
	// addi r25,r10,-1768
	ctx.r25.s64 = ctx.r10.s64 + -1768;
	// beq cr6,0x8209a348
	if (ctx.cr6.eq) goto loc_8209A348;
	// rlwinm r29,r28,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
loc_8209A2F0:
	// addi r29,r29,-4
	ctx.r29.s64 = ctx.r29.s64 + -4;
	// addi r28,r28,-1
	ctx.r28.s64 = ctx.r28.s64 + -1;
	// lwzx r11,r29,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r31.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209a340
	if (ctx.cr6.eq) goto loc_8209A340;
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// lwzx r31,r29,r31
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r31.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209a328
	if (!ctx.cr6.eq) goto loc_8209A328;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209A328;
	sub_820A71E8(ctx, base);
loc_8209A328:
	// bl 0x820b5eb8
	ctx.lr = 0x8209A32C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwzx r3,r11,r26
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8209A33C;
	sub_8209BF18(ctx, base);
	// lwz r31,4(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
loc_8209A340:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x8209a2f0
	if (!ctx.cr6.eq) goto loc_8209A2F0;
loc_8209A348:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8209a384
	if (ctx.cr6.eq) goto loc_8209A384;
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209a370
	if (!ctx.cr6.eq) goto loc_8209A370;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209A370;
	sub_820A71E8(ctx, base);
loc_8209A370:
	// bl 0x820b5eb8
	ctx.lr = 0x8209A374;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwzx r3,r11,r26
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8209A384;
	sub_8209BF18(ctx, base);
loc_8209A384:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
