DEFINE_REX_FUNC(sub_82095DA8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82095DB0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// stw r28,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r28.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r29,-6656(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + -6656);
	// beq cr6,0x82095e4c
	if (ctx.cr6.eq) goto loc_82095E4C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82096530
	ctx.lr = 0x82095DD8;
	sub_82096530(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82095ee8
	if (ctx.cr6.eq) goto loc_82095EE8;
	// addi r30,r29,14516
	ctx.r30.s64 = ctx.r29.s64 + 14516;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a434
	ctx.lr = 0x82095DF0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bne cr6,0x82095f08
	if (!ctx.cr6.eq) goto loc_82095F08;
	// bl 0x8214a444
	ctx.lr = 0x82095E10;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820960a8
	ctx.lr = 0x82095E1C;
	sub_820960A8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82095f0c
	if (!ctx.cr6.eq) goto loc_82095F0C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a434
	ctx.lr = 0x82095E30;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820967b0
	ctx.lr = 0x82095E38;
	sub_820967B0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a444
	ctx.lr = 0x82095E40;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82095E4C:
	// lwz r10,140(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 140);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82095e9c
	if (ctx.cr6.eq) goto loc_82095E9C;
	// lhz r8,156(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 156);
	// lhz r9,158(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 158);
loc_82095E60:
	// lhz r11,44(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 44);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x82095e80
	if (!ctx.cr6.eq) goto loc_82095E80;
	// lhz r11,46(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 46);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82095e84
	if (ctx.cr6.eq) goto loc_82095E84;
loc_82095E80:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82095E84:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82095ef4
	if (!ctx.cr6.eq) goto loc_82095EF4;
	// lwz r10,52(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 52);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82095e60
	if (!ctx.cr6.eq) goto loc_82095E60;
loc_82095E9C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82095EA0:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// beq cr6,0x82095ee4
	if (ctx.cr6.eq) goto loc_82095EE4;
	// bl 0x82096530
	ctx.lr = 0x82095EB8;
	sub_82096530(ctx, base);
	// addi r30,r29,14516
	ctx.r30.s64 = ctx.r29.s64 + 14516;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a434
	ctx.lr = 0x82095EC8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82095efc
	if (!ctx.cr6.eq) goto loc_82095EFC;
	// bl 0x8214a444
	ctx.lr = 0x82095EDC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_82095EE4:
	// bl 0x82096250
	ctx.lr = 0x82095EE8;
	sub_82096250(ctx, base);
loc_82095EE8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82095EF4:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82095ea0
	goto loc_82095EA0;
loc_82095EFC:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_82095F08:
	// bl 0x8214a444
	ctx.lr = 0x82095F0C;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_82095F0C:
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
