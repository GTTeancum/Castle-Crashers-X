DEFINE_REX_FUNC(sub_82141F88) {
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
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82141fac
	if (!ctx.cr6.eq) goto loc_82141FAC;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x8214208c
	goto loc_8214208C;
loc_82141FAC:
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r11,24184(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 24184);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82142088
	if (ctx.cr6.eq) goto loc_82142088;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r11,24188(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24188);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82142088
	if (ctx.cr6.eq) goto loc_82142088;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r11,24192(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24192);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82142088
	if (ctx.cr6.eq) goto loc_82142088;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r11,24196(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24196);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82142088
	if (ctx.cr6.eq) goto loc_82142088;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r11,24200(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24200);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82142088
	if (ctx.cr6.eq) goto loc_82142088;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r11,24204(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24204);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82142088
	if (ctx.cr6.eq) goto loc_82142088;
	// lwz r11,24184(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 24184);
	// li r4,44
	ctx.r4.s64 = 44;
	// li r3,1
	ctx.r3.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82142028;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82142038
	if (!ctx.cr0.eq) goto loc_82142038;
loc_82142030:
	// li r3,6000
	ctx.r3.s64 = 6000;
	// b 0x8214208c
	goto loc_8214208C;
loc_82142038:
	// li r9,10
	ctx.r9.s64 = 10;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stb r9,12(r11)
	REX_STORE_U8(ctx.r11.u32 + 12, ctx.r9.u8);
	// li r8,100
	ctx.r8.s64 = 100;
	// ori r10,r10,64206
	ctx.r10.u64 = ctx.r10.u64 | 64206;
	// li r9,3000
	ctx.r9.s64 = 3000;
	// stw r8,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// stw r9,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// lwz r4,24(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// bl 0x82142800
	ctx.lr = 0x8214206C;
	sub_82142800(ctx, base);
	// clrlwi. r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82142080
	if (ctx.cr0.eq) goto loc_82142080;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82141ec0
	ctx.lr = 0x8214207C;
	sub_82141EC0(ctx, base);
	// b 0x82142030
	goto loc_82142030;
loc_82142080:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8214208c
	goto loc_8214208C;
loc_82142088:
	// li r3,6001
	ctx.r3.s64 = 6001;
loc_8214208C:
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
