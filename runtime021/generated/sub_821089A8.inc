DEFINE_REX_FUNC(sub_821089A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e4
	ctx.lr = 0x821089B0;
	__savegprlr_15(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r4
	ctx.r21.u64 = ctx.r4.u64;
	// mr r16,r3
	ctx.r16.u64 = ctx.r3.u64;
	// mr r19,r5
	ctx.r19.u64 = ctx.r5.u64;
	// mr r18,r6
	ctx.r18.u64 = ctx.r6.u64;
	// mr r17,r7
	ctx.r17.u64 = ctx.r7.u64;
	// mr r15,r8
	ctx.r15.u64 = ctx.r8.u64;
	// mr r27,r9
	ctx.r27.u64 = ctx.r9.u64;
	// mr r26,r10
	ctx.r26.u64 = ctx.r10.u64;
	// cmplwi cr6,r21,1024
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 1024, ctx.xer);
	// bgt cr6,0x82108a74
	if (ctx.cr6.gt) goto loc_82108A74;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lwz r10,0(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// lwz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// li r22,0
	ctx.r22.s64 = 0;
	// ori r20,r9,65001
	ctx.r20.u64 = ctx.r9.u64 | 65001;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// beq cr6,0x82108af4
	if (ctx.cr6.eq) goto loc_82108AF4;
loc_821089FC:
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x82108a74
	if (ctx.cr6.lt) goto loc_82108A74;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r30,r11,-5
	ctx.r30.s64 = ctx.r11.s64 + -5;
	// addi r22,r22,24
	ctx.r22.s64 = ctx.r22.s64 + 24;
	// addi r29,r10,1
	ctx.r29.s64 = ctx.r10.s64 + 1;
	// lbz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82108ad4
	if (ctx.cr6.eq) goto loc_82108AD4;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82108a50
	if (ctx.cr6.eq) goto loc_82108A50;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x82108a50
	if (ctx.cr6.eq) goto loc_82108A50;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x82108a80
	if (ctx.cr6.eq) goto loc_82108A80;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x82108ad4
	if (ctx.cr6.eq) goto loc_82108AD4;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// beq cr6,0x82108a58
	if (ctx.cr6.eq) goto loc_82108A58;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x82108a74
	if (!ctx.cr6.eq) goto loc_82108A74;
loc_82108A50:
	// li r31,8
	ctx.r31.s64 = 8;
	// b 0x82108ad8
	goto loc_82108AD8;
loc_82108A58:
	// li r31,2
	ctx.r31.s64 = 2;
	// cmplwi cr6,r30,2
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2, ctx.xer);
	// ble cr6,0x82108ad8
	if (!ctx.cr6.gt) goto loc_82108AD8;
	// lhz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 0);
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r11,1024
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1024, ctx.xer);
	// ble cr6,0x82108ad8
	if (!ctx.cr6.gt) goto loc_82108AD8;
loc_82108A74:
	// lis r3,-32747
	ctx.r3.s64 = -2146107392;
	// ori r3,r3,10
	ctx.r3.u64 = ctx.r3.u64 | 10;
	// b 0x82108d48
	goto loc_82108D48;
loc_82108A80:
	// li r31,2
	ctx.r31.s64 = 2;
	// cmplwi cr6,r30,2
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2, ctx.xer);
	// ble cr6,0x82108ad8
	if (!ctx.cr6.gt) goto loc_82108AD8;
	// lhz r6,0(r29)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r29.u32 + 0);
	// add r30,r6,r30
	ctx.r30.u64 = ctx.r6.u64 + ctx.r30.u64;
	// cmplwi cr6,r30,2
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2, ctx.xer);
	// ble cr6,0x82108ad8
	if (!ctx.cr6.gt) goto loc_82108AD8;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r29,2
	ctx.r5.s64 = ctx.r29.s64 + 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x82136f70
	ctx.lr = 0x82108AB4;
	sub_82136F70(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82108a74
	if (ctx.cr0.lt) goto loc_82108A74;
	// cmplwi cr6,r3,512
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 512, ctx.xer);
	// bgt cr6,0x82108a74
	if (ctx.cr6.gt) goto loc_82108A74;
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// addi r22,r11,3
	ctx.r22.s64 = ctx.r11.s64 + 3;
	// b 0x82108ad8
	goto loc_82108AD8;
loc_82108AD4:
	// li r31,4
	ctx.r31.s64 = 4;
