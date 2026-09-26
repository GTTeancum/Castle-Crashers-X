DEFINE_REX_FUNC(sub_820A9D78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a9d8c
	if (!ctx.cr6.eq) goto loc_820A9D8C;
loc_820A9D84:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_820A9D8C:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820a9d84
	if (ctx.cr6.eq) goto loc_820A9D84;
	// lwz r11,108(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 108);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a9d84
	if (ctx.cr6.eq) goto loc_820A9D84;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lhz r7,0(r4)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r4.u32 + 0);
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// lfs f0,9540(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f11,f13,f2,f0
	ctx.f11.f64 = double(float(std::fma(ctx.f13.f64, ctx.f2.f64, ctx.f0.f64)));
	// lfs f13,9536(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9536);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,0(r5)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// stfs f13,0(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// fmr f12,f11
	ctx.f12.f64 = ctx.f11.f64;
	// beq cr6,0x820a9de8
	if (ctx.cr6.eq) goto loc_820A9DE8;
loc_820A9DD8:
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// lhz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r8.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a9dd8
	if (!ctx.cr6.eq) goto loc_820A9DD8;
loc_820A9DE8:
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// cmplw cr6,r4,r8
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x820a9e8c
	if (!ctx.cr6.lt) goto loc_820A9E8C;
loc_820A9DF4:
	// lhz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r9.u32 + 0);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bne cr6,0x820a9e0c
	if (!ctx.cr6.eq) goto loc_820A9E0C;
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
	// fadds f12,f11,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// b 0x820a9e80
	goto loc_820A9E80;
loc_820A9E0C:
	// lwz r10,112(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 112);
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,116(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 116);
	// lhzx r4,r7,r10
	ctx.r4.u64 = REX_LOAD_U16(ctx.r7.u32 + ctx.r10.u32);
	// rotlwi r10,r4,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 4);
	// add. r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820a9e80
	if (ctx.cr0.eq) goto loc_820A9E80;
	// lhz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 12);
	// lfs f10,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lhz r7,8(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 8);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// std r10,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f9,-16(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// std r7,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r7.u64);
	// lfd f8,-8(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// fcfid f5,f9
	ctx.f5.f64 = double(ctx.f9.s64);
	// fmadds f4,f6,f1,f0
	ctx.f4.f64 = double(float(std::fma(ctx.f6.f64, ctx.f1.f64, ctx.f0.f64)));
	// frsp f3,f5
	ctx.f3.f64 = double(float(ctx.f5.f64));
	// fmadds f0,f3,f1,f4
	ctx.f0.f64 = double(float(std::fma(ctx.f3.f64, ctx.f1.f64, ctx.f4.f64)));
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// ble cr6,0x820a9e70
	if (!ctx.cr6.gt) goto loc_820A9E70;
	// stfs f0,0(r5)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r5.u32 + 0, temp.u32);
loc_820A9E70:
	// lfs f10,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f12,f10
	ctx.cr6.compare(ctx.f12.f64, ctx.f10.f64);
	// ble cr6,0x820a9e80
	if (!ctx.cr6.gt) goto loc_820A9E80;
	// stfs f12,0(r6)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
loc_820A9E80:
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x820a9df4
	if (ctx.cr6.lt) goto loc_820A9DF4;
loc_820A9E8C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}
