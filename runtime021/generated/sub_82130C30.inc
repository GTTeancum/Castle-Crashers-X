DEFINE_REX_FUNC(sub_82130C30) {
	REX_FUNC_PROLOGUE();
	// rlwinm. r11,r3,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82130c40
	if (ctx.cr0.eq) goto loc_82130C40;
	// li r3,5
	ctx.r3.s64 = 5;
	// blr 
	return;
loc_82130C40:
	// rlwinm. r11,r3,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82130c50
	if (ctx.cr0.eq) goto loc_82130C50;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82130C50:
	// rlwinm. r11,r3,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82130c60
	if (ctx.cr0.eq) goto loc_82130C60;
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_82130C60:
	// clrlwi. r11,r3,31
	ctx.r11.u64 = ctx.r3.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82130c70
	if (ctx.cr0.eq) goto loc_82130C70;
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_82130C70:
	// rlwinm r3,r3,1,29,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x4;
	// blr 
	return;
}