loc_82108AD8:
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x82108a74
	if (ctx.cr6.lt) goto loc_82108A74;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// add r10,r31,r29
	ctx.r10.u64 = ctx.r31.u64 + ctx.r29.u64;
	// subf r11,r31,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r31.u64;
	// cmplw cr6,r28,r21
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r21.u32, ctx.xer);
	// blt cr6,0x821089fc
	if (ctx.cr6.lt) goto loc_821089FC;
loc_82108AF4:
	// cmplwi cr6,r17,0
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 0, ctx.xer);
	// beq cr6,0x82108b4c
	if (ctx.cr6.eq) goto loc_82108B4C;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x82108b14
	if (ctx.cr6.eq) goto loc_82108B14;
	// lwz r11,0(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// subfic r11,r11,4
	ctx.xer.ca = ctx.r11.u32 <= 4;
	ctx.r11.u64 = static_cast<uint64_t>(4) - ctx.r11.u64;
	// b 0x82108b18
	goto loc_82108B18;
loc_82108B14:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82108B18:
	// add r22,r11,r22
	ctx.r22.u64 = ctx.r11.u64 + ctx.r22.u64;
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// beq cr6,0x82108d44
	if (ctx.cr6.eq) goto loc_82108D44;
	// lwz r10,0(r15)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r15.u32 + 0);
	// cmplw cr6,r22,r10
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82108b3c
	if (!ctx.cr6.gt) goto loc_82108B3C;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,122
	ctx.r3.u64 = ctx.r3.u64 | 122;
	// b 0x82108d48
	goto loc_82108D48;
loc_82108B3C:
	// lwz r10,0(r17)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// add r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r31,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r31.u32);
	// b 0x82108b84
	goto loc_82108B84;
loc_82108B4C:
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// bl 0x821080e0
	ctx.lr = 0x82108B54;
	sub_821080E0(ctx, base);
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// beq cr6,0x82108d44
	if (ctx.cr6.eq) goto loc_82108D44;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x82108f48
	ctx.lr = 0x82108B68;
	sub_82108F48(ctx, base);
	// stw r3,4(r16)
	REX_STORE_U32(ctx.r16.u32 + 4, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82108b80
	if (!ctx.cr0.eq) goto loc_82108B80;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x82108d48
	goto loc_82108D48;
loc_82108B80:
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_82108B84:
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82129fa0
	ctx.lr = 0x82108B94;
	sub_82129FA0(ctx, base);
	// mulli r11,r21,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r21.u64 * static_cast<uint64_t>(24));
	// add r28,r11,r31
	ctx.r28.u64 = ctx.r11.u64 + ctx.r31.u64;
	// subf r25,r11,r22
	ctx.r25.u64 = ctx.r22.u64 - ctx.r11.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// lwz r29,0(r19)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// lwz r27,0(r18)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// beq cr6,0x82108d14
	if (ctx.cr6.eq) goto loc_82108D14;
	// mr r23,r21
	ctx.r23.u64 = ctx.r21.u64;
loc_82108BB8:
	// lwz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r8,r29,4
	ctx.r8.s64 = ctx.r29.s64 + 4;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
	// addi r30,r31,20
	ctx.r30.s64 = ctx.r31.s64 + 20;
	// addi r10,r27,-5
	ctx.r10.s64 = ctx.r27.s64 + -5;
	// stw r7,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// lbz r8,4(r29)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r29.u32 + 4);
	// stb r8,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r8.u8);
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// beq cr6,0x82108cf4
	if (ctx.cr6.eq) goto loc_82108CF4;
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// beq cr6,0x82108cdc
	if (ctx.cr6.eq) goto loc_82108CDC;
	// cmpwi cr6,r8,3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3, ctx.xer);
	// beq cr6,0x82108cdc
	if (ctx.cr6.eq) goto loc_82108CDC;
	// cmpwi cr6,r8,4
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 4, ctx.xer);
	// beq cr6,0x82108c50
	if (ctx.cr6.eq) goto loc_82108C50;
	// cmpwi cr6,r8,5
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 5, ctx.xer);
	// beq cr6,0x82108cf4
	if (ctx.cr6.eq) goto loc_82108CF4;
	// cmpwi cr6,r8,6
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 6, ctx.xer);
	// bne cr6,0x82108cdc
	if (!ctx.cr6.eq) goto loc_82108CDC;
	// lhz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r29,r11,2
	ctx.r29.s64 = ctx.r11.s64 + 2;
	// stw r28,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r27,r10,-2
	ctx.r27.s64 = ctx.r10.s64 + -2;
	// addi r26,r9,2
	ctx.r26.s64 = ctx.r9.s64 + 2;
	// bl 0x82129a70
	ctx.lr = 0x82108C3C;
	sub_82129A70(ctx, base);
	// add r29,r30,r29
	ctx.r29.u64 = ctx.r30.u64 + ctx.r29.u64;
	// add r28,r30,r28
	ctx.r28.u64 = ctx.r30.u64 + ctx.r28.u64;
	// subf r25,r30,r25
	ctx.r25.u64 = ctx.r25.u64 - ctx.r30.u64;
	// add r11,r30,r26
	ctx.r11.u64 = ctx.r30.u64 + ctx.r26.u64;
	// b 0x82108d08
	goto loc_82108D08;
