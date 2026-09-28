DEFINE_REX_FUNC(sub_8210CD28) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8210CD30;
	__savegprlr_29(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// bl 0x8210cc60
	ctx.lr = 0x8210CD44;
	sub_8210CC60(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8210cd58
	if (!ctx.cr0.eq) goto loc_8210CD58;
loc_8210CD4C:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4105
	ctx.r3.u64 = ctx.r3.u64 | 4105;
	// b 0x8210cda8
	goto loc_8210CDA8;
loc_8210CD58:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x820d7ed0
	ctx.lr = 0x8210CD68;
	sub_820D7ED0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8210cd4c
	if (!ctx.cr0.eq) goto loc_8210CD4C;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d7eb8
	ctx.lr = 0x8210CD80;
	sub_820D7EB8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8210cd9c
	if (ctx.cr0.eq) goto loc_8210CD9C;
	// cmpwi cr6,r3,10102
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 10102, ctx.xer);
	// bne cr6,0x8210cd4c
	if (!ctx.cr6.eq) goto loc_8210CD4C;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x8210cda8
	goto loc_8210CDA8;
loc_8210CD9C:
	// lhz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 36);
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r11,4(r30)
	REX_STORE_U16(ctx.r30.u32 + 4, ctx.r11.u16);
loc_8210CDA8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
