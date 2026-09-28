DEFINE_REX_FUNC(sub_821020F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f8
	ctx.lr = 0x821020F8;
	__savegprlr_20(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r20,r4
	ctx.r20.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r23,r6
	ctx.r23.u64 = ctx.r6.u64;
	// mr r22,r7
	ctx.r22.u64 = ctx.r7.u64;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r24,r9
	ctx.r24.u64 = ctx.r9.u64;
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82102134
	if (ctx.cr6.eq) goto loc_82102134;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,1609
	ctx.r30.u64 = ctx.r30.u64 | 1609;
	// b 0x821023f0
	goto loc_821023F0;
loc_82102134:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r21,0
	ctx.r21.s64 = 0;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r21,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r21.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82102164;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fe5f8
	ctx.lr = 0x8210217C;
	sub_820FE5F8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x821023f0
	if (ctx.cr0.lt) goto loc_821023F0;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r23,r11
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8210219c
	if (!ctx.cr6.lt) goto loc_8210219C;
	// lis r30,-32747
	ctx.r30.s64 = -2146107392;
	// ori r30,r30,20994
	ctx.r30.u64 = ctx.r30.u64 | 20994;
	// b 0x821023f0
	goto loc_821023F0;
loc_8210219C:
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82102208
	if (ctx.cr6.eq) goto loc_82102208;
	// lwz r27,324(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 324);
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
loc_821021BC:
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,32778
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32778, ctx.xer);
	// bne cr6,0x821021e0
	if (!ctx.cr6.eq) goto loc_821021E0;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821021d8
	if (!ctx.cr6.eq) goto loc_821021D8;
	// li r6,1
	ctx.r6.s64 = 1;
loc_821021D8:
	// li r8,1
	ctx.r8.s64 = 1;
	// b 0x821021ec
	goto loc_821021EC;
loc_821021E0:
	// cmplwi cr6,r11,32779
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32779, ctx.xer);
	// bne cr6,0x821021ec
	if (!ctx.cr6.eq) goto loc_821021EC;
	// li r7,1
	ctx.r7.s64 = 1;
loc_821021EC:
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bne 0x821021bc
	if (!ctx.cr0.eq) goto loc_821021BC;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82102208
	if (ctx.cr6.eq) goto loc_82102208;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x82102214
	if (!ctx.cr6.eq) goto loc_82102214;
loc_82102208:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,87
	ctx.r30.u64 = ctx.r30.u64 | 87;
	// b 0x821023f0
	goto loc_821023F0;
loc_82102214:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x821022b8
	if (ctx.cr6.eq) goto loc_821022B8;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x821022c0
	if (!ctx.cr6.eq) goto loc_821022C0;
loc_82102228:
	// addi r25,r31,228
	ctx.r25.s64 = ctx.r31.s64 + 228;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82108138
	ctx.lr = 0x82102240;
	sub_82108138(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x821023f0
	if (ctx.cr0.lt) goto loc_821023F0;
	// addi r26,r31,240
	ctx.r26.s64 = ctx.r31.s64 + 240;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82107c70
	ctx.lr = 0x82102260;
	sub_82107C70(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x821023f0
	if (ctx.cr0.lt) goto loc_821023F0;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r23,168(r31)
	REX_STORE_U8(ctx.r31.u32 + 168, ctx.r23.u8);
	// oris r7,r11,16384
	ctx.r7.u64 = ctx.r11.u64 | 1073741824;
	// stb r22,169(r31)
	REX_STORE_U8(ctx.r31.u32 + 169, ctx.r22.u8);
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// ori r7,r7,1024
	ctx.r7.u64 = ctx.r7.u64 | 1024;
	// subf r11,r8,r28
	ctx.r11.u64 = ctx.r28.u64 - ctx.r8.u64;
	// stw r7,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r7.u32);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r4,r11,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// bl 0x820fcaa8
	ctx.lr = 0x82102298;
	sub_820FCAA8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// rlwinm. r27,r29,0,29,30
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x6;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq 0x821022cc
	if (ctx.cr0.eq) goto loc_821022CC;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x821022cc
	if (!ctx.cr6.eq) goto loc_821022CC;
	// lis r30,-32747
	ctx.r30.s64 = -2146107392;
	// ori r30,r30,21001
	ctx.r30.u64 = ctx.r30.u64 | 21001;
	// b 0x821023f0
	goto loc_821023F0;
loc_821022B8:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82102228
	if (!ctx.cr6.eq) goto loc_82102228;
loc_821022C0:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,117
	ctx.r30.u64 = ctx.r30.u64 | 117;
	// b 0x821023f0
	goto loc_821023F0;
loc_821022CC:
	// rlwimi r7,r29,10,20,20
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 10) & 0x800) | (ctx.r7.u64 & 0xFFFFFFFFFFFFF7FF);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r7,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r7.u32);
	// rlwinm r8,r29,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x4;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821009f8
	ctx.lr = 0x821022F4;
	sub_821009F8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x821023f0
	if (ctx.cr0.lt) goto loc_821023F0;
	// mr r30,r21
	ctx.r30.u64 = ctx.r21.u64;
	// addi r28,r31,380
	ctx.r28.s64 = ctx.r31.s64 + 380;
