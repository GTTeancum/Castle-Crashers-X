DEFINE_REX_FUNC(sub_82128F70) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82128F78;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r11,-4096
	ctx.r11.s64 = -4096;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82129014
	if (ctx.cr6.gt) goto loc_82129014;
	// lis r28,-32221
	ctx.r28.s64 = -2111635456;
loc_82128F90:
	// bl 0x820bb280
	ctx.lr = 0x82128F94;
	sub_820BB280(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82128fb0
	if (!ctx.cr0.eq) goto loc_82128FB0;
	// bl 0x8212c3b0
	ctx.lr = 0x82128FA0;
	sub_8212C3B0(ctx, base);
	// li r3,30
	ctx.r3.s64 = 30;
	// bl 0x8212c368
	ctx.lr = 0x82128FA8;
	sub_8212C368(ctx, base);
	// li r3,255
	ctx.r3.s64 = 255;
	// bl 0x8212a040
	ctx.lr = 0x82128FB0;
	sub_8212A040(ctx, base);
loc_82128FB0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// bne cr6,0x82128fc0
	if (!ctx.cr6.eq) goto loc_82128FC0;
	// li r31,1
	ctx.r31.s64 = 1;
loc_82128FC0:
	// bl 0x820bb280
	ctx.lr = 0x82128FC4;
	sub_820BB280(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x820b9958
	ctx.lr = 0x82128FD0;
	sub_820B9958(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x8212900c
	if (!ctx.cr0.eq) goto loc_8212900C;
	// lwz r11,23312(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 23312);
	// li r31,12
	ctx.r31.s64 = 12;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82128ffc
	if (ctx.cr6.eq) goto loc_82128FFC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8212ec50
	ctx.lr = 0x82128FF0;
	sub_8212EC50(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82128f90
	if (!ctx.cr0.eq) goto loc_82128F90;
	// b 0x82129004
	goto loc_82129004;
loc_82128FFC:
	// bl 0x821294e0
	ctx.lr = 0x82129000;
	sub_821294E0(ctx, base);
	// stw r31,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
loc_82129004:
	// bl 0x821294e0
	ctx.lr = 0x82129008;
	sub_821294E0(ctx, base);
	// stw r31,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
loc_8212900C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// b 0x82129030
	goto loc_82129030;
loc_82129014:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8212ec50
	ctx.lr = 0x8212901C;
	sub_8212EC50(ctx, base);
	// bl 0x821294e0
	ctx.lr = 0x82129020;
	sub_821294E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,12
	ctx.r10.s64 = 12;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82129030:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
