DEFINE_REX_FUNC(sub_8208E580) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298ec
	ctx.lr = 0x8208E588;
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
	// beq cr6,0x8208e760
	if (ctx.cr6.eq) goto loc_8208E760;
	// lwz r10,-4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + -4);
	// addi r18,r31,-4
	ctx.r18.s64 = ctx.r31.s64 + -4;
	// mulli r11,r10,248
	ctx.r11.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(248));
	// addic. r20,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r20.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// add r28,r11,r31
	ctx.r28.u64 = ctx.r11.u64 + ctx.r31.u64;
	// blt 0x8208e740
	if (ctx.cr0.lt) goto loc_8208E740;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r31,r28,112
	ctx.r31.s64 = ctx.r28.s64 + 112;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r23,-32215
	ctx.r23.s64 = -2111242240;
	// ori r19,r6,65535
	ctx.r19.u64 = ctx.r6.u64 | 65535;
	// li r22,1
	ctx.r22.s64 = 1;
	// addi r27,r7,29632
	ctx.r27.s64 = ctx.r7.s64 + 29632;
	// addi r26,r8,-7184
	ctx.r26.s64 = ctx.r8.s64 + -7184;
	// addi r25,r9,-6264
	ctx.r25.s64 = ctx.r9.s64 + -6264;
	// addi r21,r10,-1768
	ctx.r21.s64 = ctx.r10.s64 + -1768;
	// addi r24,r11,-6024
	ctx.r24.s64 = ctx.r11.s64 + -6024;
loc_8208E5F8:
	// addi r28,r28,-248
	ctx.r28.s64 = ctx.r28.s64 + -248;
	// addi r31,r31,-248
	ctx.r31.s64 = ctx.r31.s64 + -248;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r24,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r24.u32);
	// bl 0x82086ba8
	ctx.lr = 0x8208E60C;
	sub_82086BA8(ctx, base);
	// addi r3,r31,48
	ctx.r3.s64 = ctx.r31.s64 + 48;
	// bl 0x8207a7e0
	ctx.lr = 0x8208E614;
	sub_8207A7E0(ctx, base);
	// lwz r29,0(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8208e658
	if (ctx.cr6.eq) goto loc_8208E658;
	// lbz r11,-22601(r23)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r23.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208e640
	if (!ctx.cr6.eq) goto loc_8208E640;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8208E640;
	sub_820A71E8(ctx, base);
loc_8208E640:
	// bl 0x820b5eb8
	ctx.lr = 0x8208E644;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8208E654;
	sub_8209BF18(ctx, base);
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
loc_8208E658:
	// stw r30,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r30.u32);
	// addi r3,r31,-8
	ctx.r3.s64 = ctx.r31.s64 + -8;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// bl 0x82084be8
	ctx.lr = 0x8208E668;
	sub_82084BE8(ctx, base);
	// stw r25,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r25.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82079a00
	ctx.lr = 0x8208E674;
	sub_82079A00(ctx, base);
	// lwz r11,-36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -36);
	// stw r30,-84(r31)
	REX_STORE_U32(ctx.r31.u32 + -84, ctx.r30.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208e6c4
	if (ctx.cr6.eq) goto loc_8208E6C4;
	// stw r30,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r30.u32);
	// lwz r29,-36(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + -36);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8208E6A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// and r9,r3,r12
	ctx.r9.u64 = ctx.r3.u64 & ctx.r12.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8208e6c0
	if (ctx.cr6.eq) goto loc_8208E6C0;
	// lhz r11,24(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 24);
	// add r10,r11,r19
	ctx.r10.u64 = ctx.r11.u64 + ctx.r19.u64;
	// sth r10,24(r29)
	REX_STORE_U16(ctx.r29.u32 + 24, ctx.r10.u16);
loc_8208E6C0:
	// stw r30,-36(r31)
	REX_STORE_U32(ctx.r31.u32 + -36, ctx.r30.u32);
loc_8208E6C4:
	// lbz r11,-26(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + -26);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r26,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r26.u32);
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// sth r30,-30(r31)
	REX_STORE_U16(ctx.r31.u32 + -30, ctx.r30.u16);
	// sth r22,-28(r31)
	REX_STORE_U16(ctx.r31.u32 + -28, ctx.r22.u16);
	// stb r10,-26(r31)
	REX_STORE_U8(ctx.r31.u32 + -26, ctx.r10.u8);
	// stw r30,-24(r31)
	REX_STORE_U32(ctx.r31.u32 + -24, ctx.r30.u32);
	// stw r30,-80(r31)
	REX_STORE_U32(ctx.r31.u32 + -80, ctx.r30.u32);
	// bl 0x82079a00
	ctx.lr = 0x8208E6EC;
	sub_82079A00(ctx, base);
	// lwz r29,-104(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + -104);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8208e730
	if (ctx.cr6.eq) goto loc_8208E730;
	// lbz r11,-22601(r23)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r23.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208e718
	if (!ctx.cr6.eq) goto loc_8208E718;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8208E718;
	sub_820A71E8(ctx, base);
loc_8208E718:
	// bl 0x820b5eb8
	ctx.lr = 0x8208E71C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8208E72C;
	sub_8209BF18(ctx, base);
	// stw r30,-104(r31)
	REX_STORE_U32(ctx.r31.u32 + -104, ctx.r30.u32);
loc_8208E730:
	// addic. r20,r20,-1
	ctx.xer.ca = ctx.r20.u32 > 0;
	ctx.r20.s64 = ctx.r20.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// stw r30,-108(r31)
	REX_STORE_U32(ctx.r31.u32 + -108, ctx.r30.u32);
	// stw r30,-100(r31)
	REX_STORE_U32(ctx.r31.u32 + -100, ctx.r30.u32);
	// bge 0x8208e5f8
	if (!ctx.cr0.lt) goto loc_8208E5F8;
loc_8208E740:
	// clrlwi r11,r17,31
	ctx.r11.u64 = ctx.r17.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208e754
	if (ctx.cr6.eq) goto loc_8208E754;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x820a7400
	ctx.lr = 0x8208E754;
	sub_820A7400(ctx, base);
loc_8208E754:
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8212993c
	__restgprlr_17(ctx, base);
	return;
loc_8208E760:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82086b00
	ctx.lr = 0x8208E768;
	sub_82086B00(ctx, base);
	// clrlwi r11,r17,31
	ctx.r11.u64 = ctx.r17.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208e77c
	if (ctx.cr6.eq) goto loc_8208E77C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a7400
	ctx.lr = 0x8208E77C;
	sub_820A7400(ctx, base);
loc_8208E77C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8212993c
	__restgprlr_17(ctx, base);
	return;
}
