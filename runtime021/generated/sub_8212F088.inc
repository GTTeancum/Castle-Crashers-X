DEFINE_REX_FUNC(sub_8212F088) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8212F090;
	__savegprlr_27(ctx, base);
	// addi r31,r1,-144
	ctx.r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// stw r27,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r27.u32);
	// cmpwi cr6,r27,-2
	ctx.cr6.compare<int32_t>(ctx.r27.s32, -2, ctx.xer);
	// bne cr6,0x8212f0c0
	if (!ctx.cr6.eq) goto loc_8212F0C0;
	// bl 0x821294e0
	ctx.lr = 0x8212F0AC;
	sub_821294E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x8212f1a8
	goto loc_8212F1A8;
loc_8212F0C0:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// blt cr6,0x8212f0d8
	if (ctx.cr6.lt) goto loc_8212F0D8;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lwz r11,2960(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 2960);
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8212f104
	if (ctx.cr6.lt) goto loc_8212F104;
loc_8212F0D8:
	// bl 0x821294e0
	ctx.lr = 0x8212F0DC;
	sub_821294E0(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8212c298
	ctx.lr = 0x8212F0FC;
	sub_8212C298(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8212f1a8
	goto loc_8212F1A8;
loc_8212F104:
	// srawi r11,r27,5
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r27.s32 >> 5;
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// rlwinm r28,r11,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r10,2976
	ctx.r29.s64 = ctx.r10.s64 + 2976;
	// rlwinm r30,r27,6,21,25
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 6) & 0x7C0;
	// lwzx r11,r28,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r29.u32);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212f0d8
	if (ctx.cr0.eq) goto loc_8212F0D8;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821348a8
	ctx.lr = 0x8212F134;
	sub_821348A8(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r28,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r29.u32);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212f184
	if (ctx.cr0.eq) goto loc_8212F184;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821347d8
	ctx.lr = 0x8212F154;
	sub_821347D8(ctx, base);
	// bl 0x820b6b40
	ctx.lr = 0x8212F158;
	sub_820B6B40(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8212f16c
	if (!ctx.cr0.eq) goto loc_8212F16C;
	// bl 0x820b6780
	ctx.lr = 0x8212F164;
	sub_820B6780(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x8212f170
	goto loc_8212F170;
loc_8212F16C:
	// li r30,0
	ctx.r30.s64 = 0;
loc_8212F170:
	// stw r30,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x8212f198
	if (ctx.cr6.eq) goto loc_8212F198;
	// bl 0x82129518
	ctx.lr = 0x8212F180;
	sub_82129518(ctx, base);
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
loc_8212F184:
	// bl 0x821294e0
	ctx.lr = 0x8212F188;
	sub_821294E0(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
loc_8212F198:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,144
	ctx.r12.s64 = ctx.r31.s64 + 144;
	// bl 0x8212f1d0
	ctx.lr = 0x8212F1A4;
	sub_8212F1D0(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
loc_8212F1A8:
	// addi r1,r31,144
	ctx.r1.s64 = ctx.r31.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
