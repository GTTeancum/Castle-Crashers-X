DEFINE_REX_FUNC(sub_820A8960) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x820A8968;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r3,-6656(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6656);
	// bl 0x82095da8
	ctx.lr = 0x820A8984;
	sub_82095DA8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x820a89a8
	if (!ctx.cr6.eq) goto loc_820A89A8;
	// lwz r30,-6656(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + -6656);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82096530
	ctx.lr = 0x820A89A0;
	sub_82096530(ctx, base);
	// addi r31,r30,14516
	ctx.r31.s64 = ctx.r30.s64 + 14516;
	// b 0x820a89d0
	goto loc_820A89D0;
loc_820A89A8:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,92(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A89BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r31,-6656(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + -6656);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82096530
	ctx.lr = 0x820A89CC;
	sub_82096530(ctx, base);
	// addi r31,r31,14516
	ctx.r31.s64 = ctx.r31.s64 + 14516;
loc_820A89D0:
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214a434
	ctx.lr = 0x820A89DC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820967b0
	ctx.lr = 0x820A89E4;
	sub_820967B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214a444
	ctx.lr = 0x820A89EC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
