DEFINE_REX_FUNC(sub_821091C8) {
	REX_FUNC_PROLOGUE();
	// cmpwi cr6,r5,24
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 24, ctx.xer);
	// bne cr6,0x821091ec
	if (!ctx.cr6.eq) goto loc_821091EC;
	// cmplwi cr6,r7,20
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 20, ctx.xer);
	// bne cr6,0x821091e0
	if (!ctx.cr6.eq) goto loc_821091E0;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// b 0x821090c8
	sub_821090C8(ctx, base);
	return;
loc_821091E0:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// blr 
	return;
loc_821091EC:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16385
	ctx.r3.u64 = ctx.r3.u64 | 16385;
	// blr 
	return;
}
