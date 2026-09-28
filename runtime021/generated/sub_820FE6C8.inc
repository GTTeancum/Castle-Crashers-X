DEFINE_REX_FUNC(sub_820FE6C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820FE6D0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r29,r28,248
	ctx.r29.s64 = ctx.r28.s64 + 248;
	// lwz r31,248(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 248);
	// b 0x820fe724
	goto loc_820FE724;
loc_820FE6E8:
	// lwz r4,100(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// lwz r5,8(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r4,r5
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r5.u32, ctx.xer);
	// bne cr6,0x820fe708
	if (!ctx.cr6.eq) goto loc_820FE708;
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// lwz r10,-68(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + -68);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// b 0x820fe71c
	goto loc_820FE71C;
loc_820FE708:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,400(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 400);
	// bl 0x82108e78
	ctx.lr = 0x820FE714;
	sub_82108E78(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
loc_820FE71C:
	// blt cr6,0x820fe758
	if (ctx.cr6.lt) goto loc_820FE758;
	// lwz r31,0(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_820FE724:
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x820fe734
	if (ctx.cr6.eq) goto loc_820FE734;
	// cmplwi r31,0
	ctx.cr0.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne 0x820fe6e8
	if (!ctx.cr0.eq) goto loc_820FE6E8;
loc_820FE734:
	// stw r29,92(r30)
	REX_STORE_U32(ctx.r30.u32 + 92, ctx.r29.u32);
	// addi r11,r30,92
	ctx.r11.s64 = ctx.r30.s64 + 92;
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// stw r10,96(r30)
	REX_STORE_U32(ctx.r30.u32 + 96, ctx.r10.u32);
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r11,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
loc_820FE750:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820FE758:
	// stw r31,92(r30)
	REX_STORE_U32(ctx.r30.u32 + 92, ctx.r31.u32);
	// addi r11,r30,92
	ctx.r11.s64 = ctx.r30.s64 + 92;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r10,96(r30)
	REX_STORE_U32(ctx.r30.u32 + 96, ctx.r10.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// b 0x820fe750
	goto loc_820FE750;
}
