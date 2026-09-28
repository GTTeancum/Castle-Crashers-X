DEFINE_REX_FUNC(sub_820FCEA0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x820FCEA8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r29,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r29.u64);
	// lis r6,8192
	ctx.r6.s64 = 536870912;
	// li r8,8
	ctx.r8.s64 = 8;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// ori r6,r6,3
	ctx.r6.u64 = ctx.r6.u64 | 3;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82108ea0
	ctx.lr = 0x820FCED8;
	sub_82108EA0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820fcfa4
	if (ctx.cr0.lt) goto loc_820FCFA4;
	// ld r11,648(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 648);
	// lis r6,8192
	ctx.r6.s64 = 536870912;
	// ld r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// li r8,8
	ctx.r8.s64 = 8;
	// std r29,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r29.u64);
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// ori r6,r6,7
	ctx.r6.u64 = ctx.r6.u64 | 7;
	// std r11,648(r31)
	REX_STORE_U64(ctx.r31.u32 + 648, ctx.r11.u64);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82108ea0
	ctx.lr = 0x820FCF14;
	sub_82108EA0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820fcfa4
	if (ctx.cr0.lt) goto loc_820FCFA4;
	// ld r11,656(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 656);
	// lis r6,8192
	ctx.r6.s64 = 536870912;
	// ld r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// ori r6,r6,2
	ctx.r6.u64 = ctx.r6.u64 | 2;
	// std r11,656(r31)
	REX_STORE_U64(ctx.r31.u32 + 656, ctx.r11.u64);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82108ea0
	ctx.lr = 0x820FCF50;
	sub_82108EA0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820fcfa4
	if (ctx.cr0.lt) goto loc_820FCFA4;
	// lwz r10,712(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 712);
	// lis r6,8192
	ctx.r6.s64 = 536870912;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// ori r6,r6,6
	ctx.r6.u64 = ctx.r6.u64 | 6;
	// stw r11,712(r31)
	REX_STORE_U32(ctx.r31.u32 + 712, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82108ea0
	ctx.lr = 0x820FCF8C;
	sub_82108EA0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820fcfa4
	if (ctx.cr0.lt) goto loc_820FCFA4;
	// lwz r11,716(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 716);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,716(r31)
	REX_STORE_U32(ctx.r31.u32 + 716, ctx.r11.u32);
loc_820FCFA4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
