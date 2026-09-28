DEFINE_REX_FUNC(sub_82058320) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82058328;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r6,1
	ctx.r6.s64 = 1;
	// lhz r5,52(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// lhz r4,10(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// bl 0x82053c70
	ctx.lr = 0x82058354;
	sub_82053C70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82058434
	if (ctx.cr6.eq) goto loc_82058434;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// lhz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 8);
	// lhz r29,10(r11)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// lwz r3,-6628(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// sth r9,22(r31)
	REX_STORE_U16(ctx.r31.u32 + 22, ctx.r9.u16);
	// bl 0x820a3900
	ctx.lr = 0x82058384;
	sub_820A3900(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r4,-6628(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// beq cr6,0x820583c4
	if (ctx.cr6.eq) goto loc_820583C4;
	// bl 0x820a37b8
	ctx.lr = 0x82058398;
	sub_820A37B8(ctx, base);
	// li r11,7
	ctx.r11.s64 = 7;
	// li r5,15
	ctx.r5.s64 = 15;
	// sth r11,44(r31)
	REX_STORE_U16(ctx.r31.u32 + 44, ctx.r11.u16);
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82054d38
	ctx.lr = 0x820583B0;
	sub_82054D38(ctx, base);
	// lwz r11,-6628(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,140(r11)
	REX_STORE_U32(ctx.r11.u32 + 140, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_820583C4:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// extsh r5,r29
	ctx.r5.s64 = ctx.r29.s16;
	// lhz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 8);
	// addi r10,r11,-5
	ctx.r10.s64 = ctx.r11.s64 + -5;
	// srawi r9,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 2;
	// addze r6,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r6.s64 = temp.s64;
	// bl 0x820a2ed8
	ctx.lr = 0x820583E0;
	sub_820A2ED8(ctx, base);
	// sth r29,30(r31)
	REX_STORE_U16(ctx.r31.u32 + 30, ctx.r29.u16);
	// li r4,37
	ctx.r4.s64 = 37;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053bc8
	ctx.lr = 0x820583F0;
	sub_82053BC8(ctx, base);
	// lhz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82058420
	if (ctx.cr6.lt) goto loc_82058420;
	// beq cr6,0x82058418
	if (ctx.cr6.eq) goto loc_82058418;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x82058410
	if (ctx.cr6.eq) goto loc_82058410;
	// li r4,582
	ctx.r4.s64 = 582;
	// b 0x82058424
	goto loc_82058424;
loc_82058410:
	// li r4,390
	ctx.r4.s64 = 390;
	// b 0x82058424
	goto loc_82058424;
loc_82058418:
	// li r4,389
	ctx.r4.s64 = 389;
	// b 0x82058424
	goto loc_82058424;
loc_82058420:
	// li r4,382
	ctx.r4.s64 = 382;
loc_82058424:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x82058434;
	sub_82067230(ctx, base);
loc_82058434:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
