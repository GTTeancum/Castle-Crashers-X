DEFINE_REX_FUNC(sub_820D5568) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x820D5570;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,20(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d56a4
	if (ctx.cr6.eq) goto loc_820D56A4;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// addi r26,r11,20
	ctx.r26.s64 = ctx.r11.s64 + 20;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// add r25,r11,r26
	ctx.r25.u64 = ctx.r11.u64 + ctx.r26.u64;
	// b 0x820d569c
	goto loc_820D569C;
loc_820D559C:
	// lhz r28,2(r26)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r26.u32 + 2);
	// addi r11,r26,4
	ctx.r11.s64 = ctx.r26.s64 + 4;
	// lhz r30,0(r26)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r26.u32 + 0);
	// cmplwi r28,0
	ctx.cr0.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq 0x820d56a4
	if (ctx.cr0.eq) goto loc_820D56A4;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r26,r11,4
	ctx.r26.s64 = ctx.r11.s64 + 4;
	// lbz r9,10940(r27)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r27.u32 + 10940);
	// add r31,r10,r24
	ctx.r31.u64 = ctx.r10.u64 + ctx.r24.u64;
	// rlwinm. r11,r9,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d5650
	if (ctx.cr0.eq) goto loc_820D5650;
	// bl 0x8214a6e4
	ctx.lr = 0x820D55CC;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x820d5650
	if (!ctx.cr6.eq) goto loc_820D5650;
	// addi r4,r28,1
	ctx.r4.s64 = ctx.r28.s64 + 1;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820c7458
	ctx.lr = 0x820D55E0;
	sub_820C7458(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x820d569c
	if (ctx.cr0.eq) goto loc_820D569C;
	// sync 
	// rlwinm r11,r31,12,20,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 12) & 0xFFF;
	// addi r10,r30,4096
	ctx.r10.s64 = ctx.r30.s64 + 4096;
	// addi r9,r28,-1
	ctx.r9.s64 = ctx.r28.s64 + -1;
	// addi r8,r11,512
	ctx.r8.s64 = ctx.r11.s64 + 512;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// clrlwi r11,r31,3
	ctx.r11.u64 = ctx.r31.u32 & 0x1FFFFFFF;
	// rlwinm r10,r8,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// rlwinm r31,r28,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// addis r30,r11,-16384
	ctx.r30.s64 = ctx.r11.s64 + -1073741824;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r29,4
	ctx.r3.s64 = ctx.r29.s64 + 4;
	// bl 0x82129a70
	ctx.lr = 0x820D5634;
	sub_82129A70(ctx, base);
	// add r4,r31,r30
	ctx.r4.u64 = ctx.r31.u64 + ctx.r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d6470
	ctx.lr = 0x820D5644;
	sub_820D6470(ctx, base);
	// add r11,r31,r29
	ctx.r11.u64 = ctx.r31.u64 + ctx.r29.u64;
	// stw r11,48(r27)
	REX_STORE_U32(ctx.r27.u32 + 48, ctx.r11.u32);
	// b 0x820d569c
	goto loc_820D569C;
loc_820D5650:
	// lwz r11,56(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 56);
	// lwz r3,48(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 48);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820d5668
	if (!ctx.cr6.gt) goto loc_820D5668;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820c7228
	ctx.lr = 0x820D5668;
	sub_820C7228(ctx, base);
loc_820D5668:
	// lis r10,-16382
	ctx.r10.s64 = -1073610752;
	// rlwinm r11,r31,12,20,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 12) & 0xFFF;
	// ori r10,r10,12032
	ctx.r10.u64 = ctx.r10.u64 | 12032;
	// addi r11,r11,512
	ctx.r11.s64 = ctx.r11.s64 + 512;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// clrlwi r10,r31,3
	ctx.r10.u64 = ctx.r31.u32 & 0x1FFFFFFF;
	// rlwinm r11,r11,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r28.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r27)
	REX_STORE_U32(ctx.r27.u32 + 48, ctx.r3.u32);
loc_820D569C:
	// cmplw cr6,r26,r25
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r25.u32, ctx.xer);
	// blt cr6,0x820d559c
	if (ctx.cr6.lt) goto loc_820D559C;
loc_820D56A4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
