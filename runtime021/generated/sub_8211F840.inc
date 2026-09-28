DEFINE_REX_FUNC(sub_8211F840) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x8211F848;
	__savegprlr_24(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8211fa5c
	if (!ctx.cr6.eq) goto loc_8211FA5C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,40(r24)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r24.u32 + 40);
	// lwz r5,44(r24)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// bl 0x82120d18
	ctx.lr = 0x8211F870;
	sub_82120D18(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8211fa5c
	if (ctx.cr0.eq) goto loc_8211FA5C;
	// lwz r30,120(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// addi r27,r31,872
	ctx.r27.s64 = ctx.r31.s64 + 872;
	// lhz r4,872(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 872);
	// lbz r11,2(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 2);
	// lbz r10,3(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 3);
	// rlwinm r11,r11,8,22,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0x300;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// clrlwi r3,r11,16
	ctx.r3.u64 = ctx.r11.u32 & 0xFFFF;
	// bl 0x82119e70
	ctx.lr = 0x8211F89C;
	sub_82119E70(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211a240
	ctx.lr = 0x8211F8A8;
	sub_8211A240(ctx, base);
	// subf r10,r3,r25
	ctx.r10.u64 = ctx.r25.u64 - ctx.r3.u64;
	// lhz r11,1040(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1040);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8211fa5c
	if (!ctx.cr6.lt) goto loc_8211FA5C;
	// neg r11,r11
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x8211fa5c
	if (!ctx.cr6.gt) goto loc_8211FA5C;
	// lbz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 4);
	// lbz r10,5(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 5);
	// rlwinm r11,r11,8,22,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0x300;
	// lhz r30,1046(r31)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r31.u32 + 1046);
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// clrlwi r3,r11,16
	ctx.r3.u64 = ctx.r11.u32 & 0xFFFF;
	// bl 0x82119e70
	ctx.lr = 0x8211F8E8;
	sub_82119E70(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// extsh r11,r28
	ctx.r11.s64 = ctx.r28.s16;
	// subf r10,r30,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r30.u64;
	// extsh r29,r10
	ctx.r29.s64 = ctx.r10.s16;
	// cmpwi cr6,r29,-256
	ctx.cr6.compare<int32_t>(ctx.r29.s32, -256, ctx.xer);
	// blt cr6,0x8211fa5c
	if (ctx.cr6.lt) goto loc_8211FA5C;
	// cmpwi cr6,r29,256
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 256, ctx.xer);
	// bgt cr6,0x8211fa5c
	if (ctx.cr6.gt) goto loc_8211FA5C;
	// lhz r10,1032(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 1032);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// extsh. r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt 0x8211fa5c
	if (ctx.cr0.lt) goto loc_8211FA5C;
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8211f950
	if (ctx.cr6.eq) goto loc_8211F950;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r6,112(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82123cd0
	ctx.lr = 0x8211F934;
	sub_82123CD0(ctx, base);
	// lhz r11,1032(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1032);
	// lhz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// extsh. r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x8211fa5c
	if (!ctx.cr0.gt) goto loc_8211FA5C;
	// addi r26,r1,80
	ctx.r26.s64 = ctx.r1.s64 + 80;
	// b 0x8211f954
	goto loc_8211F954;
loc_8211F950:
	// li r26,0
	ctx.r26.s64 = 0;
loc_8211F954:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82123aa0
	ctx.lr = 0x8211F960;
	sub_82123AA0(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq 0x8211fa5c
	if (ctx.cr0.eq) goto loc_8211FA5C;
	// bl 0x82136f58
	ctx.lr = 0x8211F96C;
	sub_82136F58(ctx, base);
	// lwz r11,1160(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1160);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// ld r10,1184(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 1184);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r30,464(r31)
	REX_STORE_U32(ctx.r31.u32 + 464, ctx.r30.u32);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r11,1160(r31)
	REX_STORE_U32(ctx.r31.u32 + 1160, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,44(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// std r11,1184(r31)
	REX_STORE_U64(ctx.r31.u32 + 1184, ctx.r11.u64);
	// blt cr6,0x8211f9cc
	if (ctx.cr6.lt) goto loc_8211F9CC;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211ea80
	ctx.lr = 0x8211F9AC;
	sub_8211EA80(ctx, base);
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// rlwinm r6,r11,30,2,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// bl 0x8211b100
	ctx.lr = 0x8211F9C8;
	sub_8211B100(ctx, base);
	// b 0x8211f9d4
	goto loc_8211F9D4;
loc_8211F9CC:
	// addi r3,r31,664
	ctx.r3.s64 = ctx.r31.s64 + 664;
	// bl 0x82125430
	ctx.lr = 0x8211F9D4;
	sub_82125430(ctx, base);
loc_8211F9D4:
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,2(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// rlwinm r4,r11,27,30,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x3;
	// bl 0x8211aff8
	ctx.lr = 0x8211F9EC;
	sub_8211AFF8(ctx, base);
	// cmpwi cr6,r27,1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 1, ctx.xer);
	// beq cr6,0x8211fa5c
	if (ctx.cr6.eq) goto loc_8211FA5C;
	// lwz r5,96(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8211fa10
	if (ctx.cr6.eq) goto loc_8211FA10;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// lwz r6,116(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211b0b0
	ctx.lr = 0x8211FA10;
	sub_8211B0B0(ctx, base);
loc_8211FA10:
	// lwz r11,108(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8211fa5c
	if (ctx.cr6.eq) goto loc_8211FA5C;
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// ld r6,616(r31)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r31.u32 + 616);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r7,104(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lbz r11,2(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// rlwinm r5,r11,0,27,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// bl 0x82121180
	ctx.lr = 0x8211FA40;
	sub_82121180(ctx, base);
	// std r3,616(r31)
	REX_STORE_U64(ctx.r31.u32 + 616, ctx.r3.u64);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwz r6,108(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,104(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// bl 0x8211f548
	ctx.lr = 0x8211FA58;
	sub_8211F548(ctx, base);
	// b 0x8211fa60
	goto loc_8211FA60;
loc_8211FA5C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8211FA60:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
