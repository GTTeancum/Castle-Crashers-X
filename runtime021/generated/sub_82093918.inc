DEFINE_REX_FUNC(sub_82093918) {
	REX_FUNC_PROLOGUE();
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// addi r11,r11,-74
	ctx.r11.s64 = ctx.r11.s64 + -74;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x820939b0
	if (ctx.cr6.gt) goto loc_820939B0;
	// lis r12,-32247
	ctx.r12.s64 = -2113339392;
	// addi r12,r12,14656
	ctx.r12.s64 = ctx.r12.s64 + 14656;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82093950;
	case 1:
		goto loc_82093968;
	case 2:
		goto loc_82093980;
	case 3:
		goto loc_82093998;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82093950:
	// li r10,40
	ctx.r10.s64 = 40;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r10,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// blr 
	return;
loc_82093968:
	// li r10,37
	ctx.r10.s64 = 37;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r10,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// blr 
	return;
loc_82093980:
	// li r10,39
	ctx.r10.s64 = 39;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r10,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// blr 
	return;
loc_82093998:
	// li r10,38
	ctx.r10.s64 = 38;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r10,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// blr 
	return;
loc_820939B0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
