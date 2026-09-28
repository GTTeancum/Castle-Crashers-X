DEFINE_REX_FUNC(sub_820F20F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f0
	ctx.lr = 0x820F2100;
	__savegprlr_18(ctx, base);
	// lwz r4,8(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// addi r26,r3,13
	ctx.r26.s64 = ctx.r3.s64 + 13;
	// lwz r6,28(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// addi r21,r3,8
	ctx.r21.s64 = ctx.r3.s64 + 8;
	// lbz r11,13(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 13);
	// addi r18,r3,28
	ctx.r18.s64 = ctx.r3.s64 + 28;
	// lwz r5,24(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// rlwinm r7,r6,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r31,4(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mullw r10,r4,r11
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r11.s32);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// subf r5,r6,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r6.u64;
	// subf r27,r4,r31
	ctx.r27.u64 = ctx.r31.u64 - ctx.r4.u64;
	// addi r19,r3,24
	ctx.r19.s64 = ctx.r3.s64 + 24;
	// stw r5,-144(r1)
	REX_STORE_U32(ctx.r1.u32 + -144, ctx.r5.u32);
	// addi r25,r3,4
	ctx.r25.s64 = ctx.r3.s64 + 4;
	// addi r20,r3,20
	ctx.r20.s64 = ctx.r3.s64 + 20;
	// addi r22,r3,52
	ctx.r22.s64 = ctx.r3.s64 + 52;
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r4,r7,r8
	ctx.r4.u64 = ctx.r7.u64 + ctx.r8.u64;
	// dcbt r0,r6
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f0,48(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// li r7,40
	ctx.r7.s64 = 40;
	// lfs f13,44(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// rldicr r8,r10,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// addi r9,r1,-144
	ctx.r9.s64 = ctx.r1.s64 + -144;
	// std r8,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.r8.u64);
	// lfd f12,-136(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// li r10,4
	ctx.r10.s64 = 4;
	// fmul f10,f0,f11
	ctx.f10.f64 = ctx.f0.f64 * ctx.f11.f64;
	// addi r29,r1,-144
	ctx.r29.s64 = ctx.r1.s64 + -144;
	// lvlx128 v60,r3,r7
	temp.u32 = ctx.r3.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmul f9,f13,f11
	ctx.f9.f64 = ctx.f13.f64 * ctx.f11.f64;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r23,r3,36
	ctx.r23.s64 = ctx.r3.s64 + 36;
	// vcsxwfp128 v62,v63,0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v63.u32)));
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r8,r1,-136
	ctx.r8.s64 = ctx.r1.s64 + -136;
	// addi r24,r3,48
	ctx.r24.s64 = ctx.r3.s64 + 48;
	// li r31,0
	ctx.r31.s64 = 0;
	// lvlx128 v61,r0,r23
	temp.u32 = ctx.r23.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vsubfp128 v59,v60,v61
	simde_mm_store_ps(ctx.v59.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfd f0,9616(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r9.u32 + 9616);
	// vspltw128 v63,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// fdiv f12,f0,f11
	ctx.f12.f64 = ctx.f0.f64 / ctx.f11.f64;
	// fctidz f8,f10
	ctx.f8.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f8,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.f8.u64);
	// ld r7,-136(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// fctidz f7,f9
	ctx.f7.s64 = std::isnan(ctx.f9.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// std r7,-144(r1)
	REX_STORE_U64(ctx.r1.u32 + -144, ctx.r7.u64);
	// lvlx128 v55,r10,r29
	temp.u32 = ctx.r10.u32 + ctx.r29.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vrefp128 v58,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v58.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v62.f32)));
	// stfd f7,-136(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.f7.u64);
	// ld r30,-136(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// cmpdi cr6,r7,0
	ctx.cr6.compare<int64_t>(ctx.r7.s64, 0, ctx.xer);
	// std r30,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.r30.u64);
	// vspltw128 v0,v55,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v55.u32), 0xFF));
	// vmulfp128 v57,v59,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v57.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v58.f32)));
	// lvlx128 v56,r10,r8
	temp.u32 = ctx.r10.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.u32), 0xFF));
	// vspltw128 v61,v57,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.u32), 0xFF));
	// bge cr6,0x820f22a0
	if (!ctx.cr6.lt) goto loc_820F22A0;
