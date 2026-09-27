DEFINE_REX_FUNC(sub_820837C0) {
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
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r11,76(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208382c
	if (ctx.cr6.eq) goto loc_8208382C;
	// lhz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 28);
	// sth r10,28(r11)
	REX_STORE_U16(ctx.r11.u32 + 28, ctx.r10.u16);
	// lhz r9,30(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 30);
	// sth r9,30(r11)
	REX_STORE_U16(ctx.r11.u32 + 30, ctx.r9.u16);
	// lhz r8,32(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 32);
	// sth r8,32(r11)
	REX_STORE_U16(ctx.r11.u32 + 32, ctx.r8.u16);
	// lhz r7,40(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 40);
	// sth r7,40(r11)
	REX_STORE_U16(ctx.r11.u32 + 40, ctx.r7.u16);
	// lhz r6,34(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// sth r6,34(r11)
	REX_STORE_U16(ctx.r11.u32 + 34, ctx.r6.u16);
	// lhz r5,36(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 36);
	// sth r5,36(r11)
	REX_STORE_U16(ctx.r11.u32 + 36, ctx.r5.u16);
	// lhz r4,38(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 38);
	// sth r4,38(r11)
	REX_STORE_U16(ctx.r11.u32 + 38, ctx.r4.u16);
	// lhz r3,42(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 42);
	// sth r3,42(r11)
	REX_STORE_U16(ctx.r11.u32 + 42, ctx.r3.u16);
	// b 0x8208388c
	goto loc_8208388C;
loc_8208382C:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r4,44(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r3,-6648(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6648);
	// bl 0x8208f9e8
	ctx.lr = 0x8208383C;
	sub_8208F9E8(ctx, base);
	// stw r3,76(r30)
	REX_STORE_U32(ctx.r30.u32 + 76, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82066ea8
	ctx.lr = 0x82083848;
	sub_82066EA8(ctx, base);
	// lwz r10,76(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 76);
	// lhz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 28);
	// sth r9,28(r10)
	REX_STORE_U16(ctx.r10.u32 + 28, ctx.r9.u16);
	// lhz r8,30(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 30);
	// sth r8,30(r10)
	REX_STORE_U16(ctx.r10.u32 + 30, ctx.r8.u16);
	// lhz r7,32(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 32);
	// sth r7,32(r10)
	REX_STORE_U16(ctx.r10.u32 + 32, ctx.r7.u16);
	// lhz r6,40(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 40);
	// sth r6,40(r10)
	REX_STORE_U16(ctx.r10.u32 + 40, ctx.r6.u16);
	// lhz r5,34(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// sth r5,34(r10)
	REX_STORE_U16(ctx.r10.u32 + 34, ctx.r5.u16);
	// lhz r4,36(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 36);
	// sth r4,36(r10)
	REX_STORE_U16(ctx.r10.u32 + 36, ctx.r4.u16);
	// lhz r3,38(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 38);
	// sth r3,38(r10)
	REX_STORE_U16(ctx.r10.u32 + 38, ctx.r3.u16);
	// lhz r11,42(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 42);
	// sth r11,42(r10)
	REX_STORE_U16(ctx.r10.u32 + 42, ctx.r11.u16);
loc_8208388C:
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
