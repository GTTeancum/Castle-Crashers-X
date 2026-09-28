DEFINE_REX_FUNC(sub_820DDCD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x820DDCD8;
	__savegprlr_21(ctx, base);
	// addi r12,r1,-96
	ctx.r12.s64 = ctx.r1.s64 + -96;
	// bl 0x8212a854
	ctx.lr = 0x820DDCE0;
	__savefpr_27(ctx, base);
	// lwz r10,16(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// addi r11,r3,24
	ctx.r11.s64 = ctx.r3.s64 + 24;
	// lwz r6,0(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r10,2
	ctx.r9.s64 = ctx.r10.s64 + 2;
	// lfs f13,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// subf r10,r6,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r6.u64;
	// lfs f12,12(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
loc_820DDD10:
	// addi r7,r10,-2
	ctx.r7.s64 = ctx.r10.s64 + -2;
	// lfs f11,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// lfs f10,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r7,r7,2,23,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x1FC;
	// lfs f9,8(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// rlwinm r5,r5,2,23,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x1FC;
	// lfs f8,12(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// rlwinm r31,r10,2,23,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x1FC;
	// lfs f7,16(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f7.f64 = double(temp.f32);
	// addi r30,r10,1
	ctx.r30.s64 = ctx.r10.s64 + 1;
	// lfs f6,20(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// addi r29,r10,2
	ctx.r29.s64 = ctx.r10.s64 + 2;
	// lfs f5,24(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f5.f64 = double(temp.f32);
	// lfsx f4,r7,r11
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	ctx.f4.f64 = double(temp.f32);
	// rlwinm r7,r30,2,23,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0x1FC;
	// fmadds f3,f0,f4,f11
	ctx.f3.f64 = double(float(std::fma(ctx.f0.f64, ctx.f4.f64, ctx.f11.f64)));
	// stfs f3,-8(r9)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r9.u32 + -8, temp.u32);
	// lfsx f2,r5,r11
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f1,f0,f2,f10
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f2.f64, ctx.f10.f64)));
	// stfs f1,-4(r9)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r9.u32 + -4, temp.u32);
	// addi r5,r10,3
	ctx.r5.s64 = ctx.r10.s64 + 3;
	// lfsx f11,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r31,r29,2,23,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0x1FC;
	// fmadds f10,f0,f11,f9
	ctx.f10.f64 = double(float(std::fma(ctx.f0.f64, ctx.f11.f64, ctx.f9.f64)));
	// stfs f10,0(r9)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// lfsx f9,r7,r11
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	ctx.f9.f64 = double(temp.f32);
	// rlwinm r5,r5,2,23,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x1FC;
	// fmadds f8,f0,f9,f8
	ctx.f8.f64 = double(float(std::fma(ctx.f0.f64, ctx.f9.f64, ctx.f8.f64)));
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// stfs f8,4(r9)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// addi r30,r10,5
	ctx.r30.s64 = ctx.r10.s64 + 5;
	// lfsx f31,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f31.f64 = double(temp.f32);
	// rlwinm r7,r7,2,23,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x1FC;
	// fmadds f7,f0,f31,f7
	ctx.f7.f64 = double(float(std::fma(ctx.f0.f64, ctx.f31.f64, ctx.f7.f64)));
	// stfs f7,8(r9)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// lfsx f30,r5,r11
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	ctx.f30.f64 = double(temp.f32);
	// rlwinm r5,r30,2,23,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0x1FC;
	// fmadds f6,f0,f30,f6
	ctx.f6.f64 = double(float(std::fma(ctx.f0.f64, ctx.f30.f64, ctx.f6.f64)));
	// stfs f6,12(r9)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// lfsx f29,r7,r11
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	ctx.f29.f64 = double(temp.f32);
	// fmadds f5,f0,f29,f5
	ctx.f5.f64 = double(float(std::fma(ctx.f0.f64, ctx.f29.f64, ctx.f5.f64)));
	// lfs f28,28(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 28);
	ctx.f28.f64 = double(temp.f32);
	// addi r7,r4,28
	ctx.r7.s64 = ctx.r4.s64 + 28;
	// stfs f5,16(r9)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r9.u32 + 16, temp.u32);
	// fmadds f4,f13,f3,f4
	ctx.f4.f64 = double(float(std::fma(ctx.f13.f64, ctx.f3.f64, ctx.f4.f64)));
	// lfsx f27,r5,r11
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	ctx.f27.f64 = double(temp.f32);
	// fmadds f28,f0,f27,f28
	ctx.f28.f64 = double(float(std::fma(ctx.f0.f64, ctx.f27.f64, ctx.f28.f64)));
	// fmadds f3,f13,f1,f2
	ctx.f3.f64 = double(float(std::fma(ctx.f13.f64, ctx.f1.f64, ctx.f2.f64)));
	// stfs f12,0(r4)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fmadds f2,f13,f10,f11
	ctx.f2.f64 = double(float(std::fma(ctx.f13.f64, ctx.f10.f64, ctx.f11.f64)));
	// stfs f28,20(r9)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r9.u32 + 20, temp.u32);
	// fmadds f1,f13,f8,f9
	ctx.f1.f64 = double(float(std::fma(ctx.f13.f64, ctx.f8.f64, ctx.f9.f64)));
	// stfs f4,4(r4)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// fmadds f11,f13,f7,f31
	ctx.f11.f64 = double(float(std::fma(ctx.f13.f64, ctx.f7.f64, ctx.f31.f64)));
	// stfs f3,8(r4)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// fmadds f10,f13,f6,f30
	ctx.f10.f64 = double(float(std::fma(ctx.f13.f64, ctx.f6.f64, ctx.f30.f64)));
	// stfs f2,12(r4)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r4.u32 + 12, temp.u32);
	// stfs f1,16(r4)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r4.u32 + 16, temp.u32);
	// fmadds f9,f13,f5,f29
	ctx.f9.f64 = double(float(std::fma(ctx.f13.f64, ctx.f5.f64, ctx.f29.f64)));
	// stfs f11,20(r4)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r4.u32 + 20, temp.u32);
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stfs f10,24(r4)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r4.u32 + 24, temp.u32);
	// fmadds f12,f13,f28,f27
	ctx.f12.f64 = double(float(std::fma(ctx.f13.f64, ctx.f28.f64, ctx.f27.f64)));
	// stfs f9,0(r7)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// addi r4,r4,32
	ctx.r4.s64 = ctx.r4.s64 + 32;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// bne 0x820ddd10
	if (!ctx.cr0.eq) goto loc_820DDD10;
	// neg r7,r6
	ctx.r7.s64 = static_cast<int64_t>(-ctx.r6.u64);
	// subfic r9,r6,2
	ctx.xer.ca = ctx.r6.u32 <= 2;
	ctx.r9.u64 = static_cast<uint64_t>(2) - ctx.r6.u64;
	// addi r10,r11,8
	ctx.r10.s64 = ctx.r11.s64 + 8;
	// li r8,16
	ctx.r8.s64 = 16;
