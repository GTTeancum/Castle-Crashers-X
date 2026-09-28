DEFINE_REX_FUNC(sub_8206D068) {
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
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lwz r10,612(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 612);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,612(r11)
	REX_STORE_U32(ctx.r11.u32 + 612, ctx.r10.u32);
	// cmplwi cr6,r10,120
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 120, ctx.xer);
	// blt cr6,0x8206d0c0
	if (ctx.cr6.lt) goto loc_8206D0C0;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,48(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// li r4,15
	ctx.r4.s64 = 15;
	// stw r10,612(r11)
	REX_STORE_U32(ctx.r11.u32 + 612, ctx.r10.u32);
	// lhz r31,12(r9)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r9.u32 + 12);
	// bl 0x82053bc8
	ctx.lr = 0x8206D0A8;
	sub_82053BC8(ctx, base);
	// lis r8,-32218
	ctx.r8.s64 = -2111438848;
	// li r6,0
	ctx.r6.s64 = 0;
	// extsh r5,r31
	ctx.r5.s64 = ctx.r31.s16;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6624(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + -6624);
	// bl 0x82077310
	ctx.lr = 0x8206D0C0;
	sub_82077310(ctx, base);
loc_8206D0C0:
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
