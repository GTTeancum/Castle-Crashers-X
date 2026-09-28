DEFINE_REX_FUNC(sub_82142398) {
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
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x821423c0
	if (!ctx.cr6.eq) goto loc_821423C0;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x821424c8
	goto loc_821424C8;
loc_821423C0:
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// li r31,0
	ctx.r31.s64 = 0;
	// stw r31,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r31.u32);
	// lwz r11,24184(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 24184);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821424c4
	if (ctx.cr6.eq) goto loc_821424C4;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r11,24188(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24188);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821424c4
	if (ctx.cr6.eq) goto loc_821424C4;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r11,24192(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24192);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821424c4
	if (ctx.cr6.eq) goto loc_821424C4;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r11,24196(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24196);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821424c4
	if (ctx.cr6.eq) goto loc_821424C4;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r11,24200(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24200);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821424c4
	if (ctx.cr6.eq) goto loc_821424C4;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r11,24204(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24204);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821424c4
	if (ctx.cr6.eq) goto loc_821424C4;
	// lwz r11,24184(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 24184);
	// li r4,44
	ctx.r4.s64 = 44;
	// li r3,1
	ctx.r3.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8214243C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8214244c
	if (!ctx.cr0.eq) goto loc_8214244C;
loc_82142444:
	// li r3,6000
	ctx.r3.s64 = 6000;
	// b 0x821424c8
	goto loc_821424C8;
loc_8214244C:
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// li r9,11
	ctx.r9.s64 = 11;
	// ori r10,r10,64206
	ctx.r10.u64 = ctx.r10.u64 | 64206;
	// stb r9,12(r11)
	REX_STORE_U8(ctx.r11.u32 + 12, ctx.r9.u8);
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// bl 0x821434d8
	ctx.lr = 0x8214246C;
	sub_821434D8(ctx, base);
	// clrlwi. r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82142480
	if (ctx.cr0.eq) goto loc_82142480;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821422d8
	ctx.lr = 0x8214247C;
	sub_821422D8(ctx, base);
	// b 0x82142444
	goto loc_82142444;
loc_82142480:
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// lis r11,15258
	ctx.r11.s64 = 999948288;
	// addi r30,r10,24144
	ctx.r30.s64 = ctx.r10.s64 + 24144;
	// ori r11,r11,51712
	ctx.r11.u64 = ctx.r11.u64 | 51712;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// std r31,0(r9)
	REX_STORE_U64(ctx.r9.u32 + 0, ctx.r31.u64);
	// std r31,8(r9)
	REX_STORE_U64(ctx.r9.u32 + 8, ctx.r31.u64);
	// std r31,16(r9)
	REX_STORE_U64(ctx.r9.u32 + 16, ctx.r31.u64);
	// std r31,24(r9)
	REX_STORE_U64(ctx.r9.u32 + 24, ctx.r31.u64);
	// std r31,32(r9)
	REX_STORE_U64(ctx.r9.u32 + 32, ctx.r31.u64);
	// std r11,24144(r10)
	REX_STORE_U64(ctx.r10.u32 + 24144, ctx.r11.u64);
	// bl 0x820b6d10
	ctx.lr = 0x821424B4;
	sub_820B6D10(ctx, base);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,32(r30)
	REX_STORE_U32(ctx.r30.u32 + 32, ctx.r11.u32);
	// b 0x821424c8
	goto loc_821424C8;
loc_821424C4:
	// li r3,6001
	ctx.r3.s64 = 6001;
loc_821424C8:
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
