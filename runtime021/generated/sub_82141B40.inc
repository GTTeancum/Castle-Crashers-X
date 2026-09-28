DEFINE_REX_FUNC(sub_82141B40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82141B48;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r30,12(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x82141448
	ctx.lr = 0x82141B58;
	sub_82141448(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82140f28
	ctx.lr = 0x82141B60;
	sub_82140F28(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// b 0x82141b9c
	goto loc_82141B9C;
loc_82141B68:
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r30,r30,-1
	ctx.r30.s64 = ctx.r30.s64 + -1;
	// subf r11,r30,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r30.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82141b88
	if (ctx.cr6.lt) goto loc_82141B88;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// b 0x82141b94
	goto loc_82141B94;
loc_82141B88:
	// lwz r10,96(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_82141B94:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821412f8
	ctx.lr = 0x82141B9C;
	sub_821412F8(ctx, base);
loc_82141B9C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82141b68
	if (!ctx.cr6.eq) goto loc_82141B68;
	// li r11,600
	ctx.r11.s64 = 600;
	// stb r29,140(r31)
	REX_STORE_U8(ctx.r31.u32 + 140, ctx.r29.u8);
	// stw r29,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r29.u32);
	// stw r11,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// stw r29,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r29.u32);
	// stw r29,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r29.u32);
	// bl 0x82136f58
	ctx.lr = 0x82141BC0;
	sub_82136F58(ctx, base);
	// stw r3,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
