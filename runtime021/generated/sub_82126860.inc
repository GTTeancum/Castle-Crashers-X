DEFINE_REX_FUNC(sub_82126860) {
	REX_FUNC_PROLOGUE();
	// lhz r11,72(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 72);
	// ori r11,r11,1024
	ctx.r11.u64 = ctx.r11.u64 | 1024;
	// rlwinm. r10,r11,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// sth r11,72(r3)
	REX_STORE_U16(ctx.r3.u32 + 72, ctx.r11.u16);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,568(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 568);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,568(r10)
	REX_STORE_U32(ctx.r10.u32 + 568, ctx.r11.u32);
	// lhz r11,72(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 72);
	// ori r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 2048;
	// sth r11,72(r3)
	REX_STORE_U16(ctx.r3.u32 + 72, ctx.r11.u16);
	// blr 
	return;
}
