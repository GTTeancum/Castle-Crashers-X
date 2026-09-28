DEFINE_REX_FUNC(sub_8211B2A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x8211B2A8;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// lwz r5,96(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r11,656(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 656);
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// bge cr6,0x8211b32c
	if (!ctx.cr6.lt) goto loc_8211B32C;
	// addi r29,r31,572
	ctx.r29.s64 = ctx.r31.s64 + 572;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82122118
	ctx.lr = 0x8211B2DC;
	sub_82122118(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8211b334
	if (ctx.cr0.lt) goto loc_8211B334;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// li r4,0
	ctx.r4.s64 = 0;
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// clrlwi r6,r11,31
	ctx.r6.u64 = ctx.r11.u32 & 0x1;
	// bl 0x82124570
	ctx.lr = 0x8211B304;
	sub_82124570(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8211b334
	if (ctx.cr0.lt) goto loc_8211B334;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r6,r31,624
	ctx.r6.s64 = ctx.r31.s64 + 624;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x821245d8
	ctx.lr = 0x8211B324;
	sub_821245D8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8211b344
	if (!ctx.cr0.eq) goto loc_8211B344;
loc_8211B32C:
	// lis r30,-32646
	ctx.r30.s64 = -2139488256;
	// ori r30,r30,4109
	ctx.r30.u64 = ctx.r30.u64 | 4109;
loc_8211B334:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821210b0
	ctx.lr = 0x8211B340;
	sub_821210B0(ctx, base);
	// b 0x8211b3a8
	goto loc_8211B3A8;
loc_8211B344:
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r31,604
	ctx.r9.s64 = ctx.r31.s64 + 604;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r10,24
	ctx.r11.s64 = ctx.r10.s64 + 24;
	// stw r9,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r9.u32);
	// lwz r9,608(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 608);
	// stw r9,28(r10)
	REX_STORE_U32(ctx.r10.u32 + 28, ctx.r9.u32);
	// lwz r10,608(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 608);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r11,608(r31)
	REX_STORE_U32(ctx.r31.u32 + 608, ctx.r11.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r11,r11,2,6,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x3FFFFFC;
	// stwx r9,r11,r10
	REX_STORE_U32(ctx.r11.u32 + ctx.r10.u32, ctx.r9.u32);
	// lwz r10,652(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 652);
	// lwz r9,636(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 636);
	// lwz r8,88(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r11,656(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 656);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,656(r31)
	REX_STORE_U32(ctx.r31.u32 + 656, ctx.r11.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// subf r11,r8,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r8.u64;
	// stw r10,652(r31)
	REX_STORE_U32(ctx.r31.u32 + 652, ctx.r10.u32);
	// stw r11,636(r31)
	REX_STORE_U32(ctx.r31.u32 + 636, ctx.r11.u32);
loc_8211B3A8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
