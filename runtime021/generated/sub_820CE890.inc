DEFINE_REX_FUNC(sub_820CE890) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x820CE898;
	__savegprlr_21(ctx, base);
	// addi r12,r1,-96
	ctx.r12.s64 = ctx.r1.s64 + -96;
	// bl 0x8212a858
	ctx.lr = 0x820CE8A0;
	__savefpr_28(ctx, base);
	// stwu r1,-544(r1)
	ea = -544 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r7
	ctx.r21.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r29,r9
	ctx.r29.u64 = ctx.r9.u64;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,352
	ctx.r7.s64 = ctx.r1.s64 + 352;
	// lis r9,2048
	ctx.r9.s64 = 134217728;
	// stw r8,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r7,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r23,r4
	ctx.r23.u64 = ctx.r4.u64;
	// stw r30,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// stw r30,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// mr r28,r10
	ctx.r28.u64 = ctx.r10.u64;
	// addi r11,r1,148
	ctx.r11.s64 = ctx.r1.s64 + 148;
	// li r10,2
	ctx.r10.s64 = 2;
	// ori r9,r9,74
	ctx.r9.u64 = ctx.r9.u64 | 74;
	// stw r11,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,2048
	ctx.r4.s64 = 2048;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x820c3ef8
	ctx.lr = 0x820CE914;
	sub_820C3EF8(ctx, base);
	// lwz r11,384(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 384);
	// lwz r10,0(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,400(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 400);
	// li r6,16
	ctx.r6.s64 = 16;
	// rlwimi r11,r10,0,0,19
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFF000) | (ctx.r11.u64 & 0xFFFFFFFF00000FFF);
	// clrlwi r10,r9,20
	ctx.r10.u64 = ctx.r9.u32 & 0xFFF;
	// stw r10,400(r1)
	REX_STORE_U32(ctx.r1.u32 + 400, ctx.r10.u32);
	// li r5,112
	ctx.r5.s64 = 112;
	// stw r11,384(r1)
	REX_STORE_U32(ctx.r1.u32 + 384, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820c0248
	ctx.lr = 0x820CE944;
	sub_820C0248(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,352
	ctx.r5.s64 = ctx.r1.s64 + 352;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820c86d8
	ctx.lr = 0x820CE958;
	sub_820C86D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ccbd8
	ctx.lr = 0x820CE960;
	sub_820CCBD8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r27,r11,12732
	ctx.r27.s64 = ctx.r11.s64 + 12732;
	// li r5,309
	ctx.r5.s64 = 309;
	// addi r4,r27,228
	ctx.r4.s64 = ctx.r27.s64 + 228;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ccc30
	ctx.lr = 0x820CE97C;
	sub_820CCC30(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820ce998
	if (ctx.cr0.eq) goto loc_820CE998;
	// addi r5,r27,36
	ctx.r5.s64 = ctx.r27.s64 + 36;
	// li r6,12
	ctx.r6.s64 = 12;
	// li r4,244
	ctx.r4.s64 = 244;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ccca8
	ctx.lr = 0x820CE998;
	sub_820CCCA8(ctx, base);
loc_820CE998:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,9
	ctx.r5.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ccc30
	ctx.lr = 0x820CE9AC;
	sub_820CCC30(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r10,56(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x820ce9c8
	if (!ctx.cr6.gt) goto loc_820CE9C8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c7228
	ctx.lr = 0x820CE9C4;
	sub_820C7228(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_820CE9C8:
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r9,5888
	ctx.r9.s64 = 385875968;
	// ori r10,r10,8576
	ctx.r10.u64 = ctx.r10.u64 | 8576;
	// ori r9,r9,16
	ctx.r9.u64 = ctx.r9.u64 | 16;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// bl 0x820ccf50
	ctx.lr = 0x820CE9F4;
	sub_820CCF50(ctx, base);
	// addi r5,r26,28
	ctx.r5.s64 = ctx.r26.s64 + 28;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ccd80
	ctx.lr = 0x820CEA04;
	sub_820CCD80(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cce48
	ctx.lr = 0x820CEA0C;
	sub_820CCE48(ctx, base);
	// lwz r22,636(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 636);
	// lwz r11,628(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 628);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// lfs f9,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// addi r8,r1,164
	ctx.r8.s64 = ctx.r1.s64 + 164;
	// lfs f4,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// std r9,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r9.u64);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lfs f6,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lfs f12,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// fdivs f1,f9,f12
	ctx.f1.f64 = double(float(ctx.f9.f64 / ctx.f12.f64));
	// lfs f13,14368(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14368);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fmuls f5,f6,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// fmuls f3,f12,f13
	ctx.f3.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lfs f11,14356(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 14356);
	ctx.f11.f64 = double(temp.f32);
	// lfs f8,9724(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 9724);
	ctx.f8.f64 = double(temp.f32);
	// fdivs f2,f4,f6
	ctx.f2.f64 = double(float(ctx.f4.f64 / ctx.f6.f64));
	// lfs f12,14396(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 14396);
	ctx.f12.f64 = double(temp.f32);
	// lfs f30,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// lfs f29,4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f29.f64 = double(temp.f32);
	// lfs f28,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f28.f64 = double(temp.f32);
	// lfd f0,128(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f10,f0
	ctx.f10.f64 = double(ctx.f0.s64);
	// lfs f0,9536(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stw r30,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r30.u32);
	// stw r30,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r30.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r30,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r30.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f0,284(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// lfs f9,4860(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4860);
	ctx.f9.f64 = double(temp.f32);
	// frsp f31,f10
	ctx.f31.f64 = double(float(ctx.f10.f64));
	// lfs f10,9684(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9684);
	ctx.f10.f64 = double(temp.f32);
	// lfs f7,14388(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 14388);
	ctx.f7.f64 = double(temp.f32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lfs f0,14392(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14392);
	ctx.f0.f64 = double(temp.f32);
	// stfs f6,208(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// fdivs f6,f4,f5
	ctx.f6.f64 = double(float(ctx.f4.f64 / ctx.f5.f64));
	// stfs f10,200(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f9,204(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f13,224(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f13,228(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f11,232(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f11,236(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f8,272(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// stfs f12,276(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// stfs f30,192(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f29,196(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f28,212(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f7,280(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// stfs f12,288(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// stfs f0,292(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// lfs f0,9540(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fdivs f4,f0,f31
	ctx.f4.f64 = double(float(ctx.f0.f64 / ctx.f31.f64));
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fsubs f2,f2,f0
	ctx.f2.f64 = double(float(ctx.f2.f64 - ctx.f0.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fsubs f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 - ctx.f0.f64));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// fdivs f30,f0,f6
	ctx.f30.f64 = double(float(ctx.f0.f64 / ctx.f6.f64));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f10,14384(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14384);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r1,320
	ctx.r11.s64 = ctx.r1.s64 + 320;
	// lfs f9,9924(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9924);
	ctx.f9.f64 = double(temp.f32);
	// lfs f11,14380(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14380);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f31,f10
	ctx.f10.f64 = double(float(ctx.f31.f64 * ctx.f10.f64));
	// lfs f13,4852(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4852);
	ctx.f13.f64 = double(temp.f32);
	// li r6,8
	ctx.r6.s64 = 8;
	// lfs f8,14376(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 14376);
	ctx.f8.f64 = double(temp.f32);
	// li r4,4
	ctx.r4.s64 = 4;
	// lfs f7,14372(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 14372);
	ctx.f7.f64 = double(temp.f32);
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// fmuls f9,f4,f9
	ctx.f9.f64 = double(float(ctx.f4.f64 * ctx.f9.f64));
	// stfs f11,296(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// stfs f5,240(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// fadds f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 + ctx.f0.f64));
	// stfs f13,300(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f3,244(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f31,256(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
	// stfs f10,268(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f6,248(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f2,216(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f30,252(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f4,260(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f1,220(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f9,264(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// fctidz f11,f11
	ctx.f11.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfs f8,304(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfs f7,308(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// stfs f12,312(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// stfs f13,316(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// std r30,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r30.u64);
	// std r30,8(r11)
	REX_STORE_U64(ctx.r11.u32 + 8, ctx.r30.u64);
	// stfd f11,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.f11.u64);
	// std r30,16(r11)
	REX_STORE_U64(ctx.r11.u32 + 16, ctx.r30.u64);
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// std r30,24(r11)
	REX_STORE_U64(ctx.r11.u32 + 24, ctx.r30.u64);
	// lwz r11,132(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// lwz r10,140(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// mullw r28,r11,r10
	ctx.r28.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// bl 0x820ccca8
	ctx.lr = 0x820CEBE4;
	sub_820CCCA8(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x820cecd4
	if (ctx.cr6.eq) goto loc_820CECD4;
loc_820CEBF0:
	// lwz r10,0(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// addi r26,r11,1
	ctx.r26.s64 = ctx.r11.s64 + 1;
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// add r11,r10,r23
	ctx.r11.u64 = ctx.r10.u64 + ctx.r23.u64;
	// cmplw cr6,r26,r24
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r24.u32, ctx.xer);
	// beq cr6,0x820cec0c
	if (ctx.cr6.eq) goto loc_820CEC0C;
	// li r9,16384
	ctx.r9.s64 = 16384;
loc_820CEC0C:
	// subf r9,r11,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r11.u64;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r9,255
	ctx.r10.s64 = ctx.r9.s64 + 255;
	// rlwinm r10,r10,24,8,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// mulli r29,r10,42
	ctx.r29.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(42));
	// cmplw cr6,r28,r29
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r29.u32, ctx.xer);
	// bge cr6,0x820cec2c
	if (!ctx.cr6.lt) goto loc_820CEC2C;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
loc_820CEC2C:
	// clrldi r7,r27,32
	ctx.r7.u64 = ctx.r27.u64 & 0xFFFFFFFF;
	// lwz r8,168(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 168);
	// rlwinm r10,r11,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFF;
	// std r7,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r7.u64);
	// rlwinm r11,r11,0,3,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1FFFFFFC;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// rlwinm r9,r9,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// andi. r10,r8,49400
	ctx.r10.u64 = ctx.r8.u64 & 49400;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lfd f0,136(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// clrlwi r9,r9,9
	ctx.r9.u64 = ctx.r9.u32 & 0x7FFFFF;
	// oris r11,r11,16384
	ctx.r11.u64 = ctx.r11.u64 | 1073741824;
	// oris r10,r10,19200
	ctx.r10.u64 = ctx.r10.u64 | 1258291200;
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// lis r8,19200
	ctx.r8.s64 = 1258291200;
	// ori r10,r10,2561
	ctx.r10.u64 = ctx.r10.u64 | 2561;
	// oris r11,r9,19200
	ctx.r11.u64 = ctx.r9.u64 | 1258291200;
	// stw r8,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r8.u32);
	// stw r10,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r10.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r11,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r11.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// bl 0x820ccca8
	ctx.lr = 0x820CECA8;
	sub_820CCCA8(ctx, base);
	// mullw r5,r29,r22
	ctx.r5.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r22.s32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cceb0
	ctx.lr = 0x820CECB8;
	sub_820CCEB0(ctx, base);
	// subf r28,r29,r28
	ctx.r28.u64 = ctx.r28.u64 - ctx.r29.u64;
	// add r27,r29,r27
	ctx.r27.u64 = ctx.r29.u64 + ctx.r27.u64;
	// mr r23,r30
	ctx.r23.u64 = ctx.r30.u64;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// addi r25,r25,4
	ctx.r25.s64 = ctx.r25.s64 + 4;
	// cmplw cr6,r26,r24
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r24.u32, ctx.xer);
	// blt cr6,0x820cebf0
	if (ctx.cr6.lt) goto loc_820CEBF0;
loc_820CECD4:
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,352
	ctx.r5.s64 = ctx.r1.s64 + 352;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c87e0
	ctx.lr = 0x820CECE8;
	sub_820C87E0(ctx, base);
	// li r6,64
	ctx.r6.s64 = 64;
	// li r5,64
	ctx.r5.s64 = 64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c0248
	ctx.lr = 0x820CECFC;
	sub_820C0248(ctx, base);
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// addi r12,r1,-96
	ctx.r12.s64 = ctx.r1.s64 + -96;
	// bl 0x8212a8a4
	ctx.lr = 0x820CED08;
	__restfpr_28(ctx, base);
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
