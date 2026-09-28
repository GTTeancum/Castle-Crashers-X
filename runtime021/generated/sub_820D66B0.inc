DEFINE_REX_FUNC(sub_820D66B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x820D66B8;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// addi r27,r11,8
	ctx.r27.s64 = ctx.r11.s64 + 8;
	// lwz r26,4(r11)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_820D66D0:
	// lwz r4,0(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// cmplw cr6,r10,r4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, ctx.xer);
	// bge cr6,0x820d6788
	if (!ctx.cr6.lt) goto loc_820D6788;
	// addi r5,r26,-1
	ctx.r5.s64 = ctx.r26.s64 + -1;
	// addi r11,r10,8
	ctx.r11.s64 = ctx.r10.s64 + 8;
loc_820D66E8:
	// lhz r8,2(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// rlwinm r9,r5,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// lhz r7,-2(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + -2);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lhz r30,-4(r11)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r11.u32 + -4);
	// lhz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r9,r9,r27
	ctx.r9.u64 = ctx.r9.u64 + ctx.r27.u64;
	// lwz r31,0(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r28,r8,3,0,28
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// rotlwi r30,r30,3
	ctx.r30.u64 = __builtin_rotateleft32(ctx.r30.u32, 3);
	// rlwinm r7,r7,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// rotlwi r29,r29,3
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r29.u32, 3);
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
loc_820D6728:
	// lwz r24,-4(r9)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r9.u32 + -4);
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r24,r7
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x820d6760
	if (!ctx.cr6.lt) goto loc_820D6760;
	// lwz r24,4(r9)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// cmplw cr6,r24,r30
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r30.u32, ctx.xer);
	// ble cr6,0x820d6760
	if (!ctx.cr6.gt) goto loc_820D6760;
	// lwz r24,0(r9)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r24,r28
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r28.u32, ctx.xer);
	// bge cr6,0x820d6760
	if (!ctx.cr6.lt) goto loc_820D6760;
	// lwz r24,8(r9)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r24,r29
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r29.u32, ctx.xer);
	// ble cr6,0x820d6760
	if (!ctx.cr6.gt) goto loc_820D6760;
	// ori r6,r6,3
	ctx.r6.u64 = ctx.r6.u64 | 3;
loc_820D6760:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// addi r9,r9,-16
	ctx.r9.s64 = ctx.r9.s64 + -16;
	// bne cr6,0x820d6728
	if (!ctx.cr6.eq) goto loc_820D6728;
	// oris r9,r6,32768
	ctx.r9.u64 = ctx.r6.u64 | 2147483648;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// cmplw cr6,r10,r4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, ctx.xer);
	// blt cr6,0x820d66e8
	if (ctx.cr6.lt) goto loc_820D66E8;
loc_820D6788:
	// lwz r31,0(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x820d679c
	if (ctx.cr6.eq) goto loc_820D679C;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x820d6470
	ctx.lr = 0x820D679C;
	sub_820D6470(ctx, base);
loc_820D679C:
	// lis r11,-16384
	ctx.r11.s64 = -1073741824;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820d66d0
	if (!ctx.cr6.eq) goto loc_820D66D0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
