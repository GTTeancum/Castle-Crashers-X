DEFINE_REX_FUNC(sub_820CBFF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r7,r11,23712
	ctx.r7.s64 = ctx.r11.s64 + 23712;
	// addi r6,r10,22560
	ctx.r6.s64 = ctx.r10.s64 + 22560;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-18176
	ctx.r4.s64 = ctx.r9.s64 + -18176;
	// lis r3,7645
	ctx.r3.s64 = 501022720;
	// bl 0x8214a8a4
	ctx.lr = 0x820CC028;
	__imp__VdInitializeEngines(ctx, base);
	// bl 0x8214a6e4
	ctx.lr = 0x820CC02C;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x820cc054
	if (ctx.cr6.eq) goto loc_820CC054;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,2272
	ctx.r3.s64 = ctx.r11.s64 + 2272;
	// bl 0x8214a844
	ctx.lr = 0x820CC044;
	__imp__ExRegisterTitleTerminateNotification(ctx, base);
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,2288
	ctx.r3.s64 = ctx.r11.s64 + 2288;
	// bl 0x8214a844
	ctx.lr = 0x820CC054;
	__imp__ExRegisterTitleTerminateNotification(ctx, base);
loc_820CC054:
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r11,16712(r31)
	REX_STORE_U32(ctx.r31.u32 + 16712, ctx.r11.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r10,24800
	ctx.r3.s64 = ctx.r10.s64 + 24800;
	// bl 0x8214a894
	ctx.lr = 0x820CC06C;
	__imp__VdSetGraphicsInterruptCallback(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
