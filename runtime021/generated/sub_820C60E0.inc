DEFINE_REX_FUNC(sub_820C60E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x820C60E8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// bne cr6,0x820c614c
	if (!ctx.cr6.eq) goto loc_820C614C;
	// lwz r11,10900(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10900);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820c6114
	if (ctx.cr6.eq) goto loc_820C6114;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820C6114;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820C6114:
	// addi r30,r31,10904
	ctx.r30.s64 = ctx.r31.s64 + 10904;
	// lbz r11,268(r13)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r13.u32 + 268);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r31,10900(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 10900);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// slw r29,r10,r11
	ctx.r29.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// bl 0x8214a7a4
	ctx.lr = 0x820C6130;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// andc r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 & ~ctx.r29.u64;
	// clrlwi r11,r11,26
	ctx.r11.u64 = ctx.r11.u32 & 0x3F;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x8214a794
	ctx.lr = 0x820C6148;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// b 0x820c616c
	goto loc_820C616C;
loc_820C614C:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820c616c
	if (!ctx.cr6.eq) goto loc_820C616C;
	// lis r11,32712
	ctx.r11.s64 = 2143813632;
	// lwz r11,25924(r11)
	ctx.r11.u64 = REX_MM_LOAD_U32(ctx.r11.u32 + 25924);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820c616c
	if (ctx.cr0.eq) goto loc_820C616C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c05f0
	ctx.lr = 0x820C616C;
	sub_820C05F0(ctx, base);
loc_820C616C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
