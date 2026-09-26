DEFINE_REX_FUNC(sub_82070AC8_post_init) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	(void)temp;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-label"
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,4096
	ctx.r6.s64 = 4096;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,256
	ctx.r4.s64 = 16777216;
	// lwz r11,-6656(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6656);
	// lwz r3,136(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
	// bl 0x8209bc98
	ctx.lr = 0x82070BC4;
	sub_8209BC98(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r4,r10,-9040
	ctx.r4.s64 = ctx.r10.s64 + -9040;
	// bl 0x82053a00
	ctx.lr = 0x82070BD4;
	sub_82053A00(ctx, base);
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r11,-6604(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6604);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r3,r11,212
	ctx.r3.s64 = ctx.r11.s64 + 212;
	// bl 0x820a9b58
	ctx.lr = 0x82070BEC;
	sub_820A9B58(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f31,9536(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r7,12(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82070C0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r6,-32218
	ctx.r6.s64 = -2111438848;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r8,-32221
	ctx.r8.s64 = -2111635456;
	// lwz r3,-6604(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6604);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r27,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r11,-6596(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + -6596);
	// li r6,140
	ctx.r6.s64 = 140;
	// lfs f2,9540(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 9540);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// lbz r7,9(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 9);
	// subfic r5,r7,0
	ctx.xer.ca = ctx.r7.u32 <= 0;
	ctx.r5.u64 = static_cast<uint64_t>(0) - ctx.r7.u64;
	// subfe r11,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r5.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r11,0,25,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x78;
	// rlwinm r11,r11,0,28,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// lwz r8,-26316(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + -26316);
	// addi r5,r11,51
	ctx.r5.s64 = ctx.r11.s64 + 51;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x8209d028
	ctx.lr = 0x82070C60;
	sub_8209D028(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82070C78;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r8,-32218
	ctx.r8.s64 = -2111438848;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r4,-6612(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + -6612);
	// bl 0x82096828
	ctx.lr = 0x82070C8C;
	sub_82096828(ctx, base);
	// lis r28,-32218
	ctx.r28.s64 = -2111438848;
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r3,-6624(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + -6624);
	// bl 0x820756e0
	ctx.lr = 0x82070C9C;
	sub_820756E0(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r6,r7,-9056
	ctx.r6.s64 = ctx.r7.s64 + -9056;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x820b5f50
	ctx.lr = 0x82070CB4;
	sub_820B5F50(ctx, base);
	// lis r6,-32218
	ctx.r6.s64 = -2111438848;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r5,r5,2088
	ctx.r5.s64 = ctx.r5.s64 + 2088;
	// stw r3,-6620(r6)
	REX_STORE_U32(ctx.r6.u32 + -6620, ctx.r3.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x820b5d60
	ctx.lr = 0x82070CDC;
	sub_820B5D60(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x820b5d70
	ctx.lr = 0x82070CE8;
	sub_820B5D70(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820b6028
	ctx.lr = 0x82070CF0;
	sub_820B6028(ctx, base);
	// lis r4,-32218
	ctx.r4.s64 = -2111438848;
	// lbz r3,-22601(r29)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lwz r30,-6636(r4)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r4.u32 + -6636);
	// lwz r31,0(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r26,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r26.u32);
	// bne cr6,0x82070d20
	if (!ctx.cr6.eq) goto loc_82070D20;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82070D20;
	sub_820A71E8(ctx, base);
loc_82070D20:
	// bl 0x820b5eb8
	ctx.lr = 0x82070D24;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,12
	ctx.r4.s64 = 12;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82070D34;
	sub_8209BDD8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82070d50
	if (ctx.cr6.eq) goto loc_82070D50;
	// stb r24,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r24.u8);
	// stw r24,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r24.u32);
	// stb r24,8(r11)
	REX_STORE_U8(ctx.r11.u32 + 8, ctx.r24.u8);
	// b 0x82070d54
	goto loc_82070D54;
loc_82070D50:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_82070D54:
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// stw r31,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stb r27,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r27.u8);
	// stb r27,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r27.u8);
	// lwz r4,-6628(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + -6628);
	// bl 0x820a1bf8
	ctx.lr = 0x82070D74;
	sub_820A1BF8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6624(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + -6624);
	// bl 0x820757c8
	ctx.lr = 0x82070D80;
	sub_820757C8(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f31,9724(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9724);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x820b6d10
	ctx.lr = 0x82070D90;
	sub_820B6D10(ctx, base);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x820b6d48
	ctx.lr = 0x82070D98;
	sub_820B6D48(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// ld r27,96(r1)
	ctx.r27.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lis r29,-32215
	ctx.r29.s64 = -2111242240;
	// addi r30,r11,18268
	ctx.r30.s64 = ctx.r11.s64 + 18268;
	// lfs f30,9732(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9732);
	ctx.f30.f64 = double(temp.f32);
#pragma clang diagnostic pop
	// Diagnostic continuation stop: next original code is the loc_82070DB0 main monitor loop (startup complete).
	return;
}
