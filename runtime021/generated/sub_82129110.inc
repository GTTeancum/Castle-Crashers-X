DEFINE_REX_FUNC(sub_82129110) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
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
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82129134
	if (!ctx.cr6.eq) goto loc_82129134;
	// bl 0x82129190
	ctx.lr = 0x82129130;
	sub_82129190(ctx, base);
	// b 0x82129174
	goto loc_82129174;
loc_82129134:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82129078
	ctx.lr = 0x8212913C;
	sub_82129078(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8212914c
	if (ctx.cr0.eq) goto loc_8212914C;
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82129174
	goto loc_82129174;
loc_8212914C:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm. r11,r11,0,17,17
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82129170
	if (ctx.cr0.eq) goto loc_82129170;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8212e910
	ctx.lr = 0x82129160;
	sub_8212E910(ctx, base);
	// bl 0x8212f088
	ctx.lr = 0x82129164;
	sub_8212F088(ctx, base);
	// subfic r11,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r3.u64;
	// subfe r3,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// b 0x82129174
	goto loc_82129174;
loc_82129170:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82129174:
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
