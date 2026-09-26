DEFINE_REX_FUNC(sub_821329E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82132a0c
	if (!ctx.cr6.eq) goto loc_82132A0C;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82132a0c
	if (ctx.cr6.eq) goto loc_82132A0C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82132ae8
	if (ctx.cr6.eq) goto loc_82132AE8;
	// b 0x82132ae4
	goto loc_82132AE4;
loc_82132A0C:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82132a1c
	if (ctx.cr6.eq) goto loc_82132A1C;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_82132A1C:
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// cmplw cr6,r5,r10
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82132a58
	if (!ctx.cr6.gt) goto loc_82132A58;
	// bl 0x821294e0
	ctx.lr = 0x82132A30;
	sub_821294E0(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8212c298
	ctx.lr = 0x82132A50;
	sub_8212C298(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x82132aec
	goto loc_82132AEC;
loc_82132A58:
	// clrlwi r10,r6,16
	ctx.r10.u64 = ctx.r6.u32 & 0xFFFF;
	// cmplwi cr6,r10,255
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 255, ctx.xer);
	// ble cr6,0x82132a98
	if (!ctx.cr6.gt) goto loc_82132A98;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82132a80
	if (ctx.cr6.eq) goto loc_82132A80;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82132a80
	if (ctx.cr6.eq) goto loc_82132A80;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x82129fa0
	ctx.lr = 0x82132A80;
	sub_82129FA0(ctx, base);
loc_82132A80:
	// bl 0x821294e0
	ctx.lr = 0x82132A84;
	sub_821294E0(ctx, base);
	// li r11,42
	ctx.r11.s64 = 42;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x821294e0
	ctx.lr = 0x82132A90;
	sub_821294E0(ctx, base);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x82132aec
	goto loc_82132AEC;
loc_82132A98:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82132ad8
	if (ctx.cr6.eq) goto loc_82132AD8;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x82132ad4
	if (!ctx.cr6.eq) goto loc_82132AD4;
	// bl 0x821294e0
	ctx.lr = 0x82132AAC;
	sub_821294E0(ctx, base);
	// li r11,34
	ctx.r11.s64 = 34;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8212c298
	ctx.lr = 0x82132ACC;
	sub_8212C298(ctx, base);
	// li r3,34
	ctx.r3.s64 = 34;
	// b 0x82132aec
	goto loc_82132AEC;
loc_82132AD4:
	// stb r6,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r6.u8);
loc_82132AD8:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82132ae8
	if (ctx.cr6.eq) goto loc_82132AE8;
	// li r11,1
	ctx.r11.s64 = 1;
loc_82132AE4:
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_82132AE8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82132AEC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
