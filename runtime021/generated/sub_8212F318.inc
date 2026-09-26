DEFINE_REX_FUNC(sub_8212F318) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8212F320;
	__savegprlr_28(ctx, base);
	// addi r31,r1,-128
	ctx.r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// bl 0x820bb280
	ctx.lr = 0x8212F338;
	sub_820BB280(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8212f354
	if (!ctx.cr0.eq) goto loc_8212F354;
	// bl 0x8212c3b0
	ctx.lr = 0x8212F344;
	sub_8212C3B0(ctx, base);
	// li r3,30
	ctx.r3.s64 = 30;
	// bl 0x8212c368
	ctx.lr = 0x8212F34C;
	sub_8212C368(ctx, base);
	// li r3,255
	ctx.r3.s64 = 255;
	// bl 0x8212a040
	ctx.lr = 0x8212F354;
	sub_8212A040(ctx, base);
loc_8212F354:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// rlwinm r29,r30,3,0,28
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r30,r11,32712
	ctx.r30.s64 = ctx.r11.s64 + 32712;
	// lwzx r11,r29,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8212f374
	if (ctx.cr6.eq) goto loc_8212F374;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8212f404
	goto loc_8212F404;
loc_8212F374:
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82128f70
	ctx.lr = 0x8212F37C;
	sub_82128F70(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne 0x8212f39c
	if (!ctx.cr0.eq) goto loc_8212F39C;
	// bl 0x821294e0
	ctx.lr = 0x8212F388;
	sub_821294E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,12
	ctx.r10.s64 = 12;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x8212f404
	goto loc_8212F404;
loc_8212F39C:
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x8212f458
	ctx.lr = 0x8212F3A4;
	sub_8212F458(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r29,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bne cr6,0x8212f3f0
	if (!ctx.cr6.eq) goto loc_8212F3F0;
	// li r4,4000
	ctx.r4.s64 = 4000;
	// bl 0x82130438
	ctx.lr = 0x8212F3C0;
	sub_82130438(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8212f3e8
	if (!ctx.cr0.eq) goto loc_8212F3E8;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82129880
	ctx.lr = 0x8212F3D0;
	sub_82129880(ctx, base);
	// bl 0x821294e0
	ctx.lr = 0x8212F3D4;
	sub_821294E0(ctx, base);
	// li r11,12
	ctx.r11.s64 = 12;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// b 0x8212f3f4
	goto loc_8212F3F4;
loc_8212F3E8:
	// stwx r28,r29,r30
	REX_STORE_U32(ctx.r29.u32 + ctx.r30.u32, ctx.r28.u32);
	// b 0x8212f3f4
	goto loc_8212F3F4;
loc_8212F3F0:
	// bl 0x82129880
	ctx.lr = 0x8212F3F4;
	sub_82129880(ctx, base);
loc_8212F3F4:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	ctx.r12.s64 = ctx.r31.s64 + 128;
	// bl 0x8212f428
	ctx.lr = 0x8212F400;
	sub_8212F428(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
loc_8212F404:
	// addi r1,r31,128
	ctx.r1.s64 = ctx.r31.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
