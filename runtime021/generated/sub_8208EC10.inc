DEFINE_REX_FUNC(sub_8208EC10) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x8208EC18;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r4
	ctx.r21.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r11,r21,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208ecf4
	if (ctx.cr6.eq) goto loc_8208ECF4;
	// lwz r10,-4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + -4);
	// addi r22,r31,-4
	ctx.r22.s64 = ctx.r31.s64 + -4;
	// mulli r11,r10,28
	ctx.r11.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(28));
	// addic. r27,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r27.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// add r29,r11,r31
	ctx.r29.u64 = ctx.r11.u64 + ctx.r31.u64;
	// blt 0x8208ecd4
	if (ctx.cr0.lt) goto loc_8208ECD4;
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r31,r29,8
	ctx.r31.s64 = ctx.r29.s64 + 8;
	// li r28,0
	ctx.r28.s64 = 0;
	// lis r24,-32215
	ctx.r24.s64 = -2111242240;
	// addi r26,r9,29632
	ctx.r26.s64 = ctx.r9.s64 + 29632;
	// addi r23,r10,-1768
	ctx.r23.s64 = ctx.r10.s64 + -1768;
	// addi r25,r11,-7184
	ctx.r25.s64 = ctx.r11.s64 + -7184;
loc_8208EC6C:
	// addi r29,r29,-28
	ctx.r29.s64 = ctx.r29.s64 + -28;
	// addi r31,r31,-28
	ctx.r31.s64 = ctx.r31.s64 + -28;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r25,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r25.u32);
	// bl 0x82079a00
	ctx.lr = 0x8208EC80;
	sub_82079A00(ctx, base);
	// lwz r30,0(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8208ecc4
	if (ctx.cr6.eq) goto loc_8208ECC4;
	// lbz r11,-22601(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208ecac
	if (!ctx.cr6.eq) goto loc_8208ECAC;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8208ECAC;
	sub_820A71E8(ctx, base);
loc_8208ECAC:
	// bl 0x820b5eb8
	ctx.lr = 0x8208ECB0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r3,r11,r26
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8208ECC0;
	sub_8209BF18(ctx, base);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
loc_8208ECC4:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// stw r28,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r28.u32);
	// stw r28,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
	// bge 0x8208ec6c
	if (!ctx.cr0.lt) goto loc_8208EC6C;
loc_8208ECD4:
	// clrlwi r11,r21,31
	ctx.r11.u64 = ctx.r21.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208ece8
	if (ctx.cr6.eq) goto loc_8208ECE8;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x820a7400
	ctx.lr = 0x8208ECE8;
	sub_820A7400(ctx, base);
loc_8208ECE8:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
loc_8208ECF4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82079970
	ctx.lr = 0x8208ECFC;
	sub_82079970(ctx, base);
	// clrlwi r11,r21,31
	ctx.r11.u64 = ctx.r21.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208ed10
	if (ctx.cr6.eq) goto loc_8208ED10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a7400
	ctx.lr = 0x8208ED10;
	sub_820A7400(ctx, base);
loc_8208ED10:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
