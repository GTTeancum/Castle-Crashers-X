DEFINE_REX_FUNC(sub_8211F0C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8211F0C8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r28,r31,40
	ctx.r28.s64 = ctx.r31.s64 + 40;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a434
	ctx.lr = 0x8211F0DC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stb r29,1145(r31)
	REX_STORE_U8(ctx.r31.u32 + 1145, ctx.r29.u8);
	// stb r29,1144(r31)
	REX_STORE_U8(ctx.r31.u32 + 1144, ctx.r29.u8);
	// lwz r11,1148(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1148);
	// rlwinm. r11,r11,0,3,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8211f118
	if (ctx.cr0.eq) goto loc_8211F118;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a444
	ctx.lr = 0x8211F108;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211e870
	ctx.lr = 0x8211F110;
	sub_8211E870(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a434
	ctx.lr = 0x8211F118;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8211F118:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211a3b8
	ctx.lr = 0x8211F120;
	sub_8211A3B8(ctx, base);
	// lwz r3,416(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 416);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8211f134
	if (ctx.cr6.eq) goto loc_8211F134;
	// bl 0x821180d8
	ctx.lr = 0x8211F130;
	sub_821180D8(ctx, base);
	// stw r29,416(r31)
	REX_STORE_U32(ctx.r31.u32 + 416, ctx.r29.u32);
loc_8211F134:
	// lwz r3,420(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 420);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8211f148
	if (ctx.cr6.eq) goto loc_8211F148;
	// bl 0x821180d8
	ctx.lr = 0x8211F144;
	sub_821180D8(ctx, base);
	// stw r29,420(r31)
	REX_STORE_U32(ctx.r31.u32 + 420, ctx.r29.u32);
loc_8211F148:
	// lwz r11,984(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 984);
	// addi r30,r31,984
	ctx.r30.s64 = ctx.r31.s64 + 984;
	// b 0x8211f194
	goto loc_8211F194;
loc_8211F154:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8211f168
	if (!ctx.cr6.eq) goto loc_8211F168;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// b 0x8211f188
	goto loc_8211F188;
loc_8211F168:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
loc_8211F188:
	// addi r3,r11,-16
	ctx.r3.s64 = ctx.r11.s64 + -16;
	// bl 0x821180d8
	ctx.lr = 0x8211F190;
	sub_821180D8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_8211F194:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8211f154
	if (!ctx.cr6.eq) goto loc_8211F154;
	// lwz r11,992(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 992);
	// addi r30,r31,992
	ctx.r30.s64 = ctx.r31.s64 + 992;
	// b 0x8211f1e8
	goto loc_8211F1E8;
loc_8211F1A8:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8211f1bc
	if (!ctx.cr6.eq) goto loc_8211F1BC;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// b 0x8211f1dc
	goto loc_8211F1DC;
loc_8211F1BC:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
loc_8211F1DC:
	// addi r3,r11,-16
	ctx.r3.s64 = ctx.r11.s64 + -16;
	// bl 0x821180d8
	ctx.lr = 0x8211F1E4;
	sub_821180D8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_8211F1E8:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8211f1a8
	if (!ctx.cr6.eq) goto loc_8211F1A8;
	// lwz r11,1000(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1000);
	// addi r30,r31,1000
	ctx.r30.s64 = ctx.r31.s64 + 1000;
	// b 0x8211f23c
	goto loc_8211F23C;
loc_8211F1FC:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8211f210
	if (!ctx.cr6.eq) goto loc_8211F210;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// b 0x8211f230
	goto loc_8211F230;
loc_8211F210:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
loc_8211F230:
	// addi r3,r11,-8
	ctx.r3.s64 = ctx.r11.s64 + -8;
	// bl 0x821180d8
	ctx.lr = 0x8211F238;
	sub_821180D8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_8211F23C:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8211f1fc
	if (!ctx.cr6.eq) goto loc_8211F1FC;
	// lwz r11,1008(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1008);
	// addi r30,r31,1008
	ctx.r30.s64 = ctx.r31.s64 + 1008;
	// b 0x8211f290
	goto loc_8211F290;
loc_8211F250:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8211f264
	if (!ctx.cr6.eq) goto loc_8211F264;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// b 0x8211f284
	goto loc_8211F284;
loc_8211F264:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
loc_8211F284:
	// addi r3,r11,-8
	ctx.r3.s64 = ctx.r11.s64 + -8;
	// bl 0x821180d8
	ctx.lr = 0x8211F28C;
	sub_821180D8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_8211F290:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8211f250
	if (!ctx.cr6.eq) goto loc_8211F250;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r31,624
	ctx.r3.s64 = ctx.r31.s64 + 624;
	// bl 0x82125908
	ctx.lr = 0x8211F2A4;
	sub_82125908(ctx, base);
	// lwz r11,636(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 636);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// subf r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	// addi r3,r31,640
	ctx.r3.s64 = ctx.r31.s64 + 640;
	// stw r11,636(r31)
	REX_STORE_U32(ctx.r31.u32 + 636, ctx.r11.u32);
	// bl 0x82125908
	ctx.lr = 0x8211F2BC;
	sub_82125908(ctx, base);
	// lwz r11,512(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 512);
	// addi r30,r31,512
	ctx.r30.s64 = ctx.r31.s64 + 512;
	// b 0x8211f2e8
	goto loc_8211F2E8;
loc_8211F2C8:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8211f2d8
	if (!ctx.cr6.eq) goto loc_8211F2D8;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8211F2D8:
	// addi r4,r11,-20
	ctx.r4.s64 = ctx.r11.s64 + -20;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211c068
	ctx.lr = 0x8211F2E4;
	sub_8211C068(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_8211F2E8:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8211f2c8
	if (!ctx.cr6.eq) goto loc_8211F2C8;
	// lwz r11,520(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// addi r30,r31,520
	ctx.r30.s64 = ctx.r31.s64 + 520;
	// b 0x8211f31c
	goto loc_8211F31C;
loc_8211F2FC:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8211f30c
	if (!ctx.cr6.eq) goto loc_8211F30C;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8211F30C:
	// addi r4,r11,-20
	ctx.r4.s64 = ctx.r11.s64 + -20;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211c068
	ctx.lr = 0x8211F318;
	sub_8211C068(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_8211F31C:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8211f2fc
	if (!ctx.cr6.eq) goto loc_8211F2FC;
	// lwz r11,604(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 604);
	// addi r30,r31,604
	ctx.r30.s64 = ctx.r31.s64 + 604;
	// b 0x8211f350
	goto loc_8211F350;
loc_8211F330:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8211f340
	if (!ctx.cr6.eq) goto loc_8211F340;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8211F340:
	// addi r4,r11,-24
	ctx.r4.s64 = ctx.r11.s64 + -24;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211dab8
	ctx.lr = 0x8211F34C;
	sub_8211DAB8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_8211F350:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8211f330
	if (!ctx.cr6.eq) goto loc_8211F330;
	// lwz r11,1016(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1016);
	// addi r30,r31,1016
	ctx.r30.s64 = ctx.r31.s64 + 1016;
	// b 0x8211f3b4
	goto loc_8211F3B4;
loc_8211F364:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8211f378
	if (!ctx.cr6.eq) goto loc_8211F378;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// b 0x8211f39c
	goto loc_8211F39C;
loc_8211F378:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
loc_8211F39C:
	// lhz r11,1044(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1044);
	// addi r3,r10,-8
	ctx.r3.s64 = ctx.r10.s64 + -8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,1044(r31)
	REX_STORE_U16(ctx.r31.u32 + 1044, ctx.r11.u16);
	// bl 0x821180d8
	ctx.lr = 0x8211F3B0;
	sub_821180D8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_8211F3B4:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8211f364
	if (!ctx.cr6.eq) goto loc_8211F364;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82121220
	ctx.lr = 0x8211F3C4;
	sub_82121220(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a444
	ctx.lr = 0x8211F3CC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821180d8
	ctx.lr = 0x8211F3D4;
	sub_821180D8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
