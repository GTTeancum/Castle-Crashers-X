DEFINE_REX_FUNC(sub_820A9308) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x820A9310;
	__savegprlr_21(ctx, base);
	// addi r12,r1,-96
	ctx.r12.s64 = ctx.r1.s64 + -96;
	// bl 0x8212a838
	ctx.lr = 0x820A9318;
	__savefpr_20(ctx, base);
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// mr r29,r9
	ctx.r29.u64 = ctx.r9.u64;
	// mr r28,r10
	ctx.r28.u64 = ctx.r10.u64;
	// lbz r11,28715(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28715);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a9ad0
	if (ctx.cr6.eq) goto loc_820A9AD0;
	// lis r21,-32215
	ctx.r21.s64 = -2111242240;
	// lwz r3,-22588(r21)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r21.u32 + -22588);
	// cmpwi cr6,r3,6000
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 6000, ctx.xer);
	// bge cr6,0x820a9ad0
	if (!ctx.cr6.lt) goto loc_820A9AD0;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,4(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r8,8(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// addi r22,r11,18236
	ctx.r22.s64 = ctx.r11.s64 + 18236;
	// lwz r4,0(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r11,4(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// lwz r27,0(r6)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r26,4(r6)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r25,0(r7)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r24,4(r7)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,8(r5)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// lwz r6,8(r6)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r7,8(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r23,500(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 500);
	// stw r10,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// stw r9,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// cmpwi cr6,r23,4
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 4, ctx.xer);
	// stw r8,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);
	// stw r4,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r4.u32);
	// stw r11,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r11.u32);
	// stw r5,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r5.u32);
	// stw r27,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// stw r26,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r26.u32);
	// stw r6,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// stw r25,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r25.u32);
	// stw r24,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r24.u32);
	// stw r7,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r7.u32);
	// beq cr6,0x820a950c
	if (ctx.cr6.eq) goto loc_820A950C;
	// lwz r11,29124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 29124);
	// lfs f4,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,184(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r10,r11,1198
	ctx.r10.s64 = ctx.r11.s64 + 1198;
	// lfs f0,12(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f10,132(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f12,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// fadds f6,f10,f0
	ctx.f6.f64 = double(float(ctx.f10.f64 + ctx.f0.f64));
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lfs f3,120(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f3.f64 = double(temp.f32);
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// fadds f8,f12,f0
	ctx.f8.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lfs f10,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// add r8,r11,r31
	ctx.r8.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r11,184(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
	// lfs f5,152(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f5.f64 = double(temp.f32);
	// lfs f12,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// stfs f3,200(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// fadds f3,f10,f0
	ctx.f3.f64 = double(float(ctx.f10.f64 + ctx.f0.f64));
	// lwzx r4,r9,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// stfs f5,168(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lwz r10,28748(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 28748);
	// fadds f5,f12,f0
	ctx.f5.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// lwz r9,200(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 200);
	// lfs f11,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f11.f64 = double(temp.f32);
	// fadds f9,f13,f0
	ctx.f9.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfs f13,148(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// fadds f7,f11,f0
	ctx.f7.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// std r4,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f2,80(r1)
	ctx.f2.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// fcfid f12,f2
	ctx.f12.f64 = double(ctx.f2.s64);
	// lfd f1,80(r1)
	ctx.f1.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fadds f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// fcfid f10,f1
	ctx.f10.f64 = double(ctx.f1.s64);
	// lfs f4,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f4.f64 = double(temp.f32);
	// fadds f0,f4,f0
	ctx.f0.f64 = double(float(ctx.f4.f64 + ctx.f0.f64));
	// lfs f13,136(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f13.f64 = double(temp.f32);
	// frsp f4,f12
	ctx.f4.f64 = double(float(ctx.f12.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r8,88(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// lwz r7,168(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 168);
	// stw r7,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r7.u32);
	// frsp f2,f10
	ctx.f2.f64 = double(float(ctx.f10.f64));
	// stw r8,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);
	// fmuls f13,f4,f7
	ctx.f13.f64 = double(float(ctx.f4.f64 * ctx.f7.f64));
	// stfs f13,196(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// fmuls f10,f4,f6
	ctx.f10.f64 = double(float(ctx.f4.f64 * ctx.f6.f64));
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r6,196(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 196);
	// fmuls f1,f4,f8
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f8.f64));
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stfs f1,180(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lwz r7,180(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// stw r9,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r9.u32);
	// stw r7,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// fmuls f12,f2,f9
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f9.f64));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f9,f4,f11
	ctx.f9.f64 = double(float(ctx.f4.f64 * ctx.f11.f64));
	// stfs f9,164(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lwz r11,164(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// fmuls f8,f2,f5
	ctx.f8.f64 = double(float(ctx.f2.f64 * ctx.f5.f64));
	// fmuls f7,f2,f3
	ctx.f7.f64 = double(float(ctx.f2.f64 * ctx.f3.f64));
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// fmuls f6,f0,f2
	ctx.f6.f64 = double(float(ctx.f0.f64 * ctx.f2.f64));
	// stfs f8,160(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f7,176(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lwz r10,160(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// stfs f6,192(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lwz r9,176(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// lwz r8,192(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 192);
	// stw r4,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r4.u32);
	// stw r6,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r6.u32);
	// stw r5,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r5.u32);
	// stw r11,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r11.u32);
	// stw r10,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// stw r9,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r8,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
loc_820A950C:
	// lwz r11,492(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 492);
	// lwz r10,30208(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 30208);
	// clrlwi r9,r11,24
	ctx.r9.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r8,r11,8,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFF;
	// addi r7,r10,7544
	ctx.r7.s64 = ctx.r10.s64 + 7544;
	// mullw r6,r9,r8
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// mullw r5,r9,r8
	ctx.r5.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// mullw r10,r9,r8
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// mullw r4,r9,r8
	ctx.r4.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// rlwinm r6,r6,24,24,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0xFF;
	// rlwinm r27,r11,8,16,23
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFF00;
	// rlwinm r26,r11,8,16,23
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFF00;
	// rlwinm r5,r5,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFF;
	// rlwinm r8,r11,16,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFF;
	// rlwinm r25,r11,8,16,23
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFF00;
	// rlwinm r24,r10,24,24,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF;
	// rlwinm r4,r4,24,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFF;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// or r7,r6,r27
	ctx.r7.u64 = ctx.r6.u64 | ctx.r27.u64;
	// or r5,r5,r26
	ctx.r5.u64 = ctx.r5.u64 | ctx.r26.u64;
	// mullw r6,r8,r9
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwzx r10,r10,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// mullw r27,r9,r8
	ctx.r27.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// or r4,r4,r25
	ctx.r4.u64 = ctx.r4.u64 | ctx.r25.u64;
	// mullw r26,r9,r8
	ctx.r26.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// rlwinm r23,r11,8,16,23
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFF00;
	// rlwinm r6,r6,24,24,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0xFF;
	// rlwinm r27,r27,24,24,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 24) & 0xFF;
	// rlwinm r26,r26,24,24,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 24) & 0xFF;
	// rlwinm r7,r7,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r5,r5,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r4,r4,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r11,r11,24,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFF;
	// mullw r8,r9,r8
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// or r25,r24,r23
	ctx.r25.u64 = ctx.r24.u64 | ctx.r23.u64;
	// or r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r5,r5,r27
	ctx.r5.u64 = ctx.r5.u64 | ctx.r27.u64;
	// or r4,r4,r26
	ctx.r4.u64 = ctx.r4.u64 | ctx.r26.u64;
	// mullw r6,r11,r9
	ctx.r6.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r9.s32);
	// mullw r27,r9,r11
	ctx.r27.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// mullw r26,r9,r11
	ctx.r26.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// rlwinm r25,r25,8,0,23
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r8,r8,24,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF;
	// mullw r11,r9,r11
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// rlwinm r9,r7,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r25,r8
	ctx.r8.u64 = ctx.r25.u64 | ctx.r8.u64;
	// rlwinm r7,r6,24,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0xFF;
	// rlwinm r6,r5,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r5,r27,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 24) & 0xFF;
	// rlwinm r27,r26,24,24,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 24) & 0xFF;
	// rlwinm r4,r4,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r11,r11,24,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFF;
	// or r26,r9,r7
	ctx.r26.u64 = ctx.r9.u64 | ctx.r7.u64;
	// or r25,r6,r5
	ctx.r25.u64 = ctx.r6.u64 | ctx.r5.u64;
	// or r24,r4,r27
	ctx.r24.u64 = ctx.r4.u64 | ctx.r27.u64;
	// or r23,r8,r11
	ctx.r23.u64 = ctx.r8.u64 | ctx.r11.u64;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// bgt cr6,0x820a9ad0
	if (ctx.cr6.gt) goto loc_820A9AD0;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f30,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f30.f64 = double(temp.f32);
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lfs f29,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f29.f64 = double(temp.f32);
	// lfs f28,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f28.f64 = double(temp.f32);
	// lfs f27,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f27.f64 = double(temp.f32);
	// addi r27,r11,-22952
	ctx.r27.s64 = ctx.r11.s64 + -22952;
	// lfs f31,9540(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9540);
	ctx.f31.f64 = double(temp.f32);
	// lis r12,-32245
	ctx.r12.s64 = -2113208320;
	// addi r12,r12,-27084
	ctx.r12.s64 = ctx.r12.s64 + -27084;
	// rlwinm r0,r10,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r10.u32) {
	case 0:
		goto loc_820A99F4;
	case 1:
		goto loc_820A99F4;
	case 2:
		goto loc_820A96CC;
	case 3:
		goto loc_820A99F4;
	case 4:
		goto loc_820A9AD0;
	case 5:
		goto loc_820A99F4;
	case 6:
		goto loc_820A96CC;
	case 7:
		goto loc_820A99F4;
	case 8:
		goto loc_820A99F4;
	case 9:
		goto loc_820A99F4;
	case 10:
		goto loc_820A9724;
	case 11:
		goto loc_820A98C8;
	case 12:
		goto loc_820A99F4;
	case 13:
		goto loc_820A9AD0;
	case 14:
		goto loc_820A9678;
	case 15:
		goto loc_820A96CC;
	case 16:
		goto loc_820A99F4;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_820A9678:
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// fsubs f0,f28,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f28.f64 - ctx.f29.f64));
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// fsubs f13,f27,f30
	ctx.f13.f64 = double(float(ctx.f27.f64 - ctx.f30.f64));
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r5,r10,-22844
	ctx.r5.s64 = ctx.r10.s64 + -22844;
	// rldicr r7,r7,60,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 60) & 0xFFFFFFFFFFFFFFFF;
	// stfs f0,-22852(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + -22852, temp.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// stfs f13,-22844(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + -22844, temp.u32);
	// li r4,12
	ctx.r4.s64 = 12;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r21,r11,-22852
	ctx.r21.s64 = ctx.r11.s64 + -22852;
	// bl 0x820bfb50
	ctx.lr = 0x820A96B0;
	sub_820BFB50(ctx, base);
	// li r7,3
	ctx.r7.s64 = 3;
	// mr r5,r21
	ctx.r5.u64 = ctx.r21.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// rldicr r7,r7,60,3
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 60) & 0xF000000000000000;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r4,11
	ctx.r4.s64 = 11;
	// bl 0x820bfb50
	ctx.lr = 0x820A96CC;
	sub_820BFB50(ctx, base);
loc_820A96CC:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stfs f31,36(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r27.u32 + 36, temp.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stfs f31,60(r27)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r27.u32 + 60, temp.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stfs f31,64(r27)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r27.u32 + 64, temp.u32);
	// stfs f31,88(r27)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r27.u32 + 88, temp.u32);
	// lfs f0,9536(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,9604(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9604);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9788(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9788);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,0(r27)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// stfs f0,4(r27)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + 4, temp.u32);
	// stfs f0,12(r27)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + 12, temp.u32);
	// stfs f0,16(r27)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + 16, temp.u32);
	// stfs f13,24(r27)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r27.u32 + 24, temp.u32);
	// stfs f0,28(r27)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + 28, temp.u32);
	// stfs f0,40(r27)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + 40, temp.u32);
	// stfs f13,48(r27)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r27.u32 + 48, temp.u32);
	// stfs f12,52(r27)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r27.u32 + 52, temp.u32);
	// stfs f0,72(r27)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + 72, temp.u32);
	// stfs f12,76(r27)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r27.u32 + 76, temp.u32);
	// stfs f0,84(r27)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + 84, temp.u32);
loc_820A9724:
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// addi r10,r27,4
	ctx.r10.s64 = ctx.r27.s64 + 4;
	// addi r6,r11,-22840
	ctx.r6.s64 = ctx.r11.s64 + -22840;
	// addi r11,r6,20
	ctx.r11.s64 = ctx.r6.s64 + 20;
loc_820A9734:
	// lfs f0,-4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r6,148
	ctx.r9.s64 = ctx.r6.s64 + 148;
	// lfs f13,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,12(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// stfs f0,-20(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + -20, temp.u32);
	// stfs f13,-16(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + -16, temp.u32);
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stfs f11,4(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x820a9734
	if (ctx.cr6.lt) goto loc_820A9734;
	// lfs f0,32(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,484(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 484);
	// lfs f13,0(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f26,f28,f0
	ctx.f26.f64 = double(float(ctx.f28.f64 - ctx.f0.f64));
	// fsubs f7,f0,f13
	ctx.f7.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f11,4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,68(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 68);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f24,f30,f11
	ctx.f24.f64 = double(float(ctx.f30.f64 - ctx.f11.f64));
	// fsubs f5,f12,f11
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// stfs f30,4(r6)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// fsubs f25,f29,f13
	ctx.f25.f64 = double(float(ctx.f29.f64 - ctx.f13.f64));
	// lfs f6,100(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 100);
	ctx.f6.f64 = double(temp.f32);
	// stfs f29,0(r6)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// fsubs f22,f27,f6
	ctx.f22.f64 = double(float(ctx.f27.f64 - ctx.f6.f64));
	// lfs f0,64(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// li r7,32
	ctx.r7.s64 = 32;
	// lfs f13,36(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// li r5,4
	ctx.r5.s64 = 4;
	// lfs f9,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// li r4,13
	ctx.r4.s64 = 13;
	// lfs f8,148(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f23,f9,f0
	ctx.f23.f64 = double(float(ctx.f9.f64 - ctx.f0.f64));
	// fsubs f21,f8,f13
	ctx.f21.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// lfs f13,20(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fabs f2,f7
	ctx.f2.u64 = ctx.f7.u64 & ~0x8000000000000000;
	// lfs f11,96(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f10.f64 = double(temp.f32);
	// fabs f30,f5
	ctx.f30.u64 = ctx.f5.u64 & ~0x8000000000000000;
	// lfs f7,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f7.f64 = double(temp.f32);
	// lfs f4,24(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f29,f10,f11
	ctx.f29.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// lfs f1,120(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 120);
	ctx.f1.f64 = double(temp.f32);
	// lfs f6,52(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 52);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,84(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 84);
	ctx.f5.f64 = double(temp.f32);
	// lfs f3,56(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 56);
	ctx.f3.f64 = double(temp.f32);
	// lfs f11,116(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 116);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,0(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f20,f31,f2
	ctx.f20.f64 = double(float(ctx.f31.f64 / ctx.f2.f64));
	// lfs f2,88(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 88);
	ctx.f2.f64 = double(temp.f32);
	// stfs f0,8(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// fdivs f31,f31,f30
	ctx.f31.f64 = double(float(ctx.f31.f64 / ctx.f30.f64));
	// fsubs f30,f7,f12
	ctx.f30.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fmadds f13,f25,f20,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f25.f64, ctx.f20.f64, ctx.f13.f64)));
	// stfs f13,20(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 20, temp.u32);
	// fmadds f12,f29,f20,f11
	ctx.f12.f64 = double(float(std::fma(ctx.f29.f64, ctx.f20.f64, ctx.f11.f64)));
	// stfs f12,116(r6)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r6.u32 + 116, temp.u32);
	// fmadds f13,f24,f31,f4
	ctx.f13.f64 = double(float(std::fma(ctx.f24.f64, ctx.f31.f64, ctx.f4.f64)));
	// stfs f13,24(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 24, temp.u32);
	// fmadds f13,f22,f31,f1
	ctx.f13.f64 = double(float(std::fma(ctx.f22.f64, ctx.f31.f64, ctx.f1.f64)));
	// stfs f13,120(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 120, temp.u32);
	// fmadds f13,f26,f20,f6
	ctx.f13.f64 = double(float(std::fma(ctx.f26.f64, ctx.f20.f64, ctx.f6.f64)));
	// stfs f13,52(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 52, temp.u32);
	// fmadds f13,f23,f20,f5
	ctx.f13.f64 = double(float(std::fma(ctx.f23.f64, ctx.f20.f64, ctx.f5.f64)));
	// stfs f13,84(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 84, temp.u32);
	// fmadds f13,f21,f31,f3
	ctx.f13.f64 = double(float(std::fma(ctx.f21.f64, ctx.f31.f64, ctx.f3.f64)));
	// stfs f13,56(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 56, temp.u32);
	// fmadds f13,f30,f31,f2
	ctx.f13.f64 = double(float(std::fma(ctx.f30.f64, ctx.f31.f64, ctx.f2.f64)));
	// stfs f13,88(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 88, temp.u32);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,12(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 12, temp.u32);
	// lfs f13,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stw r26,28(r6)
	REX_STORE_U32(ctx.r6.u32 + 28, ctx.r26.u32);
	// stfs f13,16(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 16, temp.u32);
	// stfs f28,32(r6)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r6.u32 + 32, temp.u32);
	// stfs f8,36(r6)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r6.u32 + 36, temp.u32);
	// stfs f0,40(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 40, temp.u32);
	// lfs f13,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,44(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 44, temp.u32);
	// lfs f13,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stw r25,60(r6)
	REX_STORE_U32(ctx.r6.u32 + 60, ctx.r25.u32);
	// stfs f13,48(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 48, temp.u32);
	// stfs f9,64(r6)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r6.u32 + 64, temp.u32);
	// stfs f7,68(r6)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r6.u32 + 68, temp.u32);
	// stfs f0,72(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 72, temp.u32);
	// lfs f13,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,76(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 76, temp.u32);
	// lfs f13,4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stw r24,92(r6)
	REX_STORE_U32(ctx.r6.u32 + 92, ctx.r24.u32);
	// stfs f13,80(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 80, temp.u32);
	// stfs f10,96(r6)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r6.u32 + 96, temp.u32);
	// stfs f27,100(r6)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r6.u32 + 100, temp.u32);
	// stfs f0,104(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 104, temp.u32);
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 108, temp.u32);
	// lfs f0,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stw r23,124(r6)
	REX_STORE_U32(ctx.r6.u32 + 124, ctx.r23.u32);
	// stfs f0,112(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 112, temp.u32);
	// b 0x820a9ac8
	goto loc_820A9AC8;
