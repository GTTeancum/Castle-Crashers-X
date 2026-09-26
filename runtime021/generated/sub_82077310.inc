DEFINE_REX_FUNC(sub_82077310) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82077318;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r4,24
	ctx.r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207753c
	if (ctx.cr6.eq) goto loc_8207753C;
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820776cc
	if (!ctx.cr6.eq) goto loc_820776CC;
	// or r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 | ctx.r29.u64;
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// lwz r10,288(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820776cc
	if (ctx.cr6.eq) goto loc_820776CC;
	// lhz r11,1664(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1664);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820776cc
	if (!ctx.cr6.eq) goto loc_820776CC;
	// lwz r11,1656(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1656);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207737c
	if (ctx.cr6.eq) goto loc_8207737C;
	// lwz r10,1660(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1660);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820776cc
	if (!ctx.cr6.eq) goto loc_820776CC;
loc_8207737C:
	// lwz r30,1756(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 1756);
	// li r27,0
	ctx.r27.s64 = 0;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// blt cr6,0x820773e0
	if (ctx.cr6.lt) goto loc_820773E0;
	// li r11,214
	ctx.r11.s64 = 214;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// sth r11,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r11.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,-6624(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x820773A8;
	sub_82052EA8(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// stw r28,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r28.u32);
	// stw r28,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r28.u32);
	// lwz r11,-6652(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -6652);
	// lbz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x820773cc
	if (!ctx.cr6.eq) goto loc_820773CC;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// b 0x820773d8
	goto loc_820773D8;
loc_820773CC:
	// addi r10,r28,2
	ctx.r10.s64 = ctx.r28.s64 + 2;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
loc_820773D8:
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r10,35(r11)
	REX_STORE_U8(ctx.r11.u32 + 35, ctx.r10.u8);
loc_820773E0:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f1,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82078fe8
	ctx.lr = 0x820773F8;
	sub_82078FE8(ctx, base);
	// lwz r4,1660(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 1660);
	// lwz r10,1656(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1656);
	// cmplw cr6,r10,r4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x82077428
	if (ctx.cr6.eq) goto loc_82077428;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8206dd58
	ctx.lr = 0x82077410;
	sub_8206DD58(ctx, base);
	// lwz r3,136(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82077428;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82077428:
	// lwz r30,1660(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 1660);
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82053bc8
	ctx.lr = 0x82077438;
	sub_82053BC8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8206c1d0
	ctx.lr = 0x82077444;
	sub_8206C1D0(ctx, base);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// blt cr6,0x82077488
	if (ctx.cr6.lt) goto loc_82077488;
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82077474
	if (!ctx.cr6.eq) goto loc_82077474;
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82077474
	if (!ctx.cr6.eq) goto loc_82077474;
	// rlwinm r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82077488
	if (ctx.cr6.eq) goto loc_82077488;
loc_82077474:
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// extsh r10,r28
	ctx.r10.s64 = ctx.r28.s16;
	// sth r10,12(r11)
	REX_STORE_U16(ctx.r11.u32 + 12, ctx.r10.u16);
	// sth r10,10(r11)
	REX_STORE_U16(ctx.r11.u32 + 10, ctx.r10.u16);
	// b 0x82077498
	goto loc_82077498;
loc_82077488:
	// lwz r10,48(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// li r11,-1
	ctx.r11.s64 = -1;
	// sth r11,12(r10)
	REX_STORE_U16(ctx.r10.u32 + 12, ctx.r11.u16);
	// sth r11,10(r10)
	REX_STORE_U16(ctx.r10.u32 + 10, ctx.r11.u16);
loc_82077498:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r30,1
	ctx.r30.s64 = 1;
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820774cc
	if (ctx.cr6.eq) goto loc_820774CC;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820774cc
	if (ctx.cr6.eq) goto loc_820774CC;
	// lbz r11,1185(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1185);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// bne cr6,0x820774d0
	if (!ctx.cr6.eq) goto loc_820774D0;
loc_820774CC:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_820774D0:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820776cc
	if (!ctx.cr6.eq) goto loc_820776CC;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-6596(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// bl 0x820a1138
	ctx.lr = 0x820774FC;
	sub_820A1138(ctx, base);
	// lwz r10,288(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// lwz r11,96(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82077510
	if (ctx.cr6.eq) goto loc_82077510;
	// stb r30,10333(r11)
	REX_STORE_U8(ctx.r11.u32 + 10333, ctx.r30.u8);
loc_82077510:
	// lis r31,-32218
	ctx.r31.s64 = -2111438848;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-6612(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + -6612);
	// bl 0x82097198
	ctx.lr = 0x82077524;
	sub_82097198(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,-6612(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + -6612);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82097420
	ctx.lr = 0x82077534;
	sub_82097420(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8207753C:
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820776cc
	if (ctx.cr6.eq) goto loc_820776CC;
	// lhz r11,1664(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1664);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820776cc
	if (!ctx.cr6.eq) goto loc_820776CC;
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// li r27,0
	ctx.r27.s64 = 0;
	// andc r10,r11,r29
	ctx.r10.u64 = ctx.r11.u64 & ~ctx.r29.u64;
	// stw r10,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x82077580
	if (!ctx.cr6.eq) goto loc_82077580;
	// lwz r11,1656(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1656);
	// lwz r10,1660(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1660);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82077580
	if (ctx.cr6.eq) goto loc_82077580;
	// stw r27,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r27.u32);
loc_82077580:
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820776cc
	if (!ctx.cr6.eq) goto loc_820776CC;
	// lwz r11,1660(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1660);
	// li r30,1
	ctx.r30.s64 = 1;
	// lwz r10,1656(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1656);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820775f4
	if (!ctx.cr6.eq) goto loc_820775F4;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r9,48(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// lfs f0,9536(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// stb r30,424(r9)
	REX_STORE_U8(ctx.r9.u32 + 424, ctx.r30.u8);
	// stfs f0,428(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 428, temp.u32);
	// stb r27,340(r9)
	REX_STORE_U8(ctx.r9.u32 + 340, ctx.r27.u8);
	// lwz r8,48(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// lhz r7,10(r8)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + 10);
	// cmplwi cr6,r7,32768
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 32768, ctx.xer);
	// blt cr6,0x820775d8
	if (ctx.cr6.lt) goto loc_820775D8;
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// li r11,-2
	ctx.r11.s64 = -2;
	// sth r11,12(r10)
	REX_STORE_U16(ctx.r10.u32 + 12, ctx.r11.u16);
	// sth r11,10(r10)
	REX_STORE_U16(ctx.r10.u32 + 10, ctx.r11.u16);
loc_820775D8:
	// lwz r3,136(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r27,1656(r31)
	REX_STORE_U32(ctx.r31.u32 + 1656, ctx.r27.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820775F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820775F4:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82077624
	if (ctx.cr6.eq) goto loc_82077624;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82077624
	if (ctx.cr6.eq) goto loc_82077624;
	// lbz r11,1185(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1185);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// bne cr6,0x82077628
	if (!ctx.cr6.eq) goto loc_82077628;
loc_82077624:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_82077628:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8207768c
	if (!ctx.cr6.eq) goto loc_8207768C;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-6596(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// bl 0x820a1138
	ctx.lr = 0x82077654;
	sub_820A1138(ctx, base);
	// lwz r10,288(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// lwz r11,96(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82077668
	if (ctx.cr6.eq) goto loc_82077668;
	// stb r27,10333(r11)
	REX_STORE_U8(ctx.r11.u32 + 10333, ctx.r27.u8);
loc_82077668:
	// lis r31,-32218
	ctx.r31.s64 = -2111438848;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-6612(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + -6612);
	// bl 0x82097198
	ctx.lr = 0x8207767C;
	sub_82097198(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,-6612(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + -6612);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82097420
	ctx.lr = 0x8207768C;
	sub_82097420(ctx, base);
loc_8207768C:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// blt cr6,0x820776cc
	if (ctx.cr6.lt) goto loc_820776CC;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r11,-6652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6652);
	// lbz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820776b0
	if (!ctx.cr6.eq) goto loc_820776B0;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// b 0x820776bc
	goto loc_820776BC;
loc_820776B0:
	// addi r10,r28,2
	ctx.r10.s64 = ctx.r28.s64 + 2;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
loc_820776BC:
	// lbz r10,35(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 35);
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bne cr6,0x820776cc
	if (!ctx.cr6.eq) goto loc_820776CC;
	// stb r30,35(r11)
	REX_STORE_U8(ctx.r11.u32 + 35, ctx.r30.u8);
loc_820776CC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
