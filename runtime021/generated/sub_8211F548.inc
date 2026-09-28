DEFINE_REX_FUNC(sub_8211F548) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x8211F550;
	__savegprlr_22(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r23,0
	ctx.r23.s64 = 0;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// lhz r11,834(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 834);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mulli r11,r11,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// stwx r23,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r23.u32);
	// lhz r11,834(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 834);
	// mulli r11,r11,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r30,r11,52
	ctx.r30.s64 = ctx.r11.s64 + 52;
	// mr r27,r23
	ctx.r27.u64 = ctx.r23.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stb r23,68(r11)
	REX_STORE_U8(ctx.r11.u32 + 68, ctx.r23.u8);
	// lhz r10,834(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 834);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// mulli r11,r11,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stb r10,69(r11)
	REX_STORE_U8(ctx.r11.u32 + 69, ctx.r10.u8);
	// lhz r10,836(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 836);
	// lhz r11,834(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 834);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r11,834(r31)
	REX_STORE_U16(ctx.r31.u32 + 834, ctx.r11.u16);
	// sth r10,836(r31)
	REX_STORE_U16(ctx.r31.u32 + 836, ctx.r10.u16);
	// lwz r6,96(r25)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r25.u32 + 96);
	// bl 0x82125c10
	ctx.lr = 0x8211F5D8;
	sub_82125C10(ctx, base);
	// lbz r11,13(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 13);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8211f624
	if (ctx.cr0.eq) goto loc_8211F624;
	// addi r22,r1,96
	ctx.r22.s64 = ctx.r1.s64 + 96;
loc_8211F5EC:
	// lhz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 8);
	// add r9,r10,r26
	ctx.r9.u64 = ctx.r10.u64 + ctx.r26.u64;
	// cmplw cr6,r9,r29
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r29.u32, ctx.xer);
	// bgt cr6,0x8211f624
	if (ctx.cr6.gt) goto loc_8211F624;
	// clrlwi r24,r10,16
	ctx.r24.u64 = ctx.r10.u32 & 0xFFFF;
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// beq cr6,0x8211f6d4
	if (ctx.cr6.eq) goto loc_8211F6D4;
	// lbz r10,12(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 12);
	// rlwinm. r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8211f624
	if (ctx.cr0.eq) goto loc_8211F624;
	// rlwinm. r10,r10,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq 0x8211f630
	if (ctx.cr0.eq) goto loc_8211F630;
	// bne cr6,0x8211f634
	if (!ctx.cr6.eq) goto loc_8211F634;
loc_8211F624:
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
loc_8211F628:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8211F630:
	// bne cr6,0x8211f624
	if (!ctx.cr6.eq) goto loc_8211F624;
