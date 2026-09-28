DEFINE_REX_FUNC(sub_82077F20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82077F28;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82077fd8
	ctx.lr = 0x82077F34;
	sub_82077FD8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82077fd0
	if (ctx.cr6.lt) goto loc_82077FD0;
	// mulli r11,r3,76
	ctx.r11.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(76));
	// add r31,r11,r30
	ctx.r31.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82077fd0
	if (ctx.cr6.eq) goto loc_82077FD0;
	// lhz r10,208(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 208);
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// sth r8,208(r31)
	REX_STORE_U16(ctx.r31.u32 + 208, ctx.r8.u16);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82077fd0
	if (!ctx.cr6.eq) goto loc_82077FD0;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// lwz r29,100(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-6608(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + -6608);
	// bl 0x8209c718
	ctx.lr = 0x82077F80;
	sub_8209C718(ctx, base);
	// lwz r4,136(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x82078170
	ctx.lr = 0x82077F8C;
	sub_82078170(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820788b8
	ctx.lr = 0x82077F94;
	sub_820788B8(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stw r9,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r9.u32);
	// addi r3,r31,140
	ctx.r3.s64 = ctx.r31.s64 + 140;
	// addi r4,r8,-8185
	ctx.r4.s64 = ctx.r8.s64 + -8185;
	// bl 0x82053a00
	ctx.lr = 0x82077FAC;
	sub_82053A00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820758e8
	ctx.lr = 0x82077FB4;
	sub_820758E8(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,-6656(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + -6656);
	// bl 0x82095f78
	ctx.lr = 0x82077FC4;
	sub_82095F78(ctx, base);
	// lis r6,-32218
	ctx.r6.s64 = -2111438848;
	// lwz r3,-6648(r6)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r6.u32 + -6648);
	// bl 0x8208f5f0
	ctx.lr = 0x82077FD0;
	sub_8208F5F0(ctx, base);
loc_82077FD0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
