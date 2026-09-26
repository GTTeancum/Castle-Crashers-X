DEFINE_REX_FUNC(sub_82076F08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x82076F10;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r11,72(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 72);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82076fe0
	if (ctx.cr6.eq) goto loc_82076FE0;
	// lwz r11,1656(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 1656);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82076f68
	if (!ctx.cr6.eq) goto loc_82076F68;
	// li r11,213
	ctx.r11.s64 = 213;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r11,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r11.u16);
	// addi r3,r29,1672
	ctx.r3.s64 = ctx.r29.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x82076F48;
	sub_82052EA8(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82076f68
	if (!ctx.cr6.eq) goto loc_82076F68;
	// li r6,2
	ctx.r6.s64 = 2;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82077310
	ctx.lr = 0x82076F68;
	sub_82077310(ctx, base);
loc_82076F68:
	// lis r31,-32218
	ctx.r31.s64 = -2111438848;
	// lwz r11,-6628(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -6628);
	// lbz r10,29(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 29);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82076f94
	if (!ctx.cr6.eq) goto loc_82076F94;
	// li r6,2
	ctx.r6.s64 = 2;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82077310
	ctx.lr = 0x82076F90;
	sub_82077310(ctx, base);
	// lwz r11,-6628(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -6628);
loc_82076F94:
	// lbz r11,180(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 180);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820772a8
	if (ctx.cr6.eq) goto loc_820772A8;
	// li r11,223
	ctx.r11.s64 = 223;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r11,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r11.u16);
	// addi r3,r29,1672
	ctx.r3.s64 = ctx.r29.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x82076FB4;
	sub_82052EA8(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820772a8
	if (ctx.cr6.eq) goto loc_820772A8;
	// lwz r11,-6628(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -6628);
	// li r6,8
	ctx.r6.s64 = 8;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,184(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// bl 0x82077310
	ctx.lr = 0x82076FD8;
	sub_82077310(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_82076FE0:
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82077014
	if (ctx.cr6.eq) goto loc_82077014;
	// lwz r11,1656(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 1656);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820772a8
	if (!ctx.cr6.eq) goto loc_820772A8;
	// li r6,16
	ctx.r6.s64 = 16;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r5,-1
	ctx.r5.s64 = -1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82077310
	ctx.lr = 0x8207700C;
	sub_82077310(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_82077014:
	// rlwinm r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82077050
	if (ctx.cr6.eq) goto loc_82077050;
	// lwz r11,1656(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 1656);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820772a8
	if (!ctx.cr6.eq) goto loc_820772A8;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r6,8
	ctx.r6.s64 = 8;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lwz r5,184(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// bl 0x82077310
	ctx.lr = 0x82077048;
	sub_82077310(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_82077050:
	// lis r25,-32218
	ctx.r25.s64 = -2111438848;
	// lwz r11,-6628(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6628);
	// lwz r10,140(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// bne cr6,0x82077134
	if (!ctx.cr6.eq) goto loc_82077134;
	// li r11,208
	ctx.r11.s64 = 208;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r11,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r11.u16);
	// addi r3,r29,1672
	ctx.r3.s64 = ctx.r29.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x82077078;
	sub_82052EA8(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82077128
	if (!ctx.cr6.eq) goto loc_82077128;
	// lwz r31,1660(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 1660);
	// li r30,-1
	ctx.r30.s64 = -1;
	// lwz r11,1656(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 1656);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x820770c0
	if (ctx.cr6.eq) goto loc_820770C0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8206dd58
	ctx.lr = 0x820770A4;
	sub_8206DD58(ctx, base);
	// lwz r3,136(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 136);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820770BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820770c8
	goto loc_820770C8;
loc_820770C0:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lhz r30,12(r11)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r11.u32 + 12);
loc_820770C8:
	// li r4,17
	ctx.r4.s64 = 17;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053bc8
	ctx.lr = 0x820770D4;
	sub_82053BC8(ctx, base);
	// lwz r11,-6628(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6628);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,144
	ctx.r4.s64 = ctx.r11.s64 + 144;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// sth r30,12(r11)
	REX_STORE_U16(ctx.r11.u32 + 12, ctx.r30.u16);
	// sth r30,10(r11)
	REX_STORE_U16(ctx.r11.u32 + 10, ctx.r30.u16);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r3,20(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x82067518
	ctx.lr = 0x820770F8;
	sub_82067518(ctx, base);
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 24);
	// li r4,482
	ctx.r4.s64 = 482;
	// bl 0x82067230
	ctx.lr = 0x8207710C;
	sub_82067230(ctx, base);
	// lwz r8,4(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,76(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 76);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,164(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 164);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82077128;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82077128:
	// lwz r11,-6628(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6628);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,140(r11)
	REX_STORE_U32(ctx.r11.u32 + 140, ctx.r10.u32);
loc_82077134:
	// lwz r11,-6628(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6628);
	// lbz r10,29(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 29);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82077194
	if (ctx.cr6.eq) goto loc_82077194;
	// li r11,213
	ctx.r11.s64 = 213;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r11,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r11.u16);
	// addi r3,r29,1672
	ctx.r3.s64 = ctx.r29.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x82077158;
	sub_82052EA8(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82077178
	if (ctx.cr6.eq) goto loc_82077178;
	// lwz r11,72(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 72);
	// ori r10,r11,2
	ctx.r10.u64 = ctx.r11.u64 | 2;
	// stw r10,72(r29)
	REX_STORE_U32(ctx.r29.u32 + 72, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_82077178:
	// li r6,2
	ctx.r6.s64 = 2;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r5,-1
	ctx.r5.s64 = -1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82077310
	ctx.lr = 0x8207718C;
	sub_82077310(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_82077194:
	// li r27,0
	ctx.r27.s64 = 0;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r26,213
	ctx.r26.s64 = 213;
loc_820771A4:
	// lwz r11,1756(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 1756);
	// lwzx r10,r28,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8207726c
	if (ctx.cr6.eq) goto loc_8207726C;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,-6628(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + -6628);
	// bl 0x820a39f0
	ctx.lr = 0x820771C0;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207726c
	if (ctx.cr6.eq) goto loc_8207726C;
	// lwz r11,1756(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 1756);
	// lwzx r3,r28,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// bl 0x82078d90
	ctx.lr = 0x820771D8;
	sub_82078D90(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82077200
	if (ctx.cr6.eq) goto loc_82077200;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820771FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82077204
	goto loc_82077204;
loc_82077200:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82077204:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82077254
	if (ctx.cr6.eq) goto loc_82077254;
	// sth r26,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r26.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r29,1672
	ctx.r3.s64 = ctx.r29.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x82077220;
	sub_82052EA8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8207726c
	if (!ctx.cr6.eq) goto loc_8207726C;
	// lbz r11,238(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 238);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq cr6,0x82077240
	if (ctx.cr6.eq) goto loc_82077240;
	// lbz r11,242(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 242);
loc_82077240:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207726c
	if (ctx.cr6.eq) goto loc_8207726C;
	// li r6,1
	ctx.r6.s64 = 1;
	// b 0x8207725c
	goto loc_8207725C;
loc_82077254:
	// li r6,5
	ctx.r6.s64 = 5;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
loc_8207725C:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82077310
	ctx.lr = 0x8207726C;
	sub_82077310(ctx, base);
loc_8207726C:
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r28,16
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 16, ctx.xer);
	// blt cr6,0x820771a4
	if (ctx.cr6.lt) goto loc_820771A4;
	// lwz r11,72(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 72);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820772a8
	if (ctx.cr6.eq) goto loc_820772A8;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x820772a8
	if (!ctx.cr6.eq) goto loc_820772A8;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r5,-1
	ctx.r5.s64 = -1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82077310
	ctx.lr = 0x820772A8;
	sub_82077310(ctx, base);
loc_820772A8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
