DEFINE_REX_FUNC(sub_8208F9E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r10,-6648(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -6648);
	// lhz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// addi r6,r9,23507
	ctx.r6.s64 = ctx.r9.s64 + 23507;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r5,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// lhz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208fa6c
	if (ctx.cr6.eq) goto loc_8208FA6C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-5568
	ctx.r3.s64 = ctx.r11.s64 + -5568;
loc_8208FA28:
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// clrlwi r9,r11,16
	ctx.r9.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r9,8(r10)
	REX_STORE_U16(ctx.r10.u32 + 8, ctx.r9.u16);
	// cmplwi cr6,r9,2000
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2000, ctx.xer);
	// bne cr6,0x8208fa40
	if (!ctx.cr6.eq) goto loc_8208FA40;
	// sth r8,8(r10)
	REX_STORE_U16(ctx.r10.u32 + 8, ctx.r8.u16);
loc_8208FA40:
	// lhz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x8208fa50
	if (!ctx.cr6.eq) goto loc_8208FA50;
	// bl 0x8208c5d8
	ctx.lr = 0x8208FA50;
	sub_8208C5D8(ctx, base);
loc_8208FA50:
	// lhz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// addi r11,r11,23507
	ctx.r11.s64 = ctx.r11.s64 + 23507;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r10
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// lhz r11,24(r5)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r5.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208fa28
	if (!ctx.cr6.eq) goto loc_8208FA28;
loc_8208FA6C:
	// lhz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// li r11,255
	ctx.r11.s64 = 255;
	// addi r9,r9,23507
	ctx.r9.s64 = ctx.r9.s64 + 23507;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r7,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// sth r11,40(r3)
	REX_STORE_U16(ctx.r3.u32 + 40, ctx.r11.u16);
	// sth r11,32(r3)
	REX_STORE_U16(ctx.r3.u32 + 32, ctx.r11.u16);
	// sth r11,30(r3)
	REX_STORE_U16(ctx.r3.u32 + 30, ctx.r11.u16);
	// sth r11,28(r3)
	REX_STORE_U16(ctx.r3.u32 + 28, ctx.r11.u16);
	// sth r8,42(r3)
	REX_STORE_U16(ctx.r3.u32 + 42, ctx.r8.u16);
	// sth r8,38(r3)
	REX_STORE_U16(ctx.r3.u32 + 38, ctx.r8.u16);
	// sth r8,36(r3)
	REX_STORE_U16(ctx.r3.u32 + 36, ctx.r8.u16);
	// sth r8,34(r3)
	REX_STORE_U16(ctx.r3.u32 + 34, ctx.r8.u16);
	// stw r4,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
