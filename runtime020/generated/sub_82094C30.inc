DEFINE_REX_FUNC(sub_82094C30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r11,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stw r10,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stb r11,20(r3)
	REX_STORE_U8(ctx.r3.u32 + 20, ctx.r11.u8);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// sth r11,24(r3)
	REX_STORE_U16(ctx.r3.u32 + 24, ctx.r11.u16);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// stw r11,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// stw r11,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// lfs f0,18236(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18236);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,36(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stb r11,48(r3)
	REX_STORE_U8(ctx.r3.u32 + 48, ctx.r11.u8);
	// stfs f0,40(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stb r11,49(r3)
	REX_STORE_U8(ctx.r3.u32 + 49, ctx.r11.u8);
	// stfs f0,52(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stb r11,50(r3)
	REX_STORE_U8(ctx.r3.u32 + 50, ctx.r11.u8);
	// stfs f0,56(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// addi r5,r6,-2432
	ctx.r5.s64 = ctx.r6.s64 + -2432;
	// lfs f0,9536(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,44(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f0,60(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stfs f0,64(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f0,68(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f0,72(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stb r10,102(r3)
	REX_STORE_U8(ctx.r3.u32 + 102, ctx.r10.u8);
	// addi r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 + 104;
	// stw r11,76(r3)
	REX_STORE_U32(ctx.r3.u32 + 76, ctx.r11.u32);
	// sth r11,82(r3)
	REX_STORE_U16(ctx.r3.u32 + 82, ctx.r11.u16);
	// sth r11,84(r3)
	REX_STORE_U16(ctx.r3.u32 + 84, ctx.r11.u16);
	// stw r11,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r11.u32);
	// sth r11,96(r3)
	REX_STORE_U16(ctx.r3.u32 + 96, ctx.r11.u16);
	// sth r11,98(r3)
	REX_STORE_U16(ctx.r3.u32 + 98, ctx.r11.u16);
	// lbz r4,86(r3)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r3.u32 + 86);
	// clrlwi r10,r4,28
	ctx.r10.u64 = ctx.r4.u32 & 0xF;
	// stb r10,86(r3)
	REX_STORE_U8(ctx.r3.u32 + 86, ctx.r10.u8);
	// stfs f0,104(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// stfs f0,108(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// stfs f0,112(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// stfs f0,116(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// stb r11,120(r3)
	REX_STORE_U8(ctx.r3.u32 + 120, ctx.r11.u8);
	// stb r11,124(r3)
	REX_STORE_U8(ctx.r3.u32 + 124, ctx.r11.u8);
	// lfs f0,9540(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// sth r11,126(r3)
	REX_STORE_U16(ctx.r3.u32 + 126, ctx.r11.u16);
	// sth r11,128(r3)
	REX_STORE_U16(ctx.r3.u32 + 128, ctx.r11.u16);
	// sth r11,130(r3)
	REX_STORE_U16(ctx.r3.u32 + 130, ctx.r11.u16);
	// sth r11,132(r3)
	REX_STORE_U16(ctx.r3.u32 + 132, ctx.r11.u16);
	// stfs f0,164(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 164, temp.u32);
	// stw r11,136(r3)
	REX_STORE_U32(ctx.r3.u32 + 136, ctx.r11.u32);
	// stw r11,140(r3)
	REX_STORE_U32(ctx.r3.u32 + 140, ctx.r11.u32);
	// stw r11,144(r3)
	REX_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
	// stw r5,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// sth r11,148(r3)
	REX_STORE_U16(ctx.r3.u32 + 148, ctx.r11.u16);
	// sth r11,150(r3)
	REX_STORE_U16(ctx.r3.u32 + 150, ctx.r11.u16);
	// stw r11,152(r3)
	REX_STORE_U32(ctx.r3.u32 + 152, ctx.r11.u32);
	// stw r11,156(r3)
	REX_STORE_U32(ctx.r3.u32 + 156, ctx.r11.u32);
	// sth r11,160(r3)
	REX_STORE_U16(ctx.r3.u32 + 160, ctx.r11.u16);
	// blr 
	return;
}
