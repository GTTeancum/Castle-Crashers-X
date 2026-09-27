DEFINE_REX_FUNC(sub_82086010) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,255
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 255, ctx.xer);
	// beq cr6,0x82086078
	if (ctx.cr6.eq) goto loc_82086078;
	// lis r11,-32234
	ctx.r11.s64 = -2112487424;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,-23552
	ctx.r8.s64 = ctx.r11.s64 + -23552;
	// lwzx r11,r9,r8
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82086060
	if (ctx.cr6.eq) goto loc_82086060;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82086050;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82086060:
	// cmpwi cr6,r4,45
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 45, ctx.xer);
	// beq cr6,0x82086078
	if (ctx.cr6.eq) goto loc_82086078;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-6716
	ctx.r3.s64 = ctx.r11.s64 + -6716;
	// bl 0x820798d8
	ctx.lr = 0x82086074;
	sub_820798D8(ctx, base);
	// bl 0x8208c5d8
	ctx.lr = 0x82086078;
	sub_8208C5D8(ctx, base);
loc_82086078:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
