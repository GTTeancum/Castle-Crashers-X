DEFINE_REX_FUNC(sub_8211D5B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298ec
	ctx.lr = 0x8211D5B8;
	__savegprlr_17(ctx, base);
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r22,0
	ctx.r22.s64 = 0;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// lhz r11,1042(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1042);
	// stw r3,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8211d9f4
	if (ctx.cr0.eq) goto loc_8211D9F4;
	// lhz r10,1032(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 1032);
	// lhz r9,1050(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 1050);
	// lhz r7,1046(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 1046);
	// subf r11,r9,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r9.u64;
	// lhz r6,1056(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 1056);
	// subf r10,r7,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r7.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// extsh r30,r10
	ctx.r30.s64 = ctx.r10.s16;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// bgt cr6,0x8211d9f4
	if (ctx.cr6.gt) goto loc_8211D9F4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82121370
	ctx.lr = 0x8211D610;
	sub_82121370(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8211d9f0
	if (ctx.cr0.lt) goto loc_8211D9F0;
	// addi r21,r31,942
	ctx.r21.s64 = ctx.r31.s64 + 942;
	// lhz r3,1032(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 1032);
	// addi r19,r31,872
	ctx.r19.s64 = ctx.r31.s64 + 872;
	// mr r5,r21
	ctx.r5.u64 = ctx.r21.u64;
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// bl 0x8211b8f8
	ctx.lr = 0x8211D630;
	sub_8211B8F8(ctx, base);
	// subfic r25,r3,1264
	ctx.xer.ca = ctx.r3.u32 <= 1264;
	ctx.r25.u64 = static_cast<uint64_t>(1264) - ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211a158
	ctx.lr = 0x8211D63C;
	sub_8211A158(ctx, base);
	// mr r18,r3
	ctx.r18.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// bl 0x8211a1e0
	ctx.lr = 0x8211D64C;
	sub_8211A1E0(ctx, base);
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// mr r17,r3
	ctx.r17.u64 = ctx.r3.u64;
	// stw r22,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r22.u32);
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// cmpwi cr6,r30,254
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 254, ctx.xer);
	// bge cr6,0x8211d698
	if (!ctx.cr6.lt) goto loc_8211D698;
	// lhz r10,1042(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 1042);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8211d698
	if (ctx.cr0.eq) goto loc_8211D698;
	// lhz r10,1056(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 1056);
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8211d698
	if (!ctx.cr6.lt) goto loc_8211D698;
	// lwz r10,1148(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1148);
	// rlwinm. r10,r10,0,6,6
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8211d6a0
	if (ctx.cr0.eq) goto loc_8211D6A0;
	// lhz r10,1040(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 1040);
	// clrlwi r9,r17,16
	ctx.r9.u64 = ctx.r17.u32 & 0xFFFF;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8211d6a0
	if (!ctx.cr6.lt) goto loc_8211D6A0;
loc_8211D698:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
loc_8211D6A0:
	// lhz r10,128(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 128);
	// subfic r10,r10,256
	ctx.xer.ca = ctx.r10.u32 <= 256;
	ctx.r10.u64 = static_cast<uint64_t>(256) - ctx.r10.u64;
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8211d6dc
	if (!ctx.cr6.lt) goto loc_8211D6DC;
	// lhz r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 124);
	// lhz r9,1042(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 1042);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8211d6dc
	if (!ctx.cr6.gt) goto loc_8211D6DC;
	// lhz r10,1056(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 1056);
	// lhz r9,126(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 126);
	// subf r10,r29,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r29.u64;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x8211d6dc
	if (!ctx.cr6.gt) goto loc_8211D6DC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8211d6e4
	if (ctx.cr6.eq) goto loc_8211D6E4;
loc_8211D6DC:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
loc_8211D6E4:
	// lhz r11,980(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 980);
	// rlwinm. r11,r11,0,0,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF8000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8211d6f8
	if (ctx.cr0.eq) goto loc_8211D6F8;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
loc_8211D6F8:
	// stw r22,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r22.u32);
	// li r30,1
	ctx.r30.s64 = 1;
	// bl 0x82136f58
	ctx.lr = 0x8211D704;
	sub_82136F58(ctx, base);
	// lwz r11,540(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 540);
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
	// li r23,32
	ctx.r23.s64 = 32;
	// mr r28,r22
	ctx.r28.u64 = ctx.r22.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8211d7d8
	if (ctx.cr6.eq) goto loc_8211D7D8;
	// li r24,248
	ctx.r24.s64 = 248;
loc_8211D724:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x8211d7d0
	if (ctx.cr6.eq) goto loc_8211D7D0;
	// cmplwi cr6,r29,32
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 32, ctx.xer);
	// bge cr6,0x8211d7d0
	if (!ctx.cr6.lt) goto loc_8211D7D0;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x8211d7d0
	if (ctx.cr6.eq) goto loc_8211D7D0;
	// lwz r11,536(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 536);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r26,r11,-32
	ctx.r26.s64 = ctx.r11.s64 + -32;
	// lwz r11,-20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8211d760
	if (ctx.cr6.eq) goto loc_8211D760;
	// mr r27,r24
	ctx.r27.u64 = ctx.r24.u64;
	// addi r7,r23,-32
	ctx.r7.s64 = ctx.r23.s64 + -32;
	// b 0x8211d768
	goto loc_8211D768;
