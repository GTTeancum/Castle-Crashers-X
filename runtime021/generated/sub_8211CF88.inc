DEFINE_REX_FUNC(sub_8211CF88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x8211CF90;
	__savegprlr_25(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r26,0
	ctx.r26.s64 = 0;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// stw r26,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r26.u32);
	// stw r26,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r26.u32);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8211d1ec
	if (ctx.cr6.eq) goto loc_8211D1EC;
	// lwz r11,1148(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1148);
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8211d1ec
	if (ctx.cr0.eq) goto loc_8211D1EC;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r5,44(r25)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r25.u32 + 44);
	// lwz r4,40(r25)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r25.u32 + 40);
	// bl 0x82120af0
	ctx.lr = 0x8211CFD0;
	sub_82120AF0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8211d1ec
	if (ctx.cr0.eq) goto loc_8211D1EC;
	// lwz r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lhz r11,3(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 3);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211d1ec
	if (ctx.cr6.lt) goto loc_8211D1EC;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,1607
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1607, ctx.xer);
	// bgt cr6,0x8211d1ec
	if (ctx.cr6.gt) goto loc_8211D1EC;
	// lhz r9,5(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 5);
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// bgt cr6,0x8211d1ec
	if (ctx.cr6.gt) goto loc_8211D1EC;
	// lhz r11,7(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 7);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8211d1ec
	if (ctx.cr6.lt) goto loc_8211D1EC;
	// clrlwi r8,r11,16
	ctx.r8.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r8,60000
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 60000, ctx.xer);
	// bgt cr6,0x8211d1ec
	if (ctx.cr6.gt) goto loc_8211D1EC;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8211d1ec
	if (ctx.cr6.gt) goto loc_8211D1EC;
	// lwz r11,29(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 29);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8211d1ec
	if (ctx.cr0.eq) goto loc_8211D1EC;
	// lwz r9,96(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x8211d1ec
	if (ctx.cr6.gt) goto loc_8211D1EC;
	// lwz r11,9(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 9);
	// lwz r9,424(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8211d1ec
	if (!ctx.cr6.eq) goto loc_8211D1EC;
	// lwz r11,25(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 25);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x8211d1ec
	if (!ctx.cr6.eq) goto loc_8211D1EC;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82120b30
	ctx.lr = 0x8211D06C;
	sub_82120B30(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8211d1ec
	if (ctx.cr0.eq) goto loc_8211D1EC;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,29(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 29);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x8211d1ec
	if (ctx.cr6.gt) goto loc_8211D1EC;
	// lbz r10,1144(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 1144);
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stb r10,1144(r31)
	REX_STORE_U8(ctx.r31.u32 + 1144, ctx.r10.u8);
	// lwz r10,21(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 21);
	// stw r10,436(r31)
	REX_STORE_U32(ctx.r31.u32 + 436, ctx.r10.u32);
	// bne cr6,0x8211d1ec
	if (!ctx.cr6.eq) goto loc_8211D1EC;
	// lhz r10,3(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 3);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// sth r10,1056(r31)
	REX_STORE_U16(ctx.r31.u32 + 1056, ctx.r10.u16);
	// lhz r10,5(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 5);
	// sth r10,1052(r31)
	REX_STORE_U16(ctx.r31.u32 + 1052, ctx.r10.u16);
	// lhz r10,7(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 7);
	// sth r10,1054(r31)
	REX_STORE_U16(ctx.r31.u32 + 1054, ctx.r10.u16);
	// lwz r10,29(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 29);
	// stw r10,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r10.u32);
	// lwz r4,13(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 13);
	// bl 0x8211b620
	ctx.lr = 0x8211D0D4;
	sub_8211B620(ctx, base);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8211d114
	if (ctx.cr6.eq) goto loc_8211D114;
	// addi r3,r31,572
	ctx.r3.s64 = ctx.r31.s64 + 572;
	// bl 0x821220f8
	ctx.lr = 0x8211D0E8;
	sub_821220F8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8211d114
	if (!ctx.cr0.eq) goto loc_8211D114;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x8211d1ec
	if (ctx.cr6.eq) goto loc_8211D1EC;
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// li r10,3
	ctx.r10.s64 = 3;
	// ori r11,r11,14
	ctx.r11.u64 = ctx.r11.u64 | 14;
	// stw r10,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// b 0x8211d1dc
	goto loc_8211D1DC;
loc_8211D114:
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// addi r28,r1,84
	ctx.r28.s64 = ctx.r1.s64 + 84;
loc_8211D11C:
	// lhz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 0);
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8211d16c
	if (ctx.cr0.eq) goto loc_8211D16C;
	// subfic r11,r29,-1
	ctx.xer.ca = ctx.r29.u32 <= 4294967295;
	ctx.r11.u64 = static_cast<uint64_t>(-1) - ctx.r29.u64;
	// rlwinm r11,r11,24,0,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFF000000;
	// oris r27,r11,32768
	ctx.r27.u64 = ctx.r11.u64 | 2147483648;
loc_8211D138:
	// lis r11,255
	ctx.r11.s64 = 16711680;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// ori r11,r11,65534
	ctx.r11.u64 = ctx.r11.u64 | 65534;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
	// or r4,r11,r27
	ctx.r4.u64 = ctx.r11.u64 | ctx.r27.u64;
	// bl 0x8211b3b8
	ctx.lr = 0x8211D154;
	sub_8211B3B8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8211d1c4
	if (ctx.cr0.lt) goto loc_8211D1C4;
	// lhz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 0);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8211d138
	if (ctx.cr6.lt) goto loc_8211D138;
loc_8211D16C:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r28,r28,2
	ctx.r28.s64 = ctx.r28.s64 + 2;
	// cmplwi cr6,r29,2
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 2, ctx.xer);
	// blt cr6,0x8211d11c
	if (ctx.cr6.lt) goto loc_8211D11C;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r30,17(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 17);
	// bl 0x82136f58
	ctx.lr = 0x8211D188;
	sub_82136F58(ctx, base);
	// lwz r11,432(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 432);
	// subf r10,r11,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r11.u64;
	// subf r9,r11,r30
	ctx.r9.u64 = ctx.r30.u64 - ctx.r11.u64;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8211d1a0
	if (!ctx.cr6.gt) goto loc_8211D1A0;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_8211D1A0:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211b690
	ctx.lr = 0x8211D1AC;
	sub_8211B690(ctx, base);
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8211d1ec
	if (ctx.cr6.eq) goto loc_8211D1EC;
	// stw r25,420(r31)
	REX_STORE_U32(ctx.r31.u32 + 420, ctx.r25.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8211d1f0
	goto loc_8211D1F0;
loc_8211D1C4:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x8211d1ec
	if (ctx.cr6.eq) goto loc_8211D1EC;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r3,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_8211D1DC:
	// stb r26,1144(r31)
	REX_STORE_U8(ctx.r31.u32 + 1144, ctx.r26.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r26,1145(r31)
	REX_STORE_U8(ctx.r31.u32 + 1145, ctx.r26.u8);
	// bl 0x8211a3b8
	ctx.lr = 0x8211D1EC;
	sub_8211A3B8(ctx, base);
loc_8211D1EC:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_8211D1F0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
