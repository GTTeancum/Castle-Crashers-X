DEFINE_REX_FUNC(sub_8211CC70) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8211CC78;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r29,r30,640
	ctx.r29.s64 = ctx.r30.s64 + 640;
	// lwz r31,640(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 640);
	// b 0x8211ccec
	goto loc_8211CCEC;
loc_8211CC90:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lhz r5,12(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82125de8
	ctx.lr = 0x8211CCA0;
	sub_82125DE8(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,652(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 652);
	// lwz r11,1(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8211ccf4
	if (!ctx.cr6.eq) goto loc_8211CCF4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82125628
	ctx.lr = 0x8211CCBC;
	sub_82125628(ctx, base);
	// lbz r11,21(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 21);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mulli r11,r11,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// subf r5,r11,r31
	ctx.r5.u64 = ctx.r31.u64 - ctx.r11.u64;
	// bl 0x8211b2a0
	ctx.lr = 0x8211CCE0;
	sub_8211B2A0(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// blt 0x8211ccf4
	if (ctx.cr0.lt) goto loc_8211CCF4;
	// lwz r31,0(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
loc_8211CCEC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8211cc90
	if (!ctx.cr6.eq) goto loc_8211CC90;
loc_8211CCF4:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