loc_820F2204:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// ble cr6,0x820f22a0
	if (!ctx.cr6.gt) goto loc_820F22A0;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f2284
	if (ctx.cr6.eq) goto loc_820F2284;
	// vspltisw128 v54,0
	simde_mm_store_si128((simde__m128i*)ctx.v54.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// vspltisb v11,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_set1_epi8(char(0x1)));
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// vspltisb v13,7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_set1_epi8(char(0x7)));
	// vsubfp128 v53,v54,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v53.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsr v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_vsr(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)));
	// vslb v13,v13,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi8(0x7));
		simde_mm_store_si128((simde__m128i*)ctx.v13.u8, rex::ppc::simde_mm_sllv_epi8(a, shift));
	}
	// vcuxwfp128 v52,v10,31
	simde_mm_store_ps(ctx.v52.f32, simde_mm_mul_ps(rex::ppc::simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)ctx.v10.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x30000000)))));
	// vsldoi128 v51,v63,v53,4
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v53.u8), 12));
	// vmulfp128 v50,v52,v51
	simde_mm_store_ps(ctx.v50.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v52.f32), simde_mm_load_ps(ctx.v51.f32)));
	// vsldoi128 v62,v50,v63,8
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), 8));
loc_820F2248:
	// lvlx v11,r10,r6
	temp.u32 = ctx.r10.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// vaddubm v10,v11,v13
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)));
	// lvlx128 v49,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v48,v49,0
	simde_mm_store_si128((simde__m128i*)ctx.v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v49.u32), 0xFF));
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// vupkhsb128 v47,v10,v0
	simde_mm_store_si128((simde__m128i*)ctx.v47.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v10.s8), simde_mm_load_si128((simde__m128i*)ctx.v10.s8))));
	// vupkhsb128 v46,v47,v96
	simde_mm_store_si128((simde__m128i*)ctx.v46.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v47.s16), simde_mm_load_si128((simde__m128i*)ctx.v47.s16))));
	// vcsxwfp128 v45,v46,7
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v45.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v46.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vrlimi128 v48,v45,8,0
	simde_mm_store_ps(ctx.v48.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v48.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v45.f32), 228), 8));
	// vmsum3fp128 v44,v48,v62
	simde_mm_store_ps(ctx.v44.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v48.f32), simde_mm_load_ps(ctx.v62.f32), 0xEF));
	// stvewx128 v44,r0,r8
	ea = (ctx.r8.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v44.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r8,r8,1024
	ctx.r8.s64 = ctx.r8.s64 + 1024;
	// blt cr6,0x820f2248
	if (ctx.cr6.lt) goto loc_820F2248;
loc_820F2284:
	// add r7,r30,r7
	ctx.r7.u64 = ctx.r30.u64 + ctx.r7.u64;
	// vadduwm v0,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)ctx.v12.u32)));
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// cmpdi cr6,r7,0
	ctx.cr6.compare<int64_t>(ctx.r7.s64, 0, ctx.xer);
	// blt cr6,0x820f2204
	if (ctx.cr6.lt) goto loc_820F2204;
loc_820F22A0:
	// sradi r10,r7,63
	ctx.xer.ca = (ctx.r7.s64 < 0) & ((ctx.r7.u64 & 0x7FFFFFFFFFFFFFFF) != 0);
	ctx.r10.s64 = ctx.r7.s64 >> 63;
	// sradi r9,r7,32
	ctx.xer.ca = (ctx.r7.s64 < 0) & ((ctx.r7.u64 & 0xFFFFFFFF) != 0);
	ctx.r9.s64 = ctx.r7.s64 >> 32;
	// addi r28,r27,-1
	ctx.r28.s64 = ctx.r27.s64 + -1;
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// extsw r29,r28
	ctx.r29.s64 = ctx.r28.s32;
	// cmpd cr6,r10,r29
	ctx.cr6.compare<int64_t>(ctx.r10.s64, ctx.r29.s64, ctx.xer);
	// bge cr6,0x820f2398
	if (!ctx.cr6.lt) goto loc_820F2398;
loc_820F22BC:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x820f2420
	if (ctx.cr6.eq) goto loc_820F2420;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f2350
	if (ctx.cr6.eq) goto loc_820F2350;
	// vspltisw128 v43,0
	simde_mm_store_si128((simde__m128i*)ctx.v43.u32, simde_mm_set1_epi32(int(0x0)));
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// vspltisb v11,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_set1_epi8(char(0x1)));
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// vspltisb v13,7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_set1_epi8(char(0x7)));
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// vsubfp128 v42,v43,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v42.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v43.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsr v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_vsr(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)));
	// vslb v13,v13,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi8(0x7));
		simde_mm_store_si128((simde__m128i*)ctx.v13.u8, rex::ppc::simde_mm_sllv_epi8(a, shift));
	}
	// vcuxwfp128 v41,v10,31
	simde_mm_store_ps(ctx.v41.f32, simde_mm_mul_ps(rex::ppc::simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)ctx.v10.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x30000000)))));
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// vsldoi128 v40,v63,v42,4
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v42.u8), 12));
	// vmulfp128 v39,v41,v40
	simde_mm_store_ps(ctx.v39.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v41.f32), simde_mm_load_ps(ctx.v40.f32)));
	// vsldoi128 v62,v39,v63,8
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v39.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), 8));
loc_820F2308:
	// lvlx v11,0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// vaddubm v10,v11,v13
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)));
	// lvlx v9,r10,r11
	temp.u32 = ctx.r10.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vaddubm v8,v9,v13
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)));
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// vupkhsb128 v38,v10,v0
	simde_mm_store_si128((simde__m128i*)ctx.v38.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v10.s8), simde_mm_load_si128((simde__m128i*)ctx.v10.s8))));
	// vupkhsb128 v37,v8,v0
	simde_mm_store_si128((simde__m128i*)ctx.v37.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v8.s8), simde_mm_load_si128((simde__m128i*)ctx.v8.s8))));
	// vupkhsb128 v36,v38,v96
	simde_mm_store_si128((simde__m128i*)ctx.v36.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v38.s16), simde_mm_load_si128((simde__m128i*)ctx.v38.s16))));
	// vupkhsb128 v35,v37,v96
	simde_mm_store_si128((simde__m128i*)ctx.v35.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v37.s16), simde_mm_load_si128((simde__m128i*)ctx.v37.s16))));
	// vcsxwfp128 v34,v36,7
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v34.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v36.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vcsxwfp128 v33,v35,7
	simde_mm_store_ps(ctx.v33.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v35.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vspltw128 v32,v34,0
	simde_mm_store_si128((simde__m128i*)ctx.v32.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v34.u32), 0xFF));
	// vrlimi128 v32,v33,8,0
	simde_mm_store_ps(ctx.v32.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v32.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v33.f32), 228), 8));
	// vmsum3fp128 v60,v32,v62
	simde_mm_store_ps(ctx.v60.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v32.f32), simde_mm_load_ps(ctx.v62.f32), 0xEF));
	// stvewx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v60.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r8,r8,1024
	ctx.r8.s64 = ctx.r8.s64 + 1024;
	// bne 0x820f2308
	if (!ctx.cr0.eq) goto loc_820F2308;
