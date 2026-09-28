DEFINE_REX_FUNC(sub_820D7F38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820D7F40;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lwz r31,268(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 268);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lwz r30,260(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 260);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// lwz r29,252(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 252);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// lwz r28,244(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 244);
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// stw r31,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r31.u32);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// stw r30,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r30.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stw r29,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r28,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r28.u32);
	// bl 0x8214aa44
	ctx.lr = 0x820D7F90;
	__imp__NetDll_XNetQosLookup(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
