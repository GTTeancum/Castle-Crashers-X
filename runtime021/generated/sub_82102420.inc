DEFINE_REX_FUNC(sub_82102420) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x82102428;
	__savegprlr_25(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82102454
	if (ctx.cr6.eq) goto loc_82102454;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,1609
	ctx.r30.u64 = ctx.r30.u64 | 1609;
	// b 0x82102698
	goto loc_82102698;
loc_82102454:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r11,2
	ctx.r11.s64 = 2;
	// li r26,0
	ctx.r26.s64 = 0;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r26,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r26.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82102484;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fe5f8
	ctx.lr = 0x8210249C;
	sub_820FE5F8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82102698
	if (ctx.cr0.lt) goto loc_82102698;
	// lwz r7,60(r27)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r27.u32 + 60);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x821024c0
	if (!ctx.cr6.lt) goto loc_821024C0;
	// lis r30,-32747
	ctx.r30.s64 = -2146107392;
	// ori r30,r30,20994
	ctx.r30.u64 = ctx.r30.u64 | 20994;
	// b 0x82102698
	goto loc_82102698;
loc_821024C0:
	// lwz r8,80(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 80);
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82102528
	if (ctx.cr6.eq) goto loc_82102528;
	// lwz r11,88(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 88);
loc_821024D4:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,32778
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 32778, ctx.xer);
	// bne cr6,0x82102518
	if (!ctx.cr6.eq) goto loc_82102518;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82102504
	if (!ctx.cr6.eq) goto loc_82102504;
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// beq cr6,0x82102518
	if (ctx.cr6.eq) goto loc_82102518;
loc_821024F8:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,117
	ctx.r30.u64 = ctx.r30.u64 | 117;
	// b 0x82102698
	goto loc_82102698;
loc_82102504:
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x82102518
	if (!ctx.cr6.eq) goto loc_82102518;
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// beq cr6,0x821024f8
	if (ctx.cr6.eq) goto loc_821024F8;
loc_82102518:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x821024d4
	if (ctx.cr6.lt) goto loc_821024D4;
loc_82102528:
	// lwz r11,68(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 68);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// subf r10,r10,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r10.u64;
	// stb r11,168(r31)
	REX_STORE_U8(ctx.r31.u32 + 168, ctx.r11.u8);
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r11,64(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 64);
	// rlwinm r4,r10,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r10,72(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 72);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stb r11,169(r31)
	REX_STORE_U8(ctx.r31.u32 + 169, ctx.r11.u8);
	// bl 0x820fcaa8
	ctx.lr = 0x8210255C;
	sub_820FCAA8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// rlwinm. r11,r28,0,29,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x6;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210257c
	if (ctx.cr0.eq) goto loc_8210257C;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x8210257c
	if (!ctx.cr6.eq) goto loc_8210257C;
	// lis r30,-32747
	ctx.r30.s64 = -2146107392;
	// ori r30,r30,21001
	ctx.r30.u64 = ctx.r30.u64 | 21001;
	// b 0x82102698
	goto loc_82102698;
loc_8210257C:
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r8,r28,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x4;
	// rlwimi r11,r28,10,20,20
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 10) & 0x800) | (ctx.r11.u64 & 0xFFFFFFFFFFFFF7FF);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// li r6,254
	ctx.r6.s64 = 254;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821009f8
	ctx.lr = 0x821025A8;
	sub_821009F8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82102698
	if (ctx.cr0.lt) goto loc_82102698;
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// addi r29,r31,380
	ctx.r29.s64 = ctx.r31.s64 + 380;
loc_821025B8:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821025e8
	if (ctx.cr6.eq) goto loc_821025E8;
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lis r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// ori r4,r4,32778
	ctx.r4.u64 = ctx.r4.u64 | 32778;
	// li r5,0
	ctx.r5.s64 = 0;
	// beq cr6,0x821025e4
	if (ctx.cr6.eq) goto loc_821025E4;
	// li r5,1
	ctx.r5.s64 = 1;
loc_821025E4:
	// bl 0x820b5958
	ctx.lr = 0x821025E8;
	sub_820B5958(ctx, base);
loc_821025E8:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x821025b8
	if (ctx.cr6.lt) goto loc_821025B8;
	// lwz r30,8(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82136f58
	ctx.lr = 0x82102600;
	sub_82136F58(ctx, base);
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// addi r29,r31,48
	ctx.r29.s64 = ctx.r31.s64 + 48;
	// li r5,60
	ctx.r5.s64 = 60;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r11,44(r30)
	REX_STORE_U32(ctx.r30.u32 + 44, ctx.r11.u32);
	// bl 0x82129a70
	ctx.lr = 0x82102624;
	sub_82129A70(ctx, base);
	// lbz r6,169(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 169);
	// lbz r11,168(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 168);
	// addi r30,r31,200
	ctx.r30.s64 = ctx.r31.s64 + 200;
	// stw r28,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r28.u32);
	// addi r10,r31,32
	ctx.r10.s64 = ctx.r31.s64 + 32;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// addi r7,r31,40
	ctx.r7.s64 = ctx.r31.s64 + 40;
	// stb r6,173(r31)
	REX_STORE_U8(ctx.r31.u32 + 173, ctx.r6.u8);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// stb r11,172(r31)
	REX_STORE_U8(ctx.r31.u32 + 172, ctx.r11.u8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// std r26,200(r31)
	REX_STORE_U64(ctx.r31.u32 + 200, ctx.r26.u64);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// std r26,208(r31)
	REX_STORE_U64(ctx.r31.u32 + 208, ctx.r26.u64);
	// std r26,216(r31)
	REX_STORE_U64(ctx.r31.u32 + 216, ctx.r26.u64);
	// stw r26,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r26.u32);
	// lbz r6,169(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 169);
	// lbz r5,168(r31)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r31.u32 + 168);
	// bl 0x82138678
	ctx.lr = 0x82102670;
	sub_82138678(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x821026a8
	if (ctx.cr0.eq) goto loc_821026A8;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x821026a8
	if (ctx.cr6.eq) goto loc_821026A8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82136e38
	ctx.lr = 0x82102688;
	sub_82136E38(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82102698
	if (ctx.cr0.lt) goto loc_82102698;
	// lis r30,-32768
	ctx.r30.s64 = -2147483648;
	// ori r30,r30,16389
	ctx.r30.u64 = ctx.r30.u64 | 16389;
loc_82102698:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82100fd8
	ctx.lr = 0x821026A4;
	sub_82100FD8(ctx, base);
	// b 0x821026b8
	goto loc_821026B8;
loc_821026A8:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// addi r11,r11,6936
	ctx.r11.s64 = ctx.r11.s64 + 6936;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
loc_821026B8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
