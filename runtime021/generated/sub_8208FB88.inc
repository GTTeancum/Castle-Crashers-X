DEFINE_REX_FUNC(sub_8208FB88) {
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
	// lwz r10,-6648(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -6648);
	// lhz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 12);
	// addi r7,r9,25907
	ctx.r7.s64 = ctx.r9.s64 + 25907;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r10
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// lhz r4,24(r5)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r5.u32 + 24);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8208fc0c
	if (ctx.cr6.eq) goto loc_8208FC0C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r3,r11,-5468
	ctx.r3.s64 = ctx.r11.s64 + -5468;
loc_8208FBC8:
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// clrlwi r9,r11,16
	ctx.r9.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r9,12(r10)
	REX_STORE_U16(ctx.r10.u32 + 12, ctx.r9.u16);
	// cmplwi cr6,r9,200
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 200, ctx.xer);
	// bne cr6,0x8208fbe0
	if (!ctx.cr6.eq) goto loc_8208FBE0;
	// sth r7,12(r10)
	REX_STORE_U16(ctx.r10.u32 + 12, ctx.r7.u16);
loc_8208FBE0:
	// lhz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8208fbf0
	if (!ctx.cr6.eq) goto loc_8208FBF0;
	// bl 0x8208c5d8
	ctx.lr = 0x8208FBF0;
	sub_8208C5D8(ctx, base);
loc_8208FBF0:
	// lhz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 12);
	// addi r11,r11,25907
	ctx.r11.s64 = ctx.r11.s64 + 25907;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r10
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// lhz r4,24(r5)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r5.u32 + 24);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8208fbc8
	if (!ctx.cr6.eq) goto loc_8208FBC8;
loc_8208FC0C:
	// lhz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 12);
	// addi r11,r11,25907
	ctx.r11.s64 = ctx.r11.s64 + 25907;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
