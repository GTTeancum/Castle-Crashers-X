DEFINE_REX_FUNC(sub_820A8650) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lbz r11,28715(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 28715);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lbz r11,28739(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 28739);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lbz r7,28736(r3)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r3.u32 + 28736);
	// li r10,0
	ctx.r10.s64 = 0;
	// rotlwi r6,r11,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r4,28737(r3)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r3.u32 + 28737);
	// lbz r11,28738(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 28738);
	// li r9,0
	ctx.r9.s64 = 0;
	// or r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 | ctx.r7.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f1,9540(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9540);
	ctx.f1.f64 = double(temp.f32);
	// li r6,63
	ctx.r6.s64 = 63;
	// rlwinm r8,r7,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// li r5,0
	ctx.r5.s64 = 0;
	// or r7,r8,r4
	ctx.r7.u64 = ctx.r8.u64 | ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r8,r7,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | ctx.r11.u64;
	// b 0x820c2c98
	sub_820C2C98(ctx, base);
	return;
}
