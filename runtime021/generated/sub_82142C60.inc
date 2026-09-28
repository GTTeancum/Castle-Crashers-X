DEFINE_REX_FUNC(sub_82142C60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x82142C68;
	__savegprlr_24(ctx, base);
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-3184(r1)
	ea = -3184 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// lwz r31,72(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 72);
	// mr r24,r9
	ctx.r24.u64 = ctx.r9.u64;
	// li r9,100
	ctx.r9.s64 = 100;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,1536
	ctx.r6.s64 = ctx.r1.s64 + 1536;
	// addi r5,r1,512
	ctx.r5.s64 = ctx.r1.s64 + 512;
	// addi r30,r27,8
	ctx.r30.s64 = ctx.r27.s64 + 8;
	// bl 0x82146860
	ctx.lr = 0x82142CAC;
	sub_82146860(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f13,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// li r9,100
	ctx.r9.s64 = 100;
	// addi r7,r1,512
	ctx.r7.s64 = ctx.r1.s64 + 512;
	// lwz r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,1536
	ctx.r4.s64 = ctx.r1.s64 + 1536;
	// lfs f0,9756(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9756);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,512
	ctx.r3.s64 = ctx.r1.s64 + 512;
	// fdivs f31,f0,f13
	ctx.f31.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82146608
	ctx.lr = 0x82142CDC;
	sub_82146608(ctx, base);
	// addi r26,r30,4
	ctx.r26.s64 = ctx.r30.s64 + 4;
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,100
	ctx.r10.s64 = 100;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,1536
	ctx.r7.s64 = ctx.r1.s64 + 1536;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r1,512
	ctx.r4.s64 = ctx.r1.s64 + 512;
	// addi r3,r29,8
	ctx.r3.s64 = ctx.r29.s64 + 8;
	// bl 0x82145be8
	ctx.lr = 0x82142D04;
	sub_82145BE8(ctx, base);
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,512
	ctx.r4.s64 = ctx.r1.s64 + 512;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82142aa8
	ctx.lr = 0x82142D14;
	sub_82142AA8(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f12,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lhz r6,28(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 28);
	// lfs f0,9540(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// lfs f31,9536(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bne cr6,0x82142d3c
	if (!ctx.cr6.eq) goto loc_82142D3C;
	// extsh. r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82142e3c
	if (ctx.cr0.eq) goto loc_82142E3C;
loc_82142D3C:
	// lha r7,36(r31)
	ctx.r7.s64 = int16_t(REX_LOAD_U16(ctx.r31.u32 + 36));
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f31.f64;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82142D50:
	// extsw r11,r8
	ctx.r11.s64 = ctx.r8.s32;
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f11,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fmuls f11,f11,f12
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fctiwz f11,f11
	ctx.f11.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f11.u64);
	// lhz r11,102(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 102);
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// blt cr6,0x82142db8
	if (ctx.cr6.lt) goto loc_82142DB8;
	// extsh. r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// blt 0x82142dac
	if (ctx.cr0.lt) goto loc_82142DAC;
	// bge cr6,0x82142db0
	if (!ctx.cr6.lt) goto loc_82142DB0;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r1,512
	ctx.r4.s64 = ctx.r1.s64 + 512;
	// addi r9,r1,1936
	ctx.r9.s64 = ctx.r1.s64 + 1936;
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lfsx f11,r5,r4
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + ctx.r4.u32);
	ctx.f11.f64 = double(temp.f32);
	// stfsx f11,r10,r9
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r9.u32, temp.u32);
	// b 0x82142dcc
	goto loc_82142DCC;
loc_82142DAC:
	// blt cr6,0x82142db8
	if (ctx.cr6.lt) goto loc_82142DB8;
loc_82142DB0:
	// lfs f11,1532(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1532);
	ctx.f11.f64 = double(temp.f32);
	// b 0x82142dc0
	goto loc_82142DC0;
loc_82142DB8:
	// addi r9,r1,512
	ctx.r9.s64 = ctx.r1.s64 + 512;
	// lfsx f11,r10,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	ctx.f11.f64 = double(temp.f32);
loc_82142DC0:
	// addi r11,r1,1936
	ctx.r11.s64 = ctx.r1.s64 + 1936;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_82142DCC:
	// addi r9,r1,512
	ctx.r9.s64 = ctx.r1.s64 + 512;
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lfsx f11,r10,r9
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	ctx.f11.f64 = double(temp.f32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// fadds f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// cmpwi cr6,r10,1024
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1024, ctx.xer);
	// blt cr6,0x82142d50
	if (ctx.cr6.lt) goto loc_82142D50;
	// fsubs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r11,r1,1936
	ctx.r11.s64 = ctx.r1.s64 + 1936;
	// li r10,256
	ctx.r10.s64 = 256;
	// lfs f0,-31784(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -31784);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
loc_82142E08:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bne 0x82142e08
	if (!ctx.cr0.eq) goto loc_82142E08;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,1936
	ctx.r4.s64 = ctx.r1.s64 + 1936;
	// addi r3,r1,512
	ctx.r3.s64 = ctx.r1.s64 + 512;
	// lwz r11,24196(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24196);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82142E3C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82142E3C:
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,1536
	ctx.r6.s64 = ctx.r1.s64 + 1536;
	// addi r5,r27,16
	ctx.r5.s64 = ctx.r27.s64 + 16;
	// li r4,12
	ctx.r4.s64 = 12;
	// addi r3,r1,512
	ctx.r3.s64 = ctx.r1.s64 + 512;
	// bl 0x821461a0
	ctx.lr = 0x82142E54;
	sub_821461A0(ctx, base);
	// addi r5,r27,20
	ctx.r5.s64 = ctx.r27.s64 + 20;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82146158
	ctx.lr = 0x82142E64;
	sub_82146158(ctx, base);
	// addi r6,r1,1936
	ctx.r6.s64 = ctx.r1.s64 + 1936;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r24,145
	ctx.r4.s64 = ctx.r24.s64 + 145;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x821451c8
	ctx.lr = 0x82142E78;
	sub_821451C8(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r6,r1,1936
	ctx.r6.s64 = ctx.r1.s64 + 1936;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,1936
	ctx.r3.s64 = ctx.r1.s64 + 1936;
	// lfs f1,9632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9632);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821454e8
	ctx.lr = 0x82142E90;
	sub_821454E8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,1936
	ctx.r3.s64 = ctx.r1.s64 + 1936;
	// bl 0x82145718
	ctx.lr = 0x82142E9C;
	sub_82145718(ctx, base);
	// lwz r31,3268(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 3268);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// addi r3,r1,1936
	ctx.r3.s64 = ctx.r1.s64 + 1936;
	// bl 0x82145f80
	ctx.lr = 0x82142EB8;
	sub_82145F80(ctx, base);
	// lfs f5,52(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 52);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,48(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 48);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82145b18
	ctx.lr = 0x82142ED0;
	sub_82145B18(ctx, base);
	// stfs f1,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
	// addi r1,r1,3184
	ctx.r1.s64 = ctx.r1.s64 + 3184;
	// lfd f31,-80(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
