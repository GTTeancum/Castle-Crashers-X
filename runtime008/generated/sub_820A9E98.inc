DEFINE_REX_FUNC(sub_820A9E98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f8
	ctx.lr = 0x820A9EA0;
	__savegprlr_20(ctx, base);
	// addi r12,r1,-104
	ctx.r12.s64 = ctx.r1.s64 + -104;
	// bl 0x8212a820
	ctx.lr = 0x820A9EA8;
	__savefpr_14(ctx, base);
	// stwu r1,-560(r1)
	ea = -560 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// fmr f30,f2
	ctx.f30.f64 = ctx.f2.f64;
	// mr r20,r7
	ctx.r20.u64 = ctx.r7.u64;
	// fmr f29,f3
	ctx.f29.f64 = ctx.f3.f64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// fmr f28,f4
	ctx.f28.f64 = ctx.f4.f64;
	// lwz r11,108(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 108);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820aa474
	if (ctx.cr6.eq) goto loc_820AA474;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x820aa474
	if (ctx.cr6.eq) goto loc_820AA474;
	// lbz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820aa474
	if (ctx.cr6.eq) goto loc_820AA474;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lwz r10,32(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A9F04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r4,r28,12
	ctx.r4.s64 = ctx.r28.s64 + 12;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r8,92(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 92);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820A9F1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,72(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 72);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820A9F30;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// fmr f18,f1
	ctx.fpscr.disableFlushMode();
	ctx.f18.f64 = ctx.f1.f64;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A9F50;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lfs f0,156(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r1,164
	ctx.r5.s64 = ctx.r1.s64 + 164;
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f26,f0,f31
	ctx.f26.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// addi r4,r1,196
	ctx.r4.s64 = ctx.r1.s64 + 196;
	// fmuls f31,f13,f30
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f30.f64));
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r8,44(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 44);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820A9F7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,68(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 68);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820A9F90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x820a9fb4
	if (!ctx.cr6.eq) goto loc_820A9FB4;
	// lwz r10,164(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// std r10,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r10.u64);
	// lfd f0,120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fsubs f31,f12,f31
	ctx.f31.f64 = double(float(ctx.f12.f64 - ctx.f31.f64));
loc_820A9FB4:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A9FC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// lfs f14,18248(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18248);
	ctx.f14.f64 = double(temp.f32);
	// lfs f19,9540(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9540);
	ctx.f19.f64 = double(temp.f32);
	// beq cr6,0x820aa034
	if (ctx.cr6.eq) goto loc_820AA034;
	// lwz r9,196(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 196);
	// lfs f0,156(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f0.f64 = double(temp.f32);
	// lwz r8,164(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// std r9,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r9.u64);
	// lfd f12,120(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// std r8,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r8.u64);
	// lfd f11,120(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fdivs f6,f31,f8
	ctx.f6.f64 = double(float(ctx.f31.f64 / ctx.f8.f64));
	// fdivs f5,f26,f7
	ctx.f5.f64 = double(float(ctx.f26.f64 / ctx.f7.f64));
	// fsubs f4,f19,f6
	ctx.f4.f64 = double(float(ctx.f19.f64 - ctx.f6.f64));
	// fsubs f3,f5,f14
	ctx.f3.f64 = double(float(ctx.f5.f64 - ctx.f14.f64));
	// fsubs f2,f4,f14
	ctx.f2.f64 = double(float(ctx.f4.f64 - ctx.f14.f64));
	// fdivs f26,f3,f0
	ctx.f26.f64 = double(float(ctx.f3.f64 / ctx.f0.f64));
	// fdivs f23,f2,f13
	ctx.f23.f64 = double(float(ctx.f2.f64 / ctx.f13.f64));
	// b 0x820aa038
	goto loc_820AA038;
loc_820AA034:
	// fmr f23,f31
	ctx.fpscr.disableFlushMode();
	ctx.f23.f64 = ctx.f31.f64;
loc_820AA038:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r5,r1,168
	ctx.r5.s64 = ctx.r1.s64 + 168;
	// addi r4,r1,172
	ctx.r4.s64 = ctx.r1.s64 + 172;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820AA054;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,172(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,168(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// fmuls f13,f13,f28
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f28.f64));
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r9,0
	ctx.r9.s64 = 0;
	// fmr f2,f19
	ctx.f2.f64 = ctx.f19.f64;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// fmr f1,f19
	ctx.f1.f64 = ctx.f19.f64;
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lfs f25,9536(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9536);
	ctx.f25.f64 = double(temp.f32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f24,f25
	ctx.f24.f64 = ctx.f25.f64;
	// fmr f17,f0
	ctx.f17.f64 = ctx.f0.f64;
	// fmr f16,f13
	ctx.f16.f64 = ctx.f13.f64;
	// bl 0x820a9d78
	ctx.lr = 0x820AA0A0;
	sub_820A9D78(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lfs f12,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,9680(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9680);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// bl 0x82129038
	ctx.lr = 0x820AA0B4;
	sub_82129038(ctx, base);
	// lhz r6,0(r26)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r26.u32 + 0);
	// li r21,1
	ctx.r21.s64 = 1;
	// frsp f15,f1
	ctx.fpscr.disableFlushMode();
	ctx.f15.f64 = double(float(ctx.f1.f64));
	// mr r23,r26
	ctx.r23.u64 = ctx.r26.u64;
	// mr r27,r21
	ctx.r27.u64 = ctx.r21.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x820aa0e0
	if (ctx.cr6.eq) goto loc_820AA0E0;
loc_820AA0D0:
	// addi r23,r23,2
	ctx.r23.s64 = ctx.r23.s64 + 2;
	// lhz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r23.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820aa0d0
	if (!ctx.cr6.eq) goto loc_820AA0D0;
loc_820AA0E0:
	// mr r25,r26
	ctx.r25.u64 = ctx.r26.u64;
	// cmplw cr6,r26,r23
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r23.u32, ctx.xer);
	// bge cr6,0x820aa448
	if (!ctx.cr6.lt) goto loc_820AA448;
	// lwz r24,644(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 644);
	// li r22,0
	ctx.r22.s64 = 0;
loc_820AA0F4:
	// clrlwi r11,r27,24
	ctx.r11.u64 = ctx.r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820aa160
	if (ctx.cr6.eq) goto loc_820AA160;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x820aa110
	if (ctx.cr6.eq) goto loc_820AA110;
	// cmplwi cr6,r24,2
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 2, ctx.xer);
	// bne cr6,0x820aa15c
	if (!ctx.cr6.eq) goto loc_820AA15C;
loc_820AA110:
	// li r9,0
	ctx.r9.s64 = 0;
	// fmr f2,f19
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f19.f64;
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// fmr f1,f19
	ctx.f1.f64 = ctx.f19.f64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820a9d78
	ctx.lr = 0x820AA130;
	sub_820A9D78(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// bne cr6,0x820aa144
	if (!ctx.cr6.eq) goto loc_820AA144;
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f1,f26,f0
	ctx.f1.f64 = double(float(ctx.f26.f64 - ctx.f0.f64));
	// b 0x820aa154
	goto loc_820AA154;
loc_820AA144:
	// cmplwi cr6,r24,2
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 2, ctx.xer);
	// bne cr6,0x820aa15c
	if (!ctx.cr6.eq) goto loc_820AA15C;
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f1,f0,f14,f26
	ctx.f1.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f14.f64, -ctx.f26.f64)));
