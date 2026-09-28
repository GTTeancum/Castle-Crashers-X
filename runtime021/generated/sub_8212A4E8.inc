DEFINE_REX_FUNC(sub_8212A4E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8212a584
	if (ctx.cr6.eq) goto loc_8212A584;
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8212a514
	if (ctx.cr6.eq) goto loc_8212A514;
	// bl 0x82129880
	ctx.lr = 0x8212A514;
	sub_82129880(ctx, base);
loc_8212A514:
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8212a524
	if (ctx.cr6.eq) goto loc_8212A524;
	// bl 0x82129880
	ctx.lr = 0x8212A524;
	sub_82129880(ctx, base);
loc_8212A524:
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8212a534
	if (ctx.cr6.eq) goto loc_8212A534;
	// bl 0x82129880
	ctx.lr = 0x8212A534;
	sub_82129880(ctx, base);
loc_8212A534:
	// lwz r3,60(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8212a544
	if (ctx.cr6.eq) goto loc_8212A544;
	// bl 0x82129880
	ctx.lr = 0x8212A544;
	sub_82129880(ctx, base);
loc_8212A544:
	// lwz r3,68(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8212a554
	if (ctx.cr6.eq) goto loc_8212A554;
	// bl 0x82129880
	ctx.lr = 0x8212A554;
	sub_82129880(ctx, base);
loc_8212A554:
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8212a564
	if (ctx.cr6.eq) goto loc_8212A564;
	// bl 0x82129880
	ctx.lr = 0x8212A564;
	sub_82129880(ctx, base);
loc_8212A564:
	// lis r11,-32234
	ctx.r11.s64 = -2112487424;
	// lwz r3,92(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// addi r11,r11,-32496
	ctx.r11.s64 = ctx.r11.s64 + -32496;
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8212a57c
	if (ctx.cr6.eq) goto loc_8212A57C;
	// bl 0x82129880
	ctx.lr = 0x8212A57C;
	sub_82129880(ctx, base);
loc_8212A57C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82129880
	ctx.lr = 0x8212A584;
	sub_82129880(ctx, base);
loc_8212A584:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
