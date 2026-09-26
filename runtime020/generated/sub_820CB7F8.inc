DEFINE_REX_FUNC(sub_820CB7F8) {
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
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r11,10584
	ctx.r3.s64 = ctx.r11.s64 + 10584;
	// bl 0x8214a5a4
	ctx.lr = 0x820CB818;
	__imp__DbgPrint(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,13432(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 13432);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cb468
	ctx.lr = 0x820CB82C;
	sub_820CB468(ctx, base);
	// lwz r11,13432(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 13432);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cb884
	if (ctx.cr6.eq) goto loc_820CB884;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r11,5056(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 5056);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820cb850
	if (ctx.cr6.eq) goto loc_820CB850;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820cb8a4
	goto loc_820CB8A4;
loc_820CB850:
	// lbz r10,10941(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 10941);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,10908(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10908);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r7,10896(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 10896);
	// ori r10,r10,3
	ctx.r10.u64 = ctx.r10.u64 | 3;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// stb r10,10941(r31)
	REX_STORE_U8(ctx.r31.u32 + 10941, ctx.r10.u8);
	// addi r3,r8,7124
	ctx.r3.s64 = ctx.r8.s64 + 7124;
	// stw r11,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// stw r9,11008(r31)
	REX_STORE_U32(ctx.r31.u32 + 11008, ctx.r9.u32);
	// bl 0x820ccb40
	ctx.lr = 0x820CB880;
	sub_820CCB40(ctx, base);
	// b 0x820cb8a0
	goto loc_820CB8A0;
loc_820CB884:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r3,r11,10360
	ctx.r3.s64 = ctx.r11.s64 + 10360;
	// bl 0x8214a5a4
	ctx.lr = 0x820CB890;
	__imp__DbgPrint(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r3,r11,10264
	ctx.r3.s64 = ctx.r11.s64 + 10264;
	// bl 0x8214a5a4
	ctx.lr = 0x820CB89C;
	__imp__DbgPrint(ctx, base);
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_820CB8A0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_820CB8A4:
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