loc_820AA154:
	// bl 0x82129038
	ctx.lr = 0x820AA158;
	sub_82129038(ctx, base);
	// frsp f24,f1
	ctx.fpscr.disableFlushMode();
	ctx.f24.f64 = double(float(ctx.f1.f64));
loc_820AA15C:
	// mr r27,r22
	ctx.r27.u64 = ctx.r22.u64;
loc_820AA160:
	// lhz r29,0(r25)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r25.u32 + 0);
	// cmplwi cr6,r29,10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 10, ctx.xer);
	// bne cr6,0x820aa1b0
	if (!ctx.cr6.eq) goto loc_820AA1B0;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// fmr f24,f26
	ctx.fpscr.disableFlushMode();
	ctx.f24.f64 = ctx.f26.f64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,68(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820AA184;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,108(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 108);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// beq cr6,0x820aa1a4
	if (ctx.cr6.eq) goto loc_820AA1A4;
	// fsubs f15,f15,f0
	ctx.f15.f64 = double(float(ctx.f15.f64 - ctx.f0.f64));
	// mr r27,r21
	ctx.r27.u64 = ctx.r21.u64;
	// b 0x820aa43c
	goto loc_820AA43C;
loc_820AA1A4:
	// fadds f15,f0,f15
	ctx.fpscr.disableFlushMode();
	ctx.f15.f64 = double(float(ctx.f0.f64 + ctx.f15.f64));
	// mr r27,r21
	ctx.r27.u64 = ctx.r21.u64;
	// b 0x820aa43c
	goto loc_820AA43C;
loc_820AA1B0:
	// lwz r10,112(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 112);
	// rlwinm r9,r29,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,116(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 116);
	// lhzx r8,r9,r10
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// rotlwi r10,r8,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 4);
	// add. r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x820aa43c
	if (ctx.cr0.eq) goto loc_820AA43C;
	// lhz r11,10(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 10);
	// fsubs f31,f15,f14
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f15.f64 - ctx.f14.f64));
	// lhz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// extsh r6,r11
	ctx.r6.s64 = ctx.r11.s16;
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// extsh r5,r10
	ctx.r5.s64 = ctx.r10.s16;
	// std r6,264(r1)
	REX_STORE_U64(ctx.r1.u32 + 264, ctx.r6.u64);
	// lfd f12,264(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 264);
	// std r5,280(r1)
	REX_STORE_U64(ctx.r1.u32 + 280, ctx.r5.u64);
	// lfd f0,280(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 280);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// lwz r4,68(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + 68);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// fadds f28,f11,f24
	ctx.f28.f64 = double(float(ctx.f11.f64 + ctx.f24.f64));
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fsubs f30,f28,f14
	ctx.f30.f64 = double(float(ctx.f28.f64 - ctx.f14.f64));
	// fadds f8,f9,f19
	ctx.f8.f64 = double(float(ctx.f9.f64 + ctx.f19.f64));
	// fadds f27,f8,f30
	ctx.f27.f64 = double(float(ctx.f8.f64 + ctx.f30.f64));
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x820AA224;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,108(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 108);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f13,f0,f19
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f19.f64));
	// beq cr6,0x820aa244
	if (ctx.cr6.eq) goto loc_820AA244;
	// fsubs f29,f31,f13
	ctx.f29.f64 = double(float(ctx.f31.f64 - ctx.f13.f64));
	// b 0x820aa248
	goto loc_820AA248;
