DEFINE_REX_FUNC(sub_82104D68) {
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
	// lwz r11,84(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 84);
	// b 0x82104d84
	goto loc_82104D84;
loc_82104D7C:
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
loc_82104D84:
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82104d7c
	if (!ctx.cr0.eq) goto loc_82104D7C;
loc_82104D8C:
	// lwz r11,396(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 396);
	// oris r11,r11,1024
	ctx.r11.u64 = ctx.r11.u64 | 67108864;
	// stw r11,396(r4)
	REX_STORE_U32(ctx.r4.u32 + 396, ctx.r11.u32);
	// lwz r4,88(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + 88);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82104d8c
	if (!ctx.cr6.eq) goto loc_82104D8C;
	// lwz r11,188(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 188);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,188(r3)
	REX_STORE_U32(ctx.r3.u32 + 188, ctx.r11.u32);
	// bne 0x82104dc0
	if (!ctx.cr0.eq) goto loc_82104DC0;
	// bl 0x82104c20
	ctx.lr = 0x82104DB8;
	sub_82104C20(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82104dc4
	if (ctx.cr0.lt) goto loc_82104DC4;
loc_82104DC0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82104DC4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
