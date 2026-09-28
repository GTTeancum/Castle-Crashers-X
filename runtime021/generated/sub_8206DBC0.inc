DEFINE_REX_FUNC(sub_8206DBC0) {
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
	// lis r30,-32215
	ctx.r30.s64 = -2111242240;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,620(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 620);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8206dd08
	if (ctx.cr6.lt) goto loc_8206DD08;
	// beq cr6,0x8206dc34
	if (ctx.cr6.eq) goto loc_8206DC34;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x8206dd40
	if (!ctx.cr6.eq) goto loc_8206DD40;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-6628(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// bl 0x820a37b8
	ctx.lr = 0x8206DC04;
	sub_820A37B8(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r5,15
	ctx.r5.s64 = 15;
	// stb r10,33(r31)
	REX_STORE_U8(ctx.r31.u32 + 33, ctx.r10.u8);
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82054d38
	ctx.lr = 0x8206DC1C;
	sub_82054D38(ctx, base);
	// lis r9,-32221
	ctx.r9.s64 = -2111635456;
	// li r11,300
	ctx.r11.s64 = 300;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,620(r30)
	REX_STORE_U32(ctx.r30.u32 + 620, ctx.r10.u32);
	// stw r11,824(r9)
	REX_STORE_U32(ctx.r9.u32 + 824, ctx.r11.u32);
	// b 0x8206dd40
	goto loc_8206DD40;
loc_8206DC34:
	// lis r9,-32221
	ctx.r9.s64 = -2111635456;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,300
	ctx.r10.s64 = 300;
	// stw r11,620(r30)
	REX_STORE_U32(ctx.r30.u32 + 620, ctx.r11.u32);
	// lis r8,-32218
	ctx.r8.s64 = -2111438848;
	// addi r3,r31,12
	ctx.r3.s64 = ctx.r31.s64 + 12;
	// stw r10,824(r9)
	REX_STORE_U32(ctx.r9.u32 + 824, ctx.r10.u32);
	// li r6,32
	ctx.r6.s64 = 32;
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r11,-6628(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -6628);
	// lwz r5,24(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// bl 0x821274b0
	ctx.lr = 0x8206DC64;
	sub_821274B0(ctx, base);
	// lis r4,-32218
	ctx.r4.s64 = -2111438848;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,105
	ctx.r6.s64 = 105;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-6596(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + -6596);
	// bl 0x820a1138
	ctx.lr = 0x8206DC84;
	sub_820A1138(ctx, base);
	// li r4,40
	ctx.r4.s64 = 40;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053bc8
	ctx.lr = 0x8206DC90;
	sub_82053BC8(ctx, base);
	// lhz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8206dcf0
	if (ctx.cr6.lt) goto loc_8206DCF0;
	// beq cr6,0x8206dcd8
	if (ctx.cr6.eq) goto loc_8206DCD8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x8206dcc0
	if (ctx.cr6.eq) goto loc_8206DCC0;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r4,582
	ctx.r4.s64 = 582;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x8206DCBC;
	sub_82067230(ctx, base);
	// b 0x8206dd40
	goto loc_8206DD40;
loc_8206DCC0:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r4,390
	ctx.r4.s64 = 390;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x8206DCD4;
	sub_82067230(ctx, base);
	// b 0x8206dd40
	goto loc_8206DD40;
loc_8206DCD8:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r4,389
	ctx.r4.s64 = 389;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x8206DCEC;
	sub_82067230(ctx, base);
	// b 0x8206dd40
	goto loc_8206DD40;
loc_8206DCF0:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r4,382
	ctx.r4.s64 = 382;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x8206DD04;
	sub_82067230(ctx, base);
	// b 0x8206dd40
	goto loc_8206DD40;
loc_8206DD08:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8206dd24
	if (ctx.cr6.eq) goto loc_8206DD24;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x8206dd3c
	goto loc_8206DD3C;
loc_8206DD24:
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// lwz r11,824(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 824);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,824(r10)
	REX_STORE_U32(ctx.r10.u32 + 824, ctx.r11.u32);
	// bgt 0x8206dd40
	if (ctx.cr0.gt) goto loc_8206DD40;
	// li r11,3
	ctx.r11.s64 = 3;
loc_8206DD3C:
	// stw r11,620(r30)
	REX_STORE_U32(ctx.r30.u32 + 620, ctx.r11.u32);
loc_8206DD40:
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
