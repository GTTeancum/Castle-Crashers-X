DEFINE_REX_FUNC(sub_820DEA50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e0
	ctx.lr = 0x820DEA58;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8212a820
	ctx.lr = 0x820DEA60;
	__savefpr_14(ctx, base);
	// ld r12,-4096(r1)
	ctx.r12.u64 = REX_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	ctx.r12.u64 = REX_LOAD_U64(ctx.r1.u32 + -8192);
	// ld r12,-12288(r1)
	ctx.r12.u64 = REX_LOAD_U64(ctx.r1.u32 + -12288);
	// ld r12,-16384(r1)
	ctx.r12.u64 = REX_LOAD_U64(ctx.r1.u32 + -16384);
	// stwu r1,-17968(r1)
	ea = -17968 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r30,17988(r1)
	REX_STORE_U32(ctx.r1.u32 + 17988, ctx.r30.u32);
	// lwz r11,100(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x820deaa8
	if (ctx.cr6.eq) goto loc_820DEAA8;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x820deaa0
	if (ctx.cr6.eq) goto loc_820DEAA0;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r29,4(r4)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// b 0x820deab4
	goto loc_820DEAB4;
loc_820DEAA0:
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// b 0x820deaac
	goto loc_820DEAAC;
loc_820DEAA8:
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
loc_820DEAAC:
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
loc_820DEAB4:
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r9,4(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// lwz r8,12(r5)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + 12);
	// lwz r7,16(r5)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r5.u32 + 16);
	// stw r29,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r29.u32);
	// stw r10,332(r1)
	REX_STORE_U32(ctx.r1.u32 + 332, ctx.r10.u32);
	// stw r9,324(r1)
	REX_STORE_U32(ctx.r1.u32 + 324, ctx.r9.u32);
	// stw r8,316(r1)
	REX_STORE_U32(ctx.r1.u32 + 316, ctx.r8.u32);
	// stw r7,308(r1)
	REX_STORE_U32(ctx.r1.u32 + 308, ctx.r7.u32);
	// dcbt r0,r11
	// dcbt r0,r29
	// li r6,128
	ctx.r6.s64 = 128;
	// dcbt r6,r11
	// li r5,128
	ctx.r5.s64 = 128;
	// dcbt r5,r29
	// addi r5,r1,7744
	ctx.r5.s64 = ctx.r1.s64 + 7744;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// addi r3,r30,104
	ctx.r3.s64 = ctx.r30.s64 + 104;
	// bl 0x820dd4a8
	ctx.lr = 0x820DEB00;
	sub_820DD4A8(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = ctx.r30.s64 + 131072;
	// li r6,256
	ctx.r6.s64 = 256;
	// addi r5,r1,9920
	ctx.r5.s64 = ctx.r1.s64 + 9920;
	// addi r4,r1,7744
	ctx.r4.s64 = ctx.r1.s64 + 7744;
	// addi r3,r3,168
	ctx.r3.s64 = ctx.r3.s64 + 168;
	// bl 0x820ddaf8
	ctx.lr = 0x820DEB18;
	sub_820DDAF8(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = ctx.r30.s64 + 131072;
	// li r7,256
	ctx.r7.s64 = 256;
	// addi r6,r1,6704
	ctx.r6.s64 = ctx.r1.s64 + 6704;
	// addi r5,r1,480
	ctx.r5.s64 = ctx.r1.s64 + 480;
	// addi r4,r1,9920
	ctx.r4.s64 = ctx.r1.s64 + 9920;
	// addi r3,r3,240
	ctx.r3.s64 = ctx.r3.s64 + 240;
	// bl 0x820ddc08
	ctx.lr = 0x820DEB34;
	sub_820DDC08(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = ctx.r30.s64 + 131072;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// addi r3,r3,2332
	ctx.r3.s64 = ctx.r3.s64 + 2332;
	// bl 0x820ddcd0
	ctx.lr = 0x820DEB44;
	sub_820DDCD0(ctx, base);
	// addi r4,r1,16639
	ctx.r4.s64 = ctx.r1.s64 + 16639;
	// addis r3,r30,2
	ctx.r3.s64 = ctx.r30.s64 + 131072;
	// rlwinm r31,r4,0,0,24
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFF80;
	// li r7,256
	ctx.r7.s64 = 256;
	// addi r6,r1,12096
	ctx.r6.s64 = ctx.r1.s64 + 12096;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// addi r3,r3,2868
	ctx.r3.s64 = ctx.r3.s64 + 2868;
	// bl 0x820ddf78
	ctx.lr = 0x820DEB68;
	sub_820DDF78(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = ctx.r30.s64 + 131072;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r3,11104
	ctx.r3.s64 = ctx.r3.s64 + 11104;
	// bl 0x820de040
	ctx.lr = 0x820DEB78;
	sub_820DE040(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = ctx.r30.s64 + 131072;
	// addi r5,r1,4640
	ctx.r5.s64 = ctx.r1.s64 + 4640;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r3,12152
	ctx.r3.s64 = ctx.r3.s64 + 12152;
	// bl 0x820de330
	ctx.lr = 0x820DEB8C;
	sub_820DE330(ctx, base);
	// addi r3,r1,14303
	ctx.r3.s64 = ctx.r1.s64 + 14303;
	// addi r10,r1,15471
	ctx.r10.s64 = ctx.r1.s64 + 15471;
	// rlwinm r11,r3,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFF80;
	// addis r3,r30,2
	ctx.r3.s64 = ctx.r30.s64 + 131072;
	// rlwinm r5,r10,0,0,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// addi r6,r11,8
	ctx.r6.s64 = ctx.r11.s64 + 8;
	// addi r4,r1,4640
	ctx.r4.s64 = ctx.r1.s64 + 4640;
	// stw r5,232(r1)
	REX_STORE_U32(ctx.r1.u32 + 232, ctx.r5.u32);
	// addi r3,r3,14224
	ctx.r3.s64 = ctx.r3.s64 + 14224;
	// stw r6,220(r1)
	REX_STORE_U32(ctx.r1.u32 + 220, ctx.r6.u32);
	// bl 0x820de4a8
	ctx.lr = 0x820DEBB8;
	sub_820DE4A8(ctx, base);
	// addis r3,r30,1
	ctx.r3.s64 = ctx.r30.s64 + 65536;
	// addi r5,r1,7744
	ctx.r5.s64 = ctx.r1.s64 + 7744;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r3,136
	ctx.r3.s64 = ctx.r3.s64 + 136;
	// bl 0x820dd4a8
	ctx.lr = 0x820DEBCC;
	sub_820DD4A8(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = ctx.r30.s64 + 131072;
	// li r6,256
	ctx.r6.s64 = 256;
	// addi r5,r1,9920
	ctx.r5.s64 = ctx.r1.s64 + 9920;
	// addi r4,r1,7744
	ctx.r4.s64 = ctx.r1.s64 + 7744;
	// addi r3,r3,200
	ctx.r3.s64 = ctx.r3.s64 + 200;
	// bl 0x820ddaf8
	ctx.lr = 0x820DEBE4;
	sub_820DDAF8(ctx, base);
	// li r7,256
	ctx.r7.s64 = 256;
	// addi r6,r1,4640
	ctx.r6.s64 = ctx.r1.s64 + 4640;
	// addi r5,r1,2560
	ctx.r5.s64 = ctx.r1.s64 + 2560;
	// addi r4,r1,9920
	ctx.r4.s64 = ctx.r1.s64 + 9920;
	// addis r3,r30,2
	ctx.r3.s64 = ctx.r30.s64 + 131072;
	// addi r3,r3,18360
	ctx.r3.s64 = ctx.r3.s64 + 18360;
	// bl 0x820ddc08
	ctx.lr = 0x820DEC00;
	sub_820DDC08(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = ctx.r30.s64 + 131072;
	// addi r4,r1,2560
	ctx.r4.s64 = ctx.r1.s64 + 2560;
	// addi r3,r3,20452
	ctx.r3.s64 = ctx.r3.s64 + 20452;
	// bl 0x820ddcd0
	ctx.lr = 0x820DEC10;
	sub_820DDCD0(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = ctx.r30.s64 + 131072;
	// li r7,256
	ctx.r7.s64 = 256;
	// addi r6,r1,13136
	ctx.r6.s64 = ctx.r1.s64 + 13136;
	// addi r5,r1,1520
	ctx.r5.s64 = ctx.r1.s64 + 1520;
	// addi r4,r1,2560
	ctx.r4.s64 = ctx.r1.s64 + 2560;
	// addi r3,r3,20988
	ctx.r3.s64 = ctx.r3.s64 + 20988;
	// bl 0x820ddf78
	ctx.lr = 0x820DEC2C;
	sub_820DDF78(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = ctx.r30.s64 + 131072;
	// addi r4,r1,1520
	ctx.r4.s64 = ctx.r1.s64 + 1520;
	// addi r3,r3,29224
	ctx.r3.s64 = ctx.r3.s64 + 29224;
	// bl 0x820de040
	ctx.lr = 0x820DEC3C;
	sub_820DE040(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = ctx.r30.s64 + 131072;
	// addi r5,r1,3600
	ctx.r5.s64 = ctx.r1.s64 + 3600;
	// addi r4,r1,1520
	ctx.r4.s64 = ctx.r1.s64 + 1520;
	// addi r3,r3,30272
	ctx.r3.s64 = ctx.r3.s64 + 30272;
	// bl 0x820de330
	ctx.lr = 0x820DEC50;
	sub_820DE330(ctx, base);
	// addi r9,r1,7871
	ctx.r9.s64 = ctx.r1.s64 + 7871;
	// addi r8,r1,10047
	ctx.r8.s64 = ctx.r1.s64 + 10047;
	// rlwinm r11,r9,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	// addis r3,r30,2
	ctx.r3.s64 = ctx.r30.s64 + 131072;
	// rlwinm r5,r8,0,0,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// addi r6,r11,8
	ctx.r6.s64 = ctx.r11.s64 + 8;
	// addi r4,r1,3600
	ctx.r4.s64 = ctx.r1.s64 + 3600;
	// stw r5,224(r1)
	REX_STORE_U32(ctx.r1.u32 + 224, ctx.r5.u32);
	// addi r3,r3,32344
	ctx.r3.s64 = ctx.r3.s64 + 32344;
	// stw r6,228(r1)
	REX_STORE_U32(ctx.r1.u32 + 228, ctx.r6.u32);
	// stw r5,216(r1)
	REX_STORE_U32(ctx.r1.u32 + 216, ctx.r5.u32);
	// bl 0x820de4a8
	ctx.lr = 0x820DEC80;
	sub_820DE4A8(ctx, base);
	// lis r7,2
	ctx.r7.s64 = 131072;
	// lis r6,2
	ctx.r6.s64 = 131072;
	// lfs f0,96(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lis r5,2
	ctx.r5.s64 = 131072;
	// lis r4,2
	ctx.r4.s64 = 131072;
	// ori r3,r7,18352
	ctx.r3.u64 = ctx.r7.u64 | 18352;
	// ori r11,r6,236
	ctx.r11.u64 = ctx.r6.u64 | 236;
	// ori r10,r5,18356
	ctx.r10.u64 = ctx.r5.u64 | 18356;
	// ori r9,r4,232
	ctx.r9.u64 = ctx.r4.u64 | 232;
	// addi r8,r1,2560
	ctx.r8.s64 = ctx.r1.s64 + 2560;
	// lfsx f13,r30,r3
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r3.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,6704
	ctx.r7.s64 = ctx.r1.s64 + 6704;
	// lfsx f12,r30,r11
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// addi r6,r1,1520
	ctx.r6.s64 = ctx.r1.s64 + 1520;
	// lfsx f11,r30,r10
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r10.u32);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r1,480
	ctx.r5.s64 = ctx.r1.s64 + 480;
	// lfsx f10,r30,r9
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r9.u32);
	ctx.f10.f64 = double(temp.f32);
	// addi r4,r1,4640
	ctx.r4.s64 = ctx.r1.s64 + 4640;
	// addi r3,r1,2564
	ctx.r3.s64 = ctx.r1.s64 + 2564;
	// addi r11,r1,6708
	ctx.r11.s64 = ctx.r1.s64 + 6708;
	// addi r10,r1,1524
	ctx.r10.s64 = ctx.r1.s64 + 1524;
	// addi r9,r1,484
	ctx.r9.s64 = ctx.r1.s64 + 484;
	// subf r8,r31,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r31.u64;
	// subf r7,r31,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r31.u64;
	// subf r6,r31,r6
	ctx.r6.u64 = ctx.r6.u64 - ctx.r31.u64;
	// stw r8,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r8.u32);
	// addi r30,r1,4644
	ctx.r30.s64 = ctx.r1.s64 + 4644;
	// stw r7,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// addi r29,r1,2568
	ctx.r29.s64 = ctx.r1.s64 + 2568;
	// stw r6,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r6.u32);
	// addi r28,r31,4
	ctx.r28.s64 = ctx.r31.s64 + 4;
	// subf r5,r31,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r31.u64;
	// subf r4,r31,r4
	ctx.r4.u64 = ctx.r4.u64 - ctx.r31.u64;
	// stw r28,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r28.u32);
	// subf r3,r31,r3
	ctx.r3.u64 = ctx.r3.u64 - ctx.r31.u64;
	// stw r5,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r5.u32);
	// subf r11,r31,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r31.u64;
	// stw r4,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r4.u32);
	// subf r10,r31,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r31.u64;
	// stw r3,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r3.u32);
	// subf r9,r31,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r31.u64;
	// stw r11,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r11.u32);
	// subf r8,r31,r30
	ctx.r8.u64 = ctx.r30.u64 - ctx.r31.u64;
	// stw r10,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// subf r7,r31,r29
	ctx.r7.u64 = ctx.r29.u64 - ctx.r31.u64;
	// stw r9,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r9.u32);
	// addi r6,r1,6712
	ctx.r6.s64 = ctx.r1.s64 + 6712;
	// stw r7,188(r1)
	REX_STORE_U32(ctx.r1.u32 + 188, ctx.r7.u32);
	// addi r7,r1,6720
	ctx.r7.s64 = ctx.r1.s64 + 6720;
	// addi r9,r1,1532
	ctx.r9.s64 = ctx.r1.s64 + 1532;
	// stw r8,200(r1)
	REX_STORE_U32(ctx.r1.u32 + 200, ctx.r8.u32);
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r30,r1,1536
	ctx.r30.s64 = ctx.r1.s64 + 1536;
	// lwz r29,80(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// subf r9,r31,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r31.u64;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// addi r7,r1,496
	ctx.r7.s64 = ctx.r1.s64 + 496;
	// addi r28,r1,4652
	ctx.r28.s64 = ctx.r1.s64 + 4652;
	// stw r9,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r9.u32);
	// addi r30,r1,2576
	ctx.r30.s64 = ctx.r1.s64 + 2576;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r8,r1,492
	ctx.r8.s64 = ctx.r1.s64 + 492;
	// lwz r27,84(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subf r9,r31,r28
	ctx.r9.u64 = ctx.r28.u64 - ctx.r31.u64;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// subf r8,r31,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r31.u64;
	// rotlwi r30,r30,0
	ctx.r30.u64 = __builtin_rotateleft32(ctx.r30.u32, 0);
	// stw r9,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// addi r5,r1,1528
	ctx.r5.s64 = ctx.r1.s64 + 1528;
	// stw r8,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r8.u32);
	// subf r9,r31,r27
	ctx.r9.u64 = ctx.r27.u64 - ctx.r31.u64;
	// addi r4,r1,488
	ctx.r4.s64 = ctx.r1.s64 + 488;
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// addi r3,r1,4648
	ctx.r3.s64 = ctx.r1.s64 + 4648;
	// subf r8,r31,r30
	ctx.r8.u64 = ctx.r30.u64 - ctx.r31.u64;
	// addi r11,r1,2572
	ctx.r11.s64 = ctx.r1.s64 + 2572;
	// addi r10,r1,6716
	ctx.r10.s64 = ctx.r1.s64 + 6716;
	// stw r8,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r8.u32);
	// subf r6,r31,r6
	ctx.r6.u64 = ctx.r6.u64 - ctx.r31.u64;
	// subf r5,r31,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r31.u64;
	// subf r4,r31,r4
	ctx.r4.u64 = ctx.r4.u64 - ctx.r31.u64;
	// stw r6,204(r1)
	REX_STORE_U32(ctx.r1.u32 + 204, ctx.r6.u32);
	// subf r3,r31,r3
	ctx.r3.u64 = ctx.r3.u64 - ctx.r31.u64;
	// stw r5,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r5.u32);
	// subf r30,r31,r29
	ctx.r30.u64 = ctx.r29.u64 - ctx.r31.u64;
	// stw r4,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r4.u32);
	// subf r11,r31,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r31.u64;
	// stw r3,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r3.u32);
	// subf r10,r31,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r31.u64;
	// stw r30,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r30.u32);
	// addi r9,r1,3616
	ctx.r9.s64 = ctx.r1.s64 + 3616;
	// stw r11,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r11.u32);
	// rotlwi r7,r7,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r10,212(r1)
	REX_STORE_U32(ctx.r1.u32 + 212, ctx.r10.u32);
	// addi r8,r1,5696
	ctx.r8.s64 = ctx.r1.s64 + 5696;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r6,r1,4656
	ctx.r6.s64 = ctx.r1.s64 + 4656;
	// addi r5,r1,2580
	ctx.r5.s64 = ctx.r1.s64 + 2580;
	// stw r8,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// addi r4,r1,6724
	ctx.r4.s64 = ctx.r1.s64 + 6724;
	// addi r3,r1,1540
	ctx.r3.s64 = ctx.r1.s64 + 1540;
	// addi r11,r1,500
	ctx.r11.s64 = ctx.r1.s64 + 500;
	// addi r10,r1,4660
	ctx.r10.s64 = ctx.r1.s64 + 4660;
	// addi r30,r1,5700
	ctx.r30.s64 = ctx.r1.s64 + 5700;
	// subf r9,r31,r7
	ctx.r9.u64 = ctx.r7.u64 - ctx.r31.u64;
	// subf r8,r31,r6
	ctx.r8.u64 = ctx.r6.u64 - ctx.r31.u64;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// subf r7,r31,r5
	ctx.r7.u64 = ctx.r5.u64 - ctx.r31.u64;
	// subf r6,r31,r4
	ctx.r6.u64 = ctx.r4.u64 - ctx.r31.u64;
	// subf r5,r31,r3
	ctx.r5.u64 = ctx.r3.u64 - ctx.r31.u64;
	// addi r26,r1,2584
	ctx.r26.s64 = ctx.r1.s64 + 2584;
	// addi r25,r1,6728
	ctx.r25.s64 = ctx.r1.s64 + 6728;
	// addi r24,r1,1544
	ctx.r24.s64 = ctx.r1.s64 + 1544;
	// addi r23,r1,504
	ctx.r23.s64 = ctx.r1.s64 + 504;
	// addi r22,r1,4664
	ctx.r22.s64 = ctx.r1.s64 + 4664;
	// addi r21,r1,5680
	ctx.r21.s64 = ctx.r1.s64 + 5680;
	// addi r20,r1,3600
	ctx.r20.s64 = ctx.r1.s64 + 3600;
	// addi r19,r1,5684
	ctx.r19.s64 = ctx.r1.s64 + 5684;
	// addi r18,r1,3604
	ctx.r18.s64 = ctx.r1.s64 + 3604;
	// addi r17,r1,5688
	ctx.r17.s64 = ctx.r1.s64 + 5688;
	// addi r16,r1,3608
	ctx.r16.s64 = ctx.r1.s64 + 3608;
	// addi r15,r1,5692
	ctx.r15.s64 = ctx.r1.s64 + 5692;
	// addi r14,r1,3612
	ctx.r14.s64 = ctx.r1.s64 + 3612;
	// addi r29,r1,3620
	ctx.r29.s64 = ctx.r1.s64 + 3620;
	// addi r28,r1,5704
	ctx.r28.s64 = ctx.r1.s64 + 5704;
	// addi r27,r1,3624
	ctx.r27.s64 = ctx.r1.s64 + 3624;
	// subf r4,r31,r11
	ctx.r4.u64 = ctx.r11.u64 - ctx.r31.u64;
	// subf r3,r31,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r31.u64;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// subf r30,r31,r26
	ctx.r30.u64 = ctx.r26.u64 - ctx.r31.u64;
	// subf r26,r31,r22
	ctx.r26.u64 = ctx.r22.u64 - ctx.r31.u64;
	// stw r29,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// subf r10,r31,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r31.u64;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subf r22,r31,r18
	ctx.r22.u64 = ctx.r18.u64 - ctx.r31.u64;
	// stw r27,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// subf r11,r31,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r31.u64;
	// lwz r18,100(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// subf r29,r31,r25
	ctx.r29.u64 = ctx.r25.u64 - ctx.r31.u64;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// subf r25,r31,r21
	ctx.r25.u64 = ctx.r21.u64 - ctx.r31.u64;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// subf r27,r31,r23
	ctx.r27.u64 = ctx.r23.u64 - ctx.r31.u64;
	// stw r28,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r28.u32);
	// subf r28,r31,r24
	ctx.r28.u64 = ctx.r24.u64 - ctx.r31.u64;
	// lwz r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// subf r10,r31,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r31.u64;
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// subf r18,r31,r18
	ctx.r18.u64 = ctx.r18.u64 - ctx.r31.u64;
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// subf r11,r31,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r31.u64;
	// subf r21,r31,r17
	ctx.r21.u64 = ctx.r17.u64 - ctx.r31.u64;
	// stw r18,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r18.u32);
	// subf r24,r31,r20
	ctx.r24.u64 = ctx.r20.u64 - ctx.r31.u64;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// subf r23,r31,r19
	ctx.r23.u64 = ctx.r19.u64 - ctx.r31.u64;
	// lwz r11,156(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// subf r17,r31,r10
	ctx.r17.u64 = ctx.r10.u64 - ctx.r31.u64;
	// subf r20,r31,r16
	ctx.r20.u64 = ctx.r16.u64 - ctx.r31.u64;
	// subf r19,r31,r15
	ctx.r19.u64 = ctx.r15.u64 - ctx.r31.u64;
	// subf r18,r31,r14
	ctx.r18.u64 = ctx.r14.u64 - ctx.r31.u64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_820DEF0C:
	// lwz r31,136(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// addi r16,r1,1520
	ctx.r16.s64 = ctx.r1.s64 + 1520;
	// lwz r15,120(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lfs f9,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// lwz r14,128(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lfs f7,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f9,f12
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// fmuls f4,f8,f12
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// std r17,240(r1)
	REX_STORE_U64(ctx.r1.u32 + 240, ctx.r17.u64);
	// lfsx f3,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f2,f7,f12
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// lfsx f1,r15,r11
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + ctx.r11.u32);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f9,f3,f11
	ctx.f9.f64 = double(float(ctx.f3.f64 * ctx.f11.f64));
	// lfsx f8,r10,r16
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r16.u32);
	ctx.f8.f64 = double(temp.f32);
	// lwz r31,144(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// lwz r16,104(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// fmuls f7,f1,f11
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// lwz r15,116(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// fmuls f1,f8,f11
	ctx.f1.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// lwz r17,164(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// lfsx f3,r14,r11
	temp.u32 = REX_LOAD_U32(ctx.r14.u32 + ctx.r11.u32);
	ctx.f3.f64 = double(temp.f32);
	// std r19,264(r1)
	REX_STORE_U64(ctx.r1.u32 + 264, ctx.r19.u64);
	// fmuls f8,f3,f11
	ctx.f8.f64 = double(float(ctx.f3.f64 * ctx.f11.f64));
	// std r18,248(r1)
	REX_STORE_U64(ctx.r1.u32 + 248, ctx.r18.u64);
	// addi r18,r1,480
	ctx.r18.s64 = ctx.r1.s64 + 480;
	// lwz r19,208(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 208);
	// lfsx f31,r16,r11
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + ctx.r11.u32);
	ctx.f31.f64 = double(temp.f32);
	// lfsx f3,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f3.f64 = double(temp.f32);
	// lwz r31,172(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 172);
	// lfs f5,12(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f5.f64 = double(temp.f32);
	// lwz r16,184(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
	// lfsx f30,r15,r11
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + ctx.r11.u32);
	ctx.f30.f64 = double(temp.f32);
	// addi r14,r1,2560
	ctx.r14.s64 = ctx.r1.s64 + 2560;
	// lfsx f29,r17,r11
	temp.u32 = REX_LOAD_U32(ctx.r17.u32 + ctx.r11.u32);
	ctx.f29.f64 = double(temp.f32);
	// fmuls f5,f5,f12
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f12.f64));
	// fmadds f9,f30,f10,f9
	ctx.f9.f64 = double(float(std::fma(ctx.f30.f64, ctx.f10.f64, ctx.f9.f64)));
	// lfsx f30,r10,r18
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r18.u32);
	ctx.f30.f64 = double(temp.f32);
	// fmadds f4,f29,f13,f4
	ctx.f4.f64 = double(float(std::fma(ctx.f29.f64, ctx.f13.f64, ctx.f4.f64)));
	// lfsx f29,r19,r11
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + ctx.r11.u32);
	ctx.f29.f64 = double(temp.f32);
	// std r21,296(r1)
	REX_STORE_U64(ctx.r1.u32 + 296, ctx.r21.u64);
	// fmadds f3,f3,f13,f31
	ctx.f3.f64 = double(float(std::fma(ctx.f3.f64, ctx.f13.f64, ctx.f31.f64)));
	// lwz r21,188(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 188);
	// fmadds f1,f30,f10,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f30.f64, ctx.f10.f64, ctx.f1.f64)));
	// fmadds f7,f29,f10,f7
	ctx.f7.f64 = double(float(std::fma(ctx.f29.f64, ctx.f10.f64, ctx.f7.f64)));
	// lfsx f30,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f30.f64 = double(temp.f32);
	// lfsx f29,r16,r11
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + ctx.r11.u32);
	ctx.f29.f64 = double(temp.f32);
	// std r20,280(r1)
	REX_STORE_U64(ctx.r1.u32 + 280, ctx.r20.u64);
	// lfsx f31,r10,r14
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r14.u32);
	ctx.f31.f64 = double(temp.f32);
	// lwz r31,180(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r16,192(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 192);
	// addi r20,r1,6704
	ctx.r20.s64 = ctx.r1.s64 + 6704;
	// fmadds f6,f31,f13,f6
	ctx.f6.f64 = double(float(std::fma(ctx.f31.f64, ctx.f13.f64, ctx.f6.f64)));
	// lfsx f31,r21,r11
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + ctx.r11.u32);
	ctx.f31.f64 = double(temp.f32);
	// fmadds f2,f31,f13,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f31.f64, ctx.f13.f64, ctx.f2.f64)));
	// addi r14,r1,4640
	ctx.r14.s64 = ctx.r1.s64 + 4640;
	// fmadds f5,f29,f13,f5
	ctx.f5.f64 = double(float(std::fma(ctx.f29.f64, ctx.f13.f64, ctx.f5.f64)));
	// lwz r15,200(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 200);
	// lfsx f29,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f29.f64 = double(temp.f32);
	// lwz r21,204(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 204);
	// lfsx f31,r10,r20
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r20.u32);
	ctx.f31.f64 = double(temp.f32);
	// lwz r20,196(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 196);
	// lfsx f28,r16,r11
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + ctx.r11.u32);
	ctx.f28.f64 = double(temp.f32);
	// lwz r19,212(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 212);
	// lwz r31,168(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 168);
	// fmadds f8,f30,f10,f8
	ctx.f8.f64 = double(float(std::fma(ctx.f30.f64, ctx.f10.f64, ctx.f8.f64)));
	// lwz r16,176(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// lfs f30,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// lfsx f27,r10,r14
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r14.u32);
	ctx.f27.f64 = double(temp.f32);
	// fmadds f3,f12,f30,f3
	ctx.f3.f64 = double(float(std::fma(ctx.f12.f64, ctx.f30.f64, ctx.f3.f64)));
	// lfsx f26,r15,r11
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + ctx.r11.u32);
	ctx.f26.f64 = double(temp.f32);
	// fadds f9,f9,f29
	ctx.f9.f64 = double(float(ctx.f9.f64 + ctx.f29.f64));
	// fadds f6,f6,f31
	ctx.f6.f64 = double(float(ctx.f6.f64 + ctx.f31.f64));
	// lfsx f25,r21,r11
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + ctx.r11.u32);
	ctx.f25.f64 = double(temp.f32);
	// fadds f4,f4,f28
	ctx.f4.f64 = double(float(ctx.f4.f64 + ctx.f28.f64));
	// lfsx f30,r20,r11
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + ctx.r11.u32);
	ctx.f30.f64 = double(temp.f32);
	// lfsx f29,r19,r11
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + ctx.r11.u32);
	ctx.f29.f64 = double(temp.f32);
	// addi r15,r1,5680
	ctx.r15.s64 = ctx.r1.s64 + 5680;
	// lfsx f31,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f31.f64 = double(temp.f32);
	// fadds f1,f1,f27
	ctx.f1.f64 = double(float(ctx.f1.f64 + ctx.f27.f64));
	// lfsx f28,r16,r11
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + ctx.r11.u32);
	ctx.f28.f64 = double(temp.f32);
	// lwz r16,92(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// fadds f8,f8,f30
	ctx.f8.f64 = double(float(ctx.f8.f64 + ctx.f30.f64));
	// lfs f30,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f31,f31,f11
	ctx.f31.f64 = double(float(ctx.f31.f64 * ctx.f11.f64));
	// fmuls f30,f30,f12
	ctx.f30.f64 = double(float(ctx.f30.f64 * ctx.f12.f64));
	// lfsx f27,r5,r11
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	ctx.f27.f64 = double(temp.f32);
	// fadds f5,f5,f29
	ctx.f5.f64 = double(float(ctx.f5.f64 + ctx.f29.f64));
	// lfs f29,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f29.f64 = double(temp.f32);
	// fadds f7,f7,f26
	ctx.f7.f64 = double(float(ctx.f7.f64 + ctx.f26.f64));
	// lfs f26,24(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f26.f64 = double(temp.f32);
	// lfsx f24,r16,r11
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + ctx.r11.u32);
	ctx.f24.f64 = double(temp.f32);
	// lwz r16,132(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// fmuls f29,f29,f12
	ctx.f29.f64 = double(float(ctx.f29.f64 * ctx.f12.f64));
	// lwz r14,140(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// fmuls f27,f27,f11
	ctx.f27.f64 = double(float(ctx.f27.f64 * ctx.f11.f64));
	// lwz r21,148(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// fadds f2,f2,f25
	ctx.f2.f64 = double(float(ctx.f2.f64 + ctx.f25.f64));
	// lfsx f25,r28,r11
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	ctx.f25.f64 = double(temp.f32);
	// fmuls f26,f26,f12
	ctx.f26.f64 = double(float(ctx.f26.f64 * ctx.f12.f64));
	// lfsx f22,r7,r11
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	ctx.f22.f64 = double(temp.f32);
	// lfsx f19,r16,r11
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + ctx.r11.u32);
	ctx.f19.f64 = double(temp.f32);
	// fmuls f25,f25,f11
	ctx.f25.f64 = double(float(ctx.f25.f64 * ctx.f11.f64));
	// fmadds f31,f28,f10,f31
	ctx.f31.f64 = double(float(std::fma(ctx.f28.f64, ctx.f10.f64, ctx.f31.f64)));
	// lfsx f21,r4,r11
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + ctx.r11.u32);
	ctx.f21.f64 = double(temp.f32);
	// fmadds f30,f19,f13,f30
	ctx.f30.f64 = double(float(std::fma(ctx.f19.f64, ctx.f13.f64, ctx.f30.f64)));
	// lfsx f20,r30,r11
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	ctx.f20.f64 = double(temp.f32);
	// fmuls f24,f24,f11
	ctx.f24.f64 = double(float(ctx.f24.f64 * ctx.f11.f64));
	// lfsx f23,r9,r11
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	ctx.f23.f64 = double(temp.f32);
	// lwz r20,80(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lfsx f28,r27,r11
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	ctx.f28.f64 = double(temp.f32);
	// fmuls f6,f6,f0
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// stfsx f6,r10,r15
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r15.u32, temp.u32);
	// fmadds f29,f22,f13,f29
	ctx.f29.f64 = double(float(std::fma(ctx.f22.f64, ctx.f13.f64, ctx.f29.f64)));
	// lfsx f22,r14,r11
	temp.u32 = REX_LOAD_U32(ctx.r14.u32 + ctx.r11.u32);
	ctx.f22.f64 = double(temp.f32);
	// fmadds f27,f21,f10,f27
	ctx.f27.f64 = double(float(std::fma(ctx.f21.f64, ctx.f10.f64, ctx.f27.f64)));
	// lfsx f21,r21,r11
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + ctx.r11.u32);
	ctx.f21.f64 = double(temp.f32);
	// lwz r21,112(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// addi r31,r1,3600
	ctx.r31.s64 = ctx.r1.s64 + 3600;
	// fmadds f26,f20,f13,f26
	ctx.f26.f64 = double(float(std::fma(ctx.f20.f64, ctx.f13.f64, ctx.f26.f64)));
	// stw r20,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r20.u32);
	// fmadds f28,f28,f10,f25
	ctx.f28.f64 = double(float(std::fma(ctx.f28.f64, ctx.f10.f64, ctx.f25.f64)));
	// ld r20,280(r1)
	ctx.r20.u64 = REX_LOAD_U64(ctx.r1.u32 + 280);
	// fadds f31,f31,f22
	ctx.f31.f64 = double(float(ctx.f31.f64 + ctx.f22.f64));
	// ld r19,264(r1)
	ctx.r19.u64 = REX_LOAD_U64(ctx.r1.u32 + 264);
	// fadds f6,f30,f21
	ctx.f6.f64 = double(float(ctx.f30.f64 + ctx.f21.f64));
	// ld r18,248(r1)
	ctx.r18.u64 = REX_LOAD_U64(ctx.r1.u32 + 248);
	// fmadds f24,f23,f10,f24
	ctx.f24.f64 = double(float(std::fma(ctx.f23.f64, ctx.f10.f64, ctx.f24.f64)));
	// stw r21,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r21.u32);
	// ld r21,296(r1)
	ctx.r21.u64 = REX_LOAD_U64(ctx.r1.u32 + 296);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// lfsx f23,r6,r11
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	ctx.f23.f64 = double(temp.f32);
	// fmuls f3,f3,f0
	ctx.f3.f64 = double(float(ctx.f3.f64 * ctx.f0.f64));
	// stfsx f1,r10,r31
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r31.u32, temp.u32);
	// fmuls f1,f9,f0
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// lfsx f25,r3,r11
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	ctx.f25.f64 = double(temp.f32);
	// fmuls f9,f4,f0
	ctx.f9.f64 = double(float(ctx.f4.f64 * ctx.f0.f64));
	// lfsx f19,r29,r11
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	ctx.f19.f64 = double(temp.f32);
	// fadds f30,f29,f23
	ctx.f30.f64 = double(float(ctx.f29.f64 + ctx.f23.f64));
	// lfsx f20,r8,r11
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	ctx.f20.f64 = double(temp.f32);
	// fmuls f4,f2,f0
	ctx.f4.f64 = double(float(ctx.f2.f64 * ctx.f0.f64));
	// lfsx f18,r26,r11
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + ctx.r11.u32);
	ctx.f18.f64 = double(temp.f32);
	// fadds f29,f27,f25
	ctx.f29.f64 = double(float(ctx.f27.f64 + ctx.f25.f64));
	// stfsx f3,r25,r11
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r25.u32 + ctx.r11.u32, temp.u32);
	// fadds f27,f26,f19
	ctx.f27.f64 = double(float(ctx.f26.f64 + ctx.f19.f64));
	// stfsx f1,r24,r11
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r24.u32 + ctx.r11.u32, temp.u32);
	// fmuls f7,f7,f0
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// stfsx f9,r23,r11
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r23.u32 + ctx.r11.u32, temp.u32);
	// fmuls f3,f8,f0
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// fmuls f2,f5,f0
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// lwz r16,84(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// fmuls f1,f31,f0
	ctx.f1.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// lwz r14,100(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stfsx f7,r22,r11
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r22.u32 + ctx.r11.u32, temp.u32);
	// fadds f26,f24,f20
	ctx.f26.f64 = double(float(ctx.f24.f64 + ctx.f20.f64));
	// stfsx f4,r21,r11
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r21.u32 + ctx.r11.u32, temp.u32);
	// fadds f28,f28,f18
	ctx.f28.f64 = double(float(ctx.f28.f64 + ctx.f18.f64));
	// stfsx f3,r20,r11
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r20.u32 + ctx.r11.u32, temp.u32);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// stfsx f2,r19,r11
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r19.u32 + ctx.r11.u32, temp.u32);
	// fmuls f9,f6,f0
	ctx.f9.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// stfsx f1,r18,r11
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r18.u32 + ctx.r11.u32, temp.u32);
	// lwz r31,96(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// fmuls f8,f26,f0
	ctx.f8.f64 = double(float(ctx.f26.f64 * ctx.f0.f64));
	// fmuls f5,f27,f0
	ctx.f5.f64 = double(float(ctx.f27.f64 * ctx.f0.f64));
	// ld r17,240(r1)
	ctx.r17.u64 = REX_LOAD_U64(ctx.r1.u32 + 240);
	// fmuls f7,f30,f0
	ctx.f7.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// stfsx f7,r16,r11
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r16.u32 + ctx.r11.u32, temp.u32);
	// fmuls f6,f29,f0
	ctx.f6.f64 = double(float(ctx.f29.f64 * ctx.f0.f64));
	// stfsx f6,r14,r11
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r14.u32 + ctx.r11.u32, temp.u32);
	// fmuls f4,f28,f0
	ctx.f4.f64 = double(float(ctx.f28.f64 * ctx.f0.f64));
	// cmpwi cr6,r10,1024
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1024, ctx.xer);
	// stfsx f8,r31,r11
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// lwz r31,108(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// stfsx f9,r17,r11
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r17.u32 + ctx.r11.u32, temp.u32);
	// stfsx f5,r31,r11
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// lwz r31,88(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// stfsx f4,r31,r11
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// blt cr6,0x820def0c
	if (ctx.cr6.lt) goto loc_820DEF0C;
	// lwz r11,17988(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 17988);
	// lis r10,2
	ctx.r10.s64 = 131072;
	// lis r9,2
	ctx.r9.s64 = 131072;
	// addis r6,r11,3
	ctx.r6.s64 = ctx.r11.s64 + 196608;
	// ori r5,r10,38556
	ctx.r5.u64 = ctx.r10.u64 | 38556;
	// addi r6,r6,-26992
	ctx.r6.s64 = ctx.r6.s64 + -26992;
	// lis r8,2
	ctx.r8.s64 = 131072;
	// stw r5,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// lis r7,2
	ctx.r7.s64 = 131072;
	// stw r6,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// ori r4,r9,40624
	ctx.r4.u64 = ctx.r9.u64 | 40624;
	// ori r3,r8,40656
	ctx.r3.u64 = ctx.r8.u64 | 40656;
	// ori r9,r7,40676
	ctx.r9.u64 = ctx.r7.u64 | 40676;
	// stw r4,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r4.u32);
	// stw r3,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r3.u32);
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// stw r9,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// addis r10,r11,3
	ctx.r10.s64 = ctx.r11.s64 + 196608;
	// addis r8,r11,3
	ctx.r8.s64 = ctx.r11.s64 + 196608;
	// addi r10,r10,-29064
	ctx.r10.s64 = ctx.r10.s64 + -29064;
	// addis r5,r31,3
	ctx.r5.s64 = ctx.r31.s64 + 196608;
	// addi r8,r8,-24920
	ctx.r8.s64 = ctx.r8.s64 + -24920;
	// stw r10,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r10.u32);
	// addis r4,r31,3
	ctx.r4.s64 = ctx.r31.s64 + 196608;
	// addi r7,r10,16
	ctx.r7.s64 = ctx.r10.s64 + 16;
	// stw r8,328(r1)
	REX_STORE_U32(ctx.r1.u32 + 328, ctx.r8.u32);
	// addi r5,r5,-29052
	ctx.r5.s64 = ctx.r5.s64 + -29052;
	// addis r10,r31,3
	ctx.r10.s64 = ctx.r31.s64 + 196608;
	// stw r7,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// addi r4,r4,-24828
	ctx.r4.s64 = ctx.r4.s64 + -24828;
	// stw r5,204(r1)
	REX_STORE_U32(ctx.r1.u32 + 204, ctx.r5.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// addis r8,r31,3
	ctx.r8.s64 = ctx.r31.s64 + 196608;
	// stw r4,188(r1)
	REX_STORE_U32(ctx.r1.u32 + 188, ctx.r4.u32);
	// addi r10,r10,-8384
	ctx.r10.s64 = ctx.r10.s64 + -8384;
	// stw r6,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r6.u32);
	// addis r5,r31,3
	ctx.r5.s64 = ctx.r31.s64 + 196608;
	// addi r8,r8,-4244
	ctx.r8.s64 = ctx.r8.s64 + -4244;
	// stw r10,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r10.u32);
	// addis r3,r31,3
	ctx.r3.s64 = ctx.r31.s64 + 196608;
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// addis r11,r31,3
	ctx.r11.s64 = ctx.r31.s64 + 196608;
	// stw r8,340(r1)
	REX_STORE_U32(ctx.r1.u32 + 340, ctx.r8.u32);
	// addis r9,r31,3
	ctx.r9.s64 = ctx.r31.s64 + 196608;
	// lwz r8,88(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// addis r7,r31,3
	ctx.r7.s64 = ctx.r31.s64 + 196608;
	// addis r6,r31,3
	ctx.r6.s64 = ctx.r31.s64 + 196608;
	// addis r4,r31,3
	ctx.r4.s64 = ctx.r31.s64 + 196608;
	// addi r5,r5,-4160
	ctx.r5.s64 = ctx.r5.s64 + -4160;
	// addi r3,r3,-8412
	ctx.r3.s64 = ctx.r3.s64 + -8412;
	// addi r11,r11,-24816
	ctx.r11.s64 = ctx.r11.s64 + -24816;
	// stw r5,352(r1)
	REX_STORE_U32(ctx.r1.u32 + 352, ctx.r5.u32);
	// addi r9,r9,-6312
	ctx.r9.s64 = ctx.r9.s64 + -6312;
	// stw r3,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r3.u32);
	// addi r7,r7,-4212
	ctx.r7.s64 = ctx.r7.s64 + -4212;
	// stw r11,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r11.u32);
	// addi r6,r6,-4192
	ctx.r6.s64 = ctx.r6.s64 + -4192;
	// stw r9,304(r1)
	REX_STORE_U32(ctx.r1.u32 + 304, ctx.r9.u32);
	// addi r4,r4,12256
	ctx.r4.s64 = ctx.r4.s64 + 12256;
	// stw r7,344(r1)
	REX_STORE_U32(ctx.r1.u32 + 344, ctx.r7.u32);
	// addi r5,r10,16
	ctx.r5.s64 = ctx.r10.s64 + 16;
	// stw r6,256(r1)
	REX_STORE_U32(ctx.r1.u32 + 256, ctx.r6.u32);
	// add r10,r31,r8
	ctx.r10.u64 = ctx.r31.u64 + ctx.r8.u64;
	// stw r4,272(r1)
	REX_STORE_U32(ctx.r1.u32 + 272, ctx.r4.u32);
	// lwz r6,148(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// addis r3,r31,3
	ctx.r3.s64 = ctx.r31.s64 + 196608;
	// lwz r4,140(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// addis r11,r31,3
	ctx.r11.s64 = ctx.r31.s64 + 196608;
	// lwz r8,132(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// addis r9,r31,3
	ctx.r9.s64 = ctx.r31.s64 + 196608;
	// addis r7,r31,3
	ctx.r7.s64 = ctx.r31.s64 + 196608;
	// stw r5,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r3,r3,-4148
	ctx.r3.s64 = ctx.r3.s64 + -4148;
	// stw r10,200(r1)
	REX_STORE_U32(ctx.r1.u32 + 200, ctx.r10.u32);
	// addi r11,r11,12284
	ctx.r11.s64 = ctx.r11.s64 + 12284;
	// addi r9,r9,20504
	ctx.r9.s64 = ctx.r9.s64 + 20504;
	// addi r7,r7,28720
	ctx.r7.s64 = ctx.r7.s64 + 28720;
	// add r6,r31,r6
	ctx.r6.u64 = ctx.r31.u64 + ctx.r6.u64;
	// add r4,r31,r4
	ctx.r4.u64 = ctx.r31.u64 + ctx.r4.u64;
	// add r8,r31,r8
	ctx.r8.u64 = ctx.r31.u64 + ctx.r8.u64;
	// addis r5,r31,4
	ctx.r5.s64 = ctx.r31.s64 + 262144;
	// addis r28,r31,4
	ctx.r28.s64 = ctx.r31.s64 + 262144;
	// stw r6,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r6.u32);
	// stw r4,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r4.u32);
	// addis r10,r31,4
	ctx.r10.s64 = ctx.r31.s64 + 262144;
	// addi r28,r28,16616
	ctx.r28.s64 = ctx.r28.s64 + 16616;
	// stw r9,288(r1)
	REX_STORE_U32(ctx.r1.u32 + 288, ctx.r9.u32);
	// addis r6,r31,4
	ctx.r6.s64 = ctx.r31.s64 + 262144;
	// stw r3,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r3.u32);
	// addis r4,r31,4
	ctx.r4.s64 = ctx.r31.s64 + 262144;
	// stw r28,392(r1)
	REX_STORE_U32(ctx.r1.u32 + 392, ctx.r28.u32);
	// addis r9,r31,3
	ctx.r9.s64 = ctx.r31.s64 + 196608;
	// stw r7,368(r1)
	REX_STORE_U32(ctx.r1.u32 + 368, ctx.r7.u32);
	// addi r5,r5,-28600
	ctx.r5.s64 = ctx.r5.s64 + -28600;
	// lwz r24,216(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 216);
	// addi r9,r9,-6324
	ctx.r9.s64 = ctx.r9.s64 + -6324;
	// stw r8,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r8.u32);
	// addi r10,r10,-24484
	ctx.r10.s64 = ctx.r10.s64 + -24484;
	// stw r5,236(r1)
	REX_STORE_U32(ctx.r1.u32 + 236, ctx.r5.u32);
	// addi r6,r6,-8072
	ctx.r6.s64 = ctx.r6.s64 + -8072;
	// stw r9,416(r1)
	REX_STORE_U32(ctx.r1.u32 + 416, ctx.r9.u32);
	// addi r4,r4,-8036
	ctx.r4.s64 = ctx.r4.s64 + -8036;
	// stw r10,376(r1)
	REX_STORE_U32(ctx.r1.u32 + 376, ctx.r10.u32);
	// addis r30,r31,4
	ctx.r30.s64 = ctx.r31.s64 + 262144;
	// stw r6,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r6.u32);
	// addis r27,r31,4
	ctx.r27.s64 = ctx.r31.s64 + 262144;
	// stw r4,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r4.u32);
	// addis r26,r31,5
	ctx.r26.s64 = ctx.r31.s64 + 327680;
	// stw r11,360(r1)
	REX_STORE_U32(ctx.r1.u32 + 360, ctx.r11.u32);
	// addis r25,r31,4
	ctx.r25.s64 = ctx.r31.s64 + 262144;
	// lwz r11,232(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 232);
	// addis r23,r31,4
	ctx.r23.s64 = ctx.r31.s64 + 262144;
	// lwz r8,220(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 220);
	// addis r28,r31,3
	ctx.r28.s64 = ctx.r31.s64 + 196608;
	// lwz r29,228(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 228);
	// addi r30,r30,8400
	ctx.r30.s64 = ctx.r30.s64 + 8400;
	// addi r27,r27,20732
	ctx.r27.s64 = ctx.r27.s64 + 20732;
	// addi r26,r26,-28392
	ctx.r26.s64 = ctx.r26.s64 + -28392;
	// stw r30,312(r1)
	REX_STORE_U32(ctx.r1.u32 + 312, ctx.r30.u32);
	// addi r25,r25,20744
	ctx.r25.s64 = ctx.r25.s64 + 20744;
	// stw r27,320(r1)
	REX_STORE_U32(ctx.r1.u32 + 320, ctx.r27.u32);
	// addi r23,r23,-24472
	ctx.r23.s64 = ctx.r23.s64 + -24472;
	// stw r26,216(r1)
	REX_STORE_U32(ctx.r1.u32 + 216, ctx.r26.u32);
	// addi r28,r28,-8420
	ctx.r28.s64 = ctx.r28.s64 + -8420;
	// stw r25,212(r1)
	REX_STORE_U32(ctx.r1.u32 + 212, ctx.r25.u32);
	// addi r7,r9,16
	ctx.r7.s64 = ctx.r9.s64 + 16;
	// stw r23,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r23.u32);
	// addis r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 262144;
	// stw r28,408(r1)
	REX_STORE_U32(ctx.r1.u32 + 408, ctx.r28.u32);
	// addis r10,r31,3
	ctx.r10.s64 = ctx.r31.s64 + 196608;
	// addis r6,r31,3
	ctx.r6.s64 = ctx.r31.s64 + 196608;
	// addis r5,r31,3
	ctx.r5.s64 = ctx.r31.s64 + 196608;
	// addis r9,r31,3
	ctx.r9.s64 = ctx.r31.s64 + 196608;
	// addis r4,r31,4
	ctx.r4.s64 = ctx.r31.s64 + 262144;
	// addis r22,r31,3
	ctx.r22.s64 = ctx.r31.s64 + 196608;
	// addi r3,r3,184
	ctx.r3.s64 = ctx.r3.s64 + 184;
	// addi r10,r10,-8396
	ctx.r10.s64 = ctx.r10.s64 + -8396;
	// addi r6,r6,12272
	ctx.r6.s64 = ctx.r6.s64 + 12272;
	// stw r3,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r3.u32);
	// addi r5,r5,28708
	ctx.r5.s64 = ctx.r5.s64 + 28708;
	// lwz r3,224(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 224);
	// addi r9,r9,20488
	ctx.r9.s64 = ctx.r9.s64 + 20488;
	// stw r10,336(r1)
	REX_STORE_U32(ctx.r1.u32 + 336, ctx.r10.u32);
	// addi r4,r4,-28612
	ctx.r4.s64 = ctx.r4.s64 + -28612;
	// stw r6,420(r1)
	REX_STORE_U32(ctx.r1.u32 + 420, ctx.r6.u32);
	// addis r30,r31,3
	ctx.r30.s64 = ctx.r31.s64 + 196608;
	// stw r9,356(r1)
	REX_STORE_U32(ctx.r1.u32 + 356, ctx.r9.u32);
	// addi r22,r22,-4252
	ctx.r22.s64 = ctx.r22.s64 + -4252;
	// stw r5,396(r1)
	REX_STORE_U32(ctx.r1.u32 + 396, ctx.r5.u32);
	// addis r27,r31,3
	ctx.r27.s64 = ctx.r31.s64 + 196608;
	// stw r4,364(r1)
	REX_STORE_U32(ctx.r1.u32 + 364, ctx.r4.u32);
	// addis r26,r31,4
	ctx.r26.s64 = ctx.r31.s64 + 262144;
	// stw r22,424(r1)
	REX_STORE_U32(ctx.r1.u32 + 424, ctx.r22.u32);
	// addis r28,r31,4
	ctx.r28.s64 = ctx.r31.s64 + 262144;
	// addis r25,r31,4
	ctx.r25.s64 = ctx.r31.s64 + 262144;
	// addis r23,r31,4
	ctx.r23.s64 = ctx.r31.s64 + 262144;
	// addi r30,r30,-24836
	ctx.r30.s64 = ctx.r30.s64 + -24836;
	// addi r27,r27,-4168
	ctx.r27.s64 = ctx.r27.s64 + -4168;
	// addi r26,r26,-24492
	ctx.r26.s64 = ctx.r26.s64 + -24492;
	// addi r28,r28,168
	ctx.r28.s64 = ctx.r28.s64 + 168;
	// addi r25,r25,-8076
	ctx.r25.s64 = ctx.r25.s64 + -8076;
	// addi r23,r23,-8048
	ctx.r23.s64 = ctx.r23.s64 + -8048;
	// stw r28,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// addis r28,r31,4
	ctx.r28.s64 = ctx.r31.s64 + 262144;
	// stw r25,412(r1)
	REX_STORE_U32(ctx.r1.u32 + 412, ctx.r25.u32);
	// addis r25,r31,3
	ctx.r25.s64 = ctx.r31.s64 + 196608;
	// addi r28,r28,8388
	ctx.r28.s64 = ctx.r28.s64 + 8388;
	// stw r23,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r23.u32);
	// addi r25,r25,12248
	ctx.r25.s64 = ctx.r25.s64 + 12248;
	// lwz r18,156(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// stw r28,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// addis r28,r31,4
	ctx.r28.s64 = ctx.r31.s64 + 262144;
	// stw r25,348(r1)
	REX_STORE_U32(ctx.r1.u32 + 348, ctx.r25.u32);
	// addis r25,r31,5
	ctx.r25.s64 = ctx.r31.s64 + 327680;
	// addi r28,r28,20724
	ctx.r28.s64 = ctx.r28.s64 + 20724;
	// addi r25,r25,-28396
	ctx.r25.s64 = ctx.r25.s64 + -28396;
	// stw r28,264(r1)
	REX_STORE_U32(ctx.r1.u32 + 264, ctx.r28.u32);
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r25,280(r1)
	REX_STORE_U32(ctx.r1.u32 + 280, ctx.r25.u32);
	// addis r23,r31,4
	ctx.r23.s64 = ctx.r31.s64 + 262144;
	// stw r28,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// subf r28,r3,r8
	ctx.r28.u64 = ctx.r8.u64 - ctx.r3.u64;
	// subf r25,r3,r24
	ctx.r25.u64 = ctx.r24.u64 - ctx.r3.u64;
	// subf r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	// stw r28,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// subf r3,r3,r29
	ctx.r3.u64 = ctx.r29.u64 - ctx.r3.u64;
	// stw r25,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r25.u32);
	// addi r23,r23,16604
	ctx.r23.s64 = ctx.r23.s64 + 16604;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// stw r3,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r3.u32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// stw r23,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r23.u32);
	// lis r23,-32252
	ctx.r23.s64 = -2113667072;
	// li r20,256
	ctx.r20.s64 = 256;
	// addis r29,r31,3
	ctx.r29.s64 = ctx.r31.s64 + 196608;
	// addis r28,r31,3
	ctx.r28.s64 = ctx.r31.s64 + 196608;
	// stw r20,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r20.u32);
	// addis r22,r31,3
	ctx.r22.s64 = ctx.r31.s64 + 196608;
	// lfs f0,4848(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4848);
	ctx.f0.f64 = double(temp.f32);
	// addis r21,r31,3
	ctx.r21.s64 = ctx.r31.s64 + 196608;
	// lfs f13,9632(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 9632);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,88(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// addi r8,r10,16
	ctx.r8.s64 = ctx.r10.s64 + 16;
	// addi r25,r9,20
	ctx.r25.s64 = ctx.r9.s64 + 20;
	// lwz r23,92(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// stfs f0,400(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 400, temp.u32);
	// addi r29,r29,-24896
	ctx.r29.s64 = ctx.r29.s64 + -24896;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r28,r28,-4228
	ctx.r28.s64 = ctx.r28.s64 + -4228;
	// addi r22,r22,-24864
	ctx.r22.s64 = ctx.r22.s64 + -24864;
	// addi r21,r21,-4196
	ctx.r21.s64 = ctx.r21.s64 + -4196;
	// addi r11,r30,24
	ctx.r11.s64 = ctx.r30.s64 + 24;
	// addi r10,r27,24
	ctx.r10.s64 = ctx.r27.s64 + 24;
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// addi r5,r5,16
	ctx.r5.s64 = ctx.r5.s64 + 16;
	// addi r4,r4,16
	ctx.r4.s64 = ctx.r4.s64 + 16;
	// addi r9,r26,24
	ctx.r9.s64 = ctx.r26.s64 + 24;
	// b 0x820df548
	goto loc_820DF548;
loc_820DF544:
	// lwz r20,144(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
loc_820DF548:
	// lwz r19,116(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// clrlwi r19,r19,27
	ctx.r19.u64 = ctx.r19.u32 & 0x1F;
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// bne cr6,0x820df568
	if (!ctx.cr6.eq) goto loc_820DF568;
	// lwz r19,160(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// dcbt r20,r19
	// lwz r19,152(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// dcbt r20,r19
loc_820DF568:
	// lfs f0,8(r18)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r18.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lwz r19,0(r23)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// lwz r18,0(r18)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// addi r17,r1,5680
	ctx.r17.s64 = ctx.r1.s64 + 5680;
	// mr r20,r19
	ctx.r20.u64 = ctx.r19.u64;
	// std r31,384(r1)
	REX_STORE_U64(ctx.r1.u32 + 384, ctx.r31.u64);
	// subf r19,r18,r19
	ctx.r19.u64 = ctx.r19.u64 - ctx.r18.u64;
	// std r26,448(r1)
	REX_STORE_U64(ctx.r1.u32 + 448, ctx.r26.u64);
	// addi r15,r20,2
	ctx.r15.s64 = ctx.r20.s64 + 2;
	// lwz r14,216(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 216);
	// clrlwi r20,r19,23
	ctx.r20.u64 = ctx.r19.u32 & 0x1FF;
	// lwz r19,148(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r31,140(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// addi r16,r1,3600
	ctx.r16.s64 = ctx.r1.s64 + 3600;
	// addi r20,r20,2
	ctx.r20.s64 = ctx.r20.s64 + 2;
	// lwz r26,132(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// std r25,440(r1)
	REX_STORE_U64(ctx.r1.u32 + 440, ctx.r25.u64);
	// rlwinm r15,r15,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0xFFFFFFFC;
	// std r9,456(r1)
	REX_STORE_U64(ctx.r1.u32 + 456, ctx.r9.u64);
	// rlwinm r20,r20,2,0,29
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r18,100(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lfs f8,0(r14)
	temp.u32 = REX_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lwz r25,168(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 168);
	// lfs f7,0(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lwz r9,212(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 212);
	// lfs f6,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lfs f4,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// std r4,464(r1)
	REX_STORE_U64(ctx.r1.u32 + 464, ctx.r4.u64);
	// lfsx f3,r20,r23
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + ctx.r23.u32);
	ctx.f3.f64 = double(temp.f32);
	// lwz r14,196(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 196);
	// lfsx f13,r24,r18
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + ctx.r18.u32);
	ctx.f13.f64 = double(temp.f32);
	// lwz r19,204(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 204);
	// lwz r31,200(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 200);
	// lfs f11,0(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lwz r26,180(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lfs f1,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,184(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
	// fmadds f2,f0,f3,f13
	ctx.f2.f64 = double(float(std::fma(ctx.f0.f64, ctx.f3.f64, ctx.f13.f64)));
	// std r5,432(r1)
	REX_STORE_U64(ctx.r1.u32 + 432, ctx.r5.u64);
	// lfs f0,0(r14)
	temp.u32 = REX_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r18,176(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// lfs f31,0(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// lwz r20,192(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 192);
	// lfs f13,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r25,188(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 188);
	// lfs f29,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// lwz r9,208(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 208);
	// lfs f28,0(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f28.f64 = double(temp.f32);
	// lwz r5,164(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// lfs f12,0(r18)
	temp.u32 = REX_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lwz r14,304(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 304);
	// lwz r19,340(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 340);
	// lfs f30,0(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// lwz r31,344(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 344);
	// lfs f27,0(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f27.f64 = double(temp.f32);
	// lwz r26,352(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 352);
	// lfs f10,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lwz r4,272(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 272);
	// lfs f26,0(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f26.f64 = double(temp.f32);
	// lwz r18,172(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 172);
	// lfs f25,0(r14)
	temp.u32 = REX_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f25.f64 = double(temp.f32);
	// lwz r20,256(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 256);
	// lfs f24,0(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f24.f64 = double(temp.f32);
	// lwz r25,360(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 360);
	// add r18,r18,r24
	ctx.r18.u64 = ctx.r18.u64 + ctx.r24.u64;
	// lwz r9,288(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 288);
	// lfs f23,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f23.f64 = double(temp.f32);
	// lwz r5,368(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 368);
	// lfs f21,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f21.f64 = double(temp.f32);
	// lfs f9,0(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fadds f5,f2,f8
	ctx.f5.f64 = double(float(ctx.f2.f64 + ctx.f8.f64));
	// lwz r14,236(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 236);
	// lfs f22,0(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f22.f64 = double(temp.f32);
	// lwz r19,376(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 376);
	// lfs f20,0(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f20.f64 = double(temp.f32);
	// lwz r31,312(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 312);
	// lfs f19,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f19.f64 = double(temp.f32);
	// lfs f2,0(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// addi r26,r1,12096
	ctx.r26.s64 = ctx.r1.s64 + 12096;
	// addi r4,r1,13136
	ctx.r4.s64 = ctx.r1.s64 + 13136;
	// stw r18,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r18.u32);
	// lfs f18,0(r14)
	temp.u32 = REX_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f18.f64 = double(temp.f32);
	// lwz r18,156(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// lwz r20,392(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 392);
	// lfs f16,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f16.f64 = double(temp.f32);
	// lwz r14,320(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 320);
	// stfs f7,404(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 404, temp.u32);
	// stfs f16,240(r1)
	temp.f32 = float(ctx.f16.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// fadds f7,f5,f4
	ctx.f7.f64 = double(float(ctx.f5.f64 + ctx.f4.f64));
	// lfs f17,0(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f17.f64 = double(temp.f32);
	// fsubs f4,f8,f4
	ctx.f4.f64 = double(float(ctx.f8.f64 - ctx.f4.f64));
	// lfs f16,4(r18)
	temp.u32 = REX_LOAD_U32(ctx.r18.u32 + 4);
	ctx.f16.f64 = double(temp.f32);
	// lwz r19,104(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lfs f15,0(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f15.f64 = double(temp.f32);
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lfs f14,0(r14)
	temp.u32 = REX_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f14.f64 = double(temp.f32);
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stfsx f7,r15,r23
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r15.u32 + ctx.r23.u32, temp.u32);
	// lwz r20,0(r23)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// addi r15,r20,1
	ctx.r15.s64 = ctx.r20.s64 + 1;
	// lwz r20,136(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// lfsx f8,r20,r26
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + ctx.r26.u32);
	ctx.f8.f64 = double(temp.f32);
	// clrlwi r15,r15,23
	ctx.r15.u64 = ctx.r15.u32 & 0x1FF;
	// stfs f8,92(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fmadds f3,f16,f7,f3
	ctx.f3.f64 = double(float(std::fma(ctx.f16.f64, ctx.f7.f64, ctx.f3.f64)));
	// lfsx f8,r20,r4
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + ctx.r4.u32);
	ctx.f8.f64 = double(temp.f32);
	// lwz r20,108(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// stw r15,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r15.u32);
	// stfs f3,12(r18)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r18.u32 + 12, temp.u32);
	// lfsx f7,r19,r17
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + ctx.r17.u32);
	ctx.f7.f64 = double(temp.f32);
	// lwz r15,0(r3)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfsx f3,r19,r16
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + ctx.r16.u32);
	ctx.f3.f64 = double(temp.f32);
	// fadds f1,f7,f1
	ctx.f1.f64 = double(float(ctx.f7.f64 + ctx.f1.f64));
	// stfs f17,372(r1)
	temp.f32 = float(ctx.f17.f64);
	REX_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// fadds f7,f3,f0
	ctx.f7.f64 = double(float(ctx.f3.f64 + ctx.f0.f64));
	// lwz r19,0(r20)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// lfs f16,8(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 8);
	ctx.f16.f64 = double(temp.f32);
	// lfs f17,4(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 4);
	ctx.f17.f64 = double(temp.f32);
	// stfs f15,248(r1)
	temp.f32 = float(ctx.f15.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f6,124(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lfs f6,88(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f6.f64 = double(temp.f32);
	// lfs f3,92(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f3.f64 = double(temp.f32);
	// fadds f0,f3,f13
	ctx.f0.f64 = double(float(ctx.f3.f64 + ctx.f13.f64));
	// subf r19,r19,r15
	ctx.r19.u64 = ctx.r15.u64 - ctx.r19.u64;
	// fadds f1,f1,f12
	ctx.f1.f64 = double(float(ctx.f1.f64 + ctx.f12.f64));
	// mr r17,r15
	ctx.r17.u64 = ctx.r15.u64;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// clrlwi r19,r19,23
	ctx.r19.u64 = ctx.r19.u32 & 0x1FF;
	// lfs f5,400(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 400);
	ctx.f5.f64 = double(temp.f32);
	// addi r17,r17,2
	ctx.r17.s64 = ctx.r17.s64 + 2;
	// lfsx f0,r9,r24
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r24.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r19,r19,2
	ctx.r19.s64 = ctx.r19.s64 + 2;
	// lfs f13,0(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// stfs f14,296(r1)
	temp.f32 = float(ctx.f14.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// rlwinm r19,r19,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// fmuls f28,f28,f5
	ctx.f28.f64 = double(float(ctx.f28.f64 * ctx.f5.f64));
	// lfsx f15,r19,r3
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + ctx.r3.u32);
	ctx.f15.f64 = double(temp.f32);
	// fmadds f31,f16,f15,f31
	ctx.f31.f64 = double(float(std::fma(ctx.f16.f64, ctx.f15.f64, ctx.f31.f64)));
	// stfsx f31,r17,r3
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r17.u32 + ctx.r3.u32, temp.u32);
	// lwz r19,0(r3)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r19,r19,1
	ctx.r19.s64 = ctx.r19.s64 + 1;
	// fmadds f31,f31,f17,f15
	ctx.f31.f64 = double(float(std::fma(ctx.f31.f64, ctx.f17.f64, ctx.f15.f64)));
	// fadds f17,f7,f11
	ctx.f17.f64 = double(float(ctx.f7.f64 + ctx.f11.f64));
	// clrlwi r19,r19,23
	ctx.r19.u64 = ctx.r19.u32 & 0x1FF;
	// fmuls f7,f1,f6
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f6.f64));
	// stw r19,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r19.u32);
	// stfs f31,12(r20)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r20.u32 + 12, temp.u32);
	// lwz r20,328(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 328);
	// addi r19,r20,12
	ctx.r19.s64 = ctx.r20.s64 + 12;
	// lfs f31,4(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// lwz r17,0(r20)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// lfs f16,16(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 16);
	ctx.f16.f64 = double(temp.f32);
	// clrlwi r17,r17,31
	ctx.r17.u64 = ctx.r17.u32 & 0x1;
	// fmuls f6,f17,f6
	ctx.f6.f64 = double(float(ctx.f17.f64 * ctx.f6.f64));
	// lfs f17,92(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f17.f64 = double(temp.f32);
	// addi r17,r17,4
	ctx.r17.s64 = ctx.r17.s64 + 4;
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r17,r20
	temp.u32 = REX_LOAD_U32(ctx.r17.u32 + ctx.r20.u32);
	ctx.f1.f64 = double(temp.f32);
	// stfs f16,20(r20)
	temp.f32 = float(ctx.f16.f64);
	REX_STORE_U32(ctx.r20.u32 + 20, temp.u32);
	// stfs f17,16(r20)
	temp.f32 = float(ctx.f17.f64);
	REX_STORE_U32(ctx.r20.u32 + 16, temp.u32);
	// fmadds f1,f1,f31,f17
	ctx.f1.f64 = double(float(std::fma(ctx.f1.f64, ctx.f31.f64, ctx.f17.f64)));
	// stfs f1,8(r20)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r20.u32 + 8, temp.u32);
	// lwz r20,0(r29)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lfs f1,8(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// clrlwi r20,r20,31
	ctx.r20.u64 = ctx.r20.u32 & 0x1;
	// lfs f31,12(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 12);
	ctx.f31.f64 = double(temp.f32);
	// addi r17,r20,6
	ctx.r17.s64 = ctx.r20.s64 + 6;
	// lfs f17,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f17.f64 = double(temp.f32);
	// addi r20,r29,20
	ctx.r20.s64 = ctx.r29.s64 + 20;
	// lfs f16,24(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 24);
	ctx.f16.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r20,r22,16
	ctx.r20.s64 = ctx.r22.s64 + 16;
	// lfs f15,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f15.f64 = double(temp.f32);
	// fadds f25,f8,f25
	ctx.f25.f64 = double(float(ctx.f8.f64 + ctx.f25.f64));
	// lfsx f14,r17,r29
	temp.u32 = REX_LOAD_U32(ctx.r17.u32 + ctx.r29.u32);
	ctx.f14.f64 = double(temp.f32);
	// fmadds f1,f1,f14,f30
	ctx.f1.f64 = double(float(std::fma(ctx.f1.f64, ctx.f14.f64, ctx.f30.f64)));
	// fmuls f31,f31,f14
	ctx.f31.f64 = double(float(ctx.f31.f64 * ctx.f14.f64));
	// stfs f1,24(r29)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r29.u32 + 24, temp.u32);
	// stfs f16,28(r29)
	temp.f32 = float(ctx.f16.f64);
	REX_STORE_U32(ctx.r29.u32 + 28, temp.u32);
	// fmadds f1,f1,f17,f31
	ctx.f1.f64 = double(float(std::fma(ctx.f1.f64, ctx.f17.f64, ctx.f31.f64)));
	// stfs f1,16(r29)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r29.u32 + 16, temp.u32);
	// lfs f1,12(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// lwz r17,0(r22)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// lfs f31,20(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 20);
	ctx.f31.f64 = double(temp.f32);
	// clrlwi r19,r17,31
	ctx.r19.u64 = ctx.r17.u32 & 0x1;
	// addi r19,r19,5
	ctx.r19.s64 = ctx.r19.s64 + 5;
	// rlwinm r19,r19,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f30,r19,r22
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + ctx.r22.u32);
	ctx.f30.f64 = double(temp.f32);
	// fmadds f1,f30,f1,f29
	ctx.f1.f64 = double(float(std::fma(ctx.f30.f64, ctx.f1.f64, ctx.f29.f64)));
	// stfs f1,20(r22)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r22.u32 + 20, temp.u32);
	// stfs f31,24(r22)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r22.u32 + 24, temp.u32);
	// lfs f31,8(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 8);
	ctx.f31.f64 = double(temp.f32);
	// fmuls f1,f31,f1
	ctx.f1.f64 = double(float(ctx.f31.f64 * ctx.f1.f64));
	// stfs f1,4(r22)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r22.u32 + 4, temp.u32);
	// lwz r17,12(r30)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// lfs f1,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lwz r19,0(r11)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f31,16(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 16);
	ctx.f31.f64 = double(temp.f32);
	// mr r16,r19
	ctx.r16.u64 = ctx.r19.u64;
	// lwz r15,0(r30)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// subf r16,r15,r16
	ctx.r16.u64 = ctx.r16.u64 - ctx.r15.u64;
	// subf r19,r17,r19
	ctx.r19.u64 = ctx.r19.u64 - ctx.r17.u64;
	// clrlwi r20,r16,20
	ctx.r20.u64 = ctx.r16.u32 & 0xFFF;
	// clrlwi r19,r19,20
	ctx.r19.u64 = ctx.r19.u32 & 0xFFF;
	// addi r20,r20,2
	ctx.r20.s64 = ctx.r20.s64 + 2;
	// addi r19,r19,2
	ctx.r19.s64 = ctx.r19.s64 + 2;
	// rlwinm r20,r20,2,0,29
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r19,r19,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f30,r20,r11
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + ctx.r11.u32);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f1,f30,f1
	ctx.f1.f64 = double(float(ctx.f30.f64 * ctx.f1.f64));
	// lfsx f30,r19,r11
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + ctx.r11.u32);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f31,f30,f31
	ctx.f31.f64 = double(float(ctx.f30.f64 * ctx.f31.f64));
	// stfs f1,8(r30)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
	// stfs f31,20(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 20, temp.u32);
	// lwz r20,0(r11)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r20,r20,2
	ctx.r20.s64 = ctx.r20.s64 + 2;
	// rlwinm r20,r20,2,0,29
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f28,r20,r11
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r20.u32 + ctx.r11.u32, temp.u32);
	// lwz r20,0(r11)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r19,r20,1
	ctx.r19.s64 = ctx.r20.s64 + 1;
	// lwz r20,408(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 408);
	// clrlwi r19,r19,20
	ctx.r19.u64 = ctx.r19.u32 & 0xFFF;
	// stw r19,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r19.u32);
	// lfs f1,4(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lwz r19,0(r20)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// clrlwi r19,r19,31
	ctx.r19.u64 = ctx.r19.u32 & 0x1;
	// addi r19,r19,4
	ctx.r19.s64 = ctx.r19.s64 + 4;
	// rlwinm r19,r19,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f31,r19,r20
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + ctx.r20.u32);
	ctx.f31.f64 = double(temp.f32);
	// fmuls f1,f31,f1
	ctx.f1.f64 = double(float(ctx.f31.f64 * ctx.f1.f64));
	// stfs f1,8(r20)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r20.u32 + 8, temp.u32);
	// addi r20,r20,12
	ctx.r20.s64 = ctx.r20.s64 + 12;
	// lfs f1,4(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,8(r20)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r20.u32 + 8, temp.u32);
	// stfs f27,4(r20)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r20.u32 + 4, temp.u32);
	// lwz r20,336(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 336);
	// lwz r19,0(r8)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// mr r17,r19
	ctx.r17.u64 = ctx.r19.u64;
	// lwz r16,0(r20)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// lfs f1,8(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lfs f31,4(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// subf r17,r16,r17
	ctx.r17.u64 = ctx.r17.u64 - ctx.r16.u64;
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// addi r19,r19,2
	ctx.r19.s64 = ctx.r19.s64 + 2;
	// addi r17,r17,2
	ctx.r17.s64 = ctx.r17.s64 + 2;
	// rlwinm r19,r19,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f30,r17,r8
	temp.u32 = REX_LOAD_U32(ctx.r17.u32 + ctx.r8.u32);
	ctx.f30.f64 = double(temp.f32);
	// fmadds f4,f1,f30,f4
	ctx.f4.f64 = double(float(std::fma(ctx.f1.f64, ctx.f30.f64, ctx.f4.f64)));
	// fadds f1,f4,f15
	ctx.f1.f64 = double(float(ctx.f4.f64 + ctx.f15.f64));
	// stfsx f1,r19,r8
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r19.u32 + ctx.r8.u32, temp.u32);
	// lwz r19,0(r8)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// addi r19,r19,1
	ctx.r19.s64 = ctx.r19.s64 + 1;
	// clrlwi r19,r19,23
	ctx.r19.u64 = ctx.r19.u32 & 0x1FF;
	// fmadds f4,f1,f31,f30
	ctx.f4.f64 = double(float(std::fma(ctx.f1.f64, ctx.f31.f64, ctx.f30.f64)));
	// fmuls f1,f22,f5
	ctx.f1.f64 = double(float(ctx.f22.f64 * ctx.f5.f64));
	// stw r19,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r19.u32);
	// stfs f4,12(r20)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r20.u32 + 12, temp.u32);
	// lwz r20,416(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 416);
	// lwz r19,0(r7)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// mr r17,r19
	ctx.r17.u64 = ctx.r19.u64;
	// lfs f4,8(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 8);
	ctx.f4.f64 = double(temp.f32);
	// lwz r16,0(r20)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// lfs f5,4(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// subf r17,r16,r17
	ctx.r17.u64 = ctx.r17.u64 - ctx.r16.u64;
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// addi r19,r19,2
	ctx.r19.s64 = ctx.r19.s64 + 2;
	// addi r17,r17,2
	ctx.r17.s64 = ctx.r17.s64 + 2;
	// rlwinm r19,r19,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f31,r17,r7
	temp.u32 = REX_LOAD_U32(ctx.r17.u32 + ctx.r7.u32);
	ctx.f31.f64 = double(temp.f32);
	// fmadds f4,f4,f31,f26
	ctx.f4.f64 = double(float(std::fma(ctx.f4.f64, ctx.f31.f64, ctx.f26.f64)));
	// stfsx f4,r19,r7
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r19.u32 + ctx.r7.u32, temp.u32);
	// lwz r19,0(r7)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// addi r19,r19,1
	ctx.r19.s64 = ctx.r19.s64 + 1;
	// fmadds f5,f4,f5,f31
	ctx.f5.f64 = double(float(std::fma(ctx.f4.f64, ctx.f5.f64, ctx.f31.f64)));
	// clrlwi r19,r19,23
	ctx.r19.u64 = ctx.r19.u32 & 0x1FF;
	// stw r19,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r19.u32);
	// stfs f5,12(r20)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r20.u32 + 12, temp.u32);
	// lwz r20,424(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 424);
	// addi r19,r20,12
	ctx.r19.s64 = ctx.r20.s64 + 12;
	// lwz r17,0(r20)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// clrlwi r17,r17,31
	ctx.r17.u64 = ctx.r17.u32 & 0x1;
	// addi r17,r17,4
	ctx.r17.s64 = ctx.r17.s64 + 4;
	// lfs f5,16(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,4(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f31,r17,r20
	temp.u32 = REX_LOAD_U32(ctx.r17.u32 + ctx.r20.u32);
	ctx.f31.f64 = double(temp.f32);
	// fmadds f4,f31,f4,f25
	ctx.f4.f64 = double(float(std::fma(ctx.f31.f64, ctx.f4.f64, ctx.f25.f64)));
	// stfs f5,20(r20)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r20.u32 + 20, temp.u32);
	// stfs f25,16(r20)
	temp.f32 = float(ctx.f25.f64);
	REX_STORE_U32(ctx.r20.u32 + 16, temp.u32);
	// stfs f4,8(r20)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r20.u32 + 8, temp.u32);
	// lwz r20,0(r28)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lfs f4,4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// clrlwi r20,r20,31
	ctx.r20.u64 = ctx.r20.u32 & 0x1;
	// lfs f31,12(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 12);
	ctx.f31.f64 = double(temp.f32);
	// addi r17,r20,6
	ctx.r17.s64 = ctx.r20.s64 + 6;
	// lfs f30,24(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 24);
	ctx.f30.f64 = double(temp.f32);
	// addi r20,r28,20
	ctx.r20.s64 = ctx.r28.s64 + 20;
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f5,8(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// addi r20,r21,16
	ctx.r20.s64 = ctx.r21.s64 + 16;
	// lfsx f29,r17,r28
	temp.u32 = REX_LOAD_U32(ctx.r17.u32 + ctx.r28.u32);
	ctx.f29.f64 = double(temp.f32);
	// fmadds f5,f5,f29,f24
	ctx.f5.f64 = double(float(std::fma(ctx.f5.f64, ctx.f29.f64, ctx.f24.f64)));
	// fmuls f4,f5,f4
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f4.f64));
	// stfs f5,24(r28)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r28.u32 + 24, temp.u32);
	// stfs f30,28(r28)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r28.u32 + 28, temp.u32);
	// fmadds f5,f29,f31,f4
	ctx.f5.f64 = double(float(std::fma(ctx.f29.f64, ctx.f31.f64, ctx.f4.f64)));
	// stfs f5,16(r28)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r28.u32 + 16, temp.u32);
	// lfs f4,12(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 12);
	ctx.f4.f64 = double(temp.f32);
	// lwz r17,0(r21)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// lfs f5,20(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 20);
	ctx.f5.f64 = double(temp.f32);
	// clrlwi r19,r17,31
	ctx.r19.u64 = ctx.r17.u32 & 0x1;
	// addi r19,r19,5
	ctx.r19.s64 = ctx.r19.s64 + 5;
	// rlwinm r19,r19,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f31,r19,r21
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + ctx.r21.u32);
	ctx.f31.f64 = double(temp.f32);
	// fmadds f4,f31,f4,f23
	ctx.f4.f64 = double(float(std::fma(ctx.f31.f64, ctx.f4.f64, ctx.f23.f64)));
	// stfs f4,20(r21)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r21.u32 + 20, temp.u32);
	// stfs f5,24(r21)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r21.u32 + 24, temp.u32);
	// lfs f5,8(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f4,f5
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f5.f64));
	// stfs f4,4(r21)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r21.u32 + 4, temp.u32);
	// lwz r19,0(r10)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r17,12(r27)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r27.u32 + 12);
	// lfs f4,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// lwz r16,0(r27)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lfs f5,16(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// subf r19,r17,r19
	ctx.r19.u64 = ctx.r19.u64 - ctx.r17.u64;
	// lwz r17,0(r10)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// ld r25,440(r1)
	ctx.r25.u64 = REX_LOAD_U64(ctx.r1.u32 + 440);
	// fadds f31,f0,f20
	ctx.f31.f64 = double(float(ctx.f0.f64 + ctx.f20.f64));
	// subf r17,r16,r17
	ctx.r17.u64 = ctx.r17.u64 - ctx.r16.u64;
	// ld r5,432(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 432);
	// clrlwi r19,r19,20
	ctx.r19.u64 = ctx.r19.u32 & 0xFFF;
	// ld r4,464(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 464);
	// clrlwi r20,r17,20
	ctx.r20.u64 = ctx.r17.u32 & 0xFFF;
	// ld r9,456(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 456);
	// addi r19,r19,2
	ctx.r19.s64 = ctx.r19.s64 + 2;
	// fadds f3,f3,f18
	ctx.f3.f64 = double(float(ctx.f3.f64 + ctx.f18.f64));
	// addi r20,r20,2
	ctx.r20.s64 = ctx.r20.s64 + 2;
	// rlwinm r19,r19,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r20,r20,2,0,29
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f30,r19,r10
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + ctx.r10.u32);
	ctx.f30.f64 = double(temp.f32);
	// lfsx f29,r20,r10
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + ctx.r10.u32);
	ctx.f29.f64 = double(temp.f32);
	// fmuls f5,f5,f30
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f30.f64));
	// fmuls f4,f29,f4
	ctx.f4.f64 = double(float(ctx.f29.f64 * ctx.f4.f64));
	// stfs f4,8(r27)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r27.u32 + 8, temp.u32);
	// stfs f5,20(r27)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r27.u32 + 20, temp.u32);
	// lwz r20,0(r10)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r20,r20,2
	ctx.r20.s64 = ctx.r20.s64 + 2;
	// rlwinm r20,r20,2,0,29
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f1,r20,r10
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r20.u32 + ctx.r10.u32, temp.u32);
	// lwz r20,0(r10)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r20,r20,1
	ctx.r20.s64 = ctx.r20.s64 + 1;
	// clrlwi r19,r20,20
	ctx.r19.u64 = ctx.r20.u32 & 0xFFF;
	// lwz r20,348(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 348);
	// stw r19,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r19.u32);
	// lwz r19,0(r20)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// clrlwi r19,r19,31
	ctx.r19.u64 = ctx.r19.u32 & 0x1;
	// addi r19,r19,4
	ctx.r19.s64 = ctx.r19.s64 + 4;
	// lfs f1,4(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// rlwinm r19,r19,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f5,r19,r20
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + ctx.r20.u32);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f5,f1
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f1.f64));
	// stfs f4,8(r20)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r20.u32 + 8, temp.u32);
	// addi r20,r20,12
	ctx.r20.s64 = ctx.r20.s64 + 12;
	// lfs f1,4(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,8(r20)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r20.u32 + 8, temp.u32);
	// stfs f21,4(r20)
	temp.f32 = float(ctx.f21.f64);
	REX_STORE_U32(ctx.r20.u32 + 4, temp.u32);
	// lwz r20,420(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 420);
	// lfs f4,8(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 8);
	ctx.f4.f64 = double(temp.f32);
	// lwz r17,0(r20)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// lwz r19,0(r6)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// lfs f5,4(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// subf r19,r17,r19
	ctx.r19.u64 = ctx.r19.u64 - ctx.r17.u64;
	// clrlwi r17,r19,21
	ctx.r17.u64 = ctx.r19.u32 & 0x7FF;
	// lwz r19,0(r6)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// addi r19,r19,2
	ctx.r19.s64 = ctx.r19.s64 + 2;
	// addi r17,r17,2
	ctx.r17.s64 = ctx.r17.s64 + 2;
	// rlwinm r19,r19,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r17,r6
	temp.u32 = REX_LOAD_U32(ctx.r17.u32 + ctx.r6.u32);
	ctx.f1.f64 = double(temp.f32);
	// fmadds f4,f1,f4,f13
	ctx.f4.f64 = double(float(std::fma(ctx.f1.f64, ctx.f4.f64, ctx.f13.f64)));
	// fadds f4,f4,f9
	ctx.f4.f64 = double(float(ctx.f4.f64 + ctx.f9.f64));
	// fadds f4,f4,f10
	ctx.f4.f64 = double(float(ctx.f4.f64 + ctx.f10.f64));
	// stfsx f4,r19,r6
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r19.u32 + ctx.r6.u32, temp.u32);
	// lwz r19,0(r6)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// addi r19,r19,1
	ctx.r19.s64 = ctx.r19.s64 + 1;
	// clrlwi r19,r19,21
	ctx.r19.u64 = ctx.r19.u32 & 0x7FF;
	// fmadds f1,f4,f5,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f4.f64, ctx.f5.f64, ctx.f1.f64)));
	// stw r19,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r19.u32);
	// stfs f1,12(r20)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r20.u32 + 12, temp.u32);
	// lwz r20,356(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 356);
	// lwz r19,0(r25)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r17,r19
	ctx.r17.u64 = ctx.r19.u64;
	// lwz r16,0(r20)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// subf r17,r16,r17
	ctx.r17.u64 = ctx.r17.u64 - ctx.r16.u64;
	// addi r16,r19,2
	ctx.r16.s64 = ctx.r19.s64 + 2;
	// lfs f5,12(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 12);
	ctx.f5.f64 = double(temp.f32);
	// clrlwi r19,r17,21
	ctx.r19.u64 = ctx.r17.u32 & 0x7FF;
	// lfs f4,8(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 8);
	ctx.f4.f64 = double(temp.f32);
	// lfs f1,4(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// rlwinm r17,r16,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r19,r19,2
	ctx.r19.s64 = ctx.r19.s64 + 2;
	// rlwinm r19,r19,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// ld r26,448(r1)
	ctx.r26.u64 = REX_LOAD_U64(ctx.r1.u32 + 448);
	// lwz r16,116(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lfsx f30,r19,r25
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + ctx.r25.u32);
	ctx.f30.f64 = double(temp.f32);
	// fmadds f4,f30,f4,f31
	ctx.f4.f64 = double(float(std::fma(ctx.f30.f64, ctx.f4.f64, ctx.f31.f64)));
	// stfsx f4,r17,r25
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r17.u32 + ctx.r25.u32, temp.u32);
	// fmuls f5,f30,f5
	ctx.f5.f64 = double(float(ctx.f30.f64 * ctx.f5.f64));
	// fmadds f1,f1,f31,f5
	ctx.f1.f64 = double(float(std::fma(ctx.f1.f64, ctx.f31.f64, ctx.f5.f64)));
	// lwz r19,0(r25)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// addi r19,r19,1
	ctx.r19.s64 = ctx.r19.s64 + 1;
	// clrlwi r19,r19,21
	ctx.r19.u64 = ctx.r19.u32 & 0x7FF;
	// stw r19,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r19.u32);
	// stfs f1,16(r20)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r20.u32 + 16, temp.u32);
	// lwz r20,396(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 396);
	// lwz r17,0(r20)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// lfs f4,8(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 8);
	ctx.f4.f64 = double(temp.f32);
	// lwz r15,0(r5)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// lfs f5,4(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// subf r17,r17,r15
	ctx.r17.u64 = ctx.r15.u64 - ctx.r17.u64;
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// mr r19,r15
	ctx.r19.u64 = ctx.r15.u64;
	// addi r17,r17,2
	ctx.r17.s64 = ctx.r17.s64 + 2;
	// addi r19,r19,2
	ctx.r19.s64 = ctx.r19.s64 + 2;
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r19,r19,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r17,r5
	temp.u32 = REX_LOAD_U32(ctx.r17.u32 + ctx.r5.u32);
	ctx.f1.f64 = double(temp.f32);
	// fmadds f4,f1,f4,f19
	ctx.f4.f64 = double(float(std::fma(ctx.f1.f64, ctx.f4.f64, ctx.f19.f64)));
	// stfsx f4,r19,r5
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r19.u32 + ctx.r5.u32, temp.u32);
	// lwz r19,0(r5)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// addi r19,r19,1
	ctx.r19.s64 = ctx.r19.s64 + 1;
	// fmadds f1,f4,f5,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f4.f64, ctx.f5.f64, ctx.f1.f64)));
	// clrlwi r19,r19,21
	ctx.r19.u64 = ctx.r19.u32 & 0x7FF;
	// stw r19,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r19.u32);
	// stfs f1,12(r20)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r20.u32 + 12, temp.u32);
	// lwz r20,364(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 364);
	// lfs f5,8(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,4(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// lwz r15,0(r4)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r17,0(r20)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// subf r17,r17,r15
	ctx.r17.u64 = ctx.r15.u64 - ctx.r17.u64;
	// clrlwi r17,r17,22
	ctx.r17.u64 = ctx.r17.u32 & 0x3FF;
	// mr r19,r15
	ctx.r19.u64 = ctx.r15.u64;
	// addi r17,r17,2
	ctx.r17.s64 = ctx.r17.s64 + 2;
	// addi r19,r19,2
	ctx.r19.s64 = ctx.r19.s64 + 2;
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r19,r19,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r17,r4
	temp.u32 = REX_LOAD_U32(ctx.r17.u32 + ctx.r4.u32);
	ctx.f1.f64 = double(temp.f32);
	// fmadds f5,f1,f5,f0
	ctx.f5.f64 = double(float(std::fma(ctx.f1.f64, ctx.f5.f64, ctx.f0.f64)));
	// fadds f2,f5,f2
	ctx.f2.f64 = double(float(ctx.f5.f64 + ctx.f2.f64));
	// stfsx f2,r19,r4
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r19.u32 + ctx.r4.u32, temp.u32);
	// fmadds f1,f2,f4,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f2.f64, ctx.f4.f64, ctx.f1.f64)));
	// lwz r19,0(r4)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// addi r19,r19,1
	ctx.r19.s64 = ctx.r19.s64 + 1;
	// clrlwi r19,r19,22
	ctx.r19.u64 = ctx.r19.u32 & 0x3FF;
	// stw r19,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r19.u32);
	// stfs f1,12(r20)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r20.u32 + 12, temp.u32);
	// lwz r19,12(r26)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r26.u32 + 12);
	// lfs f5,16(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// lwz r20,0(r9)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f4,4(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// mr r17,r20
	ctx.r17.u64 = ctx.r20.u64;
	// subf r20,r19,r20
	ctx.r20.u64 = ctx.r20.u64 - ctx.r19.u64;
	// lwz r19,0(r26)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// clrlwi r20,r20,20
	ctx.r20.u64 = ctx.r20.u32 & 0xFFF;
	// subf r19,r19,r17
	ctx.r19.u64 = ctx.r17.u64 - ctx.r19.u64;
	// addi r17,r20,2
	ctx.r17.s64 = ctx.r20.s64 + 2;
	// clrlwi r20,r19,20
	ctx.r20.u64 = ctx.r19.u32 & 0xFFF;
	// rlwinm r19,r17,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r17,r20,2
	ctx.r17.s64 = ctx.r20.s64 + 2;
	// clrlwi r20,r16,27
	ctx.r20.u64 = ctx.r16.u32 & 0x1F;
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// lfsx f2,r19,r9
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + ctx.r9.u32);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f1,f2,f5
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f5.f64));
	// lfsx f5,r17,r9
	temp.u32 = REX_LOAD_U32(ctx.r17.u32 + ctx.r9.u32);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f5,f4
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f4.f64));
	// stfs f4,8(r26)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r26.u32 + 8, temp.u32);
	// stfs f1,20(r26)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r26.u32 + 20, temp.u32);
	// lwz r20,0(r9)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// addi r20,r20,2
	ctx.r20.s64 = ctx.r20.s64 + 2;
	// rlwinm r20,r20,2,0,29
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f3,r20,r9
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r20.u32 + ctx.r9.u32, temp.u32);
	// ld r31,384(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + 384);
	// lfs f2,372(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 372);
	ctx.f2.f64 = double(temp.f32);
	// lwz r20,0(r9)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// addi r19,r20,1
	ctx.r19.s64 = ctx.r20.s64 + 1;
	// lwz r20,412(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 412);
	// clrlwi r17,r19,20
	ctx.r17.u64 = ctx.r19.u32 & 0xFFF;
	// addi r19,r20,16
	ctx.r19.s64 = ctx.r20.s64 + 16;
	// stw r17,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r17.u32);
	// lwz r17,0(r20)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// lfs f3,8(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f2.f64));
	// clrlwi r17,r17,31
	ctx.r17.u64 = ctx.r17.u32 & 0x1;
	// lfs f5,12(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 12);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,20(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 20);
	ctx.f4.f64 = double(temp.f32);
	// addi r17,r17,5
	ctx.r17.s64 = ctx.r17.s64 + 5;
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f3,r17,r20
	temp.u32 = REX_LOAD_U32(ctx.r17.u32 + ctx.r20.u32);
	ctx.f3.f64 = double(temp.f32);
	// stfs f4,24(r20)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r20.u32 + 24, temp.u32);
	// fmadds f1,f3,f5,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f3.f64, ctx.f5.f64, ctx.f1.f64)));
	// stfs f2,20(r20)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r20.u32 + 20, temp.u32);
	// stfs f1,4(r20)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r20.u32 + 4, temp.u32);
	// bne cr6,0x820dfd68
	if (!ctx.cr6.eq) goto loc_820DFD68;
	// lwz r20,144(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// addi r20,r20,128
	ctx.r20.s64 = ctx.r20.s64 + 128;
	// stw r20,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r20.u32);
