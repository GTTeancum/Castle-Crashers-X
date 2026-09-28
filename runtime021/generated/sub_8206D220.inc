DEFINE_REX_FUNC(sub_8206D220) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r10,48(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,-6652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6652);
	// lhz r10,10(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// lbz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8206d244
	if (!ctx.cr6.eq) goto loc_8206D244;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8206d254
	goto loc_8206D254;
loc_8206D244:
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r8,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
loc_8206D254:
	// lis r8,-32218
	ctx.r8.s64 = -2111438848;
	// li r9,3
	ctx.r9.s64 = 3;
	// li r6,1
	ctx.r6.s64 = 1;
	// stb r9,35(r11)
	REX_STORE_U8(ctx.r11.u32 + 35, ctx.r9.u8);
	// extsh r5,r10
	ctx.r5.s64 = ctx.r10.s16;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6624(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + -6624);
	// b 0x82077310
	sub_82077310(ctx, base);
	return;
}
