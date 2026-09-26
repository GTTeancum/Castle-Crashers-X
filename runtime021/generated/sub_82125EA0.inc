DEFINE_REX_FUNC(sub_82125EA0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lhz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 72);
	// lwz r3,20(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r5,r11,21,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 21) & 0x1;
	// bl 0x821233b8
	ctx.lr = 0x82125ED0;
	sub_821233B8(ctx, base);
	// lbz r11,74(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 74);
	// lwz r3,20(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82125eec
	if (!ctx.cr0.eq) goto loc_82125EEC;
	// bl 0x82122b78
	ctx.lr = 0x82125EE8;
	sub_82122B78(ctx, base);
	// b 0x82125f0c
	goto loc_82125F0C;
loc_82125EEC:
	// lhz r10,72(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 72);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r11,75(r31)
	REX_STORE_U8(ctx.r31.u32 + 75, ctx.r11.u8);
	// ori r11,r10,32768
	ctx.r11.u64 = ctx.r10.u64 | 32768;
	// stb r9,74(r31)
	REX_STORE_U8(ctx.r31.u32 + 74, ctx.r9.u8);
	// stw r30,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r30.u32);
	// sth r11,72(r31)
	REX_STORE_U16(ctx.r31.u32 + 72, ctx.r11.u16);
	// bl 0x821235b0
	ctx.lr = 0x82125F0C;
	sub_821235B0(ctx, base);
loc_82125F0C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
