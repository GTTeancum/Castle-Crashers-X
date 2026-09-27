DEFINE_REX_FUNC(sub_820D49C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x820D49D0;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r31,r6,-4
	ctx.r31.s64 = ctx.r6.s64 + -4;
	// lis r21,-32768
	ctx.r21.s64 = -2147483648;
	// li r22,4
	ctx.r22.s64 = 4;
	// lwz r4,48(r26)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + 48);
	// li r23,20
	ctx.r23.s64 = 20;
	// li r24,36
	ctx.r24.s64 = 36;
	// li r25,52
	ctx.r25.s64 = 52;
loc_820D49F8:
	// cntlzd r10,r30
	ctx.r10.u64 = ctx.r30.u64 == 0 ? 64 : __builtin_clzll(ctx.r30.u64);
	// lwz r9,52(r26)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r26.u32 + 52);
	// clrldi r8,r10,32
	ctx.r8.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rlwinm r11,r10,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// sld r30,r30,r8
	ctx.r30.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r30.u64 << (ctx.r8.u8 & 0x7F));
	// not r8,r30
	ctx.r8.u64 = ~ctx.r30.u64;
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cntlzd r28,r8
	ctx.r28.u64 = ctx.r8.u64 == 0 ? 64 : __builtin_clzll(ctx.r8.u64);
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r29,r28,4,0,27
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 4) & 0xFFFFFFF0;
	// add r27,r10,r5
	ctx.r27.u64 = ctx.r10.u64 + ctx.r5.u64;
	// addi r11,r29,3
	ctx.r11.s64 = ctx.r29.s64 + 3;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x820d4a6c
	if (ctx.cr6.lt) goto loc_820D4A6C;
	// li r8,16
	ctx.r8.s64 = 16;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x820d3fe8
	ctx.lr = 0x820D4A50;
	sub_820D3FE8(ctx, base);
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// clrldi r10,r28,32
	ctx.r10.u64 = ctx.r28.u64 & 0xFFFFFFFF;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r5,r29,r27
	ctx.r5.u64 = ctx.r29.u64 + ctx.r27.u64;
	// sld r30,r30,r10
	ctx.r30.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r30.u64 << (ctx.r10.u8 & 0x7F));
	// b 0x820d4b08
	goto loc_820D4B08;
loc_820D4A6C:
	// clrlwi r11,r4,28
	ctx.r11.u64 = ctx.r4.u32 & 0xF;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x820d4a84
	if (!ctx.cr6.eq) goto loc_820D4A84;
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// stwu r11,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r4.u32 = ea;
	// b 0x820d4ac0
	goto loc_820D4AC0;
loc_820D4A84:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d4aa0
	if (!ctx.cr6.eq) goto loc_820D4AA0;
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// stwu r11,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r4.u32 = ea;
	// stwu r10,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r4.u32 = ea;
	// b 0x820d4ac0
	goto loc_820D4AC0;
loc_820D4AA0:
	// cmplwi cr6,r11,12
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 12, ctx.xer);
	// bne cr6,0x820d4ac0
	if (!ctx.cr6.eq) goto loc_820D4AC0;
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// stwu r11,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r4.u32 = ea;
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// stwu r10,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r4.u32 = ea;
	// stwu r9,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r4.u32 = ea;
loc_820D4AC0:
	// addi r11,r29,-1
	ctx.r11.s64 = ctx.r29.s64 + -1;
	// add r5,r29,r27
	ctx.r5.u64 = ctx.r29.u64 + ctx.r27.u64;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// or r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 | ctx.r27.u64;
	// stwu r11,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r4.u32 = ea;
loc_820D4AD4:
	// lvx128 v63,r31,r22
	ea = (ctx.r31.u32 + ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// lvx128 v62,r31,r23
	ea = (ctx.r31.u32 + ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rldicr r30,r30,1,62
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// lvx128 v61,r31,r24
	ea = (ctx.r31.u32 + ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r31,r25
	ea = (ctx.r31.u32 + ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r31,64
	ctx.r31.s64 = ctx.r31.s64 + 64;
	// stvx128 v63,r4,r22
	ea = (ctx.r4.u32 + ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r4,r23
	ea = (ctx.r4.u32 + ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r4,r24
	ea = (ctx.r4.u32 + ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r4,r25
	ea = (ctx.r4.u32 + ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r4,64
	ctx.r4.s64 = ctx.r4.s64 + 64;
	// bne 0x820d4ad4
	if (!ctx.cr0.eq) goto loc_820D4AD4;
loc_820D4B08:
	// cmpldi cr6,r30,0
	ctx.cr6.compare<uint64_t>(ctx.r30.u64, 0, ctx.xer);
	// bne cr6,0x820d49f8
	if (!ctx.cr6.eq) goto loc_820D49F8;
	// stw r4,48(r26)
	REX_STORE_U32(ctx.r26.u32 + 48, ctx.r4.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
