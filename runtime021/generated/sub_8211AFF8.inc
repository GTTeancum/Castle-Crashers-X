DEFINE_REX_FUNC(sub_8211AFF8) {
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
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x8211b098
	if (ctx.cr6.eq) goto loc_8211B098;
	// lbz r11,1144(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1144);
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8211b098
	if (!ctx.cr0.eq) goto loc_8211B098;
	// cmpwi cr6,r4,3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 3, ctx.xer);
	// bne cr6,0x8211b040
	if (!ctx.cr6.eq) goto loc_8211B040;
	// ori r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 16;
	// addi r3,r31,296
	ctx.r3.s64 = ctx.r31.s64 + 296;
	// stb r11,1144(r31)
	REX_STORE_U8(ctx.r31.u32 + 1144, ctx.r11.u8);
	// bl 0x82122310
	ctx.lr = 0x8211B03C;
	sub_82122310(ctx, base);
	// b 0x8211b098
	goto loc_8211B098;
loc_8211B040:
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// bne cr6,0x8211b050
	if (!ctx.cr6.eq) goto loc_8211B050;
	// lhz r30,1036(r31)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r31.u32 + 1036);
	// b 0x8211b054
	goto loc_8211B054;
loc_8211B050:
	// lhz r30,1034(r31)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r31.u32 + 1034);
loc_8211B054:
	// lwz r11,352(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 352);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8211b078
	if (!ctx.cr0.eq) goto loc_8211B078;
	// bl 0x82136f58
	ctx.lr = 0x8211B064;
	sub_82136F58(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r31,296
	ctx.r3.s64 = ctx.r31.s64 + 296;
	// bl 0x82122270
	ctx.lr = 0x8211B074;
	sub_82122270(ctx, base);
	// b 0x8211b098
	goto loc_8211B098;
loc_8211B078:
	// lwz r11,348(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// add r4,r30,r5
	ctx.r4.u64 = ctx.r30.u64 + ctx.r5.u64;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// subf r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// addi r3,r31,296
	ctx.r3.s64 = ctx.r31.s64 + 296;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8211b098
	if (ctx.cr6.lt) goto loc_8211B098;
	// bl 0x82119f88
	ctx.lr = 0x8211B098;
	sub_82119F88(ctx, base);
loc_8211B098:
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
