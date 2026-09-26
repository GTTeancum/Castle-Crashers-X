DEFINE_REX_FUNC(sub_8208CFA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f8
	ctx.lr = 0x8208CFA8;
	__savegprlr_20(ctx, base);
	// stfd f30,-120(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.f30.u64);
	// stfd f31,-112(r1)
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r22,-32215
	ctx.r22.s64 = -2111242240;
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r9,r11,-4384
	ctx.r9.s64 = ctx.r11.s64 + -4384;
	// lbz r8,-22601(r22)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r22.u32 + -22601);
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// stw r31,24(r23)
	REX_STORE_U32(ctx.r23.u32 + 24, ctx.r31.u32);
	// stw r9,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r9.u32);
	// addi r20,r10,-1768
	ctx.r20.s64 = ctx.r10.s64 + -1768;
	// sth r31,4(r23)
	REX_STORE_U16(ctx.r23.u32 + 4, ctx.r31.u16);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8208cffc
	if (!ctx.cr6.eq) goto loc_8208CFFC;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8208CFFC;
	sub_820A71E8(ctx, base);
loc_8208CFFC:
	// bl 0x820b5eb8
	ctx.lr = 0x8208D000;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r21,r11,29632
	ctx.r21.s64 = ctx.r11.s64 + 29632;
	// lis r4,39
	ctx.r4.s64 = 2555904;
	// ori r4,r4,48100
	ctx.r4.u64 = ctx.r4.u64 | 48100;
	// lwzx r3,r10,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8208D01C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8208d054
	if (ctx.cr6.eq) goto loc_8208D054;
	// li r11,10500
	ctx.r11.s64 = 10500;
	// addi r28,r3,4
	ctx.r28.s64 = ctx.r3.s64 + 4;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r30,10499
	ctx.r30.s64 = 10499;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
loc_8208D038:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820869b0
	ctx.lr = 0x8208D040;
	sub_820869B0(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r29,r29,248
	ctx.r29.s64 = ctx.r29.s64 + 248;
	// bge 0x8208d038
	if (!ctx.cr0.lt) goto loc_8208D038;
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// b 0x8208d058
	goto loc_8208D058;
loc_8208D054:
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
loc_8208D058:
	// addis r9,r23,2
	ctx.r9.s64 = ctx.r23.s64 + 131072;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r9,r9,-18580
	ctx.r9.s64 = ctx.r9.s64 + -18580;
	// addi r10,r23,28
	ctx.r10.s64 = ctx.r23.s64 + 28;
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// lis r8,39
	ctx.r8.s64 = 2555904;
	// ori r7,r8,48096
	ctx.r7.u64 = ctx.r8.u64 | 48096;
loc_8208D074:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// addi r11,r11,248
	ctx.r11.s64 = ctx.r11.s64 + 248;
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x8208d074
	if (ctx.cr6.lt) goto loc_8208D074;
	// lbz r11,-22601(r22)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r22.u32 + -22601);
	// sth r31,6(r23)
	REX_STORE_U16(ctx.r23.u32 + 6, ctx.r31.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208d0b4
	if (!ctx.cr6.eq) goto loc_8208D0B4;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8208D0B4;
	sub_820A71E8(ctx, base);
loc_8208D0B4:
	// bl 0x820b5eb8
	ctx.lr = 0x8208D0B8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r4,23
	ctx.r4.s64 = 1507328;
	// ori r4,r4,676
	ctx.r4.u64 = ctx.r4.u64 | 676;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8208D0CC;
	sub_8209BDD8(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r30,1
	ctx.r30.s64 = 1;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lfs f30,18236(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 18236);
	ctx.f30.f64 = double(temp.f32);
	// lfs f31,9536(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// beq cr6,0x8208d5d0
	if (ctx.cr6.eq) goto loc_8208D5D0;
	// li r11,13000
	ctx.r11.s64 = 13000;
	// addi r7,r3,4
	ctx.r7.s64 = ctx.r3.s64 + 4;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// addi r11,r7,12
	ctx.r11.s64 = ctx.r7.s64 + 12;
	// li r9,1300
	ctx.r9.s64 = 1300;
	// addi r10,r10,-4960
	ctx.r10.s64 = ctx.r10.s64 + -4960;
loc_8208D108:
	// stw r31,-8(r11)
	REX_STORE_U32(ctx.r11.u32 + -8, ctx.r31.u32);
	// stw r31,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r31.u32);
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// stb r31,8(r11)
	REX_STORE_U8(ctx.r11.u32 + 8, ctx.r31.u8);
	// sth r31,12(r11)
	REX_STORE_U16(ctx.r11.u32 + 12, ctx.r31.u16);
	// stw r31,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r31.u32);
	// stw r31,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r31.u32);
	// stfs f30,24(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// stfs f30,28(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 28, temp.u32);
	// stb r31,36(r11)
	REX_STORE_U8(ctx.r11.u32 + 36, ctx.r31.u8);
	// stfs f31,32(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 32, temp.u32);
	// stb r31,37(r11)
	REX_STORE_U8(ctx.r11.u32 + 37, ctx.r31.u8);
	// stfs f30,40(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 40, temp.u32);
	// stb r31,38(r11)
	REX_STORE_U8(ctx.r11.u32 + 38, ctx.r31.u8);
	// stfs f30,44(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 44, temp.u32);
	// stfs f31,48(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 48, temp.u32);
	// stfs f31,52(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 52, temp.u32);
	// stfs f31,56(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 56, temp.u32);
	// stfs f31,60(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 60, temp.u32);
	// stw r31,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r31.u32);
	// sth r31,70(r11)
	REX_STORE_U16(ctx.r11.u32 + 70, ctx.r31.u16);
	// sth r31,72(r11)
	REX_STORE_U16(ctx.r11.u32 + 72, ctx.r31.u16);
	// stw r31,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r31.u32);
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// stw r31,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r31.u32);
	// stw r31,100(r11)
	REX_STORE_U32(ctx.r11.u32 + 100, ctx.r31.u32);
	// lbz r6,74(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 74);
	// clrlwi r5,r6,28
	ctx.r5.u64 = ctx.r6.u32 & 0xF;
	// stb r5,74(r11)
	REX_STORE_U8(ctx.r11.u32 + 74, ctx.r5.u8);
	// stw r31,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r31.u32);
	// stw r31,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r31.u32);
	// stw r31,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r31.u32);
	// stw r30,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r30.u32);
	// stb r31,124(r11)
	REX_STORE_U8(ctx.r11.u32 + 124, ctx.r31.u8);
	// sth r31,128(r11)
	REX_STORE_U16(ctx.r11.u32 + 128, ctx.r31.u16);
	// stw r31,132(r11)
	REX_STORE_U32(ctx.r11.u32 + 132, ctx.r31.u32);
	// stw r31,136(r11)
	REX_STORE_U32(ctx.r11.u32 + 136, ctx.r31.u32);
	// stfs f30,140(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 140, temp.u32);
	// stfs f30,144(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 144, temp.u32);
	// stfs f31,148(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 148, temp.u32);
	// stfs f30,156(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 156, temp.u32);
	// stfs f30,160(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 160, temp.u32);
	// stfs f31,164(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 164, temp.u32);
	// stfs f31,168(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 168, temp.u32);
	// stfs f31,172(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 172, temp.u32);
	// stfs f31,176(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 176, temp.u32);
	// stb r31,152(r11)
	REX_STORE_U8(ctx.r11.u32 + 152, ctx.r31.u8);
	// stb r31,153(r11)
	REX_STORE_U8(ctx.r11.u32 + 153, ctx.r31.u8);
	// stb r31,154(r11)
	REX_STORE_U8(ctx.r11.u32 + 154, ctx.r31.u8);
	// stw r31,180(r11)
	REX_STORE_U32(ctx.r11.u32 + 180, ctx.r31.u32);
	// sth r31,186(r11)
	REX_STORE_U16(ctx.r11.u32 + 186, ctx.r31.u16);
	// sth r31,188(r11)
	REX_STORE_U16(ctx.r11.u32 + 188, ctx.r31.u16);
	// stw r31,192(r11)
	REX_STORE_U32(ctx.r11.u32 + 192, ctx.r31.u32);
	// stw r10,104(r11)
	REX_STORE_U32(ctx.r11.u32 + 104, ctx.r10.u32);
	// stw r31,196(r11)
	REX_STORE_U32(ctx.r11.u32 + 196, ctx.r31.u32);
	// lbz r4,190(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 190);
	// clrlwi r3,r4,28
	ctx.r3.u64 = ctx.r4.u32 & 0xF;
	// stb r3,190(r11)
	REX_STORE_U8(ctx.r11.u32 + 190, ctx.r3.u8);
	// stw r31,216(r11)
	REX_STORE_U32(ctx.r11.u32 + 216, ctx.r31.u32);
	// stw r31,224(r11)
	REX_STORE_U32(ctx.r11.u32 + 224, ctx.r31.u32);
	// stw r31,228(r11)
	REX_STORE_U32(ctx.r11.u32 + 228, ctx.r31.u32);
	// stw r31,232(r11)
	REX_STORE_U32(ctx.r11.u32 + 232, ctx.r31.u32);
	// stw r30,236(r11)
	REX_STORE_U32(ctx.r11.u32 + 236, ctx.r30.u32);
	// stb r31,240(r11)
	REX_STORE_U8(ctx.r11.u32 + 240, ctx.r31.u8);
	// sth r31,244(r11)
	REX_STORE_U16(ctx.r11.u32 + 244, ctx.r31.u16);
	// stw r31,248(r11)
	REX_STORE_U32(ctx.r11.u32 + 248, ctx.r31.u32);
	// stw r31,252(r11)
	REX_STORE_U32(ctx.r11.u32 + 252, ctx.r31.u32);
	// stfs f30,256(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 256, temp.u32);
	// stfs f30,260(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 260, temp.u32);
	// stfs f31,264(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 264, temp.u32);
	// stfs f30,272(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 272, temp.u32);
	// stfs f30,276(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 276, temp.u32);
	// stfs f31,280(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 280, temp.u32);
	// stfs f31,284(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 284, temp.u32);
	// stfs f31,288(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 288, temp.u32);
	// stfs f31,292(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 292, temp.u32);
	// stb r31,268(r11)
	REX_STORE_U8(ctx.r11.u32 + 268, ctx.r31.u8);
	// stb r31,269(r11)
	REX_STORE_U8(ctx.r11.u32 + 269, ctx.r31.u8);
	// stb r31,270(r11)
	REX_STORE_U8(ctx.r11.u32 + 270, ctx.r31.u8);
	// stw r31,296(r11)
	REX_STORE_U32(ctx.r11.u32 + 296, ctx.r31.u32);
	// lbz r6,306(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 306);
	// sth r31,302(r11)
	REX_STORE_U16(ctx.r11.u32 + 302, ctx.r31.u16);
	// clrlwi r5,r6,28
	ctx.r5.u64 = ctx.r6.u32 & 0xF;
	// sth r31,304(r11)
	REX_STORE_U16(ctx.r11.u32 + 304, ctx.r31.u16);
	// stw r31,308(r11)
	REX_STORE_U32(ctx.r11.u32 + 308, ctx.r31.u32);
	// stb r5,306(r11)
	REX_STORE_U8(ctx.r11.u32 + 306, ctx.r5.u8);
	// stw r10,220(r11)
	REX_STORE_U32(ctx.r11.u32 + 220, ctx.r10.u32);
	// stw r31,312(r11)
	REX_STORE_U32(ctx.r11.u32 + 312, ctx.r31.u32);
	// stw r31,332(r11)
	REX_STORE_U32(ctx.r11.u32 + 332, ctx.r31.u32);
	// stw r31,340(r11)
	REX_STORE_U32(ctx.r11.u32 + 340, ctx.r31.u32);
	// stw r31,344(r11)
	REX_STORE_U32(ctx.r11.u32 + 344, ctx.r31.u32);
	// stw r31,348(r11)
	REX_STORE_U32(ctx.r11.u32 + 348, ctx.r31.u32);
	// stw r30,352(r11)
	REX_STORE_U32(ctx.r11.u32 + 352, ctx.r30.u32);
	// stb r31,356(r11)
	REX_STORE_U8(ctx.r11.u32 + 356, ctx.r31.u8);
	// sth r31,360(r11)
	REX_STORE_U16(ctx.r11.u32 + 360, ctx.r31.u16);
	// stw r31,364(r11)
	REX_STORE_U32(ctx.r11.u32 + 364, ctx.r31.u32);
	// stw r31,368(r11)
	REX_STORE_U32(ctx.r11.u32 + 368, ctx.r31.u32);
	// stfs f30,372(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 372, temp.u32);
	// stfs f30,376(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 376, temp.u32);
	// stfs f31,380(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 380, temp.u32);
	// stfs f30,388(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 388, temp.u32);
	// stfs f30,392(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 392, temp.u32);
	// stfs f31,396(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 396, temp.u32);
	// stfs f31,400(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 400, temp.u32);
	// stfs f31,404(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 404, temp.u32);
	// stfs f31,408(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 408, temp.u32);
	// stb r31,384(r11)
	REX_STORE_U8(ctx.r11.u32 + 384, ctx.r31.u8);
	// stb r31,385(r11)
	REX_STORE_U8(ctx.r11.u32 + 385, ctx.r31.u8);
	// stb r31,386(r11)
	REX_STORE_U8(ctx.r11.u32 + 386, ctx.r31.u8);
	// stw r31,412(r11)
	REX_STORE_U32(ctx.r11.u32 + 412, ctx.r31.u32);
	// sth r31,418(r11)
	REX_STORE_U16(ctx.r11.u32 + 418, ctx.r31.u16);
	// sth r31,420(r11)
	REX_STORE_U16(ctx.r11.u32 + 420, ctx.r31.u16);
	// stw r31,424(r11)
	REX_STORE_U32(ctx.r11.u32 + 424, ctx.r31.u32);
	// stw r10,336(r11)
	REX_STORE_U32(ctx.r11.u32 + 336, ctx.r10.u32);
	// stw r31,428(r11)
	REX_STORE_U32(ctx.r11.u32 + 428, ctx.r31.u32);
	// lbz r4,422(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 422);
	// clrlwi r3,r4,28
	ctx.r3.u64 = ctx.r4.u32 & 0xF;
	// stw r31,448(r11)
	REX_STORE_U32(ctx.r11.u32 + 448, ctx.r31.u32);
	// stb r3,422(r11)
	REX_STORE_U8(ctx.r11.u32 + 422, ctx.r3.u8);
	// stw r31,456(r11)
	REX_STORE_U32(ctx.r11.u32 + 456, ctx.r31.u32);
	// stw r31,460(r11)
	REX_STORE_U32(ctx.r11.u32 + 460, ctx.r31.u32);
	// stw r31,464(r11)
	REX_STORE_U32(ctx.r11.u32 + 464, ctx.r31.u32);
	// stw r30,468(r11)
	REX_STORE_U32(ctx.r11.u32 + 468, ctx.r30.u32);
	// stb r31,472(r11)
	REX_STORE_U8(ctx.r11.u32 + 472, ctx.r31.u8);
	// sth r31,476(r11)
	REX_STORE_U16(ctx.r11.u32 + 476, ctx.r31.u16);
	// stw r31,480(r11)
	REX_STORE_U32(ctx.r11.u32 + 480, ctx.r31.u32);
	// stw r31,484(r11)
	REX_STORE_U32(ctx.r11.u32 + 484, ctx.r31.u32);
	// stfs f30,488(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 488, temp.u32);
	// stfs f30,492(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 492, temp.u32);
	// stfs f31,496(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 496, temp.u32);
	// stfs f30,504(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 504, temp.u32);
	// stfs f30,508(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 508, temp.u32);
	// stfs f31,512(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 512, temp.u32);
	// stfs f31,516(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 516, temp.u32);
	// stfs f31,520(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 520, temp.u32);
	// stfs f31,524(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 524, temp.u32);
	// stb r31,500(r11)
	REX_STORE_U8(ctx.r11.u32 + 500, ctx.r31.u8);
	// stb r31,501(r11)
	REX_STORE_U8(ctx.r11.u32 + 501, ctx.r31.u8);
	// stb r31,502(r11)
	REX_STORE_U8(ctx.r11.u32 + 502, ctx.r31.u8);
	// stw r31,528(r11)
	REX_STORE_U32(ctx.r11.u32 + 528, ctx.r31.u32);
	// sth r31,534(r11)
	REX_STORE_U16(ctx.r11.u32 + 534, ctx.r31.u16);
	// sth r31,536(r11)
	REX_STORE_U16(ctx.r11.u32 + 536, ctx.r31.u16);
	// stw r31,540(r11)
	REX_STORE_U32(ctx.r11.u32 + 540, ctx.r31.u32);
	// stw r31,544(r11)
	REX_STORE_U32(ctx.r11.u32 + 544, ctx.r31.u32);
	// stw r10,452(r11)
	REX_STORE_U32(ctx.r11.u32 + 452, ctx.r10.u32);
	// lbz r6,538(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 538);
	// clrlwi r5,r6,28
	ctx.r5.u64 = ctx.r6.u32 & 0xF;
	// stb r5,538(r11)
	REX_STORE_U8(ctx.r11.u32 + 538, ctx.r5.u8);
	// stw r31,564(r11)
	REX_STORE_U32(ctx.r11.u32 + 564, ctx.r31.u32);
	// stw r31,572(r11)
	REX_STORE_U32(ctx.r11.u32 + 572, ctx.r31.u32);
	// stw r31,576(r11)
	REX_STORE_U32(ctx.r11.u32 + 576, ctx.r31.u32);
	// stw r31,580(r11)
	REX_STORE_U32(ctx.r11.u32 + 580, ctx.r31.u32);
	// stw r30,584(r11)
	REX_STORE_U32(ctx.r11.u32 + 584, ctx.r30.u32);
	// stb r31,588(r11)
	REX_STORE_U8(ctx.r11.u32 + 588, ctx.r31.u8);
	// sth r31,592(r11)
	REX_STORE_U16(ctx.r11.u32 + 592, ctx.r31.u16);
	// stw r31,596(r11)
	REX_STORE_U32(ctx.r11.u32 + 596, ctx.r31.u32);
	// stw r31,600(r11)
	REX_STORE_U32(ctx.r11.u32 + 600, ctx.r31.u32);
	// stfs f30,604(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 604, temp.u32);
	// stfs f30,608(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 608, temp.u32);
	// stfs f31,612(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 612, temp.u32);
	// stfs f30,620(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 620, temp.u32);
	// stfs f30,624(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 624, temp.u32);
	// stfs f31,628(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 628, temp.u32);
	// stfs f31,632(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 632, temp.u32);
	// stfs f31,636(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 636, temp.u32);
	// stfs f31,640(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 640, temp.u32);
	// stb r31,616(r11)
	REX_STORE_U8(ctx.r11.u32 + 616, ctx.r31.u8);
	// stb r31,617(r11)
	REX_STORE_U8(ctx.r11.u32 + 617, ctx.r31.u8);
	// stb r31,618(r11)
	REX_STORE_U8(ctx.r11.u32 + 618, ctx.r31.u8);
	// lbz r4,654(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 654);
	// clrlwi r3,r4,28
	ctx.r3.u64 = ctx.r4.u32 & 0xF;
	// stb r3,654(r11)
	REX_STORE_U8(ctx.r11.u32 + 654, ctx.r3.u8);
	// stw r31,644(r11)
	REX_STORE_U32(ctx.r11.u32 + 644, ctx.r31.u32);
	// sth r31,650(r11)
	REX_STORE_U16(ctx.r11.u32 + 650, ctx.r31.u16);
	// sth r31,652(r11)
	REX_STORE_U16(ctx.r11.u32 + 652, ctx.r31.u16);
	// stw r31,656(r11)
	REX_STORE_U32(ctx.r11.u32 + 656, ctx.r31.u32);
	// stw r10,568(r11)
	REX_STORE_U32(ctx.r11.u32 + 568, ctx.r10.u32);
	// stw r31,660(r11)
	REX_STORE_U32(ctx.r11.u32 + 660, ctx.r31.u32);
	// stw r31,680(r11)
	REX_STORE_U32(ctx.r11.u32 + 680, ctx.r31.u32);
	// stw r31,688(r11)
	REX_STORE_U32(ctx.r11.u32 + 688, ctx.r31.u32);
	// stw r31,692(r11)
	REX_STORE_U32(ctx.r11.u32 + 692, ctx.r31.u32);
	// stw r31,696(r11)
	REX_STORE_U32(ctx.r11.u32 + 696, ctx.r31.u32);
	// stw r30,700(r11)
	REX_STORE_U32(ctx.r11.u32 + 700, ctx.r30.u32);
	// stb r31,704(r11)
	REX_STORE_U8(ctx.r11.u32 + 704, ctx.r31.u8);
	// sth r31,708(r11)
	REX_STORE_U16(ctx.r11.u32 + 708, ctx.r31.u16);
	// stw r31,712(r11)
	REX_STORE_U32(ctx.r11.u32 + 712, ctx.r31.u32);
	// stw r31,716(r11)
	REX_STORE_U32(ctx.r11.u32 + 716, ctx.r31.u32);
	// stfs f30,720(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 720, temp.u32);
	// stfs f30,724(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 724, temp.u32);
	// stfs f31,728(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 728, temp.u32);
	// stfs f30,736(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 736, temp.u32);
	// stfs f30,740(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 740, temp.u32);
	// stfs f31,744(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 744, temp.u32);
	// stfs f31,748(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 748, temp.u32);
	// stfs f31,752(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 752, temp.u32);
	// stfs f31,756(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 756, temp.u32);
	// stb r31,732(r11)
	REX_STORE_U8(ctx.r11.u32 + 732, ctx.r31.u8);
	// stb r31,733(r11)
	REX_STORE_U8(ctx.r11.u32 + 733, ctx.r31.u8);
	// stb r31,734(r11)
	REX_STORE_U8(ctx.r11.u32 + 734, ctx.r31.u8);
	// stw r31,760(r11)
	REX_STORE_U32(ctx.r11.u32 + 760, ctx.r31.u32);
	// sth r31,766(r11)
	REX_STORE_U16(ctx.r11.u32 + 766, ctx.r31.u16);
	// sth r31,768(r11)
	REX_STORE_U16(ctx.r11.u32 + 768, ctx.r31.u16);
	// stw r31,772(r11)
	REX_STORE_U32(ctx.r11.u32 + 772, ctx.r31.u32);
	// stw r10,684(r11)
	REX_STORE_U32(ctx.r11.u32 + 684, ctx.r10.u32);
	// stw r31,776(r11)
	REX_STORE_U32(ctx.r11.u32 + 776, ctx.r31.u32);
	// lbz r6,770(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 770);
	// clrlwi r5,r6,28
	ctx.r5.u64 = ctx.r6.u32 & 0xF;
	// stw r31,796(r11)
	REX_STORE_U32(ctx.r11.u32 + 796, ctx.r31.u32);
	// stb r5,770(r11)
	REX_STORE_U8(ctx.r11.u32 + 770, ctx.r5.u8);
	// stw r31,804(r11)
	REX_STORE_U32(ctx.r11.u32 + 804, ctx.r31.u32);
	// stw r31,808(r11)
	REX_STORE_U32(ctx.r11.u32 + 808, ctx.r31.u32);
	// stw r31,812(r11)
	REX_STORE_U32(ctx.r11.u32 + 812, ctx.r31.u32);
	// stw r30,816(r11)
	REX_STORE_U32(ctx.r11.u32 + 816, ctx.r30.u32);
	// stb r31,820(r11)
	REX_STORE_U8(ctx.r11.u32 + 820, ctx.r31.u8);
	// sth r31,824(r11)
	REX_STORE_U16(ctx.r11.u32 + 824, ctx.r31.u16);
	// stw r31,828(r11)
	REX_STORE_U32(ctx.r11.u32 + 828, ctx.r31.u32);
	// stw r31,832(r11)
	REX_STORE_U32(ctx.r11.u32 + 832, ctx.r31.u32);
	// stfs f30,836(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 836, temp.u32);
	// stfs f30,840(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 840, temp.u32);
	// stfs f31,844(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 844, temp.u32);
	// stfs f30,852(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 852, temp.u32);
	// stfs f30,856(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 856, temp.u32);
	// stfs f31,860(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 860, temp.u32);
	// stfs f31,864(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 864, temp.u32);
	// stfs f31,868(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 868, temp.u32);
	// stfs f31,872(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 872, temp.u32);
	// stb r31,848(r11)
	REX_STORE_U8(ctx.r11.u32 + 848, ctx.r31.u8);
	// stb r31,849(r11)
	REX_STORE_U8(ctx.r11.u32 + 849, ctx.r31.u8);
	// stb r31,850(r11)
	REX_STORE_U8(ctx.r11.u32 + 850, ctx.r31.u8);
	// stw r31,876(r11)
	REX_STORE_U32(ctx.r11.u32 + 876, ctx.r31.u32);
	// sth r31,882(r11)
	REX_STORE_U16(ctx.r11.u32 + 882, ctx.r31.u16);
	// sth r31,884(r11)
	REX_STORE_U16(ctx.r11.u32 + 884, ctx.r31.u16);
	// stw r31,888(r11)
	REX_STORE_U32(ctx.r11.u32 + 888, ctx.r31.u32);
	// stw r10,800(r11)
	REX_STORE_U32(ctx.r11.u32 + 800, ctx.r10.u32);
	// stw r31,892(r11)
	REX_STORE_U32(ctx.r11.u32 + 892, ctx.r31.u32);
	// lbz r4,886(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 886);
	// clrlwi r3,r4,28
	ctx.r3.u64 = ctx.r4.u32 & 0xF;
	// stw r31,912(r11)
	REX_STORE_U32(ctx.r11.u32 + 912, ctx.r31.u32);
	// stb r3,886(r11)
	REX_STORE_U8(ctx.r11.u32 + 886, ctx.r3.u8);
	// stw r31,920(r11)
	REX_STORE_U32(ctx.r11.u32 + 920, ctx.r31.u32);
	// stw r31,924(r11)
	REX_STORE_U32(ctx.r11.u32 + 924, ctx.r31.u32);
	// stw r31,928(r11)
	REX_STORE_U32(ctx.r11.u32 + 928, ctx.r31.u32);
	// stw r30,932(r11)
	REX_STORE_U32(ctx.r11.u32 + 932, ctx.r30.u32);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stb r31,936(r11)
	REX_STORE_U8(ctx.r11.u32 + 936, ctx.r31.u8);
	// addi r8,r8,1160
	ctx.r8.s64 = ctx.r8.s64 + 1160;
	// sth r31,940(r11)
	REX_STORE_U16(ctx.r11.u32 + 940, ctx.r31.u16);
	// stw r31,944(r11)
	REX_STORE_U32(ctx.r11.u32 + 944, ctx.r31.u32);
	// stw r31,948(r11)
	REX_STORE_U32(ctx.r11.u32 + 948, ctx.r31.u32);
	// stfs f30,952(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 952, temp.u32);
	// stfs f30,956(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 956, temp.u32);
	// stfs f31,960(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 960, temp.u32);
	// stfs f30,968(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 968, temp.u32);
	// stfs f30,972(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 972, temp.u32);
	// stfs f31,976(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 976, temp.u32);
	// stfs f31,980(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 980, temp.u32);
	// stfs f31,984(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 984, temp.u32);
	// stfs f31,988(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 988, temp.u32);
	// stb r31,964(r11)
	REX_STORE_U8(ctx.r11.u32 + 964, ctx.r31.u8);
	// stb r31,965(r11)
	REX_STORE_U8(ctx.r11.u32 + 965, ctx.r31.u8);
	// stb r31,966(r11)
	REX_STORE_U8(ctx.r11.u32 + 966, ctx.r31.u8);
	// stw r31,992(r11)
	REX_STORE_U32(ctx.r11.u32 + 992, ctx.r31.u32);
	// sth r31,998(r11)
	REX_STORE_U16(ctx.r11.u32 + 998, ctx.r31.u16);
	// sth r31,1000(r11)
	REX_STORE_U16(ctx.r11.u32 + 1000, ctx.r31.u16);
	// stw r31,1004(r11)
	REX_STORE_U32(ctx.r11.u32 + 1004, ctx.r31.u32);
	// stw r10,916(r11)
	REX_STORE_U32(ctx.r11.u32 + 916, ctx.r10.u32);
	// stw r31,1008(r11)
	REX_STORE_U32(ctx.r11.u32 + 1008, ctx.r31.u32);
	// stw r31,1028(r11)
	REX_STORE_U32(ctx.r11.u32 + 1028, ctx.r31.u32);
	// lbz r6,1002(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 1002);
	// clrlwi r5,r6,28
	ctx.r5.u64 = ctx.r6.u32 & 0xF;
	// stb r5,1002(r11)
	REX_STORE_U8(ctx.r11.u32 + 1002, ctx.r5.u8);
	// stw r31,1036(r11)
	REX_STORE_U32(ctx.r11.u32 + 1036, ctx.r31.u32);
	// stw r31,1040(r11)
	REX_STORE_U32(ctx.r11.u32 + 1040, ctx.r31.u32);
	// stw r31,1044(r11)
	REX_STORE_U32(ctx.r11.u32 + 1044, ctx.r31.u32);
	// stw r30,1048(r11)
	REX_STORE_U32(ctx.r11.u32 + 1048, ctx.r30.u32);
	// stb r31,1052(r11)
	REX_STORE_U8(ctx.r11.u32 + 1052, ctx.r31.u8);
	// sth r31,1056(r11)
	REX_STORE_U16(ctx.r11.u32 + 1056, ctx.r31.u16);
	// stw r31,1060(r11)
	REX_STORE_U32(ctx.r11.u32 + 1060, ctx.r31.u32);
	// stw r31,1064(r11)
	REX_STORE_U32(ctx.r11.u32 + 1064, ctx.r31.u32);
	// stfs f30,1068(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1068, temp.u32);
	// stfs f30,1072(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1072, temp.u32);
	// stfs f31,1076(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1076, temp.u32);
	// stfs f30,1084(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1084, temp.u32);
	// stfs f30,1088(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1088, temp.u32);
	// stfs f31,1092(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1092, temp.u32);
	// stfs f31,1096(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1096, temp.u32);
	// stfs f31,1100(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1100, temp.u32);
	// stfs f31,1104(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1104, temp.u32);
	// stb r31,1080(r11)
	REX_STORE_U8(ctx.r11.u32 + 1080, ctx.r31.u8);
	// stb r31,1081(r11)
	REX_STORE_U8(ctx.r11.u32 + 1081, ctx.r31.u8);
	// stb r31,1082(r11)
	REX_STORE_U8(ctx.r11.u32 + 1082, ctx.r31.u8);
	// stw r31,1108(r11)
	REX_STORE_U32(ctx.r11.u32 + 1108, ctx.r31.u32);
	// sth r31,1114(r11)
	REX_STORE_U16(ctx.r11.u32 + 1114, ctx.r31.u16);
	// sth r31,1116(r11)
	REX_STORE_U16(ctx.r11.u32 + 1116, ctx.r31.u16);
	// stw r31,1120(r11)
	REX_STORE_U32(ctx.r11.u32 + 1120, ctx.r31.u32);
	// stw r10,1032(r11)
	REX_STORE_U32(ctx.r11.u32 + 1032, ctx.r10.u32);
	// stw r31,1124(r11)
	REX_STORE_U32(ctx.r11.u32 + 1124, ctx.r31.u32);
	// lbz r4,1118(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 1118);
	// clrlwi r3,r4,28
	ctx.r3.u64 = ctx.r4.u32 & 0xF;
	// stb r3,1118(r11)
	REX_STORE_U8(ctx.r11.u32 + 1118, ctx.r3.u8);
	// stw r31,1144(r11)
	REX_STORE_U32(ctx.r11.u32 + 1144, ctx.r31.u32);
	// addi r11,r11,1160
	ctx.r11.s64 = ctx.r11.s64 + 1160;
	// bne 0x8208d108
	if (!ctx.cr0.eq) goto loc_8208D108;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// b 0x8208d5d4
	goto loc_8208D5D4;
loc_8208D5D0:
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
loc_8208D5D4:
	// addis r9,r23,2
	ctx.r9.s64 = ctx.r23.s64 + 131072;
	// addis r10,r23,1
	ctx.r10.s64 = ctx.r23.s64 + 65536;
	// addi r9,r9,-18576
	ctx.r9.s64 = ctx.r9.s64 + -18576;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r10,r10,-23508
	ctx.r10.s64 = ctx.r10.s64 + -23508;
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// lis r8,23
	ctx.r8.s64 = 1507328;
	// ori r7,r8,672
	ctx.r7.u64 = ctx.r8.u64 | 672;
loc_8208D5F4:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r11,r11,116
	ctx.r11.s64 = ctx.r11.s64 + 116;
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x8208d5f4
	if (ctx.cr6.lt) goto loc_8208D5F4;
	// lbz r11,-22601(r22)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r22.u32 + -22601);
	// sth r31,8(r23)
	REX_STORE_U16(ctx.r23.u32 + 8, ctx.r31.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208d634
	if (!ctx.cr6.eq) goto loc_8208D634;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8208D634;
	sub_820A71E8(ctx, base);
loc_8208D634:
	// bl 0x820b5eb8
	ctx.lr = 0x8208D638;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// ori r4,r4,30468
	ctx.r4.u64 = ctx.r4.u64 | 30468;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8208D64C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8208d6d0
	if (ctx.cr6.eq) goto loc_8208D6D0;
	// li r11,2000
	ctx.r11.s64 = 2000;
	// addi r6,r3,4
	ctx.r6.s64 = ctx.r3.s64 + 4;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// li r9,1999
	ctx.r9.s64 = 1999;
	// addi r11,r6,12
	ctx.r11.s64 = ctx.r6.s64 + 12;
	// li r10,255
	ctx.r10.s64 = 255;
	// addi r7,r7,-7056
	ctx.r7.s64 = ctx.r7.s64 + -7056;
loc_8208D678:
	// stw r31,-8(r11)
	REX_STORE_U32(ctx.r11.u32 + -8, ctx.r31.u32);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r31,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r31.u32);
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// stb r31,8(r11)
	REX_STORE_U8(ctx.r11.u32 + 8, ctx.r31.u8);
	// sth r31,12(r11)
	REX_STORE_U16(ctx.r11.u32 + 12, ctx.r31.u16);
	// sth r10,28(r11)
	REX_STORE_U16(ctx.r11.u32 + 28, ctx.r10.u16);
	// sth r10,20(r11)
	REX_STORE_U16(ctx.r11.u32 + 20, ctx.r10.u16);
	// sth r10,18(r11)
	REX_STORE_U16(ctx.r11.u32 + 18, ctx.r10.u16);
	// sth r10,16(r11)
	REX_STORE_U16(ctx.r11.u32 + 16, ctx.r10.u16);
	// sth r31,30(r11)
	REX_STORE_U16(ctx.r11.u32 + 30, ctx.r31.u16);
	// sth r31,26(r11)
	REX_STORE_U16(ctx.r11.u32 + 26, ctx.r31.u16);
	// sth r31,24(r11)
	REX_STORE_U16(ctx.r11.u32 + 24, ctx.r31.u16);
	// sth r31,22(r11)
	REX_STORE_U16(ctx.r11.u32 + 22, ctx.r31.u16);
	// stw r31,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r31.u32);
	// addi r11,r11,48
	ctx.r11.s64 = ctx.r11.s64 + 48;
	// stw r7,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// addi r8,r8,48
	ctx.r8.s64 = ctx.r8.s64 + 48;
	// bge 0x8208d678
	if (!ctx.cr0.lt) goto loc_8208D678;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// b 0x8208d6d4
	goto loc_8208D6D4;
loc_8208D6D0:
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
loc_8208D6D4:
	// addis r9,r23,2
	ctx.r9.s64 = ctx.r23.s64 + 131072;
	// addis r10,r23,1
	ctx.r10.s64 = ctx.r23.s64 + 65536;
	// addi r9,r9,-18572
	ctx.r9.s64 = ctx.r9.s64 + -18572;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r10,r10,28492
	ctx.r10.s64 = ctx.r10.s64 + 28492;
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// ori r7,r8,30464
	ctx.r7.u64 = ctx.r8.u64 | 30464;
loc_8208D6F4:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// addi r11,r11,48
	ctx.r11.s64 = ctx.r11.s64 + 48;
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x8208d6f4
	if (ctx.cr6.lt) goto loc_8208D6F4;
	// lbz r11,-22601(r22)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r22.u32 + -22601);
	// sth r31,10(r23)
	REX_STORE_U16(ctx.r23.u32 + 10, ctx.r31.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208d734
	if (!ctx.cr6.eq) goto loc_8208D734;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8208D734;
	sub_820A71E8(ctx, base);
loc_8208D734:
	// bl 0x820b5eb8
	ctx.lr = 0x8208D738;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r4,0
	ctx.r4.s64 = 0;
	// ori r4,r4,56004
	ctx.r4.u64 = ctx.r4.u64 | 56004;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8208D74C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8208dce4
	if (ctx.cr6.eq) goto loc_8208DCE4;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r11,400
	ctx.r11.s64 = 400;
	// addi r7,r3,4
	ctx.r7.s64 = ctx.r3.s64 + 4;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// lfs f0,9540(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r7,12
	ctx.r11.s64 = ctx.r7.s64 + 12;
	// li r9,40
	ctx.r9.s64 = 40;
	// addi r10,r10,-5200
	ctx.r10.s64 = ctx.r10.s64 + -5200;
loc_8208D77C:
	// stw r31,-8(r11)
	REX_STORE_U32(ctx.r11.u32 + -8, ctx.r31.u32);
	// stw r31,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r31.u32);
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// stb r31,8(r11)
	REX_STORE_U8(ctx.r11.u32 + 8, ctx.r31.u8);
	// sth r31,12(r11)
	REX_STORE_U16(ctx.r11.u32 + 12, ctx.r31.u16);
	// stw r31,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r31.u32);
	// stw r31,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r31.u32);
	// stfs f30,24(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// stfs f30,28(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 28, temp.u32);
	// stb r31,36(r11)
	REX_STORE_U8(ctx.r11.u32 + 36, ctx.r31.u8);
	// stfs f31,32(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 32, temp.u32);
	// stb r31,37(r11)
	REX_STORE_U8(ctx.r11.u32 + 37, ctx.r31.u8);
	// stfs f30,40(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 40, temp.u32);
	// stb r31,38(r11)
	REX_STORE_U8(ctx.r11.u32 + 38, ctx.r31.u8);
	// stfs f30,44(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 44, temp.u32);
	// stfs f31,48(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 48, temp.u32);
	// stfs f31,52(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 52, temp.u32);
	// stfs f31,56(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 56, temp.u32);
	// stfs f31,60(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 60, temp.u32);
	// stw r31,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r31.u32);
	// stfs f0,84(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 84, temp.u32);
	// sth r31,70(r11)
	REX_STORE_U16(ctx.r11.u32 + 70, ctx.r31.u16);
	// stfs f31,88(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 88, temp.u32);
	// sth r31,72(r11)
	REX_STORE_U16(ctx.r11.u32 + 72, ctx.r31.u16);
	// stw r31,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r31.u32);
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// sth r31,68(r11)
	REX_STORE_U16(ctx.r11.u32 + 68, ctx.r31.u16);
	// stb r31,80(r11)
	REX_STORE_U8(ctx.r11.u32 + 80, ctx.r31.u8);
	// sth r31,82(r11)
	REX_STORE_U16(ctx.r11.u32 + 82, ctx.r31.u16);
	// stb r31,124(r11)
	REX_STORE_U8(ctx.r11.u32 + 124, ctx.r31.u8);
	// lbz r6,74(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 74);
	// clrlwi r5,r6,28
	ctx.r5.u64 = ctx.r6.u32 & 0xF;
	// stb r5,74(r11)
	REX_STORE_U8(ctx.r11.u32 + 74, ctx.r5.u8);
	// stw r31,132(r11)
	REX_STORE_U32(ctx.r11.u32 + 132, ctx.r31.u32);
	// stw r31,136(r11)
	REX_STORE_U32(ctx.r11.u32 + 136, ctx.r31.u32);
	// stw r31,140(r11)
	REX_STORE_U32(ctx.r11.u32 + 140, ctx.r31.u32);
	// stw r30,144(r11)
	REX_STORE_U32(ctx.r11.u32 + 144, ctx.r30.u32);
	// stb r31,148(r11)
	REX_STORE_U8(ctx.r11.u32 + 148, ctx.r31.u8);
	// sth r31,152(r11)
	REX_STORE_U16(ctx.r11.u32 + 152, ctx.r31.u16);
	// stw r31,156(r11)
	REX_STORE_U32(ctx.r11.u32 + 156, ctx.r31.u32);
	// stw r31,160(r11)
	REX_STORE_U32(ctx.r11.u32 + 160, ctx.r31.u32);
	// stfs f30,164(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 164, temp.u32);
	// stfs f30,168(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 168, temp.u32);
	// stfs f31,172(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 172, temp.u32);
	// stfs f30,180(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 180, temp.u32);
	// stfs f30,184(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 184, temp.u32);
	// stfs f31,188(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 188, temp.u32);
	// stfs f31,192(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 192, temp.u32);
	// stfs f31,196(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 196, temp.u32);
	// stfs f31,200(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 200, temp.u32);
	// stb r31,176(r11)
	REX_STORE_U8(ctx.r11.u32 + 176, ctx.r31.u8);
	// stb r31,177(r11)
	REX_STORE_U8(ctx.r11.u32 + 177, ctx.r31.u8);
	// stb r31,178(r11)
	REX_STORE_U8(ctx.r11.u32 + 178, ctx.r31.u8);
	// stfs f0,224(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 224, temp.u32);
	// stfs f31,228(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 228, temp.u32);
	// stw r31,204(r11)
	REX_STORE_U32(ctx.r11.u32 + 204, ctx.r31.u32);
	// sth r31,210(r11)
	REX_STORE_U16(ctx.r11.u32 + 210, ctx.r31.u16);
	// sth r31,212(r11)
	REX_STORE_U16(ctx.r11.u32 + 212, ctx.r31.u16);
	// stw r31,216(r11)
	REX_STORE_U32(ctx.r11.u32 + 216, ctx.r31.u32);
	// stw r10,128(r11)
	REX_STORE_U32(ctx.r11.u32 + 128, ctx.r10.u32);
	// sth r31,208(r11)
	REX_STORE_U16(ctx.r11.u32 + 208, ctx.r31.u16);
	// stb r31,220(r11)
	REX_STORE_U8(ctx.r11.u32 + 220, ctx.r31.u8);
	// sth r31,222(r11)
	REX_STORE_U16(ctx.r11.u32 + 222, ctx.r31.u16);
	// stb r31,264(r11)
	REX_STORE_U8(ctx.r11.u32 + 264, ctx.r31.u8);
	// lbz r4,214(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 214);
	// clrlwi r3,r4,28
	ctx.r3.u64 = ctx.r4.u32 & 0xF;
	// stb r3,214(r11)
	REX_STORE_U8(ctx.r11.u32 + 214, ctx.r3.u8);
	// stw r31,272(r11)
	REX_STORE_U32(ctx.r11.u32 + 272, ctx.r31.u32);
	// stw r31,276(r11)
	REX_STORE_U32(ctx.r11.u32 + 276, ctx.r31.u32);
	// stw r31,280(r11)
	REX_STORE_U32(ctx.r11.u32 + 280, ctx.r31.u32);
	// stw r30,284(r11)
	REX_STORE_U32(ctx.r11.u32 + 284, ctx.r30.u32);
	// stb r31,288(r11)
	REX_STORE_U8(ctx.r11.u32 + 288, ctx.r31.u8);
	// sth r31,292(r11)
	REX_STORE_U16(ctx.r11.u32 + 292, ctx.r31.u16);
	// stw r31,296(r11)
	REX_STORE_U32(ctx.r11.u32 + 296, ctx.r31.u32);
	// stw r31,300(r11)
	REX_STORE_U32(ctx.r11.u32 + 300, ctx.r31.u32);
	// stfs f30,304(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 304, temp.u32);
	// stfs f30,308(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 308, temp.u32);
	// stfs f31,312(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 312, temp.u32);
	// stfs f30,320(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 320, temp.u32);
	// stfs f30,324(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 324, temp.u32);
	// stfs f31,328(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 328, temp.u32);
	// stfs f31,332(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 332, temp.u32);
	// stfs f31,336(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 336, temp.u32);
	// stfs f31,340(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 340, temp.u32);
	// stb r31,316(r11)
	REX_STORE_U8(ctx.r11.u32 + 316, ctx.r31.u8);
	// stb r31,317(r11)
	REX_STORE_U8(ctx.r11.u32 + 317, ctx.r31.u8);
	// stb r31,318(r11)
	REX_STORE_U8(ctx.r11.u32 + 318, ctx.r31.u8);
	// stfs f0,364(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 364, temp.u32);
	// lbz r6,354(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 354);
	// clrlwi r5,r6,28
	ctx.r5.u64 = ctx.r6.u32 & 0xF;
	// stfs f31,368(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 368, temp.u32);
	// stw r31,344(r11)
	REX_STORE_U32(ctx.r11.u32 + 344, ctx.r31.u32);
	// sth r31,350(r11)
	REX_STORE_U16(ctx.r11.u32 + 350, ctx.r31.u16);
	// sth r31,352(r11)
	REX_STORE_U16(ctx.r11.u32 + 352, ctx.r31.u16);
	// stw r31,356(r11)
	REX_STORE_U32(ctx.r11.u32 + 356, ctx.r31.u32);
	// stw r10,268(r11)
	REX_STORE_U32(ctx.r11.u32 + 268, ctx.r10.u32);
	// sth r31,348(r11)
	REX_STORE_U16(ctx.r11.u32 + 348, ctx.r31.u16);
	// stb r31,360(r11)
	REX_STORE_U8(ctx.r11.u32 + 360, ctx.r31.u8);
	// sth r31,362(r11)
	REX_STORE_U16(ctx.r11.u32 + 362, ctx.r31.u16);
	// stb r31,404(r11)
	REX_STORE_U8(ctx.r11.u32 + 404, ctx.r31.u8);
	// stb r5,354(r11)
	REX_STORE_U8(ctx.r11.u32 + 354, ctx.r5.u8);
	// stw r31,412(r11)
	REX_STORE_U32(ctx.r11.u32 + 412, ctx.r31.u32);
	// stw r31,416(r11)
	REX_STORE_U32(ctx.r11.u32 + 416, ctx.r31.u32);
	// stw r31,420(r11)
	REX_STORE_U32(ctx.r11.u32 + 420, ctx.r31.u32);
	// stw r30,424(r11)
	REX_STORE_U32(ctx.r11.u32 + 424, ctx.r30.u32);
	// stb r31,428(r11)
	REX_STORE_U8(ctx.r11.u32 + 428, ctx.r31.u8);
	// sth r31,432(r11)
	REX_STORE_U16(ctx.r11.u32 + 432, ctx.r31.u16);
	// stw r31,436(r11)
	REX_STORE_U32(ctx.r11.u32 + 436, ctx.r31.u32);
	// stw r31,440(r11)
	REX_STORE_U32(ctx.r11.u32 + 440, ctx.r31.u32);
	// stfs f30,444(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 444, temp.u32);
	// stfs f30,448(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 448, temp.u32);
	// stfs f31,452(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 452, temp.u32);
	// stfs f30,460(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 460, temp.u32);
	// stfs f30,464(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 464, temp.u32);
	// stfs f31,468(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 468, temp.u32);
	// stfs f31,472(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 472, temp.u32);
	// stfs f31,476(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 476, temp.u32);
	// stfs f31,480(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 480, temp.u32);
	// stb r31,456(r11)
	REX_STORE_U8(ctx.r11.u32 + 456, ctx.r31.u8);
	// stb r31,457(r11)
	REX_STORE_U8(ctx.r11.u32 + 457, ctx.r31.u8);
	// stb r31,458(r11)
	REX_STORE_U8(ctx.r11.u32 + 458, ctx.r31.u8);
	// stfs f0,504(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 504, temp.u32);
	// stfs f31,508(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 508, temp.u32);
	// stw r31,484(r11)
	REX_STORE_U32(ctx.r11.u32 + 484, ctx.r31.u32);
	// sth r31,490(r11)
	REX_STORE_U16(ctx.r11.u32 + 490, ctx.r31.u16);
	// sth r31,492(r11)
	REX_STORE_U16(ctx.r11.u32 + 492, ctx.r31.u16);
	// stw r31,496(r11)
	REX_STORE_U32(ctx.r11.u32 + 496, ctx.r31.u32);
	// stw r10,408(r11)
	REX_STORE_U32(ctx.r11.u32 + 408, ctx.r10.u32);
	// sth r31,488(r11)
	REX_STORE_U16(ctx.r11.u32 + 488, ctx.r31.u16);
	// stb r31,500(r11)
	REX_STORE_U8(ctx.r11.u32 + 500, ctx.r31.u8);
	// sth r31,502(r11)
	REX_STORE_U16(ctx.r11.u32 + 502, ctx.r31.u16);
	// stb r31,544(r11)
	REX_STORE_U8(ctx.r11.u32 + 544, ctx.r31.u8);
	// lbz r4,494(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 494);
	// clrlwi r3,r4,28
	ctx.r3.u64 = ctx.r4.u32 & 0xF;
	// stb r3,494(r11)
	REX_STORE_U8(ctx.r11.u32 + 494, ctx.r3.u8);
	// stw r31,552(r11)
	REX_STORE_U32(ctx.r11.u32 + 552, ctx.r31.u32);
	// stw r31,556(r11)
	REX_STORE_U32(ctx.r11.u32 + 556, ctx.r31.u32);
	// stw r31,560(r11)
	REX_STORE_U32(ctx.r11.u32 + 560, ctx.r31.u32);
	// stw r30,564(r11)
	REX_STORE_U32(ctx.r11.u32 + 564, ctx.r30.u32);
	// stb r31,568(r11)
	REX_STORE_U8(ctx.r11.u32 + 568, ctx.r31.u8);
	// sth r31,572(r11)
	REX_STORE_U16(ctx.r11.u32 + 572, ctx.r31.u16);
	// stw r31,576(r11)
	REX_STORE_U32(ctx.r11.u32 + 576, ctx.r31.u32);
	// stw r31,580(r11)
	REX_STORE_U32(ctx.r11.u32 + 580, ctx.r31.u32);
	// stfs f30,584(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 584, temp.u32);
	// stfs f30,588(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 588, temp.u32);
	// stfs f31,592(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 592, temp.u32);
	// stfs f30,600(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 600, temp.u32);
	// stfs f30,604(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 604, temp.u32);
	// stfs f31,608(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 608, temp.u32);
	// stfs f31,612(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 612, temp.u32);
	// stfs f31,616(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 616, temp.u32);
	// stfs f31,620(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 620, temp.u32);
	// stb r31,596(r11)
	REX_STORE_U8(ctx.r11.u32 + 596, ctx.r31.u8);
	// stb r31,597(r11)
	REX_STORE_U8(ctx.r11.u32 + 597, ctx.r31.u8);
	// stb r31,598(r11)
	REX_STORE_U8(ctx.r11.u32 + 598, ctx.r31.u8);
	// stfs f0,644(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 644, temp.u32);
	// stfs f31,648(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 648, temp.u32);
	// stw r31,624(r11)
	REX_STORE_U32(ctx.r11.u32 + 624, ctx.r31.u32);
	// sth r31,630(r11)
	REX_STORE_U16(ctx.r11.u32 + 630, ctx.r31.u16);
	// sth r31,632(r11)
	REX_STORE_U16(ctx.r11.u32 + 632, ctx.r31.u16);
	// stw r31,636(r11)
	REX_STORE_U32(ctx.r11.u32 + 636, ctx.r31.u32);
	// lbz r6,634(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 634);
	// stw r10,548(r11)
	REX_STORE_U32(ctx.r11.u32 + 548, ctx.r10.u32);
	// clrlwi r5,r6,28
	ctx.r5.u64 = ctx.r6.u32 & 0xF;
	// sth r31,628(r11)
	REX_STORE_U16(ctx.r11.u32 + 628, ctx.r31.u16);
	// stb r31,640(r11)
	REX_STORE_U8(ctx.r11.u32 + 640, ctx.r31.u8);
	// stb r5,634(r11)
	REX_STORE_U8(ctx.r11.u32 + 634, ctx.r5.u8);
	// sth r31,642(r11)
	REX_STORE_U16(ctx.r11.u32 + 642, ctx.r31.u16);
	// stb r31,684(r11)
	REX_STORE_U8(ctx.r11.u32 + 684, ctx.r31.u8);
	// stw r31,692(r11)
	REX_STORE_U32(ctx.r11.u32 + 692, ctx.r31.u32);
	// stw r31,696(r11)
	REX_STORE_U32(ctx.r11.u32 + 696, ctx.r31.u32);
	// stw r31,700(r11)
	REX_STORE_U32(ctx.r11.u32 + 700, ctx.r31.u32);
	// stw r30,704(r11)
	REX_STORE_U32(ctx.r11.u32 + 704, ctx.r30.u32);
	// stb r31,708(r11)
	REX_STORE_U8(ctx.r11.u32 + 708, ctx.r31.u8);
	// sth r31,712(r11)
	REX_STORE_U16(ctx.r11.u32 + 712, ctx.r31.u16);
	// stw r31,716(r11)
	REX_STORE_U32(ctx.r11.u32 + 716, ctx.r31.u32);
	// stw r31,720(r11)
	REX_STORE_U32(ctx.r11.u32 + 720, ctx.r31.u32);
	// stfs f30,724(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 724, temp.u32);
	// stfs f30,728(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 728, temp.u32);
	// stfs f31,732(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 732, temp.u32);
	// stfs f30,740(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 740, temp.u32);
	// stfs f30,744(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 744, temp.u32);
	// stfs f31,748(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 748, temp.u32);
	// stfs f31,752(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 752, temp.u32);
	// stfs f31,756(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 756, temp.u32);
	// stfs f31,760(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 760, temp.u32);
	// stb r31,736(r11)
	REX_STORE_U8(ctx.r11.u32 + 736, ctx.r31.u8);
	// stb r31,737(r11)
	REX_STORE_U8(ctx.r11.u32 + 737, ctx.r31.u8);
	// stb r31,738(r11)
	REX_STORE_U8(ctx.r11.u32 + 738, ctx.r31.u8);
	// stfs f0,784(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 784, temp.u32);
	// stfs f31,788(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 788, temp.u32);
	// stw r31,764(r11)
	REX_STORE_U32(ctx.r11.u32 + 764, ctx.r31.u32);
	// sth r31,770(r11)
	REX_STORE_U16(ctx.r11.u32 + 770, ctx.r31.u16);
	// sth r31,772(r11)
	REX_STORE_U16(ctx.r11.u32 + 772, ctx.r31.u16);
	// stw r31,776(r11)
	REX_STORE_U32(ctx.r11.u32 + 776, ctx.r31.u32);
	// stw r10,688(r11)
	REX_STORE_U32(ctx.r11.u32 + 688, ctx.r10.u32);
	// sth r31,768(r11)
	REX_STORE_U16(ctx.r11.u32 + 768, ctx.r31.u16);
	// stb r31,780(r11)
	REX_STORE_U8(ctx.r11.u32 + 780, ctx.r31.u8);
	// sth r31,782(r11)
	REX_STORE_U16(ctx.r11.u32 + 782, ctx.r31.u16);
	// stb r31,824(r11)
	REX_STORE_U8(ctx.r11.u32 + 824, ctx.r31.u8);
	// lbz r4,774(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 774);
	// clrlwi r3,r4,28
	ctx.r3.u64 = ctx.r4.u32 & 0xF;
	// stb r3,774(r11)
	REX_STORE_U8(ctx.r11.u32 + 774, ctx.r3.u8);
	// stw r31,832(r11)
	REX_STORE_U32(ctx.r11.u32 + 832, ctx.r31.u32);
	// stw r31,836(r11)
	REX_STORE_U32(ctx.r11.u32 + 836, ctx.r31.u32);
	// stw r31,840(r11)
	REX_STORE_U32(ctx.r11.u32 + 840, ctx.r31.u32);
	// stw r30,844(r11)
	REX_STORE_U32(ctx.r11.u32 + 844, ctx.r30.u32);
	// stb r31,848(r11)
	REX_STORE_U8(ctx.r11.u32 + 848, ctx.r31.u8);
	// sth r31,852(r11)
	REX_STORE_U16(ctx.r11.u32 + 852, ctx.r31.u16);
	// stw r31,856(r11)
	REX_STORE_U32(ctx.r11.u32 + 856, ctx.r31.u32);
	// stw r31,860(r11)
	REX_STORE_U32(ctx.r11.u32 + 860, ctx.r31.u32);
	// stfs f30,864(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 864, temp.u32);
	// stfs f30,868(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 868, temp.u32);
	// stfs f31,872(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 872, temp.u32);
	// stfs f30,880(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 880, temp.u32);
	// stfs f30,884(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 884, temp.u32);
	// stfs f31,888(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 888, temp.u32);
	// stfs f31,892(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 892, temp.u32);
	// stfs f31,896(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 896, temp.u32);
	// stfs f31,900(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 900, temp.u32);
	// stb r31,876(r11)
	REX_STORE_U8(ctx.r11.u32 + 876, ctx.r31.u8);
	// stb r31,877(r11)
	REX_STORE_U8(ctx.r11.u32 + 877, ctx.r31.u8);
	// stb r31,878(r11)
	REX_STORE_U8(ctx.r11.u32 + 878, ctx.r31.u8);
	// stfs f0,924(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 924, temp.u32);
	// stfs f31,928(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 928, temp.u32);
	// stw r31,904(r11)
	REX_STORE_U32(ctx.r11.u32 + 904, ctx.r31.u32);
	// sth r31,910(r11)
	REX_STORE_U16(ctx.r11.u32 + 910, ctx.r31.u16);
	// sth r31,912(r11)
	REX_STORE_U16(ctx.r11.u32 + 912, ctx.r31.u16);
	// stw r31,916(r11)
	REX_STORE_U32(ctx.r11.u32 + 916, ctx.r31.u32);
	// stw r10,828(r11)
	REX_STORE_U32(ctx.r11.u32 + 828, ctx.r10.u32);
	// sth r31,908(r11)
	REX_STORE_U16(ctx.r11.u32 + 908, ctx.r31.u16);
	// stb r31,920(r11)
	REX_STORE_U8(ctx.r11.u32 + 920, ctx.r31.u8);
	// sth r31,922(r11)
	REX_STORE_U16(ctx.r11.u32 + 922, ctx.r31.u16);
	// stb r31,964(r11)
	REX_STORE_U8(ctx.r11.u32 + 964, ctx.r31.u8);
	// lbz r6,914(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 914);
	// clrlwi r5,r6,28
	ctx.r5.u64 = ctx.r6.u32 & 0xF;
	// stb r5,914(r11)
	REX_STORE_U8(ctx.r11.u32 + 914, ctx.r5.u8);
	// stw r31,972(r11)
	REX_STORE_U32(ctx.r11.u32 + 972, ctx.r31.u32);
	// stw r31,976(r11)
	REX_STORE_U32(ctx.r11.u32 + 976, ctx.r31.u32);
	// stw r31,980(r11)
	REX_STORE_U32(ctx.r11.u32 + 980, ctx.r31.u32);
	// stw r30,984(r11)
	REX_STORE_U32(ctx.r11.u32 + 984, ctx.r30.u32);
	// stb r31,988(r11)
	REX_STORE_U8(ctx.r11.u32 + 988, ctx.r31.u8);
	// sth r31,992(r11)
	REX_STORE_U16(ctx.r11.u32 + 992, ctx.r31.u16);
	// stw r31,996(r11)
	REX_STORE_U32(ctx.r11.u32 + 996, ctx.r31.u32);
	// stw r31,1000(r11)
	REX_STORE_U32(ctx.r11.u32 + 1000, ctx.r31.u32);
	// stfs f30,1004(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1004, temp.u32);
	// stfs f30,1008(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1008, temp.u32);
	// stfs f31,1012(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1012, temp.u32);
	// stfs f30,1020(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1020, temp.u32);
	// stfs f30,1024(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1024, temp.u32);
	// stfs f31,1028(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1028, temp.u32);
	// stfs f31,1032(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1032, temp.u32);
	// stfs f31,1036(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1036, temp.u32);
	// stfs f31,1040(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1040, temp.u32);
	// stb r31,1016(r11)
	REX_STORE_U8(ctx.r11.u32 + 1016, ctx.r31.u8);
	// stb r31,1017(r11)
	REX_STORE_U8(ctx.r11.u32 + 1017, ctx.r31.u8);
	// stb r31,1018(r11)
	REX_STORE_U8(ctx.r11.u32 + 1018, ctx.r31.u8);
	// stfs f0,1064(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 1064, temp.u32);
	// stfs f31,1068(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1068, temp.u32);
	// stw r31,1044(r11)
	REX_STORE_U32(ctx.r11.u32 + 1044, ctx.r31.u32);
	// sth r31,1050(r11)
	REX_STORE_U16(ctx.r11.u32 + 1050, ctx.r31.u16);
	// sth r31,1052(r11)
	REX_STORE_U16(ctx.r11.u32 + 1052, ctx.r31.u16);
	// stw r31,1056(r11)
	REX_STORE_U32(ctx.r11.u32 + 1056, ctx.r31.u32);
	// stw r10,968(r11)
	REX_STORE_U32(ctx.r11.u32 + 968, ctx.r10.u32);
	// sth r31,1048(r11)
	REX_STORE_U16(ctx.r11.u32 + 1048, ctx.r31.u16);
	// stb r31,1060(r11)
	REX_STORE_U8(ctx.r11.u32 + 1060, ctx.r31.u8);
	// sth r31,1062(r11)
	REX_STORE_U16(ctx.r11.u32 + 1062, ctx.r31.u16);
	// stb r31,1104(r11)
	REX_STORE_U8(ctx.r11.u32 + 1104, ctx.r31.u8);
	// lbz r4,1054(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 1054);
	// clrlwi r3,r4,28
	ctx.r3.u64 = ctx.r4.u32 & 0xF;
	// stb r3,1054(r11)
	REX_STORE_U8(ctx.r11.u32 + 1054, ctx.r3.u8);
	// stw r31,1112(r11)
	REX_STORE_U32(ctx.r11.u32 + 1112, ctx.r31.u32);
	// stw r31,1116(r11)
	REX_STORE_U32(ctx.r11.u32 + 1116, ctx.r31.u32);
	// stw r31,1120(r11)
	REX_STORE_U32(ctx.r11.u32 + 1120, ctx.r31.u32);
	// stw r30,1124(r11)
	REX_STORE_U32(ctx.r11.u32 + 1124, ctx.r30.u32);
	// stb r31,1128(r11)
	REX_STORE_U8(ctx.r11.u32 + 1128, ctx.r31.u8);
	// sth r31,1132(r11)
	REX_STORE_U16(ctx.r11.u32 + 1132, ctx.r31.u16);
	// stw r31,1136(r11)
	REX_STORE_U32(ctx.r11.u32 + 1136, ctx.r31.u32);
	// stw r31,1140(r11)
	REX_STORE_U32(ctx.r11.u32 + 1140, ctx.r31.u32);
	// stfs f30,1144(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1144, temp.u32);
	// stfs f30,1148(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1148, temp.u32);
	// stfs f31,1152(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1152, temp.u32);
	// stfs f30,1160(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1160, temp.u32);
	// stfs f30,1164(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1164, temp.u32);
	// stfs f31,1168(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1168, temp.u32);
	// stfs f31,1172(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1172, temp.u32);
	// stfs f31,1176(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1176, temp.u32);
	// stfs f31,1180(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1180, temp.u32);
	// stb r31,1156(r11)
	REX_STORE_U8(ctx.r11.u32 + 1156, ctx.r31.u8);
	// stb r31,1157(r11)
	REX_STORE_U8(ctx.r11.u32 + 1157, ctx.r31.u8);
	// stb r31,1158(r11)
	REX_STORE_U8(ctx.r11.u32 + 1158, ctx.r31.u8);
	// stfs f0,1204(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 1204, temp.u32);
	// stfs f31,1208(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1208, temp.u32);
	// stw r31,1184(r11)
	REX_STORE_U32(ctx.r11.u32 + 1184, ctx.r31.u32);
	// sth r31,1190(r11)
	REX_STORE_U16(ctx.r11.u32 + 1190, ctx.r31.u16);
	// sth r31,1192(r11)
	REX_STORE_U16(ctx.r11.u32 + 1192, ctx.r31.u16);
	// stw r31,1196(r11)
	REX_STORE_U32(ctx.r11.u32 + 1196, ctx.r31.u32);
	// stw r10,1108(r11)
	REX_STORE_U32(ctx.r11.u32 + 1108, ctx.r10.u32);
	// sth r31,1188(r11)
	REX_STORE_U16(ctx.r11.u32 + 1188, ctx.r31.u16);
	// stb r31,1200(r11)
	REX_STORE_U8(ctx.r11.u32 + 1200, ctx.r31.u8);
	// sth r31,1202(r11)
	REX_STORE_U16(ctx.r11.u32 + 1202, ctx.r31.u16);
	// stb r31,1244(r11)
	REX_STORE_U8(ctx.r11.u32 + 1244, ctx.r31.u8);
	// lbz r6,1194(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 1194);
	// clrlwi r5,r6,28
	ctx.r5.u64 = ctx.r6.u32 & 0xF;
	// stb r5,1194(r11)
	REX_STORE_U8(ctx.r11.u32 + 1194, ctx.r5.u8);
	// stw r31,1252(r11)
	REX_STORE_U32(ctx.r11.u32 + 1252, ctx.r31.u32);
	// stw r31,1256(r11)
	REX_STORE_U32(ctx.r11.u32 + 1256, ctx.r31.u32);
	// stw r31,1260(r11)
	REX_STORE_U32(ctx.r11.u32 + 1260, ctx.r31.u32);
	// stw r30,1264(r11)
	REX_STORE_U32(ctx.r11.u32 + 1264, ctx.r30.u32);
	// stb r31,1268(r11)
	REX_STORE_U8(ctx.r11.u32 + 1268, ctx.r31.u8);
	// sth r31,1272(r11)
	REX_STORE_U16(ctx.r11.u32 + 1272, ctx.r31.u16);
	// stw r31,1276(r11)
	REX_STORE_U32(ctx.r11.u32 + 1276, ctx.r31.u32);
	// stw r31,1280(r11)
	REX_STORE_U32(ctx.r11.u32 + 1280, ctx.r31.u32);
	// stfs f30,1284(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1284, temp.u32);
	// stfs f30,1288(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1288, temp.u32);
	// stfs f31,1292(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1292, temp.u32);
	// stfs f30,1300(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1300, temp.u32);
	// stfs f30,1304(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1304, temp.u32);
	// stfs f31,1308(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1308, temp.u32);
	// stfs f31,1312(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1312, temp.u32);
	// stfs f31,1316(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1316, temp.u32);
	// stfs f31,1320(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1320, temp.u32);
	// stb r31,1296(r11)
	REX_STORE_U8(ctx.r11.u32 + 1296, ctx.r31.u8);
	// stb r31,1297(r11)
	REX_STORE_U8(ctx.r11.u32 + 1297, ctx.r31.u8);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stb r31,1298(r11)
	REX_STORE_U8(ctx.r11.u32 + 1298, ctx.r31.u8);
	// stfs f0,1344(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 1344, temp.u32);
	// lbz r4,1334(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 1334);
	// clrlwi r3,r4,28
	ctx.r3.u64 = ctx.r4.u32 & 0xF;
	// stfs f31,1348(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1348, temp.u32);
	// stw r31,1324(r11)
	REX_STORE_U32(ctx.r11.u32 + 1324, ctx.r31.u32);
	// sth r31,1330(r11)
	REX_STORE_U16(ctx.r11.u32 + 1330, ctx.r31.u16);
	// addi r8,r8,1400
	ctx.r8.s64 = ctx.r8.s64 + 1400;
	// sth r31,1332(r11)
	REX_STORE_U16(ctx.r11.u32 + 1332, ctx.r31.u16);
	// stw r31,1336(r11)
	REX_STORE_U32(ctx.r11.u32 + 1336, ctx.r31.u32);
	// stw r10,1248(r11)
	REX_STORE_U32(ctx.r11.u32 + 1248, ctx.r10.u32);
	// sth r31,1328(r11)
	REX_STORE_U16(ctx.r11.u32 + 1328, ctx.r31.u16);
	// stb r31,1340(r11)
	REX_STORE_U8(ctx.r11.u32 + 1340, ctx.r31.u8);
	// sth r31,1342(r11)
	REX_STORE_U16(ctx.r11.u32 + 1342, ctx.r31.u16);
	// stb r31,1384(r11)
	REX_STORE_U8(ctx.r11.u32 + 1384, ctx.r31.u8);
	// stb r3,1334(r11)
	REX_STORE_U8(ctx.r11.u32 + 1334, ctx.r3.u8);
	// addi r11,r11,1400
	ctx.r11.s64 = ctx.r11.s64 + 1400;
	// bne 0x8208d77c
	if (!ctx.cr0.eq) goto loc_8208D77C;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// b 0x8208dce8
	goto loc_8208DCE8;
loc_8208DCE4:
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
loc_8208DCE8:
	// addis r9,r23,2
	ctx.r9.s64 = ctx.r23.s64 + 131072;
	// addis r10,r23,2
	ctx.r10.s64 = ctx.r23.s64 + 131072;
	// addi r9,r9,-18568
	ctx.r9.s64 = ctx.r9.s64 + -18568;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r10,r10,-29044
	ctx.r10.s64 = ctx.r10.s64 + -29044;
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r7,r8,56000
	ctx.r7.u64 = ctx.r8.u64 | 56000;
loc_8208DD08:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// addi r11,r11,140
	ctx.r11.s64 = ctx.r11.s64 + 140;
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x8208dd08
	if (ctx.cr6.lt) goto loc_8208DD08;
	// lbz r11,-22601(r22)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r22.u32 + -22601);
	// sth r31,12(r23)
	REX_STORE_U16(ctx.r23.u32 + 12, ctx.r31.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208dd48
	if (!ctx.cr6.eq) goto loc_8208DD48;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8208DD48;
	sub_820A71E8(ctx, base);
loc_8208DD48:
	// bl 0x820b5eb8
	ctx.lr = 0x8208DD4C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,5604
	ctx.r4.s64 = 5604;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8208DD5C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8208ddb8
	if (ctx.cr6.eq) goto loc_8208DDB8;
	// li r11,200
	ctx.r11.s64 = 200;
	// addi r7,r3,4
	ctx.r7.s64 = ctx.r3.s64 + 4;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// li r10,199
	ctx.r10.s64 = 199;
	// addi r11,r7,12
	ctx.r11.s64 = ctx.r7.s64 + 12;
	// addi r8,r8,-7184
	ctx.r8.s64 = ctx.r8.s64 + -7184;
loc_8208DD84:
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r31,-8(r11)
	REX_STORE_U32(ctx.r11.u32 + -8, ctx.r31.u32);
	// addi r9,r9,28
	ctx.r9.s64 = ctx.r9.s64 + 28;
	// stw r31,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r31.u32);
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// stb r31,8(r11)
	REX_STORE_U8(ctx.r11.u32 + 8, ctx.r31.u8);
	// sth r31,12(r11)
	REX_STORE_U16(ctx.r11.u32 + 12, ctx.r31.u16);
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// bge 0x8208dd84
	if (!ctx.cr0.lt) goto loc_8208DD84;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// b 0x8208ddbc
	goto loc_8208DDBC;
loc_8208DDB8:
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
loc_8208DDBC:
	// addis r9,r23,2
	ctx.r9.s64 = ctx.r23.s64 + 131072;
	// addis r10,r23,2
	ctx.r10.s64 = ctx.r23.s64 + 131072;
	// addi r9,r9,-18564
	ctx.r9.s64 = ctx.r9.s64 + -18564;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r10,r10,-27444
	ctx.r10.s64 = ctx.r10.s64 + -27444;
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
loc_8208DDD4:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,5600
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5600, ctx.xer);
	// blt cr6,0x8208ddd4
	if (ctx.cr6.lt) goto loc_8208DDD4;
	// lbz r11,-22601(r22)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r22.u32 + -22601);
	// sth r31,14(r23)
	REX_STORE_U16(ctx.r23.u32 + 14, ctx.r31.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208de14
	if (!ctx.cr6.eq) goto loc_8208DE14;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8208DE14;
	sub_820A71E8(ctx, base);
loc_8208DE14:
	// bl 0x820b5eb8
	ctx.lr = 0x8208DE18;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,18004
	ctx.r4.s64 = 18004;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8208DE28;
	sub_8209BDD8(ctx, base);
	// li r24,500
	ctx.r24.s64 = 500;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8208de90
	if (ctx.cr6.eq) goto loc_8208DE90;
	// addi r7,r3,4
	ctx.r7.s64 = ctx.r3.s64 + 4;
	// stw r24,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r24.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r10,499
	ctx.r10.s64 = 499;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// addi r11,r7,12
	ctx.r11.s64 = ctx.r7.s64 + 12;
	// addi r8,r8,-4716
	ctx.r8.s64 = ctx.r8.s64 + -4716;
loc_8208DE50:
	// stw r31,-8(r11)
	REX_STORE_U32(ctx.r11.u32 + -8, ctx.r31.u32);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r31,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r31.u32);
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// stb r31,8(r11)
	REX_STORE_U8(ctx.r11.u32 + 8, ctx.r31.u8);
	// sth r31,12(r11)
	REX_STORE_U16(ctx.r11.u32 + 12, ctx.r31.u16);
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,36
	ctx.r9.s64 = ctx.r9.s64 + 36;
	// stw r31,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r31.u32);
	// sth r31,20(r11)
	REX_STORE_U16(ctx.r11.u32 + 20, ctx.r31.u16);
	// sth r31,22(r11)
	REX_STORE_U16(ctx.r11.u32 + 22, ctx.r31.u16);
	// addi r11,r11,36
	ctx.r11.s64 = ctx.r11.s64 + 36;
	// bge 0x8208de50
	if (!ctx.cr0.lt) goto loc_8208DE50;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// b 0x8208de94
	goto loc_8208DE94;
loc_8208DE90:
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
loc_8208DE94:
	// addis r9,r23,2
	ctx.r9.s64 = ctx.r23.s64 + 131072;
	// addis r10,r23,2
	ctx.r10.s64 = ctx.r23.s64 + 131072;
	// addi r9,r9,-18560
	ctx.r9.s64 = ctx.r9.s64 + -18560;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r10,r10,-26644
	ctx.r10.s64 = ctx.r10.s64 + -26644;
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
loc_8208DEAC:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r11,r11,36
	ctx.r11.s64 = ctx.r11.s64 + 36;
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,18000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 18000, ctx.xer);
	// blt cr6,0x8208deac
	if (ctx.cr6.lt) goto loc_8208DEAC;
	// lbz r11,-22601(r22)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r22.u32 + -22601);
	// sth r31,16(r23)
	REX_STORE_U16(ctx.r23.u32 + 16, ctx.r31.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208deec
	if (!ctx.cr6.eq) goto loc_8208DEEC;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8208DEEC;
	sub_820A71E8(ctx, base);
loc_8208DEEC:
	// bl 0x820b5eb8
	ctx.lr = 0x8208DEF0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r4,2
	ctx.r4.s64 = 131072;
	// ori r4,r4,12932
	ctx.r4.u64 = ctx.r4.u64 | 12932;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8208DF04;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8208df80
	if (ctx.cr6.eq) goto loc_8208DF80;
	// li r11,1000
	ctx.r11.s64 = 1000;
	// addi r25,r3,4
	ctx.r25.s64 = ctx.r3.s64 + 4;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r27,r25
	ctx.r27.u64 = ctx.r25.u64;
	// li r28,999
	ctx.r28.s64 = 999;
	// addi r29,r25,12
	ctx.r29.s64 = ctx.r25.s64 + 12;
	// addi r26,r11,-4672
	ctx.r26.s64 = ctx.r11.s64 + -4672;
loc_8208DF2C:
	// li r5,96
	ctx.r5.s64 = 96;
	// stw r31,-8(r29)
	REX_STORE_U32(ctx.r29.u32 + -8, ctx.r31.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r31,-4(r29)
	REX_STORE_U32(ctx.r29.u32 + -4, ctx.r31.u32);
	// addi r3,r29,32
	ctx.r3.s64 = ctx.r29.s64 + 32;
	// stw r31,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r31.u32);
	// stw r30,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r30.u32);
	// stb r31,8(r29)
	REX_STORE_U8(ctx.r29.u32 + 8, ctx.r31.u8);
	// sth r31,12(r29)
	REX_STORE_U16(ctx.r29.u32 + 12, ctx.r31.u16);
	// stw r26,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r26.u32);
	// sth r31,20(r29)
	REX_STORE_U16(ctx.r29.u32 + 20, ctx.r31.u16);
	// stw r31,24(r29)
	REX_STORE_U32(ctx.r29.u32 + 24, ctx.r31.u32);
	// stw r31,28(r29)
	REX_STORE_U32(ctx.r29.u32 + 28, ctx.r31.u32);
	// stw r31,128(r29)
	REX_STORE_U32(ctx.r29.u32 + 128, ctx.r31.u32);
	// bl 0x82129fa0
	ctx.lr = 0x8208DF68;
	sub_82129FA0(ctx, base);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r27,r27,144
	ctx.r27.s64 = ctx.r27.s64 + 144;
	// addi r29,r29,144
	ctx.r29.s64 = ctx.r29.s64 + 144;
	// bge 0x8208df2c
	if (!ctx.cr0.lt) goto loc_8208DF2C;
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// b 0x8208df84
	goto loc_8208DF84;
loc_8208DF80:
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
loc_8208DF84:
	// addis r9,r23,2
	ctx.r9.s64 = ctx.r23.s64 + 131072;
	// addis r10,r23,2
	ctx.r10.s64 = ctx.r23.s64 + 131072;
	// addi r9,r9,-18556
	ctx.r9.s64 = ctx.r9.s64 + -18556;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r10,r10,-24644
	ctx.r10.s64 = ctx.r10.s64 + -24644;
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// lis r8,2
	ctx.r8.s64 = 131072;
	// ori r7,r8,12928
	ctx.r7.u64 = ctx.r8.u64 | 12928;
loc_8208DFA4:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r11,r11,144
	ctx.r11.s64 = ctx.r11.s64 + 144;
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x8208dfa4
	if (ctx.cr6.lt) goto loc_8208DFA4;
	// lbz r11,-22601(r22)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r22.u32 + -22601);
	// sth r31,18(r23)
	REX_STORE_U16(ctx.r23.u32 + 18, ctx.r31.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208dfe4
	if (!ctx.cr6.eq) goto loc_8208DFE4;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8208DFE4;
	sub_820A71E8(ctx, base);
loc_8208DFE4:
	// bl 0x820b5eb8
	ctx.lr = 0x8208DFE8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,2628
	ctx.r4.s64 = 2628;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8208DFF8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8208e3f8
	if (ctx.cr6.eq) goto loc_8208E3F8;
	// li r11,16
	ctx.r11.s64 = 16;
	// addi r7,r3,4
	ctx.r7.s64 = ctx.r3.s64 + 4;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// addi r11,r7,12
	ctx.r11.s64 = ctx.r7.s64 + 12;
	// li r9,2
	ctx.r9.s64 = 2;
	// addi r10,r10,-4624
	ctx.r10.s64 = ctx.r10.s64 + -4624;
loc_8208E020:
	// stw r31,-8(r11)
	REX_STORE_U32(ctx.r11.u32 + -8, ctx.r31.u32);
	// stw r31,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r31.u32);
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// stb r31,8(r11)
	REX_STORE_U8(ctx.r11.u32 + 8, ctx.r31.u8);
	// sth r31,12(r11)
	REX_STORE_U16(ctx.r11.u32 + 12, ctx.r31.u16);
	// stw r31,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r31.u32);
	// stw r31,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r31.u32);
	// stfs f31,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 32, temp.u32);
	// stfs f30,40(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 40, temp.u32);
	// stb r31,36(r11)
	REX_STORE_U8(ctx.r11.u32 + 36, ctx.r31.u8);
	// stfs f30,44(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 44, temp.u32);
	// stb r31,37(r11)
	REX_STORE_U8(ctx.r11.u32 + 37, ctx.r31.u8);
	// stfs f31,48(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 48, temp.u32);
	// stb r31,38(r11)
	REX_STORE_U8(ctx.r11.u32 + 38, ctx.r31.u8);
	// stfs f30,24(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// stfs f30,28(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 28, temp.u32);
	// stfs f31,52(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 52, temp.u32);
	// stfs f31,56(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 56, temp.u32);
	// stfs f31,60(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 60, temp.u32);
	// stw r31,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r31.u32);
	// sth r31,70(r11)
	REX_STORE_U16(ctx.r11.u32 + 70, ctx.r31.u16);
	// sth r31,72(r11)
	REX_STORE_U16(ctx.r11.u32 + 72, ctx.r31.u16);
	// stw r31,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r31.u32);
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// lbz r6,74(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 74);
	// clrlwi r5,r6,28
	ctx.r5.u64 = ctx.r6.u32 & 0xF;
	// stb r5,74(r11)
	REX_STORE_U8(ctx.r11.u32 + 74, ctx.r5.u8);
	// stw r31,84(r11)
	REX_STORE_U32(ctx.r11.u32 + 84, ctx.r31.u32);
	// stb r31,88(r11)
	REX_STORE_U8(ctx.r11.u32 + 88, ctx.r31.u8);
	// stw r31,156(r11)
	REX_STORE_U32(ctx.r11.u32 + 156, ctx.r31.u32);
	// stw r31,160(r11)
	REX_STORE_U32(ctx.r11.u32 + 160, ctx.r31.u32);
	// stw r31,164(r11)
	REX_STORE_U32(ctx.r11.u32 + 164, ctx.r31.u32);
	// stw r30,168(r11)
	REX_STORE_U32(ctx.r11.u32 + 168, ctx.r30.u32);
	// stb r31,172(r11)
	REX_STORE_U8(ctx.r11.u32 + 172, ctx.r31.u8);
	// sth r31,176(r11)
	REX_STORE_U16(ctx.r11.u32 + 176, ctx.r31.u16);
	// stw r31,180(r11)
	REX_STORE_U32(ctx.r11.u32 + 180, ctx.r31.u32);
	// stw r31,184(r11)
	REX_STORE_U32(ctx.r11.u32 + 184, ctx.r31.u32);
	// stfs f30,188(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 188, temp.u32);
	// stfs f30,192(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 192, temp.u32);
	// stfs f31,196(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 196, temp.u32);
	// stfs f30,204(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 204, temp.u32);
	// stfs f30,208(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 208, temp.u32);
	// stfs f31,212(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 212, temp.u32);
	// stfs f31,216(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 216, temp.u32);
	// stfs f31,220(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 220, temp.u32);
	// stfs f31,224(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 224, temp.u32);
	// stb r31,200(r11)
	REX_STORE_U8(ctx.r11.u32 + 200, ctx.r31.u8);
	// stb r31,201(r11)
	REX_STORE_U8(ctx.r11.u32 + 201, ctx.r31.u8);
	// stb r31,202(r11)
	REX_STORE_U8(ctx.r11.u32 + 202, ctx.r31.u8);
	// stw r31,228(r11)
	REX_STORE_U32(ctx.r11.u32 + 228, ctx.r31.u32);
	// sth r31,234(r11)
	REX_STORE_U16(ctx.r11.u32 + 234, ctx.r31.u16);
	// sth r31,236(r11)
	REX_STORE_U16(ctx.r11.u32 + 236, ctx.r31.u16);
	// stw r31,240(r11)
	REX_STORE_U32(ctx.r11.u32 + 240, ctx.r31.u32);
	// stw r10,152(r11)
	REX_STORE_U32(ctx.r11.u32 + 152, ctx.r10.u32);
	// lbz r4,238(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 238);
	// clrlwi r3,r4,28
	ctx.r3.u64 = ctx.r4.u32 & 0xF;
	// stb r3,238(r11)
	REX_STORE_U8(ctx.r11.u32 + 238, ctx.r3.u8);
	// stw r31,248(r11)
	REX_STORE_U32(ctx.r11.u32 + 248, ctx.r31.u32);
	// stb r31,252(r11)
	REX_STORE_U8(ctx.r11.u32 + 252, ctx.r31.u8);
	// stw r31,320(r11)
	REX_STORE_U32(ctx.r11.u32 + 320, ctx.r31.u32);
	// stw r31,324(r11)
	REX_STORE_U32(ctx.r11.u32 + 324, ctx.r31.u32);
	// stw r31,328(r11)
	REX_STORE_U32(ctx.r11.u32 + 328, ctx.r31.u32);
	// stw r30,332(r11)
	REX_STORE_U32(ctx.r11.u32 + 332, ctx.r30.u32);
	// stb r31,336(r11)
	REX_STORE_U8(ctx.r11.u32 + 336, ctx.r31.u8);
	// sth r31,340(r11)
	REX_STORE_U16(ctx.r11.u32 + 340, ctx.r31.u16);
	// stw r31,344(r11)
	REX_STORE_U32(ctx.r11.u32 + 344, ctx.r31.u32);
	// stw r31,348(r11)
	REX_STORE_U32(ctx.r11.u32 + 348, ctx.r31.u32);
	// stfs f30,352(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 352, temp.u32);
	// stfs f30,356(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 356, temp.u32);
	// stfs f31,360(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 360, temp.u32);
	// stfs f30,368(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 368, temp.u32);
	// stfs f30,372(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 372, temp.u32);
	// stfs f31,376(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 376, temp.u32);
	// stfs f31,380(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 380, temp.u32);
	// stfs f31,384(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 384, temp.u32);
	// stfs f31,388(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 388, temp.u32);
	// stb r31,364(r11)
	REX_STORE_U8(ctx.r11.u32 + 364, ctx.r31.u8);
	// stb r31,365(r11)
	REX_STORE_U8(ctx.r11.u32 + 365, ctx.r31.u8);
	// stb r31,366(r11)
	REX_STORE_U8(ctx.r11.u32 + 366, ctx.r31.u8);
	// stw r31,392(r11)
	REX_STORE_U32(ctx.r11.u32 + 392, ctx.r31.u32);
	// lbz r6,402(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 402);
	// sth r31,398(r11)
	REX_STORE_U16(ctx.r11.u32 + 398, ctx.r31.u16);
	// clrlwi r5,r6,28
	ctx.r5.u64 = ctx.r6.u32 & 0xF;
	// sth r31,400(r11)
	REX_STORE_U16(ctx.r11.u32 + 400, ctx.r31.u16);
	// stw r31,404(r11)
	REX_STORE_U32(ctx.r11.u32 + 404, ctx.r31.u32);
	// stb r5,402(r11)
	REX_STORE_U8(ctx.r11.u32 + 402, ctx.r5.u8);
	// stw r10,316(r11)
	REX_STORE_U32(ctx.r11.u32 + 316, ctx.r10.u32);
	// stw r31,412(r11)
	REX_STORE_U32(ctx.r11.u32 + 412, ctx.r31.u32);
	// stb r31,416(r11)
	REX_STORE_U8(ctx.r11.u32 + 416, ctx.r31.u8);
	// stw r31,484(r11)
	REX_STORE_U32(ctx.r11.u32 + 484, ctx.r31.u32);
	// stw r31,488(r11)
	REX_STORE_U32(ctx.r11.u32 + 488, ctx.r31.u32);
	// stw r31,492(r11)
	REX_STORE_U32(ctx.r11.u32 + 492, ctx.r31.u32);
	// stw r30,496(r11)
	REX_STORE_U32(ctx.r11.u32 + 496, ctx.r30.u32);
	// stb r31,500(r11)
	REX_STORE_U8(ctx.r11.u32 + 500, ctx.r31.u8);
	// sth r31,504(r11)
	REX_STORE_U16(ctx.r11.u32 + 504, ctx.r31.u16);
	// stw r31,508(r11)
	REX_STORE_U32(ctx.r11.u32 + 508, ctx.r31.u32);
	// stw r31,512(r11)
	REX_STORE_U32(ctx.r11.u32 + 512, ctx.r31.u32);
	// stfs f30,516(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 516, temp.u32);
	// stfs f30,520(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 520, temp.u32);
	// stfs f31,524(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 524, temp.u32);
	// stfs f30,532(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 532, temp.u32);
	// stfs f30,536(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 536, temp.u32);
	// stfs f31,540(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 540, temp.u32);
	// stfs f31,544(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 544, temp.u32);
	// stfs f31,548(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 548, temp.u32);
	// stfs f31,552(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 552, temp.u32);
	// stb r31,528(r11)
	REX_STORE_U8(ctx.r11.u32 + 528, ctx.r31.u8);
	// stb r31,529(r11)
	REX_STORE_U8(ctx.r11.u32 + 529, ctx.r31.u8);
	// stb r31,530(r11)
	REX_STORE_U8(ctx.r11.u32 + 530, ctx.r31.u8);
	// stw r31,556(r11)
	REX_STORE_U32(ctx.r11.u32 + 556, ctx.r31.u32);
	// sth r31,562(r11)
	REX_STORE_U16(ctx.r11.u32 + 562, ctx.r31.u16);
	// sth r31,564(r11)
	REX_STORE_U16(ctx.r11.u32 + 564, ctx.r31.u16);
	// stw r31,568(r11)
	REX_STORE_U32(ctx.r11.u32 + 568, ctx.r31.u32);
	// stw r10,480(r11)
	REX_STORE_U32(ctx.r11.u32 + 480, ctx.r10.u32);
	// lbz r4,566(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 566);
	// clrlwi r3,r4,28
	ctx.r3.u64 = ctx.r4.u32 & 0xF;
	// stb r3,566(r11)
	REX_STORE_U8(ctx.r11.u32 + 566, ctx.r3.u8);
	// stw r31,576(r11)
	REX_STORE_U32(ctx.r11.u32 + 576, ctx.r31.u32);
	// stb r31,580(r11)
	REX_STORE_U8(ctx.r11.u32 + 580, ctx.r31.u8);
	// stw r31,648(r11)
	REX_STORE_U32(ctx.r11.u32 + 648, ctx.r31.u32);
	// stw r31,652(r11)
	REX_STORE_U32(ctx.r11.u32 + 652, ctx.r31.u32);
	// stw r31,656(r11)
	REX_STORE_U32(ctx.r11.u32 + 656, ctx.r31.u32);
	// stw r30,660(r11)
	REX_STORE_U32(ctx.r11.u32 + 660, ctx.r30.u32);
	// stb r31,664(r11)
	REX_STORE_U8(ctx.r11.u32 + 664, ctx.r31.u8);
	// sth r31,668(r11)
	REX_STORE_U16(ctx.r11.u32 + 668, ctx.r31.u16);
	// stw r31,672(r11)
	REX_STORE_U32(ctx.r11.u32 + 672, ctx.r31.u32);
	// stw r31,676(r11)
	REX_STORE_U32(ctx.r11.u32 + 676, ctx.r31.u32);
	// stfs f30,680(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 680, temp.u32);
	// stfs f30,684(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 684, temp.u32);
	// stfs f31,688(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 688, temp.u32);
	// stfs f30,696(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 696, temp.u32);
	// stfs f30,700(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 700, temp.u32);
	// stfs f31,704(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 704, temp.u32);
	// stfs f31,708(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 708, temp.u32);
	// stfs f31,712(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 712, temp.u32);
	// stfs f31,716(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 716, temp.u32);
	// stb r31,692(r11)
	REX_STORE_U8(ctx.r11.u32 + 692, ctx.r31.u8);
	// stb r31,693(r11)
	REX_STORE_U8(ctx.r11.u32 + 693, ctx.r31.u8);
	// stb r31,694(r11)
	REX_STORE_U8(ctx.r11.u32 + 694, ctx.r31.u8);
	// stw r31,720(r11)
	REX_STORE_U32(ctx.r11.u32 + 720, ctx.r31.u32);
	// sth r31,726(r11)
	REX_STORE_U16(ctx.r11.u32 + 726, ctx.r31.u16);
	// sth r31,728(r11)
	REX_STORE_U16(ctx.r11.u32 + 728, ctx.r31.u16);
	// stw r31,732(r11)
	REX_STORE_U32(ctx.r11.u32 + 732, ctx.r31.u32);
	// stw r10,644(r11)
	REX_STORE_U32(ctx.r11.u32 + 644, ctx.r10.u32);
	// lbz r6,730(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 730);
	// clrlwi r5,r6,28
	ctx.r5.u64 = ctx.r6.u32 & 0xF;
	// stb r5,730(r11)
	REX_STORE_U8(ctx.r11.u32 + 730, ctx.r5.u8);
	// stw r31,740(r11)
	REX_STORE_U32(ctx.r11.u32 + 740, ctx.r31.u32);
	// stb r31,744(r11)
	REX_STORE_U8(ctx.r11.u32 + 744, ctx.r31.u8);
	// stw r31,812(r11)
	REX_STORE_U32(ctx.r11.u32 + 812, ctx.r31.u32);
	// stw r31,816(r11)
	REX_STORE_U32(ctx.r11.u32 + 816, ctx.r31.u32);
	// stw r31,820(r11)
	REX_STORE_U32(ctx.r11.u32 + 820, ctx.r31.u32);
	// stw r30,824(r11)
	REX_STORE_U32(ctx.r11.u32 + 824, ctx.r30.u32);
	// stb r31,828(r11)
	REX_STORE_U8(ctx.r11.u32 + 828, ctx.r31.u8);
	// sth r31,832(r11)
	REX_STORE_U16(ctx.r11.u32 + 832, ctx.r31.u16);
	// stw r31,836(r11)
	REX_STORE_U32(ctx.r11.u32 + 836, ctx.r31.u32);
	// stw r31,840(r11)
	REX_STORE_U32(ctx.r11.u32 + 840, ctx.r31.u32);
	// stfs f30,844(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 844, temp.u32);
	// stfs f30,848(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 848, temp.u32);
	// stfs f31,852(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 852, temp.u32);
	// stfs f30,860(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 860, temp.u32);
	// stfs f30,864(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 864, temp.u32);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stfs f31,868(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 868, temp.u32);
	// addi r8,r8,1312
	ctx.r8.s64 = ctx.r8.s64 + 1312;
	// stfs f31,872(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 872, temp.u32);
	// stfs f31,876(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 876, temp.u32);
	// stfs f31,880(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 880, temp.u32);
	// stb r31,856(r11)
	REX_STORE_U8(ctx.r11.u32 + 856, ctx.r31.u8);
	// stb r31,857(r11)
	REX_STORE_U8(ctx.r11.u32 + 857, ctx.r31.u8);
	// stb r31,858(r11)
	REX_STORE_U8(ctx.r11.u32 + 858, ctx.r31.u8);
	// lbz r4,894(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 894);
	// clrlwi r3,r4,28
	ctx.r3.u64 = ctx.r4.u32 & 0xF;
	// stb r3,894(r11)
	REX_STORE_U8(ctx.r11.u32 + 894, ctx.r3.u8);
	// stw r31,884(r11)
	REX_STORE_U32(ctx.r11.u32 + 884, ctx.r31.u32);
	// sth r31,890(r11)
	REX_STORE_U16(ctx.r11.u32 + 890, ctx.r31.u16);
	// sth r31,892(r11)
	REX_STORE_U16(ctx.r11.u32 + 892, ctx.r31.u16);
	// stw r31,896(r11)
	REX_STORE_U32(ctx.r11.u32 + 896, ctx.r31.u32);
	// stw r10,808(r11)
	REX_STORE_U32(ctx.r11.u32 + 808, ctx.r10.u32);
	// stw r31,904(r11)
	REX_STORE_U32(ctx.r11.u32 + 904, ctx.r31.u32);
	// stb r31,908(r11)
	REX_STORE_U8(ctx.r11.u32 + 908, ctx.r31.u8);
	// stw r31,976(r11)
	REX_STORE_U32(ctx.r11.u32 + 976, ctx.r31.u32);
	// stw r31,980(r11)
	REX_STORE_U32(ctx.r11.u32 + 980, ctx.r31.u32);
	// stw r31,984(r11)
	REX_STORE_U32(ctx.r11.u32 + 984, ctx.r31.u32);
	// stw r30,988(r11)
	REX_STORE_U32(ctx.r11.u32 + 988, ctx.r30.u32);
	// stb r31,992(r11)
	REX_STORE_U8(ctx.r11.u32 + 992, ctx.r31.u8);
	// sth r31,996(r11)
	REX_STORE_U16(ctx.r11.u32 + 996, ctx.r31.u16);
	// stw r31,1000(r11)
	REX_STORE_U32(ctx.r11.u32 + 1000, ctx.r31.u32);
	// stw r31,1004(r11)
	REX_STORE_U32(ctx.r11.u32 + 1004, ctx.r31.u32);
	// stfs f30,1008(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1008, temp.u32);
	// stfs f30,1012(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1012, temp.u32);
	// stfs f31,1016(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1016, temp.u32);
	// stfs f30,1024(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1024, temp.u32);
	// stfs f30,1028(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1028, temp.u32);
	// stfs f31,1032(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1032, temp.u32);
	// stfs f31,1036(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1036, temp.u32);
	// stfs f31,1040(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1040, temp.u32);
	// stfs f31,1044(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1044, temp.u32);
	// stb r31,1020(r11)
	REX_STORE_U8(ctx.r11.u32 + 1020, ctx.r31.u8);
	// stb r31,1021(r11)
	REX_STORE_U8(ctx.r11.u32 + 1021, ctx.r31.u8);
	// stb r31,1022(r11)
	REX_STORE_U8(ctx.r11.u32 + 1022, ctx.r31.u8);
	// stw r31,1048(r11)
	REX_STORE_U32(ctx.r11.u32 + 1048, ctx.r31.u32);
	// sth r31,1054(r11)
	REX_STORE_U16(ctx.r11.u32 + 1054, ctx.r31.u16);
	// sth r31,1056(r11)
	REX_STORE_U16(ctx.r11.u32 + 1056, ctx.r31.u16);
	// stw r31,1060(r11)
	REX_STORE_U32(ctx.r11.u32 + 1060, ctx.r31.u32);
	// stw r10,972(r11)
	REX_STORE_U32(ctx.r11.u32 + 972, ctx.r10.u32);
	// lbz r6,1058(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 1058);
	// clrlwi r5,r6,28
	ctx.r5.u64 = ctx.r6.u32 & 0xF;
	// stb r5,1058(r11)
	REX_STORE_U8(ctx.r11.u32 + 1058, ctx.r5.u8);
	// stw r31,1068(r11)
	REX_STORE_U32(ctx.r11.u32 + 1068, ctx.r31.u32);
	// stb r31,1072(r11)
	REX_STORE_U8(ctx.r11.u32 + 1072, ctx.r31.u8);
	// stw r31,1140(r11)
	REX_STORE_U32(ctx.r11.u32 + 1140, ctx.r31.u32);
	// stw r31,1144(r11)
	REX_STORE_U32(ctx.r11.u32 + 1144, ctx.r31.u32);
	// stw r31,1148(r11)
	REX_STORE_U32(ctx.r11.u32 + 1148, ctx.r31.u32);
	// stw r30,1152(r11)
	REX_STORE_U32(ctx.r11.u32 + 1152, ctx.r30.u32);
	// stb r31,1156(r11)
	REX_STORE_U8(ctx.r11.u32 + 1156, ctx.r31.u8);
	// sth r31,1160(r11)
	REX_STORE_U16(ctx.r11.u32 + 1160, ctx.r31.u16);
	// stw r31,1164(r11)
	REX_STORE_U32(ctx.r11.u32 + 1164, ctx.r31.u32);
	// stw r31,1168(r11)
	REX_STORE_U32(ctx.r11.u32 + 1168, ctx.r31.u32);
	// stfs f30,1172(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1172, temp.u32);
	// stfs f30,1176(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1176, temp.u32);
	// stfs f31,1180(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1180, temp.u32);
	// stfs f30,1188(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1188, temp.u32);
	// stfs f30,1192(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 1192, temp.u32);
	// stfs f31,1196(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1196, temp.u32);
	// stfs f31,1200(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1200, temp.u32);
	// stfs f31,1204(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1204, temp.u32);
	// stfs f31,1208(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 1208, temp.u32);
	// stb r31,1184(r11)
	REX_STORE_U8(ctx.r11.u32 + 1184, ctx.r31.u8);
	// stb r31,1185(r11)
	REX_STORE_U8(ctx.r11.u32 + 1185, ctx.r31.u8);
	// stb r31,1186(r11)
	REX_STORE_U8(ctx.r11.u32 + 1186, ctx.r31.u8);
	// stw r31,1212(r11)
	REX_STORE_U32(ctx.r11.u32 + 1212, ctx.r31.u32);
	// sth r31,1218(r11)
	REX_STORE_U16(ctx.r11.u32 + 1218, ctx.r31.u16);
	// sth r31,1220(r11)
	REX_STORE_U16(ctx.r11.u32 + 1220, ctx.r31.u16);
	// stw r31,1224(r11)
	REX_STORE_U32(ctx.r11.u32 + 1224, ctx.r31.u32);
	// stw r10,1136(r11)
	REX_STORE_U32(ctx.r11.u32 + 1136, ctx.r10.u32);
	// lbz r4,1222(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 1222);
	// clrlwi r3,r4,28
	ctx.r3.u64 = ctx.r4.u32 & 0xF;
	// stb r3,1222(r11)
	REX_STORE_U8(ctx.r11.u32 + 1222, ctx.r3.u8);
	// stw r31,1232(r11)
	REX_STORE_U32(ctx.r11.u32 + 1232, ctx.r31.u32);
	// stb r31,1236(r11)
	REX_STORE_U8(ctx.r11.u32 + 1236, ctx.r31.u8);
	// addi r11,r11,1312
	ctx.r11.s64 = ctx.r11.s64 + 1312;
	// bne 0x8208e020
	if (!ctx.cr0.eq) goto loc_8208E020;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// b 0x8208e3fc
	goto loc_8208E3FC;
loc_8208E3F8:
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
loc_8208E3FC:
	// addis r9,r23,2
	ctx.r9.s64 = ctx.r23.s64 + 131072;
	// addis r10,r23,2
	ctx.r10.s64 = ctx.r23.s64 + 131072;
	// addi r9,r9,-18552
	ctx.r9.s64 = ctx.r9.s64 + -18552;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r10,r10,-20644
	ctx.r10.s64 = ctx.r10.s64 + -20644;
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
loc_8208E414:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r11,r11,164
	ctx.r11.s64 = ctx.r11.s64 + 164;
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,2624
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2624, ctx.xer);
	// blt cr6,0x8208e414
	if (ctx.cr6.lt) goto loc_8208E414;
	// lbz r11,-22601(r22)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r22.u32 + -22601);
	// sth r31,20(r23)
	REX_STORE_U16(ctx.r23.u32 + 20, ctx.r31.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208e454
	if (!ctx.cr6.eq) goto loc_8208E454;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8208E454;
	sub_820A71E8(ctx, base);
loc_8208E454:
	// bl 0x820b5eb8
	ctx.lr = 0x8208E458;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// ori r4,r4,18468
	ctx.r4.u64 = ctx.r4.u64 | 18468;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8208E46C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8208e49c
	if (ctx.cr6.eq) goto loc_8208E49C;
	// addi r29,r3,4
	ctx.r29.s64 = ctx.r3.s64 + 4;
	// stw r24,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r24.u32);
	// li r30,499
	ctx.r30.s64 = 499;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_8208E484:
	// bl 0x82094c30
	ctx.lr = 0x8208E488;
	sub_82094C30(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r3,r3,168
	ctx.r3.s64 = ctx.r3.s64 + 168;
	// bge 0x8208e484
	if (!ctx.cr0.lt) goto loc_8208E484;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// b 0x8208e4a0
	goto loc_8208E4A0;
loc_8208E49C:
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
loc_8208E4A0:
	// addis r10,r23,2
	ctx.r10.s64 = ctx.r23.s64 + 131072;
	// addis r11,r23,2
	ctx.r11.s64 = ctx.r23.s64 + 131072;
	// addi r10,r10,-18548
	ctx.r10.s64 = ctx.r10.s64 + -18548;
	// addi r11,r11,-20580
	ctx.r11.s64 = ctx.r11.s64 + -20580;
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r9,18464
	ctx.r8.u64 = ctx.r9.u64 | 18464;
loc_8208E4BC:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + ctx.r31.u64;
	// addi r31,r31,168
	ctx.r31.s64 = ctx.r31.s64 + 168;
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmpw cr6,r31,r8
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x8208e4bc
	if (ctx.cr6.lt) goto loc_8208E4BC;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f31,-112(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
}
