DEFINE_REX_FUNC(sub_820878E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x820878E8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// lwz r29,28(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// blt cr6,0x82087994
	if (ctx.cr6.lt) goto loc_82087994;
	// cmpw cr6,r31,r29
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x82087994
	if (ctx.cr6.eq) goto loc_82087994;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,156(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82087918;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82087988
	if (ctx.cr6.eq) goto loc_82087988;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82087930;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208795c
	if (ctx.cr6.eq) goto loc_8208795C;
loc_8208793C:
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// cmpw cr6,r10,r31
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r31.s32, ctx.xer);
	// beq cr6,0x82087958
	if (ctx.cr6.eq) goto loc_82087958;
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208793c
	if (!ctx.cr6.eq) goto loc_8208793C;
	// b 0x8208795c
	goto loc_8208795C;
loc_82087958:
	// stw r29,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r29.u32);
loc_8208795C:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,28(r30)
	REX_STORE_U32(ctx.r30.u32 + 28, ctx.r31.u32);
	// lwz r10,156(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82087974;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r9,140(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 140);
	// ori r8,r9,32
	ctx.r8.u64 = ctx.r9.u64 | 32;
	// stb r8,140(r3)
	REX_STORE_U8(ctx.r3.u32 + 140, ctx.r8.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_82087988:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-6656
	ctx.r3.s64 = ctx.r11.s64 + -6656;
	// bl 0x8208c5d8
	ctx.lr = 0x82087994;
	sub_8208C5D8(ctx, base);
loc_82087994:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
