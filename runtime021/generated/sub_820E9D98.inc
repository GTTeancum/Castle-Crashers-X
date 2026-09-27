DEFINE_REX_FUNC(sub_820E9D98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x820E9DA0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// addi r28,r31,4
	ctx.r28.s64 = ctx.r31.s64 + 4;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820e1d28
	ctx.lr = 0x820E9DBC;
	sub_820E1D28(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r8,r11,-27528
	ctx.r8.s64 = ctx.r11.s64 + -27528;
	// addi r7,r10,-27568
	ctx.r7.s64 = ctx.r10.s64 + -27568;
	// stw r30,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r30.u32);
	// addi r6,r9,-27664
	ctx.r6.s64 = ctx.r9.s64 + -27664;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// stw r6,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lbz r11,69(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + 69);
	// stb r11,264(r31)
	REX_STORE_U8(ctx.r31.u32 + 264, ctx.r11.u8);
	// stw r30,268(r31)
	REX_STORE_U32(ctx.r31.u32 + 268, ctx.r30.u32);
	// stw r30,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r30.u32);
	// stw r30,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r30.u32);
	// stb r30,292(r31)
	REX_STORE_U8(ctx.r31.u32 + 292, ctx.r30.u8);
	// stw r30,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r30.u32);
	// stw r30,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r30.u32);
	// stb r30,308(r31)
	REX_STORE_U8(ctx.r31.u32 + 308, ctx.r30.u8);
	// stw r30,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r30.u32);
	// bl 0x820e1ab8
	ctx.lr = 0x820E9E20;
	sub_820E1AB8(ctx, base);
	// lis r10,744
	ctx.r10.s64 = 48758784;
	// ori r9,r10,47662
	ctx.r9.u64 = ctx.r10.u64 | 47662;
	// lbz r28,56(r31)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// cmplw cr6,r28,r9
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r9.u32, ctx.xer);
	// mulli r4,r28,88
	ctx.r4.s64 = static_cast<int64_t>(ctx.r28.u64 * static_cast<uint64_t>(88));
	// ble cr6,0x820e9e3c
	if (!ctx.cr6.gt) goto loc_820E9E3C;
	// li r4,-1
	ctx.r4.s64 = -1;
loc_820E9E3C:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820E9E50;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x820e9e90
	if (ctx.cr6.eq) goto loc_820E9E90;
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// blt 0x820e9e88
	if (ctx.cr0.lt) goto loc_820E9E88;
loc_820E9E68:
	// li r5,76
	ctx.r5.s64 = 76;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82129fa0
	ctx.lr = 0x820E9E78;
	sub_82129FA0(ctx, base);
	// stw r30,76(r29)
	REX_STORE_U32(ctx.r29.u32 + 76, ctx.r30.u32);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r29,r29,88
	ctx.r29.s64 = ctx.r29.s64 + 88;
	// bge 0x820e9e68
	if (!ctx.cr0.lt) goto loc_820E9E68;
loc_820E9E88:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// b 0x820e9e94
	goto loc_820E9E94;
loc_820E9E90:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_820E9E94:
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r11,200(r31)
	REX_STORE_U32(ctx.r31.u32 + 200, ctx.r11.u32);
	// vspltisw v0,15
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_set1_epi32(int(0xF)));
	// li r9,204
	ctx.r9.s64 = 204;
	// vspltisw128 v63,4
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x4)));
	// addi r3,r31,208
	ctx.r3.s64 = ctx.r31.s64 + 208;
	// vspltisw v13,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_set1_epi32(int(0x1)));
	// addi r4,r31,52
	ctx.r4.s64 = ctx.r31.s64 + 52;
	// li r5,56
	ctx.r5.s64 = 56;
	// lvlx128 v62,r27,r10
	temp.u32 = ctx.r27.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vexptefp128 v61,v62
	ctx.fpscr.enableFlushMode();
	{
		simde__m128 x = simde_mm_load_ps(ctx.v62.f32);
		simde__m128 n = simde_mm_round_ps(x, SIMDE_MM_FROUND_TO_NEG_INF | SIMDE_MM_FROUND_NO_EXC);
		simde__m128 f = simde_mm_sub_ps(x, n);
		simde__m128 p = simde_mm_set1_ps(1.8775767e-3f);
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(8.9893397e-3f));
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(5.5826318e-2f));
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(2.4015361e-1f));
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(6.9315308e-1f));
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(1.0f));
		simde__m128i exp_bits = simde_mm_slli_epi32(
			simde_mm_add_epi32(simde_mm_cvttps_epi32(n), simde_mm_set1_epi32(127)), 23);
		simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(p, simde_mm_castsi128_ps(exp_bits)));
	}
	// vcfpsxws128 v12,v61,4
	simde_mm_store_si128((simde__m128i*)ctx.v12.s32, rex::ppc::simde_mm_vctsxs(simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_set1_ps(16))));
	// vadduws v11,v12,v0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, rex::ppc::simde_mm_adds_epu32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), simde_mm_load_si128((simde__m128i*)ctx.v0.u32)));
	// vsraw128 v10,v11,v63
	ctx.v10.s32[0] = ctx.v11.s32[0] >> (ctx.v63.u8[0] & 0x1F);
	ctx.v10.s32[1] = ctx.v11.s32[1] >> (ctx.v63.u8[4] & 0x1F);
	ctx.v10.s32[2] = ctx.v11.s32[2] >> (ctx.v63.u8[8] & 0x1F);
	ctx.v10.s32[3] = ctx.v11.s32[3] >> (ctx.v63.u8[12] & 0x1F);
	// vmaxsw v9,v10,v13
	simde_mm_store_si128((simde__m128i*)ctx.v9.s32, simde_mm_max_epi32(simde_mm_load_si128((simde__m128i*)ctx.v10.s32), simde_mm_load_si128((simde__m128i*)ctx.v13.s32)));
	// vspltw128 v60,v9,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v9.u32), 0xFF));
	// stvewx128 v60,r31,r9
	ea = (ctx.r31.u32 + ctx.r9.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v60.u32[3 - ((ea & 0xF) >> 2)]);
	// bl 0x82129a70
	ctx.lr = 0x820E9EDC;
	sub_82129A70(ctx, base);
	// stw r30,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r30.u32);
	// stw r30,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r30.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r30,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// sth r11,108(r31)
	REX_STORE_U16(ctx.r31.u32 + 108, ctx.r11.u16);
	// sth r11,110(r31)
	REX_STORE_U16(ctx.r31.u32 + 110, ctx.r11.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
