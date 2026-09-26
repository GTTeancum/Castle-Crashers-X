DEFINE_REX_FUNC(sub_82058478) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82058480;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// lwz r11,-6624(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6624);
	// lwz r11,1756(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1756);
	// bge cr6,0x820584d8
	if (!ctx.cr6.lt) goto loc_820584D8;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// li r30,4
	ctx.r30.s64 = 4;
loc_820584A4:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820584c4
	if (ctx.cr6.eq) goto loc_820584C4;
	// bl 0x82078d90
	ctx.lr = 0x820584B4;
	sub_82078D90(ctx, base);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820584c4
	if (ctx.cr6.eq) goto loc_820584C4;
	// stb r29,16(r11)
	REX_STORE_U8(ctx.r11.u32 + 16, ctx.r29.u8);
loc_820584C4:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x820584a4
	if (!ctx.cr0.eq) goto loc_820584A4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_820584D8:
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820584fc
	if (ctx.cr6.eq) goto loc_820584FC;
	// bl 0x82078d90
	ctx.lr = 0x820584EC;
	sub_82078D90(ctx, base);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820584fc
	if (ctx.cr6.eq) goto loc_820584FC;
	// stb r29,16(r11)
	REX_STORE_U8(ctx.r11.u32 + 16, ctx.r29.u8);
loc_820584FC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
