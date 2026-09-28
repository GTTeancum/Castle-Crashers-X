DEFINE_REX_FUNC(sub_820D9A78) {
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
	// lbz r11,268(r13)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r13.u32 + 268);
	// lis r31,-32221
	ctx.r31.s64 = -2111635456;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// lwz r9,256(r13)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r13.u32 + 256);
	// addi r8,r11,83
	ctx.r8.s64 = ctx.r11.s64 + 83;
	// addi r30,r10,22908
	ctx.r30.s64 = ctx.r10.s64 + 22908;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,22960(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22960);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// stwx r9,r10,r11
	REX_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u32);
	// bl 0x8214a994
	ctx.lr = 0x820D9AC8;
	__imp__KeWaitForSingleObject(ctx, base);
	// lwz r3,22960(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 22960);
	// lwz r9,300(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 300);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820d9b08
	if (ctx.cr6.eq) goto loc_820D9B08;
loc_820D9AD8:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820d9330
	ctx.lr = 0x820D9AE0;
	sub_820D9330(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x8214a994
	ctx.lr = 0x820D9AF8;
	__imp__KeWaitForSingleObject(ctx, base);
	// lwz r3,22960(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 22960);
	// lwz r11,300(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 300);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d9ad8
	if (!ctx.cr6.eq) goto loc_820D9AD8;
loc_820D9B08:
	// li r3,0
	ctx.r3.s64 = 0;
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
