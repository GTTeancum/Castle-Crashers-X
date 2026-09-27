DEFINE_REX_FUNC(sub_8209BC08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8209BC10;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r31,r11,-8
	ctx.r31.s64 = ctx.r11.s64 + -8;
	// li r5,255
	ctx.r5.s64 = 255;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,260(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 260);
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r30,256(r11)
	REX_STORE_U32(ctx.r11.u32 + 256, ctx.r30.u32);
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// stw r10,260(r11)
	REX_STORE_U32(ctx.r11.u32 + 260, ctx.r10.u32);
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r9,260(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 260);
	// stw r11,256(r9)
	REX_STORE_U32(ctx.r9.u32 + 256, ctx.r11.u32);
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r8,260(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 260);
	// stw r30,260(r8)
	REX_STORE_U32(ctx.r8.u32 + 260, ctx.r30.u32);
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r3,260(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 260);
	// stw r3,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// bl 0x82128830
	ctx.lr = 0x8209BC6C;
	sub_82128830(ctx, base);
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// stb r30,255(r11)
	REX_STORE_U8(ctx.r11.u32 + 255, ctx.r30.u8);
	// lbz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8209bc88
	if (ctx.cr6.eq) goto loc_8209BC88;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820b6cd0
	ctx.lr = 0x8209BC88;
	sub_820B6CD0(ctx, base);
loc_8209BC88:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
