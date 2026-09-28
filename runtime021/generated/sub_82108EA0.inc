DEFINE_REX_FUNC(sub_82108EA0) {
	REX_FUNC_PROLOGUE();
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// rlwinm. r10,r11,0,3,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82108eb8
	if (ctx.cr0.eq) goto loc_82108EB8;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// b 0x82110960
	sub_82110960(ctx, base);
	return;
loc_82108EB8:
	// rlwinm. r10,r11,0,2,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82108ecc
	if (ctx.cr0.eq) goto loc_82108ECC;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// b 0x82110ae0
	sub_82110AE0(ctx, base);
	return;
loc_82108ECC:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4105
	ctx.r3.u64 = ctx.r3.u64 | 4105;
	// blr 
	return;
}
