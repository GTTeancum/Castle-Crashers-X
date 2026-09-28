DEFINE_REX_FUNC(sub_8211EE88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8211EE90;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8211f0b4
	if (!ctx.cr6.eq) goto loc_8211F0B4;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,44(r4)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r4.u32 + 44);
	// lwz r4,40(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + 40);
	// bl 0x82120830
	ctx.lr = 0x8211EEB4;
	sub_82120830(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8211f0b4
	if (ctx.cr0.eq) goto loc_8211F0B4;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lhz r30,1046(r31)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r31.u32 + 1046);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r11,5(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// rlwinm r10,r10,8,22,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0x300;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// clrlwi r3,r11,16
	ctx.r3.u64 = ctx.r11.u32 & 0xFFFF;
	// bl 0x82119e70
	ctx.lr = 0x8211EEE0;
	sub_82119E70(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// extsh r11,r29
	ctx.r11.s64 = ctx.r29.s16;
	// subf r10,r30,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r30.u64;
	// extsh r28,r10
	ctx.r28.s64 = ctx.r10.s16;
	// cmpwi cr6,r28,-256
	ctx.cr6.compare<int32_t>(ctx.r28.s32, -256, ctx.xer);
	// blt cr6,0x8211f0b4
	if (ctx.cr6.lt) goto loc_8211F0B4;
	// cmpwi cr6,r28,256
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 256, ctx.xer);
	// bgt cr6,0x8211f0b4
	if (ctx.cr6.gt) goto loc_8211F0B4;
	// lhz r10,1032(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 1032);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// extsh. r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt 0x8211f0b4
	if (ctx.cr0.lt) goto loc_8211F0B4;
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8211ef48
	if (ctx.cr6.eq) goto loc_8211EF48;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r6,84(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82123cd0
	ctx.lr = 0x8211EF2C;
	sub_82123CD0(ctx, base);
	// lhz r11,1032(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1032);
	// lhz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 96);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// extsh. r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x8211f0b4
	if (!ctx.cr0.gt) goto loc_8211F0B4;
	// addi r27,r1,96
	ctx.r27.s64 = ctx.r1.s64 + 96;
	// b 0x8211ef4c
	goto loc_8211EF4C;
loc_8211EF48:
	// li r27,0
	ctx.r27.s64 = 0;
loc_8211EF4C:
	// bl 0x82136f58
	ctx.lr = 0x8211EF50;
	sub_82136F58(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// stw r30,464(r31)
	REX_STORE_U32(ctx.r31.u32 + 464, ctx.r30.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// blt cr6,0x8211ef94
	if (ctx.cr6.lt) goto loc_8211EF94;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211ea80
	ctx.lr = 0x8211EF74;
	sub_8211EA80(ctx, base);
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// rlwinm r6,r11,30,2,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// bl 0x8211b100
	ctx.lr = 0x8211EF90;
	sub_8211B100(ctx, base);
	// b 0x8211ef9c
	goto loc_8211EF9C;
loc_8211EF94:
	// addi r3,r31,664
	ctx.r3.s64 = ctx.r31.s64 + 664;
	// bl 0x82125430
	ctx.lr = 0x8211EF9C;
	sub_82125430(ctx, base);
loc_8211EF9C:
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lbz r10,3(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8211efc4
	if (ctx.cr0.eq) goto loc_8211EFC4;
	// lwz r11,6(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 6);
	// lbz r10,1144(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 1144);
	// ori r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 | 32;
	// stw r11,448(r31)
	REX_STORE_U32(ctx.r31.u32 + 448, ctx.r11.u32);
	// stb r10,1144(r31)
	REX_STORE_U8(ctx.r31.u32 + 1144, ctx.r10.u8);
	// b 0x8211f0b4
	goto loc_8211F0B4;
loc_8211EFC4:
	// lwz r10,1148(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1148);
	// rlwinm. r10,r10,0,8,8
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x800000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8211f0b4
	if (ctx.cr0.eq) goto loc_8211F0B4;
	// lwz r11,6(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 6);
	// lwz r10,444(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 444);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8211f004
	if (ctx.cr6.eq) goto loc_8211F004;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplwi cr6,r11,256
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 256, ctx.xer);
	// bgt cr6,0x8211f0b4
	if (ctx.cr6.gt) goto loc_8211F0B4;
	// lwz r11,452(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// ble cr6,0x8211f0b4
	if (!ctx.cr6.gt) goto loc_8211F0B4;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r11.u32);
	// b 0x8211f0b4
	goto loc_8211F0B4;
loc_8211F004:
	// lwz r11,460(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 460);
	// lis r29,-32768
	ctx.r29.s64 = -2147483648;
	// subf r4,r11,r30
	ctx.r4.u64 = ctx.r30.u64 - ctx.r11.u64;
	// cmplw cr6,r4,r29
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x8211f01c
	if (ctx.cr6.lt) goto loc_8211F01C;
	// lwz r4,676(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 676);
loc_8211F01C:
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// addi r3,r31,664
	ctx.r3.s64 = ctx.r31.s64 + 664;
	// lwz r5,452(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// lwz r11,48(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// rlwinm r7,r11,29,3,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// bl 0x82125130
	ctx.lr = 0x8211F03C;
	sub_82125130(ctx, base);
	// lwz r11,1148(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1148);
	// stw r30,468(r31)
	REX_STORE_U32(ctx.r31.u32 + 468, ctx.r30.u32);
	// rlwinm. r10,r11,0,10,10
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8211f088
	if (ctx.cr0.eq) goto loc_8211F088;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r3,r31,356
	ctx.r3.s64 = ctx.r31.s64 + 356;
	// rlwimi r11,r10,22,8,9
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0xC00000) | (ctx.r11.u64 & 0xFFFFFFFFFF3FFFFF);
	// stw r11,1148(r31)
	REX_STORE_U32(ctx.r31.u32 + 1148, ctx.r11.u32);
	// lwz r11,412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8211f078
	if (ctx.cr0.eq) goto loc_8211F078;
	// lwz r11,52(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// subf r11,r11,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r11.u64;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x8211f0b4
	if (ctx.cr6.lt) goto loc_8211F0B4;
loc_8211F078:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82122270
	ctx.lr = 0x8211F084;
	sub_82122270(ctx, base);
	// b 0x8211f0b4
	goto loc_8211F0B4;
loc_8211F088:
	// rlwinm. r11,r11,0,11,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq 0x8211f0ac
	if (ctx.cr0.eq) goto loc_8211F0AC;
	// lis r11,-32646
	ctx.r11.s64 = -2139488256;
	// li r4,1
	ctx.r4.s64 = 1;
	// ori r11,r11,4101
	ctx.r11.u64 = ctx.r11.u64 | 4101;
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// bl 0x8211c0e8
	ctx.lr = 0x8211F0A8;
	sub_8211C0E8(ctx, base);
	// b 0x8211f0b4
	goto loc_8211F0B4;
loc_8211F0AC:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8211af80
	ctx.lr = 0x8211F0B4;
	sub_8211AF80(ctx, base);
loc_8211F0B4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
