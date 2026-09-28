DEFINE_REX_FUNC(sub_8208F178) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298ec
	ctx.lr = 0x8208F180;
	__savegprlr_17(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r17,r4
	ctx.r17.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r11,r17,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208f2fc
	if (ctx.cr6.eq) goto loc_8208F2FC;
	// lwz r10,-4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + -4);
	// addi r18,r31,-4
	ctx.r18.s64 = ctx.r31.s64 + -4;
	// mulli r11,r10,168
	ctx.r11.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(168));
	// addic. r21,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r21.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// add r29,r11,r31
	ctx.r29.u64 = ctx.r11.u64 + ctx.r31.u64;
	// blt 0x8208f2dc
	if (ctx.cr0.lt) goto loc_8208F2DC;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r8,-32218
	ctx.r8.s64 = -2111438848;
	// lis r7,-32221
	ctx.r7.s64 = -2111635456;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r31,r29,8
	ctx.r31.s64 = ctx.r29.s64 + 8;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r22,-32215
	ctx.r22.s64 = -2111242240;
	// ori r19,r6,65535
	ctx.r19.u64 = ctx.r6.u64 | 65535;
	// li r23,1
	ctx.r23.s64 = 1;
	// addi r24,r8,29632
	ctx.r24.s64 = ctx.r8.s64 + 29632;
	// addi r20,r7,-1768
	ctx.r20.s64 = ctx.r7.s64 + -1768;
	// addi r27,r9,-7184
	ctx.r27.s64 = ctx.r9.s64 + -7184;
	// addi r26,r10,-6264
	ctx.r26.s64 = ctx.r10.s64 + -6264;
	// addi r25,r11,-2432
	ctx.r25.s64 = ctx.r11.s64 + -2432;
loc_8208F1F0:
	// addi r29,r29,-168
	ctx.r29.s64 = ctx.r29.s64 + -168;
	// addi r31,r31,-168
	ctx.r31.s64 = ctx.r31.s64 + -168;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r25,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r25.u32);
	// bl 0x82094d28
	ctx.lr = 0x8208F204;
	sub_82094D28(ctx, base);
	// stw r26,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r26.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82079a00
	ctx.lr = 0x8208F210;
	sub_82079A00(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// stw r30,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208f260
	if (ctx.cr6.eq) goto loc_8208F260;
	// stw r30,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r30.u32);
	// lwz r28,68(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8208F23C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// and r9,r3,r12
	ctx.r9.u64 = ctx.r3.u64 & ctx.r12.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8208f25c
	if (ctx.cr6.eq) goto loc_8208F25C;
	// lhz r11,24(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 24);
	// add r10,r11,r19
	ctx.r10.u64 = ctx.r11.u64 + ctx.r19.u64;
	// sth r10,24(r28)
	REX_STORE_U16(ctx.r28.u32 + 24, ctx.r10.u16);
loc_8208F25C:
	// stw r30,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r30.u32);
loc_8208F260:
	// lbz r11,78(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 78);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r27,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r27.u32);
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// sth r30,74(r31)
	REX_STORE_U16(ctx.r31.u32 + 74, ctx.r30.u16);
	// sth r23,76(r31)
	REX_STORE_U16(ctx.r31.u32 + 76, ctx.r23.u16);
	// stb r10,78(r31)
	REX_STORE_U8(ctx.r31.u32 + 78, ctx.r10.u8);
	// stw r30,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// bl 0x82079a00
	ctx.lr = 0x8208F288;
	sub_82079A00(ctx, base);
	// lwz r28,0(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8208f2cc
	if (ctx.cr6.eq) goto loc_8208F2CC;
	// lbz r11,-22601(r22)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r22.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208f2b4
	if (!ctx.cr6.eq) goto loc_8208F2B4;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8208F2B4;
	sub_820A71E8(ctx, base);
loc_8208F2B4:
	// bl 0x820b5eb8
	ctx.lr = 0x8208F2B8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8208F2C8;
	sub_8209BF18(ctx, base);
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
loc_8208F2CC:
	// addic. r21,r21,-1
	ctx.xer.ca = ctx.r21.u32 > 0;
	ctx.r21.s64 = ctx.r21.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// stw r30,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r30.u32);
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// bge 0x8208f1f0
	if (!ctx.cr0.lt) goto loc_8208F1F0;
loc_8208F2DC:
	// clrlwi r11,r17,31
	ctx.r11.u64 = ctx.r17.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208f2f0
	if (ctx.cr6.eq) goto loc_8208F2F0;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x820a7400
	ctx.lr = 0x8208F2F0;
	sub_820A7400(ctx, base);
loc_8208F2F0:
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8212993c
	__restgprlr_17(ctx, base);
	return;
loc_8208F2FC:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,-2432
	ctx.r10.s64 = ctx.r11.s64 + -2432;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x82094d28
	ctx.lr = 0x8208F310;
	sub_82094D28(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r8,r9,-2192
	ctx.r8.s64 = ctx.r9.s64 + -2192;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// bl 0x820861e0
	ctx.lr = 0x8208F324;
	sub_820861E0(ctx, base);
	// clrlwi r7,r17,31
	ctx.r7.u64 = ctx.r17.u32 & 0x1;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8208f338
	if (ctx.cr6.eq) goto loc_8208F338;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a7400
	ctx.lr = 0x8208F338;
	sub_820A7400(ctx, base);
loc_8208F338:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8212993c
	__restgprlr_17(ctx, base);
	return;
}
