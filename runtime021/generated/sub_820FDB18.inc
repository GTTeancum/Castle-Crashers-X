DEFINE_REX_FUNC(sub_820FDB18) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f8
	ctx.lr = 0x820FDB20;
	__savegprlr_20(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r20,r7
	ctx.r20.u64 = ctx.r7.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// clrlwi. r11,r6,31
	ctx.r11.u64 = ctx.r6.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r25,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r25.u32);
	// lis r21,4096
	ctx.r21.s64 = 268435456;
	// beq 0x820fdb50
	if (ctx.cr0.eq) goto loc_820FDB50;
	// addi r23,r1,96
	ctx.r23.s64 = ctx.r1.s64 + 96;
	// b 0x820fdb58
	goto loc_820FDB58;
loc_820FDB50:
	// addi r23,r1,100
	ctx.r23.s64 = ctx.r1.s64 + 100;
	// ori r21,r21,1
	ctx.r21.u64 = ctx.r21.u64 | 1;
loc_820FDB58:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x820fdbd4
	if (!ctx.cr6.eq) goto loc_820FDBD4;
	// lwz r11,248(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 248);
	// addi r31,r28,248
	ctx.r31.s64 = ctx.r28.s64 + 248;
	// ori r29,r6,4
	ctx.r29.u64 = ctx.r6.u64 | 4;
	// b 0x820fdbbc
	goto loc_820FDBBC;
