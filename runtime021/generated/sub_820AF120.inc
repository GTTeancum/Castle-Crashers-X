DEFINE_REX_FUNC(sub_820AF120) {
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
	// addi r4,r31,140
	ctx.r4.s64 = ctx.r31.s64 + 140;
	// lwz r5,2836(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 2836);
	// bl 0x820aea68
	ctx.lr = 0x820AF140;
	sub_820AEA68(ctx, base);
	// addi r4,r31,2432
	ctx.r4.s64 = ctx.r31.s64 + 2432;
	// lwz r5,2848(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 2848);
	// bl 0x820aea68
	ctx.lr = 0x820AF14C;
	sub_820AEA68(ctx, base);
	// addi r4,r31,2856
	ctx.r4.s64 = ctx.r31.s64 + 2856;
	// bl 0x820ae790
	ctx.lr = 0x820AF154;
	sub_820AE790(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// li r3,18
	ctx.r3.s64 = 18;
	// addi r11,r11,13588
	ctx.r11.s64 = ctx.r11.s64 + 13588;
loc_820AF160:
	// lbzx r10,r3,r11
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r11.u32);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// add r9,r10,r31
	ctx.r9.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lhz r8,2678(r9)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + 2678);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x820af1f0
	if (!ctx.cr6.eq) goto loc_820AF1F0;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lbz r9,-1(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + -1);
	// rotlwi r10,r9,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// add r8,r10,r31
	ctx.r8.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lhz r7,2678(r8)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + 2678);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x820af1dc
	if (!ctx.cr6.eq) goto loc_820AF1DC;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lbz r9,-2(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + -2);
	// rotlwi r10,r9,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// add r8,r10,r31
	ctx.r8.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lhz r7,2678(r8)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + 2678);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x820af1e4
	if (!ctx.cr6.eq) goto loc_820AF1E4;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lbz r9,-3(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + -3);
	// rotlwi r10,r9,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// add r8,r10,r31
	ctx.r8.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lhz r7,2678(r8)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + 2678);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x820af1ec
	if (!ctx.cr6.eq) goto loc_820AF1EC;
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bge cr6,0x820af160
	if (!ctx.cr6.lt) goto loc_820AF160;
	// b 0x820af1f0
	goto loc_820AF1F0;
loc_820AF1DC:
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
	// b 0x820af1f0
	goto loc_820AF1F0;
loc_820AF1E4:
	// addi r3,r3,-2
	ctx.r3.s64 = ctx.r3.s64 + -2;
	// b 0x820af1f0
	goto loc_820AF1F0;
loc_820AF1EC:
	// addi r3,r3,-3
	ctx.r3.s64 = ctx.r3.s64 + -3;
loc_820AF1F0:
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,5792(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 5792);
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,17
	ctx.r11.s64 = ctx.r11.s64 + 17;
	// stw r11,5792(r31)
	REX_STORE_U32(ctx.r31.u32 + 5792, ctx.r11.u32);
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
