DEFINE_REX_FUNC(sub_8208B948) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x8208B950;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// lwz r22,0(r31)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r29,8(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r22,1
	ctx.r11.s64 = ctx.r22.s64 + 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// ble cr6,0x8208ba64
	if (!ctx.cr6.gt) goto loc_8208BA64;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// lwz r30,4(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// rlwinm r28,r11,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x8208b9a0
	if (!ctx.cr6.gt) goto loc_8208B9A0;
	// li r28,-1
	ctx.r28.s64 = -1;
loc_8208B9A0:
	// lis r26,-32215
	ctx.r26.s64 = -2111242240;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r25,r11,-1768
	ctx.r25.s64 = ctx.r11.s64 + -1768;
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208b9cc
	if (!ctx.cr6.eq) goto loc_8208B9CC;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8208B9CC;
	sub_820A71E8(ctx, base);
loc_8208B9CC:
	// bl 0x820b5eb8
	ctx.lr = 0x8208B9D0;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r27,r11,29632
	ctx.r27.s64 = ctx.r11.s64 + 29632;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwzx r3,r10,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r27.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8208B9E8;
	sub_8209BDD8(ctx, base);
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8208ba64
	if (ctx.cr6.eq) goto loc_8208BA64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8208ba30
	if (ctx.cr6.eq) goto loc_8208BA30;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_8208BA04:
	// lhzx r8,r11,r30
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r30.u32);
	// add r9,r11,r30
	ctx.r9.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lwz r7,4(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// sthx r8,r7,r11
	REX_STORE_U16(ctx.r7.u32 + ctx.r11.u32, ctx.r8.u16);
	// lhz r6,2(r9)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r9.u32 + 2);
	// lwz r8,4(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + ctx.r11.u64;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// sth r6,2(r5)
	REX_STORE_U16(ctx.r5.u32 + 2, ctx.r6.u16);
	// bne 0x8208ba04
	if (!ctx.cr0.eq) goto loc_8208BA04;
loc_8208BA30:
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208ba50
	if (!ctx.cr6.eq) goto loc_8208BA50;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8208BA50;
	sub_820A71E8(ctx, base);
loc_8208BA50:
	// bl 0x820b5eb8
	ctx.lr = 0x8208BA54;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8208BA64;
	sub_8209BF18(ctx, base);
loc_8208BA64:
	// mr r9,r24
	ctx.r9.u64 = ctx.r24.u64;
	// mr r7,r23
	ctx.r7.u64 = ctx.r23.u64;
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x8208bac0
	if (ctx.cr6.eq) goto loc_8208BAC0;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r6,r22
	ctx.r6.u64 = ctx.r22.u64;
loc_8208BA7C:
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// lhzx r5,r10,r11
	ctx.r5.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r11.u32);
	// cmplw cr6,r5,r8
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r8.u32, ctx.xer);
	// ble cr6,0x8208bab4
	if (!ctx.cr6.gt) goto loc_8208BAB4;
	// sthx r9,r10,r11
	REX_STORE_U16(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u16);
	// clrlwi r5,r5,16
	ctx.r5.u64 = ctx.r5.u32 & 0xFFFF;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r8,r10,2
	ctx.r8.s64 = ctx.r10.s64 + 2;
	// lhz r8,2(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// sth r7,2(r10)
	REX_STORE_U16(ctx.r10.u32 + 2, ctx.r7.u16);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
loc_8208BAB4:
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bne 0x8208ba7c
	if (!ctx.cr0.eq) goto loc_8208BA7C;
loc_8208BAC0:
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// rlwinm r11,r22,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// sth r7,2(r10)
	REX_STORE_U16(ctx.r10.u32 + 2, ctx.r7.u16);
	// lwz r8,4(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// sthx r9,r8,r11
	REX_STORE_U16(ctx.r8.u32 + ctx.r11.u32, ctx.r9.u16);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
