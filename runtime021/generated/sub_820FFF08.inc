DEFINE_REX_FUNC(sub_820FFF08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x820FFF10;
	__savegprlr_23(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// li r24,0
	ctx.r24.s64 = 0;
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820FFF3C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r27,16(r31)
	ctx.r27.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r3,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r3.u8);
	// stb r9,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r9.u8);
	// beq 0x820fff94
	if (ctx.cr0.eq) goto loc_820FFF94;
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// b 0x820fff6c
	goto loc_820FFF6C;
loc_820FFF64:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
loc_820FFF6C:
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x820fff64
	if (!ctx.cr0.eq) goto loc_820FFF64;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820FFF78:
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwinm. r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820fffa8
	if (ctx.cr0.eq) goto loc_820FFFA8;
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820fff78
	if (!ctx.cr6.eq) goto loc_820FFF78;
loc_820FFF90:
	// li r27,0
	ctx.r27.s64 = 0;
loc_820FFF94:
	// li r28,1
	ctx.r28.s64 = 1;
	// cmpldi cr6,r27,0
	ctx.cr6.compare<uint64_t>(ctx.r27.u64, 0, ctx.xer);
	// bne cr6,0x820fffb8
	if (!ctx.cr6.eq) goto loc_820FFFB8;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// b 0x820fffd4
	goto loc_820FFFD4;
loc_820FFFA8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fff90
	if (ctx.cr6.eq) goto loc_820FFF90;
	// ld r27,16(r11)
	ctx.r27.u64 = REX_LOAD_U64(ctx.r11.u32 + 16);
	// b 0x820fff94
	goto loc_820FFF94;
loc_820FFFB8:
	// li r11,9
	ctx.r11.s64 = 9;
	// rldicr r10,r27,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u64, 0) & 0xFFFF000000000000;
	// rldicr r11,r11,48,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 48) & 0xFFFF000000000000;
	// cmpld cr6,r10,r11
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, ctx.r11.u64, ctx.xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq cr6,0x820fffd4
	if (ctx.cr6.eq) goto loc_820FFFD4;
	// li r27,0
	ctx.r27.s64 = 0;
loc_820FFFD4:
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// li r30,0
	ctx.r30.s64 = 0;
loc_820FFFDC:
	// addi r11,r30,95
	ctx.r11.s64 = ctx.r30.s64 + 95;
	// rlwinm r29,r11,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r29,r25
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r25.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210013c
	if (ctx.cr6.eq) goto loc_8210013C;
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x8210013c
	if (ctx.cr6.eq) goto loc_8210013C;
	// cmpldi cr6,r27,0
	ctx.cr6.compare<uint64_t>(ctx.r27.u64, 0, ctx.xer);
	// beq cr6,0x821000a8
	if (ctx.cr6.eq) goto loc_821000A8;
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwinm. r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82100058
	if (ctx.cr0.eq) goto loc_82100058;
	// lwz r10,84(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// b 0x8210001c
	goto loc_8210001C;
loc_82100014:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lwz r10,84(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 84);
loc_8210001C:
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82100014
	if (!ctx.cr0.eq) goto loc_82100014;
loc_82100024:
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwinm. r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82100048
	if (ctx.cr0.eq) goto loc_82100048;
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82100024
	if (!ctx.cr6.eq) goto loc_82100024;
loc_8210003C:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,1307
	ctx.r3.u64 = ctx.r3.u64 | 1307;
	// b 0x82100238
	goto loc_82100238;
loc_82100048:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210003c
	if (ctx.cr6.eq) goto loc_8210003C;
	// lwz r3,24(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// b 0x8210005c
	goto loc_8210005C;
loc_82100058:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8210005C:
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82139170
	ctx.lr = 0x82100068;
	sub_82139170(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x821000a4
	if (ctx.cr0.eq) goto loc_821000A4;
	// cmplwi cr6,r3,1245
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1245, ctx.xer);
	// bne cr6,0x821001d0
	if (!ctx.cr6.eq) goto loc_821001D0;
	// lwz r11,28(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82100098
	if (ctx.cr6.eq) goto loc_82100098;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82100098
	if (ctx.cr6.eq) goto loc_82100098;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// b 0x821000b0
	goto loc_821000B0;
loc_82100098:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// b 0x821000a8
	goto loc_821000A8;
loc_821000A4:
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
loc_821000A8:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x821000c4
	if (ctx.cr6.eq) goto loc_821000C4;
loc_821000B0:
	// lbz r11,97(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 97);
	// slw r9,r28,r30
	ctx.r9.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r30.u8 & 0x3F));
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
	// stb r11,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r11.u8);
	// b 0x821000c8
	goto loc_821000C8;
