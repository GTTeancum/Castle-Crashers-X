DEFINE_REX_FUNC(sub_821480B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e4
	ctx.lr = 0x821480C0;
	__savegprlr_15(ctx, base);
	// addi r12,r1,-144
	ctx.r12.s64 = ctx.r1.s64 + -144;
	// bl 0x8212a850
	ctx.lr = 0x821480C8;
	__savefpr_26(ctx, base);
	// stwu r1,-624(r1)
	ea = -624 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r17,r4
	ctx.r17.u64 = ctx.r4.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// mr r18,r3
	ctx.r18.u64 = ctx.r3.u64;
	// fmr f27,f2
	ctx.f27.f64 = ctx.f2.f64;
	// mr r16,r5
	ctx.r16.u64 = ctx.r5.u64;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r5,r17
	ctx.r5.u64 = ctx.r17.u64;
	// mr r15,r6
	ctx.r15.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// bl 0x82145480
	ctx.lr = 0x821480F8;
	sub_82145480(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r31,0
	ctx.r31.s64 = 0;
	// lfs f0,-4808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4808);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// lfs f0,9700(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9700);
	ctx.f0.f64 = double(temp.f32);
	// addi r19,r11,-5384
	ctx.r19.s64 = ctx.r11.s64 + -5384;
	// fdivs f26,f0,f13
	ctx.f26.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
loc_8214811C:
	// mr r7,r17
	ctx.r7.u64 = ctx.r17.u64;
	// lfsx f1,r31,r19
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r19.u32);
	ctx.f1.f64 = double(temp.f32);
	// mr r6,r18
	ctx.r6.u64 = ctx.r18.u64;
	// fmr f2,f26
	ctx.f2.f64 = ctx.f26.f64;
	// mr r5,r15
	ctx.r5.u64 = ctx.r15.u64;
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// bl 0x82149628
	ctx.lr = 0x82148138;
	sub_82149628(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfsx f1,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// cmpwi cr6,r31,296
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 296, ctx.xer);
	// blt cr6,0x8214811c
	if (ctx.cr6.lt) goto loc_8214811C;
	// addi r11,r1,132
	ctx.r11.s64 = ctx.r1.s64 + 132;
	// li r10,37
	ctx.r10.s64 = 37;
loc_82148154:
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// bne 0x82148154
	if (!ctx.cr0.eq) goto loc_82148154;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,0(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r11,0
	ctx.r11.s64 = 0;
	// lfs f0,14680(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14680);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// lfs f13,3312(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3312);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f31,f13
	ctx.f11.f64 = double(float(ctx.f31.f64 * ctx.f13.f64));
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bge cr6,0x821481a8
	if (!ctx.cr6.lt) goto loc_821481A8;
	// mr r10,r19
	ctx.r10.u64 = ctx.r19.u64;
loc_82148194:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82148194
	if (ctx.cr6.lt) goto loc_82148194;
loc_821481A8:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// mr r21,r11
	ctx.r21.u64 = ctx.r11.u64;
	// lfsx f0,r10,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	ctx.f0.f64 = double(temp.f32);
loc_821481B8:
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfsx f13,r10,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x821481d0
	if (!ctx.cr6.lt) goto loc_821481D0;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// mr r21,r11
	ctx.r21.u64 = ctx.r11.u64;
loc_821481D0:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r10,296
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 296, ctx.xer);
	// bge cr6,0x821481ec
	if (!ctx.cr6.lt) goto loc_821481EC;
	// lfsx f13,r10,r19
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r19.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	ctx.cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// ble cr6,0x821481b8
	if (!ctx.cr6.gt) goto loc_821481B8;
loc_821481EC:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fcmpu cr6,f27,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f27.f64, ctx.f0.f64);
	// lfs f28,4852(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4852);
	ctx.f28.f64 = double(temp.f32);
	// ble cr6,0x82148204
	if (!ctx.cr6.gt) goto loc_82148204;
	// fadds f0,f0,f27
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f27.f64));
	// fmuls f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
loc_82148204:
	// rlwinm r30,r21,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r1,128
	ctx.r31.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfsx f31,r30,r31
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r31.u32);
	ctx.f31.f64 = double(temp.f32);
	// stfsx f0,r30,r31
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r31.u32, temp.u32);
	// bl 0x82147e50
	ctx.lr = 0x82148224;
	sub_82147E50(ctx, base);
	// stw r3,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82147f78
	ctx.lr = 0x8214823C;
	sub_82147F78(ctx, base);
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r20,r7
	ctx.r20.u64 = ctx.r7.u64;
	// mr r23,r11
	ctx.r23.u64 = ctx.r11.u64;
	// ble cr6,0x82148288
	if (!ctx.cr6.gt) goto loc_82148288;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
