DEFINE_REX_FUNC(sub_82141EC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82141EC8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x82141ee0
	if (!ctx.cr6.eq) goto loc_82141EE0;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x82141f78
	goto loc_82141F78;
loc_82141EE0:
	// lwz r31,0(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82141f74
	if (ctx.cr6.eq) goto loc_82141F74;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,64206
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64206, ctx.xer);
	// bne cr6,0x82141f74
	if (!ctx.cr6.eq) goto loc_82141F74;
	// lbz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// beq cr6,0x82141f0c
	if (ctx.cr6.eq) goto loc_82141F0C;
	// li r3,6115
	ctx.r3.s64 = 6115;
	// b 0x82141f78
	goto loc_82141F78;
loc_82141F0C:
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// bl 0x82142930
	ctx.lr = 0x82141F1C;
	sub_82142930(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// lis r30,-32221
	ctx.r30.s64 = -2111635456;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82141f3c
	if (ctx.cr6.eq) goto loc_82141F3C;
	// lwz r11,24188(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24188);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82141F38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r29.u32);
loc_82141F3C:
	// lwz r3,40(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82141f58
	if (ctx.cr6.eq) goto loc_82141F58;
	// lwz r11,24188(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24188);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82141F54;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r29.u32);
loc_82141F58:
	// lwz r11,24188(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24188);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82141F68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r29,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r29.u32);
	// b 0x82141f78
	goto loc_82141F78;
loc_82141F74:
	// li r3,6100
	ctx.r3.s64 = 6100;
loc_82141F78:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
