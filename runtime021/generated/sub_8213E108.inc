DEFINE_REX_FUNC(sub_8213E108) {
	REX_FUNC_PROLOGUE();
	// addi r11,r4,9
	ctx.r11.s64 = ctx.r4.s64 + 9;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r3
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// cmplw cr6,r5,r10
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8213e12c
	if (ctx.cr6.eq) goto loc_8213E12C;
	// li r10,1
	ctx.r10.s64 = 1;
	// stwx r5,r11,r3
	REX_STORE_U32(ctx.r11.u32 + ctx.r3.u32, ctx.r5.u32);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// stw r10,1308(r11)
	REX_STORE_U32(ctx.r11.u32 + 1308, ctx.r10.u32);
loc_8213E12C:
	// b 0x8213da80
	sub_8213DA80(ctx, base);
	return;
}
