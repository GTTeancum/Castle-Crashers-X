DEFINE_REX_FUNC(sub_82054DD8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x82054DE0;
	__savegprlr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r26,0
	ctx.r26.s64 = 0;
	// lhz r11,46(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 46);
	// lwz r27,48(r28)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// bgt cr6,0x82054fa4
	if (ctx.cr6.gt) goto loc_82054FA4;
	// lis r12,-32251
	ctx.r12.s64 = -2113601536;
	// addi r12,r12,20004
	ctx.r12.s64 = ctx.r12.s64 + 20004;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82054E54;
	case 1:
		goto loc_82054E60;
	case 2:
		goto loc_82054E78;
	case 3:
		goto loc_82054E6C;
	case 4:
		goto loc_82054F40;
	case 5:
		goto loc_82054ED8;
	case 6:
		goto loc_82054EA8;
	case 7:
		goto loc_82054FA4;
	case 8:
		goto loc_82054FA4;
	case 9:
		goto loc_82054EB8;
	case 10:
		goto loc_82054EC0;
	case 11:
		goto loc_82054ECC;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82054E54:
	// li r31,510
	ctx.r31.s64 = 510;
	// li r30,511
	ctx.r30.s64 = 511;
	// b 0x82054fa4
	goto loc_82054FA4;
loc_82054E60:
	// li r31,512
	ctx.r31.s64 = 512;
	// li r30,513
	ctx.r30.s64 = 513;
	// b 0x82054fa4
	goto loc_82054FA4;
loc_82054E6C:
	// li r31,517
	ctx.r31.s64 = 517;
	// li r30,518
	ctx.r30.s64 = 518;
	// b 0x82054fa4
	goto loc_82054FA4;
loc_82054E78:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// li r31,480
	ctx.r31.s64 = 480;
	// li r30,481
	ctx.r30.s64 = 481;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82054E94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x82054fa4
	if (ctx.cr6.eq) goto loc_82054FA4;
	// li r29,508
	ctx.r29.s64 = 508;
	// li r26,509
	ctx.r26.s64 = 509;
	// b 0x82054fa4
	goto loc_82054FA4;
loc_82054EA8:
	// li r31,472
	ctx.r31.s64 = 472;
	// li r30,522
	ctx.r30.s64 = 522;
	// li r29,523
	ctx.r29.s64 = 523;
	// b 0x82054fa4
	goto loc_82054FA4;
loc_82054EB8:
	// li r31,485
	ctx.r31.s64 = 485;
	// b 0x82054fa4
	goto loc_82054FA4;
loc_82054EC0:
	// li r31,587
	ctx.r31.s64 = 587;
	// li r30,588
	ctx.r30.s64 = 588;
	// b 0x82054fa4
	goto loc_82054FA4;
loc_82054ECC:
	// li r31,609
	ctx.r31.s64 = 609;
	// li r30,610
	ctx.r30.s64 = 610;
	// b 0x82054fa4
	goto loc_82054FA4;
loc_82054ED8:
	// lhz r11,44(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 44);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// bgt cr6,0x82054fa4
	if (ctx.cr6.gt) goto loc_82054FA4;
	// lis r12,-32251
	ctx.r12.s64 = -2113601536;
	// addi r12,r12,20224
	ctx.r12.s64 = ctx.r12.s64 + 20224;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82054F30;
	case 1:
		goto loc_82054F50;
	case 2:
		goto loc_82054F50;
	case 3:
		goto loc_82054F50;
	case 4:
		goto loc_82054F38;
	case 5:
		goto loc_82054F40;
	case 6:
		goto loc_82054F50;
	case 7:
		goto loc_82054FA4;
	case 8:
		goto loc_82054F58;
	case 9:
		goto loc_82054F9C;
	case 10:
		goto loc_82054F80;
	case 11:
		goto loc_82054F64;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82054F30:
	// li r31,471
	ctx.r31.s64 = 471;
	// b 0x82054fa4
	goto loc_82054FA4;
loc_82054F38:
	// li r31,479
	ctx.r31.s64 = 479;
	// b 0x82054fa4
	goto loc_82054FA4;
loc_82054F40:
	// li r31,514
	ctx.r31.s64 = 514;
	// li r30,515
	ctx.r30.s64 = 515;
	// li r29,516
	ctx.r29.s64 = 516;
	// b 0x82054fa4
	goto loc_82054FA4;
loc_82054F50:
	// li r31,473
	ctx.r31.s64 = 473;
	// b 0x82054fa4
	goto loc_82054FA4;
loc_82054F58:
	// li r31,483
	ctx.r31.s64 = 483;
	// li r30,484
	ctx.r30.s64 = 484;
	// b 0x82054fa4
	goto loc_82054FA4;
loc_82054F64:
	// li r31,472
	ctx.r31.s64 = 472;
	// bl 0x820fbf88
	ctx.lr = 0x82054F6C;
	sub_820FBF88(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x82054fa4
	if (ctx.cr6.eq) goto loc_82054FA4;
	// li r30,522
	ctx.r30.s64 = 522;
	// li r29,523
	ctx.r29.s64 = 523;
	// b 0x82054fa4
	goto loc_82054FA4;
loc_82054F80:
	// li r31,485
	ctx.r31.s64 = 485;
	// bl 0x820fbf88
	ctx.lr = 0x82054F88;
	sub_820FBF88(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x82054fa4
	if (ctx.cr6.eq) goto loc_82054FA4;
	// li r30,522
	ctx.r30.s64 = 522;
	// li r29,523
	ctx.r29.s64 = 523;
	// b 0x82054fa4
	goto loc_82054FA4;
loc_82054F9C:
	// li r31,480
	ctx.r31.s64 = 480;
	// li r30,481
	ctx.r30.s64 = 481;
loc_82054FA4:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 20);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x82054FB4;
	sub_82067230(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,24(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// bl 0x82067230
	ctx.lr = 0x82054FC4;
	sub_82067230(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,28(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 28);
	// bl 0x82067230
	ctx.lr = 0x82054FD4;
	sub_82067230(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r3,32(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 32);
	// bl 0x82067230
	ctx.lr = 0x82054FE4;
	sub_82067230(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,36(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 36);
	// bl 0x82067230
	ctx.lr = 0x82054FF4;
	sub_82067230(ctx, base);
	// lis r26,-32218
	ctx.r26.s64 = -2111438848;
	// lwz r11,-6628(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6628);
	// lbz r11,29(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 29);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82055118
	if (!ctx.cr6.eq) goto loc_82055118;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// li r30,-2
	ctx.r30.s64 = -2;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82055020;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x82055030
	if (!ctx.cr6.eq) goto loc_82055030;
	// lwz r11,48(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// lhz r30,10(r11)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
loc_82055030:
	// lis r31,-32215
	ctx.r31.s64 = -2111242240;
	// lwz r11,592(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 592);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,592(r31)
	REX_STORE_U32(ctx.r31.u32 + 592, ctx.r11.u32);
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// ble cr6,0x82055118
	if (!ctx.cr6.gt) goto loc_82055118;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82065898
	ctx.lr = 0x82055054;
	sub_82065898(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82055118
	if (ctx.cr6.eq) goto loc_82055118;
	// lhz r29,388(r27)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r27.u32 + 388);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// stw r11,592(r31)
	REX_STORE_U32(ctx.r31.u32 + 592, ctx.r11.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820550e0
	if (ctx.cr6.eq) goto loc_820550E0;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8205508C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r31,-1
	ctx.r31.s64 = -1;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x820550a0
	if (ctx.cr6.eq) goto loc_820550A0;
	// lwz r11,48(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// sth r31,10(r11)
	REX_STORE_U16(ctx.r11.u32 + 10, ctx.r31.u16);
loc_820550A0:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82053bc8
	ctx.lr = 0x820550AC;
	sub_82053BC8(ctx, base);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820550C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x82055118
	if (ctx.cr6.eq) goto loc_82055118;
	// lwz r11,56(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 56);
	// mulli r10,r30,436
	ctx.r10.s64 = static_cast<int64_t>(ctx.r30.u64 * static_cast<uint64_t>(436));
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// sth r31,10(r11)
	REX_STORE_U16(ctx.r11.u32 + 10, ctx.r31.u16);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_820550E0:
	// lhz r11,46(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 46);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bne cr6,0x82055118
	if (!ctx.cr6.eq) goto loc_82055118;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-6628(r26)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + -6628);
	// bl 0x820a37b8
	ctx.lr = 0x820550F8;
	sub_820A37B8(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,9424
	ctx.r4.s64 = ctx.r11.s64 + 9424;
	// bl 0x82053a00
	ctx.lr = 0x82055108;
	sub_82053A00(ctx, base);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,-6624(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + -6624);
	// bl 0x82077a98
	ctx.lr = 0x82055118;
	sub_82077A98(ctx, base);
loc_82055118:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
