DEFINE_REX_FUNC(sub_82118CB8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,272(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 272);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x82118ce4
	if (!ctx.cr6.eq) goto loc_82118CE4;
	// lis r4,-32646
	ctx.r4.s64 = -2139488256;
	// ori r4,r4,4099
	ctx.r4.u64 = ctx.r4.u64 | 4099;
	// b 0x82118d14
	goto loc_82118D14;
loc_82118CE4:
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r31,356
	ctx.r4.s64 = ctx.r31.s64 + 356;
	// bl 0x820fc7c0
	ctx.lr = 0x82118CF8;
	sub_820FC7C0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82118d08
	if (ctx.cr0.eq) goto loc_82118D08;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82118d14
	goto loc_82118D14;
loc_82118D08:
	// bl 0x820fc8b0
	ctx.lr = 0x82118D0C;
	sub_820FC8B0(ctx, base);
	// bl 0x8210c710
	ctx.lr = 0x82118D10;
	sub_8210C710(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_82118D14:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821182e0
	ctx.lr = 0x82118D1C;
	sub_821182E0(ctx, base);
	// lwz r11,440(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 440);
	// rlwinm. r11,r11,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82118d30
	if (!ctx.cr0.eq) goto loc_82118D30;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82118bc8
	ctx.lr = 0x82118D30;
	sub_82118BC8(ctx, base);
loc_82118D30:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
