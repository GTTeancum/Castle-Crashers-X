DEFINE_REX_FUNC(sub_82114BC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82114BC8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r29,12(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82114c38
	if (ctx.cr6.eq) goto loc_82114C38;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82114c18
	if (ctx.cr6.eq) goto loc_82114C18;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r31,24(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x821151c8
	ctx.lr = 0x82114BF8;
	sub_821151C8(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// bl 0x82112d10
	ctx.lr = 0x82114C0C;
	sub_82112D10(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82114c68
	if (!ctx.cr0.eq) goto loc_82114C68;
	// b 0x82114c54
	goto loc_82114C54;
loc_82114C18:
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r7,32(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r6,28(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r5,24(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x82113668
	ctx.lr = 0x82114C34;
	sub_82113668(ctx, base);
	// b 0x82114c4c
	goto loc_82114C4C;
loc_82114C38:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r6,32(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r5,28(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x821145b0
	ctx.lr = 0x82114C4C;
	sub_821145B0(ctx, base);
loc_82114C4C:
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82114c58
	if (!ctx.cr0.eq) goto loc_82114C58;
loc_82114C54:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82114C58:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82114c68
	if (ctx.cr6.eq) goto loc_82114C68;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821151c8
	ctx.lr = 0x82114C68;
	sub_821151C8(ctx, base);
loc_82114C68:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
