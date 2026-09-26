DEFINE_REX_FUNC(sub_82067E00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// addi r12,r1,-24
	ctx.r12.s64 = ctx.r1.s64 + -24;
	// bl 0x8212a848
	ctx.lr = 0x82067E18;
	__savefpr_24(ctx, base);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-6596(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lfs f28,9828(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9828);
	ctx.f28.f64 = double(temp.f32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lfs f26,9824(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 9824);
	ctx.f26.f64 = double(temp.f32);
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// lfs f0,9820(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9820);
	ctx.f0.f64 = double(temp.f32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r7,12(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lfs f31,9816(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9816);
	ctx.f31.f64 = double(temp.f32);
	// lfs f27,9812(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 9812);
	ctx.f27.f64 = double(temp.f32);
	// lwz r6,16(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// lfs f24,18248(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 18248);
	ctx.f24.f64 = double(temp.f32);
	// addi r8,r10,3000
	ctx.r8.s64 = ctx.r10.s64 + 3000;
	// lfs f29,9808(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 9808);
	ctx.f29.f64 = double(temp.f32);
	// std r5,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// stw r9,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// clrlwi r30,r8,16
	ctx.r30.u64 = ctx.r8.u32 & 0xFFFF;
	// stb r9,100(r1)
	REX_STORE_U8(ctx.r1.u32 + 100, ctx.r9.u8);
	// cmplwi cr6,r6,576
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 576, ctx.xer);
	// fmuls f30,f11,f0
	ctx.f30.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fmadds f25,f11,f24,f30
	ctx.f25.f64 = double(float(std::fma(ctx.f11.f64, ctx.f24.f64, ctx.f30.f64)));
	// bne cr6,0x82067ecc
	if (!ctx.cr6.eq) goto loc_82067ECC;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lfs f28,9804(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9804);
	ctx.f28.f64 = double(temp.f32);
	// lfs f27,9800(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9800);
	ctx.f27.f64 = double(temp.f32);
	// lfs f26,9796(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9796);
	ctx.f26.f64 = double(temp.f32);
	// lfs f31,9792(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9792);
	ctx.f31.f64 = double(temp.f32);
	// lfs f29,9788(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 9788);
	ctx.f29.f64 = double(temp.f32);
loc_82067ECC:
	// cmplwi cr6,r10,21
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 21, ctx.xer);
	// bgt cr6,0x820682a8
	if (ctx.cr6.gt) goto loc_820682A8;
	// lis r12,-32250
	ctx.r12.s64 = -2113536000;
	// addi r12,r12,32492
	ctx.r12.s64 = ctx.r12.s64 + 32492;
	// rlwinm r0,r10,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r10.u32) {
	case 0:
		goto loc_82067FD8;
	case 1:
		goto loc_820681DC;
	case 2:
		goto loc_820680CC;
	case 3:
		goto loc_82067F44;
	case 4:
		goto loc_8206802C;
	case 5:
		goto loc_820680A4;
	case 6:
		goto loc_820680F4;
	case 7:
		goto loc_8206811C;
	case 8:
		goto loc_82068054;
	case 9:
		goto loc_82068140;
	case 10:
		goto loc_8206825C;
	case 11:
		goto loc_82068284;
	case 12:
		goto loc_82068000;
	case 13:
		goto loc_82067FB0;
	case 14:
		goto loc_820681B8;
	case 15:
		goto loc_82068168;
	case 16:
		goto loc_8206807C;
	case 17:
		goto loc_82067F68;
	case 18:
		goto loc_82067F8C;
	case 19:
		goto loc_82068234;
	case 20:
		goto loc_82068208;
	case 21:
		goto loc_82068190;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82067F44:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,90
	ctx.r4.s64 = 90;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x82067F54;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18776
	ctx.r4.s64 = ctx.r11.s64 + 18776;
	// bl 0x82053a00
	ctx.lr = 0x82067F64;
	sub_82053A00(ctx, base);
	// b 0x820682a8
	goto loc_820682A8;
loc_82067F68:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,96
	ctx.r4.s64 = 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x82067F78;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18776
	ctx.r4.s64 = ctx.r11.s64 + 18776;
	// bl 0x82053a00
	ctx.lr = 0x82067F88;
	sub_82053A00(ctx, base);
	// b 0x820682a8
	goto loc_820682A8;
loc_82067F8C:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,443
	ctx.r4.s64 = 443;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x82067F9C;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18776
	ctx.r4.s64 = ctx.r11.s64 + 18776;
	// bl 0x82053a00
	ctx.lr = 0x82067FAC;
	sub_82053A00(ctx, base);
	// b 0x820682a8
	goto loc_820682A8;
loc_82067FB0:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,443
	ctx.r4.s64 = 443;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x82067FC0;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18776
	ctx.r4.s64 = ctx.r11.s64 + 18776;
	// bl 0x82053a00
	ctx.lr = 0x82067FD0;
	sub_82053A00(ctx, base);
	// fmr f31,f27
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f27.f64;
	// b 0x820682a8
	goto loc_820682A8;
loc_82067FD8:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,95
	ctx.r4.s64 = 95;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x82067FE8;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18784
	ctx.r4.s64 = ctx.r11.s64 + 18784;
	// bl 0x82053a00
	ctx.lr = 0x82067FF8;
	sub_82053A00(ctx, base);
	// fmr f30,f25
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f25.f64;
	// b 0x820682a8
	goto loc_820682A8;
loc_82068000:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,95
	ctx.r4.s64 = 95;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x82068010;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18784
	ctx.r4.s64 = ctx.r11.s64 + 18784;
	// bl 0x82053a00
	ctx.lr = 0x82068020;
	sub_82053A00(ctx, base);
	// fmr f30,f25
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f25.f64;
	// fmr f31,f27
	ctx.f31.f64 = ctx.f27.f64;
	// b 0x820682a8
	goto loc_820682A8;
loc_8206802C:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,98
	ctx.r4.s64 = 98;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x8206803C;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18784
	ctx.r4.s64 = ctx.r11.s64 + 18784;
	// bl 0x82053a00
	ctx.lr = 0x8206804C;
	sub_82053A00(ctx, base);
	// fmr f30,f25
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f25.f64;
	// b 0x820682a8
	goto loc_820682A8;
loc_82068054:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,449
	ctx.r4.s64 = 449;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x82068064;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18784
	ctx.r4.s64 = ctx.r11.s64 + 18784;
	// bl 0x82053a00
	ctx.lr = 0x82068074;
	sub_82053A00(ctx, base);
	// fmr f30,f25
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f25.f64;
	// b 0x820682a8
	goto loc_820682A8;
loc_8206807C:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,532
	ctx.r4.s64 = 532;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x8206808C;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18784
	ctx.r4.s64 = ctx.r11.s64 + 18784;
	// bl 0x82053a00
	ctx.lr = 0x8206809C;
	sub_82053A00(ctx, base);
	// fmr f30,f25
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f25.f64;
	// b 0x820682a8
	goto loc_820682A8;
loc_820680A4:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,591
	ctx.r4.s64 = 591;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x820680B4;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18792
	ctx.r4.s64 = ctx.r11.s64 + 18792;
	// bl 0x82053a00
	ctx.lr = 0x820680C4;
	sub_82053A00(ctx, base);
	// fmr f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f29.f64;
	// b 0x820682a8
	goto loc_820682A8;
loc_820680CC:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,442
	ctx.r4.s64 = 442;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x820680DC;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18792
	ctx.r4.s64 = ctx.r11.s64 + 18792;
	// bl 0x82053a00
	ctx.lr = 0x820680EC;
	sub_82053A00(ctx, base);
	// fmr f31,f28
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f28.f64;
	// b 0x820682a8
	goto loc_820682A8;
loc_820680F4:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,445
	ctx.r4.s64 = 445;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x82068104;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18792
	ctx.r4.s64 = ctx.r11.s64 + 18792;
	// bl 0x82053a00
	ctx.lr = 0x82068114;
	sub_82053A00(ctx, base);
	// fmr f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f29.f64;
	// b 0x820682a8
	goto loc_820682A8;
loc_8206811C:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,445
	ctx.r4.s64 = 445;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x8206812C;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18776
	ctx.r4.s64 = ctx.r11.s64 + 18776;
	// bl 0x82053a00
	ctx.lr = 0x8206813C;
	sub_82053A00(ctx, base);
	// b 0x820682a8
	goto loc_820682A8;
loc_82068140:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,477
	ctx.r4.s64 = 477;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x82068150;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18792
	ctx.r4.s64 = ctx.r11.s64 + 18792;
	// bl 0x82053a00
	ctx.lr = 0x82068160;
	sub_82053A00(ctx, base);
	// fmr f30,f25
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f25.f64;
	// b 0x820682a8
	goto loc_820682A8;
loc_82068168:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,398
	ctx.r4.s64 = 398;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x82068178;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18792
	ctx.r4.s64 = ctx.r11.s64 + 18792;
	// bl 0x82053a00
	ctx.lr = 0x82068188;
	sub_82053A00(ctx, base);
	// fmr f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f29.f64;
	// b 0x820682a8
	goto loc_820682A8;
loc_82068190:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,600
	ctx.r4.s64 = 600;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x820681A0;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18792
	ctx.r4.s64 = ctx.r11.s64 + 18792;
	// bl 0x82053a00
	ctx.lr = 0x820681B0;
	sub_82053A00(ctx, base);
	// fmr f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f29.f64;
	// b 0x820682a8
	goto loc_820682A8;
loc_820681B8:
	// li r5,25
	ctx.r5.s64 = 25;
	// li r4,407
	ctx.r4.s64 = 407;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x820681C8;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18800
	ctx.r4.s64 = ctx.r11.s64 + 18800;
	// bl 0x82053a00
	ctx.lr = 0x820681D8;
	sub_82053A00(ctx, base);
	// b 0x820682a8
	goto loc_820682A8;
loc_820681DC:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,453
	ctx.r4.s64 = 453;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x820681EC;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18800
	ctx.r4.s64 = ctx.r11.s64 + 18800;
	// bl 0x82053a00
	ctx.lr = 0x820681FC;
	sub_82053A00(ctx, base);
	// fmr f30,f25
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f25.f64;
	// fmr f31,f28
	ctx.f31.f64 = ctx.f28.f64;
	// b 0x820682a8
	goto loc_820682A8;
loc_82068208:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,452
	ctx.r4.s64 = 452;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x82068218;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18800
	ctx.r4.s64 = ctx.r11.s64 + 18800;
	// bl 0x82053a00
	ctx.lr = 0x82068228;
	sub_82053A00(ctx, base);
	// fmr f30,f25
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f25.f64;
	// fmr f31,f29
	ctx.f31.f64 = ctx.f29.f64;
	// b 0x820682a8
	goto loc_820682A8;
loc_82068234:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,443
	ctx.r4.s64 = 443;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x82068244;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18800
	ctx.r4.s64 = ctx.r11.s64 + 18800;
	// bl 0x82053a00
	ctx.lr = 0x82068254;
	sub_82053A00(ctx, base);
	// fmr f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f29.f64;
	// b 0x820682a8
	goto loc_820682A8;
loc_8206825C:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,450
	ctx.r4.s64 = 450;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x8206826C;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18808
	ctx.r4.s64 = ctx.r11.s64 + 18808;
	// bl 0x82053a00
	ctx.lr = 0x8206827C;
	sub_82053A00(ctx, base);
	// fmr f30,f25
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f25.f64;
	// b 0x820682a4
	goto loc_820682A4;
loc_82068284:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,451
	ctx.r4.s64 = 451;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x82068294;
	sub_82067230(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18820
	ctx.r4.s64 = ctx.r11.s64 + 18820;
	// bl 0x82053a00
	ctx.lr = 0x820682A4;
	sub_82053A00(ctx, base);
loc_820682A4:
	// fmr f31,f26
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f26.f64;
loc_820682A8:
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82053a00
	ctx.lr = 0x820682B4;
	sub_82053A00(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x82067c40
	ctx.lr = 0x820682CC;
	sub_82067C40(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r4,32(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lis r8,-32218
	ctx.r8.s64 = -2111438848;
	// sth r10,44(r31)
	REX_STORE_U16(ctx.r31.u32 + 44, ctx.r10.u16);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f2,9784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9784);
	ctx.f2.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f2,36(r31)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// lfs f1,9780(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9780);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,-6604(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -6604);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r3,r11,212
	ctx.r3.s64 = ctx.r11.s64 + 212;
	// bl 0x820a9d78
	ctx.lr = 0x8206830C;
	sub_820A9D78(ctx, base);
	// lwz r3,56(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r6,0(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,228(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 228);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82068320;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fmadds f13,f1,f24,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(std::fma(ctx.f1.f64, ctx.f24.f64, ctx.f30.f64)));
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r3,56(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lfs f0,9548(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 9548);
	ctx.f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f12,4(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,232(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 232);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82068348;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fmadds f11,f1,f24,f31
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(std::fma(ctx.f1.f64, ctx.f24.f64, ctx.f31.f64)));
	// lfs f10,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// fnmsubs f9,f10,f24,f11
	ctx.f9.f64 = double(float(-std::fma(ctx.f10.f64, ctx.f24.f64, -ctx.f11.f64)));
	// stfs f9,8(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// addi r12,r1,-24
	ctx.r12.s64 = ctx.r1.s64 + -24;
	// bl 0x8212a894
	ctx.lr = 0x82068364;
	__restfpr_24(ctx, base);
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
