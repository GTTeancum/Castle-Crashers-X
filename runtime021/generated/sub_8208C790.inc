DEFINE_REX_FUNC(sub_8208C790) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8208C798;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lbz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 92);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208c7c0
	if (!ctx.cr6.eq) goto loc_8208C7C0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-5784
	ctx.r3.s64 = ctx.r11.s64 + -5784;
	// bl 0x8208c5d8
	ctx.lr = 0x8208C7B8;
	sub_8208C5D8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8208C7C0:
	// subfic r11,r4,1
	ctx.xer.ca = ctx.r4.u32 <= 1;
	ctx.r11.u64 = static_cast<uint64_t>(1) - ctx.r4.u64;
	// lis r28,-32218
	ctx.r28.s64 = -2111438848;
	// subfe r10,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi r27,r10,31
	ctx.r27.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8208c820
	if (ctx.cr6.eq) goto loc_8208C820;
	// lbz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 136);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208c820
	if (ctx.cr6.eq) goto loc_8208C820;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8208c818
	if (!ctx.cr6.gt) goto loc_8208C818;
	// addi r30,r31,104
	ctx.r30.s64 = ctx.r31.s64 + 104;
loc_8208C7F4:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,-6612(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + -6612);
	// lhz r5,0(r30)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r30.u32 + 0);
	// bl 0x82096e50
	ctx.lr = 0x8208C804;
	sub_82096E50(ctx, base);
	// lbz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 136);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,2
	ctx.r30.s64 = ctx.r30.s64 + 2;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8208c7f4
	if (ctx.cr6.lt) goto loc_8208C7F4;
loc_8208C818:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,136(r31)
	REX_STORE_U8(ctx.r31.u32 + 136, ctx.r11.u8);
loc_8208C820:
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// lwz r3,-6612(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + -6612);
	// lfs f2,100(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 100);
	ctx.f2.f64 = double(temp.f32);
	// lhz r4,94(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 94);
	// lfs f1,96(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82096c80
	ctx.lr = 0x8208C838;
	sub_82096C80(ctx, base);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8208c85c
	if (ctx.cr6.eq) goto loc_8208C85C;
	// lbz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 136);
	// addi r11,r11,52
	ctx.r11.s64 = ctx.r11.s64 + 52;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r3,r10,r31
	REX_STORE_U16(ctx.r10.u32 + ctx.r31.u32, ctx.r3.u16);
	// lbz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 136);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stb r9,136(r31)
	REX_STORE_U8(ctx.r31.u32 + 136, ctx.r9.u8);
loc_8208C85C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
