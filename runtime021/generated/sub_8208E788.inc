DEFINE_REX_FUNC(sub_8208E788) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f0
	ctx.lr = 0x8208E790;
	__savegprlr_18(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r11,r18,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208e8f8
	if (ctx.cr6.eq) goto loc_8208E8F8;
	// lwz r10,-4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + -4);
	// addi r19,r31,-4
	ctx.r19.s64 = ctx.r31.s64 + -4;
	// mulli r11,r10,116
	ctx.r11.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(116));
	// addic. r23,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r23.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// add r28,r11,r31
	ctx.r28.u64 = ctx.r11.u64 + ctx.r31.u64;
	// blt 0x8208e8d8
	if (ctx.cr0.lt) goto loc_8208E8D8;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r8,-32218
	ctx.r8.s64 = -2111438848;
	// lis r9,-32221
	ctx.r9.s64 = -2111635456;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r31,r28,8
	ctx.r31.s64 = ctx.r28.s64 + 8;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r22,-32215
	ctx.r22.s64 = -2111242240;
	// ori r20,r7,65535
	ctx.r20.u64 = ctx.r7.u64 | 65535;
	// li r24,1
	ctx.r24.s64 = 1;
	// addi r25,r8,29632
	ctx.r25.s64 = ctx.r8.s64 + 29632;
	// addi r21,r9,-1768
	ctx.r21.s64 = ctx.r9.s64 + -1768;
	// addi r27,r10,-7184
	ctx.r27.s64 = ctx.r10.s64 + -7184;
	// addi r26,r11,-6264
	ctx.r26.s64 = ctx.r11.s64 + -6264;
loc_8208E7F8:
	// addi r28,r28,-116
	ctx.r28.s64 = ctx.r28.s64 + -116;
	// addi r31,r31,-116
	ctx.r31.s64 = ctx.r31.s64 + -116;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r26,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r26.u32);
	// bl 0x82079a00
	ctx.lr = 0x8208E80C;
	sub_82079A00(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// stw r30,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208e85c
	if (ctx.cr6.eq) goto loc_8208E85C;
	// stw r30,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r30.u32);
	// lwz r29,68(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8208E838;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// and r9,r3,r12
	ctx.r9.u64 = ctx.r3.u64 & ctx.r12.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8208e858
	if (ctx.cr6.eq) goto loc_8208E858;
	// lhz r11,24(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 24);
	// add r10,r11,r20
	ctx.r10.u64 = ctx.r11.u64 + ctx.r20.u64;
	// sth r10,24(r29)
	REX_STORE_U16(ctx.r29.u32 + 24, ctx.r10.u16);
loc_8208E858:
	// stw r30,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r30.u32);
loc_8208E85C:
	// lbz r11,78(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 78);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r27,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r27.u32);
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// sth r30,74(r31)
	REX_STORE_U16(ctx.r31.u32 + 74, ctx.r30.u16);
	// sth r24,76(r31)
	REX_STORE_U16(ctx.r31.u32 + 76, ctx.r24.u16);
	// stb r10,78(r31)
	REX_STORE_U8(ctx.r31.u32 + 78, ctx.r10.u8);
	// stw r30,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// bl 0x82079a00
	ctx.lr = 0x8208E884;
	sub_82079A00(ctx, base);
	// lwz r29,0(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8208e8c8
	if (ctx.cr6.eq) goto loc_8208E8C8;
	// lbz r11,-22601(r22)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r22.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208e8b0
	if (!ctx.cr6.eq) goto loc_8208E8B0;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8208E8B0;
	sub_820A71E8(ctx, base);
loc_8208E8B0:
	// bl 0x820b5eb8
	ctx.lr = 0x8208E8B4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8208E8C4;
	sub_8209BF18(ctx, base);
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
loc_8208E8C8:
	// addic. r23,r23,-1
	ctx.xer.ca = ctx.r23.u32 > 0;
	ctx.r23.s64 = ctx.r23.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// stw r30,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r30.u32);
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// bge 0x8208e7f8
	if (!ctx.cr0.lt) goto loc_8208E7F8;
loc_8208E8D8:
	// clrlwi r11,r18,31
	ctx.r11.u64 = ctx.r18.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208e8ec
	if (ctx.cr6.eq) goto loc_8208E8EC;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// bl 0x820a7400
	ctx.lr = 0x8208E8EC;
	sub_820A7400(ctx, base);
loc_8208E8EC:
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129940
	__restgprlr_18(ctx, base);
	return;
loc_8208E8F8:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,-4960
	ctx.r10.s64 = ctx.r11.s64 + -4960;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x820861e0
	ctx.lr = 0x8208E90C;
	sub_820861E0(ctx, base);
	// clrlwi r9,r18,31
	ctx.r9.u64 = ctx.r18.u32 & 0x1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8208e920
	if (ctx.cr6.eq) goto loc_8208E920;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a7400
	ctx.lr = 0x8208E920;
	sub_820A7400(ctx, base);
loc_8208E920:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129940
	__restgprlr_18(ctx, base);
	return;
}
