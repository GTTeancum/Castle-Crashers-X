DEFINE_REX_FUNC(sub_820AAA78) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x820AAA80;
	__savegprlr_22(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// rlwinm r9,r3,16,16,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x820aaa98
	if (!ctx.cr6.eq) goto loc_820AAA98;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_820AAA98:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820aabec
	if (ctx.cr6.eq) goto loc_820AABEC;
	// lis r10,-32761
	ctx.r10.s64 = -2147024896;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r22,r10,32881
	ctx.r22.u64 = ctx.r10.u64 | 32881;
	// ori r23,r8,65521
	ctx.r23.u64 = ctx.r8.u64 | 65521;
loc_820AAAB0:
	// cmplwi cr6,r5,5552
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 5552, ctx.xer);
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// blt cr6,0x820aaac0
	if (ctx.cr6.lt) goto loc_820AAAC0;
	// li r24,5552
	ctx.r24.s64 = 5552;
loc_820AAAC0:
	// subf r5,r24,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r24.u64;
	// cmpwi cr6,r24,16
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 16, ctx.xer);
	// blt cr6,0x820aaba4
	if (ctx.cr6.lt) goto loc_820AABA4;
	// rlwinm r8,r24,0,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0xFFFFFFF0;
	// rlwinm r10,r24,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 28) & 0xFFFFFFF;
	// subf r24,r8,r24
	ctx.r24.u64 = ctx.r24.u64 - ctx.r8.u64;
loc_820AAAD8:
	// lbz r8,0(r4)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lbz r6,1(r4)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r4.u32 + 1);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lbz r3,2(r4)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r4.u32 + 2);
	// lbz r7,3(r4)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r4.u32 + 3);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lbz r8,4(r4)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r4.u32 + 4);
	// add r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 + ctx.r11.u64;
	// lbz r25,5(r4)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r4.u32 + 5);
	// lbz r26,6(r4)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r4.u32 + 6);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lbz r27,7(r4)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r4.u32 + 7);
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lbz r28,8(r4)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r4.u32 + 8);
	// lbz r29,9(r4)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r4.u32 + 9);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lbz r30,10(r4)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r4.u32 + 10);
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lbz r31,11(r4)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r4.u32 + 11);
	// lbz r3,12(r4)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r4.u32 + 12);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lbz r6,13(r4)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r4.u32 + 13);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lbz r7,14(r4)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r4.u32 + 14);
	// lbz r8,15(r4)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r4.u32 + 15);
	// addi r4,r4,16
	ctx.r4.s64 = ctx.r4.s64 + 16;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r25,r11
	ctx.r11.u64 = ctx.r25.u64 + ctx.r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r26,r11
	ctx.r11.u64 = ctx.r26.u64 + ctx.r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r27,r11
	ctx.r11.u64 = ctx.r27.u64 + ctx.r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// bne 0x820aaad8
	if (!ctx.cr0.eq) goto loc_820AAAD8;
loc_820AABA4:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x820aabc4
	if (ctx.cr6.eq) goto loc_820AABC4;
loc_820AABAC:
	// lbz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// addic. r24,r24,-1
	ctx.xer.ca = ctx.r24.u32 > 0;
	ctx.r24.s64 = ctx.r24.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// bne 0x820aabac
	if (!ctx.cr0.eq) goto loc_820AABAC;
loc_820AABC4:
	// mulhwu r10,r9,r22
	ctx.r10.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r22.u32)) >> 32;
	// mulhwu r8,r11,r22
	ctx.r8.u64 = (uint64_t(ctx.r11.u32) * uint64_t(ctx.r22.u32)) >> 32;
	// rlwinm r7,r8,17,15,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 17) & 0x1FFFF;
	// rlwinm r6,r10,17,15,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 17) & 0x1FFFF;
	// mullw r3,r7,r23
	ctx.r3.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r23.s32);
	// mullw r10,r6,r23
	ctx.r10.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r23.s32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// subf r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	// subf r9,r10,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r10.u64;
	// bne cr6,0x820aaab0
	if (!ctx.cr6.eq) goto loc_820AAAB0;
loc_820AABEC:
	// rlwinm r10,r9,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// or r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 | ctx.r11.u64;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
