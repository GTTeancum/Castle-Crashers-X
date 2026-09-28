DEFINE_REX_FUNC(sub_820ED920) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x820ED928;
	__savegprlr_22(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// lfs f0,36(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// dcbt r0,r3
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f13,40(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lfs f10,48(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 48);
	ctx.f10.f64 = double(temp.f32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stfs f13,36(r28)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r28.u32 + 36, temp.u32);
	// extsw r10,r6
	ctx.r10.s64 = ctx.r6.s32;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// addi r10,r9,-21328
	ctx.r10.s64 = ctx.r9.s64 + -21328;
	// lfs f11,44(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 44);
	ctx.f11.f64 = double(temp.f32);
	// lfd f0,-21368(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + -21368);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// fmul f8,f10,f0
	ctx.f8.f64 = ctx.f10.f64 * ctx.f0.f64;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// fmul f9,f11,f0
	ctx.f9.f64 = ctx.f11.f64 * ctx.f0.f64;
	// addi r9,r8,-21296
	ctx.r9.s64 = ctx.r8.s64 + -21296;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v9,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r7,-21312
	ctx.r8.s64 = ctx.r7.s64 + -21312;
	// addi r7,r4,-21344
	ctx.r7.s64 = ctx.r4.s64 + -21344;
	// vspltisb v0,7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0x7)));
	// li r11,4
	ctx.r11.s64 = 4;
	// vspltisw128 v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x1)));
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// vor128 v22,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// lvx128 v8,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvx128 v7,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// lvx128 v3,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// fctidz f6,f8
	ctx.f6.s64 = std::isnan(ctx.f8.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f6,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f6.u64);
	// ld r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// fctidz f7,f9
	ctx.f7.s64 = std::isnan(ctx.f9.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// std r10,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r10.u64);
	// stfd f7,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f7.u64);
	// lvlx128 v59,r11,r7
	temp.u32 = ctx.r11.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// ld r29,88(r1)
	ctx.r29.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r29,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r29.u64);
	// lfd f5,96(r1)
	ctx.f5.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// lvlx128 v61,r11,r4
	temp.u32 = ctx.r11.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// vadduwm v11,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), simde_mm_load_si128((simde__m128i*)ctx.v13.u32)));
	// vsldoi128 v58,v62,v13,4
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8), 12));
	// lvlx128 v60,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// vspltw128 v10,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0xFF));
	// lfs f13,9684(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 9684);
	ctx.f13.f64 = double(temp.f32);
	// vadduwm v6,v13,v11
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), simde_mm_load_si128((simde__m128i*)ctx.v11.u32)));
	// li r30,0
	ctx.r30.s64 = 0;
	// vsldoi128 v57,v58,v11,4
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8), 12));
	// vadduwm v13,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), simde_mm_load_si128((simde__m128i*)ctx.v11.u32)));
	// vor128 v24,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// vor128 v21,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// vor128 v23,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// vsldoi128 v6,v57,v6,4
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8), 12));
	// vslb v0,v0,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi8(0x7));
		simde_mm_store_si128((simde__m128i*)ctx.v0.u8, rex::ppc::simde_mm_sllv_epi8(a, shift));
	}
	// fdivs f0,f12,f3
	ctx.f0.f64 = double(float(ctx.f12.f64 / ctx.f3.f64));
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v56,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v11,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.u32), 0xFF));
	// fmuls f2,f0,f13
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f2,88(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// vmaddfp v9,v11,v9,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// lvlx128 v55,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmaddfp v8,v11,v8,v12
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vadduwm v4,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), simde_mm_load_si128((simde__m128i*)ctx.v13.u32)));
	// vmaddfp v7,v11,v7,v12
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vadduwm v5,v6,v13
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v6.u32), simde_mm_load_si128((simde__m128i*)ctx.v13.u32)));
	// vmaddfp v12,v11,v3,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vadduwm v25,v6,v10
	simde_mm_store_si128((simde__m128i*)ctx.v25.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v6.u32), simde_mm_load_si128((simde__m128i*)ctx.v10.u32)));
	// vadduwm v11,v5,v13
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v5.u32), simde_mm_load_si128((simde__m128i*)ctx.v13.u32)));
	// vspltw128 v62,v55,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v55.u32), 0xFF));
	// addi r9,r5,1056
	ctx.r9.s64 = ctx.r5.s64 + 1056;
	// vadduwm v26,v5,v10
	simde_mm_store_si128((simde__m128i*)ctx.v26.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v5.u32), simde_mm_load_si128((simde__m128i*)ctx.v10.u32)));
	// vadduwm v20,v4,v4
	simde_mm_store_si128((simde__m128i*)ctx.v20.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v4.u32), simde_mm_load_si128((simde__m128i*)ctx.v4.u32)));
	// li r27,16
	ctx.r27.s64 = 16;
	// li r31,1
	ctx.r31.s64 = 1;
	// vadduwm v13,v11,v13
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), simde_mm_load_si128((simde__m128i*)ctx.v13.u32)));
	// li r4,3
	ctx.r4.s64 = 3;
	// vadduwm v27,v11,v10
	simde_mm_store_si128((simde__m128i*)ctx.v27.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), simde_mm_load_si128((simde__m128i*)ctx.v10.u32)));
	// li r7,2
	ctx.r7.s64 = 2;
	// li r22,-32
	ctx.r22.s64 = -32;
	// li r23,-16
	ctx.r23.s64 = -16;
	// vadduwm v28,v13,v10
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), simde_mm_load_si128((simde__m128i*)ctx.v10.u32)));
	// li r24,-1040
	ctx.r24.s64 = -1040;
	// li r25,-1024
	ctx.r25.s64 = -1024;
	// li r26,-1008
	ctx.r26.s64 = -1008;
