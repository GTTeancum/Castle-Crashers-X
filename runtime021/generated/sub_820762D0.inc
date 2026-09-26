DEFINE_REX_FUNC(sub_820762D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x820762D8;
	__savegprlr_29(ctx, base);
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32215
	ctx.r30.s64 = -2111242240;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lbz r11,636(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 636);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r10,10
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 10, ctx.xer);
	// bgt cr6,0x82076748
	if (ctx.cr6.gt) goto loc_82076748;
	// lis r12,-32249
	ctx.r12.s64 = -2113470464;
	// addi r12,r12,25368
	ctx.r12.s64 = ctx.r12.s64 + 25368;
	// rlwinm r0,r10,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r10.u32) {
	case 0:
		goto loc_82076344;
	case 1:
		goto loc_82076374;
	case 2:
		goto loc_82076398;
	case 3:
		goto loc_820763D8;
	case 4:
		goto loc_820763F0;
	case 5:
		goto loc_82076434;
	case 6:
		goto loc_82076540;
	case 7:
		goto loc_82076558;
	case 8:
		goto loc_8207661C;
	case 9:
		goto loc_82076724;
	case 10:
		goto loc_8207673C;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82076344:
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// lwz r11,632(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 632);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,632(r10)
	REX_STORE_U32(ctx.r10.u32 + 632, ctx.r11.u32);
	// cmplwi cr6,r11,30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 30, ctx.xer);
	// bne cr6,0x82076748
	if (!ctx.cr6.eq) goto loc_82076748;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,636(r30)
	REX_STORE_U8(ctx.r30.u32 + 636, ctx.r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_82076374:
	// lwz r3,1756(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1756);
	// bl 0x82078e38
	ctx.lr = 0x8207637C;
	sub_82078E38(ctx, base);
	// lbz r11,636(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 636);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r11,636(r30)
	REX_STORE_U8(ctx.r30.u32 + 636, ctx.r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_82076398:
	// lis r29,-32218
	ctx.r29.s64 = -2111438848;
	// lwz r3,-6652(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -6652);
	// bl 0x8209b5d0
	ctx.lr = 0x820763A4;
	sub_8209B5D0(ctx, base);
	// lwz r3,-6652(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -6652);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8209b648
	ctx.lr = 0x820763B0;
	sub_8209B648(ctx, base);
	// lwz r3,1756(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1756);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x82078f38
	ctx.lr = 0x820763BC;
	sub_82078F38(ctx, base);
	// lbz r11,636(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 636);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r11,636(r30)
	REX_STORE_U8(ctx.r30.u32 + 636, ctx.r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_820763D8:
	// li r11,4
	ctx.r11.s64 = 4;
	// stb r11,636(r30)
	REX_STORE_U8(ctx.r30.u32 + 636, ctx.r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_820763F0:
	// lbz r10,68(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 68);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// beq cr6,0x8207641c
	if (ctx.cr6.eq) goto loc_8207641C;
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
	ctx.lr = 0x82076418;
	sub_820B5FE8(ctx, base);
	// lbz r11,636(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 636);
loc_8207641C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r11,636(r30)
	REX_STORE_U8(ctx.r30.u32 + 636, ctx.r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_82076434:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r29,r31,292
	ctx.r29.s64 = ctx.r31.s64 + 292;
	// addi r4,r11,-8136
	ctx.r4.s64 = ctx.r11.s64 + -8136;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82053a00
	ctx.lr = 0x82076448;
	sub_82053A00(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82077ce0
	ctx.lr = 0x82076458;
	sub_82077CE0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82076748
	if (ctx.cr6.eq) goto loc_82076748;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f31,9540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9540);
	ctx.f31.f64 = double(temp.f32);
loc_8207646C:
	// lwz r3,288(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// lwz r11,96(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82076484
	if (ctx.cr6.eq) goto loc_82076484;
	// lbz r11,10345(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 10345);
	// b 0x82076488
	goto loc_82076488;
loc_82076484:
	// li r11,1
	ctx.r11.s64 = 1;
loc_82076488:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820764ac
	if (!ctx.cr6.eq) goto loc_820764AC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820764A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8207646c
	goto loc_8207646C;
loc_820764AC:
	// lwz r3,288(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820764C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-6608(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + -6608);
	// bl 0x8209c718
	ctx.lr = 0x820764D4;
	sub_8209C718(ctx, base);
	// lwz r4,288(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x820780d8
	ctx.lr = 0x820764E0;
	sub_820780D8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820788b8
	ctx.lr = 0x820764E8;
	sub_820788B8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8209aed8
	ctx.lr = 0x820764F0;
	sub_8209AED8(ctx, base);
	// lwz r3,288(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82076508;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x820759a8
	ctx.lr = 0x82076514;
	sub_820759A8(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r4,r6,-8160
	ctx.r4.s64 = ctx.r6.s64 + -8160;
	// bl 0x82053a00
	ctx.lr = 0x82076524;
	sub_82053A00(ctx, base);
	// lbz r11,636(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 636);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// stb r5,636(r30)
	REX_STORE_U8(ctx.r30.u32 + 636, ctx.r5.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_82076540:
	// li r11,7
	ctx.r11.s64 = 7;
	// stb r11,636(r30)
	REX_STORE_U8(ctx.r30.u32 + 636, ctx.r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_82076558:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,216
	ctx.r4.s64 = ctx.r31.s64 + 216;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82077ce0
	ctx.lr = 0x82076568;
	sub_82077CE0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82076748
	if (ctx.cr6.eq) goto loc_82076748;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f31,9540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9540);
	ctx.f31.f64 = double(temp.f32);
loc_8207657C:
	// lwz r3,212(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// lwz r11,96(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82076594
	if (ctx.cr6.eq) goto loc_82076594;
	// lbz r11,10345(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 10345);
	// b 0x82076598
	goto loc_82076598;
loc_82076594:
	// li r11,1
	ctx.r11.s64 = 1;
loc_82076598:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820765bc
	if (!ctx.cr6.eq) goto loc_820765BC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820765B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8207657c
	goto loc_8207657C;
loc_820765BC:
	// lwz r3,212(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820765D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r4,-6608(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + -6608);
	// bl 0x8209c718
	ctx.lr = 0x820765E4;
	sub_8209C718(ctx, base);
	// lwz r4,212(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x820780d8
	ctx.lr = 0x820765F0;
	sub_820780D8(ctx, base);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x820788b8
	ctx.lr = 0x820765F8;
	sub_820788B8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8209aed8
	ctx.lr = 0x82076600;
	sub_8209AED8(ctx, base);
	// lbz r11,636(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 636);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stb r8,636(r30)
	REX_STORE_U8(ctx.r30.u32 + 636, ctx.r8.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8207661C:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,140
	ctx.r4.s64 = ctx.r31.s64 + 140;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82077ce0
	ctx.lr = 0x8207662C;
	sub_82077CE0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82076748
	if (ctx.cr6.eq) goto loc_82076748;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f31,9540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9540);
	ctx.f31.f64 = double(temp.f32);
loc_82076640:
	// lwz r3,136(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// lwz r11,96(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82076658
	if (ctx.cr6.eq) goto loc_82076658;
	// lbz r11,10345(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 10345);
	// b 0x8207665c
	goto loc_8207665C;
loc_82076658:
	// li r11,1
	ctx.r11.s64 = 1;
loc_8207665C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82076680
	if (!ctx.cr6.eq) goto loc_82076680;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207667C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82076640
	goto loc_82076640;
loc_82076680:
	// lwz r3,136(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82076698;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-6608(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + -6608);
	// bl 0x8209c718
	ctx.lr = 0x820766A8;
	sub_8209C718(ctx, base);
	// lwz r4,136(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x820780d8
	ctx.lr = 0x820766B4;
	sub_820780D8(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x820788b8
	ctx.lr = 0x820766BC;
	sub_820788B8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8209aed8
	ctx.lr = 0x820766C4;
	sub_8209AED8(ctx, base);
	// li r3,60
	ctx.r3.s64 = 60;
	// bl 0x820a7390
	ctx.lr = 0x820766CC;
	sub_820A7390(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82076700
	if (ctx.cr6.eq) goto loc_82076700;
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// lwz r4,96(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// bl 0x8206be30
	ctx.lr = 0x820766E0;
	sub_8206BE30(ctx, base);
	// lbz r11,636(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 636);
	// stw r3,1660(r31)
	REX_STORE_U32(ctx.r31.u32 + 1660, ctx.r3.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r11,636(r30)
	REX_STORE_U8(ctx.r30.u32 + 636, ctx.r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_82076700:
	// lbz r11,636(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 636);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r3,1660(r31)
	REX_STORE_U32(ctx.r31.u32 + 1660, ctx.r3.u32);
	// stb r11,636(r30)
	REX_STORE_U8(ctx.r30.u32 + 636, ctx.r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_82076724:
	// li r11,10
	ctx.r11.s64 = 10;
	// stb r11,636(r30)
	REX_STORE_U8(ctx.r30.u32 + 636, ctx.r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8207673C:
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820757c8
	ctx.lr = 0x82076748;
	sub_820757C8(ctx, base);
loc_82076748:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
