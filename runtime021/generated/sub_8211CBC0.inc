DEFINE_REX_FUNC(sub_8211CBC0) {
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
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// beq cr6,0x8211cc50
	if (ctx.cr6.eq) goto loc_8211CC50;
	// addi r10,r31,176
	ctx.r10.s64 = ctx.r31.s64 + 176;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8211cbfc
	if (!ctx.cr6.eq) goto loc_8211CBFC;
	// bl 0x8211c9a0
	ctx.lr = 0x8211CBF8;
	sub_8211C9A0(ctx, base);
	// b 0x8211cc50
	goto loc_8211CC50;
loc_8211CBFC:
	// addi r10,r31,236
	ctx.r10.s64 = ctx.r31.s64 + 236;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8211cc14
	if (!ctx.cr6.eq) goto loc_8211CC14;
	// lbz r11,1144(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1144);
	// ori r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 8;
	// b 0x8211cc28
	goto loc_8211CC28;
loc_8211CC14:
	// addi r10,r31,296
	ctx.r10.s64 = ctx.r31.s64 + 296;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8211cc30
	if (!ctx.cr6.eq) goto loc_8211CC30;
	// lbz r11,1144(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1144);
	// ori r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 16;
loc_8211CC28:
	// stb r11,1144(r31)
	REX_STORE_U8(ctx.r31.u32 + 1144, ctx.r11.u8);
	// b 0x8211cc50
	goto loc_8211CC50;
loc_8211CC30:
	// addi r10,r31,356
	ctx.r10.s64 = ctx.r31.s64 + 356;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8211cc48
	if (!ctx.cr6.eq) goto loc_8211CC48;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211ca20
	ctx.lr = 0x8211CC44;
	sub_8211CA20(ctx, base);
	// b 0x8211cc50
	goto loc_8211CC50;
loc_8211CC48:
	// addi r3,r11,-80
	ctx.r3.s64 = ctx.r11.s64 + -80;
	// bl 0x82123600
	ctx.lr = 0x8211CC50;
	sub_82123600(ctx, base);
loc_8211CC50:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211c7f8
	ctx.lr = 0x8211CC58;
	sub_8211C7F8(ctx, base);
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
