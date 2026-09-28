DEFINE_REX_FUNC(sub_8211FC20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x8211FC28;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r27,1
	ctx.r27.s64 = 1;
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// bl 0x82136f58
	ctx.lr = 0x8211FC44;
	sub_82136F58(ctx, base);
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// add r26,r3,r31
	ctx.r26.u64 = ctx.r3.u64 + ctx.r31.u64;
	// addi r30,r11,30236
	ctx.r30.s64 = ctx.r11.s64 + 30236;
	// addi r3,r30,8
	ctx.r3.s64 = ctx.r30.s64 + 8;
	// bl 0x8214a434
	ctx.lr = 0x8211FC58;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8211fcc0
	if (ctx.cr6.eq) goto loc_8211FCC0;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8211fcc0
	if (ctx.cr0.eq) goto loc_8211FCC0;
loc_8211FC70:
	// lwz r11,-32(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -32);
	// addi r3,r29,-32
	ctx.r3.s64 = ctx.r29.s64 + -32;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8211FC8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r27,1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 1, ctx.xer);
	// bne cr6,0x8211fcc0
	if (!ctx.cr6.eq) goto loc_8211FCC0;
	// lwz r29,0(r29)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8211fca8
	if (!ctx.cr6.eq) goto loc_8211FCA8;
	// li r29,0
	ctx.r29.s64 = 0;
loc_8211FCA8:
	// bl 0x82136f58
	ctx.lr = 0x8211FCAC;
	sub_82136F58(ctx, base);
	// subf. r31,r3,r26
	ctx.r31.u64 = ctx.r26.u64 - ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge 0x8211fcb8
	if (!ctx.cr0.lt) goto loc_8211FCB8;
	// li r31,0
	ctx.r31.s64 = 0;
loc_8211FCB8:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8211fc70
	if (!ctx.cr6.eq) goto loc_8211FC70;
loc_8211FCC0:
	// addi r3,r30,8
	ctx.r3.s64 = ctx.r30.s64 + 8;
	// bl 0x8214a444
	ctx.lr = 0x8211FCC8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