loc_820EDAB4:
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
loc_820EDAB8:
	// rldicl r11,r10,32,32
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r29,r10
	ctx.r10.u64 = ctx.r29.u64 + ctx.r10.u64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lvlx128 v54,r11,r31
	temp.u32 = ctx.r11.u32 + ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v53,r11,r4
	temp.u32 = ctx.r11.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vsldoi128 v24,v24,v54,1
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)ctx.v54.u8), 15));
	// lvlx128 v52,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vsldoi128 v23,v23,v53,1
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)ctx.v53.u8), 15));
	// lvlx128 v51,r11,r7
	temp.u32 = ctx.r11.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vsldoi128 v22,v22,v52,1
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)ctx.v52.u8), 15));
	// vsldoi128 v21,v21,v51,1
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8), 15));
	// bne 0x820edab8
	if (!ctx.cr0.eq) goto loc_820EDAB8;
	// vaddubm v10,v22,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// rldicl r11,r10,32,32
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// vaddubm v6,v21,v0
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// vaddubm v13,v24,v0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// vaddubm v11,v23,v0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vor128 v50,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// vor128 v49,v6,v6
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_load_si128((simde__m128i*)ctx.v6.u8));
	// vupkhsb128 v48,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v48.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v13.s8), simde_mm_load_si128((simde__m128i*)ctx.v13.s8))));
	// vsrw128 v47,v28,v63
	ctx.v47.u32[0] = ctx.v28.u32[0] >> (ctx.v63.u8[0] & 0x1F);
	ctx.v47.u32[1] = ctx.v28.u32[1] >> (ctx.v63.u8[4] & 0x1F);
	ctx.v47.u32[2] = ctx.v28.u32[2] >> (ctx.v63.u8[8] & 0x1F);
	ctx.v47.u32[3] = ctx.v28.u32[3] >> (ctx.v63.u8[12] & 0x1F);
	// vupklsb128 v46,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v46.s32, simde_mm_cvtepi8_epi16(simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vsrw128 v45,v27,v63
	ctx.v45.u32[0] = ctx.v27.u32[0] >> (ctx.v63.u8[0] & 0x1F);
	ctx.v45.u32[1] = ctx.v27.u32[1] >> (ctx.v63.u8[4] & 0x1F);
	ctx.v45.u32[2] = ctx.v27.u32[2] >> (ctx.v63.u8[8] & 0x1F);
	ctx.v45.u32[3] = ctx.v27.u32[3] >> (ctx.v63.u8[12] & 0x1F);
	// vupkhsb128 v44,v11,v0
	simde_mm_store_si128((simde__m128i*)ctx.v44.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v11.s8), simde_mm_load_si128((simde__m128i*)ctx.v11.s8))));
	// vsrw128 v43,v26,v63
	ctx.v43.u32[0] = ctx.v26.u32[0] >> (ctx.v63.u8[0] & 0x1F);
	ctx.v43.u32[1] = ctx.v26.u32[1] >> (ctx.v63.u8[4] & 0x1F);
	ctx.v43.u32[2] = ctx.v26.u32[2] >> (ctx.v63.u8[8] & 0x1F);
	ctx.v43.u32[3] = ctx.v26.u32[3] >> (ctx.v63.u8[12] & 0x1F);
	// vupklsb128 v42,v11,v0
	simde_mm_store_si128((simde__m128i*)ctx.v42.s32, simde_mm_cvtepi8_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vsrw128 v41,v25,v63
	ctx.v41.u32[0] = ctx.v25.u32[0] >> (ctx.v63.u8[0] & 0x1F);
	ctx.v41.u32[1] = ctx.v25.u32[1] >> (ctx.v63.u8[4] & 0x1F);
	ctx.v41.u32[2] = ctx.v25.u32[2] >> (ctx.v63.u8[8] & 0x1F);
	ctx.v41.u32[3] = ctx.v25.u32[3] >> (ctx.v63.u8[12] & 0x1F);
	// vupkhsb128 v40,v50,v0
	simde_mm_store_si128((simde__m128i*)ctx.v40.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v50.s8), simde_mm_load_si128((simde__m128i*)ctx.v50.s8))));
	// vcuxwfp128 v13,v47,31
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(rex::ppc::simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)ctx.v47.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x30000000)))));
	// vupkhsb128 v39,v49,v0
	simde_mm_store_si128((simde__m128i*)ctx.v39.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v49.s8), simde_mm_load_si128((simde__m128i*)ctx.v49.s8))));
	// vcuxwfp128 v11,v45,31
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(rex::ppc::simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)ctx.v45.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x30000000)))));
	// vupkhsb128 v38,v48,v96
	simde_mm_store_si128((simde__m128i*)ctx.v38.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v48.s16), simde_mm_load_si128((simde__m128i*)ctx.v48.s16))));
	// vcuxwfp128 v10,v43,31
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(rex::ppc::simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)ctx.v43.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x30000000)))));
	// vupklsb128 v37,v48,v96
	simde_mm_store_si128((simde__m128i*)ctx.v37.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v48.s16)));
	// vcuxwfp128 v6,v41,31
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(rex::ppc::simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)ctx.v41.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x30000000)))));
	// vupkhsb128 v36,v46,v96
	simde_mm_store_si128((simde__m128i*)ctx.v36.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v46.s16), simde_mm_load_si128((simde__m128i*)ctx.v46.s16))));
	// xor r8,r30,r3
	ctx.r8.u64 = ctx.r30.u64 ^ ctx.r3.u64;
	// vupklsb128 v35,v46,v96
	simde_mm_store_si128((simde__m128i*)ctx.v35.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v46.s16)));
	// vupkhsb128 v34,v44,v96
	simde_mm_store_si128((simde__m128i*)ctx.v34.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v44.s16), simde_mm_load_si128((simde__m128i*)ctx.v44.s16))));
	// vcsxwfp128 v5,v38,7
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v38.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupklsb128 v33,v44,v96
	simde_mm_store_si128((simde__m128i*)ctx.v33.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v44.s16)));
	// vcsxwfp128 v4,v37,7
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v37.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupkhsb128 v32,v42,v96
	simde_mm_store_si128((simde__m128i*)ctx.v32.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v42.s16), simde_mm_load_si128((simde__m128i*)ctx.v42.s16))));
	// vcsxwfp128 v3,v36,7
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v36.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupklsb128 v61,v42,v96
	simde_mm_store_si128((simde__m128i*)ctx.v61.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v42.s16)));
	// vcsxwfp128 v2,v35,7
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v35.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupkhsb128 v60,v40,v96
	simde_mm_store_si128((simde__m128i*)ctx.v60.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v40.s16), simde_mm_load_si128((simde__m128i*)ctx.v40.s16))));
	// vcsxwfp128 v59,v34,7
	simde_mm_store_ps(ctx.v59.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v34.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupkhsb128 v58,v39,v96
	simde_mm_store_si128((simde__m128i*)ctx.v58.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v39.s16), simde_mm_load_si128((simde__m128i*)ctx.v39.s16))));
	// vcsxwfp128 v57,v33,7
	simde_mm_store_ps(ctx.v57.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v33.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vcsxwfp128 v56,v32,7
	simde_mm_store_ps(ctx.v56.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v32.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupklsb128 v55,v40,v96
	simde_mm_store_si128((simde__m128i*)ctx.v55.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v40.s16)));
	// vcsxwfp128 v54,v61,7
	simde_mm_store_ps(ctx.v54.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v61.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupklsb128 v53,v39,v96
	simde_mm_store_si128((simde__m128i*)ctx.v53.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v39.s16)));
	// vcsxwfp128 v1,v60,7
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v60.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupklsb128 v52,v50,v0
	simde_mm_store_si128((simde__m128i*)ctx.v52.s32, simde_mm_cvtepi8_epi16(simde_mm_load_si128((simde__m128i*)ctx.v50.s16)));
	// vcsxwfp128 v51,v58,7
	simde_mm_store_ps(ctx.v51.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v58.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupklsb128 v50,v49,v0
	simde_mm_store_si128((simde__m128i*)ctx.v50.s32, simde_mm_cvtepi8_epi16(simde_mm_load_si128((simde__m128i*)ctx.v49.s16)));
	// vcsxwfp128 v31,v55,7
	simde_mm_store_ps(ctx.v31.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v55.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vcsxwfp128 v49,v53,7
	simde_mm_store_ps(ctx.v49.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v53.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupkhsb128 v48,v52,v96
	simde_mm_store_si128((simde__m128i*)ctx.v48.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v52.s16), simde_mm_load_si128((simde__m128i*)ctx.v52.s16))));
	// vupklsb128 v47,v52,v96
	simde_mm_store_si128((simde__m128i*)ctx.v47.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v52.s16)));
	// vupkhsb128 v46,v50,v96
	simde_mm_store_si128((simde__m128i*)ctx.v46.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v50.s16), simde_mm_load_si128((simde__m128i*)ctx.v50.s16))));
	// vupklsb128 v45,v50,v96
	simde_mm_store_si128((simde__m128i*)ctx.v45.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v50.s16)));
	// vsubfp128 v19,v59,v5
	simde_mm_store_ps(ctx.v19.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v5.f32)));
	// vsubfp128 v18,v57,v4
	simde_mm_store_ps(ctx.v18.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v4.f32)));
	// vsubfp128 v17,v56,v3
	simde_mm_store_ps(ctx.v17.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v3.f32)));
	// vsubfp128 v16,v54,v2
	simde_mm_store_ps(ctx.v16.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_load_ps(ctx.v2.f32)));
	// vcsxwfp128 v30,v48,7
	simde_mm_store_ps(ctx.v30.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v48.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vsubfp128 v15,v51,v1
	simde_mm_store_ps(ctx.v15.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v51.f32), simde_mm_load_ps(ctx.v1.f32)));
	// vcsxwfp128 v29,v47,7
	simde_mm_store_ps(ctx.v29.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v47.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vsubfp128 v14,v49,v31
	simde_mm_store_ps(ctx.v14.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v49.f32), simde_mm_load_ps(ctx.v31.f32)));
	// vcsxwfp128 v39,v46,7
	simde_mm_store_ps(ctx.v39.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v46.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vcsxwfp128 v38,v45,7
	simde_mm_store_ps(ctx.v38.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v45.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vmaddfp v5,v19,v6,v5
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v19.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v4,v18,v10,v4
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v18.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v3,v17,v11,v3
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v17.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v2,v16,v13,v2
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v16.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v1,v15,v6,v1
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v15.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v31,v14,v10,v31
	simde_mm_store_ps(ctx.v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v14.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// vmulfp128 v44,v5,v12
	simde_mm_store_ps(ctx.v44.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v43,v4,v7
	simde_mm_store_ps(ctx.v43.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vmulfp128 v42,v3,v8
	simde_mm_store_ps(ctx.v42.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v41,v2,v9
	simde_mm_store_ps(ctx.v41.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v9.f32)));
	// vmulfp128 v40,v1,v12
	simde_mm_store_ps(ctx.v40.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v44,r9,r22
	ea = (ctx.r9.u32 + ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r9,r23
	ea = (ctx.r9.u32 + ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r9,r27
	ea = (ctx.r9.u32 + ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v40,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v19,v39,v30
	simde_mm_store_ps(ctx.v19.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v39.f32), simde_mm_load_ps(ctx.v30.f32)));
	// rlwinm r11,r8,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// vsubfp128 v18,v38,v29
	simde_mm_store_ps(ctx.v18.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v38.f32), simde_mm_load_ps(ctx.v29.f32)));
	// vmulfp128 v37,v31,v7
	simde_mm_store_ps(ctx.v37.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v7.f32)));
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// vmaddfp v17,v19,v11,v30
	simde_mm_store_ps(ctx.v17.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v19.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v30.f32)));
	// vmaddfp v16,v18,v13,v29
	simde_mm_store_ps(ctx.v16.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v18.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v29.f32)));
	// stvx128 v37,r9,r24
	ea = (ctx.r9.u32 + ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v36,v17,v8
	simde_mm_store_ps(ctx.v36.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v17.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v35,v16,v9
	simde_mm_store_ps(ctx.v35.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v16.f32), simde_mm_load_ps(ctx.v9.f32)));
	// stvx128 v36,r9,r25
	ea = (ctx.r9.u32 + ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r9,r26
	ea = (ctx.r9.u32 + ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x820edc70
	if (ctx.cr6.eq) goto loc_820EDC70;
	// li r11,128
	ctx.r11.s64 = 128;
	// dcbt r11,r3
loc_820EDC70:
	// vadduwm v28,v28,v20
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v28.u32), simde_mm_load_si128((simde__m128i*)ctx.v20.u32)));
	// addic. r6,r6,-16
	ctx.xer.ca = ctx.r6.u32 > 15;
	ctx.r6.s64 = ctx.r6.s64 + -16;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// vadduwm v27,v27,v20
	simde_mm_store_si128((simde__m128i*)ctx.v27.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v27.u32), simde_mm_load_si128((simde__m128i*)ctx.v20.u32)));
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// vadduwm v26,v26,v20
	simde_mm_store_si128((simde__m128i*)ctx.v26.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v26.u32), simde_mm_load_si128((simde__m128i*)ctx.v20.u32)));
	// vaddfp128 v9,v9,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vadduwm v25,v25,v20
	simde_mm_store_si128((simde__m128i*)ctx.v25.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v25.u32), simde_mm_load_si128((simde__m128i*)ctx.v20.u32)));
	// vaddfp128 v8,v8,v62
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vaddfp128 v7,v7,v62
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v62.f32)));
	// addi r5,r5,64
	ctx.r5.s64 = ctx.r5.s64 + 64;
	// vaddfp128 v12,v12,v62
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v62.f32)));
	// addi r9,r9,64
	ctx.r9.s64 = ctx.r9.s64 + 64;
	// bgt 0x820edab4
	if (ctx.cr0.gt) goto loc_820EDAB4;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lbz r9,13(r28)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r28.u32 + 13);
	// subf r8,r11,r3
	ctx.r8.u64 = ctx.r3.u64 - ctx.r11.u64;
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// twllei r9,0
	if (ctx.r9.s32 == 0 || ctx.r9.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r9,r8,r9
	ctx.r9.u64 = uint32_t(ctx.r9.u32 ? ctx.r8.u32 / ctx.r9.u32 : 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820edcc8
	if (ctx.cr6.lt) goto loc_820EDCC8;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
loc_820EDCC8:
	// lwz r11,20(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 20);
	// stw r9,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r9.u32);
	// subf r9,r11,r5
	ctx.r9.u64 = ctx.r5.u64 - ctx.r11.u64;
	// lwz r11,24(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 24);
	// rlwinm r9,r9,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x820edce8
	if (!ctx.cr6.lt) goto loc_820EDCE8;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_820EDCE8:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// stw r11,28(r28)
	REX_STORE_U32(ctx.r28.u32 + 28, ctx.r11.u32);
	// bl 0x8212b180
	ctx.lr = 0x820EDCF4;
	sub_8212B180(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfd f0,-21376(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + -21376);
	// fmul f0,f1,f0
	ctx.f0.f64 = ctx.f1.f64 * ctx.f0.f64;
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// stfs f13,48(r28)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r28.u32 + 48, temp.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
