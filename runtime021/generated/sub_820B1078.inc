DEFINE_REX_FUNC(sub_820B1078) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x820B1080;
	__savegprlr_22(ctx, base);
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// mr r24,r7
	ctx.r24.u64 = ctx.r7.u64;
	// lbz r10,-22601(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// mr r28,r9
	ctx.r28.u64 = ctx.r9.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820b10c8
	if (!ctx.cr6.eq) goto loc_820B10C8;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r3,r11,-1768
	ctx.r3.s64 = ctx.r11.s64 + -1768;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820B10C8;
	sub_820A71E8(ctx, base);
loc_820B10C8:
	// bl 0x820b5eb8
	ctx.lr = 0x820B10CC;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,29632
	ctx.r9.s64 = ctx.r11.s64 + 29632;
	// li r4,596
	ctx.r4.s64 = 596;
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820B10E4;
	sub_8209BDD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820b1364
	if (ctx.cr6.eq) goto loc_820B1364;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r31,r30,4
	ctx.r31.s64 = ctx.r30.s64 + 4;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// lfs f0,9540(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r31,148
	ctx.r10.s64 = ctx.r31.s64 + 148;
	// addi r10,r31,340
	ctx.r10.s64 = ctx.r31.s64 + 340;
	// stfs f0,244(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 244, temp.u32);
	// li r10,3
	ctx.r10.s64 = 3;
	// lfs f31,9536(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// stfs f0,256(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 256, temp.u32);
	// stw r11,264(r30)
	REX_STORE_U32(ctx.r30.u32 + 264, ctx.r11.u32);
	// subfc r8,r10,r28
	ctx.xer.ca = ctx.r28.u32 >= ctx.r10.u32;
	ctx.r8.u64 = ctx.r28.u64 - ctx.r10.u64;
	// stfs f31,252(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 252, temp.u32);
	// stfs f31,248(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 248, temp.u32);
	// stw r11,260(r30)
	REX_STORE_U32(ctx.r30.u32 + 260, ctx.r11.u32);
	// subfe r10,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stfs f0,276(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 276, temp.u32);
	// stfs f0,288(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 288, temp.u32);
	// stw r11,296(r30)
	REX_STORE_U32(ctx.r30.u32 + 296, ctx.r11.u32);
	// stfs f31,284(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 284, temp.u32);
	// stw r11,292(r30)
	REX_STORE_U32(ctx.r30.u32 + 292, ctx.r11.u32);
	// stfs f31,280(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 280, temp.u32);
	// stw r11,328(r30)
	REX_STORE_U32(ctx.r30.u32 + 328, ctx.r11.u32);
	// stfs f0,308(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 308, temp.u32);
	// stw r11,324(r30)
	REX_STORE_U32(ctx.r30.u32 + 324, ctx.r11.u32);
	// stfs f0,320(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 320, temp.u32);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stfs f31,316(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 316, temp.u32);
	// rotlwi r10,r29,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r29.u32, 0);
	// stfs f31,312(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 312, temp.u32);
	// stw r11,456(r30)
	REX_STORE_U32(ctx.r30.u32 + 456, ctx.r11.u32);
	// stfs f0,436(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 436, temp.u32);
	// stw r11,452(r30)
	REX_STORE_U32(ctx.r30.u32 + 452, ctx.r11.u32);
	// stfs f0,448(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 448, temp.u32);
	// li r9,255
	ctx.r9.s64 = 255;
	// stfs f31,444(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 444, temp.u32);
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// stfs f31,440(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 440, temp.u32);
	// stw r11,488(r30)
	REX_STORE_U32(ctx.r30.u32 + 488, ctx.r11.u32);
	// stfs f0,468(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 468, temp.u32);
	// stw r11,484(r30)
	REX_STORE_U32(ctx.r30.u32 + 484, ctx.r11.u32);
	// stfs f0,480(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 480, temp.u32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stfs f31,476(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 476, temp.u32);
	// stfs f31,472(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 472, temp.u32);
	// stw r11,520(r30)
	REX_STORE_U32(ctx.r30.u32 + 520, ctx.r11.u32);
	// stfs f0,500(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 500, temp.u32);
	// stw r11,516(r30)
	REX_STORE_U32(ctx.r30.u32 + 516, ctx.r11.u32);
	// stfs f0,512(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 512, temp.u32);
	// stfs f31,508(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 508, temp.u32);
	// stfs f31,504(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 504, temp.u32);
	// stw r11,592(r30)
	REX_STORE_U32(ctx.r30.u32 + 592, ctx.r11.u32);
	// stfs f0,572(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 572, temp.u32);
	// stw r11,588(r30)
	REX_STORE_U32(ctx.r30.u32 + 588, ctx.r11.u32);
	// stfs f0,584(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 584, temp.u32);
	// stfs f31,580(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 580, temp.u32);
	// stfs f31,576(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 576, temp.u32);
	// stw r11,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// stb r11,152(r31)
	REX_STORE_U8(ctx.r31.u32 + 152, ctx.r11.u8);
	// stb r11,153(r31)
	REX_STORE_U8(ctx.r31.u32 + 153, ctx.r11.u8);
	// stb r11,154(r31)
	REX_STORE_U8(ctx.r31.u32 + 154, ctx.r11.u8);
	// stw r11,328(r31)
	REX_STORE_U32(ctx.r31.u32 + 328, ctx.r11.u32);
	// stw r29,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r9,155(r31)
	REX_STORE_U8(ctx.r31.u32 + 155, ctx.r9.u8);
	// stb r7,537(r31)
	REX_STORE_U8(ctx.r31.u32 + 537, ctx.r7.u8);
	// stb r6,536(r31)
	REX_STORE_U8(ctx.r31.u32 + 536, ctx.r6.u8);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r5,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r5.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_820B1214:
	// lwz r9,16(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// subfic r8,r10,24
	ctx.xer.ca = ctx.r10.u32 <= 24;
	ctx.r8.u64 = static_cast<uint64_t>(24) - ctx.r10.u64;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// lbz r6,0(r9)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// stw r7,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r7.u32);
	// slw r5,r6,r8
	ctx.r5.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r8.u8 & 0x3F));
	// or r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 | ctx.r11.u64;
	// blt cr6,0x820b1214
	if (ctx.cr6.lt) goto loc_820B1214;
	// addi r10,r10,-5
	ctx.r10.s64 = ctx.r10.s64 + -5;
	// rlwinm r9,r11,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// rlwinm r23,r11,5,27,31
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0x1F;
	// stw r9,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// bl 0x820b4b20
	ctx.lr = 0x820B125C;
	sub_820B4B20(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b4b20
	ctx.lr = 0x820B1268;
	sub_820B4B20(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b4b20
	ctx.lr = 0x820B1274;
	sub_820B4B20(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b4b20
	ctx.lr = 0x820B1280;
	sub_820B4B20(ctx, base);
	// subf r8,r29,r22
	ctx.r8.u64 = ctx.r22.u64 - ctx.r29.u64;
	// subf r7,r28,r3
	ctx.r7.u64 = ctx.r3.u64 - ctx.r28.u64;
	// stw r3,12(r27)
	REX_STORE_U32(ctx.r27.u32 + 12, ctx.r3.u32);
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// stw r29,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r29.u32);
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// stw r22,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r22.u32);
	// std r6,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r6.u64);
	// lfd f0,144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// std r5,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r5.u64);
	// lfd f13,144(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// lis r3,-32218
	ctx.r3.s64 = -2111438848;
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// lwz r11,-6624(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + -6624);
	// stw r28,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r28.u32);
	// addi r31,r30,556
	ctx.r31.s64 = ctx.r30.s64 + 556;
	// addi r27,r30,552
	ctx.r27.s64 = ctx.r30.s64 + 552;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// lfs f0,9572(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 9572);
	ctx.f0.f64 = double(temp.f32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// stfs f8,544(r30)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r30.u32 + 544, temp.u32);
	// fmuls f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// stfs f7,548(r30)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r30.u32 + 548, temp.u32);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// fctiwz f6,f8
	ctx.f6.s64 = std::isnan(ctx.f8.f64) ? int64_t(0x80000000U) : (ctx.f8.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f6,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f6.u64);
	// lwz r4,148(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// fctiwz f5,f7
	ctx.f5.s64 = std::isnan(ctx.f7.f64) ? int64_t(0x80000000U) : (ctx.f7.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f5,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f5.u64);
	// lwz r5,148(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,124(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820B131C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,552(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 552);
	// lwz r8,556(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 556);
	// li r6,1028
	ctx.r6.s64 = 1028;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// mullw r7,r9,r8
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// rlwinm r3,r7,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,-1
	ctx.r4.s64 = -1;
	// stw r3,560(r30)
	REX_STORE_U32(ctx.r30.u32 + 560, ctx.r3.u32);
	// bl 0x820b6108
	ctx.lr = 0x820B1340;
	sub_820B6108(ctx, base);
	// stw r3,564(r30)
	REX_STORE_U32(ctx.r30.u32 + 564, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820b1374
	if (!ctx.cr6.eq) goto loc_820B1374;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820b1008
	ctx.lr = 0x820B1358;
	sub_820B1008(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,9420
	ctx.r3.s64 = ctx.r11.s64 + 9420;
	// bl 0x8208c5d8
	ctx.lr = 0x820B1364;
	sub_8208C5D8(ctx, base);
loc_820B1364:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_820B1374:
	// neg r11,r29
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r29.u64);
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// neg r9,r28
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r28.u64);
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// extsw r7,r11
	ctx.r7.s64 = ctx.r11.s32;
	// lfs f12,544(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 544);
	ctx.f12.f64 = double(temp.f32);
	// extsw r6,r9
	ctx.r6.s64 = ctx.r9.s32;
	// lfs f11,548(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 548);
	ctx.f11.f64 = double(temp.f32);
	// std r7,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r7.u64);
	// extsw r5,r10
	ctx.r5.s64 = ctx.r10.s32;
	// lfd f10,144(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// extsw r4,r8
	ctx.r4.s64 = ctx.r8.s32;
	// std r6,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r6.u64);
	// lfd f9,144(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// std r5,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r5.u64);
	// lfd f6,152(r1)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// std r4,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r4.u64);
	// lfd f8,144(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f5,f10
	ctx.f5.f64 = double(ctx.f10.s64);
	// stw r3,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r3.u32);
	// fcfid f3,f9
	ctx.f3.f64 = double(ctx.f9.s64);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// fcfid f4,f6
	ctx.f4.f64 = double(ctx.f6.s64);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// li r9,588
	ctx.r9.s64 = 588;
	// frsp f1,f5
	ctx.f1.f64 = double(float(ctx.f5.f64));
	// li r7,592
	ctx.r7.s64 = 592;
	// stfs f31,576(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 576, temp.u32);
	// stw r10,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r10.u32);
	// lfs f0,9844(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 9844);
	ctx.f0.f64 = double(temp.f32);
	// stw r8,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r8.u32);
	// lfs f13,9840(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9840);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32215
	ctx.r6.s64 = -2111242240;
	// stfs f31,580(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 580, temp.u32);
	// addi r31,r6,-22712
	ctx.r31.s64 = ctx.r6.s64 + -22712;
	// frsp f9,f3
	ctx.f9.f64 = double(float(ctx.f3.f64));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// frsp f10,f4
	ctx.f10.f64 = double(float(ctx.f4.f64));
	// frsp f2,f7
	ctx.f2.f64 = double(float(ctx.f7.f64));
	// fdivs f7,f10,f12
	ctx.f7.f64 = double(float(ctx.f10.f64 / ctx.f12.f64));
	// fdivs f8,f2,f11
	ctx.f8.f64 = double(float(ctx.f2.f64 / ctx.f11.f64));
	// fmuls f4,f1,f7
	ctx.f4.f64 = double(float(ctx.f1.f64 * ctx.f7.f64));
	// fmuls f6,f9,f8
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64));
	// fmuls f5,f8,f13
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// stfs f5,584(r30)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r30.u32 + 584, temp.u32);
	// fmuls f3,f7,f0
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// stfs f3,572(r30)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r30.u32 + 572, temp.u32);
	// fmuls f1,f4,f0
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f0.f64));
	// fmuls f2,f6,f13
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// fctiwz f13,f1
	ctx.f13.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfiwx f13,r30,r9
	REX_STORE_U32(ctx.r30.u32 + ctx.r9.u32, ctx.f13.u32);
	// fctiwz f0,f2
	ctx.f0.s64 = std::isnan(ctx.f2.f64) ? int64_t(0x80000000U) : (ctx.f2.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfiwx f0,r30,r7
	REX_STORE_U32(ctx.r30.u32 + ctx.r7.u32, ctx.f0.u32);
	// bl 0x8214a434
	ctx.lr = 0x820B1450;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,-22672(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + -22672);
	// stw r30,-22672(r5)
	REX_STORE_U32(ctx.r5.u32 + -22672, ctx.r30.u32);
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// bl 0x8214a444
	ctx.lr = 0x820B1468;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