loc_8211F634:
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// beq cr6,0x8211f6b0
	if (ctx.cr6.eq) goto loc_8211F6B0;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8211f674
	if (ctx.cr6.eq) goto loc_8211F674;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82125e38
	ctx.lr = 0x8211F654;
	sub_82125E38(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8211f624
	if (ctx.cr0.eq) goto loc_8211F624;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r10,100(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 100);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x8211f624
	if (ctx.cr6.gt) goto loc_8211F624;
	// b 0x8211f6d4
	goto loc_8211F6D4;
loc_8211F674:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82125e08
	ctx.lr = 0x8211F67C;
	sub_82125E08(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8211f624
	if (ctx.cr0.eq) goto loc_8211F624;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r24,-6
	ctx.r10.s64 = ctx.r24.s64 + -6;
	// lwz r11,2(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 2);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8211f624
	if (!ctx.cr6.eq) goto loc_8211F624;
	// addi r3,r25,572
	ctx.r3.s64 = ctx.r25.s64 + 572;
	// lwz r4,4(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x821221b0
	ctx.lr = 0x8211F6A4;
	sub_821221B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8211f624
	if (!ctx.cr0.eq) goto loc_8211F624;
	// b 0x8211f6d4
	goto loc_8211F6D4;
loc_8211F6B0:
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x82125de8
	ctx.lr = 0x8211F6B8;
	sub_82125DE8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8211f624
	if (ctx.cr0.eq) goto loc_8211F624;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r10,r24,-9
	ctx.r10.s64 = ctx.r24.s64 + -9;
	// lwz r11,5(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 5);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8211f624
	if (!ctx.cr6.eq) goto loc_8211F624;
loc_8211F6D4:
	// subf r10,r24,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r24.u64;
	// stw r30,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r30.u32);
	// add r11,r24,r26
	ctx.r11.u64 = ctx.r24.u64 + ctx.r26.u64;
	// subf. r29,r26,r10
	ctx.r29.u64 = ctx.r10.u64 - ctx.r26.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// add r28,r11,r28
	ctx.r28.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r22,r22,4
	ctx.r22.s64 = ctx.r22.s64 + 4;
	// beq 0x8211f77c
	if (ctx.cr0.eq) goto loc_8211F77C;
	// cmplwi cr6,r27,32
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 32, ctx.xer);
	// bge cr6,0x8211f624
	if (!ctx.cr6.lt) goto loc_8211F624;
	// lhz r11,834(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 834);
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mulli r11,r11,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// stwx r23,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r23.u32);
	// lhz r11,834(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 834);
	// mulli r11,r11,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r30,r11,52
	ctx.r30.s64 = ctx.r11.s64 + 52;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stb r23,68(r11)
	REX_STORE_U8(ctx.r11.u32 + 68, ctx.r23.u8);
	// lhz r10,834(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 834);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// mulli r11,r11,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stb r10,69(r11)
	REX_STORE_U8(ctx.r11.u32 + 69, ctx.r10.u8);
	// lhz r11,834(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 834);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,834(r31)
	REX_STORE_U16(ctx.r31.u32 + 834, ctx.r11.u16);
	// lhz r11,836(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 836);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,836(r31)
	REX_STORE_U16(ctx.r31.u32 + 836, ctx.r11.u16);
	// lwz r6,96(r25)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r25.u32 + 96);
	// bl 0x82125c10
	ctx.lr = 0x8211F768;
	sub_82125C10(ctx, base);
	// lbz r11,13(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 13);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8211f5ec
	if (!ctx.cr0.eq) goto loc_8211F5EC;
	// b 0x8211f624
	goto loc_8211F624;
loc_8211F77C:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8211a318
	ctx.lr = 0x8211F788;
	sub_8211A318(ctx, base);
	// mr r28,r23
	ctx.r28.u64 = ctx.r23.u64;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8211f838
	if (ctx.cr6.eq) goto loc_8211F838;
	// addi r29,r25,572
	ctx.r29.s64 = ctx.r25.s64 + 572;
	// addi r30,r31,52
	ctx.r30.s64 = ctx.r31.s64 + 52;
loc_8211F79C:
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8211f7c8
	if (!ctx.cr6.lt) goto loc_8211F7C8;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r10
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,127
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 127, ctx.xer);
	// ble cr6,0x8211f7c8
	if (!ctx.cr6.gt) goto loc_8211F7C8;
	// rotlwi r3,r9,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// b 0x8211f7cc
	goto loc_8211F7CC;
loc_8211F7C8:
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
loc_8211F7CC:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// addi r5,r30,-4
	ctx.r5.s64 = ctx.r30.s64 + -4;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bne cr6,0x8211f7ec
	if (!ctx.cr6.eq) goto loc_8211F7EC;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8211e990
	ctx.lr = 0x8211F7E8;
	sub_8211E990(ctx, base);
	// b 0x8211f7f0
	goto loc_8211F7F0;
loc_8211F7EC:
	// bl 0x82124ce0
	ctx.lr = 0x8211F7F0;
	sub_82124CE0(ctx, base);
loc_8211F7F0:
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x8211f7fc
	if (!ctx.cr0.lt) goto loc_8211F7FC;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
loc_8211F7FC:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r30,r30,24
	ctx.r30.s64 = ctx.r30.s64 + 24;
	// bne 0x8211f79c
	if (!ctx.cr0.eq) goto loc_8211F79C;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bge cr6,0x8211f838
	if (!ctx.cr6.lt) goto loc_8211F838;
	// lwz r11,20(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 20);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x8211f838
	if (ctx.cr6.eq) goto loc_8211F838;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r28,24(r25)
	REX_STORE_U32(ctx.r25.u32 + 24, ctx.r28.u32);
	// stb r23,1145(r25)
	REX_STORE_U8(ctx.r25.u32 + 1145, ctx.r23.u8);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stw r11,20(r25)
	REX_STORE_U32(ctx.r25.u32 + 20, ctx.r11.u32);
	// stb r23,1144(r25)
	REX_STORE_U8(ctx.r25.u32 + 1144, ctx.r23.u8);
	// bl 0x8211a3b8
	ctx.lr = 0x8211F838;
	sub_8211A3B8(ctx, base);
loc_8211F838:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8211f628
	goto loc_8211F628;
}
