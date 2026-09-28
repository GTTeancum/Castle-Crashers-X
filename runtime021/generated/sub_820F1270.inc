DEFINE_REX_FUNC(sub_820F1270) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f0
	ctx.lr = 0x820F1278;
	__savegprlr_18(ctx, base);
	// lwz r5,8(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// addi r21,r3,8
	ctx.r21.s64 = ctx.r3.s64 + 8;
	// lbz r4,13(r3)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r3.u32 + 13);
	// addi r27,r3,13
	ctx.r27.s64 = ctx.r3.s64 + 13;
	// lwz r8,28(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// addi r18,r3,28
	ctx.r18.s64 = ctx.r3.s64 + 28;
	// mullw r6,r4,r5
	ctx.r6.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r5.s32);
	// lwz r7,24(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,4(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r9,20(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r7,r8,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r8.u64;
	// addi r19,r3,24
	ctx.r19.s64 = ctx.r3.s64 + 24;
	// addi r26,r3,4
	ctx.r26.s64 = ctx.r3.s64 + 4;
	// stw r7,-144(r1)
	REX_STORE_U32(ctx.r1.u32 + -144, ctx.r7.u32);
	// addi r20,r3,20
	ctx.r20.s64 = ctx.r3.s64 + 20;
	// addi r29,r3,52
	ctx.r29.s64 = ctx.r3.s64 + 52;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r22,r5,r4
	ctx.r22.u64 = ctx.r4.u64 - ctx.r5.u64;
	// add r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 + ctx.r9.u64;
	// dcbt r0,r8
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f0,48(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,-144
	ctx.r10.s64 = ctx.r1.s64 + -144;
	// lfs f13,44(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// rldicr r6,r11,32,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// addi r28,r1,-144
	ctx.r28.s64 = ctx.r1.s64 + -144;
	// std r6,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.r6.u64);
	// lfd f12,-136(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// li r5,40
	ctx.r5.s64 = 40;
	// fmul f10,f0,f11
	ctx.f10.f64 = ctx.f0.f64 * ctx.f11.f64;
	// lvlx128 v63,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r10,4
	ctx.r10.s64 = 4;
	// vcsxwfp128 v62,v63,0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v63.u32)));
	// fmul f9,f13,f11
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.f64 = ctx.f13.f64 * ctx.f11.f64;
	// addi r24,r3,36
	ctx.r24.s64 = ctx.r3.s64 + 36;
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lvlx128 v60,r3,r5
	temp.u32 = ctx.r3.u32 + ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r6,r1,-136
	ctx.r6.s64 = ctx.r1.s64 + -136;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r30,1024
	ctx.r30.s64 = 1024;
	// lvlx128 v61,r0,r24
	temp.u32 = ctx.r24.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r25,r3,48
	ctx.r25.s64 = ctx.r3.s64 + 48;
	// vsubfp128 v59,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v59.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfd f0,9616(r4)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r4.u32 + 9616);
	// vspltw128 v63,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// fdiv f13,f0,f11
	ctx.f13.f64 = ctx.f0.f64 / ctx.f11.f64;
	// fctidz f8,f10
	ctx.f8.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f8,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.f8.u64);
	// ld r11,-136(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// li r31,0
	ctx.r31.s64 = 0;
	// std r11,-144(r1)
	REX_STORE_U64(ctx.r1.u32 + -144, ctx.r11.u64);
	// lvlx128 v55,r10,r28
	temp.u32 = ctx.r10.u32 + ctx.r28.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vrefp128 v58,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v58.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v62.f32)));
	// fctidz f7,f9
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f7.s64 = std::isnan(ctx.f9.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f7,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.f7.u64);
	// ld r4,-136(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// std r4,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.r4.u64);
	// cmpdi cr6,r11,0
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 0, ctx.xer);
	// vmulfp128 v57,v59,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v57.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v58.f32)));
	// lvlx128 v56,r10,r6
	temp.u32 = ctx.r10.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.u32), 0xFF));
	// vspltw128 v0,v55,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v55.u32), 0xFF));
	// vspltw128 v62,v57,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.u32), 0xFF));
	// bge cr6,0x820f1410
	if (!ctx.cr6.lt) goto loc_820F1410;
