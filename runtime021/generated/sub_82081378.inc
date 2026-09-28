DEFINE_REX_FUNC(sub_82081378) {
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
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lis r8,-32768
	ctx.r8.s64 = -2147483648;
	// lwz r7,76(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r11,156(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 156);
	// addi r11,r11,10372
	ctx.r11.s64 = ctx.r11.s64 + 10372;
	// lwz r6,5024(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 5024);
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwz r4,-4(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + -4);
	// lwz r3,0(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmpw cr6,r3,r8
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r8.s32, ctx.xer);
	// beq cr6,0x820813dc
	if (ctx.cr6.eq) goto loc_820813DC;
	// rotlwi r11,r7,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwz r31,156(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// addi r11,r31,10372
	ctx.r11.s64 = ctx.r31.s64 + 10372;
	// lwz r10,15396(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15396);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r3,-4(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + -4);
	// bl 0x82082bb0
	ctx.lr = 0x820813D8;
	sub_82082BB0(ctx, base);
	// stw r3,30476(r31)
	REX_STORE_U32(ctx.r31.u32 + 30476, ctx.r3.u32);
loc_820813DC:
	// li r3,0
	ctx.r3.s64 = 0;
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