loc_820FDB70:
	// lwz r11,304(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 304);
	// addi r5,r30,-92
	ctx.r5.s64 = ctx.r30.s64 + -92;
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820fdbb8
	if (!ctx.cr0.eq) goto loc_820FDBB8;
	// lwz r11,84(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820fdbb8
	if (!ctx.cr6.eq) goto loc_820FDBB8;
	// mr r7,r23
	ctx.r7.u64 = ctx.r23.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820fdb18
	ctx.lr = 0x820FDBA0;
	sub_820FDB18(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820fddc0
	if (ctx.cr0.lt) goto loc_820FDDC0;
	// lwz r11,0(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// lwz r10,0(r23)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r11.u32);
loc_820FDBB8:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_820FDBBC:
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x820fddbc
	if (ctx.cr6.eq) goto loc_820FDDBC;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// bne 0x820fdb70
	if (!ctx.cr0.eq) goto loc_820FDB70;
	// b 0x820fddbc
	goto loc_820FDDBC;
loc_820FDBD4:
	// rlwinm. r11,r6,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// beq 0x820fdc08
	if (ctx.cr0.eq) goto loc_820FDC08;
	// lwz r11,380(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 380);
	// addi r8,r28,380
	ctx.r8.s64 = ctx.r28.s64 + 380;
	// lwz r9,384(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 384);
	// lwz r8,388(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 388);
	// lwz r7,392(r28)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r28.u32 + 392);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stw r8,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// stw r7,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// b 0x820fdc20
	goto loc_820FDC20;
loc_820FDC08:
	// lwz r11,24(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// std r25,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.r25.u64);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// std r25,8(r10)
	REX_STORE_U64(ctx.r10.u32 + 8, ctx.r25.u64);
	// stwx r27,r11,r9
	REX_STORE_U32(ctx.r11.u32 + ctx.r9.u32, ctx.r27.u32);
loc_820FDC20:
	// rlwinm. r11,r6,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820fdc54
	if (!ctx.cr0.eq) goto loc_820FDC54;
	// lwz r11,84(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820fdc40
	if (!ctx.cr6.eq) goto loc_820FDC40;
	// lwz r11,88(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fdc54
	if (ctx.cr6.eq) goto loc_820FDC54;
loc_820FDC40:
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// li r10,1
	ctx.r10.s64 = 1;
	// slw r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// oris r27,r11,32768
	ctx.r27.u64 = ctx.r11.u64 | 2147483648;
	// b 0x820fdc58
	goto loc_820FDC58;
loc_820FDC54:
	// mr r27,r25
	ctx.r27.u64 = ctx.r25.u64;
loc_820FDC58:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lis r10,-32646
	ctx.r10.s64 = -2139488256;
	// mr r26,r25
	ctx.r26.u64 = ctx.r25.u64;
	// addi r22,r1,128
	ctx.r22.s64 = ctx.r1.s64 + 128;
	// ori r29,r11,16
	ctx.r29.u64 = ctx.r11.u64 | 16;
	// ori r24,r10,4097
	ctx.r24.u64 = ctx.r10.u64 | 4097;
loc_820FDC70:
	// lwz r11,0(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fddac
	if (ctx.cr6.eq) goto loc_820FDDAC;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lwz r4,100(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// lwz r3,400(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 400);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// ori r11,r11,65534
	ctx.r11.u64 = ctx.r11.u64 | 65534;
	// subf r11,r26,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r26.u64;
	// oris r5,r11,65532
	ctx.r5.u64 = ctx.r11.u64 | 4294705152;
	// oris r31,r11,65016
	ctx.r31.u64 = ctx.r11.u64 | 4260888576;
	// bne cr6,0x820fdcfc
	if (!ctx.cr6.eq) goto loc_820FDCFC;
	// li r8,4
	ctx.r8.s64 = 4;
	// mr r7,r23
	ctx.r7.u64 = ctx.r23.u64;
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// bl 0x82108ea0
	ctx.lr = 0x820FDCB0;
	sub_82108EA0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820fddc0
	if (ctx.cr0.lt) goto loc_820FDDC0;
	// lwz r11,720(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 720);
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820fdd9c
	if (ctx.cr0.eq) goto loc_820FDD9C;
	// li r8,4
	ctx.r8.s64 = 4;
	// lwz r4,100(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lwz r3,400(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 400);
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x82108ea0
	ctx.lr = 0x820FDCE0;
	sub_82108EA0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820fddc0
	if (ctx.cr0.lt) goto loc_820FDDC0;
	// lwz r10,0(r23)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r11.u32);
	// b 0x820fdd9c
	goto loc_820FDD9C;
loc_820FDCFC:
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// stw r25,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r25.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stw r25,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r25.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// bl 0x82108f20
	ctx.lr = 0x820FDD20;
	sub_82108F20(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x820fdd30
	if (!ctx.cr0.lt) goto loc_820FDD30;
	// cmpw cr6,r3,r24
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r24.s32, ctx.xer);
	// bne cr6,0x820fddc0
	if (!ctx.cr6.eq) goto loc_820FDDC0;
loc_820FDD30:
	// lwz r11,720(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 720);
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820fdd9c
	if (ctx.cr0.eq) goto loc_820FDD9C;
	// addi r10,r1,108
	ctx.r10.s64 = ctx.r1.s64 + 108;
	// lwz r4,100(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// addi r9,r1,104
	ctx.r9.s64 = ctx.r1.s64 + 104;
	// lwz r3,400(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 400);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r25,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r25.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r25,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r25.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x82108f20
	ctx.lr = 0x820FDD6C;
	sub_82108F20(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x820fdd7c
	if (!ctx.cr0.lt) goto loc_820FDD7C;
	// cmpw cr6,r3,r24
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r24.s32, ctx.xer);
	// bne cr6,0x820fddc0
	if (!ctx.cr6.eq) goto loc_820FDDC0;
loc_820FDD7C:
	// lwz r9,96(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r8,100(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
loc_820FDD9C:
	// lwz r11,0(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// lwz r10,0(r23)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r11.u32);
loc_820FDDAC:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r22,r22,4
	ctx.r22.s64 = ctx.r22.s64 + 4;
	// cmplwi cr6,r26,4
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 4, ctx.xer);
	// blt cr6,0x820fdc70
	if (ctx.cr6.lt) goto loc_820FDC70;
loc_820FDDBC:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
loc_820FDDC0:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
}
