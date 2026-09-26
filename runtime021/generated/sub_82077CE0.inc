DEFINE_REX_FUNC(sub_82077CE0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x82077CE8;
	__savegprlr_25(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32215
	ctx.r27.s64 = -2111242240;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// lwz r11,640(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 640);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82077d2c
	if (!ctx.cr6.eq) goto loc_82077D2C;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r29,4
	ctx.r3.s64 = ctx.r29.s64 + 4;
	// bl 0x8209a728
	ctx.lr = 0x82077D14;
	sub_8209A728(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82077f10
	if (ctx.cr6.eq) goto loc_82077F10;
	// lwz r11,640(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 640);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,640(r27)
	REX_STORE_U32(ctx.r27.u32 + 640, ctx.r11.u32);
loc_82077D2C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// addi r4,r11,-8128
	ctx.r4.s64 = ctx.r11.s64 + -8128;
	// bl 0x82053a00
	ctx.lr = 0x82077D3C;
	sub_82053A00(ctx, base);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82075210
	ctx.lr = 0x82077D4C;
	sub_82075210(ctx, base);
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-6656(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + -6656);
	// bl 0x82095ff0
	ctx.lr = 0x82077D60;
	sub_82095FF0(ctx, base);
	// lwz r11,640(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 640);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// lwz r26,80(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bne cr6,0x82077dbc
	if (!ctx.cr6.eq) goto loc_82077DBC;
	// lbz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 68);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x82077d98
	if (ctx.cr6.eq) goto loc_82077D98;
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// stb r11,68(r31)
	REX_STORE_U8(ctx.r31.u32 + 68, ctx.r11.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-6620(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + -6620);
	// bl 0x820b5fe8
	ctx.lr = 0x82077D98;
	sub_820B5FE8(ctx, base);
loc_82077D98:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-6656(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6656);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82095da8
	ctx.lr = 0x82077DA8;
	sub_82095DA8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82077f10
	if (ctx.cr6.eq) goto loc_82077F10;
	// lwz r11,640(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 640);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,640(r27)
	REX_STORE_U32(ctx.r27.u32 + 640, ctx.r11.u32);
loc_82077DBC:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82077f08
	if (!ctx.cr6.eq) goto loc_82077F08;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82077fd8
	ctx.lr = 0x82077DD0;
	sub_82077FD8(ctx, base);
	// lwz r30,-6656(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + -6656);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82096530
	ctx.lr = 0x82077DE4;
	sub_82096530(ctx, base);
	// addi r30,r30,14516
	ctx.r30.s64 = ctx.r30.s64 + 14516;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a434
	ctx.lr = 0x82077DF4;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x820967b0
	ctx.lr = 0x82077DFC;
	sub_820967B0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a444
	ctx.lr = 0x82077E04;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// blt cr6,0x82077e74
	if (ctx.cr6.lt) goto loc_82077E74;
	// mulli r11,r28,76
	ctx.r11.s64 = static_cast<int64_t>(ctx.r28.u64 * static_cast<uint64_t>(76));
	// add r30,r11,r31
	ctx.r30.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r11,136(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 136);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82077e60
	if (!ctx.cr6.eq) goto loc_82077E60;
	// li r3,104
	ctx.r3.s64 = 104;
	// bl 0x820a7390
	ctx.lr = 0x82077E28;
	sub_820A7390(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82077e58
	if (ctx.cr6.eq) goto loc_82077E58;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8209dbc0
	ctx.lr = 0x82077E40;
	sub_8209DBC0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,136(r30)
	REX_STORE_U32(ctx.r30.u32 + 136, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,640(r27)
	REX_STORE_U32(ctx.r27.u32 + 640, ctx.r11.u32);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_82077E58:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,136(r30)
	REX_STORE_U32(ctx.r30.u32 + 136, ctx.r3.u32);
loc_82077E60:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,640(r27)
	REX_STORE_U32(ctx.r27.u32 + 640, ctx.r11.u32);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_82077E74:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// addi r4,r11,-8185
	ctx.r4.s64 = ctx.r11.s64 + -8185;
	// bl 0x82053a00
	ctx.lr = 0x82077E84;
	sub_82053A00(ctx, base);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82077fd8
	ctx.lr = 0x82077E90;
	sub_82077FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r3,104
	ctx.r3.s64 = 104;
	// bl 0x820a7390
	ctx.lr = 0x82077E9C;
	sub_820A7390(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82077ebc
	if (ctx.cr6.eq) goto loc_82077EBC;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8209dbc0
	ctx.lr = 0x82077EB4;
	sub_8209DBC0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// b 0x82077ec0
	goto loc_82077EC0;
loc_82077EBC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82077EC0:
	// mulli r11,r30,76
	ctx.r11.s64 = static_cast<int64_t>(ctx.r30.u64 * static_cast<uint64_t>(76));
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r4,r29,4
	ctx.r4.s64 = ctx.r29.s64 + 4;
	// addi r30,r31,140
	ctx.r30.s64 = ctx.r31.s64 + 140;
	// addi r3,r30,4
	ctx.r3.s64 = ctx.r30.s64 + 4;
	// stw r10,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r10.u32);
	// lwz r5,0(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x82129a70
	ctx.lr = 0x82077EE0;
	sub_82129A70(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// add r9,r11,r30
	ctx.r9.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r11,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,640(r27)
	REX_STORE_U32(ctx.r27.u32 + 640, ctx.r10.u32);
	// stb r8,4(r9)
	REX_STORE_U8(ctx.r9.u32 + 4, ctx.r8.u8);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_82077F08:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,640(r27)
	REX_STORE_U32(ctx.r27.u32 + 640, ctx.r11.u32);
loc_82077F10:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
