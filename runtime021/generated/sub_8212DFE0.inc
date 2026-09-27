DEFINE_REX_FUNC(sub_8212DFE0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8212DFE8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x8212e008
	if (!ctx.cr6.eq) goto loc_8212E008;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82128f70
	ctx.lr = 0x8212E004;
	sub_82128F70(ctx, base);
	// b 0x8212e094
	goto loc_8212E094;
loc_8212E008:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8212e01c
	if (!ctx.cr6.eq) goto loc_8212E01C;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82129880
	ctx.lr = 0x8212E018;
	sub_82129880(ctx, base);
	// b 0x8212e090
	goto loc_8212E090;
loc_8212E01C:
	// li r29,-4096
	ctx.r29.s64 = -4096;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bgt cr6,0x8212e078
	if (ctx.cr6.gt) goto loc_8212E078;
	// lis r27,-32221
	ctx.r27.s64 = -2111635456;
loc_8212E02C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8212e038
	if (!ctx.cr6.eq) goto loc_8212E038;
	// li r31,1
	ctx.r31.s64 = 1;
loc_8212E038:
	// bl 0x820bb280
	ctx.lr = 0x8212E03C;
	sub_820BB280(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// bl 0x820ba518
	ctx.lr = 0x8212E04C;
	sub_820BA518(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8212e0c8
	if (!ctx.cr0.eq) goto loc_8212E0C8;
	// lwz r11,23312(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 23312);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8212e0b4
	if (ctx.cr6.eq) goto loc_8212E0B4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8212ec50
	ctx.lr = 0x8212E068;
	sub_8212EC50(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8212e09c
	if (ctx.cr0.eq) goto loc_8212E09C;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// ble cr6,0x8212e02c
	if (!ctx.cr6.gt) goto loc_8212E02C;
loc_8212E078:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8212ec50
	ctx.lr = 0x8212E080;
	sub_8212EC50(ctx, base);
	// bl 0x821294e0
	ctx.lr = 0x8212E084;
	sub_821294E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,12
	ctx.r10.s64 = 12;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8212E090:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8212E094:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8212E09C:
	// bl 0x821294e0
	ctx.lr = 0x8212E0A0;
	sub_821294E0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x820b6780
	ctx.lr = 0x8212E0A8;
	sub_820B6780(ctx, base);
	// bl 0x82129470
	ctx.lr = 0x8212E0AC;
	sub_82129470(ctx, base);
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// b 0x8212e090
	goto loc_8212E090;
loc_8212E0B4:
	// bl 0x821294e0
	ctx.lr = 0x8212E0B8;
	sub_821294E0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x820b6780
	ctx.lr = 0x8212E0C0;
	sub_820B6780(ctx, base);
	// bl 0x82129470
	ctx.lr = 0x8212E0C4;
	sub_82129470(ctx, base);
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
loc_8212E0C8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// b 0x8212e094
	goto loc_8212E094;
}
