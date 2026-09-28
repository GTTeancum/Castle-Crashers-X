DEFINE_REX_FUNC(sub_8208ED20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f8
	ctx.lr = 0x8208ED28;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r20,r4
	ctx.r20.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r11,r20,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208ee20
	if (ctx.cr6.eq) goto loc_8208EE20;
	// lwz r11,-4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -4);
	// addi r21,r31,-4
	ctx.r21.s64 = ctx.r31.s64 + -4;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addic. r25,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r25.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// blt 0x8208ee00
	if (ctx.cr0.lt) goto loc_8208EE00;
	// lis r8,-32218
	ctx.r8.s64 = -2111438848;
	// lis r9,-32221
	ctx.r9.s64 = -2111635456;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r30,r31,8
	ctx.r30.s64 = ctx.r31.s64 + 8;
	// li r28,0
	ctx.r28.s64 = 0;
	// lis r23,-32215
	ctx.r23.s64 = -2111242240;
	// addi r24,r8,29632
	ctx.r24.s64 = ctx.r8.s64 + 29632;
	// addi r22,r9,-1768
	ctx.r22.s64 = ctx.r9.s64 + -1768;
	// addi r27,r10,-7184
	ctx.r27.s64 = ctx.r10.s64 + -7184;
	// addi r26,r11,-4716
	ctx.r26.s64 = ctx.r11.s64 + -4716;
loc_8208ED8C:
	// addi r31,r31,-36
	ctx.r31.s64 = ctx.r31.s64 + -36;
	// addi r30,r30,-36
	ctx.r30.s64 = ctx.r30.s64 + -36;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r26,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// bl 0x8208cca8
	ctx.lr = 0x8208EDA0;
	sub_8208CCA8(ctx, base);
	// stw r27,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r27.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82079a00
	ctx.lr = 0x8208EDAC;
	sub_82079A00(ctx, base);
	// lwz r29,0(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8208edf0
	if (ctx.cr6.eq) goto loc_8208EDF0;
	// lbz r11,-22601(r23)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r23.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208edd8
	if (!ctx.cr6.eq) goto loc_8208EDD8;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8208EDD8;
	sub_820A71E8(ctx, base);
loc_8208EDD8:
	// bl 0x820b5eb8
	ctx.lr = 0x8208EDDC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8208EDEC;
	sub_8209BF18(ctx, base);
	// stw r28,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
loc_8208EDF0:
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// stw r28,-4(r30)
	REX_STORE_U32(ctx.r30.u32 + -4, ctx.r28.u32);
	// stw r28,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r28.u32);
	// bge 0x8208ed8c
	if (!ctx.cr0.lt) goto loc_8208ED8C;
loc_8208EE00:
	// clrlwi r11,r20,31
	ctx.r11.u64 = ctx.r20.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208ee14
	if (ctx.cr6.eq) goto loc_8208EE14;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x820a7400
	ctx.lr = 0x8208EE14;
	sub_820A7400(ctx, base);
loc_8208EE14:
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
loc_8208EE20:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,-4716
	ctx.r10.s64 = ctx.r11.s64 + -4716;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x8208cca8
	ctx.lr = 0x8208EE34;
	sub_8208CCA8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82079970
	ctx.lr = 0x8208EE3C;
	sub_82079970(ctx, base);
	// clrlwi r9,r20,31
	ctx.r9.u64 = ctx.r20.u32 & 0x1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8208ee50
	if (ctx.cr6.eq) goto loc_8208EE50;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a7400
	ctx.lr = 0x8208EE50;
	sub_820A7400(ctx, base);
loc_8208EE50:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
}