loc_820DFD68:
	// lwz r16,128(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lfs f4,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f4.f64 = double(temp.f32);
	// lwz r19,120(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// fsubs f10,f9,f10
	ctx.f10.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// mr r17,r16
	ctx.r17.u64 = ctx.r16.u64;
	// lwz r15,96(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// mr r14,r16
	ctx.r14.u64 = ctx.r16.u64;
	// std r11,384(r1)
	REX_STORE_U64(ctx.r1.u32 + 384, ctx.r11.u64);
	// addi r20,r17,16
	ctx.r20.s64 = ctx.r17.s64 + 16;
	// lfs f9,404(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 404);
	ctx.f9.f64 = double(temp.f32);
	// addi r20,r19,20
	ctx.r20.s64 = ctx.r19.s64 + 20;
	// lfs f3,4(r16)
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// addi r19,r15,16
	ctx.r19.s64 = ctx.r15.s64 + 16;
	// lwz r15,112(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// addi r16,r16,16
	ctx.r16.s64 = ctx.r16.s64 + 16;
	// lwz r11,16(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 16);
	// lfs f2,8(r17)
	temp.u32 = REX_LOAD_U32(ctx.r17.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// lwz r17,0(r17)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// fadds f5,f13,f9
	ctx.f5.f64 = double(float(ctx.f13.f64 + ctx.f9.f64));
	// subf r11,r17,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r17.u64;
	// stw r15,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r15.u32);
	// lwz r15,0(r16)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r16.u32 + 0);
	// addi r15,r15,2
	ctx.r15.s64 = ctx.r15.s64 + 2;
	// lwz r17,124(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// stw r15,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r15.u32);
	// clrlwi r15,r11,21
	ctx.r15.u64 = ctx.r11.u32 & 0x7FF;
	// addi r17,r17,16
	ctx.r17.s64 = ctx.r17.s64 + 16;
	// addi r15,r15,2
	ctx.r15.s64 = ctx.r15.s64 + 2;
	// rlwinm r15,r15,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r15,r16
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + ctx.r16.u32);
	ctx.f1.f64 = double(temp.f32);
	// fmadds f10,f1,f2,f10
	ctx.f10.f64 = double(float(std::fma(ctx.f1.f64, ctx.f2.f64, ctx.f10.f64)));
	// lwz r11,124(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// fadds f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f0.f64));
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f9,r11,r16
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r16.u32, temp.u32);
	// lwz r15,0(r16)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r16.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// clrlwi r15,r15,21
	ctx.r15.u64 = ctx.r15.u32 & 0x7FF;
	// fmadds f3,f9,f3,f1
	ctx.f3.f64 = double(float(std::fma(ctx.f9.f64, ctx.f3.f64, ctx.f1.f64)));
	// stw r15,0(r16)
	REX_STORE_U32(ctx.r16.u32 + 0, ctx.r15.u32);
	// stfs f3,12(r14)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r14.u32 + 12, temp.u32);
	// lwz r16,120(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lfs f0,12(r16)
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// lfs f2,8(r16)
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// lwz r14,0(r16)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r16.u32 + 0);
	// lwz r11,0(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// mr r15,r11
	ctx.r15.u64 = ctx.r11.u64;
	// subf r14,r14,r11
	ctx.r14.u64 = ctx.r11.u64 - ctx.r14.u64;
	// lfs f1,4(r16)
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// addi r11,r15,2
	ctx.r11.s64 = ctx.r15.s64 + 2;
	// clrlwi r15,r14,21
	ctx.r15.u64 = ctx.r14.u32 & 0x7FF;
	// rlwinm r14,r11,2,0,29
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r15,r15,2
	ctx.r15.s64 = ctx.r15.s64 + 2;
	// rlwinm r15,r15,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f10,r15,r20
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + ctx.r20.u32);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f3,f10,f0
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// fmadds f9,f10,f2,f5
	ctx.f9.f64 = double(float(std::fma(ctx.f10.f64, ctx.f2.f64, ctx.f5.f64)));
	// stfsx f9,r14,r20
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r14.u32 + ctx.r20.u32, temp.u32);
	// lwz r15,0(r20)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// clrlwi r15,r15,21
	ctx.r15.u64 = ctx.r15.u32 & 0x7FF;
	// fmadds f2,f5,f1,f3
	ctx.f2.f64 = double(float(std::fma(ctx.f5.f64, ctx.f1.f64, ctx.f3.f64)));
	// stw r15,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r15.u32);
	// stfs f2,16(r16)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r16.u32 + 16, temp.u32);
	// lwz r20,96(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lfs f1,8(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r15,0(r19)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// lwz r14,0(r20)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// lfs f0,4(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// mr r16,r15
	ctx.r16.u64 = ctx.r15.u64;
	// subf r15,r14,r15
	ctx.r15.u64 = ctx.r15.u64 - ctx.r14.u64;
	// addi r14,r16,2
	ctx.r14.s64 = ctx.r16.s64 + 2;
	// clrlwi r16,r15,21
	ctx.r16.u64 = ctx.r15.u32 & 0x7FF;
	// rlwinm r15,r14,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r16,r16,2
	ctx.r16.s64 = ctx.r16.s64 + 2;
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f10,r16,r19
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + ctx.r19.u32);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f9,f1,f10,f4
	ctx.f9.f64 = double(float(std::fma(ctx.f1.f64, ctx.f10.f64, ctx.f4.f64)));
	// stfsx f9,r15,r19
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r15.u32 + ctx.r19.u32, temp.u32);
	// lwz r16,0(r19)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// clrlwi r15,r16,21
	ctx.r15.u64 = ctx.r16.u32 & 0x7FF;
	// fmadds f5,f9,f0,f10
	ctx.f5.f64 = double(float(std::fma(ctx.f9.f64, ctx.f0.f64, ctx.f10.f64)));
	// lwz r14,104(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lfs f4,240(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f4.f64 = double(temp.f32);
	// stw r15,0(r19)
	REX_STORE_U32(ctx.r19.u32 + 0, ctx.r15.u32);
	// stfs f5,12(r20)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r20.u32 + 12, temp.u32);
	// addi r20,r14,4
	ctx.r20.s64 = ctx.r14.s64 + 4;
	// lwz r19,100(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r16,112(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stfs f6,0(r24)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r24.u32 + 0, temp.u32);
	// stw r20,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r20.u32);
	// lfs f3,248(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 248);
	ctx.f3.f64 = double(temp.f32);
	// lwz r20,84(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// fadds f2,f8,f3
	ctx.f2.f64 = double(float(ctx.f8.f64 + ctx.f3.f64));
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stfsx f7,r24,r19
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r24.u32 + ctx.r19.u32, temp.u32);
	// lwz r14,116(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lfs f1,8(r16)
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r15,136(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// stfsx f12,r20,r24
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r20.u32 + ctx.r24.u32, temp.u32);
	// addi r15,r15,4
	ctx.r15.s64 = ctx.r15.s64 + 4;
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stw r14,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r14.u32);
	// stw r15,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r15.u32);
	// addi r24,r24,4
	ctx.r24.s64 = ctx.r24.s64 + 4;
	// lwz r19,0(r17)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// lfs f0,4(r16)
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lwz r20,0(r16)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r16.u32 + 0);
	// addi r14,r19,2
	ctx.r14.s64 = ctx.r19.s64 + 2;
	// subf r20,r20,r19
	ctx.r20.u64 = ctx.r19.u64 - ctx.r20.u64;
	// lwz r15,104(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// rlwinm r14,r14,2,0,29
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r19,264(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 264);
	// clrlwi r20,r20,22
	ctx.r20.u64 = ctx.r20.u32 & 0x3FF;
	// cmpwi cr6,r15,1024
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 1024, ctx.xer);
	// addi r20,r20,2
	ctx.r20.s64 = ctx.r20.s64 + 2;
	// rlwinm r11,r20,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r20,r19,24
	ctx.r20.s64 = ctx.r19.s64 + 24;
	// lfsx f12,r11,r17
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r17.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f12,f1,f13
	ctx.f11.f64 = double(float(std::fma(ctx.f12.f64, ctx.f1.f64, ctx.f13.f64)));
	// fadds f10,f11,f4
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f4.f64));
	// stfsx f10,r14,r17
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r14.u32 + ctx.r17.u32, temp.u32);
	// fmadds f9,f10,f0,f12
	ctx.f9.f64 = double(float(std::fma(ctx.f10.f64, ctx.f0.f64, ctx.f12.f64)));
	// lwz r15,0(r17)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// clrlwi r15,r15,22
	ctx.r15.u64 = ctx.r15.u32 & 0x3FF;
	// stw r15,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r15.u32);
	// stfs f9,12(r16)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r16.u32 + 12, temp.u32);
	// lwz r16,0(r19)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// lfs f8,16(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// lwz r17,24(r19)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r19.u32 + 24);
	// lfs f7,4(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// subf r17,r16,r17
	ctx.r17.u64 = ctx.r17.u64 - ctx.r16.u64;
	// lwz r16,24(r19)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r19.u32 + 24);
	// clrlwi r17,r17,20
	ctx.r17.u64 = ctx.r17.u32 & 0xFFF;
	// lwz r15,12(r19)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r19.u32 + 12);
	// subf r16,r15,r16
	ctx.r16.u64 = ctx.r16.u64 - ctx.r15.u64;
	// addi r17,r17,2
	ctx.r17.s64 = ctx.r17.s64 + 2;
	// clrlwi r16,r16,20
	ctx.r16.u64 = ctx.r16.u32 & 0xFFF;
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r16,r16,2
	ctx.r16.s64 = ctx.r16.s64 + 2;
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f6,r17,r20
	temp.u32 = REX_LOAD_U32(ctx.r17.u32 + ctx.r20.u32);
	ctx.f6.f64 = double(temp.f32);
	// lfsx f5,r16,r20
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + ctx.r20.u32);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f5,f8
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f8.f64));
	// fmuls f3,f6,f7
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f7.f64));
	// stfs f3,8(r19)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r19.u32 + 8, temp.u32);
	// stfs f4,20(r19)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r19.u32 + 20, temp.u32);
	// lwz r19,24(r19)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r19.u32 + 24);
	// addi r19,r19,2
	ctx.r19.s64 = ctx.r19.s64 + 2;
	// rlwinm r19,r19,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f2,r19,r20
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r19.u32 + ctx.r20.u32, temp.u32);
	// lwz r19,0(r20)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// addi r19,r19,1
	ctx.r19.s64 = ctx.r19.s64 + 1;
	// clrlwi r19,r19,20
	ctx.r19.u64 = ctx.r19.u32 & 0xFFF;
	// stw r19,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r19.u32);
	// lwz r20,280(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 280);
	// lwz r19,0(r20)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// lfs f2,8(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// clrlwi r19,r19,31
	ctx.r19.u64 = ctx.r19.u32 & 0x1;
	// lfs f0,296(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// addi r17,r19,5
	ctx.r17.s64 = ctx.r19.s64 + 5;
	// fmuls f1,f2,f0
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f0.f64));
	// lfs f13,12(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f12,20(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// ld r11,384(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 384);
	// addi r19,r20,16
	ctx.r19.s64 = ctx.r20.s64 + 16;
	// lfsx f11,r17,r20
	temp.u32 = REX_LOAD_U32(ctx.r17.u32 + ctx.r20.u32);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,24(r20)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r20.u32 + 24, temp.u32);
	// stfs f0,20(r20)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r20.u32 + 20, temp.u32);
	// fmadds f10,f11,f13,f1
	ctx.f10.f64 = double(float(std::fma(ctx.f11.f64, ctx.f13.f64, ctx.f1.f64)));
	// stfs f10,4(r20)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r20.u32 + 4, temp.u32);
	// blt cr6,0x820df544
	if (ctx.cr6.lt) goto loc_820DF544;
	// lwz r27,232(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 232);
	// addis r3,r31,5
	ctx.r3.s64 = ctx.r31.s64 + 327680;
	// lwz r28,220(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 220);
	// addi r3,r3,-28368
	ctx.r3.s64 = ctx.r3.s64 + -28368;
	// lwz r26,228(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 228);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x820de1b8
	ctx.lr = 0x820E0044;
	sub_820DE1B8(ctx, base);
	// addis r3,r31,5
	ctx.r3.s64 = ctx.r31.s64 + 327680;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r3,-26296
	ctx.r3.s64 = ctx.r3.s64 + -26296;
	// bl 0x820de1b8
	ctx.lr = 0x820E0054;
	sub_820DE1B8(ctx, base);
	// lwz r30,224(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 224);
	// addis r3,r31,5
	ctx.r3.s64 = ctx.r31.s64 + 327680;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r3,-24224
	ctx.r3.s64 = ctx.r3.s64 + -24224;
	// bl 0x820de1b8
	ctx.lr = 0x820E0068;
	sub_820DE1B8(ctx, base);
	// addis r3,r31,5
	ctx.r3.s64 = ctx.r31.s64 + 327680;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r3,-22152
	ctx.r3.s64 = ctx.r3.s64 + -22152;
	// bl 0x820de1b8
	ctx.lr = 0x820E0078;
	sub_820DE1B8(ctx, base);
	// addi r29,r28,-8
	ctx.r29.s64 = ctx.r28.s64 + -8;
	// addis r3,r31,5
	ctx.r3.s64 = ctx.r31.s64 + 327680;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r3,r3,-20080
	ctx.r3.s64 = ctx.r3.s64 + -20080;
	// bl 0x820de550
	ctx.lr = 0x820E0090;
	sub_820DE550(ctx, base);
	// addi r28,r26,-8
	ctx.r28.s64 = ctx.r26.s64 + -8;
	// addis r3,r31,5
	ctx.r3.s64 = ctx.r31.s64 + 327680;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r3,r3,-19024
	ctx.r3.s64 = ctx.r3.s64 + -19024;
	// bl 0x820de550
	ctx.lr = 0x820E00A8;
	sub_820DE550(ctx, base);
	// li r7,92
	ctx.r7.s64 = 92;
	// lis r6,-32235
	ctx.r6.s64 = -2112552960;
	// lwz r9,160(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// lwz r8,152(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// addi r5,r6,6832
	ctx.r5.s64 = ctx.r6.s64 + 6832;
	// lwz r6,324(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 324);
	// subf r3,r9,r27
	ctx.r3.u64 = ctx.r27.u64 - ctx.r9.u64;
	// lvlx128 v63,r31,r7
	temp.u32 = ctx.r31.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// subf r24,r9,r29
	ctx.r24.u64 = ctx.r29.u64 - ctx.r9.u64;
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// subf r26,r9,r30
	ctx.r26.u64 = ctx.r30.u64 - ctx.r9.u64;
	// subf r22,r30,r8
	ctx.r22.u64 = ctx.r8.u64 - ctx.r30.u64;
	// lwz r7,332(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 332);
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subf r25,r9,r8
	ctx.r25.u64 = ctx.r8.u64 - ctx.r9.u64;
	// subf r27,r30,r27
	ctx.r27.u64 = ctx.r27.u64 - ctx.r30.u64;
	// lwz r8,308(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 308);
	// subf r29,r30,r29
	ctx.r29.u64 = ctx.r29.u64 - ctx.r30.u64;
	// vsubfp128 v0,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// addi r11,r9,16
	ctx.r11.s64 = ctx.r9.s64 + 16;
	// vaddfp128 v62,v63,v63
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v63.f32)));
	// subf r23,r9,r28
	ctx.r23.u64 = ctx.r28.u64 - ctx.r9.u64;
	// lwz r9,316(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 316);
	// subf r30,r30,r28
	ctx.r30.u64 = ctx.r28.u64 - ctx.r30.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// li r31,-16
	ctx.r31.s64 = -16;
	// li r5,16
	ctx.r5.s64 = 16;
