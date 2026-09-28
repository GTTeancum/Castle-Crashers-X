DEFINE_REX_FUNC(sub_820E0538) {
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
	// lwz r10,-52(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + -52);
	// addi r31,r3,-52
	ctx.r31.s64 = ctx.r3.s64 + -52;
	// clrlwi r5,r4,31
	ctx.r5.u64 = ctx.r4.u32 & 0x1;
	// addi r11,r31,52
	ctx.r11.s64 = ctx.r31.s64 + 52;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// addi r7,r9,-32056
	ctx.r7.s64 = ctx.r9.s64 + -32056;
	// addi r6,r8,-32376
	ctx.r6.s64 = ctx.r8.s64 + -32376;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r7,-52(r4)
	REX_STORE_U32(ctx.r4.u32 + -52, ctx.r7.u32);
	// stw r6,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// beq cr6,0x820e0594
	if (ctx.cr6.eq) goto loc_820E0594;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lis r5,24962
	ctx.r5.s64 = 1635909632;
	// addi r3,r11,22968
	ctx.r3.s64 = ctx.r11.s64 + 22968;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x820dc858
	ctx.lr = 0x820E0594;
	sub_820DC858(ctx, base);
loc_820E0594:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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
