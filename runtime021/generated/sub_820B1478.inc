DEFINE_REX_FUNC(sub_820B1478) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820B1480;
	__savegprlr_27(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,16383
	ctx.r8.s64 = 1073676288;
	// li r11,0
	ctx.r11.s64 = 0;
	// ori r7,r8,65535
	ctx.r7.u64 = ctx.r8.u64 | 65535;
	// lwz r10,560(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 560);
	// addi r6,r9,9508
	ctx.r6.s64 = ctx.r9.s64 + 9508;
	// stw r11,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r11.u32);
	// stw r11,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r11.u32);
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// stw r11,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r11.u32);
	// rlwinm r30,r10,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r11.u32);
	// stw r6,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// ble cr6,0x820b14c4
	if (!ctx.cr6.gt) goto loc_820B14C4;
	// li r30,-1
	ctx.r30.s64 = -1;
loc_820B14C4:
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// addi r28,r11,-22601
	ctx.r28.s64 = ctx.r11.s64 + -22601;
	// addi r27,r10,-1768
	ctx.r27.s64 = ctx.r10.s64 + -1768;
	// lbz r11,-22601(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820b14f4
	if (!ctx.cr6.eq) goto loc_820B14F4;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820B14F4;
	sub_820A71E8(ctx, base);
loc_820B14F4:
	// bl 0x820b5eb8
	ctx.lr = 0x820B14F8;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r11,29632
	ctx.r29.s64 = ctx.r11.s64 + 29632;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r3,r10,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820B1510;
	sub_8209BDD8(ctx, base);
	// lwz r9,560(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 560);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,568(r31)
	REX_STORE_U32(ctx.r31.u32 + 568, ctx.r3.u32);
	// addi r30,r31,568
	ctx.r30.s64 = ctx.r31.s64 + 568;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82129fa0
	ctx.lr = 0x820B1528;
	sub_82129FA0(ctx, base);
	// lwz r8,556(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 556);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r5,552(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 552);
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r4,568(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 568);
	// bl 0x820b1838
	ctx.lr = 0x820B1540;
	sub_820B1838(ctx, base);
	// addi r5,r31,572
	ctx.r5.s64 = ctx.r31.s64 + 572;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// bl 0x820b31d0
	ctx.lr = 0x820B1550;
	sub_820B31D0(ctx, base);
	// lwz r7,556(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 556);
	// lwz r6,552(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 552);
	// lwz r10,564(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 564);
	// lwz r11,568(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 568);
	// mullw. r9,r7,r6
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble 0x820b15cc
	if (!ctx.cr0.gt) goto loc_820B15CC;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// addi r6,r8,13392
	ctx.r6.s64 = ctx.r8.s64 + 13392;
	// li r5,16
	ctx.r5.s64 = 16;
	// lfs f0,9540(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v13,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r6,r5
	ea = (ctx.r6.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_820B1584:
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// vpermwi128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v60,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v60.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vpermwi128 v12,v60,108
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x93));
	// vmaddfp v11,v12,v13,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vor128 v59,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// vpkd3d128 v59,v11,0,1,0
	vTemp.u32[0] = 0x404000FF;
	vTemp.f32[0] = !(ctx.v11.f32[0] >= 3.0f) ? 3.0f : (ctx.v11.f32[0] > vTemp.f32[0] ? vTemp.f32[0] : ctx.v11.f32[0]);
	temp.u32 = uint32_t(vTemp.u8[0]) << 24;
	vTemp.u32[1] = 0x404000FF;
	vTemp.f32[1] = !(ctx.v11.f32[1] >= 3.0f) ? 3.0f : (ctx.v11.f32[1] > vTemp.f32[1] ? vTemp.f32[1] : ctx.v11.f32[1]);
	temp.u32 |= uint32_t(vTemp.u8[4]) << 0;
	vTemp.u32[2] = 0x404000FF;
	vTemp.f32[2] = !(ctx.v11.f32[2] >= 3.0f) ? 3.0f : (ctx.v11.f32[2] > vTemp.f32[2] ? vTemp.f32[2] : ctx.v11.f32[2]);
	temp.u32 |= uint32_t(vTemp.u8[8]) << 8;
	vTemp.u32[3] = 0x404000FF;
	vTemp.f32[3] = !(ctx.v11.f32[3] >= 3.0f) ? 3.0f : (ctx.v11.f32[3] > vTemp.f32[3] ? vTemp.f32[3] : ctx.v11.f32[3]);
	temp.u32 |= uint32_t(vTemp.u8[12]) << 16;
	ctx.v59.u32[0] = temp.u32;
	// vspltw128 v58,v59,3
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x0));
	// stvewx128 v58,r0,r10
	ea = (ctx.r10.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v58.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x820b1584
	if (!ctx.cr0.eq) goto loc_820B1584;
loc_820B15CC:
	// lbz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 0);
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820b15f0
	if (!ctx.cr6.eq) goto loc_820B15F0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820B15F0;
	sub_820A71E8(ctx, base);
loc_820B15F0:
	// bl 0x820b5eb8
	ctx.lr = 0x820B15F4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// bl 0x8209bf18
	ctx.lr = 0x820B1604;
	sub_8209BF18(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820b1960
	ctx.lr = 0x820B160C;
	sub_820B1960(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
