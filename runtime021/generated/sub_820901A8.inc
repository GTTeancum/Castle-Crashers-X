DEFINE_REX_FUNC(sub_820901A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x820901B0;
	__savegprlr_25(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// stb r30,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r30.u8);
	// lfs f13,18236(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18236);
	ctx.f13.f64 = double(temp.f32);
	// stw r30,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// lfs f0,9536(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// stw r30,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// stw r30,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r30.u32);
	// addi r29,r31,4
	ctx.r29.s64 = ctx.r31.s64 + 4;
	// stw r30,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// addi r11,r31,8252
	ctx.r11.s64 = ctx.r31.s64 + 8252;
	// li r10,31
	ctx.r10.s64 = 31;
	// stw r30,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r30.u32);
	// stw r30,4916(r31)
	REX_STORE_U32(ctx.r31.u32 + 4916, ctx.r30.u32);
	// stw r30,4920(r31)
	REX_STORE_U32(ctx.r31.u32 + 4920, ctx.r30.u32);
	// stw r30,7984(r31)
	REX_STORE_U32(ctx.r31.u32 + 7984, ctx.r30.u32);
	// stw r30,7988(r31)
	REX_STORE_U32(ctx.r31.u32 + 7988, ctx.r30.u32);
	// stw r30,8248(r31)
	REX_STORE_U32(ctx.r31.u32 + 8248, ctx.r30.u32);
loc_82090218:
	// stfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stb r30,12(r11)
	REX_STORE_U8(ctx.r11.u32 + 12, ctx.r30.u8);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// stb r30,13(r11)
	REX_STORE_U8(ctx.r11.u32 + 13, ctx.r30.u8);
	// stfs f0,8(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// stb r30,14(r11)
	REX_STORE_U8(ctx.r11.u32 + 14, ctx.r30.u8);
	// stfs f13,16(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stfs f13,20(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// stfs f0,24(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// stfs f0,28(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 28, temp.u32);
	// stfs f0,32(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 32, temp.u32);
	// stfs f0,36(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 36, temp.u32);
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
	// bge 0x82090218
	if (!ctx.cr0.lt) goto loc_82090218;
	// addi r27,r31,9536
	ctx.r27.s64 = ctx.r31.s64 + 9536;
	// stw r30,9532(r31)
	REX_STORE_U32(ctx.r31.u32 + 9532, ctx.r30.u32);
	// li r10,31
	ctx.r10.s64 = 31;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_82090264:
	// stfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// stfs f0,12(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bge 0x82090264
	if (!ctx.cr0.lt) goto loc_82090264;
	// addi r9,r31,10372
	ctx.r9.s64 = ctx.r31.s64 + 10372;
	// stfs f0,10340(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 10340, temp.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r30,10048(r31)
	REX_STORE_U32(ctx.r31.u32 + 10048, ctx.r30.u32);
	// addi r11,r9,5028
	ctx.r11.s64 = ctx.r9.s64 + 5028;
	// stw r30,10180(r31)
	REX_STORE_U32(ctx.r31.u32 + 10180, ctx.r30.u32);
	// stw r30,10320(r31)
	REX_STORE_U32(ctx.r31.u32 + 10320, ctx.r30.u32);
	// li r10,1255
	ctx.r10.s64 = 1255;
	// stw r30,10324(r31)
	REX_STORE_U32(ctx.r31.u32 + 10324, ctx.r30.u32);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r30,10328(r31)
	REX_STORE_U32(ctx.r31.u32 + 10328, ctx.r30.u32);
	// stb r30,10332(r31)
	REX_STORE_U8(ctx.r31.u32 + 10332, ctx.r30.u8);
	// stb r30,10333(r31)
	REX_STORE_U8(ctx.r31.u32 + 10333, ctx.r30.u8);
	// stw r30,10336(r31)
	REX_STORE_U32(ctx.r31.u32 + 10336, ctx.r30.u32);
	// stb r30,10344(r31)
	REX_STORE_U8(ctx.r31.u32 + 10344, ctx.r30.u8);
	// stb r30,10345(r31)
	REX_STORE_U8(ctx.r31.u32 + 10345, ctx.r30.u8);
	// stb r30,10346(r31)
	REX_STORE_U8(ctx.r31.u32 + 10346, ctx.r30.u8);
	// stw r30,10348(r31)
	REX_STORE_U32(ctx.r31.u32 + 10348, ctx.r30.u32);
	// stw r30,10352(r31)
	REX_STORE_U32(ctx.r31.u32 + 10352, ctx.r30.u32);
	// stw r30,10356(r31)
	REX_STORE_U32(ctx.r31.u32 + 10356, ctx.r30.u32);
	// stw r30,10360(r31)
	REX_STORE_U32(ctx.r31.u32 + 10360, ctx.r30.u32);
	// stw r7,10364(r31)
	REX_STORE_U32(ctx.r31.u32 + 10364, ctx.r7.u32);
	// stb r30,10368(r31)
	REX_STORE_U8(ctx.r31.u32 + 10368, ctx.r30.u8);
	// stw r30,15396(r31)
	REX_STORE_U32(ctx.r31.u32 + 15396, ctx.r30.u32);
loc_820902E0:
	// stw r30,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r30.u32);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stb r30,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r30.u8);
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// bge 0x820902e0
	if (!ctx.cr0.lt) goto loc_820902E0;
	// stw r30,20100(r9)
	REX_STORE_U32(ctx.r9.u32 + 20100, ctx.r30.u32);
	// addi r4,r28,4
	ctx.r4.s64 = ctx.r28.s64 + 4;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// addi r3,r29,4
	ctx.r3.s64 = ctx.r29.s64 + 4;
	// stb r26,112(r31)
	REX_STORE_U8(ctx.r31.u32 + 112, ctx.r26.u8);
	// lwz r5,0(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// bl 0x82129a70
	ctx.lr = 0x82090310;
	sub_82129A70(ctx, base);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// add r9,r11,r29
	ctx.r9.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lbz r8,-22601(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + -22601);
	// stb r30,4(r9)
	REX_STORE_U8(ctx.r9.u32 + 4, ctx.r30.u8);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82090348
	if (!ctx.cr6.eq) goto loc_82090348;
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
	ctx.lr = 0x82090348;
	sub_820A71E8(ctx, base);
loc_82090348:
	// bl 0x820b5eb8
	ctx.lr = 0x8209034C;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,29632
	ctx.r9.s64 = ctx.r11.s64 + 29632;
	// li r4,292
	ctx.r4.s64 = 292;
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82090364;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82090378
	if (ctx.cr6.eq) goto loc_82090378;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82094048
	ctx.lr = 0x82090374;
	sub_82094048(ctx, base);
	// b 0x8209037c
	goto loc_8209037C;
loc_82090378:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8209037C:
	// stw r3,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82066ea8
	ctx.lr = 0x82090388;
	sub_82066EA8(ctx, base);
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// stw r30,10052(r31)
	REX_STORE_U32(ctx.r31.u32 + 10052, ctx.r30.u32);
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// stw r25,288(r11)
	REX_STORE_U32(ctx.r11.u32 + 288, ctx.r25.u32);
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// bl 0x82094290
	ctx.lr = 0x820903A0;
	sub_82094290(ctx, base);
	// stw r3,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r3.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x820903b8
	if (!ctx.cr6.lt) goto loc_820903B8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-4332
	ctx.r3.s64 = ctx.r11.s64 + -4332;
	// bl 0x8208c5d8
	ctx.lr = 0x820903B8;
	sub_8208C5D8(ctx, base);
loc_820903B8:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// li r9,255
	ctx.r9.s64 = 255;
	// clrlwi r8,r26,24
	ctx.r8.u64 = ctx.r26.u32 & 0xFF;
	// stb r9,103(r31)
	REX_STORE_U8(ctx.r31.u32 + 103, ctx.r9.u8);
	// lfs f0,9544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9544);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lwz r4,8(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r5,12(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// stw r5,12(r27)
	REX_STORE_U32(ctx.r27.u32 + 12, ctx.r5.u32);
	// lwz r6,4(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r7,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r7.u32);
	// stw r6,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r6.u32);
	// stw r4,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r4.u32);
	// beq cr6,0x82090410
	if (ctx.cr6.eq) goto loc_82090410;
	// stw r30,10316(r31)
	REX_STORE_U32(ctx.r31.u32 + 10316, ctx.r30.u32);
	// b 0x82090418
	goto loc_82090418;
loc_82090410:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820906a8
	ctx.lr = 0x82090418;
	sub_820906A8(ctx, base);
loc_82090418:
	// lis r11,1525
	ctx.r11.s64 = 99942400;
	// stw r30,10312(r31)
	REX_STORE_U32(ctx.r31.u32 + 10312, ctx.r30.u32);
	// li r5,256
	ctx.r5.s64 = 256;
	// ori r10,r11,57599
	ctx.r10.u64 = ctx.r11.u64 | 57599;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,7992
	ctx.r3.s64 = ctx.r31.s64 + 7992;
	// stw r10,10184(r31)
	REX_STORE_U32(ctx.r31.u32 + 10184, ctx.r10.u32);
	// bl 0x82129fa0
	ctx.lr = 0x82090438;
	sub_82129FA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
