DEFINE_REX_FUNC(sub_8213C438) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x8213C440;
	__savegprlr_23(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// bl 0x8213bc30
	ctx.lr = 0x8213C44C;
	sub_8213BC30(ctx, base);
	// addi r24,r25,76
	ctx.r24.s64 = ctx.r25.s64 + 76;
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r31,76(r25)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r25.u32 + 76);
	// b 0x8213c500
	goto loc_8213C500;
loc_8213C45C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r11,259
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 259, ctx.xer);
	// beq cr6,0x8213c508
	if (ctx.cr6.eq) goto loc_8213C508;
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8213c494
	if (ctx.cr6.eq) goto loc_8213C494;
	// lwz r10,4(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8213c488
	if (!ctx.cr6.eq) goto loc_8213C488;
	// stw r26,4(r24)
	REX_STORE_U32(ctx.r24.u32 + 4, ctx.r26.u32);
loc_8213C488:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r10.u32);
	// stw r26,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r26.u32);
loc_8213C494:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8213c4b8
	if (!ctx.cr6.eq) goto loc_8213C4B8;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r26,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r26.u32);
loc_8213C4B8:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r30,r25,68
	ctx.r30.s64 = ctx.r25.s64 + 68;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r26,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r26.u32);
	// bl 0x8214a754
	ctx.lr = 0x8213C4CC;
	__imp__KfAcquireSpinLock(ctx, base);
	// stw r26,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r26.u32);
	// lwz r10,56(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 56);
	// addi r11,r25,52
	ctx.r11.s64 = ctx.r25.s64 + 52;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8213c4ec
	if (ctx.cr6.eq) goto loc_8213C4EC;
	// stw r31,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r31.u32);
	// b 0x8213c4f0
	goto loc_8213C4F0;
loc_8213C4EC:
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
loc_8213C4F0:
	// stw r31,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a744
	ctx.lr = 0x8213C4FC;
	__imp__KfReleaseSpinLock(ctx, base);
	// lwz r31,0(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
loc_8213C500:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8213c45c
	if (!ctx.cr6.eq) goto loc_8213C45C;
loc_8213C508:
	// lwz r27,60(r25)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r25.u32 + 60);
	// addi r23,r25,60
	ctx.r23.s64 = ctx.r25.s64 + 60;
	// b 0x8213c6c8
	goto loc_8213C6C8;
