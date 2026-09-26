DEFINE_REX_FUNC(sub_82077808) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82077810;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820778c0
	if (ctx.cr6.eq) goto loc_820778C0;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// lwz r29,100(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-6608(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + -6608);
	// bl 0x8209c718
	ctx.lr = 0x82077838;
	sub_8209C718(ctx, base);
	// lwz r4,288(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x82078170
	ctx.lr = 0x82077844;
	sub_82078170(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82077888
	if (ctx.cr6.eq) goto loc_82077888;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x82077888
	if (!ctx.cr6.eq) goto loc_82077888;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lis r8,-32215
	ctx.r8.s64 = -2111242240;
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r8,-22032
	ctx.r3.s64 = ctx.r8.s64 + -22032;
	// bl 0x8209a170
	ctx.lr = 0x82077888;
	sub_8209A170(ctx, base);
loc_82077888:
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r30.u32);
	// bl 0x820758e8
	ctx.lr = 0x82077898;
	sub_820758E8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,-6656(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6656);
	// bl 0x82095f78
	ctx.lr = 0x820778A8;
	sub_82095F78(ctx, base);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// lwz r3,-6648(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + -6648);
	// bl 0x8208f5f0
	ctx.lr = 0x820778B4;
	sub_8208F5F0(ctx, base);
	// stb r30,69(r31)
	REX_STORE_U8(ctx.r31.u32 + 69, ctx.r30.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_820778C0:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,69(r31)
	REX_STORE_U8(ctx.r31.u32 + 69, ctx.r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
