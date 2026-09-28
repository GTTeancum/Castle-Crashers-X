DEFINE_REX_FUNC(sub_820EF940) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298ec
	ctx.lr = 0x820EF948;
	__savegprlr_17(ctx, base);
	// lwz r5,8(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// addi r24,r3,13
	ctx.r24.s64 = ctx.r3.s64 + 13;
	// lbz r10,13(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 13);
	// addi r20,r3,8
	ctx.r20.s64 = ctx.r3.s64 + 8;
	// lwz r4,28(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// addi r17,r3,28
	ctx.r17.s64 = ctx.r3.s64 + 28;
	// lwz r6,24(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// mullw r9,r5,r10
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r30,4(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,20(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// subf r31,r4,r6
	ctx.r31.u64 = ctx.r6.u64 - ctx.r4.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r4,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r31,-144(r1)
	REX_STORE_U32(ctx.r1.u32 + -144, ctx.r31.u32);
	// addi r18,r3,24
	ctx.r18.s64 = ctx.r3.s64 + 24;
	// addi r23,r3,4
	ctx.r23.s64 = ctx.r3.s64 + 4;
	// addi r19,r3,20
	ctx.r19.s64 = ctx.r3.s64 + 20;
	// addi r27,r3,52
	ctx.r27.s64 = ctx.r3.s64 + 52;
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + ctx.r11.u64;
	// subf r25,r5,r30
	ctx.r25.u64 = ctx.r30.u64 - ctx.r5.u64;
	// add r4,r7,r8
	ctx.r4.u64 = ctx.r7.u64 + ctx.r8.u64;
	// dcbt r0,r6
	// li r8,1
	ctx.r8.s64 = 1;
	// lfs f0,48(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// li r9,40
	ctx.r9.s64 = 40;
	// lfs f13,44(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// rldicr r5,r8,32,63
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// addi r7,r1,-144
	ctx.r7.s64 = ctx.r1.s64 + -144;
	// std r5,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.r5.u64);
	// lfd f12,-136(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// li r11,4
	ctx.r11.s64 = 4;
	// fmul f10,f0,f11
	ctx.f10.f64 = ctx.f0.f64 * ctx.f11.f64;
	// lvlx128 v60,r3,r9
	temp.u32 = ctx.r3.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r9,r1,-144
	ctx.r9.s64 = ctx.r1.s64 + -144;
	// lvlx128 v63,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vcsxwfp128 v62,v63,0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v63.u32)));
	// fmul f9,f13,f11
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.f64 = ctx.f13.f64 * ctx.f11.f64;
	// addi r21,r3,36
	ctx.r21.s64 = ctx.r3.s64 + 36;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r7,r1,-136
	ctx.r7.s64 = ctx.r1.s64 + -136;
	// addi r22,r3,48
	ctx.r22.s64 = ctx.r3.s64 + 48;
	// li r30,0
	ctx.r30.s64 = 0;
	// lvlx128 v61,r0,r21
	temp.u32 = ctx.r21.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vsubfp128 v59,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v59.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfd f0,9616(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r8.u32 + 9616);
	// fctidz f8,f10
	ctx.f8.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f8,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.f8.u64);
	// ld r5,-136(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// vspltw128 v63,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// std r5,-144(r1)
	REX_STORE_U64(ctx.r1.u32 + -144, ctx.r5.u64);
	// lvlx128 v55,r11,r9
	temp.u32 = ctx.r11.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vrefp128 v58,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v58.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v62.f32)));
	// fctidz f7,f9
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f7.s64 = std::isnan(ctx.f9.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f7,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.f7.u64);
	// ld r29,-136(r1)
	ctx.r29.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// std r29,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.r29.u64);
	// fdiv f0,f0,f11
	ctx.f0.f64 = ctx.f0.f64 / ctx.f11.f64;
	// vmulfp128 v57,v59,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v57.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v58.f32)));
	// lvlx128 v56,r11,r7
	temp.u32 = ctx.r11.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.u32), 0xFF));
	// cmpdi cr6,r5,0
	ctx.cr6.compare<int64_t>(ctx.r5.s64, 0, ctx.xer);
	// vspltw128 v0,v55,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v55.u32), 0xFF));
	// vspltw128 v61,v57,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.u32), 0xFF));
	// bge cr6,0x820efad4
	if (!ctx.cr6.lt) goto loc_820EFAD4;