loc_821000C4:
	// mr r26,r28
	ctx.r26.u64 = ctx.r28.u64;
loc_821000C8:
	// cmplwi cr6,r30,255
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 255, ctx.xer);
	// bne cr6,0x821000d8
	if (!ctx.cr6.eq) goto loc_821000D8;
	// li r11,15
	ctx.r11.s64 = 15;
	// b 0x821000e0
	goto loc_821000E0;
loc_821000D8:
	// slw r11,r28,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r30.u8 & 0x3F));
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
loc_821000E0:
	// clrlwi r9,r11,24
	ctx.r9.u64 = ctx.r11.u32 & 0xFF;
	// lbz r11,392(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 392);
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// and r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 & ctx.r11.u64;
	// rlwinm r8,r8,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// xori r8,r8,1
	ctx.r8.u64 = ctx.r8.u64 ^ 1;
	// rlwinm r9,r9,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r9,r9,1
	ctx.r9.u64 = ctx.r9.u64 ^ 1;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// beq cr6,0x82100160
	if (ctx.cr6.eq) goto loc_82100160;
	// lwz r9,396(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// rlwinm. r9,r9,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8210011c
	if (!ctx.cr0.eq) goto loc_8210011C;
	// lwzx r24,r29,r25
	ctx.r24.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r25.u32);
loc_8210011C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// slw r9,r28,r30
	ctx.r9.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r30.u8 & 0x3F));
	// beq cr6,0x82100130
	if (ctx.cr6.eq) goto loc_82100130;
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
	// b 0x82100134
	goto loc_82100134;
loc_82100130:
	// andc r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 & ~ctx.r9.u64;
loc_82100134:
	// stb r11,392(r31)
	REX_STORE_U8(ctx.r31.u32 + 392, ctx.r11.u8);
	// b 0x82100160
	goto loc_82100160;
loc_8210013C:
	// lbz r11,392(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 392);
	// slw r9,r28,r30
	ctx.r9.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r30.u8 & 0x3F));
	// andc r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 & ~ctx.r9.u64;
	// stb r11,392(r31)
	REX_STORE_U8(ctx.r31.u32 + 392, ctx.r11.u8);
	// lwzx r11,r29,r25
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r25.u32);
	// subf r11,r11,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r11.u64;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// or r26,r11,r26
	ctx.r26.u64 = ctx.r11.u64 | ctx.r26.u64;
loc_82100160:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x820fffdc
	if (ctx.cr6.lt) goto loc_820FFFDC;
	// cntlzw r11,r26
	ctx.r11.u64 = ctx.r26.u32 == 0 ? 32 : __builtin_clz(ctx.r26.u32);
	// lwz r10,396(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// rlwimi r10,r11,17,14,14
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0x20000) | (ctx.r10.u64 & 0xFFFFFFFFFFFDFFFF);
	// stw r10,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r10.u32);
	// beq cr6,0x82100234
	if (ctx.cr6.eq) goto loc_82100234;
	// li r8,3
	ctx.r8.s64 = 3;
	// li r11,143
	ctx.r11.s64 = 143;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r11,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r11.u8);
	// li r8,2
	ctx.r8.s64 = 2;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x820ff3a8
	ctx.lr = 0x821001BC;
	sub_820FF3A8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82100238
	if (ctx.cr0.lt) goto loc_82100238;
	// lwz r10,84(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// b 0x821001ec
	goto loc_821001EC;
loc_821001D0:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x82100238
	if (!ctx.cr6.gt) goto loc_82100238;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r3,r11,32775
	ctx.r3.u64 = ctx.r11.u64 | 2147942400;
	// b 0x82100238
	goto loc_82100238;
loc_821001E4:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lwz r10,84(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 84);
loc_821001EC:
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x821001e4
	if (!ctx.cr0.eq) goto loc_821001E4;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
loc_821001FC:
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821001fc
	if (!ctx.cr6.eq) goto loc_821001FC;
	// mr r8,r23
	ctx.r8.u64 = ctx.r23.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x820fec30
	ctx.lr = 0x8210022C;
	sub_820FEC30(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82100238
	if (ctx.cr0.lt) goto loc_82100238;
loc_82100234:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82100238:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
