DEFINE_REX_FUNC(sub_8208F828) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r10,-6648(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -6648);
	// lhz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// addi r6,r9,7
	ctx.r6.s64 = ctx.r9.s64 + 7;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r5,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// lhz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208f8ac
	if (ctx.cr6.eq) goto loc_8208F8AC;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-5676
	ctx.r3.s64 = ctx.r11.s64 + -5676;
loc_8208F868:
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// clrlwi r9,r11,16
	ctx.r9.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r9,4(r10)
	REX_STORE_U16(ctx.r10.u32 + 4, ctx.r9.u16);
	// cmplwi cr6,r9,10500
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 10500, ctx.xer);
	// bne cr6,0x8208f880
	if (!ctx.cr6.eq) goto loc_8208F880;
	// sth r8,4(r10)
	REX_STORE_U16(ctx.r10.u32 + 4, ctx.r8.u16);
loc_8208F880:
	// lhz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x8208f890
	if (!ctx.cr6.eq) goto loc_8208F890;
	// bl 0x8208c5d8
	ctx.lr = 0x8208F890;
	sub_8208C5D8(ctx, base);
loc_8208F890:
	// lhz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r10
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// lhz r11,24(r5)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r5.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208f868
	if (!ctx.cr6.eq) goto loc_8208F868;
loc_8208F8AC:
	// lhz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// addi r6,r11,7
	ctx.r6.s64 = ctx.r11.s64 + 7;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,18236(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18236);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,9536(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// lwzx r3,r5,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// sth r8,80(r3)
	REX_STORE_U16(ctx.r3.u32 + 80, ctx.r8.u16);
	// stfs f13,36(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f13,40(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stb r8,48(r3)
	REX_STORE_U8(ctx.r3.u32 + 48, ctx.r8.u8);
	// stfs f0,44(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stb r8,49(r3)
	REX_STORE_U8(ctx.r3.u32 + 49, ctx.r8.u8);
	// stfs f13,52(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stb r8,50(r3)
	REX_STORE_U8(ctx.r3.u32 + 50, ctx.r8.u8);
	// stfs f13,56(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 56, temp.u32);
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
	// lbz r11,86(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 86);
	// ori r9,r11,144
	ctx.r9.u64 = ctx.r11.u64 | 144;
	// stw r4,92(r3)
	REX_STORE_U32(ctx.r3.u32 + 92, ctx.r4.u32);
	// stb r9,86(r3)
	REX_STORE_U8(ctx.r3.u32 + 86, ctx.r9.u8);
	// lwz r11,24(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r11.u32);
	// stw r11,136(r3)
	REX_STORE_U32(ctx.r3.u32 + 136, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
