DEFINE_REX_FUNC(sub_82079B48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82079B50;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r30,1256
	ctx.r30.s64 = 1256;
	// addi r31,r28,5032
	ctx.r31.s64 = ctx.r28.s64 + 5032;
	// li r29,0
	ctx.r29.s64 = 0;
loc_82079B64:
	// lbz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82079bbc
	if (ctx.cr6.eq) goto loc_82079BBC;
	// lis r12,7
	ctx.r12.s64 = 458752;
	// lwz r11,-4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -4);
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// and r10,r11,r12
	ctx.r10.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82079bbc
	if (ctx.cr6.eq) goto loc_82079BBC;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lhz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82079bbc
	if (ctx.cr6.eq) goto loc_82079BBC;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82079bb0
	if (!ctx.cr6.eq) goto loc_82079BB0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82079BB0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82079BB0:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82066ea8
	ctx.lr = 0x82079BBC;
	sub_82066EA8(ctx, base);
loc_82079BBC:
	// stb r29,4(r31)
	REX_STORE_U8(ctx.r31.u32 + 4, ctx.r29.u8);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,12
	ctx.r31.s64 = ctx.r31.s64 + 12;
	// bne 0x82079b64
	if (!ctx.cr0.eq) goto loc_82079B64;
	// stw r29,5024(r28)
	REX_STORE_U32(ctx.r28.u32 + 5024, ctx.r29.u32);
	// stw r29,20100(r28)
	REX_STORE_U32(ctx.r28.u32 + 20100, ctx.r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
