DEFINE_REX_FUNC(sub_8209A3A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x8209A3A8;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lis r10,4095
	ctx.r10.s64 = 268369920;
	// addi r29,r11,-22032
	ctx.r29.s64 = ctx.r11.s64 + -22032;
	// ori r31,r10,65535
	ctx.r31.u64 = ctx.r10.u64 | 65535;
	// li r24,1
	ctx.r24.s64 = 1;
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// subf r9,r11,r31
	ctx.r9.u64 = ctx.r31.u64 - ctx.r11.u64;
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bge cr6,0x8209a3d8
	if (!ctx.cr6.lt) goto loc_8209A3D8;
	// bl 0x82078668
	ctx.lr = 0x8209A3D4;
	sub_82078668(ctx, base);
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
loc_8209A3D8:
	// rlwinm r10,r11,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// bge cr6,0x8209a3ec
	if (!ctx.cr6.lt) goto loc_8209A3EC;
	// li r10,8
	ctx.r10.s64 = 8;
	// b 0x8209a3f4
	goto loc_8209A3F4;
loc_8209A3EC:
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// ble cr6,0x8209a404
	if (!ctx.cr6.gt) goto loc_8209A404;
loc_8209A3F4:
	// subf r9,r10,r31
	ctx.r9.u64 = ctx.r31.u64 - ctx.r10.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x8209a404
	if (ctx.cr6.gt) goto loc_8209A404;
	// mr r24,r10
	ctx.r24.u64 = ctx.r10.u64;
loc_8209A404:
	// lwz r10,12(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// add. r31,r11,r24
	ctx.r31.u64 = ctx.r11.u64 + ctx.r24.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// rlwinm r27,r10,30,2,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// bne 0x8209a41c
	if (!ctx.cr0.eq) goto loc_8209A41C;
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x8209a458
	goto loc_8209A458;
loc_8209A41C:
	// li r11,-1
	ctx.r11.s64 = -1;
	// twllei r31,0
	if (ctx.r31.s32 == 0 || ctx.r31.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r10,r11,r31
	ctx.r10.u64 = uint32_t(ctx.r31.u32 ? ctx.r11.u32 / ctx.r31.u32 : 0);
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bge cr6,0x8209a458
	if (!ctx.cr6.lt) goto loc_8209A458;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,9400
	ctx.r9.s64 = ctx.r11.s64 + 9400;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x820516f8
	ctx.lr = 0x8209A44C;
	sub_820516F8(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// addi r7,r8,9388
	ctx.r7.s64 = ctx.r8.s64 + 9388;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
loc_8209A458:
	// lis r23,-32215
	ctx.r23.s64 = -2111242240;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r22,r11,-1768
	ctx.r22.s64 = ctx.r11.s64 + -1768;
	// lbz r11,-22601(r23)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r23.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209a484
	if (!ctx.cr6.eq) goto loc_8209A484;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209A484;
	sub_820A71E8(ctx, base);
loc_8209A484:
	// bl 0x820b5eb8
	ctx.lr = 0x8209A488;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r25,r11,29632
	ctx.r25.s64 = ctx.r11.s64 + 29632;
	// rlwinm r4,r31,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8209A4A0;
	sub_8209BDD8(ctx, base);
	// lwz r31,4(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// rlwinm r30,r27,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,8(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// add r5,r30,r31
	ctx.r5.u64 = ctx.r30.u64 + ctx.r31.u64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r30,r26
	ctx.r3.u64 = ctx.r30.u64 + ctx.r26.u64;
	// subf r11,r5,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r5.u64;
	// add r7,r11,r31
	ctx.r7.u64 = ctx.r11.u64 + ctx.r31.u64;
	// srawi. r11,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r7.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r28,r6,r3
	ctx.r28.u64 = ctx.r6.u64 + ctx.r3.u64;
	// beq 0x8209a4e0
	if (ctx.cr0.eq) goto loc_8209A4E0;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x82127588
	ctx.lr = 0x8209A4DC;
	sub_82127588(ctx, base);
	// lwz r31,4(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
loc_8209A4E0:
	// cmplw cr6,r27,r24
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r24.u32, ctx.xer);
	// bgt cr6,0x8209a55c
	if (ctx.cr6.gt) goto loc_8209A55C;
	// srawi. r11,r30,2
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r30.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r6,r28
	ctx.r30.u64 = ctx.r6.u64 + ctx.r28.u64;
	// beq 0x8209a50c
	if (ctx.cr0.eq) goto loc_8209A50C;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82127588
	ctx.lr = 0x8209A508;
	sub_82127588(ctx, base);
	// lwz r31,4(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
loc_8209A50C:
	// subf. r10,r27,r24
	ctx.r10.u64 = ctx.r24.u64 - ctx.r27.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8209a538
	if (ctx.cr0.eq) goto loc_8209A538;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8209a538
	if (ctx.cr6.eq) goto loc_8209A538;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8209A528:
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x8209a528
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8209A528;
	// lwz r31,4(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
loc_8209A538:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8209a5d0
	if (ctx.cr6.eq) goto loc_8209A5D0;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
loc_8209A54C:
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x8209a54c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8209A54C;
	// b 0x8209a5cc
	goto loc_8209A5CC;
loc_8209A55C:
	// rlwinm r27,r24,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi. r11,r27,2
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r27.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8209a580
	if (ctx.cr0.eq) goto loc_8209A580;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82127588
	ctx.lr = 0x8209A57C;
	sub_82127588(ctx, base);
	// lwz r31,4(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
loc_8209A580:
	// add r5,r27,r31
	ctx.r5.u64 = ctx.r27.u64 + ctx.r31.u64;
	// subf r11,r5,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r5.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r6,r26
	ctx.r30.u64 = ctx.r6.u64 + ctx.r26.u64;
	// beq 0x8209a5ac
	if (ctx.cr0.eq) goto loc_8209A5AC;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82127588
	ctx.lr = 0x8209A5A8;
	sub_82127588(ctx, base);
	// lwz r31,4(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
loc_8209A5AC:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x8209a5d0
	if (ctx.cr6.eq) goto loc_8209A5D0;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mtctr r24
	ctx.ctr.u64 = ctx.r24.u64;
loc_8209A5C0:
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x8209a5c0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8209A5C0;
loc_8209A5CC:
	// lwz r31,4(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
loc_8209A5D0:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8209a60c
	if (ctx.cr6.eq) goto loc_8209A60C;
	// lbz r11,-22601(r23)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r23.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209a5f8
	if (!ctx.cr6.eq) goto loc_8209A5F8;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209A5F8;
	sub_820A71E8(ctx, base);
loc_8209A5F8:
	// bl 0x820b5eb8
	ctx.lr = 0x8209A5FC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8209A60C;
	sub_8209BF18(ctx, base);
loc_8209A60C:
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// stw r26,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r26.u32);
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// stw r11,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
