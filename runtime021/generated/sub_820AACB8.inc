DEFINE_REX_FUNC(sub_820AACB8) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x820AACC0;
	__savegprlr_23(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r8,36(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// lwz r11,100(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// lwz r30,48(r7)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r7.u32 + 48);
	// addi r5,r8,-262
	ctx.r5.s64 = ctx.r8.s64 + -262;
	// lwz r9,112(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 112);
	// lwz r25,116(r7)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r7.u32 + 116);
	// add r10,r30,r11
	ctx.r10.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lwz r27,136(r7)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r7.u32 + 136);
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// ble cr6,0x820aacfc
	if (!ctx.cr6.gt) goto loc_820AACFC;
	// subf r11,r8,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r8.u64;
	// addi r26,r11,262
	ctx.r26.s64 = ctx.r11.s64 + 262;
	// b 0x820aad00
	goto loc_820AAD00;
loc_820AACFC:
	// li r26,0
	ctx.r26.s64 = 0;
loc_820AAD00:
	// add r11,r6,r10
	ctx.r11.u64 = ctx.r6.u64 + ctx.r10.u64;
	// lwz r8,132(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 132);
	// lwz r29,56(r7)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r7.u32 + 56);
	// addi r5,r10,258
	ctx.r5.s64 = ctx.r10.s64 + 258;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// lwz r28,44(r7)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r7.u32 + 44);
	// lbzx r8,r6,r10
	ctx.r8.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r10.u32);
	// lbz r31,-1(r11)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r11.u32 + -1);
	// blt cr6,0x820aad28
	if (ctx.cr6.lt) goto loc_820AAD28;
	// rlwinm r25,r25,30,2,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 30) & 0x3FFFFFFF;
loc_820AAD28:
	// lwz r3,108(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 108);
	// cmplw cr6,r27,r3
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r3.u32, ctx.xer);
	// ble cr6,0x820aad38
	if (!ctx.cr6.gt) goto loc_820AAD38;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_820AAD38:
	// add r11,r30,r4
	ctx.r11.u64 = ctx.r30.u64 + ctx.r4.u64;
	// clrlwi r24,r8,24
	ctx.r24.u64 = ctx.r8.u32 & 0xFF;
	// add r9,r11,r6
	ctx.r9.u64 = ctx.r11.u64 + ctx.r6.u64;
	// lbzx r23,r11,r6
	ctx.r23.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r6.u32);
	// cmplw cr6,r23,r24
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x820aae84
	if (!ctx.cr6.eq) goto loc_820AAE84;
	// lbz r9,-1(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + -1);
	// clrlwi r24,r31,24
	ctx.r24.u64 = ctx.r31.u32 & 0xFF;
	// cmplw cr6,r9,r24
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x820aae84
	if (!ctx.cr6.eq) goto loc_820AAE84;
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r24,0(r10)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r24
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x820aae84
	if (!ctx.cr6.eq) goto loc_820AAE84;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// lbz r24,1(r10)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// lbz r11,1(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// cmplw cr6,r11,r24
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x820aae84
	if (!ctx.cr6.eq) goto loc_820AAE84;
	// addi r11,r10,2
	ctx.r11.s64 = ctx.r10.s64 + 2;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
loc_820AAD8C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r24,0(r10)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r24
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x820aae54
	if (!ctx.cr6.eq) goto loc_820AAE54;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r24,0(r10)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r24
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x820aae54
	if (!ctx.cr6.eq) goto loc_820AAE54;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r24,0(r10)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r24
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x820aae54
	if (!ctx.cr6.eq) goto loc_820AAE54;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r24,0(r10)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r24
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x820aae54
	if (!ctx.cr6.eq) goto loc_820AAE54;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r24,0(r10)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r24
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x820aae54
	if (!ctx.cr6.eq) goto loc_820AAE54;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r24,0(r10)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r24
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x820aae54
	if (!ctx.cr6.eq) goto loc_820AAE54;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r24,0(r10)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r24
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x820aae54
	if (!ctx.cr6.eq) goto loc_820AAE54;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r24,0(r10)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r24
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x820aae54
	if (!ctx.cr6.eq) goto loc_820AAE54;
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x820aad8c
	if (ctx.cr6.lt) goto loc_820AAD8C;
loc_820AAE54:
	// subf r11,r5,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r5.u64;
	// addi r10,r5,-258
	ctx.r10.s64 = ctx.r5.s64 + -258;
	// addi r11,r11,258
	ctx.r11.s64 = ctx.r11.s64 + 258;
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// ble cr6,0x820aae84
	if (!ctx.cr6.gt) goto loc_820AAE84;
	// stw r4,104(r7)
	REX_STORE_U32(ctx.r7.u32 + 104, ctx.r4.u32);
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// cmpw cr6,r11,r27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r27.s32, ctx.xer);
	// bge cr6,0x820aaea0
	if (!ctx.cr6.lt) goto loc_820AAEA0;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbzx r8,r11,r10
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// lbz r31,-1(r9)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r9.u32 + -1);
loc_820AAE84:
	// and r11,r28,r4
	ctx.r11.u64 = ctx.r28.u64 & ctx.r4.u64;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r4,r9,r29
	ctx.r4.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// cmplw cr6,r4,r26
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r26.u32, ctx.xer);
	// ble cr6,0x820aaea0
	if (!ctx.cr6.gt) goto loc_820AAEA0;
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne 0x820aad38
	if (!ctx.cr0.eq) goto loc_820AAD38;
loc_820AAEA0:
	// cmplw cr6,r6,r3
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r3.u32, ctx.xer);
	// bgt cr6,0x820aaeac
	if (ctx.cr6.gt) goto loc_820AAEAC;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
loc_820AAEAC:
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
