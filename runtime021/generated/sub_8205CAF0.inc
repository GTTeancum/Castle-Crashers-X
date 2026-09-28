DEFINE_REX_FUNC(sub_8205CAF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x8205CAF8;
	__savegprlr_21(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r27,-32218
	ctx.r27.s64 = -2111438848;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r10,48(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r28,-6612(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + -6612);
	// li r25,0
	ctx.r25.s64 = 0;
	// lfs f0,9700(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9700);
	ctx.f0.f64 = double(temp.f32);
	// lwz r30,-6596(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + -6596);
	// lhz r8,10(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// lfs f13,108(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// extsh r23,r8
	ctx.r23.s64 = ctx.r8.s16;
	// addi r7,r23,5
	ctx.r7.s64 = ctx.r23.s64 + 5;
	// rlwinm r31,r7,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r31,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// fctidz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f11.u64);
	// lbz r24,95(r1)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r1.u32 + 95);
	// bl 0x8209d3d8
	ctx.lr = 0x8205CB54;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwzx r4,r31,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d488
	ctx.lr = 0x8205CB64;
	sub_8209D488(ctx, base);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lbz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// cmplw cr6,r6,r4
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8205cb78
	if (ctx.cr6.eq) goto loc_8205CB78;
	// li r25,1
	ctx.r25.s64 = 1;
loc_8205CB78:
	// lfs f13,104(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// li r5,2
	ctx.r5.s64 = 2;
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwzx r4,r31,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// fctidz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f11.u64);
	// lbz r22,95(r1)
	ctx.r22.u64 = REX_LOAD_U8(ctx.r1.u32 + 95);
	// bl 0x8209d3d8
	ctx.lr = 0x8205CB9C;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwzx r4,r31,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d488
	ctx.lr = 0x8205CBAC;
	sub_8209D488(ctx, base);
	// lbz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8205cbc0
	if (ctx.cr6.eq) goto loc_8205CBC0;
	// li r25,1
	ctx.r25.s64 = 1;
loc_8205CBC0:
	// lis r21,-32218
	ctx.r21.s64 = -2111438848;
	// rlwinm r10,r23,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-6624(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + -6624);
	// lwz r9,1756(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 1756);
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205cc0c
	if (ctx.cr6.eq) goto loc_8205CC0C;
	// bl 0x82078d90
	ctx.lr = 0x8205CBE0;
	sub_82078D90(ctx, base);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8205cbfc
	if (ctx.cr6.eq) goto loc_8205CBFC;
	// lbz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 16);
	// lwz r30,-6596(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + -6596);
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// b 0x8205cc10
	goto loc_8205CC10;
loc_8205CBFC:
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r30,-6596(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + -6596);
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// b 0x8205cc10
	goto loc_8205CC10;
loc_8205CC0C:
	// li r28,0
	ctx.r28.s64 = 0;
loc_8205CC10:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwzx r4,r31,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x8205CC20;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwzx r4,r31,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// bl 0x8209d488
	ctx.lr = 0x8205CC30;
	sub_8209D488(ctx, base);
	// lbz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// clrlwi r11,r28,24
	ctx.r11.u64 = ctx.r28.u32 & 0xFF;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8205cc44
	if (ctx.cr6.eq) goto loc_8205CC44;
	// li r25,1
	ctx.r25.s64 = 1;
loc_8205CC44:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lbz r26,8(r30)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r30.u32 + 8);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8205CC5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r30,-6596(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + -6596);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x8205cc9c
	if (ctx.cr6.eq) goto loc_8205CC9C;
	// li r5,73
	ctx.r5.s64 = 73;
	// lwzx r4,r31,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x8205CC78;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwzx r4,r31,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// bl 0x8209d488
	ctx.lr = 0x8205CC88;
	sub_8209D488(ctx, base);
	// lbz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// clrlwi r11,r26,24
	ctx.r11.u64 = ctx.r26.u32 & 0xFF;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8205cc9c
	if (ctx.cr6.eq) goto loc_8205CC9C;
	// li r25,1
	ctx.r25.s64 = 1;
loc_8205CC9C:
	// clrlwi r11,r25,24
	ctx.r11.u64 = ctx.r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8205cdd4
	if (ctx.cr6.eq) goto loc_8205CDD4;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwzx r4,r31,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x8205CCB8;
	sub_8209D3D8(ctx, base);
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwzx r4,r31,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// bl 0x8209d538
	ctx.lr = 0x8205CCC8;
	sub_8209D538(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwzx r4,r31,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// bl 0x8209d3d8
	ctx.lr = 0x8205CCD8;
	sub_8209D3D8(ctx, base);
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwzx r4,r31,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// bl 0x8209d538
	ctx.lr = 0x8205CCE8;
	sub_8209D538(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwzx r4,r31,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// bl 0x8209d3d8
	ctx.lr = 0x8205CCF8;
	sub_8209D3D8(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwzx r4,r31,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// bl 0x8209d538
	ctx.lr = 0x8205CD08;
	sub_8209D538(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8205CD1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r6,-6596(r27)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r27.u32 + -6596);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x8205cd48
	if (ctx.cr6.eq) goto loc_8205CD48;
	// li r5,73
	ctx.r5.s64 = 73;
	// lwzx r4,r31,r6
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r6.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x8205CD38;
	sub_8209D3D8(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwzx r4,r31,r6
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r6.u32);
	// bl 0x8209d538
	ctx.lr = 0x8205CD48;
	sub_8209D538(ctx, base);
loc_8205CD48:
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x820a0988
	ctx.lr = 0x8205CD58;
	sub_820A0988(ctx, base);
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x8205cdd4
	if (!ctx.cr6.eq) goto loc_8205CDD4;
	// li r6,64
	ctx.r6.s64 = 64;
	// lwz r3,-6624(r21)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r21.u32 + -6624);
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82077310
	ctx.lr = 0x8205CD78;
	sub_82077310(ctx, base);
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82053bc8
	ctx.lr = 0x8205CD84;
	sub_82053BC8(ctx, base);
	// lwz r11,48(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,529
	ctx.r4.s64 = 529;
	// lwz r3,24(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// bl 0x82067230
	ctx.lr = 0x8205CD98;
	sub_82067230(ctx, base);
	// lwz r10,48(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,530
	ctx.r4.s64 = 530;
	// lwz r3,28(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// bl 0x82067230
	ctx.lr = 0x8205CDAC;
	sub_82067230(ctx, base);
	// lwz r9,48(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,531
	ctx.r4.s64 = 531;
	// lwz r3,32(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 32);
	// bl 0x82067230
	ctx.lr = 0x8205CDC0;
	sub_82067230(ctx, base);
	// lis r8,-32215
	ctx.r8.s64 = -2111242240;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,-22668(r8)
	REX_STORE_U32(ctx.r8.u32 + -22668, ctx.r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
loc_8205CDD4:
	// lwz r11,48(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lhz r4,390(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 390);
	// bl 0x82053bc8
	ctx.lr = 0x8205CDE4;
	sub_82053BC8(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
