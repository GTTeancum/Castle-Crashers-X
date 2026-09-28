DEFINE_REX_FUNC(sub_82064D08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82064D10;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,18404
	ctx.r4.s64 = ctx.r11.s64 + 18404;
	// lwz r30,48(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,276(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 276);
	// lwz r29,56(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + 56);
	// bl 0x8209d948
	ctx.lr = 0x82064D34;
	sub_8209D948(ctx, base);
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82064D4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x82064D54;
	sub_82085078(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,164(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 164);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82064D68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r31,356(r30)
	REX_STORE_U32(ctx.r30.u32 + 356, ctx.r31.u32);
	// addi r4,r5,20768
	ctx.r4.s64 = ctx.r5.s64 + 20768;
	// li r3,15
	ctx.r3.s64 = 15;
	// stw r11,360(r30)
	REX_STORE_U32(ctx.r30.u32 + 360, ctx.r11.u32);
	// sth r11,388(r30)
	REX_STORE_U16(ctx.r30.u32 + 388, ctx.r11.u16);
	// stw r4,364(r30)
	REX_STORE_U32(ctx.r30.u32 + 364, ctx.r4.u32);
	// sth r3,390(r30)
	REX_STORE_U16(ctx.r30.u32 + 390, ctx.r3.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
