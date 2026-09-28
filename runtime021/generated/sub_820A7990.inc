DEFINE_REX_FUNC(sub_820A7990) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x820A7998;
	__savegprlr_25(ctx, base);
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f30.u64);
	// stfd f31,-72(r1)
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r8,-32218
	ctx.r8.s64 = -2111438848;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r11,r1,288
	ctx.r11.s64 = ctx.r1.s64 + 288;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// lwz r31,-6616(r8)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r8.u32 + -6616);
	// li r10,6
	ctx.r10.s64 = 6;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820A79C4:
	// std r9,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r9.u64);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// bdnz 0x820a79c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820A79C4;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x8214a214
	ctx.lr = 0x820A79D8;
	__imp__XGetVideoMode(ctx, base);
	// lwz r9,300(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 300);
	// lwz r6,304(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 304);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// lwz r7,312(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 312);
	// cntlzw r5,r9
	ctx.r5.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// cntlzw r3,r6
	ctx.r3.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// addi r4,r7,-3
	ctx.r4.s64 = ctx.r7.s64 + -3;
	// rlwinm r9,r5,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// rlwinm r6,r3,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// cntlzw r5,r4
	ctx.r5.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// xori r7,r9,1
	ctx.r7.u64 = ctx.r9.u64 ^ 1;
	// xori r9,r6,1
	ctx.r9.u64 = ctx.r6.u64 ^ 1;
	// rlwinm r6,r5,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// stb r7,28712(r31)
	REX_STORE_U8(ctx.r31.u32 + 28712, ctx.r7.u8);
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// stb r9,28713(r31)
	REX_STORE_U8(ctx.r31.u32 + 28713, ctx.r9.u8);
	// li r10,15
	ctx.r10.s64 = 15;
	// stb r6,28714(r31)
	REX_STORE_U8(ctx.r31.u32 + 28714, ctx.r6.u8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820A7A24:
	// std r8,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r8.u64);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// bdnz 0x820a7a24
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820A7A24;
	// clrlwi r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a7a64
	if (ctx.cr6.eq) goto loc_820A7A64;
	// clrlwi r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1280
	ctx.r11.s64 = 1280;
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// beq cr6,0x820a7a5c
	if (ctx.cr6.eq) goto loc_820A7A5C;
	// li r10,720
	ctx.r10.s64 = 720;
	// b 0x820a7a70
	goto loc_820A7A70;
loc_820A7A5C:
	// li r10,960
	ctx.r10.s64 = 960;
	// b 0x820a7a70
	goto loc_820A7A70;
loc_820A7A64:
	// li r11,640
	ctx.r11.s64 = 640;
	// li r10,480
	ctx.r10.s64 = 480;
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
loc_820A7A70:
	// clrlwi r11,r6,24
	ctx.r11.u64 = ctx.r6.u32 & 0xFF;
	// stw r10,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a7aa4
	if (ctx.cr6.eq) goto loc_820A7AA4;
	// clrlwi r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a7aa4
	if (!ctx.cr6.eq) goto loc_820A7AA4;
	// lwz r11,292(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// cmplwi cr6,r11,576
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 576, ctx.xer);
	// bne cr6,0x820a7aa4
	if (!ctx.cr6.eq) goto loc_820A7AA4;
	// lwz r11,204(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 204);
	// ori r10,r11,1
	ctx.r10.u64 = ctx.r11.u64 | 1;
	// stw r10,204(r1)
	REX_STORE_U32(ctx.r1.u32 + 204, ctx.r10.u32);
loc_820A7AA4:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f13,308(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 308);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,6184
	ctx.r10.s64 = 405274624;
	// stw r28,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r28.u32);
	// lis r9,11552
	ctx.r9.s64 = 757071872;
	// stw r28,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r28.u32);
	// li r29,1
	ctx.r29.s64 = 1;
	// ori r25,r10,390
	ctx.r25.u64 = ctx.r10.u64 | 390;
	// ori r8,r9,406
	ctx.r8.u64 = ctx.r9.u64 | 406;
	// lfs f0,9848(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9848);
	ctx.f0.f64 = double(temp.f32);
	// stw r25,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r25.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// stw r29,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r29.u32);
	// stw r29,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r29.u32);
	// stw r8,200(r1)
	REX_STORE_U32(ctx.r1.u32 + 200, ctx.r8.u32);
	// stw r29,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r29.u32);
	// bge cr6,0x820a7af4
	if (!ctx.cr6.lt) goto loc_820A7AF4;
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// stw r11,212(r1)
	REX_STORE_U32(ctx.r1.u32 + 212, ctx.r11.u32);
	// b 0x820a7af8
	goto loc_820A7AF8;