loc_8211D760:
	// rlwinm r27,r28,3,0,28
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
loc_8211D768:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// add r30,r27,r11
	ctx.r30.u64 = ctx.r27.u64 + ctx.r11.u64;
	// mr r5,r20
	ctx.r5.u64 = ctx.r20.u64;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82122ac0
	ctx.lr = 0x8211D788;
	sub_82122AC0(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8211d7c4
	if (ctx.cr6.eq) goto loc_8211D7C4;
	// addi r11,r1,116
	ctx.r11.s64 = ctx.r1.s64 + 116;
	// lwz r10,12(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 12);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lhzx r11,r27,r11
	ctx.r11.u64 = REX_LOAD_U16(ctx.r27.u32 + ctx.r11.u32);
	// subf r25,r11,r25
	ctx.r25.u64 = ctx.r25.u64 - ctx.r11.u64;
	// beq cr6,0x8211d7c0
	if (ctx.cr6.eq) goto loc_8211D7C0;
	// addi r23,r23,-1
	ctx.r23.s64 = ctx.r23.s64 + -1;
	// addi r24,r24,-8
	ctx.r24.s64 = ctx.r24.s64 + -8;
	// b 0x8211d7c4
	goto loc_8211D7C4;
loc_8211D7C0:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_8211D7C4:
	// lwz r11,540(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 540);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8211d724
	if (!ctx.cr6.eq) goto loc_8211D724;
loc_8211D7D0:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8211d7e8
	if (!ctx.cr6.eq) goto loc_8211D7E8;
loc_8211D7D8:
	// lwz r3,96(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x821180d8
	ctx.lr = 0x8211D7E0;
	sub_821180D8(ctx, base);
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// b 0x8211d9f4
	goto loc_8211D9F4;
loc_8211D7E8:
	// mr r27,r22
	ctx.r27.u64 = ctx.r22.u64;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8211d840
	if (ctx.cr6.eq) goto loc_8211D840;
	// addi r30,r1,116
	ctx.r30.s64 = ctx.r1.s64 + 116;
loc_8211D7F8:
	// addi r29,r29,-1
	ctx.r29.s64 = ctx.r29.s64 + -1;
	// lwz r3,-4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -4);
	// addi r10,r30,2
	ctx.r10.s64 = ctx.r30.s64 + 2;
	// lwz r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// cntlzw r11,r29
	ctx.r11.u64 = ctx.r29.u32 == 0 ? 32 : __builtin_clz(ctx.r29.u32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// addi r8,r1,108
	ctx.r8.s64 = ctx.r1.s64 + 108;
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// rlwinm r5,r11,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// bl 0x82126530
	ctx.lr = 0x8211D824;
	sub_82126530(ctx, base);
	// lhz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 0);
	// clrlwi r10,r27,16
	ctx.r10.u64 = ctx.r27.u32 & 0xFFFF;
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// clrlwi r27,r11,16
	ctx.r27.u64 = ctx.r11.u32 & 0xFFFF;
	// bne 0x8211d7f8
	if (!ctx.cr0.eq) goto loc_8211D7F8;
loc_8211D840:
	// cmplwi cr6,r23,32
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 32, ctx.xer);
	// bge cr6,0x8211d888
	if (!ctx.cr6.lt) goto loc_8211D888;
	// addi r30,r1,364
	ctx.r30.s64 = ctx.r1.s64 + 364;
	// subfic r28,r23,32
	ctx.xer.ca = ctx.r23.u32 <= 32;
	ctx.r28.u64 = static_cast<uint64_t>(32) - ctx.r23.u64;
loc_8211D850:
	// addi r29,r29,-1
	ctx.r29.s64 = ctx.r29.s64 + -1;
	// lwz r3,-4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -4);
	// addi r10,r30,2
	ctx.r10.s64 = ctx.r30.s64 + 2;
	// lwz r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// cntlzw r11,r29
	ctx.r11.u64 = ctx.r29.u32 == 0 ? 32 : __builtin_clz(ctx.r29.u32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// addi r8,r1,108
	ctx.r8.s64 = ctx.r1.s64 + 108;
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// rlwinm r5,r11,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// bl 0x82126530
	ctx.lr = 0x8211D87C;
	sub_82126530(ctx, base);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r30,r30,-8
	ctx.r30.s64 = ctx.r30.s64 + -8;
	// bne 0x8211d850
	if (!ctx.cr0.eq) goto loc_8211D850;
loc_8211D888:
	// mr r10,r18
	ctx.r10.u64 = ctx.r18.u64;
	// lhz r9,1032(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 1032);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// lwz r8,108(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// addi r4,r31,28
	ctx.r4.s64 = ctx.r31.s64 + 28;
	// lwz r7,100(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r6,104(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,96(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// stw r21,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r21.u32);
	// stw r19,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r19.u32);
	// bl 0x82121738
	ctx.lr = 0x8211D8B4;
	sub_82121738(ctx, base);
	// lhz r10,38(r21)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r21.u32 + 38);
	// lhz r11,1032(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1032);
	// rlwinm. r10,r10,0,0,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFF8000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8211d8e4
	if (!ctx.cr0.eq) goto loc_8211D8E4;
	// lhz r10,36(r21)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r21.u32 + 36);
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// cmpwi cr6,r10,4096
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4096, ctx.xer);
	// ble cr6,0x8211d8e4
	if (!ctx.cr6.gt) goto loc_8211D8E4;
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// addi r11,r11,-2048
	ctx.r11.s64 = ctx.r11.s64 + -2048;
	// sth r11,36(r21)
	REX_STORE_U16(ctx.r21.u32 + 36, ctx.r11.u16);
loc_8211D8E4:
	// lhz r11,1032(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1032);
	// lwz r9,100(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// sth r11,1032(r31)
	REX_STORE_U16(ctx.r31.u32 + 1032, ctx.r11.u16);
	// bne cr6,0x8211d90c
	if (!ctx.cr6.eq) goto loc_8211D90C;
	// lhz r11,330(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 330);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8211d970
	if (ctx.cr0.eq) goto loc_8211D970;
loc_8211D90C:
	// addi r9,r31,1000
	ctx.r9.s64 = ctx.r31.s64 + 1000;
	// addi r11,r10,8
	ctx.r11.s64 = ctx.r10.s64 + 8;
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r9,1004(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1004);
	// stw r9,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// lwz r10,1004(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1004);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r11,1004(r31)
	REX_STORE_U32(ctx.r31.u32 + 1004, ctx.r11.u32);
loc_8211D934:
	// mfmsr r7
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r7.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r8,0,r10
	ea = ctx.r10.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r8.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stwcx. r8,0,r10
	ea = ctx.r10.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r8.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r7,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8211d934
	if (!ctx.cr0.eq) goto loc_8211D934;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lhz r10,336(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 336);
	// ori r10,r10,16384
	ctx.r10.u64 = ctx.r10.u64 | 16384;
	// sth r10,336(r11)
	REX_STORE_U16(ctx.r11.u32 + 336, ctx.r10.u16);
	// lhz r11,1042(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1042);
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// sth r11,1042(r31)
	REX_STORE_U16(ctx.r31.u32 + 1042, ctx.r11.u16);
loc_8211D970:
	// lhz r11,1040(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1040);
	// clrlwi r10,r17,16
	ctx.r10.u64 = ctx.r17.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// lwz r11,1148(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1148);
	// blt cr6,0x8211d98c
	if (ctx.cr6.lt) goto loc_8211D98C;
	// oris r11,r11,512
	ctx.r11.u64 = ctx.r11.u64 | 33554432;
	// b 0x8211d990
	goto loc_8211D990;
loc_8211D98C:
	// rlwinm r11,r11,0,7,5
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFDFFFFFF;
loc_8211D990:
	// stw r11,1148(r31)
	REX_STORE_U32(ctx.r31.u32 + 1148, ctx.r11.u32);
	// addi r3,r31,296
	ctx.r3.s64 = ctx.r31.s64 + 296;
	// lbz r11,1144(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1144);
	// andi. r11,r11,239
	ctx.r11.u64 = ctx.r11.u64 & 239;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r11,1144(r31)
	REX_STORE_U8(ctx.r31.u32 + 1144, ctx.r11.u8);
	// bl 0x82122310
	ctx.lr = 0x8211D9A8;
	sub_82122310(ctx, base);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8211d9c0
	if (ctx.cr6.eq) goto loc_8211D9C0;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211af80
	ctx.lr = 0x8211D9C0;
	sub_8211AF80(ctx, base);
loc_8211D9C0:
	// lwz r11,1152(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1152);
	// lwz r3,96(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// ld r10,1168(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 1168);
	// stw r11,1152(r31)
	REX_STORE_U32(ctx.r31.u32 + 1152, ctx.r11.u32);
	// lwz r9,24(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r11,32(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// std r11,1168(r31)
	REX_STORE_U64(ctx.r31.u32 + 1168, ctx.r11.u64);
	// b 0x8211d9f4
	goto loc_8211D9F4;
loc_8211D9F0:
	// lwz r3,96(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
loc_8211D9F4:
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// b 0x8212993c
	__restgprlr_17(ctx, base);
	return;
}