loc_820F1388:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x820f1410
	if (!ctx.cr6.gt) goto loc_820F1410;
	// vspltisw128 v54,0
	simde_mm_store_si128((simde__m128i*)ctx.v54.u32, simde_mm_set1_epi32(int(0x0)));
	// lvlx128 v53,r8,r5
	temp.u32 = ctx.r8.u32 + ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltisb v12,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_set1_epi8(char(0x1)));
	// lvlx128 v52,r29,r10
	temp.u32 = ctx.r29.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkhsb128 v51,v53,v96
	simde_mm_store_si128((simde__m128i*)ctx.v51.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v53.s16), simde_mm_load_si128((simde__m128i*)ctx.v53.s16))));
	// vadduwm v11,v0,v13
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)ctx.v13.u32)));
	// vspltw128 v50,v52,0
	simde_mm_store_si128((simde__m128i*)ctx.v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v52.u32), 0xFF));
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// vsubfp128 v49,v54,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v49.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_load_ps(ctx.v63.f32)));
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// vsr v10,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_vsr(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)));
	// cmpdi cr6,r11,0
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 0, ctx.xer);
	// vcsxwfp128 v48,v51,15
	simde_mm_store_ps(ctx.v48.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v51.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vor v0,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// vcuxwfp128 v47,v10,31
	simde_mm_store_ps(ctx.v47.f32, simde_mm_mul_ps(rex::ppc::simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)ctx.v10.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x30000000)))));
	// vsldoi128 v46,v63,v49,4
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v49.u8), 12));
	// vrlimi128 v50,v48,8,0
	simde_mm_store_ps(ctx.v50.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v50.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v48.f32), 228), 8));
	// vmulfp128 v45,v47,v46
	simde_mm_store_ps(ctx.v45.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v47.f32), simde_mm_load_ps(ctx.v46.f32)));
	// vsldoi128 v44,v45,v63,8
	simde_mm_store_si128((simde__m128i*)ctx.v44.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v45.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), 8));
	// vaddfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmsum3fp128 v43,v50,v44
	simde_mm_store_ps(ctx.v43.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v50.f32), simde_mm_load_ps(ctx.v44.f32), 0xEF));
	// stvewx128 v43,r9,r30
	ea = (ctx.r9.u32 + ctx.r30.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v43.u32[3 - ((ea & 0xF) >> 2)]);
	// lvlx128 v42,r0,r29
	temp.u32 = ctx.r29.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v41,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkhsb128 v40,v41,v96
	simde_mm_store_si128((simde__m128i*)ctx.v40.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v41.s16), simde_mm_load_si128((simde__m128i*)ctx.v41.s16))));
	// vcsxwfp128 v39,v40,15
	simde_mm_store_ps(ctx.v39.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v40.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vspltw128 v38,v42,0
	simde_mm_store_si128((simde__m128i*)ctx.v38.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v42.u32), 0xFF));
	// vrlimi128 v38,v39,8,0
	simde_mm_store_ps(ctx.v38.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v38.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v39.f32), 228), 8));
	// vmsum3fp128 v37,v38,v44
	simde_mm_store_ps(ctx.v37.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v38.f32), simde_mm_load_ps(ctx.v44.f32), 0xEF));
	// stvewx128 v37,r0,r9
	ea = (ctx.r9.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v37.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// blt cr6,0x820f1388
	if (ctx.cr6.lt) goto loc_820F1388;
loc_820F1410:
	// sradi r10,r11,63
	ctx.xer.ca = (ctx.r11.s64 < 0) & ((ctx.r11.u64 & 0x7FFFFFFFFFFFFFFF) != 0);
	ctx.r10.s64 = ctx.r11.s64 >> 63;
	// sradi r6,r11,32
	ctx.xer.ca = (ctx.r11.s64 < 0) & ((ctx.r11.u64 & 0xFFFFFFFF) != 0);
	ctx.r6.s64 = ctx.r11.s64 >> 32;
	// addi r23,r22,-1
	ctx.r23.s64 = ctx.r22.s64 + -1;
	// subf r10,r10,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r10.u64;
	// extsw r28,r23
	ctx.r28.s64 = ctx.r23.s32;
	// cmpd cr6,r10,r28
	ctx.cr6.compare<int64_t>(ctx.r10.s64, ctx.r28.s64, ctx.xer);
	// bge cr6,0x820f1504
	if (!ctx.cr6.lt) goto loc_820F1504;
loc_820F142C:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x820f1584
	if (ctx.cr6.eq) goto loc_820F1584;
	// vspltisw128 v36,0
	simde_mm_store_si128((simde__m128i*)ctx.v36.u32, simde_mm_set1_epi32(int(0x0)));
	// extsw r6,r10
	ctx.r6.s64 = ctx.r10.s32;
	// vspltisb v12,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_set1_epi8(char(0x1)));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// vadduwm v11,v0,v13
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)ctx.v13.u32)));
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// vsubfp128 v35,v36,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v35.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v36.f32), simde_mm_load_ps(ctx.v63.f32)));
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// vsr v10,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_vsr(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)));
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// add r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 + ctx.r8.u64;
	// vor v0,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// lvlx128 v34,r10,r5
	temp.u32 = ctx.r10.u32 + ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vcuxwfp128 v33,v10,31
	simde_mm_store_ps(ctx.v33.f32, simde_mm_mul_ps(rex::ppc::simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)ctx.v10.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x30000000)))));
	// vupkhsb128 v32,v34,v96
	simde_mm_store_si128((simde__m128i*)ctx.v32.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v34.s16), simde_mm_load_si128((simde__m128i*)ctx.v34.s16))));
	// lvlx128 v61,r6,r5
	temp.u32 = ctx.r6.u32 + ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkhsb128 v60,v61,v96
	simde_mm_store_si128((simde__m128i*)ctx.v60.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v61.s16), simde_mm_load_si128((simde__m128i*)ctx.v61.s16))));
	// vcsxwfp128 v59,v32,15
	simde_mm_store_ps(ctx.v59.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v32.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vsldoi128 v58,v63,v35,4
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v35.u8), 12));
	// vcsxwfp128 v57,v60,15
	simde_mm_store_ps(ctx.v57.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v60.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vmulfp128 v56,v33,v58
	simde_mm_store_ps(ctx.v56.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v33.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v55,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0xFF));
	// vrlimi128 v55,v57,8,0
	simde_mm_store_ps(ctx.v55.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v57.f32), 228), 8));
	// vsldoi128 v54,v56,v63,8
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), 8));
	// vaddfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmsum3fp128 v53,v55,v54
	simde_mm_store_ps(ctx.v53.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_load_ps(ctx.v54.f32), 0xEF));
	// stvewx128 v53,r9,r30
	ea = (ctx.r9.u32 + ctx.r30.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v53.u32[3 - ((ea & 0xF) >> 2)]);
	// lvlx128 v52,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v51,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkhsb128 v50,v51,v96
	simde_mm_store_si128((simde__m128i*)ctx.v50.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v51.s16), simde_mm_load_si128((simde__m128i*)ctx.v51.s16))));
	// vupkhsb128 v49,v52,v96
	simde_mm_store_si128((simde__m128i*)ctx.v49.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v52.s16), simde_mm_load_si128((simde__m128i*)ctx.v52.s16))));
	// vcsxwfp128 v48,v50,15
	simde_mm_store_ps(ctx.v48.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v50.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// sradi r10,r11,32
	ctx.xer.ca = (ctx.r11.s64 < 0) & ((ctx.r11.u64 & 0xFFFFFFFF) != 0);
	ctx.r10.s64 = ctx.r11.s64 >> 32;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// vcsxwfp128 v47,v49,15
	simde_mm_store_ps(ctx.v47.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v49.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// add r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 + ctx.r8.u64;
	// xor r31,r6,r31
	ctx.r31.u64 = ctx.r6.u64 ^ ctx.r31.u64;
	// rlwinm r31,r31,0,0,24
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// vspltw128 v46,v48,0
	simde_mm_store_si128((simde__m128i*)ctx.v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v48.u32), 0xFF));
	// vrlimi128 v46,v47,8,0
	simde_mm_store_ps(ctx.v46.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v46.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v47.f32), 228), 8));
	// vmsum3fp128 v45,v46,v54
	simde_mm_store_ps(ctx.v45.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v46.f32), simde_mm_load_ps(ctx.v54.f32), 0xEF));
	// stvewx128 v45,r0,r9
	ea = (ctx.r9.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v45.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// beq cr6,0x820f14f8
	if (ctx.cr6.eq) goto loc_820F14F8;
	// li r31,128
	ctx.r31.s64 = 128;
	// dcbt r31,r6
loc_820F14F8:
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// cmpd cr6,r10,r28
	ctx.cr6.compare<int64_t>(ctx.r10.s64, ctx.r28.s64, ctx.xer);
	// blt cr6,0x820f142c
	if (ctx.cr6.lt) goto loc_820F142C;
loc_820F1504:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x820f1584
	if (ctx.cr6.eq) goto loc_820F1584;
	// cmpd cr6,r10,r28
	ctx.cr6.compare<int64_t>(ctx.r10.s64, ctx.r28.s64, ctx.xer);
	// bne cr6,0x820f156c
	if (!ctx.cr6.eq) goto loc_820F156C;
	// rlwinm r7,r23,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lfs f0,9560(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 9560);
	ctx.f0.f64 = double(temp.f32);
	// lhz r5,2(r7)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r7.u32 + 2);
	// extsh r6,r5
	ctx.r6.s64 = ctx.r5.s16;
	// std r6,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.r6.u64);
	// lfd f12,-136(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// stfs f9,4(r29)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r29.u32 + 4, temp.u32);
	// lhz r5,0(r7)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r7.u32 + 0);
	// extsh r7,r5
	ctx.r7.s64 = ctx.r5.s16;
	// std r7,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.r7.u64);
	// lfd f8,-136(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// fmuls f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// stfs f5,0(r29)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// b 0x820f1584
	goto loc_820F1584;
loc_820F156C:
	// extsw r7,r22
	ctx.r7.s64 = ctx.r22.s32;
	// cmpd cr6,r10,r7
	ctx.cr6.compare<int64_t>(ctx.r10.s64, ctx.r7.s64, ctx.xer);
	// ble cr6,0x820f1584
	if (!ctx.cr6.gt) goto loc_820F1584;
	// subf r7,r7,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r7.u64;
	// rldicr r7,r7,32,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF00000000;
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
loc_820F1584:
	// rldicr r7,r10,32,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF00000000;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r5,r7,r11
	ctx.r5.u64 = ctx.r11.u64 - ctx.r7.u64;
	// std r5,-144(r1)
	REX_STORE_U64(ctx.r1.u32 + -144, ctx.r5.u64);
	// stvewx128 v63,r0,r24
	ea = (ctx.r24.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// lfd f0,-144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -144);
	// lbz r4,0(r27)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r27.u32 + 0);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// subf r11,r3,r6
	ctx.r11.u64 = ctx.r6.u64 - ctx.r3.u64;
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// add r10,r11,r8
	ctx.r10.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rotlwi r8,r4,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// divwu r10,r10,r8
	ctx.r10.u64 = uint32_t(ctx.r8.u32 ? ctx.r10.u32 / ctx.r8.u32 : 0);
	// twllei r8,0
	if (ctx.r8.s32 == 0 || ctx.r8.u32 < 0u) ppc_trap(ctx, base, 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// fmul f11,f12,f13
	ctx.f11.f64 = ctx.f12.f64 * ctx.f13.f64;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stfs f10,0(r25)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r25.u32 + 0, temp.u32);
	// bge cr6,0x820f15d8
	if (!ctx.cr6.lt) goto loc_820F15D8;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820F15D8:
	// lwz r10,0(r20)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r11.u32);
	// subf r9,r10,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r10.u64;
	// lwz r8,0(r19)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// rlwinm r11,r9,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x820f15fc
	if (!ctx.cr6.lt) goto loc_820F15FC;
	// stw r11,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r11.u32);
	// b 0x82129940
	__restgprlr_18(ctx, base);
	return;
loc_820F15FC:
	// stw r8,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r8.u32);
	// b 0x82129940
	__restgprlr_18(ctx, base);
	return;
}
