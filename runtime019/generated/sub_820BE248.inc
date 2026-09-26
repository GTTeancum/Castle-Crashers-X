DEFINE_REX_FUNC(sub_820BE248) {
	REX_FUNC_PROLOGUE();
	// lwz r10,24(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 24);
	// rlwinm. r11,r10,16,30,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x3;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820be25c
	if (!ctx.cr0.eq) goto loc_820BE25C;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x820be274
	goto loc_820BE274;
loc_820BE25C:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// lis r11,0
	ctx.r11.s64 = 0;
	// bne cr6,0x820be270
	if (!ctx.cr6.eq) goto loc_820BE270;
	// ori r11,r11,32769
	ctx.r11.u64 = ctx.r11.u64 | 32769;
	// b 0x820be274
	goto loc_820BE274;
loc_820BE270:
	// ori r11,r11,49155
	ctx.r11.u64 = ctx.r11.u64 | 49155;
loc_820BE274:
	// li r12,1
	ctx.r12.s64 = 1;
	// stw r11,10684(r3)
	REX_STORE_U32(ctx.r3.u32 + 10684, ctx.r11.u32);
	// stw r10,10368(r3)
	REX_STORE_U32(ctx.r3.u32 + 10368, ctx.r10.u32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// rldicr r12,r12,57,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 57) & 0xFFFFFFFFFFFFFFFF;
	// ld r9,16(r3)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r3.u32 + 16);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// or r9,r9,r12
	ctx.r9.u64 = ctx.r9.u64 | ctx.r12.u64;
	// std r9,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r9.u64);
	// li r12,1
	ctx.r12.s64 = 1;
	// ld r8,32(r3)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r3.u32 + 32);
	// addi r9,r11,4756
	ctx.r9.s64 = ctx.r11.s64 + 4756;
	// rldicr r12,r12,36,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 36) & 0xFFFFFFFFFFFFFFFF;
	// addi r4,r10,4732
	ctx.r4.s64 = ctx.r10.s64 + 4732;
	// or r8,r8,r12
	ctx.r8.u64 = ctx.r8.u64 | ctx.r12.u64;
	// std r8,32(r3)
	REX_STORE_U64(ctx.r3.u32 + 32, ctx.r8.u64);
	// lwz r11,4756(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4756);
	// stw r11,12676(r3)
	REX_STORE_U32(ctx.r3.u32 + 12676, ctx.r11.u32);
	// lwz r11,4(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// stw r11,12680(r3)
	REX_STORE_U32(ctx.r3.u32 + 12680, ctx.r11.u32);
	// lwz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// stw r11,12684(r3)
	REX_STORE_U32(ctx.r3.u32 + 12684, ctx.r11.u32);
	// lwz r11,12(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// stw r11,12688(r3)
	REX_STORE_U32(ctx.r3.u32 + 12688, ctx.r11.u32);
	// b 0x820be1a8
	sub_820BE1A8(ctx, base);
	return;
}
