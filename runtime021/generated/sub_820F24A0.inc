DEFINE_REX_FUNC(sub_820F24A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f4
	ctx.lr = 0x820F24A8;
	__savegprlr_19(ctx, base);
	// lwz r5,8(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// addi r22,r3,8
	ctx.r22.s64 = ctx.r3.s64 + 8;
	// lwz r4,28(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// addi r28,r3,13
	ctx.r28.s64 = ctx.r3.s64 + 13;
	// lwz r9,24(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// addi r19,r3,28
	ctx.r19.s64 = ctx.r3.s64 + 28;
	// lbz r10,13(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 13);
	// rlwinm r6,r4,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// subf r7,r4,r9
	ctx.r7.u64 = ctx.r9.u64 - ctx.r4.u64;
	// lwz r31,4(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mullw r10,r10,r5
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// lwz r8,20(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// stw r7,-128(r1)
	REX_STORE_U32(ctx.r1.u32 + -128, ctx.r7.u32);
	// addi r20,r3,24
	ctx.r20.s64 = ctx.r3.s64 + 24;
	// addi r27,r3,4
	ctx.r27.s64 = ctx.r3.s64 + 4;
	// addi r21,r3,20
	ctx.r21.s64 = ctx.r3.s64 + 20;
	// addi r30,r3,52
	ctx.r30.s64 = ctx.r3.s64 + 52;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r24,r5,r31
	ctx.r24.u64 = ctx.r31.u64 - ctx.r5.u64;
	// add r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 + ctx.r8.u64;
	// dcbt r0,r9
	// li r6,1
	ctx.r6.s64 = 1;
	// lfs f0,48(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// li r11,40
	ctx.r11.s64 = 40;
	// lfs f13,44(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// rldicr r4,r6,32,63
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// addi r5,r1,-128
	ctx.r5.s64 = ctx.r1.s64 + -128;
	// std r4,-120(r1)
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.r4.u64);
	// lfd f12,-120(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// li r10,4
	ctx.r10.s64 = 4;
	// fmul f10,f0,f11
	ctx.f10.f64 = ctx.f0.f64 * ctx.f11.f64;
	// addi r29,r1,-128
	ctx.r29.s64 = ctx.r1.s64 + -128;
	// lvlx128 v60,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmul f9,f13,f11
	ctx.f9.f64 = ctx.f13.f64 * ctx.f11.f64;
	// lvlx128 v63,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r25,r3,36
	ctx.r25.s64 = ctx.r3.s64 + 36;
	// vcsxwfp128 v62,v63,0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v63.u32)));
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r31,r1,-120
	ctx.r31.s64 = ctx.r1.s64 + -120;
	// addi r26,r3,48
	ctx.r26.s64 = ctx.r3.s64 + 48;
	// li r4,0
	ctx.r4.s64 = 0;
	// lvlx128 v61,r0,r25
	temp.u32 = ctx.r25.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vsubfp128 v59,v60,v61
	simde_mm_store_ps(ctx.v59.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfd f0,9616(r6)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r6.u32 + 9616);
	// vspltw128 v63,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// fdiv f12,f0,f11
	ctx.f12.f64 = ctx.f0.f64 / ctx.f11.f64;
	// fctidz f8,f10
	ctx.f8.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f8,-120(r1)
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.f8.u64);
	// ld r11,-120(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// fctidz f7,f9
	ctx.f7.s64 = std::isnan(ctx.f9.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// std r11,-128(r1)
	REX_STORE_U64(ctx.r1.u32 + -128, ctx.r11.u64);
	// lvlx128 v55,r10,r29
	temp.u32 = ctx.r10.u32 + ctx.r29.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vrefp128 v58,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v58.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v62.f32)));
	// stfd f7,-120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.f7.u64);
	// ld r5,-120(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// cmpdi cr6,r11,0
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 0, ctx.xer);
	// std r5,-120(r1)
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.r5.u64);
	// vspltw128 v0,v55,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v55.u32), 0xFF));
	// vmulfp128 v57,v59,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v57.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v58.f32)));
	// lvlx128 v56,r10,r31
	temp.u32 = ctx.r10.u32 + ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.u32), 0xFF));
	// vspltw128 v62,v57,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.u32), 0xFF));
	// bge cr6,0x820f2624
	if (!ctx.cr6.lt) goto loc_820F2624;
