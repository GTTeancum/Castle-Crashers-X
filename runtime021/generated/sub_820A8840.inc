DEFINE_REX_FUNC(sub_820A8840) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,28715(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 28715);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a8948
	if (ctx.cr6.eq) goto loc_820A8948;
	// fneg f10,f6
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = ctx.f6.u64 ^ 0x8000000000000000;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// fneg f11,f5
	ctx.f11.u64 = ctx.f5.u64 ^ 0x8000000000000000;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// fsubs f9,f2,f1
	ctx.f9.f64 = double(float(ctx.f2.f64 - ctx.f1.f64));
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// fsubs f8,f3,f4
	ctx.f8.f64 = double(float(ctx.f3.f64 - ctx.f4.f64));
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// fadds f6,f3,f4
	ctx.f6.f64 = double(float(ctx.f3.f64 + ctx.f4.f64));
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_set1_epi32(int(0x0)));
	// lfs f0,9540(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// fadds f7,f1,f2
	ctx.f7.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f13,9632(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9632);
	ctx.f13.f64 = double(temp.f32);
	// lis r7,-32215
	ctx.r7.s64 = -2111242240;
	// lfs f12,9536(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9536);
	ctx.f12.f64 = double(temp.f32);
	// vor128 v63,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// vor128 v62,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r9,r7,528
	ctx.r9.s64 = ctx.r7.s64 + 528;
	// fsubs f5,f10,f11
	ctx.f5.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// li r8,32
	ctx.r8.s64 = 32;
	// fdivs f4,f0,f9
	ctx.f4.f64 = double(float(ctx.f0.f64 / ctx.f9.f64));
	// li r31,48
	ctx.r31.s64 = 48;
	// fdivs f3,f0,f8
	ctx.f3.f64 = double(float(ctx.f0.f64 / ctx.f8.f64));
	// li r30,16
	ctx.r30.s64 = 16;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
	// rldicr r7,r7,63,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// fdivs f2,f0,f5
	ctx.f2.f64 = double(float(ctx.f0.f64 / ctx.f5.f64));
	// stfs f2,88(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmuls f1,f7,f4
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f4.f64));
	// fmuls f0,f6,f3
	ctx.f0.f64 = double(float(ctx.f6.f64 * ctx.f3.f64));
	// fmuls f12,f4,f13
	ctx.f12.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f10,f3,f13
	ctx.f10.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v61,v60,2,0
	simde_mm_store_ps(ctx.v61.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v60.f32), 228), 2));
	// fmuls f9,f2,f11
	ctx.f9.f64 = double(float(ctx.f2.f64 * ctx.f11.f64));
	// vrlimi128 v63,v60,8,0
	simde_mm_store_ps(ctx.v63.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v60.f32), 228), 8));
	// fneg f8,f1
	ctx.f8.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// vrlimi128 v62,v60,4,0
	simde_mm_store_ps(ctx.v62.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v60.f32), 228), 4));
	// fneg f7,f0
	ctx.f7.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f8,144(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f7,148(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r9,r30
	ea = (ctx.r9.u32 + ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r9,r8
	ea = (ctx.r9.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fneg f6,f9
	ctx.f6.u64 = ctx.f9.u64 ^ 0x8000000000000000;
	// stfs f6,152(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r9,r31
	ea = (ctx.r9.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x820bfa70
	ctx.lr = 0x820A8948;
	sub_820BFA70(ctx, base);
loc_820A8948:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