loc_820E0118:
	// lvx128 v61,r27,r10
	ea = (ctx.r27.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r4,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// lvx128 v60,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v63,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lvx128 v59,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v12,v63,v60
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// lvx128 v58,r26,r11
	ea = (ctx.r26.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v11,v63,v59
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vmulfp128 v10,v63,v58
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v58.f32)));
	// lvx128 v9,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r11,r31
	ea = (ctx.r11.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v7,r22,r10
	ea = (ctx.r22.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v6,r25,r11
	ea = (ctx.r25.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r29,r10
	ea = (ctx.r29.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r24,r11
	ea = (ctx.r24.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v55,v62,v57
	simde_mm_store_ps(ctx.v55.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v57.f32)));
	// lvx128 v54,r30,r10
	ea = (ctx.r30.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v53,v62,v56
	simde_mm_store_ps(ctx.v53.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v56.f32)));
	// lvx128 v52,r23,r11
	ea = (ctx.r23.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v51,v62,v54
	simde_mm_store_ps(ctx.v51.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v54.f32)));
	// vmulfp128 v50,v62,v52
	simde_mm_store_ps(ctx.v50.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v52.f32)));
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// vmaddfp v5,v0,v8,v13
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// vmaddfp v4,v0,v9,v12
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v3,v0,v7,v11
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v2,v0,v6,v10
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v55,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r9,r5
	ea = (ctx.r9.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// stvx128 v51,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r8,r5
	ea = (ctx.r8.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,32
	ctx.r8.s64 = ctx.r8.s64 + 32;
	// stvx128 v5,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v4,r7,r5
	ea = (ctx.r7.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r7,32
	ctx.r7.s64 = ctx.r7.s64 + 32;
	// stvx128 v3,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v2,r6,r5
	ea = (ctx.r6.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r6,32
	ctx.r6.s64 = ctx.r6.s64 + 32;
	// bne 0x820e0118
	if (!ctx.cr0.eq) goto loc_820E0118;
	// addi r1,r1,17968
	ctx.r1.s64 = ctx.r1.s64 + 17968;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8212a86c
	ctx.lr = 0x820E01C4;
	__restfpr_14(ctx, base);
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
}
