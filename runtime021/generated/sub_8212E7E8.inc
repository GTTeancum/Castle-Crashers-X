DEFINE_REX_FUNC(sub_8212E7E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r4,64
	ctx.r4.s64 = 64;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x8212e218
	ctx.lr = 0x8212E800;
	sub_8212E218(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8212e810
	if (!ctx.cr0.eq) goto loc_8212E810;
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8212e89c
	goto loc_8212E89C;
loc_8212E810:
	// lis r8,-32215
	ctx.r8.s64 = -2111242240;
	// lis r7,-32215
	ctx.r7.s64 = -2111242240;
	// addi r6,r3,2048
	ctx.r6.s64 = ctx.r3.s64 + 2048;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,2976(r8)
	REX_STORE_U32(ctx.r8.u32 + 2976, ctx.r11.u32);
	// cmplw cr6,r3,r6
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r6.u32, ctx.xer);
	// stw r10,2960(r7)
	REX_STORE_U32(ctx.r7.u32 + 2960, ctx.r10.u32);
	// bge cr6,0x8212e878
	if (!ctx.cr6.lt) goto loc_8212E878;
	// li r10,10
	ctx.r10.s64 = 10;
loc_8212E83C:
	// li r11,-1
	ctx.r11.s64 = -1;
	// stb r9,4(r3)
	REX_STORE_U8(ctx.r3.u32 + 4, ctx.r9.u8);
	// stb r10,5(r3)
	REX_STORE_U8(ctx.r3.u32 + 5, ctx.r10.u8);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r9,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// stb r9,40(r3)
	REX_STORE_U8(ctx.r3.u32 + 40, ctx.r9.u8);
	// stb r10,41(r3)
	REX_STORE_U8(ctx.r3.u32 + 41, ctx.r10.u8);
	// stb r10,42(r3)
	REX_STORE_U8(ctx.r3.u32 + 42, ctx.r10.u8);
	// addi r3,r3,64
	ctx.r3.s64 = ctx.r3.s64 + 64;
	// lwz r11,2976(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 2976);
	// addi r7,r11,2048
	ctx.r7.s64 = ctx.r11.s64 + 2048;
	// cmplw cr6,r3,r7
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x8212e83c
	if (ctx.cr6.lt) goto loc_8212E83C;
	// b 0x8212e878
	goto loc_8212E878;
loc_8212E874:
	// lwz r11,2976(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 2976);
loc_8212E878:
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// li r10,-63
	ctx.r10.s64 = -63;
	// li r7,-2
	ctx.r7.s64 = -2;
	// addi r9,r9,64
	ctx.r9.s64 = ctx.r9.s64 + 64;
	// stb r10,4(r11)
	REX_STORE_U8(ctx.r11.u32 + 4, ctx.r10.u8);
	// cmpwi cr6,r9,192
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 192, ctx.xer);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// blt cr6,0x8212e874
	if (ctx.cr6.lt) goto loc_8212E874;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8212E89C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