loc_820DDE34:
	// rlwinm r6,r7,2,23,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x1FC;
	// lfs f11,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r9,-1
	ctx.r5.s64 = ctx.r9.s64 + -1;
	// stfs f12,0(r4)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// rlwinm r27,r9,2,23,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x1FC;
	// lfs f10,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r26,r5,2,23,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x1FC;
	// lfs f9,8(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// lfs f8,12(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// lfsx f6,r6,r11
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	ctx.f6.f64 = double(temp.f32);
	// addi r6,r9,2
	ctx.r6.s64 = ctx.r9.s64 + 2;
	// fmadds f5,f0,f6,f11
	ctx.f5.f64 = double(float(std::fma(ctx.f0.f64, ctx.f6.f64, ctx.f11.f64)));
	// stfs f5,-8(r10)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r10.u32 + -8, temp.u32);
	// rlwinm r25,r5,2,23,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x1FC;
	// lfs f7,16(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r24,r6,2,23,29
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x1FC;
	// lfs f4,20(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f4.f64 = double(temp.f32);
	// addi r6,r9,4
	ctx.r6.s64 = ctx.r9.s64 + 4;
	// lfs f3,24(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f3.f64 = double(temp.f32);
	// addi r5,r9,3
	ctx.r5.s64 = ctx.r9.s64 + 3;
	// rlwinm r22,r6,2,23,29
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x1FC;
	// addi r6,r4,8
	ctx.r6.s64 = ctx.r4.s64 + 8;
	// rlwinm r23,r5,2,23,29
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x1FC;
	// addi r5,r9,5
	ctx.r5.s64 = ctx.r9.s64 + 5;
	// addi r28,r4,28
	ctx.r28.s64 = ctx.r4.s64 + 28;
	// fmadds f2,f13,f5,f6
	ctx.f2.f64 = double(float(std::fma(ctx.f13.f64, ctx.f5.f64, ctx.f6.f64)));
	// stfs f2,4(r4)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// rlwinm r21,r5,2,23,29
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x1FC;
	// addi r5,r4,12
	ctx.r5.s64 = ctx.r4.s64 + 12;
	// addi r31,r4,16
	ctx.r31.s64 = ctx.r4.s64 + 16;
	// lfs f1,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// addi r30,r4,20
	ctx.r30.s64 = ctx.r4.s64 + 20;
	// addi r29,r4,24
	ctx.r29.s64 = ctx.r4.s64 + 24;
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// addi r4,r4,32
	ctx.r4.s64 = ctx.r4.s64 + 32;
	// addi r7,r7,8
	ctx.r7.s64 = ctx.r7.s64 + 8;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// lfsx f12,r26,r11
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + ctx.r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f0,f12,f10
	ctx.f11.f64 = double(float(std::fma(ctx.f0.f64, ctx.f12.f64, ctx.f10.f64)));
	// stfs f11,-4(r10)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r10.u32 + -4, temp.u32);
	// lfsx f6,r27,r11
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f5,f0,f6,f9
	ctx.f5.f64 = double(float(std::fma(ctx.f0.f64, ctx.f6.f64, ctx.f9.f64)));
	// stfs f5,0(r10)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fmadds f10,f13,f11,f12
	ctx.f10.f64 = double(float(std::fma(ctx.f13.f64, ctx.f11.f64, ctx.f12.f64)));
	// stfs f10,0(r6)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// fmadds f11,f13,f5,f6
	ctx.f11.f64 = double(float(std::fma(ctx.f13.f64, ctx.f5.f64, ctx.f6.f64)));
	// stfs f11,0(r5)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// lfsx f2,r25,r11
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + ctx.r11.u32);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f12,f0,f2,f8
	ctx.f12.f64 = double(float(std::fma(ctx.f0.f64, ctx.f2.f64, ctx.f8.f64)));
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// fmadds f8,f13,f12,f2
	ctx.f8.f64 = double(float(std::fma(ctx.f13.f64, ctx.f12.f64, ctx.f2.f64)));
	// stfs f8,0(r31)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// lfsx f10,r24,r11
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + ctx.r11.u32);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f9,f0,f10,f7
	ctx.f9.f64 = double(float(std::fma(ctx.f0.f64, ctx.f10.f64, ctx.f7.f64)));
	// stfs f9,8(r10)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lfsx f6,r23,r11
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + ctx.r11.u32);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f5,f0,f6,f4
	ctx.f5.f64 = double(float(std::fma(ctx.f0.f64, ctx.f6.f64, ctx.f4.f64)));
	// stfs f5,12(r10)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// fmadds f7,f13,f9,f10
	ctx.f7.f64 = double(float(std::fma(ctx.f13.f64, ctx.f9.f64, ctx.f10.f64)));
	// lfsx f4,r22,r11
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + ctx.r11.u32);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f3,f0,f4,f3
	ctx.f3.f64 = double(float(std::fma(ctx.f0.f64, ctx.f4.f64, ctx.f3.f64)));
	// stfs f3,16(r10)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// fmadds f2,f13,f5,f6
	ctx.f2.f64 = double(float(std::fma(ctx.f13.f64, ctx.f5.f64, ctx.f6.f64)));
	// lfsx f12,r21,r11
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + ctx.r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f0,f12,f1
	ctx.f11.f64 = double(float(std::fma(ctx.f0.f64, ctx.f12.f64, ctx.f1.f64)));
	// stfs f11,20(r10)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r10.u32 + 20, temp.u32);
	// fmadds f10,f13,f3,f4
	ctx.f10.f64 = double(float(std::fma(ctx.f13.f64, ctx.f3.f64, ctx.f4.f64)));
	// stfs f7,0(r30)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// fmadds f12,f13,f11,f12
	ctx.f12.f64 = double(float(std::fma(ctx.f13.f64, ctx.f11.f64, ctx.f12.f64)));
	// stfs f2,0(r29)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// stfs f10,0(r28)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// bne 0x820dde34
	if (!ctx.cr0.eq) goto loc_820DDE34;
	// li r11,0
	ctx.r11.s64 = 0;
	// stfs f12,12(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f12,0(r4)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// stw r11,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// addi r12,r1,-96
	ctx.r12.s64 = ctx.r1.s64 + -96;
	// bl 0x8212a8a0
	ctx.lr = 0x820DDF74;
	__restfpr_27(ctx, base);
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
