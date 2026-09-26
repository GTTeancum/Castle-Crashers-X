DEFINE_REX_FUNC(sub_82085AD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82085AE0;
	__savegprlr_28(ctx, base);
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a84c
	ctx.lr = 0x82085AE8;
	__savefpr_25(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32215
	ctx.r28.s64 = -2111242240;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r11,-22604(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + -22604);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lfs f31,18236(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18236);
	ctx.f31.f64 = double(temp.f32);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lfs f0,9536(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stfs f31,0(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// stb r10,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r10.u8);
	// stfs f31,4(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// stb r10,13(r31)
	REX_STORE_U8(ctx.r31.u32 + 13, ctx.r10.u8);
	// stfs f0,8(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// stb r10,14(r31)
	REX_STORE_U8(ctx.r31.u32 + 14, ctx.r10.u8);
	// stfs f31,16(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 16, temp.u32);
	// stfs f31,20(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// stfs f0,24(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// stfs f0,28(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// stfs f0,32(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// stfs f0,36(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// beq cr6,0x82085b60
	if (ctx.cr6.eq) goto loc_82085B60;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82085c70
	ctx.lr = 0x82085B54;
	sub_82085C70(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82085c70
	ctx.lr = 0x82085B5C;
	sub_82085C70(ctx, base);
	// lbz r11,-22604(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + -22604);
loc_82085B60:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f12,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f10,32(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,20(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lfs f9,36(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 36);
	ctx.f9.f64 = double(temp.f32);
	// clrlwi r7,r11,24
	ctx.r7.u64 = ctx.r11.u32 & 0xFF;
	// lfs f3,16(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 16);
	ctx.f3.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,9572(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9572);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// lfs f13,9588(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9588);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// fmuls f4,f12,f13
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lfs f1,20(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f6,f9,f0
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// lfs f5,28(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f2,f11,f13
	ctx.f2.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// lfs f10,24(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f12,f13
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lfs f12,28(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// lfs f8,24(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 24);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f11,f11,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fmuls f3,f3,f13
	ctx.f3.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// lfs f30,32(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 32);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f1,f1,f13
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
	// lfs f29,36(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 36);
	ctx.f29.f64 = double(temp.f32);
	// fmuls f10,f10,f0
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// lfs f13,9576(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9576);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f27,f5,f0
	ctx.f27.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f4,f4,f7
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f7.f64));
	// fmuls f28,f8,f0
	ctx.f28.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// fmuls f2,f2,f6
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f6.f64));
	// fmuls f5,f5,f0
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// fmuls f8,f8,f0
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// fmuls f26,f3,f9
	ctx.f26.f64 = double(float(ctx.f3.f64 * ctx.f9.f64));
	// fmuls f25,f1,f11
	ctx.f25.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// fmuls f11,f10,f11
	ctx.f11.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// fmuls f9,f12,f9
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f9.f64));
	// fmadds f6,f27,f6,f4
	ctx.f6.f64 = double(float(std::fma(ctx.f27.f64, ctx.f6.f64, ctx.f4.f64)));
	// fmadds f4,f28,f7,f2
	ctx.f4.f64 = double(float(std::fma(ctx.f28.f64, ctx.f7.f64, ctx.f2.f64)));
	// fmadds f2,f10,f5,f26
	ctx.f2.f64 = double(float(std::fma(ctx.f10.f64, ctx.f5.f64, ctx.f26.f64)));
	// fmadds f12,f12,f8,f25
	ctx.f12.f64 = double(float(std::fma(ctx.f12.f64, ctx.f8.f64, ctx.f25.f64)));
	// fmadds f11,f3,f8,f11
	ctx.f11.f64 = double(float(std::fma(ctx.f3.f64, ctx.f8.f64, ctx.f11.f64)));
	// fmadds f10,f1,f5,f9
	ctx.f10.f64 = double(float(std::fma(ctx.f1.f64, ctx.f5.f64, ctx.f9.f64)));
	// fmadds f9,f30,f0,f6
	ctx.f9.f64 = double(float(std::fma(ctx.f30.f64, ctx.f0.f64, ctx.f6.f64)));
	// fmadds f8,f29,f0,f4
	ctx.f8.f64 = double(float(std::fma(ctx.f29.f64, ctx.f0.f64, ctx.f4.f64)));
	// fmuls f7,f2,f31
	ctx.f7.f64 = double(float(ctx.f2.f64 * ctx.f31.f64));
	// stfs f7,16(r31)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r31.u32 + 16, temp.u32);
	// fmuls f6,f12,f31
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f31.f64));
	// stfs f6,20(r31)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// fmuls f5,f11,f13
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// stfs f5,24(r31)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// fmuls f4,f10,f13
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// stfs f4,28(r31)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// fmuls f3,f9,f13
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// stfs f3,32(r31)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// fmuls f2,f8,f13
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// stfs f2,36(r31)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// beq cr6,0x82085c60
	if (ctx.cr6.eq) goto loc_82085C60;
	// bl 0x82085c70
	ctx.lr = 0x82085C5C;
	sub_82085C70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82085C60:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a898
	ctx.lr = 0x82085C6C;
	__restfpr_25(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
