DEFINE_REX_FUNC(sub_82083658) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// addi r11,r11,2720
	ctx.r11.s64 = ctx.r11.s64 + 2720;
	// lwz r10,2760(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 2760);
	// clrlwi r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x820836c4
	if (!ctx.cr6.eq) goto loc_820836C4;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// stb r8,12(r11)
	REX_STORE_U8(ctx.r11.u32 + 12, ctx.r8.u8);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// stw r10,2760(r9)
	REX_STORE_U32(ctx.r9.u32 + 2760, ctx.r10.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r7,13(r11)
	REX_STORE_U8(ctx.r11.u32 + 13, ctx.r7.u8);
	// lfs f13,18236(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 18236);
	ctx.f13.f64 = double(temp.f32);
	// stb r10,14(r11)
	REX_STORE_U8(ctx.r11.u32 + 14, ctx.r10.u8);
	// lfs f0,9536(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// stfs f13,16(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// stfs f13,20(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// stfs f0,24(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// stfs f0,28(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 28, temp.u32);
	// stfs f0,32(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 32, temp.u32);
	// stfs f0,36(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 36, temp.u32);
loc_820836C4:
	// lbz r10,86(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 86);
	// addi r3,r3,36
	ctx.r3.s64 = ctx.r3.s64 + 36;
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}
