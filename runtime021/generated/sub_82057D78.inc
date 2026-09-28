DEFINE_REX_FUNC(sub_82057D78) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x82057D80;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r9,30583
	ctx.r9.s64 = 2004287488;
	// lis r8,-1
	ctx.r8.s64 = -65536;
	// ori r7,r9,30719
	ctx.r7.u64 = ctx.r9.u64 | 30719;
	// li r30,5
	ctx.r30.s64 = 5;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// ori r6,r8,255
	ctx.r6.u64 = ctx.r8.u64 | 255;
	// lhz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// addi r5,r11,5
	ctx.r5.s64 = ctx.r11.s64 + 5;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// stw r7,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// sth r30,8(r10)
	REX_STORE_U16(ctx.r10.u32 + 8, ctx.r30.u16);
	// lwz r11,40(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 40);
	// stw r6,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r6.u32);
	// lhz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82057df0
	if (ctx.cr6.lt) goto loc_82057DF0;
	// beq cr6,0x82057de8
	if (ctx.cr6.eq) goto loc_82057DE8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x82057de0
	if (ctx.cr6.eq) goto loc_82057DE0;
	// li r4,582
	ctx.r4.s64 = 582;
	// b 0x82057df4
	goto loc_82057DF4;
loc_82057DE0:
	// li r4,390
	ctx.r4.s64 = 390;
	// b 0x82057df4
	goto loc_82057DF4;
loc_82057DE8:
	// li r4,389
	ctx.r4.s64 = 389;
	// b 0x82057df4
	goto loc_82057DF4;
loc_82057DF0:
	// li r4,382
	ctx.r4.s64 = 382;
loc_82057DF4:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x82057E04;
	sub_82067230(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r25,0
	ctx.r25.s64 = 0;
	// lhz r10,14(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 14);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r31,356(r11)
	REX_STORE_U32(ctx.r11.u32 + 356, ctx.r31.u32);
	// bne cr6,0x82057e54
	if (!ctx.cr6.eq) goto loc_82057E54;
	// stw r25,372(r11)
	REX_STORE_U32(ctx.r11.u32 + 372, ctx.r25.u32);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r11,288(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 288);
	// lwz r9,56(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82057e4c
	if (ctx.cr6.eq) goto loc_82057E4C;
	// rotlwi r3,r9,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,236(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 236);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82057E4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82057E4C:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82057e90
	goto loc_82057E90;
loc_82057E54:
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r9,r10,-31680
	ctx.r9.s64 = ctx.r10.s64 + -31680;
	// stw r9,372(r11)
	REX_STORE_U32(ctx.r11.u32 + 372, ctx.r9.u32);
	// lwz r8,48(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r11,288(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 288);
	// lwz r7,56(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82057e8c
	if (ctx.cr6.eq) goto loc_82057E8C;
	// rotlwi r3,r7,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,236(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 236);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82057E8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82057E8C:
	// li r4,443
	ctx.r4.s64 = 443;
loc_82057E90:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,288(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// bl 0x82067230
	ctx.lr = 0x82057EA0;
	sub_82067230(ctx, base);
	// mr r26,r25
	ctx.r26.u64 = ctx.r25.u64;
	// mr r27,r25
	ctx.r27.u64 = ctx.r25.u64;
	// li r29,1
	ctx.r29.s64 = 1;
	// lis r24,-32218
	ctx.r24.s64 = -2111438848;
loc_82057EB0:
	// lwz r11,-6628(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// lwz r10,280(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 280);
	// cmplw cr6,r26,r10
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82058020
	if (!ctx.cr6.lt) goto loc_82058020;
	// lhz r10,14(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 14);
	// add r11,r27,r11
	ctx.r11.u64 = ctx.r27.u64 + ctx.r11.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r28,r11,288
	ctx.r28.s64 = ctx.r11.s64 + 288;
	// bne cr6,0x82057f58
	if (!ctx.cr6.eq) goto loc_82057F58;
	// lhz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82057f34
	if (ctx.cr6.lt) goto loc_82057F34;
	// beq cr6,0x82057f10
	if (ctx.cr6.eq) goto loc_82057F10;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x82057f78
	if (!ctx.cr6.eq) goto loc_82057F78;
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// li r4,390
	ctx.r4.s64 = 390;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x82067230
	ctx.lr = 0x82057F0C;
	sub_82067230(ctx, base);
	// b 0x82057f78
	goto loc_82057F78;
loc_82057F10:
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// li r4,389
	ctx.r4.s64 = 389;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x82067230
	ctx.lr = 0x82057F30;
	sub_82067230(ctx, base);
	// b 0x82057f78
	goto loc_82057F78;
loc_82057F34:
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// li r4,382
	ctx.r4.s64 = 382;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x82067230
	ctx.lr = 0x82057F54;
	sub_82067230(ctx, base);
	// b 0x82057f78
	goto loc_82057F78;
loc_82057F58:
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x82067518
	ctx.lr = 0x82057F78;
	sub_82067518(ctx, base);
loc_82057F78:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,44(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 44);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// rlwinm r23,r9,2,0,29
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r23,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + ctx.r10.u32);
	// bl 0x820670f8
	ctx.lr = 0x82057F9C;
	sub_820670F8(ctx, base);
	// addi r8,r30,2
	ctx.r8.s64 = ctx.r30.s64 + 2;
	// lwz r6,48(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,48(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// clrlwi r11,r8,16
	ctx.r11.u64 = ctx.r8.u32 & 0xFFFF;
	// addi r7,r11,5
	ctx.r7.s64 = ctx.r11.s64 + 5;
	// rlwinm r22,r7,2,0,29
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r22,r6
	ctx.r3.u64 = REX_LOAD_U32(ctx.r22.u32 + ctx.r6.u32);
	// bl 0x820670f8
	ctx.lr = 0x82057FC0;
	sub_820670F8(ctx, base);
	// addi r3,r30,3
	ctx.r3.s64 = ctx.r30.s64 + 3;
	// lwz r4,40(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 40);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// addi r11,r11,5
	ctx.r11.s64 = ctx.r11.s64 + 5;
	// rlwinm r28,r11,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r28,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r10.u32);
	// bl 0x820670f8
	ctx.lr = 0x82057FE4;
	sub_820670F8(ctx, base);
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r7,48(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r8,r7
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// stb r25,21(r6)
	REX_STORE_U8(ctx.r6.u32 + 21, ctx.r25.u8);
	// lwz r5,48(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwzx r4,r23,r5
	ctx.r4.u64 = REX_LOAD_U32(ctx.r23.u32 + ctx.r5.u32);
	// stb r29,21(r4)
	REX_STORE_U8(ctx.r4.u32 + 21, ctx.r29.u8);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwzx r11,r22,r3
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + ctx.r3.u32);
	// stb r29,21(r11)
	REX_STORE_U8(ctx.r11.u32 + 21, ctx.r29.u8);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwzx r9,r28,r10
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r10.u32);
	// b 0x820580d8
	goto loc_820580D8;
