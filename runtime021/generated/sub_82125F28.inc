DEFINE_REX_FUNC(sub_82125F28) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lhz r10,72(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 72);
	// lbz r11,74(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 74);
	// ori r10,r10,8192
	ctx.r10.u64 = ctx.r10.u64 | 8192;
	// rlwinm. r9,r11,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// sth r10,72(r31)
	REX_STORE_U16(ctx.r31.u32 + 72, ctx.r10.u16);
	// bne 0x82125f5c
	if (!ctx.cr0.eq) goto loc_82125F5C;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82125f98
	goto loc_82125F98;
loc_82125F5C:
	// lbz r9,75(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 75);
	// andi. r11,r11,191
	ctx.r11.u64 = ctx.r11.u64 & 191;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ori r9,r9,64
	ctx.r9.u64 = ctx.r9.u64 | 64;
	// stb r11,74(r31)
	REX_STORE_U8(ctx.r31.u32 + 74, ctx.r11.u8);
	// rlwinm. r10,r10,0,16,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stb r9,75(r31)
	REX_STORE_U8(ctx.r31.u32 + 75, ctx.r9.u8);
	// bne 0x82125f90
	if (!ctx.cr0.eq) goto loc_82125F90;
	// lhz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 72);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,20(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// ori r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 32768;
	// sth r11,72(r31)
	REX_STORE_U16(ctx.r31.u32 + 72, ctx.r11.u16);
	// bl 0x821235b0
	ctx.lr = 0x82125F90;
	sub_821235B0(ctx, base);
loc_82125F90:
	// lbz r11,74(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 74);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
loc_82125F98:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