loc_820A7AF4:
	// stw r29,212(r1)
	REX_STORE_U32(ctx.r1.u32 + 212, ctx.r29.u32);
loc_820A7AF8:
	// addi r30,r31,4
	ctx.r30.s64 = ctx.r31.s64 + 4;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x820befd0
	ctx.lr = 0x820A7B18;
	sub_820BEFD0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x820a7b34
	if (!ctx.cr6.lt) goto loc_820A7B34;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,7908
	ctx.r3.s64 = ctx.r11.s64 + 7908;
	// bl 0x8208c5d8
	ctx.lr = 0x820A7B2C;
	sub_8208C5D8(ctx, base);
	// stw r29,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r29.u32);
	// b 0x820a7dc4
	goto loc_820A7DC4;
loc_820A7B34:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,15
	ctx.r6.s64 = 15;
	// lfs f31,9540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9540);
	ctx.f31.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x820c2c98
	ctx.lr = 0x820A7B60;
	sub_820C2C98(ctx, base);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x820c13b8
	ctx.lr = 0x820A7B68;
	sub_820C13B8(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// li r6,15
	ctx.r6.s64 = 15;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820c2c98
	ctx.lr = 0x820A7B8C;
	sub_820C2C98(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// fmr f4,f31
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = ctx.f31.f64;
	// lwz r8,160(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r7,164(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// lfs f30,9536(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9536);
	ctx.f30.f64 = double(temp.f32);
	// lwz r6,28(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 28);
	// fmr f3,f30
	ctx.f3.f64 = ctx.f30.f64;
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// stw r8,28720(r31)
	REX_STORE_U32(ctx.r31.u32 + 28720, ctx.r8.u32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// stw r7,28724(r31)
	REX_STORE_U32(ctx.r31.u32 + 28724, ctx.r7.u32);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820A7BC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r5,28720(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 28720);
	// stfs f30,28756(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 28756, temp.u32);
	// lwz r4,28724(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 28724);
	// stfs f31,28760(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 28760, temp.u32);
	// stw r28,29124(r31)
	REX_STORE_U32(ctx.r31.u32 + 29124, ctx.r28.u32);
	// mr r27,r28
	ctx.r27.u64 = ctx.r28.u64;
	// stw r28,28740(r31)
	REX_STORE_U32(ctx.r31.u32 + 28740, ctx.r28.u32);
	// stw r28,28744(r31)
	REX_STORE_U32(ctx.r31.u32 + 28744, ctx.r28.u32);
	// stw r5,28748(r31)
	REX_STORE_U32(ctx.r31.u32 + 28748, ctx.r5.u32);
	// stw r4,28752(r31)
	REX_STORE_U32(ctx.r31.u32 + 28752, ctx.r4.u32);
loc_820A7BF0:
	// rlwinm r11,r27,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,0(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// add r11,r27,r11
	ctx.r11.u64 = ctx.r27.u64 + ctx.r11.u64;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r4,r11,29836
	ctx.r4.s64 = ctx.r11.s64 + 29836;
	// bl 0x820aa5b8
	ctx.lr = 0x820A7C14;
	sub_820AA5B8(ctx, base);
	// addi r10,r27,1
	ctx.r10.s64 = ctx.r27.s64 + 1;
	// clrlwi r27,r10,16
	ctx.r27.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r27,17
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 17, ctx.xer);
	// blt cr6,0x820a7bf0
	if (ctx.cr6.lt) goto loc_820A7BF0;
	// addi r11,r31,29836
	ctx.r11.s64 = ctx.r31.s64 + 29836;
	// stb r29,28715(r31)
	REX_STORE_U8(ctx.r31.u32 + 28715, ctx.r29.u8);
	// li r5,28672
	ctx.r5.s64 = 28672;
	// stw r28,30208(r31)
	REX_STORE_U32(ctx.r31.u32 + 30208, ctx.r28.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,30176(r31)
	REX_STORE_U32(ctx.r31.u32 + 30176, ctx.r11.u32);
	// addi r3,r31,40
	ctx.r3.s64 = ctx.r31.s64 + 40;
	// bl 0x82129fa0
	ctx.lr = 0x820A7C44;
	sub_82129FA0(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r9,3
	ctx.r9.s64 = 3;
	// stfs f31,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stw r28,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// addi r3,r31,29192
	ctx.r3.s64 = ctx.r31.s64 + 29192;
	// stw r9,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stw r29,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r29.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// lfs f0,18248(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 18248);
	ctx.f0.f64 = double(temp.f32);
	// stw r29,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r29.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stw r29,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r29.u32);
	// stw r28,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r28.u32);
	// stw r28,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r28.u32);
	// stw r28,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// stw r28,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r28.u32);
	// stw r29,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r29.u32);
	// stw r29,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r29.u32);
	// stw r29,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r29.u32);
	// stb r28,148(r1)
	REX_STORE_U8(ctx.r1.u32 + 148, ctx.r28.u8);
	// stb r28,156(r1)
	REX_STORE_U8(ctx.r1.u32 + 156, ctx.r28.u8);
	// stw r28,29832(r31)
	REX_STORE_U32(ctx.r31.u32 + 29832, ctx.r28.u32);
	// bl 0x82129a70
	ctx.lr = 0x820A7CA4;
	sub_82129A70(ctx, base);
	// lwz r11,29832(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 29832);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,29832(r31)
	REX_STORE_U32(ctx.r31.u32 + 29832, ctx.r11.u32);
	// rlwinm r11,r11,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r4,r11,29128
	ctx.r4.s64 = ctx.r11.s64 + 29128;
	// bl 0x820a8190
	ctx.lr = 0x820A7CC8;
	sub_820A8190(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x820bb6a8
	ctx.lr = 0x820A7CD4;
	sub_820BB6A8(ctx, base);
	// lwz r27,30176(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 30176);
	// lwz r4,12(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 12);
	// lwz r3,4(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x820bfee8
	ctx.lr = 0x820A7CE4;
	sub_820BFEE8(ctx, base);
	// lwz r4,8(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// lwz r3,4(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x820bfc30
	ctx.lr = 0x820A7CF0;
	sub_820BFC30(ctx, base);
	// lwz r4,16(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 16);
	// lwz r3,4(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x820c00b8
	ctx.lr = 0x820A7CFC;
	sub_820C00B8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x820bb6a8
	ctx.lr = 0x820A7D08;
	sub_820BB6A8(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x820bd0f8
	ctx.lr = 0x820A7D18;
	sub_820BD0F8(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x820bcf50
	ctx.lr = 0x820A7D28;
	sub_820BCF50(ctx, base);
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r10,3
	ctx.r10.s64 = 3;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,1164(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 1164);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// rlwimi r3,r29,24,7,8
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 24) & 0x1800000) | (ctx.r3.u64 & 0xFFFFFFFFFE7FFFFF);
	// stw r3,1164(r4)
	REX_STORE_U32(ctx.r4.u32 + 1164, ctx.r3.u32);
	// ld r11,24(r4)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r4.u32 + 24);
	// oris r3,r11,32768
	ctx.r3.u64 = ctx.r11.u64 | 2147483648;
	// std r3,24(r4)
	REX_STORE_U64(ctx.r4.u32 + 24, ctx.r3.u64);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r4,1152(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 1152);
	// rlwimi r4,r29,11,19,21
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 11) & 0x1C00) | (ctx.r4.u64 & 0xFFFFFFFFFFFFE3FF);
	// stw r4,1152(r11)
	REX_STORE_U32(ctx.r11.u32 + 1152, ctx.r4.u32);
	// ld r3,24(r11)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r11.u32 + 24);
	// oris r4,r3,32768
	ctx.r4.u64 = ctx.r3.u64 | 2147483648;
	// std r4,24(r11)
	REX_STORE_U64(ctx.r11.u32 + 24, ctx.r4.u64);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,1152(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1152);
	// rlwimi r11,r29,14,16,18
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 14) & 0xE000) | (ctx.r11.u64 & 0xFFFFFFFFFFFF1FFF);
	// stw r11,1152(r3)
	REX_STORE_U32(ctx.r3.u32 + 1152, ctx.r11.u32);
	// ld r4,24(r3)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r3.u32 + 24);
	// oris r11,r4,32768
	ctx.r11.u64 = ctx.r4.u64 | 2147483648;
	// std r11,24(r3)
	REX_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r3,1152(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 1152);
	// rlwimi r3,r29,17,13,15
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 17) & 0x70000) | (ctx.r3.u64 & 0xFFFFFFFFFFF8FFFF);
	// stw r3,1152(r4)
	REX_STORE_U32(ctx.r4.u32 + 1152, ctx.r3.u32);
	// ld r11,24(r4)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r4.u32 + 24);
	// oris r3,r11,32768
	ctx.r3.u64 = ctx.r11.u64 | 2147483648;
	// std r3,24(r4)
	REX_STORE_U64(ctx.r4.u32 + 24, ctx.r3.u64);
	// lwz r4,28724(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 28724);
	// lwz r3,28720(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28720);
	// bl 0x820c44a0
	ctx.lr = 0x820A7DBC;
	sub_820C44A0(ctx, base);
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// stw r28,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r28.u32);
loc_820A7DC4:
	// stw r28,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r28.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
