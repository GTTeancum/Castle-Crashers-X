DEFINE_REX_FUNC(sub_820D4870) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x820D4878;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// addi r10,r27,1152
	ctx.r10.s64 = ctx.r27.s64 + 1152;
	// li r11,18432
	ctx.r11.s64 = 18432;
	// addi r30,r10,-4
	ctx.r30.s64 = ctx.r10.s64 + -4;
	// lwz r4,48(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 48);
loc_820D4894:
	// cntlzd r10,r31
	ctx.r10.u64 = ctx.r31.u64 == 0 ? 64 : __builtin_clzll(ctx.r31.u64);
	// lwz r8,52(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 52);
	// clrldi r7,r10,32
	ctx.r7.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// mulli r9,r10,6
	ctx.r9.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(6));
	// sld r31,r31,r7
	ctx.r31.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r31.u64 << (ctx.r7.u8 & 0x7F));
	// not r7,r31
	ctx.r7.u64 = ~ctx.r31.u64;
	// add r28,r9,r11
	ctx.r28.u64 = ctx.r9.u64 + ctx.r11.u64;
	// cntlzd r26,r7
	ctx.r26.u64 = ctx.r7.u64 == 0 ? 64 : __builtin_clzll(ctx.r7.u64);
	// mulli r10,r10,24
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(24));
	// mulli r29,r26,6
	ctx.r29.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(6));
	// addi r11,r29,5
	ctx.r11.s64 = ctx.r29.s64 + 5;
	// add r30,r10,r30
	ctx.r30.u64 = ctx.r10.u64 + ctx.r30.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x820d4950
	if (ctx.cr6.lt) goto loc_820D4950;
	// li r8,6
	ctx.r8.s64 = 6;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820d3fe8
	ctx.lr = 0x820D48EC;
	sub_820D3FE8(ctx, base);
	// clrldi r10,r26,32
	ctx.r10.u64 = ctx.r26.u64 & 0xFFFFFFFF;
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// sld r31,r31,r10
	ctx.r31.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r31.u64 << (ctx.r10.u8 & 0x7F));
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// add r11,r29,r28
	ctx.r11.u64 = ctx.r29.u64 + ctx.r28.u64;
	// cmpldi cr6,r31,0
	ctx.cr6.compare<uint64_t>(ctx.r31.u64, 0, ctx.xer);
	// bne cr6,0x820d4894
	if (!ctx.cr6.eq) goto loc_820D4894;
	// lwz r11,56(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 56);
	// stw r4,48(r27)
	REX_STORE_U32(ctx.r27.u32 + 48, ctx.r4.u32);
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820d4924
	if (!ctx.cr6.gt) goto loc_820D4924;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820c7228
	ctx.lr = 0x820D4924;
	sub_820C7228(ctx, base);
loc_820D4924:
	// lis r11,2
	ctx.r11.s64 = 131072;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,20480
	ctx.r11.u64 = ctx.r11.u64 | 20480;
	// li r9,0
	ctx.r9.s64 = 0;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r27)
	REX_STORE_U32(ctx.r27.u32 + 48, ctx.r3.u32);
	// b 0x820d49c0
	goto loc_820D49C0;
loc_820D4950:
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// clrlwi r11,r4,29
	ctx.r11.u64 = ctx.r4.u32 & 0x7;
	// addi r9,r29,-1
	ctx.r9.s64 = ctx.r29.s64 + -1;
	// stw r10,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// add r4,r11,r4
	ctx.r4.u64 = ctx.r11.u64 + ctx.r4.u64;
	// rlwinm r10,r9,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r29,r28
	ctx.r11.u64 = ctx.r29.u64 + ctx.r28.u64;
	// or r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 | ctx.r28.u64;
	// stwu r10,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r4.u32 = ea;
loc_820D4974:
	// ld r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r30.u32 + 4);
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// ld r9,12(r30)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r30.u32 + 12);
	// rldicr r31,r31,1,62
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// ld r8,20(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 20);
	// addi r30,r30,24
	ctx.r30.s64 = ctx.r30.s64 + 24;
	// std r10,4(r4)
	REX_STORE_U64(ctx.r4.u32 + 4, ctx.r10.u64);
	// std r9,12(r4)
	REX_STORE_U64(ctx.r4.u32 + 12, ctx.r9.u64);
	// std r8,20(r4)
	REX_STORE_U64(ctx.r4.u32 + 20, ctx.r8.u64);
	// addi r4,r4,24
	ctx.r4.s64 = ctx.r4.s64 + 24;
	// bne 0x820d4974
	if (!ctx.cr0.eq) goto loc_820D4974;
	// cmpldi cr6,r31,0
	ctx.cr6.compare<uint64_t>(ctx.r31.u64, 0, ctx.xer);
	// bne cr6,0x820d4894
	if (!ctx.cr6.eq) goto loc_820D4894;
	// li r11,37
	ctx.r11.s64 = 37;
	// addi r10,r4,16
	ctx.r10.s64 = ctx.r4.s64 + 16;
	// rldicr r11,r11,44,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 44) & 0xFFFFF00000000000;
	// stw r10,48(r27)
	REX_STORE_U32(ctx.r27.u32 + 48, ctx.r10.u32);
	// std r11,4(r4)
	REX_STORE_U64(ctx.r4.u32 + 4, ctx.r11.u64);
	// std r11,12(r4)
	REX_STORE_U64(ctx.r4.u32 + 12, ctx.r11.u64);
loc_820D49C0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
