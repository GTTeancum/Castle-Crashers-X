DEFINE_REX_FUNC(sub_8208E930) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x8208E938;
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
	// beq cr6,0x8208ea1c
	if (ctx.cr6.eq) goto loc_8208EA1C;
	// lwz r11,-4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -4);
	// addi r22,r31,-4
	ctx.r22.s64 = ctx.r31.s64 + -4;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addic. r27,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r27.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r29,r11,r31
	ctx.r29.u64 = ctx.r11.u64 + ctx.r31.u64;
	// blt 0x8208e9fc
	if (ctx.cr0.lt) goto loc_8208E9FC;
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
loc_8208E994:
	// addi r29,r29,-48
	ctx.r29.s64 = ctx.r29.s64 + -48;
	// addi r31,r31,-48
	ctx.r31.s64 = ctx.r31.s64 + -48;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r25,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r25.u32);
	// bl 0x82079a00
	ctx.lr = 0x8208E9A8;
	sub_82079A00(ctx, base);
	// lwz r30,0(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8208e9ec
	if (ctx.cr6.eq) goto loc_8208E9EC;
	// lbz r11,-22601(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208e9d4
	if (!ctx.cr6.eq) goto loc_8208E9D4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8208E9D4;
	sub_820A71E8(ctx, base);
loc_8208E9D4:
	// bl 0x820b5eb8
	ctx.lr = 0x8208E9D8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r3,r11,r26
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8208E9E8;
	sub_8209BF18(ctx, base);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
loc_8208E9EC:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// stw r28,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r28.u32);
	// stw r28,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
	// bge 0x8208e994
	if (!ctx.cr0.lt) goto loc_8208E994;
loc_8208E9FC:
	// clrlwi r11,r21,31
	ctx.r11.u64 = ctx.r21.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208ea10
	if (ctx.cr6.eq) goto loc_8208EA10;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x820a7400
	ctx.lr = 0x8208EA10;
	sub_820A7400(ctx, base);
loc_8208EA10:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
loc_8208EA1C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,-7008
	ctx.r10.s64 = ctx.r11.s64 + -7008;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x82079970
	ctx.lr = 0x8208EA30;
	sub_82079970(ctx, base);
	// clrlwi r9,r21,31
	ctx.r9.u64 = ctx.r21.u32 & 0x1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8208ea44
	if (ctx.cr6.eq) goto loc_8208EA44;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a7400
	ctx.lr = 0x8208EA44;
	sub_820A7400(ctx, base);
loc_8208EA44:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