loc_820EFA50:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// ble cr6,0x820efad4
	if (!ctx.cr6.gt) goto loc_820EFAD4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820efab8
	if (ctx.cr6.eq) goto loc_820EFAB8;
	// vspltisw128 v54,0
	simde_mm_store_si128((simde__m128i*)ctx.v54.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// vspltisb v12,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_set1_epi8(char(0x1)));
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// subf r7,r27,r6
	ctx.r7.u64 = ctx.r6.u64 - ctx.r27.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// vsubfp128 v53,v54,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v53.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsr v11,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, rex::ppc::simde_mm_vsr(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)));
	// vcuxwfp128 v52,v11,31
	simde_mm_store_ps(ctx.v52.f32, simde_mm_mul_ps(rex::ppc::simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)ctx.v11.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x30000000)))));
	// vsldoi128 v51,v63,v53,4
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v53.u8), 12));
	// vmulfp128 v50,v52,v51
	simde_mm_store_ps(ctx.v50.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v52.f32), simde_mm_load_ps(ctx.v51.f32)));
	// vsldoi128 v62,v50,v63,8
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), 8));
loc_820EFA90:
	// lvlx128 v49,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// vspltw128 v48,v49,0
	simde_mm_store_si128((simde__m128i*)ctx.v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v49.u32), 0xFF));
	// lvlx128 v47,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// vrlimi128 v48,v47,8,0
	simde_mm_store_ps(ctx.v48.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v48.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v47.f32), 228), 8));
	// vmsum3fp128 v46,v48,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v46.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v48.f32), simde_mm_load_ps(ctx.v62.f32), 0xEF));
	// stvewx128 v46,r0,r8
	ea = (ctx.r8.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v46.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r8,r8,1024
	ctx.r8.s64 = ctx.r8.s64 + 1024;
	// bne 0x820efa90
	if (!ctx.cr0.eq) goto loc_820EFA90;
loc_820EFAB8:
	// add r5,r29,r5
	ctx.r5.u64 = ctx.r29.u64 + ctx.r5.u64;
	// vadduwm v0,v0,v13
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)ctx.v13.u32)));
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// cmpdi cr6,r5,0
	ctx.cr6.compare<int64_t>(ctx.r5.s64, 0, ctx.xer);
	// blt cr6,0x820efa50
	if (ctx.cr6.lt) goto loc_820EFA50;
