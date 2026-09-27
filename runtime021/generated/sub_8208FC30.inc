DEFINE_REX_FUNC(sub_8208FC30) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r10,-6648(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -6648);
	// lhz r9,14(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 14);
	// addi r7,r9,26107
	ctx.r7.s64 = ctx.r9.s64 + 26107;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r10
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// lhz r3,24(r5)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r5.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8208fcb8
	if (ctx.cr6.eq) goto loc_8208FCB8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r3,r11,-5416
	ctx.r3.s64 = ctx.r11.s64 + -5416;
loc_8208FC74:
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// clrlwi r9,r11,16
	ctx.r9.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r9,14(r10)
	REX_STORE_U16(ctx.r10.u32 + 14, ctx.r9.u16);
	// cmplwi cr6,r9,500
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 500, ctx.xer);
	// bne cr6,0x8208fc8c
	if (!ctx.cr6.eq) goto loc_8208FC8C;
	// sth r7,14(r10)
	REX_STORE_U16(ctx.r10.u32 + 14, ctx.r7.u16);
loc_8208FC8C:
	// lhz r9,14(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 14);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8208fc9c
	if (!ctx.cr6.eq) goto loc_8208FC9C;
	// bl 0x8208c5d8
	ctx.lr = 0x8208FC9C;
	sub_8208C5D8(ctx, base);
loc_8208FC9C:
	// lhz r11,14(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 14);
	// addi r11,r11,26107
	ctx.r11.s64 = ctx.r11.s64 + 26107;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r10
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// lhz r11,24(r5)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r5.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208fc74
	if (!ctx.cr6.eq) goto loc_8208FC74;
loc_8208FCB8:
	// lhz r11,14(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 14);
	// addi r11,r11,26107
	ctx.r11.s64 = ctx.r11.s64 + 26107;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r10
	ctx.r31.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8208cb88
	ctx.lr = 0x8208FCD0;
	sub_8208CB88(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
