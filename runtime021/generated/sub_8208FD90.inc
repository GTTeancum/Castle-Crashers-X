DEFINE_REX_FUNC(sub_8208FD90) {
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
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,-6648(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -6648);
	// lhz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 20);
	// addi r6,r9,27623
	ctx.r6.s64 = ctx.r9.s64 + 27623;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r5,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// lhz r3,24(r4)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r4.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8208fe14
	if (ctx.cr6.eq) goto loc_8208FE14;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-5264
	ctx.r3.s64 = ctx.r11.s64 + -5264;
loc_8208FDD0:
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// clrlwi r9,r11,16
	ctx.r9.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r9,20(r10)
	REX_STORE_U16(ctx.r10.u32 + 20, ctx.r9.u16);
	// cmplwi cr6,r9,500
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 500, ctx.xer);
	// bne cr6,0x8208fde8
	if (!ctx.cr6.eq) goto loc_8208FDE8;
	// sth r7,20(r10)
	REX_STORE_U16(ctx.r10.u32 + 20, ctx.r7.u16);
loc_8208FDE8:
	// lhz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 20);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8208fdf8
	if (!ctx.cr6.eq) goto loc_8208FDF8;
	// bl 0x8208c5d8
	ctx.lr = 0x8208FDF8;
	sub_8208C5D8(ctx, base);
loc_8208FDF8:
	// lhz r11,20(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 20);
	// addi r11,r11,27623
	ctx.r11.s64 = ctx.r11.s64 + 27623;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r10
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// lhz r4,24(r5)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r5.u32 + 24);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8208fdd0
	if (!ctx.cr6.eq) goto loc_8208FDD0;
loc_8208FE14:
	// lhz r11,20(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 20);
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r11,27623
	ctx.r8.s64 = ctx.r11.s64 + 27623;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r6,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// lbz r5,86(r3)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r3.u32 + 86);
	// sth r7,80(r3)
	REX_STORE_U16(ctx.r3.u32 + 80, ctx.r7.u16);
	// ori r4,r5,16
	ctx.r4.u64 = ctx.r5.u64 | 16;
	// stb r9,102(r3)
	REX_STORE_U8(ctx.r3.u32 + 102, ctx.r9.u8);
	// stb r4,86(r3)
	REX_STORE_U8(ctx.r3.u32 + 86, ctx.r4.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
