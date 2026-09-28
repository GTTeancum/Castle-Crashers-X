DEFINE_REX_FUNC(sub_82141CF8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82141D00;
	__savegprlr_28(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82141d1c
	if (!ctx.cr6.eq) goto loc_82141D1C;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x82141e0c
	goto loc_82141E0C;
loc_82141D1C:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82141d30
	if (!ctx.cr6.eq) goto loc_82141D30;
	// li r3,6130
	ctx.r3.s64 = 6130;
	// b 0x82141e0c
	goto loc_82141E0C;
loc_82141D30:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82141d44
	if (!ctx.cr6.eq) goto loc_82141D44;
	// li r3,6125
	ctx.r3.s64 = 6125;
	// b 0x82141e0c
	goto loc_82141E0C;
loc_82141D44:
	// lhz r10,14(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 14);
	// lhz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82141d5c
	if (ctx.cr6.lt) goto loc_82141D5C;
	// li r3,6145
	ctx.r3.s64 = 6145;
	// b 0x82141e0c
	goto loc_82141E0C;
loc_82141D5C:
	// lhz r10,18(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 18);
	// addi r29,r31,18
	ctx.r29.s64 = ctx.r31.s64 + 18;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82141d74
	if (ctx.cr6.lt) goto loc_82141D74;
	// li r3,6150
	ctx.r3.s64 = 6150;
	// b 0x82141e0c
	goto loc_82141E0C;
loc_82141D74:
	// lbz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// ble cr6,0x82141d88
	if (!ctx.cr6.gt) goto loc_82141D88;
	// li r3,6135
	ctx.r3.s64 = 6135;
	// b 0x82141e0c
	goto loc_82141E0C;
loc_82141D88:
	// lbz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 20);
	// addi r30,r31,20
	ctx.r30.s64 = ctx.r31.s64 + 20;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// ble cr6,0x82141da0
	if (!ctx.cr6.gt) goto loc_82141DA0;
	// li r3,6140
	ctx.r3.s64 = 6140;
	// b 0x82141e0c
	goto loc_82141E0C;
loc_82141DA0:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82141e08
	if (ctx.cr6.eq) goto loc_82141E08;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,64206
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64206, ctx.xer);
	// bne cr6,0x82141e08
	if (!ctx.cr6.eq) goto loc_82141E08;
	// lbz r11,12(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 12);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// beq cr6,0x82141dc8
	if (ctx.cr6.eq) goto loc_82141DC8;
	// li r3,6110
	ctx.r3.s64 = 6110;
	// b 0x82141e0c
	goto loc_82141E0C;
loc_82141DC8:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,16(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 16);
	// bl 0x82142ee0
	ctx.lr = 0x82141DD4;
	sub_82142EE0(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r4,16(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 16);
	// bl 0x82142768
	ctx.lr = 0x82141DE4;
	sub_82142768(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// lhz r7,12(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821426f8
	ctx.lr = 0x82141E00;
	sub_821426F8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82141e0c
	goto loc_82141E0C;
loc_82141E08:
	// li r3,6100
	ctx.r3.s64 = 6100;
loc_82141E0C:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