loc_82108C50:
	// lhz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// clrlwi. r7,r28,31
	ctx.r7.u64 = ctx.r28.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// addi r26,r11,2
	ctx.r26.s64 = ctx.r11.s64 + 2;
	// addi r27,r10,-2
	ctx.r27.s64 = ctx.r10.s64 + -2;
	// addi r24,r9,2
	ctx.r24.s64 = ctx.r9.s64 + 2;
	// beq 0x82108c6c
	if (ctx.cr0.eq) goto loc_82108C6C;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_82108C6C:
	// stw r28,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// clrlwi r29,r8,16
	ctx.r29.u64 = ctx.r8.u32 & 0xFFFF;
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x82136f70
	ctx.lr = 0x82108C90;
	sub_82136F70(ctx, base);
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r5,0(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// rlwinm r6,r11,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// add r29,r29,r26
	ctx.r29.u64 = ctx.r29.u64 + ctx.r26.u64;
	// subf r25,r11,r25
	ctx.r25.u64 = ctx.r25.u64 - ctx.r11.u64;
	// add r28,r11,r28
	ctx.r28.u64 = ctx.r11.u64 + ctx.r28.u64;
	// bl 0x82136e98
	ctx.lr = 0x82108CD0;
	sub_82136E98(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// b 0x82108d08
	goto loc_82108D08;
loc_82108CDC:
	// ld r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// addi r29,r11,8
	ctx.r29.s64 = ctx.r11.s64 + 8;
	// addi r27,r10,-8
	ctx.r27.s64 = ctx.r10.s64 + -8;
	// addi r11,r9,8
	ctx.r11.s64 = ctx.r9.s64 + 8;
	// std r8,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r8.u64);
	// b 0x82108d08
	goto loc_82108D08;
loc_82108CF4:
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r29,r11,4
	ctx.r29.s64 = ctx.r11.s64 + 4;
	// addi r11,r9,4
	ctx.r11.s64 = ctx.r9.s64 + 4;
	// addi r27,r10,-4
	ctx.r27.s64 = ctx.r10.s64 + -4;
	// stw r8,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
loc_82108D08:
	// addic. r23,r23,-1
	ctx.xer.ca = ctx.r23.u32 > 0;
	ctx.r23.s64 = ctx.r23.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// addi r31,r31,24
	ctx.r31.s64 = ctx.r31.s64 + 24;
	// bne 0x82108bb8
	if (!ctx.cr0.eq) goto loc_82108BB8;
loc_82108D14:
	// cmplwi cr6,r17,0
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 0, ctx.xer);
	// beq cr6,0x82108d34
	if (ctx.cr6.eq) goto loc_82108D34;
	// stw r28,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r28.u32);
	// lwz r11,0(r15)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r15.u32 + 0);
	// subf r11,r22,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r22.u64;
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stw r11,0(r15)
	REX_STORE_U32(ctx.r15.u32 + 0, ctx.r11.u32);
	// b 0x82108d3c
	goto loc_82108D3C;
loc_82108D34:
	// stw r21,0(r16)
	REX_STORE_U32(ctx.r16.u32 + 0, ctx.r21.u32);
	// stw r11,8(r16)
	REX_STORE_U32(ctx.r16.u32 + 8, ctx.r11.u32);
loc_82108D3C:
	// stw r29,0(r19)
	REX_STORE_U32(ctx.r19.u32 + 0, ctx.r29.u32);
	// stw r27,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r27.u32);
loc_82108D44:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82108D48:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129934
	__restgprlr_15(ctx, base);
	return;
}
