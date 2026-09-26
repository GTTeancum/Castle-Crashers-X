DEFINE_REX_FUNC(sub_821227D0) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x821227e0
	if (!ctx.cr6.eq) goto loc_821227E0;
loc_821227D8:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_821227E0:
	// clrlwi. r11,r6,31
	ctx.r11.u64 = ctx.r6.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821227f0
	if (ctx.cr0.eq) goto loc_821227F0;
	// cmplw cr6,r4,r5
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x821227d8
	if (ctx.cr6.eq) goto loc_821227D8;
loc_821227F0:
	// rlwinm. r11,r6,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82122800
	if (ctx.cr0.eq) goto loc_82122800;
	// and. r11,r4,r5
	ctx.r11.u64 = ctx.r4.u64 & ctx.r5.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x821227d8
	if (!ctx.cr0.eq) goto loc_821227D8;
loc_82122800:
	// rlwinm. r11,r6,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82122810
	if (ctx.cr0.eq) goto loc_82122810;
	// or. r11,r4,r5
	ctx.r11.u64 = ctx.r4.u64 | ctx.r5.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x821227d8
	if (!ctx.cr0.eq) goto loc_821227D8;
loc_82122810:
	// rlwinm. r11,r6,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82122820
	if (ctx.cr0.eq) goto loc_82122820;
	// cmplw cr6,r4,r5
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r5.u32, ctx.xer);
	// bne cr6,0x821227d8
	if (!ctx.cr6.eq) goto loc_821227D8;
loc_82122820:
	// rlwinm. r11,r6,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82122838
	if (ctx.cr0.eq) goto loc_82122838;
	// and r11,r4,r5
	ctx.r11.u64 = ctx.r4.u64 & ctx.r5.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_82122838:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
