DEFINE_REX_FUNC(sub_8210C660) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8210C668;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// cmplwi cr6,r31,1199
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1199, ctx.xer);
	// ble cr6,0x8210c694
	if (!ctx.cr6.gt) goto loc_8210C694;
	// lis r29,-32646
	ctx.r29.s64 = -2139488256;
	// ori r29,r29,4102
	ctx.r29.u64 = ctx.r29.u64 | 4102;
	// b 0x8210c6f4
	goto loc_8210C6F4;
loc_8210C694:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8210c908
	ctx.lr = 0x8210C69C;
	sub_8210C908(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt 0x8210c6e4
	if (ctx.cr0.lt) goto loc_8210C6E4;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8210c548
	ctx.lr = 0x8210C6BC;
	sub_8210C548(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8210c6d0
	if (!ctx.cr0.eq) goto loc_8210C6D0;
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
	// b 0x8210c6e4
	goto loc_8210C6E4;
loc_8210C6D0:
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210c0b8
	ctx.lr = 0x8210C6DC;
	sub_8210C0B8(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x8210c6fc
	if (ctx.cr0.eq) goto loc_8210C6FC;
loc_8210C6E4:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210c6f4
	if (ctx.cr6.eq) goto loc_8210C6F4;
	// bl 0x8210c788
	ctx.lr = 0x8210C6F4;
	sub_8210C788(ctx, base);
loc_8210C6F4:
	// stw r28,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r28.u32);
	// b 0x8210c700
	goto loc_8210C700;
loc_8210C6FC:
	// stw r31,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r31.u32);
loc_8210C700:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
