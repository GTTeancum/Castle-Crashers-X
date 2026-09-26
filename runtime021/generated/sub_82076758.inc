DEFINE_REX_FUNC(sub_82076758) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x82076760;
	__savegprlr_26(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32215
	ctx.r26.s64 = -2111242240;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lbz r11,637(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 637);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x82076ad0
	if (ctx.cr6.gt) goto loc_82076AD0;
	// lis r12,-32249
	ctx.r12.s64 = -2113470464;
	// addi r12,r12,26512
	ctx.r12.s64 = ctx.r12.s64 + 26512;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_820767A0;
	case 1:
		goto loc_820767EC;
	case 2:
		goto loc_8207684C;
	case 3:
		goto loc_820768F4;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_820767A0:
	// li r29,0
	ctx.r29.s64 = 0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r29,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// addi r4,r31,1688
	ctx.r4.s64 = ctx.r31.s64 + 1688;
	// stb r29,100(r1)
	REX_STORE_U8(ctx.r1.u32 + 100, ctx.r29.u8);
	// addi r5,r11,-8128
	ctx.r5.s64 = ctx.r11.s64 + -8128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82075130
	ctx.lr = 0x820767C0;
	sub_82075130(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// bl 0x8209a728
	ctx.lr = 0x820767CC;
	sub_8209A728(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82076ad0
	if (ctx.cr6.eq) goto loc_82076AD0;
	// lbz r11,637(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 637);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r11,637(r26)
	REX_STORE_U8(ctx.r26.u32 + 637, ctx.r11.u8);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_820767EC:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r5,r31,1684
	ctx.r5.s64 = ctx.r31.s64 + 1684;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-6656(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6656);
	// bl 0x82095ff0
	ctx.lr = 0x82076800;
	sub_82095FF0(ctx, base);
	// lhz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r3.u32 + 0);
	// lbz r10,68(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 68);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// sth r9,1752(r31)
	REX_STORE_U16(ctx.r31.u32 + 1752, ctx.r9.u16);
	// lhz r8,2(r3)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r3.u32 + 2);
	// sth r8,1754(r31)
	REX_STORE_U16(ctx.r31.u32 + 1754, ctx.r8.u16);
	// beq cr6,0x82076838
	if (ctx.cr6.eq) goto loc_82076838;
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
	ctx.lr = 0x82076838;
	sub_820B5FE8(ctx, base);
loc_82076838:
	// lbz r11,637(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 637);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r11,637(r26)
	REX_STORE_U8(ctx.r26.u32 + 637, ctx.r11.u8);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_8207684C:
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// lwz r4,1752(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 1752);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-6656(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6656);
	// bl 0x82095da8
	ctx.lr = 0x82076860;
	sub_82095DA8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82076ad0
	if (ctx.cr6.eq) goto loc_82076AD0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-6656(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6656);
	// lwz r4,1752(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 1752);
	// bl 0x82095f18
	ctx.lr = 0x82076878;
	sub_82095F18(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r11,-6644(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6644);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82076890;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r3,104
	ctx.r3.s64 = 104;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// stw r11,-22592(r9)
	REX_STORE_U32(ctx.r9.u32 + -22592, ctx.r11.u32);
	// bl 0x820a7390
	ctx.lr = 0x820768A8;
	sub_820A7390(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820768d8
	if (ctx.cr6.eq) goto loc_820768D8;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r31,1684
	ctx.r5.s64 = ctx.r31.s64 + 1684;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8209dbc0
	ctx.lr = 0x820768C0;
	sub_8209DBC0(ctx, base);
	// lbz r11,637(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 637);
	// stw r3,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r3.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r11,637(r26)
	REX_STORE_U8(ctx.r26.u32 + 637, ctx.r11.u8);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_820768D8:
	// lbz r11,637(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 637);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r3,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r3.u32);
	// stb r11,637(r26)
	REX_STORE_U8(ctx.r26.u32 + 637, ctx.r11.u8);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_820768F4:
	// lwz r3,364(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 364);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82076ad0
	if (ctx.cr6.eq) goto loc_82076AD0;
	// lwz r11,96(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// li r27,1
	ctx.r27.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82076918
	if (ctx.cr6.eq) goto loc_82076918;
	// lbz r11,10345(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 10345);
	// b 0x8207691c
	goto loc_8207691C;
loc_82076918:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8207691C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82076ab8
	if (ctx.cr6.eq) goto loc_82076AB8;
	// lis r30,-32215
	ctx.r30.s64 = -2111242240;
	// lbz r11,638(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 638);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x82076a8c
	if (!ctx.cr6.eq) goto loc_82076A8C;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r10,219
	ctx.r10.s64 = 219;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// sth r10,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r10.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r11,638(r30)
	REX_STORE_U8(ctx.r30.u32 + 638, ctx.r11.u8);
	// addi r30,r31,1672
	ctx.r30.s64 = ctx.r31.s64 + 1672;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82052ea8
	ctx.lr = 0x8207695C;
	sub_82052EA8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r8,220
	ctx.r8.s64 = 220;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r8,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r8.u16);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r29,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r29.u32);
	// bl 0x82052ea8
	ctx.lr = 0x82076978;
	sub_82052EA8(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r28,221
	ctx.r28.s64 = 221;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x820769a8
	if (ctx.cr6.eq) goto loc_820769A8;
	// sth r28,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r28.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82052ea8
	ctx.lr = 0x82076998;
	sub_82052EA8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// bne cr6,0x820769ac
	if (!ctx.cr6.eq) goto loc_820769AC;
loc_820769A8:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_820769AC:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820769c4
	if (!ctx.cr6.eq) goto loc_820769C4;
	// lwz r11,212(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82076ad0
	if (!ctx.cr6.eq) goto loc_82076AD0;
loc_820769C4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82077808
	ctx.lr = 0x820769CC;
	sub_82077808(ctx, base);
	// lwz r11,364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 364);
	// stw r29,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r29.u32);
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r11,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r11.u32);
	// beq cr6,0x82076a08
	if (ctx.cr6.eq) goto loc_82076A08;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r4,-6608(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6608);
	// bl 0x8209c718
	ctx.lr = 0x820769F4;
	sub_8209C718(ctx, base);
	// lwz r4,288(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x820780d8
	ctx.lr = 0x82076A00;
	sub_820780D8(ctx, base);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x820788b8
	ctx.lr = 0x82076A08;
	sub_820788B8(ctx, base);
loc_82076A08:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8209aed8
	ctx.lr = 0x82076A10;
	sub_8209AED8(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820757c8
	ctx.lr = 0x82076A1C;
	sub_820757C8(ctx, base);
	// sth r28,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r28.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82052ea8
	ctx.lr = 0x82076A2C;
	sub_82052EA8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// stw r29,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// stw r29,1776(r31)
	REX_STORE_U32(ctx.r31.u32 + 1776, ctx.r29.u32);
	// stb r27,1772(r31)
	REX_STORE_U8(ctx.r31.u32 + 1772, ctx.r27.u8);
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82076a50
	if (ctx.cr6.eq) goto loc_82076A50;
	// stb r27,1375(r11)
	REX_STORE_U8(ctx.r11.u32 + 1375, ctx.r27.u8);
	// stb r27,1376(r11)
	REX_STORE_U8(ctx.r11.u32 + 1376, ctx.r27.u8);
loc_82076A50:
	// lbz r10,71(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 71);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// stb r11,637(r26)
	REX_STORE_U8(ctx.r26.u32 + 637, ctx.r11.u8);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x82076ad0
	if (!ctx.cr6.eq) goto loc_82076AD0;
	// stb r29,71(r31)
	REX_STORE_U8(ctx.r31.u32 + 71, ctx.r29.u8);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// addi r4,r11,9424
	ctx.r4.s64 = ctx.r11.s64 + 9424;
	// bl 0x82053a00
	ctx.lr = 0x82076A78;
	sub_82053A00(ctx, base);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82077a98
	ctx.lr = 0x82076A84;
	sub_82077A98(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_82076A8C:
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f1,9540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9540);
	ctx.f1.f64 = double(temp.f32);
	// lwz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82076AA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,638(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 638);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stb r8,638(r30)
	REX_STORE_U8(ctx.r30.u32 + 638, ctx.r8.u8);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_82076AB8:
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f1,9540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9540);
	ctx.f1.f64 = double(temp.f32);
	// lwz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82076AD0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82076AD0:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
