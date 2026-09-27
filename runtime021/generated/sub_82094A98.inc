DEFINE_REX_FUNC(sub_82094A98) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82094AA0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lhz r11,98(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 98);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82094ac4
	if (ctx.cr6.eq) goto loc_82094AC4;
loc_82094AB8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_82094AC4:
	// lwz r3,140(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82094adc
	if (ctx.cr6.eq) goto loc_82094ADC;
	// bl 0x820a7400
	ctx.lr = 0x82094AD8;
	sub_820A7400(ctx, base);
	// stw r30,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r30.u32);
loc_82094ADC:
	// lwz r3,144(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82094af0
	if (ctx.cr6.eq) goto loc_82094AF0;
	// bl 0x820a7400
	ctx.lr = 0x82094AEC;
	sub_820A7400(ctx, base);
	// stw r30,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r30.u32);
loc_82094AF0:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82094ab8
	if (ctx.cr6.eq) goto loc_82094AB8;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82127e20
	ctx.lr = 0x82094B00;
	sub_82127E20(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// sth r11,100(r31)
	REX_STORE_U16(ctx.r31.u32 + 100, ctx.r11.u16);
	// beq cr6,0x82094b3c
	if (ctx.cr6.eq) goto loc_82094B3C;
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
	// ble cr6,0x82094b2c
	if (!ctx.cr6.gt) goto loc_82094B2C;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82094B2C:
	// bl 0x820a7390
	ctx.lr = 0x82094B30;
	sub_820A7390(ctx, base);
	// stw r3,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r3.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82127bc8
	ctx.lr = 0x82094B3C;
	sub_82127BC8(ctx, base);
loc_82094B3C:
	// lhz r3,100(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 100);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
