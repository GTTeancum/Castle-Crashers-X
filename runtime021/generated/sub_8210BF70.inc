DEFINE_REX_FUNC(sub_8210BF70) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8210BF78;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8210bfa8
	if (ctx.cr6.eq) goto loc_8210BFA8;
	// addi r10,r4,4
	ctx.r10.s64 = ctx.r4.s64 + 4;
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
loc_8210BF94:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// add r28,r28,r9
	ctx.r28.u64 = ctx.r28.u64 + ctx.r9.u64;
	// bne 0x8210bf94
	if (!ctx.cr0.eq) goto loc_8210BF94;
loc_8210BFA8:
	// lwz r11,40(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 40);
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8210bfc0
	if (!ctx.cr6.gt) goto loc_8210BFC0;
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4102
	ctx.r3.u64 = ctx.r3.u64 | 4102;
	// b 0x8210c000
	goto loc_8210C000;
loc_8210BFC0:
	// addi r29,r27,124
	ctx.r29.s64 = ctx.r27.s64 + 124;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8210bff8
	if (ctx.cr6.eq) goto loc_8210BFF8;
	// addi r31,r4,4
	ctx.r31.s64 = ctx.r4.s64 + 4;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
loc_8210BFD4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,0(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r4,-4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + -4);
	// bl 0x82129a70
	ctx.lr = 0x8210BFE4;
	sub_82129A70(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bne 0x8210bfd4
	if (!ctx.cr0.eq) goto loc_8210BFD4;
loc_8210BFF8:
	// stw r28,44(r27)
	REX_STORE_U32(ctx.r27.u32 + 44, ctx.r28.u32);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8210C000:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
