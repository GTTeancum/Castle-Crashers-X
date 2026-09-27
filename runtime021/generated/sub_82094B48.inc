DEFINE_REX_FUNC(sub_82094B48) {
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
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// sth r4,98(r31)
	REX_STORE_U16(ctx.r31.u32 + 98, ctx.r4.u16);
	// bne cr6,0x82094b78
	if (!ctx.cr6.eq) goto loc_82094B78;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82094c14
	goto loc_82094C14;
loc_82094B78:
	// lwz r3,140(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82094b90
	if (ctx.cr6.eq) goto loc_82094B90;
	// bl 0x820a7400
	ctx.lr = 0x82094B8C;
	sub_820A7400(ctx, base);
	// stw r30,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r30.u32);
loc_82094B90:
	// lwz r3,144(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82094ba4
	if (ctx.cr6.eq) goto loc_82094BA4;
	// bl 0x820a7400
	ctx.lr = 0x82094BA0;
	sub_820A7400(ctx, base);
	// stw r30,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r30.u32);
loc_82094BA4:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lhz r10,98(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 98);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwz r11,-6640(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6640);
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// lwzx r6,r9,r8
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r6,r5
	ctx.r30.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82127e20
	ctx.lr = 0x82094BD4;
	sub_82127E20(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// sth r11,100(r31)
	REX_STORE_U16(ctx.r31.u32 + 100, ctx.r11.u16);
	// beq cr6,0x82094c10
	if (ctx.cr6.eq) goto loc_82094C10;
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// rlwinm r3,r11,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x82094c00
	if (!ctx.cr6.gt) goto loc_82094C00;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82094C00:
	// bl 0x820a7390
	ctx.lr = 0x82094C04;
	sub_820A7390(ctx, base);
	// stw r3,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r3.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82127bc8
	ctx.lr = 0x82094C10;
	sub_82127BC8(ctx, base);
loc_82094C10:
	// lhz r3,100(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 100);
loc_82094C14:
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
