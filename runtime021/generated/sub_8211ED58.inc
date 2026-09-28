DEFINE_REX_FUNC(sub_8211ED58) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8211ED60;
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
	// bne cr6,0x8211ee78
	if (!ctx.cr6.eq) goto loc_8211EE78;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,44(r4)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r4.u32 + 44);
	// lwz r4,40(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + 40);
	// bl 0x821207a8
	ctx.lr = 0x8211ED84;
	sub_821207A8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8211ee78
	if (ctx.cr0.eq) goto loc_8211EE78;
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
	ctx.lr = 0x8211EDB0;
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
	// blt cr6,0x8211ee78
	if (ctx.cr6.lt) goto loc_8211EE78;
	// cmpwi cr6,r28,256
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 256, ctx.xer);
	// bgt cr6,0x8211ee78
	if (ctx.cr6.gt) goto loc_8211EE78;
	// lhz r10,1032(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 1032);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// extsh. r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt 0x8211ee78
	if (ctx.cr0.lt) goto loc_8211EE78;
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8211ee18
	if (ctx.cr6.eq) goto loc_8211EE18;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r6,84(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82123cd0
	ctx.lr = 0x8211EDFC;
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
	// ble 0x8211ee78
	if (!ctx.cr0.gt) goto loc_8211EE78;
	// addi r27,r1,96
	ctx.r27.s64 = ctx.r1.s64 + 96;
	// b 0x8211ee1c
	goto loc_8211EE1C;
loc_8211EE18:
	// li r27,0
	ctx.r27.s64 = 0;
loc_8211EE1C:
	// bl 0x82136f58
	ctx.lr = 0x8211EE20;
	sub_82136F58(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// stw r30,464(r31)
	REX_STORE_U32(ctx.r31.u32 + 464, ctx.r30.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// blt cr6,0x8211ee70
	if (ctx.cr6.lt) goto loc_8211EE70;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211ea80
	ctx.lr = 0x8211EE44;
	sub_8211EA80(ctx, base);
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
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
	ctx.lr = 0x8211EE64;
	sub_8211B100(ctx, base);
	// or. r11,r3,r28
	ctx.r11.u64 = ctx.r3.u64 | ctx.r28.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8211ee78
	if (!ctx.cr0.eq) goto loc_8211EE78;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
loc_8211EE70:
	// addi r3,r31,664
	ctx.r3.s64 = ctx.r31.s64 + 664;
	// bl 0x82125430
	ctx.lr = 0x8211EE78;
	sub_82125430(ctx, base);
loc_8211EE78:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
