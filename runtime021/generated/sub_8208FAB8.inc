DEFINE_REX_FUNC(sub_8208FAB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r10,-6648(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -6648);
	// lhz r9,10(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// addi r6,r9,25507
	ctx.r6.s64 = ctx.r9.s64 + 25507;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r5,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// lhz r3,24(r4)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r4.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8208fb3c
	if (ctx.cr6.eq) goto loc_8208FB3C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-5516
	ctx.r3.s64 = ctx.r11.s64 + -5516;
loc_8208FAF8:
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// clrlwi r9,r11,16
	ctx.r9.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r9,10(r10)
	REX_STORE_U16(ctx.r10.u32 + 10, ctx.r9.u16);
	// cmplwi cr6,r9,400
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 400, ctx.xer);
	// bne cr6,0x8208fb10
	if (!ctx.cr6.eq) goto loc_8208FB10;
	// sth r8,10(r10)
	REX_STORE_U16(ctx.r10.u32 + 10, ctx.r8.u16);
loc_8208FB10:
	// lhz r9,10(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x8208fb20
	if (!ctx.cr6.eq) goto loc_8208FB20;
	// bl 0x8208c5d8
	ctx.lr = 0x8208FB20;
	sub_8208C5D8(ctx, base);
loc_8208FB20:
	// lhz r11,10(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// addi r11,r11,25507
	ctx.r11.s64 = ctx.r11.s64 + 25507;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r10
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// lhz r4,24(r5)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r5.u32 + 24);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8208faf8
	if (!ctx.cr6.eq) goto loc_8208FAF8;
loc_8208FB3C:
	// lhz r11,10(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// addi r6,r11,25507
	ctx.r6.s64 = ctx.r11.s64 + 25507;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,9540(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,9536(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9536);
	ctx.f13.f64 = double(temp.f32);
	// lwzx r3,r5,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// stfs f0,96(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// sth r8,80(r3)
	REX_STORE_U16(ctx.r3.u32 + 80, ctx.r8.u16);
	// stfs f13,100(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// stb r8,92(r3)
	REX_STORE_U8(ctx.r3.u32 + 92, ctx.r8.u8);
	// sth r8,94(r3)
	REX_STORE_U16(ctx.r3.u32 + 94, ctx.r8.u16);
	// stb r8,136(r3)
	REX_STORE_U8(ctx.r3.u32 + 136, ctx.r8.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
