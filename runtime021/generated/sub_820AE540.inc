DEFINE_REX_FUNC(sub_820AE540) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x820AE548;
	__savegprlr_23(ctx, base);
	// lwz r8,8(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// addi r11,r3,2868
	ctx.r11.s64 = ctx.r3.s64 + 2868;
	// lwz r25,0(r4)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r23,4(r4)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,16
	ctx.r10.s64 = 16;
	// lwz r4,0(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r26,4(r8)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r30,8(r8)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r27,16(r8)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820AE578:
	// sth r9,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r9.u16);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// bdnz 0x820ae578
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820AE578;
	// lwz r11,5196(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 5196);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,725
	ctx.r9.s64 = ctx.r11.s64 + 725;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r3
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// rlwinm r11,r7,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r25
	ctx.r6.u64 = ctx.r11.u64 + ctx.r25.u64;
	// sth r10,2(r6)
	REX_STORE_U16(ctx.r6.u32 + 2, ctx.r10.u16);
	// lwz r11,5196(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 5196);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r11,573
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 573, ctx.xer);
	// bge cr6,0x820ae788
	if (!ctx.cr6.lt) goto loc_820AE788;
	// addi r10,r11,725
	ctx.r10.s64 = ctx.r11.s64 + 725;
	// subfic r28,r11,573
	ctx.xer.ca = ctx.r11.u32 <= 573;
	ctx.r28.u64 = static_cast<uint64_t>(573) - ctx.r11.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r24,r28,r11
	ctx.r24.u64 = ctx.r28.u64 + ctx.r11.u64;
	// add r31,r10,r3
	ctx.r31.u64 = ctx.r10.u64 + ctx.r3.u64;
loc_820AE5C8:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r5,r25
	ctx.r6.u64 = ctx.r5.u64 + ctx.r25.u64;
	// lhz r11,2(r6)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r6.u32 + 2);
	// rotlwi r11,r11,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// add r9,r11,r25
	ctx.r9.u64 = ctx.r11.u64 + ctx.r25.u64;
	// lhz r11,2(r9)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r9.u32 + 2);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpw cr6,r11,r27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r27.s32, ctx.xer);
	// ble cr6,0x820ae5f8
	if (!ctx.cr6.gt) goto loc_820AE5F8;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
loc_820AE5F8:
	// cmpw cr6,r10,r23
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r23.s32, ctx.xer);
	// sth r11,2(r6)
	REX_STORE_U16(ctx.r6.u32 + 2, ctx.r11.u16);
	// bgt cr6,0x820ae670
	if (ctx.cr6.gt) goto loc_820AE670;
	// addi r8,r11,1434
	ctx.r8.s64 = ctx.r11.s64 + 1434;
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r10,r30
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r30.s32, ctx.xer);
	// lhzx r7,r8,r3
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r3.u32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// sthx r7,r8,r3
	REX_STORE_U16(ctx.r8.u32 + ctx.r3.u32, ctx.r7.u16);
	// blt cr6,0x820ae630
	if (ctx.cr6.lt) goto loc_820AE630;
	// subf r10,r30,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r30.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r26
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r26.u32);
loc_820AE630:
	// lhz r10,0(r6)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r6.u32 + 0);
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwz r8,5792(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 5792);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// mullw r10,r7,r11
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r11.s32);
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stw r6,5792(r3)
	REX_STORE_U32(ctx.r3.u32 + 5792, ctx.r6.u32);
	// beq cr6,0x820ae670
	if (ctx.cr6.eq) goto loc_820AE670;
	// add r8,r5,r4
	ctx.r8.u64 = ctx.r5.u64 + ctx.r4.u64;
	// lwz r10,5796(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 5796);
	// lhz r8,2(r8)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r8.u32 + 2);
	// add r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r11,r7,r11
	ctx.r11.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r11.s32);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r6,5796(r3)
	REX_STORE_U32(ctx.r3.u32 + 5796, ctx.r6.u32);
loc_820AE670:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x820ae5c8
	if (!ctx.cr0.eq) goto loc_820AE5C8;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x820ae788
	if (ctx.cr6.eq) goto loc_820AE788;
	// addi r11,r27,1434
	ctx.r11.s64 = ctx.r27.s64 + 1434;
	// addi r6,r27,-1
	ctx.r6.s64 = ctx.r27.s64 + -1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r3
	ctx.r7.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r9,r11,65535
	ctx.r9.u64 = ctx.r11.u64 | 65535;
loc_820AE69C:
	// addi r10,r6,1434
	ctx.r10.s64 = ctx.r6.s64 + 1434;
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// lhz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x820ae6cc
	if (!ctx.cr6.eq) goto loc_820AE6CC;
loc_820AE6B8:
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lhz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820ae6b8
	if (ctx.cr6.eq) goto loc_820AE6B8;
loc_820AE6CC:
	// addi r10,r11,1434
	ctx.r10.s64 = ctx.r11.s64 + 1434;
	// addi r8,r11,1435
	ctx.r8.s64 = ctx.r11.s64 + 1435;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r8,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// addic. r29,r29,-2
	ctx.xer.ca = ctx.r29.u32 > 1;
	ctx.r29.s64 = ctx.r29.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// lhzx r5,r10,r3
	ctx.r5.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r3.u32);
	// lhzx r8,r11,r3
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r3.u32);
	// add r4,r5,r9
	ctx.r4.u64 = ctx.r5.u64 + ctx.r9.u64;
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// sthx r4,r10,r3
	REX_STORE_U16(ctx.r10.u32 + ctx.r3.u32, ctx.r4.u16);
	// sthx r8,r11,r3
	REX_STORE_U16(ctx.r11.u32 + ctx.r3.u32, ctx.r8.u16);
	// lhz r11,0(r7)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r7.u32 + 0);
	// add r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 + ctx.r9.u64;
	// sth r10,0(r7)
	REX_STORE_U16(ctx.r7.u32 + 0, ctx.r10.u16);
	// bgt 0x820ae69c
	if (ctx.cr0.gt) goto loc_820AE69C;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x820ae788
	if (ctx.cr6.eq) goto loc_820AE788;
loc_820AE714:
	// lhz r5,0(r7)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r7.u32 + 0);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x820ae77c
	if (ctx.cr6.eq) goto loc_820AE77C;
	// addi r11,r24,725
	ctx.r11.s64 = ctx.r24.s64 + 725;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r3
	ctx.r6.u64 = ctx.r11.u64 + ctx.r3.u64;
loc_820AE72C:
	// addi r6,r6,-4
	ctx.r6.s64 = ctx.r6.s64 + -4;
	// addi r24,r24,-1
	ctx.r24.s64 = ctx.r24.s64 + -1;
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmpw cr6,r11,r23
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r23.s32, ctx.xer);
	// bgt cr6,0x820ae774
	if (ctx.cr6.gt) goto loc_820AE774;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// lhz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x820ae770
	if (ctx.cr6.eq) goto loc_820AE770;
	// lhz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// lwz r8,5792(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 5792);
	// mullw r10,r10,r4
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stw r8,5792(r3)
	REX_STORE_U32(ctx.r3.u32 + 5792, ctx.r8.u32);
	// sth r9,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r9.u16);
loc_820AE770:
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
loc_820AE774:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x820ae72c
	if (!ctx.cr6.eq) goto loc_820AE72C;
loc_820AE77C:
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r7,r7,-2
	ctx.r7.s64 = ctx.r7.s64 + -2;
	// bne 0x820ae714
	if (!ctx.cr0.eq) goto loc_820AE714;
loc_820AE788:
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