loc_820F25AC:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x820f2624
	if (!ctx.cr6.gt) goto loc_820F2624;
	// vspltisb v13,7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_set1_epi8(char(0x7)));
	// lvlx v11,0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltisw128 v54,0
	simde_mm_store_si128((simde__m128i*)ctx.v54.u32, simde_mm_set1_epi32(int(0x0)));
	// lvlx128 v53,r0,r30
	temp.u32 = ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltisb v10,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_set1_epi8(char(0x1)));
	// vadduwm v9,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)ctx.v12.u32)));
	// vspltw128 v52,v53,0
	simde_mm_store_si128((simde__m128i*)ctx.v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v53.u32), 0xFF));
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// vslb v8,v13,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi8(0x7));
		simde_mm_store_si128((simde__m128i*)ctx.v8.u8, rex::ppc::simde_mm_sllv_epi8(a, shift));
	}
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// vsubfp128 v51,v54,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v51.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_load_ps(ctx.v63.f32)));
	// cmpdi cr6,r11,0
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 0, ctx.xer);
	// vsr v7,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, rex::ppc::simde_mm_vsr(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)));
	// vor v0,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v9.u8));
	// vaddubm v6,v11,v8
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)));
	// vcuxwfp128 v50,v7,31
	simde_mm_store_ps(ctx.v50.f32, simde_mm_mul_ps(rex::ppc::simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)ctx.v7.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x30000000)))));
	// vupkhsb128 v49,v6,v0
	simde_mm_store_si128((simde__m128i*)ctx.v49.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v6.s8), simde_mm_load_si128((simde__m128i*)ctx.v6.s8))));
	// vupkhsb128 v48,v49,v96
	simde_mm_store_si128((simde__m128i*)ctx.v48.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v49.s16), simde_mm_load_si128((simde__m128i*)ctx.v49.s16))));
	// vsldoi128 v47,v63,v51,4
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8), 12));
	// vcsxwfp128 v46,v48,7
	simde_mm_store_ps(ctx.v46.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v48.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vmulfp128 v45,v50,v47
	simde_mm_store_ps(ctx.v45.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v50.f32), simde_mm_load_ps(ctx.v47.f32)));
	// vrlimi128 v52,v46,8,0
	simde_mm_store_ps(ctx.v52.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v52.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v46.f32), 228), 8));
	// vsldoi128 v44,v45,v63,8
	simde_mm_store_si128((simde__m128i*)ctx.v44.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v45.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), 8));
	// vaddfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmsum3fp128 v43,v52,v44
	simde_mm_store_ps(ctx.v43.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v52.f32), simde_mm_load_ps(ctx.v44.f32), 0xEF));
	// stvewx128 v43,r0,r8
	ea = (ctx.r8.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v43.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// blt cr6,0x820f25ac
	if (ctx.cr6.lt) goto loc_820F25AC;
loc_820F2624:
	// sradi r10,r11,63
	ctx.xer.ca = (ctx.r11.s64 < 0) & ((ctx.r11.u64 & 0x7FFFFFFFFFFFFFFF) != 0);
	ctx.r10.s64 = ctx.r11.s64 >> 63;
	// sradi r6,r11,32
	ctx.xer.ca = (ctx.r11.s64 < 0) & ((ctx.r11.u64 & 0xFFFFFFFF) != 0);
	ctx.r6.s64 = ctx.r11.s64 >> 32;
	// addi r23,r24,-1
	ctx.r23.s64 = ctx.r24.s64 + -1;
	// subf r10,r10,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r10.u64;
	// extsw r29,r23
	ctx.r29.s64 = ctx.r23.s32;
	// cmpd cr6,r10,r29
	ctx.cr6.compare<int64_t>(ctx.r10.s64, ctx.r29.s64, ctx.xer);
	// bge cr6,0x820f26fc
	if (!ctx.cr6.lt) goto loc_820F26FC;
	// li r31,1
	ctx.r31.s64 = 1;
loc_820F2644:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x820f275c
	if (ctx.cr6.eq) goto loc_820F275C;
	// vspltisb v13,7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_set1_epi8(char(0x7)));
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// vspltisw128 v42,0
	simde_mm_store_si128((simde__m128i*)ctx.v42.u32, simde_mm_set1_epi32(int(0x0)));
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// vspltisb v11,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_set1_epi8(char(0x1)));
	// vadduwm v10,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)ctx.v12.u32)));
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// vslb v13,v13,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi8(0x7));
		simde_mm_store_si128((simde__m128i*)ctx.v13.u8, rex::ppc::simde_mm_sllv_epi8(a, shift));
	}
	// lvlx v9,r10,r9
	temp.u32 = ctx.r10.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vsubfp128 v41,v42,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v41.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v42.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsr v8,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, rex::ppc::simde_mm_vsr(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)));
	// sradi r10,r11,32
	ctx.xer.ca = (ctx.r11.s64 < 0) & ((ctx.r11.u64 & 0xFFFFFFFF) != 0);
	ctx.r10.s64 = ctx.r11.s64 >> 32;
	// lvlx v7,r6,r31
	temp.u32 = ctx.r6.u32 + ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor v0,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// vaddubm v6,v9,v13
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)));
	// extsw r6,r10
	ctx.r6.s64 = ctx.r10.s32;
	// vaddubm v5,v7,v13
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)));
	// vcuxwfp128 v40,v8,31
	simde_mm_store_ps(ctx.v40.f32, simde_mm_mul_ps(rex::ppc::simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)ctx.v8.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x30000000)))));
	// add r6,r6,r9
	ctx.r6.u64 = ctx.r6.u64 + ctx.r9.u64;
	// vupkhsb128 v39,v6,v0
	simde_mm_store_si128((simde__m128i*)ctx.v39.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v6.s8), simde_mm_load_si128((simde__m128i*)ctx.v6.s8))));
	// xor r4,r6,r4
	ctx.r4.u64 = ctx.r6.u64 ^ ctx.r4.u64;
	// vupkhsb128 v38,v5,v0
	simde_mm_store_si128((simde__m128i*)ctx.v38.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v5.s8), simde_mm_load_si128((simde__m128i*)ctx.v5.s8))));
	// rlwinm r4,r4,0,0,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFF80;
	// vupkhsb128 v37,v39,v96
	simde_mm_store_si128((simde__m128i*)ctx.v37.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v39.s16), simde_mm_load_si128((simde__m128i*)ctx.v39.s16))));
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// vsldoi128 v36,v63,v41,4
	simde_mm_store_si128((simde__m128i*)ctx.v36.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v41.u8), 12));
	// vupkhsb128 v35,v38,v96
	simde_mm_store_si128((simde__m128i*)ctx.v35.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v38.s16), simde_mm_load_si128((simde__m128i*)ctx.v38.s16))));
	// vcsxwfp128 v34,v37,7
	simde_mm_store_ps(ctx.v34.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v37.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vmulfp128 v33,v40,v36
	simde_mm_store_ps(ctx.v33.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v40.f32), simde_mm_load_ps(ctx.v36.f32)));
	// vcsxwfp128 v32,v35,7
	simde_mm_store_ps(ctx.v32.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v35.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vspltw128 v61,v34,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v34.u32), 0xFF));
	// vsldoi128 v60,v33,v63,8
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v33.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), 8));
	// vaddfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vrlimi128 v61,v32,8,0
	simde_mm_store_ps(ctx.v61.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v32.f32), 228), 8));
	// vmsum3fp128 v59,v61,v60
	simde_mm_store_ps(ctx.v59.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32), 0xEF));
	// stvewx128 v59,r0,r8
	ea = (ctx.r8.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v59.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// beq cr6,0x820f26f0
	if (ctx.cr6.eq) goto loc_820F26F0;
	// li r4,128
	ctx.r4.s64 = 128;
	// dcbt r4,r6
loc_820F26F0:
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// cmpd cr6,r10,r29
	ctx.cr6.compare<int64_t>(ctx.r10.s64, ctx.r29.s64, ctx.xer);
	// blt cr6,0x820f2644
	if (ctx.cr6.lt) goto loc_820F2644;
loc_820F26FC:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x820f275c
	if (ctx.cr6.eq) goto loc_820F275C;
	// cmpd cr6,r10,r29
	ctx.cr6.compare<int64_t>(ctx.r10.s64, ctx.r29.s64, ctx.xer);
	// bne cr6,0x820f2744
	if (!ctx.cr6.eq) goto loc_820F2744;
	// lbzx r4,r23,r9
	ctx.r4.u64 = REX_LOAD_U8(ctx.r23.u32 + ctx.r9.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// std r4,-120(r1)
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.r4.u64);
	// lfd f0,-120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f0,-21604(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -21604);
	ctx.f0.f64 = double(temp.f32);
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// lfs f13,-21608(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -21608);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f0.f64));
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// stfs f9,0(r30)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// b 0x820f275c
	goto loc_820F275C;
loc_820F2744:
	// extsw r7,r24
	ctx.r7.s64 = ctx.r24.s32;
	// cmpd cr6,r10,r7
	ctx.cr6.compare<int64_t>(ctx.r10.s64, ctx.r7.s64, ctx.xer);
	// ble cr6,0x820f275c
	if (!ctx.cr6.gt) goto loc_820F275C;
	// subf r7,r7,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r7.u64;
	// rldicr r7,r7,32,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF00000000;
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
loc_820F275C:
	// rldicr r7,r10,32,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF00000000;
	// rotlwi r6,r10,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// subf r5,r7,r11
	ctx.r5.u64 = ctx.r11.u64 - ctx.r7.u64;
	// std r5,-128(r1)
	REX_STORE_U64(ctx.r1.u32 + -128, ctx.r5.u64);
	// stvewx128 v63,r0,r25
	ea = (ctx.r25.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// lwz r4,0(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// subf r11,r4,r6
	ctx.r11.u64 = ctx.r6.u64 - ctx.r4.u64;
	// lbz r3,0(r28)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r28.u32 + 0);
	// lfd f0,-128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -128);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// add r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 + ctx.r9.u64;
	// fmul f12,f13,f12
	ctx.f12.f64 = ctx.f13.f64 * ctx.f12.f64;
	// divwu r10,r10,r3
	ctx.r10.u64 = uint32_t(ctx.r3.u32 ? ctx.r10.u32 / ctx.r3.u32 : 0);
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// twllei r3,0
	if (ctx.r3.s32 == 0 || ctx.r3.u32 < 0u) ppc_trap(ctx, base, 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f11,0(r26)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
	// bge cr6,0x820f27ac
	if (!ctx.cr6.lt) goto loc_820F27AC;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820F27AC:
	// lwz r10,0(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// stw r11,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// subf r8,r10,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r10.u64;
	// lwz r9,0(r20)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// rlwinm r11,r8,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x820f27d0
	if (!ctx.cr6.lt) goto loc_820F27D0;
	// stw r11,0(r19)
	REX_STORE_U32(ctx.r19.u32 + 0, ctx.r11.u32);
	// b 0x82129944
	__restgprlr_19(ctx, base);
	return;
loc_820F27D0:
	// stw r9,0(r19)
	REX_STORE_U32(ctx.r19.u32 + 0, ctx.r9.u32);
	// b 0x82129944
	__restgprlr_19(ctx, base);
	return;
}
