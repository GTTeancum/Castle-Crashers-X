DEFINE_REX_FUNC(sub_820A67D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x820A67D8;
	__savegprlr_23(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// blt cr6,0x820a6978
	if (ctx.cr6.lt) goto loc_820A6978;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// addi r3,r11,6868
	ctx.r3.s64 = ctx.r11.s64 + 6868;
	// bl 0x8208c5d8
	ctx.lr = 0x820A67FC;
	sub_8208C5D8(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820A6814;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820a6968
	if (ctx.cr6.eq) goto loc_820A6968;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r24,r8,7060
	ctx.r24.s64 = ctx.r8.s64 + 7060;
	// addi r23,r7,7032
	ctx.r23.s64 = ctx.r7.s64 + 7032;
	// addi r27,r9,6988
	ctx.r27.s64 = ctx.r9.s64 + 6988;
	// addi r26,r10,6944
	ctx.r26.s64 = ctx.r10.s64 + 6944;
	// addi r25,r11,6924
	ctx.r25.s64 = ctx.r11.s64 + 6924;
loc_820A6844:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A685C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x820A686C;
	sub_8208C5D8(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r5,68(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r4,60(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// bl 0x8208c5d8
	ctx.lr = 0x820A687C;
	sub_8208C5D8(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r5,72(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// lwz r4,64(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// bl 0x8208c5d8
	ctx.lr = 0x820A688C;
	sub_8208C5D8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r8,28(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820A68A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lbz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// rlwinm r7,r11,0,30,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x820a6948
	if (ctx.cr6.eq) goto loc_820A6948;
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a6948
	if (ctx.cr6.eq) goto loc_820A6948;
	// rlwinm r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a6948
	if (!ctx.cr6.eq) goto loc_820A6948;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// lhz r5,14(r10)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r10.u32 + 14);
	// lhz r4,12(r10)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r10.u32 + 12);
	// bl 0x8208c5d8
	ctx.lr = 0x820A68E0;
	sub_8208C5D8(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r5,20(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r4,16(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// bl 0x8208c5d8
	ctx.lr = 0x820A68F0;
	sub_8208C5D8(ctx, base);
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82051e68
	ctx.lr = 0x820A6900;
	sub_82051E68(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a6948
	if (ctx.cr6.eq) goto loc_820A6948;
	// lwz r10,280(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 280);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// li r9,7
	ctx.r9.s64 = 7;
	// mulli r10,r10,56
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(56));
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + ctx.r28.u64;
	// addi r10,r10,288
	ctx.r10.s64 = ctx.r10.s64 + 288;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820A6928:
	// ld r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// std r9,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x820a6928
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820A6928;
	// lwz r11,280(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 280);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,280(r28)
	REX_STORE_U32(ctx.r28.u32 + 280, ctx.r11.u32);
loc_820A6948:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A6960;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r29,r3
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x820a6844
	if (ctx.cr6.lt) goto loc_820A6844;
loc_820A6968:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,272(r28)
	REX_STORE_U8(ctx.r28.u32 + 272, ctx.r11.u8);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
loc_820A6978:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,7088
	ctx.r3.s64 = ctx.r11.s64 + 7088;
	// bl 0x8208c5d8
	ctx.lr = 0x820A6984;
	sub_8208C5D8(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
