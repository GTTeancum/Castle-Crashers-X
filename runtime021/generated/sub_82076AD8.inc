DEFINE_REX_FUNC(sub_82076AD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
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
	// li r5,1
	ctx.r5.s64 = 1;
	// lhz r11,1664(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1664);
	// mulli r11,r11,76
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(76));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r4,r11,140
	ctx.r4.s64 = ctx.r11.s64 + 140;
	// bl 0x82077ce0
	ctx.lr = 0x82076B08;
	sub_82077CE0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82076cc0
	if (ctx.cr6.eq) goto loc_82076CC0;
	// lhz r11,1664(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1664);
	// li r30,1
	ctx.r30.s64 = 1;
	// lwz r10,1668(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1668);
	// mulli r11,r11,76
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(76));
	// add r9,r11,r31
	ctx.r9.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r8,136(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 136);
	// lwz r7,96(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 96);
	// stb r30,112(r7)
	REX_STORE_U8(ctx.r7.u32 + 112, ctx.r30.u8);
	// lwz r6,76(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r5,156(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 156);
	// lwz r4,10316(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 10316);
	// stw r4,10316(r7)
	REX_STORE_U32(ctx.r7.u32 + 10316, ctx.r4.u32);
	// lhz r3,1664(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 1664);
	// mulli r11,r3,76
	ctx.r11.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(76));
	// add r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r11,136(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 136);
	// lwz r9,96(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82076b68
	if (ctx.cr6.eq) goto loc_82076B68;
	// lbz r9,10345(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 10345);
	// b 0x82076b6c
	goto loc_82076B6C;
loc_82076B68:
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
loc_82076B6C:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// lwz r3,136(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 136);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82076b98
	if (!ctx.cr6.eq) goto loc_82076B98;
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f1,9540(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9540);
	ctx.f1.f64 = double(temp.f32);
	// lwz r7,8(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82076B94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82076cc0
	goto loc_82076CC0;
loc_82076B98:
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82076BAC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-6608(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + -6608);
	// bl 0x8209c718
	ctx.lr = 0x82076BBC;
	sub_8209C718(ctx, base);
	// lhz r8,1664(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 1664);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mulli r11,r8,76
	ctx.r11.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(76));
	// add r7,r11,r31
	ctx.r7.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r4,136(r7)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r7.u32 + 136);
	// bl 0x820780d8
	ctx.lr = 0x82076BD4;
	sub_820780D8(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82076c18
	if (ctx.cr6.eq) goto loc_82076C18;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x82076c18
	if (!ctx.cr6.eq) goto loc_82076C18;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lis r8,-32215
	ctx.r8.s64 = -2111242240;
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r8,-22032
	ctx.r3.s64 = ctx.r8.s64 + -22032;
	// bl 0x8209a170
	ctx.lr = 0x82076C18;
	sub_8209A170(ctx, base);
loc_82076C18:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8209aed8
	ctx.lr = 0x82076C20;
	sub_8209AED8(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r8,r31,448
	ctx.r8.s64 = ctx.r31.s64 + 448;
	// addi r6,r11,-8185
	ctx.r6.s64 = ctx.r11.s64 + -8185;
loc_82076C30:
	// lwz r11,-8(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82076c70
	if (!ctx.cr6.eq) goto loc_82076C70;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_82076C44:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r5,0(r10)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r5,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r5.u64;
	// beq cr6,0x82076c68
	if (ctx.cr6.eq) goto loc_82076C68;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82076c44
	if (ctx.cr6.eq) goto loc_82076C44;
loc_82076C68:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82076cd8
	if (!ctx.cr6.eq) goto loc_82076CD8;
loc_82076C70:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,76
	ctx.r8.s64 = ctx.r8.s64 + 76;
	// cmpwi cr6,r7,20
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 20, ctx.xer);
	// blt cr6,0x82076c30
	if (ctx.cr6.lt) goto loc_82076C30;
	// lwz r11,1776(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1776);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82076cb0
	if (!ctx.cr6.eq) goto loc_82076CB0;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// stw r10,1776(r31)
	REX_STORE_U32(ctx.r31.u32 + 1776, ctx.r10.u32);
	// stb r30,1772(r31)
	REX_STORE_U8(ctx.r31.u32 + 1772, ctx.r30.u8);
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82076cb0
	if (ctx.cr6.eq) goto loc_82076CB0;
	// stb r30,1375(r11)
	REX_STORE_U8(ctx.r11.u32 + 1375, ctx.r30.u8);
	// stb r30,1376(r11)
	REX_STORE_U8(ctx.r11.u32 + 1376, ctx.r30.u8);
loc_82076CB0:
	// sth r10,1664(r31)
	REX_STORE_U16(ctx.r31.u32 + 1664, ctx.r10.u16);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,36(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// bl 0x820757c8
	ctx.lr = 0x82076CC0;
	sub_820757C8(ctx, base);
loc_82076CC0:
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
loc_82076CD8:
	// sth r7,1664(r31)
	REX_STORE_U16(ctx.r31.u32 + 1664, ctx.r7.u16);
	// b 0x82076cc0
	goto loc_82076CC0;
}