loc_820AA244:
	// fadds f29,f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = double(float(ctx.f13.f64 + ctx.f31.f64));
loc_820AA248:
	// lhz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// cmplwi cr6,r29,32
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 32, ctx.xer);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// std r9,296(r1)
	REX_STORE_U64(ctx.r1.u32 + 296, ctx.r9.u64);
	// lfd f0,296(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 296);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fadds f24,f12,f28
	ctx.f24.f64 = double(float(ctx.f12.f64 + ctx.f28.f64));
	// beq cr6,0x820aa43c
	if (ctx.cr6.eq) goto loc_820AA43C;
	// lhz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r5,28(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 28);
	// extsw r6,r10
	ctx.r6.s64 = ctx.r10.s32;
	// lhz r10,2(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 2);
	// lwz r4,32(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 32);
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// lhz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// std r6,272(r1)
	REX_STORE_U64(ctx.r1.u32 + 272, ctx.r6.u64);
	// std r5,248(r1)
	REX_STORE_U64(ctx.r1.u32 + 248, ctx.r5.u64);
	// lfd f0,248(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 248);
	// std r7,304(r1)
	REX_STORE_U64(ctx.r1.u32 + 304, ctx.r7.u64);
	// lfd f10,304(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 304);
	// std r4,288(r1)
	REX_STORE_U64(ctx.r1.u32 + 288, ctx.r4.u64);
	// lfd f11,288(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 288);
	// extsw r8,r11
	ctx.r8.s64 = ctx.r11.s32;
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// stfs f25,128(r1)
	temp.f32 = float(ctx.f25.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// std r8,256(r1)
	REX_STORE_U64(ctx.r1.u32 + 256, ctx.r8.u64);
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stfs f25,132(r1)
	temp.f32 = float(ctx.f25.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// std r9,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r9.u64);
	// lfd f8,176(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 176);
	// fcfid f3,f8
	ctx.f3.f64 = double(ctx.f8.s64);
	// stfs f25,136(r1)
	temp.f32 = float(ctx.f25.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lfd f13,256(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 256);
	// fcfid f6,f11
	ctx.f6.f64 = double(ctx.f11.s64);
	// lfd f12,272(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 272);
	// fcfid f5,f0
	ctx.f5.f64 = double(ctx.f0.s64);
	// fcfid f7,f12
	ctx.f7.f64 = double(ctx.f12.s64);
	// lwz r6,76(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 76);
	// fcfid f4,f13
	ctx.f4.f64 = double(ctx.f13.s64);
	// stfs f25,144(r1)
	temp.f32 = float(ctx.f25.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// stfs f25,148(r1)
	temp.f32 = float(ctx.f25.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// frsp f11,f3
	ctx.f11.f64 = double(float(ctx.f3.f64));
	// stfs f25,152(r1)
	temp.f32 = float(ctx.f25.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// frsp f0,f6
	ctx.f0.f64 = double(float(ctx.f6.f64));
	// frsp f13,f5
	ctx.f13.f64 = double(float(ctx.f5.f64));
	// frsp f1,f7
	ctx.f1.f64 = double(float(ctx.f7.f64));
	// frsp f12,f4
	ctx.f12.f64 = double(float(ctx.f4.f64));
	// frsp f2,f9
	ctx.f2.f64 = double(float(ctx.f9.f64));
	// fdivs f20,f11,f0
	ctx.f20.f64 = double(float(ctx.f11.f64 / ctx.f0.f64));
	// fdivs f21,f1,f13
	ctx.f21.f64 = double(float(ctx.f1.f64 / ctx.f13.f64));
	// fdivs f22,f12,f13
	ctx.f22.f64 = double(float(ctx.f12.f64 / ctx.f13.f64));
	// fdivs f28,f2,f0
	ctx.f28.f64 = double(float(ctx.f2.f64 / ctx.f0.f64));
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820AA330;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820aa3a8
	if (ctx.cr6.eq) goto loc_820AA3A8;
	// fmuls f13,f16,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f16.f64 * ctx.f31.f64));
	// stfs f18,192(r1)
	temp.f32 = float(ctx.f18.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// fmuls f12,f17,f27
	ctx.f12.f64 = double(float(ctx.f17.f64 * ctx.f27.f64));
	// stfs f18,208(r1)
	temp.f32 = float(ctx.f18.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// fmuls f0,f17,f30
	ctx.f0.f64 = double(float(ctx.f17.f64 * ctx.f30.f64));
	// lwz r10,208(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 208);
	// fmuls f11,f16,f29
	ctx.f11.f64 = double(float(ctx.f16.f64 * ctx.f29.f64));
	// stw r10,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r10.u32);
	// fadds f9,f13,f23
	ctx.f9.f64 = double(float(ctx.f13.f64 + ctx.f23.f64));
	// stfs f9,188(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// fadds f8,f12,f26
	ctx.f8.f64 = double(float(ctx.f12.f64 + ctx.f26.f64));
	// stfs f8,200(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// lwz r7,188(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 188);
	// fadds f10,f0,f26
	ctx.f10.f64 = double(float(ctx.f0.f64 + ctx.f26.f64));
	// lwz r6,200(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 200);
	// stfs f10,184(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// lwz r11,192(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 192);
	// fadds f7,f11,f23
	ctx.f7.f64 = double(float(ctx.f11.f64 + ctx.f23.f64));
	// stfs f7,204(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// lwz r8,204(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 204);
	// stw r8,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r8.u32);
	// lwz r9,184(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
	// stw r11,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r11.u32);
	// stw r7,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r7.u32);
	// stw r6,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r6.u32);
	// stw r9,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// b 0x820aa400
	goto loc_820AA400;
loc_820AA3A8:
	// fadds f11,f30,f26
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f30.f64 + ctx.f26.f64));
	// stfs f11,216(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// lwz r6,216(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 216);
	// fadds f0,f27,f26
	ctx.f0.f64 = double(float(ctx.f27.f64 + ctx.f26.f64));
	// fadds f13,f29,f23
	ctx.f13.f64 = double(float(ctx.f29.f64 + ctx.f23.f64));
	// stfs f0,232(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// fadds f12,f31,f23
	ctx.f12.f64 = double(float(ctx.f31.f64 + ctx.f23.f64));
	// stfs f13,236(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f18,240(r1)
	temp.f32 = float(ctx.f18.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f12,220(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f18,224(r1)
	temp.f32 = float(ctx.f18.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// lwz r7,224(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 224);
	// stw r7,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r7.u32);
	// lwz r11,232(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 232);
	// lwz r10,236(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 236);
	// lwz r9,240(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 240);
	// lwz r8,220(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 220);
	// stw r6,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r6.u32);
	// stw r11,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r11.u32);
	// stw r10,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r10.u32);
	// stw r9,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r9.u32);
	// stw r8,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r8.u32);
loc_820AA400:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// fmr f5,f25
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = ctx.f25.f64;
	// stw r21,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r21.u32);
	// mr r10,r20
	ctx.r10.u64 = ctx.r20.u64;
	// stb r22,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r22.u8);
	// fmr f4,f20
	ctx.f4.f64 = ctx.f20.f64;
	// fmr f3,f21
	ctx.f3.f64 = ctx.f21.f64;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// fmr f2,f28
	ctx.f2.f64 = ctx.f28.f64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r9,112(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// fmr f1,f22
	ctx.f1.f64 = ctx.f22.f64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820AA43C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820AA43C:
	// addi r25,r25,2
	ctx.r25.s64 = ctx.r25.s64 + 2;
	// cmplw cr6,r25,r23
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r23.u32, ctx.xer);
	// blt cr6,0x820aa0f4
	if (ctx.cr6.lt) goto loc_820AA0F4;
loc_820AA448:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820AA460;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,560
	ctx.r1.s64 = ctx.r1.s64 + 560;
	// addi r12,r1,-104
	ctx.r12.s64 = ctx.r1.s64 + -104;
	// bl 0x8212a86c
	ctx.lr = 0x820AA470;
	__restfpr_14(ctx, base);
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
loc_820AA474:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,560
	ctx.r1.s64 = ctx.r1.s64 + 560;
	// addi r12,r1,-104
	ctx.r12.s64 = ctx.r1.s64 + -104;
	// bl 0x8212a86c
	ctx.lr = 0x820AA484;
	__restfpr_14(ctx, base);
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
}
