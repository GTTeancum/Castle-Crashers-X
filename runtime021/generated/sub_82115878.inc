DEFINE_REX_FUNC(sub_82115878) {
	REX_FUNC_PROLOGUE();
	// lis r11,4626
	ctx.r11.s64 = 303169536;
	// ori r11,r11,4626
	ctx.r11.u64 = ctx.r11.u64 | 4626;
	// cmpw cr6,r8,r11
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x821158c0
	if (ctx.cr6.eq) goto loc_821158C0;
	// lis r11,13364
	ctx.r11.s64 = 875823104;
	// ori r11,r11,13364
	ctx.r11.u64 = ctx.r11.u64 | 13364;
	// cmpw cr6,r8,r11
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x821158c0
	if (ctx.cr6.eq) goto loc_821158C0;
	// mulli r11,r4,5
	ctx.r11.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(5));
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x821158c0
	if (ctx.cr6.eq) goto loc_821158C0;
loc_821158A8:
	// lwz r10,5(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 5);
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x821158cc
	if (ctx.cr6.eq) goto loc_821158CC;
	// addic. r5,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// addi r11,r11,13
	ctx.r11.s64 = ctx.r11.s64 + 13;
	// bne 0x821158a8
	if (!ctx.cr0.eq) goto loc_821158A8;
loc_821158C0:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4106
	ctx.r3.u64 = ctx.r3.u64 | 4106;
	// blr 
	return;
loc_821158CC:
	// stw r8,9(r11)
	REX_STORE_U32(ctx.r11.u32 + 9, ctx.r8.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
