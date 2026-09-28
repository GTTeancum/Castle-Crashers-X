DEFINE_REX_FUNC(sub_82119B40) {
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
	// bne cr6,0x82119b74
	if (!ctx.cr6.eq) goto loc_82119B74;
	// lwz r3,436(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 436);
	// bl 0x821180d8
	ctx.lr = 0x82119B68;
	sub_821180D8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,436(r31)
	REX_STORE_U32(ctx.r31.u32 + 436, ctx.r11.u32);
	// b 0x82119bac
	goto loc_82119BAC;
loc_82119B74:
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,408
	ctx.r4.s64 = ctx.r31.s64 + 408;
	// bl 0x820fc7c0
	ctx.lr = 0x82119B88;
	sub_820FC7C0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82119ba4
	if (ctx.cr0.eq) goto loc_82119BA4;
	// lwz r11,436(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 436);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r10.u32);
	// bl 0x82118d48
	ctx.lr = 0x82119BA4;
	sub_82118D48(ctx, base);
loc_82119BA4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821199d0
	ctx.lr = 0x82119BAC;
	sub_821199D0(ctx, base);
loc_82119BAC:
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
