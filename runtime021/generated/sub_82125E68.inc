DEFINE_REX_FUNC(sub_82125E68) {
	REX_FUNC_PROLOGUE();
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// clrldi r11,r4,32
	ctx.r11.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// ld r10,24(r9)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r9.u32 + 24);
	// rldicl r8,r10,5,59
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 5) & 0x1F;
	// cmpld cr6,r8,r11
	ctx.cr6.compare<uint64_t>(ctx.r8.u64, ctx.r11.u64, ctx.xer);
	// bgt cr6,0x82125e88
	if (ctx.cr6.gt) goto loc_82125E88;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82125E88:
	// clrldi r10,r10,5
	ctx.r10.u64 = ctx.r10.u64 & 0x7FFFFFFFFFFFFFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// rldimi r10,r11,59,0
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u64, 59) & 0xF800000000000000) | (ctx.r10.u64 & 0x7FFFFFFFFFFFFFF);
	// std r10,24(r9)
	REX_STORE_U64(ctx.r9.u32 + 24, ctx.r10.u64);
	// blr 
	return;
}
