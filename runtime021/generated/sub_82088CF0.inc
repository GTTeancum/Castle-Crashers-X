DEFINE_REX_FUNC(sub_82088CF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x82088CF8;
	__savegprlr_24(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,8248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8248);
	// clrlwi r10,r27,16
	ctx.r10.u64 = ctx.r27.u32 & 0xFFFF;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// addi r9,r11,1998
	ctx.r9.s64 = ctx.r11.s64 + 1998;
	// stw r11,8248(r25)
	REX_STORE_U32(ctx.r25.u32 + 8248, ctx.r11.u32);
	// li r24,0
	ctx.r24.s64 = 0;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r10,128
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 128, ctx.xer);
	// stwx r30,r8,r25
	REX_STORE_U32(ctx.r8.u32 + ctx.r25.u32, ctx.r30.u32);
	// ble cr6,0x82088d50
	if (!ctx.cr6.gt) goto loc_82088D50;
	// cmplwi cr6,r10,175
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 175, ctx.xer);
	// bge cr6,0x82088d50
	if (!ctx.cr6.lt) goto loc_82088D50;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82088d80
	goto loc_82088D80;
loc_82088D50:
	// cmplwi cr6,r10,176
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 176, ctx.xer);
	// ble cr6,0x82088d68
	if (!ctx.cr6.gt) goto loc_82088D68;
	// cmplwi cr6,r10,187
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 187, ctx.xer);
	// bge cr6,0x82088d68
	if (!ctx.cr6.lt) goto loc_82088D68;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82088d80
	goto loc_82088D80;
loc_82088D68:
	// cmplwi cr6,r10,226
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 226, ctx.xer);
	// ble cr6,0x82088d7c
	if (!ctx.cr6.gt) goto loc_82088D7C;
	// cmplwi cr6,r10,229
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 229, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// blt cr6,0x82088d80
	if (ctx.cr6.lt) goto loc_82088D80;
