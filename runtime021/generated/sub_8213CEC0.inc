DEFINE_REX_FUNC(sub_8213CEC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8213ce58
	ctx.lr = 0x8213CEDC;
	sub_8213CE58(ctx, base);
	// addi r30,r31,52
	ctx.r30.s64 = ctx.r31.s64 + 52;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821420a0
	ctx.lr = 0x8213CEE8;
	sub_821420A0(ctx, base);
	// clrlwi. r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8213cf04
	if (ctx.cr0.eq) goto loc_8213CF04;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82141f80
	ctx.lr = 0x8213CEF8;
	sub_82141F80(ctx, base);
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x8213cf28
	goto loc_8213CF28;
loc_8213CF04:
	// addi r11,r31,64
	ctx.r11.s64 = ctx.r31.s64 + 64;
	// li r10,160
	ctx.r10.s64 = 160;
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// addi r9,r31,384
	ctx.r9.s64 = ctx.r31.s64 + 384;
	// li r11,9
	ctx.r11.s64 = 9;
	// sth r10,32(r31)
	REX_STORE_U16(ctx.r31.u32 + 32, ctx.r10.u16);
	// stw r9,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r11,40(r31)
	REX_STORE_U16(ctx.r31.u32 + 40, ctx.r11.u16);
loc_8213CF28:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