loc_82058020:
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r28,r9,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r28,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r10.u32);
	// bl 0x82067230
	ctx.lr = 0x82058040;
	sub_82067230(ctx, base);
	// addi r8,r30,1
	ctx.r8.s64 = ctx.r30.s64 + 1;
	// lwz r6,48(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// clrlwi r11,r8,16
	ctx.r11.u64 = ctx.r8.u32 & 0xFFFF;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r7,r11,5
	ctx.r7.s64 = ctx.r11.s64 + 5;
	// rlwinm r23,r7,2,0,29
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r23,r6
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + ctx.r6.u32);
	// bl 0x82067230
	ctx.lr = 0x82058064;
	sub_82067230(ctx, base);
	// addi r4,r30,2
	ctx.r4.s64 = ctx.r30.s64 + 2;
	// li r5,0
	ctx.r5.s64 = 0;
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// rlwinm r22,r3,2,0,29
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwzx r3,r22,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r22.u32 + ctx.r11.u32);
	// bl 0x82067230
	ctx.lr = 0x82058088;
	sub_82067230(ctx, base);
	// addi r10,r30,3
	ctx.r10.s64 = ctx.r30.s64 + 3;
	// lwz r8,48(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// rlwinm r21,r9,2,0,29
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r21,r8
	ctx.r3.u64 = REX_LOAD_U32(ctx.r21.u32 + ctx.r8.u32);
	// bl 0x82067230
	ctx.lr = 0x820580AC;
	sub_82067230(ctx, base);
	// lwz r7,48(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwzx r6,r28,r7
	ctx.r6.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r7.u32);
	// stb r29,21(r6)
	REX_STORE_U8(ctx.r6.u32 + 21, ctx.r29.u8);
	// lwz r5,48(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwzx r4,r23,r5
	ctx.r4.u64 = REX_LOAD_U32(ctx.r23.u32 + ctx.r5.u32);
	// stb r29,21(r4)
	REX_STORE_U8(ctx.r4.u32 + 21, ctx.r29.u8);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwzx r11,r22,r3
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + ctx.r3.u32);
	// stb r29,21(r11)
	REX_STORE_U8(ctx.r11.u32 + 21, ctx.r29.u8);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwzx r9,r21,r10
	ctx.r9.u64 = REX_LOAD_U32(ctx.r21.u32 + ctx.r10.u32);
loc_820580D8:
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// stb r29,21(r9)
	REX_STORE_U8(ctx.r9.u32 + 21, ctx.r29.u8);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r27,r27,56
	ctx.r27.s64 = ctx.r27.s64 + 56;
	// cmplwi cr6,r30,41
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 41, ctx.xer);
	// blt cr6,0x82057eb0
	if (ctx.cr6.lt) goto loc_82057EB0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
