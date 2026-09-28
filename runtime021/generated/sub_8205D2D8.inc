DEFINE_REX_FUNC(sub_8205D2D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8205D2E0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,4
	ctx.r5.s64 = 4;
	// lhz r4,10(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// bl 0x82053c70
	ctx.lr = 0x8205D30C;
	sub_82053C70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8205d3d4
	if (ctx.cr6.eq) goto loc_8205D3D4;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// lhz r9,10(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// lwz r3,-6624(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6624);
	// lhz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// extsh r31,r9
	ctx.r31.s64 = ctx.r9.s16;
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// rlwinm r7,r31,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,1756(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 1756);
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r7,r6
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// lwzx r29,r5,r10
	ctx.r29.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8205d37c
	if (ctx.cr6.eq) goto loc_8205D37C;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x82078d90
	ctx.lr = 0x8205D358;
	sub_82078D90(ctx, base);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8205d370
	if (ctx.cr6.eq) goto loc_8205D370;
	// lbz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 16);
	// lwz r3,-6624(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6624);
	// b 0x8205d380
	goto loc_8205D380;
loc_8205D370:
	// lwz r3,-6624(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6624);
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8205d380
	goto loc_8205D380;
loc_8205D37C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8205D380:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8205d3a8
	if (ctx.cr6.eq) goto loc_8205D3A8;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// sth r11,102(r29)
	REX_STORE_U16(ctx.r29.u32 + 102, ctx.r11.u16);
	// bl 0x82058478
	ctx.lr = 0x8205D3A0;
	sub_82058478(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8205D3A8:
	// li r11,1
	ctx.r11.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// sth r11,102(r29)
	REX_STORE_U16(ctx.r29.u32 + 102, ctx.r11.u16);
	// bl 0x82058478
	ctx.lr = 0x8205D3B8;
	sub_82058478(ctx, base);
	// lwz r11,-6624(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6624);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,1756(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 1756);
	// lfs f1,18268(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 18268);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82078fe8
	ctx.lr = 0x8205D3D4;
	sub_82078FE8(ctx, base);
loc_8205D3D4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
