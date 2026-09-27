DEFINE_REX_FUNC(sub_82083550) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82083558;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r10,28(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r10,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// lwz r9,32(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// stw r9,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r9.u32);
	// beq cr6,0x82083598
	if (ctx.cr6.eq) goto loc_82083598;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r29,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r29.u32);
	// lwz r3,76(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// bl 0x82066ea8
	ctx.lr = 0x82083594;
	sub_82066EA8(ctx, base);
	// stw r29,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r29.u32);
loc_82083598:
	// lwz r4,76(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 76);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820835ac
	if (ctx.cr6.eq) goto loc_820835AC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820837c0
	ctx.lr = 0x820835AC;
	sub_820837C0(ctx, base);
loc_820835AC:
	// lhz r11,80(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 80);
	// lbz r10,86(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 86);
	// clrlwi r9,r10,25
	ctx.r9.u64 = ctx.r10.u32 & 0x7F;
	// sth r11,80(r31)
	REX_STORE_U16(ctx.r31.u32 + 80, ctx.r11.u16);
	// stb r9,86(r31)
	REX_STORE_U8(ctx.r31.u32 + 86, ctx.r9.u8);
	// lbz r8,86(r30)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r30.u32 + 86);
	// rlwinm r7,r8,0,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8208363c
	if (ctx.cr6.eq) goto loc_8208363C;
	// lfs f0,36(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,36(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// lfs f13,40(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,40(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 40, temp.u32);
	// lfs f12,44(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,44(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// lfs f11,52(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 52);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,52(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 52, temp.u32);
	// lfs f10,56(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 56);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,56(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
	// lfs f9,60(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 60);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,60(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r31.u32 + 60, temp.u32);
	// lfs f8,64(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 64);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,64(r31)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// lfs f7,68(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 68);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,68(r31)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// lfs f6,72(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 72);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,72(r31)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// lbz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 48);
	// stb r11,48(r31)
	REX_STORE_U8(ctx.r31.u32 + 48, ctx.r11.u8);
	// lbz r10,49(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 49);
	// stb r10,49(r31)
	REX_STORE_U8(ctx.r31.u32 + 49, ctx.r10.u8);
	// lbz r9,50(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 50);
	// stb r9,50(r31)
	REX_STORE_U8(ctx.r31.u32 + 50, ctx.r9.u8);
	// lbz r8,86(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 86);
	// ori r7,r8,128
	ctx.r7.u64 = ctx.r8.u64 | 128;
	// stb r7,86(r31)
	REX_STORE_U8(ctx.r31.u32 + 86, ctx.r7.u8);
loc_8208363C:
	// lbz r11,86(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 86);
	// lbz r10,86(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 86);
	// rlwimi r10,r11,0,27,27
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFEF);
	// stb r10,86(r31)
	REX_STORE_U8(ctx.r31.u32 + 86, ctx.r10.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