loc_820F2350:
	// add r7,r30,r7
	ctx.r7.u64 = ctx.r30.u64 + ctx.r7.u64;
	// vadduwm v0,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)ctx.v12.u32)));
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// sradi r10,r7,32
	ctx.xer.ca = (ctx.r7.s64 < 0) & ((ctx.r7.u64 & 0xFFFFFFFF) != 0);
	ctx.r10.s64 = ctx.r7.s64 >> 32;
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// xor r8,r9,r31
	ctx.r8.u64 = ctx.r9.u64 ^ ctx.r31.u64;
	// rlwinm r8,r8,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820f238c
	if (ctx.cr6.eq) goto loc_820F238C;
	// li r8,128
	ctx.r8.s64 = 128;
	// dcbt r8,r9
loc_820F238C:
	// mr r31,r9
	ctx.r31.u64 = ctx.r9.u64;
	// cmpd cr6,r10,r29
	ctx.cr6.compare<int64_t>(ctx.r10.s64, ctx.r29.s64, ctx.xer);
	// blt cr6,0x820f22bc
	if (ctx.cr6.lt) goto loc_820F22BC;
loc_820F2398:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x820f2420
	if (ctx.cr6.eq) goto loc_820F2420;
	// cmpd cr6,r10,r29
	ctx.cr6.compare<int64_t>(ctx.r10.s64, ctx.r29.s64, ctx.xer);
	// bne cr6,0x820f2408
	if (!ctx.cr6.eq) goto loc_820F2408;
	// mullw r9,r28,r11
	ctx.r9.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r11.s32);
	// add r5,r9,r6
	ctx.r5.u64 = ctx.r9.u64 + ctx.r6.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f2420
	if (ctx.cr6.eq) goto loc_820F2420;
	// lis r31,-32255
	ctx.r31.s64 = -2113863680;
	// lis r30,-32255
	ctx.r30.s64 = -2113863680;
	// mr r8,r22
	ctx.r8.u64 = ctx.r22.u64;
	// lfs f13,-21608(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -21608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-21604(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -21604);
	ctx.f0.f64 = double(temp.f32);
