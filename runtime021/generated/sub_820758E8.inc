DEFINE_REX_FUNC(sub_820758E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820758F0;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82099fa0
	ctx.lr = 0x820758FC;
	sub_82099FA0(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r29,-6656(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + -6656);
	// addi r27,r29,14628
	ctx.r27.s64 = ctx.r29.s64 + 14628;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8214a434
	ctx.lr = 0x82075910;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r31,140(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 140);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82075994
	if (ctx.cr6.eq) goto loc_82075994;
	// li r28,0
	ctx.r28.s64 = 0;
loc_82075920:
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lhz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82075988
	if (ctx.cr6.eq) goto loc_82075988;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82075948;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82075988
	if (ctx.cr6.eq) goto loc_82075988;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r30,52(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82075970
	if (!ctx.cr6.gt) goto loc_82075970;
	// lwz r4,24(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r3,136(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 136);
	// bl 0x8209bf18
	ctx.lr = 0x82075970;
	sub_8209BF18(ctx, base);
loc_82075970:
	// stw r28,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r28.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820966a0
	ctx.lr = 0x82075980;
	sub_820966A0(ctx, base);
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// b 0x8207598c
	goto loc_8207598C;
loc_82075988:
	// lwz r31,52(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
loc_8207598C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82075920
	if (!ctx.cr6.eq) goto loc_82075920;
loc_82075994:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8214a444
	ctx.lr = 0x8207599C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