loc_820A98C8:
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,484(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 484);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// addi r9,r10,-22952
	ctx.r9.s64 = ctx.r10.s64 + -22952;
	// ble cr6,0x820a996c
	if (!ctx.cr6.gt) goto loc_820A996C;
	// lfs f12,148(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,4(r9)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f13,-22952(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + -22952, temp.u32);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,12(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// lfs f13,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,16(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 16, temp.u32);
	// lfs f11,132(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,28(r9)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r9.u32 + 28, temp.u32);
	// stfs f0,24(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24, temp.u32);
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,36(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 36, temp.u32);
	// lfs f0,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f10,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,48(r9)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r9.u32 + 48, temp.u32);
	// stfs f0,40(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 40, temp.u32);
	// lfs f9,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,52(r9)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r9.u32 + 52, temp.u32);
	// lfs f8,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// lfs f12,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,60(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 60, temp.u32);
	// lfs f0,4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,64(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 64, temp.u32);
	// stfs f8,72(r9)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r9.u32 + 72, temp.u32);
	// stfs f12,76(r9)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r9.u32 + 76, temp.u32);
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 84, temp.u32);
	// lfs f0,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,88(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 88, temp.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// addi r12,r1,-96
	ctx.r12.s64 = ctx.r1.s64 + -96;
	// bl 0x8212a884
	ctx.lr = 0x820A9968;
	__restfpr_20(ctx, base);
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
loc_820A996C:
	// lfs f12,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,4(r9)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f0,-22952(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -22952, temp.u32);
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,12(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// lfs f0,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,16(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16, temp.u32);
	// lfs f11,148(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f11.f64 = double(temp.f32);
	// stfs f13,24(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 24, temp.u32);
	// stfs f11,28(r9)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r9.u32 + 28, temp.u32);
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,36(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 36, temp.u32);
	// lfs f0,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,40(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 40, temp.u32);
	// lfs f10,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// stfs f10,48(r9)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r9.u32 + 48, temp.u32);
	// stfs f9,52(r9)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r9.u32 + 52, temp.u32);
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,60(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 60, temp.u32);
	// lfs f0,4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f8,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f8.f64 = double(temp.f32);
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,64(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 64, temp.u32);
	// stfs f8,76(r9)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r9.u32 + 76, temp.u32);
	// stfs f12,72(r9)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r9.u32 + 72, temp.u32);
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 84, temp.u32);
	// lfs f0,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,88(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 88, temp.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// addi r12,r1,-96
	ctx.r12.s64 = ctx.r1.s64 + -96;
	// bl 0x8212a884
	ctx.lr = 0x820A99F0;
	__restfpr_20(ctx, base);
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
loc_820A99F4:
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f0,0(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// add r8,r3,r11
	ctx.r8.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lfs f12,132(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r10,29656
	ctx.r9.s64 = ctx.r10.s64 + 29656;
	// lfs f11,148(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r8,r8,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// lfs f10,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f8.f64 = double(temp.f32);
	// lwz r10,484(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 484);
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lfs f9,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f7.f64 = double(temp.f32);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// lfs f6,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f6.f64 = double(temp.f32);
	// li r7,24
	ctx.r7.s64 = 24;
	// stfsx f13,r8,r9
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + ctx.r9.u32, temp.u32);
	// stw r11,-22588(r21)
	REX_STORE_U32(ctx.r21.u32 + -22588, ctx.r11.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// stfs f0,8(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// li r4,13
	ctx.r4.s64 = 13;
	// stfs f12,4(r6)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// lfs f5,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,12(r6)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r6.u32 + 12, temp.u32);
	// lfs f4,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// stw r26,20(r6)
	REX_STORE_U32(ctx.r6.u32 + 20, ctx.r26.u32);
	// stfs f11,28(r6)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r6.u32 + 28, temp.u32);
	// stfs f4,16(r6)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r6.u32 + 16, temp.u32);
	// stfs f10,24(r6)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r6.u32 + 24, temp.u32);
	// stfs f0,32(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 32, temp.u32);
	// lfs f3,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,36(r6)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r6.u32 + 36, temp.u32);
	// lfs f2,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// stw r25,44(r6)
	REX_STORE_U32(ctx.r6.u32 + 44, ctx.r25.u32);
	// stfs f2,40(r6)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r6.u32 + 40, temp.u32);
	// stfs f8,52(r6)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r6.u32 + 52, temp.u32);
	// stfs f0,56(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 56, temp.u32);
	// stfs f9,48(r6)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r6.u32 + 48, temp.u32);
	// lfs f1,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,60(r6)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r6.u32 + 60, temp.u32);
	// lfs f13,4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stw r24,68(r6)
	REX_STORE_U32(ctx.r6.u32 + 68, ctx.r24.u32);
	// stfs f0,80(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 80, temp.u32);
	// stfs f13,64(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 64, temp.u32);
	// stfs f7,72(r6)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r6.u32 + 72, temp.u32);
	// stfs f6,76(r6)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r6.u32 + 76, temp.u32);
	// lfs f12,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,84(r6)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r6.u32 + 84, temp.u32);
	// lfs f11,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// stw r23,92(r6)
	REX_STORE_U32(ctx.r6.u32 + 92, ctx.r23.u32);
	// stfs f11,88(r6)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r6.u32 + 88, temp.u32);
loc_820A9AC8:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820c1980
	ctx.lr = 0x820A9AD0;
	sub_820C1980(ctx, base);
loc_820A9AD0:
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// addi r12,r1,-96
	ctx.r12.s64 = ctx.r1.s64 + -96;
	// bl 0x8212a884
	ctx.lr = 0x820A9ADC;
	__restfpr_20(ctx, base);
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