loc_82088D7C:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_82088D80:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82088df0
	if (ctx.cr6.eq) goto loc_82088DF0;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82071280
	ctx.lr = 0x82088DA4;
	sub_82071280(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82088dcc
	if (!ctx.cr6.eq) goto loc_82088DCC;
loc_82088DB0:
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r30,160
	ctx.r3.s64 = ctx.r30.s64 + 160;
	// bl 0x8207b150
	ctx.lr = 0x82088DCC;
	sub_8207B150(ctx, base);
loc_82088DCC:
	// lwz r11,8248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8248);
	// addi r11,r11,1998
	ctx.r11.s64 = ctx.r11.s64 + 1998;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r24,r10,r25
	REX_STORE_U32(ctx.r10.u32 + ctx.r25.u32, ctx.r24.u32);
	// lwz r11,8248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8248);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// stw r9,8248(r25)
	REX_STORE_U32(ctx.r25.u32 + 8248, ctx.r9.u32);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
loc_82088DF0:
	// addi r11,r10,-24
	ctx.r11.s64 = ctx.r10.s64 + -24;
	// cmplwi cr6,r11,42
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 42, ctx.xer);
	// bgt cr6,0x82088db0
	if (ctx.cr6.gt) goto loc_82088DB0;
	// lis r12,-32247
	ctx.r12.s64 = -2113339392;
	// addi r12,r12,-29164
	ctx.r12.s64 = ctx.r12.s64 + -29164;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82088EC0;
	case 1:
		goto loc_82088EE0;
	case 2:
		goto loc_82088F00;
	case 3:
		goto loc_82088F48;
	case 4:
		goto loc_82088F14;
	case 5:
		goto loc_82088F34;
	case 6:
		goto loc_82088F5C;
	case 7:
		goto loc_82088FB8;
	case 8:
		goto loc_82089028;
	case 9:
		goto loc_82089054;
	case 10:
		goto loc_82089084;
	case 11:
		goto loc_82089098;
	case 12:
		goto loc_82089198;
	case 13:
		goto loc_820890C8;
	case 14:
		goto loc_820890F8;
	case 15:
		goto loc_820891B0;
	case 16:
		goto loc_82088DCC;
	case 17:
		goto loc_820891C4;
	case 18:
		goto loc_820891D4;
	case 19:
		goto loc_82088DCC;
	case 20:
		goto loc_82088DCC;
	case 21:
		goto loc_820891E8;
	case 22:
		goto loc_82088DCC;
	case 23:
		goto loc_82089200;
	case 24:
		goto loc_8208921C;
	case 25:
		goto loc_82089234;
	case 26:
		goto loc_8208923C;
	case 27:
		goto loc_82089254;
	case 28:
		goto loc_82089264;
	case 29:
		goto loc_82089280;
	case 30:
		goto loc_82089294;
	case 31:
		goto loc_820892EC;
	case 32:
		goto loc_82089318;
	case 33:
		goto loc_82089344;
	case 34:
		goto loc_82089370;
	case 35:
		goto loc_82089390;
	case 36:
		goto loc_820893A4;
	case 37:
		goto loc_82089420;
	case 38:
		goto loc_82089494;
	case 39:
		goto loc_820894D0;
	case 40:
		goto loc_82089514;
	case 41:
		goto loc_82089528;
	case 42:
		goto loc_820895D0;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82088EC0:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82089668
	ctx.lr = 0x82088ED0;
	sub_82089668(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8206f918
	ctx.lr = 0x82088EDC;
	sub_8206F918(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82088EE0:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8208b7f8
	ctx.lr = 0x82088EF0;
	sub_8208B7F8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8206f918
	ctx.lr = 0x82088EFC;
	sub_8206F918(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82088F00:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8208afc8
	ctx.lr = 0x82088F10;
	sub_8208AFC8(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82088F14:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82089778
	ctx.lr = 0x82088F24;
	sub_82089778(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8206f918
	ctx.lr = 0x82088F30;
	sub_8206F918(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82088F34:
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// stw r11,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r11.u32);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82088F48:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82087160
	ctx.lr = 0x82088F58;
	sub_82087160(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82088F5C:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x82088f98
	if (ctx.cr6.eq) goto loc_82088F98;
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// beq cr6,0x82088f98
	if (ctx.cr6.eq) goto loc_82088F98;
	// bl 0x82082890
	ctx.lr = 0x82088F78;
	sub_82082890(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,120(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82088F90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82088fa0
	goto loc_82088FA0;
loc_82088F98:
	// bl 0x82082bb0
	ctx.lr = 0x82088F9C;
	sub_82082BB0(ctx, base);
	// clrlwi r4,r3,16
	ctx.r4.u64 = ctx.r3.u32 & 0xFFFF;
loc_82088FA0:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,172(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82088FB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82088FB8:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x82088fd4
	if (!ctx.cr6.eq) goto loc_82088FD4;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x82089010
	goto loc_82089010;
loc_82088FD4:
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x82089008
	if (ctx.cr6.eq) goto loc_82089008;
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// beq cr6,0x82089008
	if (ctx.cr6.eq) goto loc_82089008;
	// bl 0x82082890
	ctx.lr = 0x82088FE8;
	sub_82082890(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,120(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82089000;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82089010
	goto loc_82089010;
loc_82089008:
	// bl 0x82082bb0
	ctx.lr = 0x8208900C;
	sub_82082BB0(ctx, base);
	// clrlwi r4,r3,16
	ctx.r4.u64 = ctx.r3.u32 & 0xFFFF;
loc_82089010:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,164(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82089024;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089028:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82089044;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stb r3,4(r28)
	REX_STORE_U8(ctx.r28.u32 + 4, ctx.r3.u8);
	// stw r9,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r9.u32);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089054:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x82088dcc
	if (ctx.cr6.eq) goto loc_82088DCC;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x82088dcc
	if (ctx.cr6.eq) goto loc_82088DCC;
	// bl 0x82082890
	ctx.lr = 0x82089074;
	sub_82082890(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82087ad8
	ctx.lr = 0x82089080;
	sub_82087AD8(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089084:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82086ff0
	ctx.lr = 0x82089094;
	sub_82086FF0(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089098:
	// lhz r11,146(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 146);
	// lhz r10,148(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 148);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r4,r9,16
	ctx.r4.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r4,r10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82088dcc
	if (ctx.cr6.gt) goto loc_82088DCC;
	// lbz r11,140(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 140);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// ori r10,r11,2
	ctx.r10.u64 = ctx.r11.u64 | 2;
	// stb r10,140(r30)
	REX_STORE_U8(ctx.r30.u32 + 140, ctx.r10.u8);
	// bl 0x82087f70
	ctx.lr = 0x820890C4;
	sub_82087F70(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_820890C8:
	// lhz r11,146(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 146);
	// addis r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi r4,r10,16
	ctx.r4.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82088dcc
	if (ctx.cr6.eq) goto loc_82088DCC;
	// lbz r11,140(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 140);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// ori r10,r11,2
	ctx.r10.u64 = ctx.r11.u64 | 2;
	// stb r10,140(r30)
	REX_STORE_U8(ctx.r30.u32 + 140, ctx.r10.u8);
	// bl 0x82087f70
	ctx.lr = 0x820890F4;
	sub_82087F70(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_820890F8:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x8208912c
	if (!ctx.cr6.eq) goto loc_8208912C;
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x82088dcc
	if (ctx.cr6.lt) goto loc_82088DCC;
	// lwz r3,96(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 96);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82089120;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82084d18
	ctx.lr = 0x82089128;
	sub_82084D18(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_8208912C:
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// bne cr6,0x82088dcc
	if (!ctx.cr6.eq) goto loc_82088DCC;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// and r9,r11,r12
	ctx.r9.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82089158
	if (ctx.cr6.eq) goto loc_82089158;
	// lwz r4,4(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x82089180
	goto loc_82089180;
loc_82089158:
	// lis r9,-32768
	ctx.r9.s64 = -2147483648;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8208917c
	if (ctx.cr6.eq) goto loc_8208917C;
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// beq cr6,0x82089174
	if (ctx.cr6.eq) goto loc_82089174;
	// cmplwi cr6,r11,8192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8192, ctx.xer);
	// bne cr6,0x8208917c
	if (!ctx.cr6.eq) goto loc_8208917C;
loc_82089174:
	// lwz r4,4(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x82089180
	goto loc_82089180;
loc_8208917C:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_82089180:
	// lwz r11,28(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x82088dcc
	if (ctx.cr6.lt) goto loc_82088DCC;
	// addi r3,r30,104
	ctx.r3.s64 = ctx.r30.s64 + 104;
	// bl 0x82084d18
	ctx.lr = 0x82089194;
	sub_82084D18(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089198:
	// lbz r11,140(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 140);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r10,r10,0,31,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF9;
	// ori r9,r10,4
	ctx.r9.u64 = ctx.r10.u64 | 4;
	// stb r9,140(r30)
	REX_STORE_U8(ctx.r30.u32 + 140, ctx.r9.u8);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_820891B0:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820877a0
	ctx.lr = 0x820891C0;
	sub_820877A0(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_820891C4:
	// lbz r11,140(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 140);
	// ori r10,r11,2
	ctx.r10.u64 = ctx.r11.u64 | 2;
	// stb r10,140(r30)
	REX_STORE_U8(ctx.r30.u32 + 140, ctx.r10.u8);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_820891D4:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820879a0
	ctx.lr = 0x820891E4;
	sub_820879A0(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_820891E8:
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820868d8
	ctx.lr = 0x820891FC;
	sub_820868D8(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089200:
	// lwz r11,72(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 72);
	// li r10,4
	ctx.r10.s64 = 4;
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,272(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 272);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_8208921C:
	// lbz r11,140(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 140);
	// li r10,2
	ctx.r10.s64 = 2;
	// rlwinm r9,r11,25,7,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1FFFFFF;
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// stb r9,4(r28)
	REX_STORE_U8(ctx.r28.u32 + 4, ctx.r9.u8);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089234:
	// stw r24,152(r30)
	REX_STORE_U32(ctx.r30.u32 + 152, ctx.r24.u32);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_8208923C:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082670
	ctx.lr = 0x82089244;
	sub_82082670(ctx, base);
	// lbz r11,140(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 140);
	// rlwimi r11,r3,7,17,24
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 7) & 0x7F80) | (ctx.r11.u64 & 0xFFFFFFFFFFFF807F);
	// stb r11,140(r30)
	REX_STORE_U8(ctx.r30.u32 + 140, ctx.r11.u8);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089254:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x8208925C;
	sub_82082BB0(ctx, base);
	// stb r3,103(r25)
	REX_STORE_U8(ctx.r25.u32 + 103, ctx.r3.u8);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089264:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x8208926C;
	sub_82082BB0(ctx, base);
	// lwz r11,72(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82088dcc
	if (ctx.cr6.eq) goto loc_82088DCC;
	// stw r3,272(r11)
	REX_STORE_U32(ctx.r11.u32 + 272, ctx.r3.u32);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089280:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82089ab8
	ctx.lr = 0x82089290;
	sub_82089AB8(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089294:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x8208929C;
	sub_82082BB0(ctx, base);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// std r9,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r9.u64);
	// lfd f0,152(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lis r8,-32218
	ctx.r8.s64 = -2111438848;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f13,9724(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9724);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,-6612(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -6612);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// lfs f11,108(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 108);
	ctx.f11.f64 = double(temp.f32);
	// stb r6,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r6.u8);
	// lfs f0,9536(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 116, temp.u32);
	// stfs f11,112(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 112, temp.u32);
	// fmuls f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fdivs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// stfs f9,120(r11)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + 120, temp.u32);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_820892EC:
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r11,4
	ctx.r11.s64 = 4;
	// lwz r10,-6612(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -6612);
	// lfs f0,18236(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18236);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,100(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctidz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfiwx f11,r28,r11
	REX_STORE_U32(ctx.r28.u32 + ctx.r11.u32, ctx.f11.u32);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089318:
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r11,4
	ctx.r11.s64 = 4;
	// lwz r10,-6612(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -6612);
	// lfs f0,18236(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18236);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,108(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctidz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfiwx f11,r28,r11
	REX_STORE_U32(ctx.r28.u32 + ctx.r11.u32, ctx.f11.u32);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089344:
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r11,4
	ctx.r11.s64 = 4;
	// lwz r10,-6612(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -6612);
	// lfs f0,18236(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18236);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,104(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctidz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfiwx f11,r28,r11
	REX_STORE_U32(ctx.r28.u32 + ctx.r11.u32, ctx.f11.u32);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089370:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082670
	ctx.lr = 0x82089378;
	sub_82082670(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// lwz r4,-6612(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6612);
	// bl 0x82097198
	ctx.lr = 0x8208938C;
	sub_82097198(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089390:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820899d0
	ctx.lr = 0x820893A0;
	sub_820899D0(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_820893A4:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x820893AC;
	sub_82082BB0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r30,10316(r25)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r25.u32 + 10316);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82082890
	ctx.lr = 0x820893BC;
	sub_82082890(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820893d0
	if (!ctx.cr6.eq) goto loc_820893D0;
	// addi r4,r30,12
	ctx.r4.s64 = ctx.r30.s64 + 12;
	// b 0x820893dc
	goto loc_820893DC;
loc_820893D0:
	// lwz r10,28(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r9
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
loc_820893DC:
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82053a00
	ctx.lr = 0x820893E4;
	sub_82053A00(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r11,-6612(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6612);
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82089408
	if (!ctx.cr6.eq) goto loc_82089408;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-1080
	ctx.r3.s64 = ctx.r11.s64 + -1080;
	// bl 0x8208c5d8
	ctx.lr = 0x82089404;
	sub_8208C5D8(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089408:
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// bl 0x8209ed28
	ctx.lr = 0x8208941C;
	sub_8209ED28(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089420:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x82089428;
	sub_82082BB0(ctx, base);
	// clrldi r11,r3,32
	ctx.r11.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// std r11,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r11.u64);
	// lfd f0,152(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,9588(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9588);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,-6612(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -6612);
	// lfs f11,100(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// beq cr6,0x82088dcc
	if (ctx.cr6.eq) goto loc_82088DCC;
	// lwz r10,92(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// stfs f0,100(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 100, temp.u32);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x82088dcc
	if (!ctx.cr6.eq) goto loc_82088DCC;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lfs f13,108(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lwz r11,5376(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 5376);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82088dcc
	if (ctx.cr6.eq) goto loc_82088DCC;
	// stfs f1,5384(r10)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r10.u32 + 5384, temp.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x820d8430
	ctx.lr = 0x82089490;
	sub_820D8430(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089494:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x8208949C;
	sub_82082BB0(ctx, base);
	// clrldi r11,r3,32
	ctx.r11.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// std r11,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r11.u64);
	// lfd f13,152(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lfs f0,9588(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9588);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r4,-6612(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + -6612);
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// bl 0x82097560
	ctx.lr = 0x820894CC;
	sub_82097560(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_820894D0:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x820894D8;
	sub_82082BB0(ctx, base);
	// clrldi r11,r3,32
	ctx.r11.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// std r11,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r11.u64);
	// lfd f12,152(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// lfs f0,9588(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9588);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,-6612(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -6612);
	// lfs f13,104(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f10,f0
	ctx.f0.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// beq cr6,0x82088dcc
	if (ctx.cr6.eq) goto loc_82088DCC;
	// stfs f0,104(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 104, temp.u32);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089514:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r4,-6612(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6612);
	// bl 0x820970d0
	ctx.lr = 0x82089524;
	sub_820970D0(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_82089528:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x82089530;
	sub_82082BB0(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bge cr6,0x8208954c
	if (!ctx.cr6.lt) goto loc_8208954C;
loc_8208953C:
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r24,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r24.u32);
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_8208954C:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// lwz r7,-6596(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// bne cr6,0x8208957c
	if (!ctx.cr6.eq) goto loc_8208957C;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82082848
	ctx.lr = 0x82089564;
	sub_82082848(ctx, base);
	// addi r11,r6,5
	ctx.r11.s64 = ctx.r6.s64 + 5;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwzx r4,r10,r7
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// bl 0x8209d3d8
	ctx.lr = 0x8208957C;
	sub_8209D3D8(ctx, base);
loc_8208957C:
	// addi r11,r6,5
	ctx.r11.s64 = ctx.r6.s64 + 5;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// lwzx r4,r10,r7
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// bl 0x8209d488
	ctx.lr = 0x82089594;
	sub_8209D488(ctx, base);
	// lwz r9,152(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x820895bc
	if (!ctx.cr6.eq) goto loc_820895BC;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-6512
	ctx.r3.s64 = ctx.r11.s64 + -6512;
	// bl 0x8208c5d8
	ctx.lr = 0x820895AC;
	sub_8208C5D8(ctx, base);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r24,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r24.u32);
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_820895BC:
	// lbz r9,144(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 144);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// stw r9,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r9.u32);
	// b 0x82088dcc
	goto loc_82088DCC;
loc_820895D0:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x820895D8;
	sub_82082BB0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82088dcc
	if (ctx.cr6.lt) goto loc_82088DCC;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// lwz r6,-6596(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// bne cr6,0x82089604
	if (!ctx.cr6.eq) goto loc_82089604;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82082848
	ctx.lr = 0x820895FC;
	sub_82082848(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// b 0x82089630
	goto loc_82089630;
loc_82089604:
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82082848
	ctx.lr = 0x8208960C;
	sub_82082848(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82082848
	ctx.lr = 0x82089618;
	sub_82082848(ctx, base);
	// addi r11,r30,5
	ctx.r11.s64 = ctx.r30.s64 + 5;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwzx r4,r10,r6
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// bl 0x8209d3d8
	ctx.lr = 0x82089630;
	sub_8209D3D8(ctx, base);
loc_82089630:
	// addi r11,r30,5
	ctx.r11.s64 = ctx.r30.s64 + 5;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// lwzx r4,r10,r6
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// bl 0x8209d538
	ctx.lr = 0x82089648;
	sub_8209D538(ctx, base);
	// lwz r9,152(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x8208953c
	if (!ctx.cr6.eq) goto loc_8208953C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-6484
	ctx.r3.s64 = ctx.r11.s64 + -6484;
	// bl 0x8208c5d8
	ctx.lr = 0x82089660;
	sub_8208C5D8(ctx, base);
	// b 0x82088dcc
	goto loc_82088DCC;
}
