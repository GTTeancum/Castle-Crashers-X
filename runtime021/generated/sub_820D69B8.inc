DEFINE_REX_FUNC(sub_820D69B8) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x820d6648
	ctx.lr = 0x820D69D4;
	sub_820D6648(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8214a6e4
	ctx.lr = 0x820D69DC;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x820d69f0
	if (!ctx.cr6.eq) goto loc_820D69F0;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1480(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1480);
	// b 0x820d69f8
	goto loc_820D69F8;
loc_820D69F0:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1484(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1484);
loc_820D69F8:
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,356(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 356);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820d6a28
	if (ctx.cr6.eq) goto loc_820D6A28;
	// lis r11,-16384
	ctx.r11.s64 = -1073741824;
	// stw r31,356(r30)
	REX_STORE_U32(ctx.r30.u32 + 356, ctx.r31.u32);
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// ori r11,r11,25088
	ctx.r11.u64 = ctx.r11.u64 | 25088;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x820c5f98
	ctx.lr = 0x820D6A28;
	sub_820C5F98(ctx, base);
loc_820D6A28:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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
