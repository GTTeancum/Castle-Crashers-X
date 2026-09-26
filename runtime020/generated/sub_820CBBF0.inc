DEFINE_REX_FUNC(sub_820CBBF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x820CBBF8;
	__savegprlr_22(ctx, base);
	// stwu r1,-1760(r1)
	ea = -1760 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r30,64(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r28,0(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r27,4(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lwz r25,16(r31)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r22,40(r31)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r26,8(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bne cr6,0x820cbc2c
	if (!ctx.cr6.eq) goto loc_820CBC2C;
	// clrlwi r11,r26,26
	ctx.r11.u64 = ctx.r26.u32 & 0x3F;
	// b 0x820cbc3c
	goto loc_820CBC3C;
loc_820CBC2C:
	// lis r11,10280
	ctx.r11.s64 = 673710080;
	// ori r11,r11,390
	ctx.r11.u64 = ctx.r11.u64 | 390;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x820cbc44
	if (!ctx.cr6.eq) goto loc_820CBC44;
loc_820CBC3C:
	// lis r30,10280
	ctx.r30.s64 = 673710080;
	// b 0x820cbc58
	goto loc_820CBC58;
loc_820CBC44:
	// lis r11,6184
	ctx.r11.s64 = 405274624;
	// ori r11,r11,390
	ctx.r11.u64 = ctx.r11.u64 | 390;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x820cbc60
	if (!ctx.cr6.eq) goto loc_820CBC60;
	// lis r30,6184
	ctx.r30.s64 = 405274624;
loc_820CBC58:
	// ori r30,r30,262
	ctx.r30.u64 = ctx.r30.u64 | 262;
	// b 0x820cbc90
	goto loc_820CBC90;
loc_820CBC60:
	// lis r11,10280
	ctx.r11.s64 = 673710080;
	// ori r11,r11,438
	ctx.r11.u64 = ctx.r11.u64 | 438;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x820cbc78
	if (!ctx.cr6.eq) goto loc_820CBC78;
	// lis r30,10280
	ctx.r30.s64 = 673710080;
	// b 0x820cbc8c
	goto loc_820CBC8C;
loc_820CBC78:
	// lis r11,6184
	ctx.r11.s64 = 405274624;
	// ori r11,r11,438
	ctx.r11.u64 = ctx.r11.u64 | 438;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x820cbc90
	if (!ctx.cr6.eq) goto loc_820CBC90;
	// lis r30,6184
	ctx.r30.s64 = 405274624;
loc_820CBC8C:
	// ori r30,r30,310
	ctx.r30.u64 = ctx.r30.u64 | 310;
loc_820CBC90:
	// clrlwi r23,r30,26
	ctx.r23.u64 = ctx.r30.u32 & 0x3F;
	// mr r24,r23
	ctx.r24.u64 = ctx.r23.u64;
	// cmplwi cr6,r23,50
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 50, ctx.xer);
	// bne cr6,0x820cbca8
	if (!ctx.cr6.eq) goto loc_820CBCA8;
	// li r24,6
	ctx.r24.s64 = 6;
	// b 0x820cbcb4
	goto loc_820CBCB4;
loc_820CBCA8:
	// cmplwi cr6,r24,7
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 7, ctx.xer);
	// bne cr6,0x820cbcb4
	if (!ctx.cr6.eq) goto loc_820CBCB4;
	// li r24,54
	ctx.r24.s64 = 54;
loc_820CBCB4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8214a864
	ctx.lr = 0x820CBCBC;
	__imp__VdQueryVideoMode(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r9,21556
	ctx.r9.s64 = 21556;
	// lfs f0,4852(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4852);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stw r11,21544(r29)
	REX_STORE_U32(ctx.r29.u32 + 21544, ctx.r11.u32);
	// stw r11,21552(r29)
	REX_STORE_U32(ctx.r29.u32 + 21552, ctx.r11.u32);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfiwx f0,r29,r9
	REX_STORE_U32(ctx.r29.u32 + ctx.r9.u32, ctx.f0.u32);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,21548(r29)
	REX_STORE_U32(ctx.r29.u32 + 21548, ctx.r11.u32);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820cbd30
	if (!ctx.cr6.eq) goto loc_820CBD30;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820c44a0
	ctx.lr = 0x820CBD1C;
	sub_820C44A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x820cbd2c
	if (!ctx.cr0.eq) goto loc_820CBD2C;
loc_820CBD24:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820cbe34
	goto loc_820CBE34;
loc_820CBD2C:
	// stw r3,14828(r29)
	REX_STORE_U32(ctx.r29.u32 + 14828, ctx.r3.u32);
loc_820CBD30:
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820cbd6c
	if (!ctx.cr6.eq) goto loc_820CBD6C;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820c45c0
	ctx.lr = 0x820CBD54;
	sub_820C45C0(ctx, base);
	// mr. r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq 0x820cbd24
	if (ctx.cr0.eq) goto loc_820CBD24;
	// stw r5,14832(r29)
	REX_STORE_U32(ctx.r29.u32 + 14832, ctx.r5.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820be2d8
	ctx.lr = 0x820CBD6C;
	sub_820BE2D8(ctx, base);
loc_820CBD6C:
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820cbda4
	if (ctx.cr6.eq) goto loc_820CBDA4;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820c45c0
	ctx.lr = 0x820CBD90;
	sub_820C45C0(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq 0x820cbd24
	if (ctx.cr0.eq) goto loc_820CBD24;
	// stw r4,14824(r29)
	REX_STORE_U32(ctx.r29.u32 + 14824, ctx.r4.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820be620
	ctx.lr = 0x820CBDA4;
	sub_820BE620(ctx, base);
loc_820CBDA4:
	// addi r3,r29,13544
	ctx.r3.s64 = ctx.r29.s64 + 13544;
	// li r5,124
	ctx.r5.s64 = 124;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82129a70
	ctx.lr = 0x820CBDB4;
	sub_82129A70(ctx, base);
	// rlwinm r11,r30,0,2,13
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x3FFC0000;
	// lis r10,9360
	ctx.r10.s64 = 613416960;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x820cbdd0
	if (ctx.cr6.eq) goto loc_820CBDD0;
	// oris r11,r23,10280
	ctx.r11.u64 = ctx.r23.u64 | 673710080;
	// ori r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 256;
	// stw r11,13608(r29)
	REX_STORE_U32(ctx.r29.u32 + 13608, ctx.r11.u32);
loc_820CBDD0:
	// addi r4,r31,96
	ctx.r4.s64 = ctx.r31.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820d19b8
	ctx.lr = 0x820CBDDC;
	sub_820D19B8(ctx, base);
	// cmplwi cr6,r24,7
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 7, ctx.xer);
	// beq cr6,0x820cbe0c
	if (ctx.cr6.eq) goto loc_820CBE0C;
	// cmplwi cr6,r24,54
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 54, ctx.xer);
	// beq cr6,0x820cbe0c
	if (ctx.cr6.eq) goto loc_820CBE0C;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820c9090
	ctx.lr = 0x820CBDF8;
	sub_820C9090(ctx, base);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820bdca8
	ctx.lr = 0x820CBE08;
	sub_820BDCA8(ctx, base);
	// b 0x820cbe28
	goto loc_820CBE28;
loc_820CBE0C:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820c90e0
	ctx.lr = 0x820CBE18;
	sub_820C90E0(ctx, base);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820bdd78
	ctx.lr = 0x820CBE28;
	sub_820BDD78(ctx, base);
loc_820CBE28:
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,16708(r29)
	REX_STORE_U32(ctx.r29.u32 + 16708, ctx.r11.u32);
loc_820CBE34:
	// addi r1,r1,1760
	ctx.r1.s64 = ctx.r1.s64 + 1760;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
