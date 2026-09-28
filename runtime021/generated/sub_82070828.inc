DEFINE_REX_FUNC(sub_82070828) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x82070830;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r27,-1
	ctx.r27.s64 = -1;
	// lis r28,-32218
	ctx.r28.s64 = -2111438848;
	// lis r29,-32218
	ctx.r29.s64 = -2111438848;
	// addi r26,r11,-1712
	ctx.r26.s64 = ctx.r11.s64 + -1712;
loc_82070848:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r3,-6620(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -6620);
	// bl 0x820b6020
	ctx.lr = 0x82070854;
	sub_820B6020(ctx, base);
	// lwz r31,-6656(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + -6656);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x820708ec
	if (ctx.cr6.eq) goto loc_820708EC;
	// addi r30,r31,14488
	ctx.r30.s64 = ctx.r31.s64 + 14488;
loc_8207086C:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// bl 0x82096530
	ctx.lr = 0x82070884;
	sub_82096530(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820708a8
	if (ctx.cr6.eq) goto loc_820708A8;
	// lwz r11,24(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820708b0
	if (!ctx.cr6.eq) goto loc_820708B0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820960a8
	ctx.lr = 0x820708A4;
	sub_820960A8(ctx, base);
	// b 0x820708b0
	goto loc_820708B0;
loc_820708A8:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x820708B0;
	sub_8208C5D8(ctx, base);
loc_820708B0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a434
	ctx.lr = 0x820708B8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srawi r10,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 5;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,5,0,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r7,r8,r11
	ctx.r7.u64 = ctx.r11.u64 - ctx.r8.u64;
	// stw r7,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
	// bl 0x8214a444
	ctx.lr = 0x820708DC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r5,0(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpw cr6,r6,r5
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, ctx.xer);
	// bne cr6,0x8207086c
	if (!ctx.cr6.eq) goto loc_8207086C;
loc_820708EC:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-6620(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -6620);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x820b5fe8
	ctx.lr = 0x820708FC;
	sub_820B5FE8(ctx, base);
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x820b6068
	ctx.lr = 0x82070904;
	sub_820B6068(ctx, base);
	// b 0x82070848
	goto loc_82070848;
}
