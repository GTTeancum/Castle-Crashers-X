DEFINE_REX_FUNC(sub_820EABF8) {
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
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// bl 0x820e7660
	ctx.lr = 0x820EAC14;
	sub_820E7660(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820eac44
	if (ctx.cr6.lt) goto loc_820EAC44;
	// lbz r11,196(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 196);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lbz r9,197(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 197);
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r7,r10,-27144
	ctx.r7.s64 = ctx.r10.s64 + -27144;
	// rotlwi r6,r11,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lwzx r5,r6,r7
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// sth r8,110(r31)
	REX_STORE_U16(ctx.r31.u32 + 110, ctx.r8.u16);
	// mullw r4,r5,r9
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// sth r4,108(r31)
	REX_STORE_U16(ctx.r31.u32 + 108, ctx.r4.u16);
loc_820EAC44:
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
