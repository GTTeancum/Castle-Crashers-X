DEFINE_REX_FUNC(sub_820DE040) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x820DE048;
	__savegprlr_29(ctx, base);
	// addi r12,r1,-32
	ctx.r12.s64 = ctx.r1.s64 + -32;
	// bl 0x8212a854
	ctx.lr = 0x820DE050;
	__savefpr_27(ctx, base);
	// lwz r7,16(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// addi r9,r3,24
	ctx.r9.s64 = ctx.r3.s64 + 24;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r7,2
	ctx.r10.s64 = ctx.r7.s64 + 2;
	// lfs f13,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// subf r11,r11,r7
	ctx.r11.u64 = ctx.r7.u64 - ctx.r11.u64;
	// lfs f12,12(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// li r8,32
	ctx.r8.s64 = 32;
	// add r11,r6,r9
	ctx.r11.u64 = ctx.r6.u64 + ctx.r9.u64;
	// addi r7,r7,256
	ctx.r7.s64 = ctx.r7.s64 + 256;
loc_820DE084:
	// addi r6,r10,-2
	ctx.r6.s64 = ctx.r10.s64 + -2;
	// lfs f11,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// lfs f10,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r6,r6,2,22,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3FC;
	// lfs f9,8(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// rlwinm r5,r5,2,22,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x3FC;
	// lfs f8,12(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// rlwinm r31,r10,2,22,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x3FC;
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
	// lfsx f4,r6,r9
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	ctx.f4.f64 = double(temp.f32);
	// rlwinm r6,r30,2,22,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0x3FC;
	// fmadds f3,f0,f4,f11
	ctx.f3.f64 = double(float(std::fma(ctx.f0.f64, ctx.f4.f64, ctx.f11.f64)));
	// stfs f3,-8(r11)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r11.u32 + -8, temp.u32);
	// lfsx f2,r5,r9
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f1,f0,f2,f10
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f2.f64, ctx.f10.f64)));
	// stfs f1,-4(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// addi r5,r10,3
	ctx.r5.s64 = ctx.r10.s64 + 3;
	// lfsx f10,r31,r9
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r31,r29,2,22,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0x3FC;
	// fmadds f9,f0,f10,f9
	ctx.f9.f64 = double(float(std::fma(ctx.f0.f64, ctx.f10.f64, ctx.f9.f64)));
	// stfs f9,0(r11)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfsx f31,r6,r9
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	ctx.f31.f64 = double(temp.f32);
	// rlwinm r5,r5,2,22,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x3FC;
	// fmadds f8,f0,f31,f8
	ctx.f8.f64 = double(float(std::fma(ctx.f0.f64, ctx.f31.f64, ctx.f8.f64)));
	// addi r6,r10,4
	ctx.r6.s64 = ctx.r10.s64 + 4;
	// stfs f8,4(r11)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// addi r30,r10,5
	ctx.r30.s64 = ctx.r10.s64 + 5;
	// lfsx f30,r31,r9
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	ctx.f30.f64 = double(temp.f32);
	// fmadds f7,f0,f30,f7
	ctx.f7.f64 = double(float(std::fma(ctx.f0.f64, ctx.f30.f64, ctx.f7.f64)));
	// rlwinm r6,r6,2,22,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3FC;
	// stfs f7,8(r11)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// lfsx f29,r5,r9
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	ctx.f29.f64 = double(temp.f32);
	// rlwinm r5,r30,2,22,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0x3FC;
	// fmadds f6,f0,f29,f6
	ctx.f6.f64 = double(float(std::fma(ctx.f0.f64, ctx.f29.f64, ctx.f6.f64)));
	// stfs f6,12(r11)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// lfsx f28,r6,r9
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	ctx.f28.f64 = double(temp.f32);
	// fmadds f5,f0,f28,f5
	ctx.f5.f64 = double(float(std::fma(ctx.f0.f64, ctx.f28.f64, ctx.f5.f64)));
	// lfs f11,28(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f4,f13,f3,f4
	ctx.f4.f64 = double(float(std::fma(ctx.f13.f64, ctx.f3.f64, ctx.f4.f64)));
	// stfs f5,16(r11)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// fmadds f2,f13,f1,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f13.f64, ctx.f1.f64, ctx.f2.f64)));
	// lfsx f3,r5,r9
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f27,f0,f3,f11
	ctx.f27.f64 = double(float(std::fma(ctx.f0.f64, ctx.f3.f64, ctx.f11.f64)));
	// fmadds f11,f13,f27,f3
	ctx.f11.f64 = double(float(std::fma(ctx.f13.f64, ctx.f27.f64, ctx.f3.f64)));
	// stfs f12,0(r4)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fmadds f1,f13,f9,f10
	ctx.f1.f64 = double(float(std::fma(ctx.f13.f64, ctx.f9.f64, ctx.f10.f64)));
	// stfs f4,4(r4)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// fmadds f12,f13,f8,f31
	ctx.f12.f64 = double(float(std::fma(ctx.f13.f64, ctx.f8.f64, ctx.f31.f64)));
	// stfs f12,16(r4)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r4.u32 + 16, temp.u32);
	// fmadds f10,f13,f7,f30
	ctx.f10.f64 = double(float(std::fma(ctx.f13.f64, ctx.f7.f64, ctx.f30.f64)));
	// stfs f2,8(r4)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// fmadds f9,f13,f6,f29
	ctx.f9.f64 = double(float(std::fma(ctx.f13.f64, ctx.f6.f64, ctx.f29.f64)));
	// stfs f1,12(r4)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r4.u32 + 12, temp.u32);
	// fmadds f8,f13,f5,f28
	ctx.f8.f64 = double(float(std::fma(ctx.f13.f64, ctx.f5.f64, ctx.f28.f64)));
	// stfs f10,20(r4)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r4.u32 + 20, temp.u32);
	// stfs f9,24(r4)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r4.u32 + 24, temp.u32);
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stfs f8,28(r4)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r4.u32 + 28, temp.u32);
	// addi r4,r4,32
	ctx.r4.s64 = ctx.r4.s64 + 32;
	// stfs f27,20(r11)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// fmr f12,f11
	ctx.f12.f64 = ctx.f11.f64;
	// bne 0x820de084
	if (!ctx.cr0.eq) goto loc_820DE084;
	// clrlwi r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	// stfs f11,12(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f11,0(r4)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// stw r11,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// addi r12,r1,-32
	ctx.r12.s64 = ctx.r1.s64 + -32;
	// bl 0x8212a8a0
	ctx.lr = 0x820DE1B0;
	__restfpr_27(ctx, base);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