loc_82102304:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82102330
	if (ctx.cr6.eq) goto loc_82102330;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82108800
	ctx.lr = 0x82102320;
	sub_82108800(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82107e78
	ctx.lr = 0x82102330;
	sub_82107E78(ctx, base);
loc_82102330:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x82102304
	if (ctx.cr6.lt) goto loc_82102304;
	// lwz r30,8(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82136f58
	ctx.lr = 0x82102348;
	sub_82136F58(ctx, base);
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// stw r11,44(r30)
	REX_STORE_U32(ctx.r30.u32 + 44, ctx.r11.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8210237c
	if (!ctx.cr6.eq) goto loc_8210237C;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x8210237c
	if (!ctx.cr6.eq) goto loc_8210237C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82101730
	ctx.lr = 0x82102378;
	sub_82101730(ctx, base);
	// b 0x8210240c
	goto loc_8210240C;
loc_8210237C:
	// lbz r9,169(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 169);
	// addi r30,r31,200
	ctx.r30.s64 = ctx.r31.s64 + 200;
	// lbz r11,168(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 168);
	// addi r10,r31,32
	ctx.r10.s64 = ctx.r31.s64 + 32;
	// stw r29,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r29.u32);
	// addi r8,r31,48
	ctx.r8.s64 = ctx.r31.s64 + 48;
	// addi r7,r31,40
	ctx.r7.s64 = ctx.r31.s64 + 40;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// stb r9,173(r31)
	REX_STORE_U8(ctx.r31.u32 + 173, ctx.r9.u8);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stb r11,172(r31)
	REX_STORE_U8(ctx.r31.u32 + 172, ctx.r11.u8);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// std r21,200(r31)
	REX_STORE_U64(ctx.r31.u32 + 200, ctx.r21.u64);
	// std r21,208(r31)
	REX_STORE_U64(ctx.r31.u32 + 208, ctx.r21.u64);
	// std r21,216(r31)
	REX_STORE_U64(ctx.r31.u32 + 216, ctx.r21.u64);
	// stw r21,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r21.u32);
	// lbz r6,169(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 169);
	// lbz r5,168(r31)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r31.u32 + 168);
	// bl 0x82138678
	ctx.lr = 0x821023C8;
	sub_82138678(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82102400
	if (ctx.cr0.eq) goto loc_82102400;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x82102400
	if (ctx.cr6.eq) goto loc_82102400;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82136e38
	ctx.lr = 0x821023E0;
	sub_82136E38(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x821023f0
	if (ctx.cr0.lt) goto loc_821023F0;
	// lis r30,-32768
	ctx.r30.s64 = -2147483648;
	// ori r30,r30,16389
	ctx.r30.u64 = ctx.r30.u64 | 16389;
loc_821023F0:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82100fd8
	ctx.lr = 0x821023FC;
	sub_82100FD8(ctx, base);
	// b 0x82102410
	goto loc_82102410;
loc_82102400:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,5936
	ctx.r11.s64 = ctx.r11.s64 + 5936;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
loc_8210240C:
	// mr r30,r21
	ctx.r30.u64 = ctx.r21.u64;
loc_82102410:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
}
