DEFINE_REX_FUNC(sub_82070908) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x82070910;
	__savegprlr_23(ctx, base);
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x8212a84c
	ctx.lr = 0x82070918;
	__savefpr_25(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32218
	ctx.r31.s64 = -2111438848;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r3,-6616(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + -6616);
	// lwz r11,-6596(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// lfs f31,9540(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9540);
	ctx.f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8207094C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f30,9536(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9536);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x820b6d10
	ctx.lr = 0x8207095C;
	sub_820B6D10(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820b6d48
	ctx.lr = 0x82070964;
	sub_820B6D48(ctx, base);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x820b6d48
	ctx.lr = 0x8207096C;
	sub_820B6D48(ctx, base);
	// lis r6,-32221
	ctx.r6.s64 = -2111635456;
	// ld r3,96(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// rlwinm r27,r30,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r6,-26352
	ctx.r28.s64 = ctx.r6.s64 + -26352;
	// ld r25,104(r1)
	ctx.r25.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// bl 0x8212b180
	ctx.lr = 0x82070984;
	sub_8212B180(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f1.f64;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f29,9700(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9700);
	ctx.f29.f64 = double(temp.f32);
	// li r29,1
	ctx.r29.s64 = 1;
	// lfs f26,9876(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9876);
	ctx.f26.f64 = double(temp.f32);
	// li r30,-1
	ctx.r30.s64 = -1;
	// lfs f27,9872(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9872);
	ctx.f27.f64 = double(temp.f32);
	// lis r26,-32218
	ctx.r26.s64 = -2111438848;
	// addi r24,r11,564
	ctx.r24.s64 = ctx.r11.s64 + 564;
	// addi r23,r10,520
	ctx.r23.s64 = ctx.r10.s64 + 520;
loc_820709BC:
	// lwz r3,-6616(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + -6616);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820709D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,-6616(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + -6616);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820709EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwzx r8,r27,r28
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82070a04
	if (!ctx.cr6.eq) goto loc_82070A04;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x82070A00;
	sub_8208C5D8(ctx, base);
	// b 0x82070a40
	goto loc_82070A40;
loc_82070A04:
	// lwz r11,-6604(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6604);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addic. r3,r11,212
	ctx.xer.ca = ctx.r11.u32 > 4294967083;
	ctx.r3.s64 = ctx.r11.s64 + 212;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82070a20
	if (!ctx.cr0.eq) goto loc_82070A20;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x82070A1C;
	sub_8208C5D8(ctx, base);
	// b 0x82070a40
	goto loc_82070A40;
loc_82070A20:
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// lwz r4,-6616(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + -6616);
	// fmr f4,f31
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = ctx.f31.f64;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// fmr f3,f31
	ctx.f3.f64 = ctx.f31.f64;
	// fmr f2,f26
	ctx.f2.f64 = ctx.f26.f64;
	// fmr f1,f27
	ctx.f1.f64 = ctx.f27.f64;
	// bl 0x820a9e98
	ctx.lr = 0x82070A40;
	sub_820A9E98(ctx, base);
loc_82070A40:
	// lwz r3,-6616(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + -6616);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82070A58;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x820b6d48
	ctx.lr = 0x82070A60;
	sub_820B6D48(ctx, base);
	// ld r3,96(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// bl 0x8212b180
	ctx.lr = 0x82070A68;
	sub_8212B180(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// fmr f25,f1
	ctx.fpscr.disableFlushMode();
	ctx.f25.f64 = ctx.f1.f64;
	// bl 0x8212b180
	ctx.lr = 0x82070A74;
	sub_8212B180(ctx, base);
	// fsub f0,f25,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f25.f64 - ctx.f1.f64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// fdiv f13,f0,f28
	ctx.f13.f64 = ctx.f0.f64 / ctx.f28.f64;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fadds f30,f12,f30
	ctx.f30.f64 = double(float(ctx.f12.f64 + ctx.f30.f64));
	// bl 0x820b6d48
	ctx.lr = 0x82070A8C;
	sub_820B6D48(ctx, base);
	// fcmpu cr6,f30,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f30.f64, ctx.f29.f64);
	// ld r25,112(r1)
	ctx.r25.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// blt cr6,0x820709bc
	if (ctx.cr6.lt) goto loc_820709BC;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820b6d48
	ctx.lr = 0x82070AA0;
	sub_820B6D48(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r4,-6628(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82070ab8
	if (ctx.cr6.eq) goto loc_82070AB8;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x820a1d20
	ctx.lr = 0x82070AB8;
	sub_820A1D20(ctx, base);
loc_82070AB8:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,2780
	ctx.r3.s64 = ctx.r11.s64 + 2780;
	// bl 0x820b6908
	ctx.lr = 0x82070AC8;
	sub_820B6908(ctx, base);
}
