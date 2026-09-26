DEFINE_REX_FUNC(sub_8209E928) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8209E930;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r27,256
	ctx.r27.s64 = 256;
	// addi r31,r29,2304
	ctx.r31.s64 = ctx.r29.s64 + 2304;
	// li r28,0
	ctx.r28.s64 = 0;
loc_8209E944:
	// lwz r30,0(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8209e98c
	if (ctx.cr6.eq) goto loc_8209E98C;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d8210
	ctx.lr = 0x8209E95C;
	sub_820D8210(ctx, base);
	// lbz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8209e98c
	if (!ctx.cr6.eq) goto loc_8209E98C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d8088
	ctx.lr = 0x8209E974;
	sub_820D8088(ctx, base);
	// lwz r11,5376(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 5376);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8209e984
	if (!ctx.cr6.eq) goto loc_8209E984;
	// stw r28,5376(r29)
	REX_STORE_U32(ctx.r29.u32 + 5376, ctx.r28.u32);
loc_8209E984:
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// stw r28,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
loc_8209E98C:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r31,r31,12
	ctx.r31.s64 = ctx.r31.s64 + 12;
	// bne 0x8209e944
	if (!ctx.cr0.eq) goto loc_8209E944;
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// bl 0x820fbea8
	ctx.lr = 0x8209E9A0;
	sub_820FBEA8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8209e9bc
	if (ctx.cr6.eq) goto loc_8209E9BC;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,1292
	ctx.r3.s64 = ctx.r11.s64 + 1292;
	// bl 0x8208c5d8
	ctx.lr = 0x8209E9B4;
	sub_8208C5D8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8209E9BC:
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// lwz r11,5376(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 5376);
	// bne cr6,0x8209e9f4
	if (!ctx.cr6.eq) goto loc_8209E9F4;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stb r10,5380(r29)
	REX_STORE_U8(ctx.r29.u32 + 5380, ctx.r10.u8);
	// beq cr6,0x8209ea0c
	if (ctx.cr6.eq) goto loc_8209EA0C;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f1,9536(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9536);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x820d8430
	ctx.lr = 0x8209E9EC;
	sub_820D8430(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8209E9F4:
	// stb r28,5380(r29)
	REX_STORE_U8(ctx.r29.u32 + 5380, ctx.r28.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209ea0c
	if (ctx.cr6.eq) goto loc_8209EA0C;
	// lfs f1,5384(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 5384);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x820d8430
	ctx.lr = 0x8209EA0C;
	sub_820D8430(ctx, base);
loc_8209EA0C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