loc_820EFAD4:
	// sradi r11,r5,63
	ctx.xer.ca = (ctx.r5.s64 < 0) & ((ctx.r5.u64 & 0x7FFFFFFFFFFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s64 >> 63;
	// sradi r9,r5,32
	ctx.xer.ca = (ctx.r5.s64 < 0) & ((ctx.r5.u64 & 0xFFFFFFFF) != 0);
	ctx.r9.s64 = ctx.r5.s64 >> 32;
	// addi r26,r25,-1
	ctx.r26.s64 = ctx.r25.s64 + -1;
	// subf r11,r11,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
	// extsw r28,r26
	ctx.r28.s64 = ctx.r26.s32;
	// cmpd cr6,r11,r28
	ctx.cr6.compare<int64_t>(ctx.r11.s64, ctx.r28.s64, ctx.xer);
	// bge cr6,0x820efbc0
	if (!ctx.cr6.lt) goto loc_820EFBC0;
loc_820EFAF0:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq cr6,0x820efc24
	if (ctx.cr6.eq) goto loc_820EFC24;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820efb74
	if (ctx.cr6.eq) goto loc_820EFB74;
	// vspltisw128 v45,0
	simde_mm_store_si128((simde__m128i*)ctx.v45.u32, simde_mm_set1_epi32(int(0x0)));
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// vspltisb v12,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_set1_epi8(char(0x1)));
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// vsubfp128 v44,v45,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v44.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v45.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsr v11,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, rex::ppc::simde_mm_vsr(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)));
	// vcuxwfp128 v43,v11,31
	simde_mm_store_ps(ctx.v43.f32, simde_mm_mul_ps(rex::ppc::simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)ctx.v11.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x30000000)))));
	// mullw r9,r9,r10
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// vsldoi128 v42,v63,v44,4
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v44.u8), 12));
	// vmulfp128 v41,v43,v42
	simde_mm_store_ps(ctx.v41.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v43.f32), simde_mm_load_ps(ctx.v42.f32)));
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r6
	ctx.r8.u64 = ctx.r11.u64 + ctx.r6.u64;
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// vsldoi128 v62,v41,v63,8
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v41.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), 8));
loc_820EFB48:
	// lvlx128 v40,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// vspltw128 v39,v40,0
	simde_mm_store_si128((simde__m128i*)ctx.v39.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v40.u32), 0xFF));
	// lvlx128 v38,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// vrlimi128 v39,v38,8,0
	simde_mm_store_ps(ctx.v39.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v39.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v38.f32), 228), 8));
	// vmsum3fp128 v37,v39,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v37.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v39.f32), simde_mm_load_ps(ctx.v62.f32), 0xEF));
	// stvewx128 v37,r0,r7
	ea = (ctx.r7.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v37.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r7,r7,1024
	ctx.r7.s64 = ctx.r7.s64 + 1024;
	// bne 0x820efb48
	if (!ctx.cr0.eq) goto loc_820EFB48;
loc_820EFB74:
	// add r5,r29,r5
	ctx.r5.u64 = ctx.r29.u64 + ctx.r5.u64;
	// vadduwm v0,v0,v13
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)ctx.v13.u32)));
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// sradi r11,r5,32
	ctx.xer.ca = (ctx.r5.s64 < 0) & ((ctx.r5.u64 & 0xFFFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s64 >> 32;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// rlwinm r9,r8,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// xor r7,r9,r30
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r30.u64;
	// rlwinm r8,r7,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820efbb4
	if (ctx.cr6.eq) goto loc_820EFBB4;
	// li r8,128
	ctx.r8.s64 = 128;
	// dcbt r8,r9
loc_820EFBB4:
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// cmpd cr6,r11,r28
	ctx.cr6.compare<int64_t>(ctx.r11.s64, ctx.r28.s64, ctx.xer);
	// blt cr6,0x820efaf0
	if (ctx.cr6.lt) goto loc_820EFAF0;
loc_820EFBC0:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq cr6,0x820efc24
	if (ctx.cr6.eq) goto loc_820EFC24;
	// cmpd cr6,r11,r28
	ctx.cr6.compare<int64_t>(ctx.r11.s64, ctx.r28.s64, ctx.xer);
	// bne cr6,0x820efc0c
	if (!ctx.cr6.eq) goto loc_820EFC0C;
	// mullw r9,r26,r10
	ctx.r9.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r10.s32);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// add r8,r9,r6
	ctx.r8.u64 = ctx.r9.u64 + ctx.r6.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820efc24
	if (ctx.cr6.eq) goto loc_820EFC24;
	// subf r7,r27,r8
	ctx.r7.u64 = ctx.r8.u64 - ctx.r27.u64;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
loc_820EFBF4:
	// lfsx f13,r7,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	ctx.f13.f64 = double(temp.f32);
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stfs f13,0(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x820efbf4
	if (!ctx.cr0.eq) goto loc_820EFBF4;
	// b 0x820efc24
	goto loc_820EFC24;
loc_820EFC0C:
	// extsw r9,r25
	ctx.r9.s64 = ctx.r25.s32;
	// cmpd cr6,r11,r9
	ctx.cr6.compare<int64_t>(ctx.r11.s64, ctx.r9.s64, ctx.xer);
	// ble cr6,0x820efc24
	if (!ctx.cr6.gt) goto loc_820EFC24;
	// subf r9,r9,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r9.u64;
	// rldicr r9,r9,32,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF00000000;
	// add r5,r9,r5
	ctx.r5.u64 = ctx.r9.u64 + ctx.r5.u64;
loc_820EFC24:
	// rldicr r9,r11,32,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 32) & 0xFFFFFFFF00000000;
	// rotlwi r8,r11,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// subf r7,r9,r5
	ctx.r7.u64 = ctx.r5.u64 - ctx.r9.u64;
	// mullw r5,r8,r10
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// std r7,-144(r1)
	REX_STORE_U64(ctx.r1.u32 + -144, ctx.r7.u64);
	// stvewx128 v63,r0,r21
	ea = (ctx.r21.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// lfd f13,-144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -144);
	// lbz r9,0(r24)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r24.u32 + 0);
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r7,r5,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r8,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r8.u64;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// rotlwi r5,r9,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// twllei r5,0
	if (ctx.r5.s32 == 0 || ctx.r5.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r10,r6,r5
	ctx.r10.u64 = uint32_t(ctx.r5.u32 ? ctx.r6.u32 / ctx.r5.u32 : 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// fmul f11,f12,f0
	ctx.f11.f64 = ctx.f12.f64 * ctx.f0.f64;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stfs f10,0(r22)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r22.u32 + 0, temp.u32);
	// bge cr6,0x820efc80
	if (!ctx.cr6.lt) goto loc_820EFC80;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820EFC80:
	// lwz r10,0(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// stw r11,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r11.u32);
	// subf r8,r10,r4
	ctx.r8.u64 = ctx.r4.u64 - ctx.r10.u64;
	// lwz r9,0(r18)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// rlwinm r11,r8,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x820efca4
	if (!ctx.cr6.lt) goto loc_820EFCA4;
	// stw r11,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r11.u32);
	// b 0x8212993c
	__restgprlr_17(ctx, base);
	return;
loc_820EFCA4:
	// stw r9,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r9.u32);
	// b 0x8212993c
	__restgprlr_17(ctx, base);
	return;
}
