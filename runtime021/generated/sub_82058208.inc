DEFINE_REX_FUNC(sub_82058208) {
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
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r6,1
	ctx.r6.s64 = 1;
	// lhz r5,52(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// lhz r4,10(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// bl 0x82053c70
	ctx.lr = 0x82058244;
	sub_82053C70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82058308
	if (ctx.cr6.eq) goto loc_82058308;
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// lwz r3,-6628(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// bl 0x820a3900
	ctx.lr = 0x8205825C;
	sub_820A3900(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r4,-6628(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// beq cr6,0x82058298
	if (ctx.cr6.eq) goto loc_82058298;
	// bl 0x820a37b8
	ctx.lr = 0x82058270;
	sub_820A37B8(ctx, base);
	// li r11,7
	ctx.r11.s64 = 7;
	// li r5,15
	ctx.r5.s64 = 15;
	// sth r11,44(r31)
	REX_STORE_U16(ctx.r31.u32 + 44, ctx.r11.u16);
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82054d38
	ctx.lr = 0x82058288;
	sub_82054D38(ctx, base);
	// lwz r11,-6628(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,140(r11)
	REX_STORE_U32(ctx.r11.u32 + 140, ctx.r10.u32);
	// b 0x82058308
	goto loc_82058308;
loc_82058298:
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// addi r6,r31,12
	ctx.r6.s64 = ctx.r31.s64 + 12;
	// sth r11,18(r31)
	REX_STORE_U16(ctx.r31.u32 + 18, ctx.r11.u16);
	// stb r11,32(r31)
	REX_STORE_U8(ctx.r31.u32 + 32, ctx.r11.u8);
	// lhz r9,10(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// extsh r5,r9
	ctx.r5.s64 = ctx.r9.s16;
	// bl 0x820a40e8
	ctx.lr = 0x820582B8;
	sub_820A40E8(ctx, base);
	// li r4,35
	ctx.r4.s64 = 35;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053bc8
	ctx.lr = 0x820582C4;
	sub_82053BC8(ctx, base);
	// lhz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x820582f4
	if (ctx.cr6.lt) goto loc_820582F4;
	// beq cr6,0x820582ec
	if (ctx.cr6.eq) goto loc_820582EC;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x820582e4
	if (ctx.cr6.eq) goto loc_820582E4;
	// li r4,582
	ctx.r4.s64 = 582;
	// b 0x820582f8
	goto loc_820582F8;
loc_820582E4:
	// li r4,390
	ctx.r4.s64 = 390;
	// b 0x820582f8
	goto loc_820582F8;
loc_820582EC:
	// li r4,389
	ctx.r4.s64 = 389;
	// b 0x820582f8
	goto loc_820582F8;
loc_820582F4:
	// li r4,382
	ctx.r4.s64 = 382;
loc_820582F8:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x82058308;
	sub_82067230(ctx, base);
loc_82058308:
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
