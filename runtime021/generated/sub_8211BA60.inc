DEFINE_REX_FUNC(sub_8211BA60) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8211BA68;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82136f58
	ctx.lr = 0x8211BA78;
	sub_82136F58(ctx, base);
	// lhz r11,336(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 336);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// rlwinm. r11,r11,0,17,17
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8211ba94
	if (!ctx.cr0.eq) goto loc_8211BA94;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821180d8
	ctx.lr = 0x8211BA90;
	sub_821180D8(ctx, base);
	// b 0x8211bb40
	goto loc_8211BB40;
loc_8211BA94:
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// lbz r11,2(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// rlwinm r29,r11,27,30,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x3;
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// bne cr6,0x8211bab0
	if (!ctx.cr6.eq) goto loc_8211BAB0;
	// lhz r9,1054(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 1054);
	// b 0x8211bac4
	goto loc_8211BAC4;
loc_8211BAB0:
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// bne cr6,0x8211bac0
	if (!ctx.cr6.eq) goto loc_8211BAC0;
	// lhz r9,1052(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 1052);
	// b 0x8211bac4
	goto loc_8211BAC4;
loc_8211BAC0:
	// li r9,0
	ctx.r9.s64 = 0;
loc_8211BAC4:
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// addi r3,r31,664
	ctx.r3.s64 = ctx.r31.s64 + 664;
	// lwz r10,64(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 64);
	// lwz r4,56(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 56);
	// subf r6,r10,r28
	ctx.r6.u64 = ctx.r28.u64 - ctx.r10.u64;
	// lwz r8,112(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// lwz r7,108(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// lwz r5,80(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r11,48(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// rlwinm r10,r11,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// bl 0x82125558
	ctx.lr = 0x8211BAF4;
	sub_82125558(ctx, base);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// add r10,r3,r28
	ctx.r10.u64 = ctx.r3.u64 + ctx.r28.u64;
	// bne cr6,0x8211bb30
	if (!ctx.cr6.eq) goto loc_8211BB30;
	// addis r10,r10,-32768
	ctx.r10.s64 = ctx.r10.s64 + -2147483648;
	// addi r11,r31,992
	ctx.r11.s64 = ctx.r31.s64 + 992;
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// stw r10,60(r30)
	REX_STORE_U32(ctx.r30.u32 + 60, ctx.r10.u32);
	// addi r10,r30,16
	ctx.r10.s64 = ctx.r30.s64 + 16;
	// stw r11,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// lwz r11,996(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 996);
	// stw r11,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// lwz r11,996(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 996);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r10,996(r31)
	REX_STORE_U32(ctx.r31.u32 + 996, ctx.r10.u32);
	// b 0x8211bb40
	goto loc_8211BB40;
loc_8211BB30:
	// stw r10,60(r30)
	REX_STORE_U32(ctx.r30.u32 + 60, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211a288
	ctx.lr = 0x8211BB40;
	sub_8211A288(ctx, base);
loc_8211BB40:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211aed8
	ctx.lr = 0x8211BB4C;
	sub_8211AED8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