loc_82148260:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r21,r8
	ctx.cr6.compare<int32_t>(ctx.r21.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x82148274
	if (!ctx.cr6.eq) goto loc_82148274;
	// li r6,1
	ctx.r6.s64 = 1;
	// cmpw cr6,r21,r8
	ctx.cr6.compare<int32_t>(ctx.r21.s32, ctx.r8.s32, ctx.xer);
loc_82148274:
	// bgt cr6,0x82148288
	if (ctx.cr6.gt) goto loc_82148288;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82148260
	if (ctx.cr6.lt) goto loc_82148260;
loc_82148288:
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne cr6,0x82148340
	if (!ctx.cr6.eq) goto loc_82148340;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r30,r31
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r31.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// lwzx r9,r9,r8
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,9668(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 9668);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r9,r6
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// bne cr6,0x821482e4
	if (!ctx.cr6.eq) goto loc_821482E4;
	// lwz r9,96(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f12,3324(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 3324);
	ctx.f12.f64 = double(temp.f32);
	// lfsx f11,r9,r8
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f12,f11,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x821482f4
	if (!ctx.cr6.lt) goto loc_821482F4;
loc_821482E4:
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// ble cr6,0x82148340
	if (!ctx.cr6.gt) goto loc_82148340;
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82148340
	if (ctx.cr6.lt) goto loc_82148340;
loc_821482F4:
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x82148324
	if (!ctx.cr6.gt) goto loc_82148324;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// subf r8,r10,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r10.u64;
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
loc_8214830C:
	// lwz r6,-4(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + -4);
	// addi r7,r9,-4
	ctx.r7.s64 = ctx.r9.s64 + -4;
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r6,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// bne 0x8214830c
	if (!ctx.cr0.eq) goto loc_8214830C;
loc_82148324:
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stwx r21,r9,r8
	REX_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r21.u32);
	// blt cr6,0x8214833c
	if (ctx.cr6.lt) goto loc_8214833C;
	// mr r20,r10
	ctx.r20.u64 = ctx.r10.u64;
loc_8214833C:
	// addi r23,r11,1
	ctx.r23.s64 = ctx.r11.s64 + 1;
loc_82148340:
	// stfsx f31,r30,r31
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r31.u32, temp.u32);
	// li r25,0
	ctx.r25.s64 = 0;
	// addi r22,r23,-1
	ctx.r22.s64 = ctx.r23.s64 + -1;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// ble cr6,0x82148470
	if (!ctx.cr6.gt) goto loc_82148470;
	// addi r27,r1,96
	ctx.r27.s64 = ctx.r1.s64 + 96;
	// subf r24,r26,r29
	ctx.r24.u64 = ctx.r29.u64 - ctx.r26.u64;
loc_82148360:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x82148378
	if (ctx.cr6.eq) goto loc_82148378;
	// cmpw cr6,r28,r22
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r22.s32, ctx.xer);
	// beq cr6,0x82148378
	if (ctx.cr6.eq) goto loc_82148378;
	// cmpw cr6,r28,r20
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r20.s32, ctx.xer);
	// bne cr6,0x82148460
	if (!ctx.cr6.eq) goto loc_82148460;
loc_82148378:
	// cmpw cr6,r28,r20
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r20.s32, ctx.xer);
	// bne cr6,0x82148388
	if (!ctx.cr6.eq) goto loc_82148388;
	// lwz r11,708(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 708);
	// stw r25,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r25.u32);
loc_82148388:
	// lwz r30,0(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// li r11,0
	ctx.r11.s64 = 0;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// add r9,r10,r19
	ctx.r9.u64 = ctx.r10.u64 + ctx.r19.u64;
	// lfsx f31,r10,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	ctx.f31.f64 = double(temp.f32);
	// lfsx f29,r10,r19
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r19.u32);
	ctx.f29.f64 = double(temp.f32);
	// ble cr6,0x821483c0
	if (!ctx.cr6.gt) goto loc_821483C0;
	// lfs f0,-4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// fadds f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// fmuls f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_821483C0:
	// addi r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r10,74
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 74, ctx.xer);
	// bge cr6,0x821483ec
	if (!ctx.cr6.lt) goto loc_821483EC;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lfsx f0,r10,r19
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r19.u32);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// fmuls f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
	// stfsx f0,r9,r8
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + ctx.r8.u32, temp.u32);
loc_821483EC:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82148438
	if (!ctx.cr6.gt) goto loc_82148438;
	// addi r31,r1,80
	ctx.r31.s64 = ctx.r1.s64 + 80;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
loc_821483FC:
	// lfs f30,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// mr r7,r17
	ctx.r7.u64 = ctx.r17.u64;
	// mr r6,r18
	ctx.r6.u64 = ctx.r18.u64;
	// fmr f2,f26
	ctx.f2.f64 = ctx.f26.f64;
	// mr r5,r15
	ctx.r5.u64 = ctx.r15.u64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// bl 0x82149628
	ctx.lr = 0x8214841C;
	sub_82149628(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// ble cr6,0x8214842c
	if (!ctx.cr6.gt) goto loc_8214842C;
	// fmr f29,f30
	ctx.f29.f64 = ctx.f30.f64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
loc_8214842C:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x821483fc
	if (!ctx.cr0.eq) goto loc_821483FC;
loc_82148438:
	// stfsx f29,r24,r26
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r24.u32 + ctx.r26.u32, temp.u32);
	// cmpw cr6,r30,r21
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r21.s32, ctx.xer);
	// bne cr6,0x82148454
	if (!ctx.cr6.eq) goto loc_82148454;
	// fcmpu cr6,f27,f31
	ctx.cr6.compare(ctx.f27.f64, ctx.f31.f64);
	// ble cr6,0x82148454
	if (!ctx.cr6.gt) goto loc_82148454;
	// fadds f0,f31,f27
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f27.f64));
	// fmuls f31,f0,f28
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
loc_82148454:
	// stfs f31,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
loc_82148460:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// cmpw cr6,r28,r23
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r23.s32, ctx.xer);
	// blt cr6,0x82148360
	if (ctx.cr6.lt) goto loc_82148360;
loc_82148470:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,624
	ctx.r1.s64 = ctx.r1.s64 + 624;
	// addi r12,r1,-144
	ctx.r12.s64 = ctx.r1.s64 + -144;
	// bl 0x8212a89c
	ctx.lr = 0x82148480;
	__restfpr_26(ctx, base);
	// b 0x82129934
	__restgprlr_15(ctx, base);
	return;
}
