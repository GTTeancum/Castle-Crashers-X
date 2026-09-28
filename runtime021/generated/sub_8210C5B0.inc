DEFINE_REX_FUNC(sub_8210C5B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x8210C5B8;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stw r25,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// cmplwi cr6,r31,1199
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1199, ctx.xer);
	// ble cr6,0x8210c5ec
	if (!ctx.cr6.gt) goto loc_8210C5EC;
	// lis r27,-32646
	ctx.r27.s64 = -2139488256;
	// ori r27,r27,4102
	ctx.r27.u64 = ctx.r27.u64 | 4102;
	// b 0x8210c648
	goto loc_8210C648;
loc_8210C5EC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8210c908
	ctx.lr = 0x8210C5F4;
	sub_8210C908(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// blt 0x8210c638
	if (ctx.cr0.lt) goto loc_8210C638;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8210c548
	ctx.lr = 0x8210C614;
	sub_8210C548(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8210c628
	if (!ctx.cr0.eq) goto loc_8210C628;
	// lis r27,-32761
	ctx.r27.s64 = -2147024896;
	// ori r27,r27,14
	ctx.r27.u64 = ctx.r27.u64 | 14;
	// b 0x8210c638
	goto loc_8210C638;
loc_8210C628:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210c0b8
	ctx.lr = 0x8210C630;
	sub_8210C0B8(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq 0x8210c650
	if (ctx.cr0.eq) goto loc_8210C650;
loc_8210C638:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210c648
	if (ctx.cr6.eq) goto loc_8210C648;
	// bl 0x8210c788
	ctx.lr = 0x8210C648;
	sub_8210C788(ctx, base);
loc_8210C648:
	// stw r25,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r25.u32);
	// b 0x8210c654
	goto loc_8210C654;
loc_8210C650:
	// stw r31,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r31.u32);
loc_8210C654:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