loc_820F23D4:
	// lbzx r31,r9,r5
	ctx.r31.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r5.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// std r31,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.r31.u64);
	// lfd f11,-136(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fsubs f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f0.f64));
	// fmuls f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// stfs f7,0(r8)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// blt cr6,0x820f23d4
	if (ctx.cr6.lt) goto loc_820F23D4;
	// b 0x820f2420
	goto loc_820F2420;
loc_820F2408:
	// extsw r9,r27
	ctx.r9.s64 = ctx.r27.s32;
	// cmpd cr6,r10,r9
	ctx.cr6.compare<int64_t>(ctx.r10.s64, ctx.r9.s64, ctx.xer);
	// ble cr6,0x820f2420
	if (!ctx.cr6.gt) goto loc_820F2420;
	// subf r9,r9,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r9.u64;
	// rldicr r9,r9,32,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF00000000;
	// add r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 + ctx.r7.u64;
loc_820F2420:
	// rldicr r9,r10,32,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF00000000;
	// rotlwi r8,r10,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// subf r7,r9,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r9.u64;
	// mullw r5,r8,r11
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// std r7,-144(r1)
	REX_STORE_U64(ctx.r1.u32 + -144, ctx.r7.u64);
	// stvewx128 v63,r0,r23
	ea = (ctx.r23.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// lfd f0,-144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -144);
	// lbz r9,0(r26)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// subf r10,r8,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r8.u64;
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// add r7,r10,r6
	ctx.r7.u64 = ctx.r10.u64 + ctx.r6.u64;
	// twllei r9,0
	if (ctx.r9.s32 == 0 || ctx.r9.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r10,r7,r9
	ctx.r10.u64 = uint32_t(ctx.r9.u32 ? ctx.r7.u32 / ctx.r9.u32 : 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// fmul f12,f13,f12
	ctx.f12.f64 = ctx.f13.f64 * ctx.f12.f64;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f11,0(r24)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r24.u32 + 0, temp.u32);
	// bge cr6,0x820f2474
	if (!ctx.cr6.lt) goto loc_820F2474;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820F2474:
	// lwz r10,0(r20)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r11.u32);
	// subf r8,r10,r4
	ctx.r8.u64 = ctx.r4.u64 - ctx.r10.u64;
	// lwz r9,0(r19)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// rlwinm r11,r8,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x820f2498
	if (!ctx.cr6.lt) goto loc_820F2498;
	// stw r11,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r11.u32);
	// b 0x82129940
	__restgprlr_18(ctx, base);
	return;
loc_820F2498:
	// stw r9,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r9.u32);
	// b 0x82129940
	__restgprlr_18(ctx, base);
	return;
}