loc_8213C514:
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// subf. r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8213c6ec
	if (!ctx.cr0.eq) goto loc_8213C6EC;
	// addi r31,r25,68
	ctx.r31.s64 = ctx.r25.s64 + 68;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214a754
	ctx.lr = 0x8213C534;
	__imp__KfAcquireSpinLock(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x8213ec70
	ctx.lr = 0x8213C540;
	sub_8213EC70(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8213c558
	if (!ctx.cr0.eq) goto loc_8213C558;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8213ec70
	ctx.lr = 0x8213C550;
	sub_8213EC70(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// ble cr6,0x8213c6d4
	if (!ctx.cr6.gt) goto loc_8213C6D4;
loc_8213C558:
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8213c580
	if (ctx.cr6.eq) goto loc_8213C580;
	// lwz r10,4(r23)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r23.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8213c574
	if (!ctx.cr6.eq) goto loc_8213C574;
	// stw r26,4(r23)
	REX_STORE_U32(ctx.r23.u32 + 4, ctx.r26.u32);
loc_8213C574:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r10.u32);
	// stw r26,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r26.u32);
loc_8213C580:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214a744
	ctx.lr = 0x8213C58C;
	__imp__KfReleaseSpinLock(ctx, base);
	// stw r26,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r26.u32);
	// lwz r11,4(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8213c5a4
	if (ctx.cr6.eq) goto loc_8213C5A4;
	// stw r27,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r27.u32);
	// b 0x8213c5a8
	goto loc_8213C5A8;
loc_8213C5A4:
	// stw r27,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r27.u32);
loc_8213C5A8:
	// stw r27,4(r24)
	REX_STORE_U32(ctx.r24.u32 + 4, ctx.r27.u32);
	// addi r28,r25,84
	ctx.r28.s64 = ctx.r25.s64 + 84;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r31,8(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// rlwinm. r11,r10,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x8213c690
	if (!ctx.cr0.gt) goto loc_8213C690;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
loc_8213C5D4:
	// lha r10,0(r31)
	ctx.r10.s64 = int16_t(REX_LOAD_U16(ctx.r31.u32 + 0));
	// li r12,-7880
	ctx.r12.s64 = -7880;
	// addi r11,r10,-7880
	ctx.r11.s64 = ctx.r10.s64 + -7880;
	// sth r26,82(r1)
	REX_STORE_U16(ctx.r1.u32 + 82, ctx.r26.u16);
	// sth r26,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r26.u16);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// srawi r11,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 16;
	// addi r5,r1,82
	ctx.r5.s64 = ctx.r1.s64 + 82;
	// not r9,r11
	ctx.r9.u64 = ~ctx.r11.u64;
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	// andi. r10,r9,7880
	ctx.r10.u64 = ctx.r9.u64 & 7880;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// or r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 | ctx.r11.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r11,r10,7880
	ctx.r11.s64 = ctx.r10.s64 + 7880;
	// srawi r11,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 16;
	// and r9,r11,r12
	ctx.r9.u64 = ctx.r11.u64 & ctx.r12.u64;
	// andc r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ~ctx.r11.u64;
	// or r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 | ctx.r9.u64;
	// extsh r4,r11
	ctx.r4.s64 = ctx.r11.s16;
	// bl 0x8213fdc8
	ctx.lr = 0x8213C624;
	sub_8213FDC8(ctx, base);
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
	// li r12,-7880
	ctx.r12.s64 = -7880;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r3,0
	ctx.r3.s64 = 0;
	// lha r10,0(r31)
	ctx.r10.s64 = int16_t(REX_LOAD_U16(ctx.r31.u32 + 0));
	// addi r11,r10,-7880
	ctx.r11.s64 = ctx.r10.s64 + -7880;
	// srawi r11,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 16;
	// not r9,r11
	ctx.r9.u64 = ~ctx.r11.u64;
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	// andi. r10,r9,7880
	ctx.r10.u64 = ctx.r9.u64 & 7880;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// or r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 | ctx.r10.u64;
	// addi r11,r10,7880
	ctx.r11.s64 = ctx.r10.s64 + 7880;
	// srawi r11,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 16;
	// and r9,r11,r12
	ctx.r9.u64 = ctx.r11.u64 & ctx.r12.u64;
	// andc r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ~ctx.r11.u64;
	// or r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 | ctx.r9.u64;
	// extsh r4,r11
	ctx.r4.s64 = ctx.r11.s16;
	// bl 0x8213fdc8
	ctx.lr = 0x8213C670;
	sub_8213FDC8(ctx, base);
	// lha r11,80(r1)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r1.u32 + 80));
	// lhz r10,82(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 82);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
	// rlwimi r10,r11,4,0,27
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0) | (ctx.r10.u64 & 0xFFFFFFFF0000000F);
	// stb r10,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r10.u8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// bne 0x8213c5d4
	if (!ctx.cr0.eq) goto loc_8213C5D4;
loc_8213C690:
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm r9,r9,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r9,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// stw r10,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r5,0(r27)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r3,8(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// bl 0x8214adb4
	ctx.lr = 0x8213C6BC;
	__imp__XamVoiceSubmitPacket(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8213c6e4
	if (ctx.cr0.lt) goto loc_8213C6E4;
	// lwz r27,0(r23)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
loc_8213C6C8:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x8213c514
	if (!ctx.cr6.eq) goto loc_8213C514;
	// b 0x8213c6ec
	goto loc_8213C6EC;
loc_8213C6D4:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r25,68
	ctx.r3.s64 = ctx.r25.s64 + 68;
	// bl 0x8214a744
	ctx.lr = 0x8213C6E0;
	__imp__KfReleaseSpinLock(ctx, base);
	// b 0x8213c6ec
	goto loc_8213C6EC;
loc_8213C6E4:
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// stw r26,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r26.u32);
loc_8213C6EC:
	// lwz r3,4(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// bl 0x82141508
	ctx.lr = 0x8213C6F4;
	sub_82141508(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt 0x8213c738
	if (ctx.cr0.lt) goto loc_8213C738;
	// lwz r11,32(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 32);
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8213c738
	if (!ctx.cr6.gt) goto loc_8213C738;
	// addi r31,r25,12
	ctx.r31.s64 = ctx.r25.s64 + 12;
loc_8213C710:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8213C724;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,32(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8213c710
	if (ctx.cr6.lt) goto loc_8213C710;
loc_8213C738:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
