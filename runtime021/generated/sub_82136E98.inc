DEFINE_REX_FUNC(sub_82136E98) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82136EA0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82136ec4
	if (ctx.cr6.eq) goto loc_82136EC4;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_82136EC4:
	// cmplwi cr6,r3,65001
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 65001, ctx.xer);
	// bne cr6,0x82136ee0
	if (!ctx.cr6.eq) goto loc_82136EE0;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82138350
	ctx.lr = 0x82136EDC;
	sub_82138350(ctx, base);
	// b 0x82136f50
	goto loc_82136F50;
loc_82136EE0:
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// bne cr6,0x82136ef8
	if (!ctx.cr6.eq) goto loc_82136EF8;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82127e20
	ctx.lr = 0x82136EF0;
	sub_82127E20(ctx, base);
	// addi r31,r3,1
	ctx.r31.s64 = ctx.r3.s64 + 1;
	// b 0x82136efc
	goto loc_82136EFC;
loc_82136EF8:
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
loc_82136EFC:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x82136f0c
	if (!ctx.cr6.eq) goto loc_82136F0C;
loc_82136F04:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x82136f50
	goto loc_82136F50;
loc_82136F0C:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x82136f44
	if (ctx.cr6.lt) goto loc_82136F44;
	// cmpw cr6,r30,r31
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r31.s32, ctx.xer);
	// blt cr6,0x82136f44
	if (ctx.cr6.lt) goto loc_82136F44;
	// rlwinm r7,r31,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a604
	ctx.lr = 0x82136F34;
	__imp__RtlUnicodeToMultiByteN(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82136f04
	if (!ctx.cr0.lt) goto loc_82136F04;
	// bl 0x8214a5c4
	ctx.lr = 0x82136F40;
	__imp__RtlNtStatusToDosError(ctx, base);
	// b 0x82136f48
	goto loc_82136F48;
loc_82136F44:
	// li r3,122
	ctx.r3.s64 = 122;
loc_82136F48:
	// bl 0x820b73c8
	ctx.lr = 0x82136F4C;
	sub_820B73C8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82136F50:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
