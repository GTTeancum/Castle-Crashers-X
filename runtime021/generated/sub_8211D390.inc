DEFINE_REX_FUNC(sub_8211D390) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8211D398;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r8,r31,984
	ctx.r8.s64 = ctx.r31.s64 + 984;
	// lwz r11,984(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 984);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8211d3bc
	if (!ctx.cr6.eq) goto loc_8211D3BC;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x8211d5a0
	goto loc_8211D5A0;
loc_8211D3BC:
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8211d3d0
	if (!ctx.cr6.eq) goto loc_8211D3D0;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8211D3D0:
	// addi r30,r11,-16
	ctx.r30.s64 = ctx.r11.s64 + -16;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lis r9,-32768
	ctx.r9.s64 = -2147483648;
	// subf r10,r11,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r11.u64;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8211d3fc
	if (ctx.cr6.lt) goto loc_8211D3FC;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// addi r3,r31,176
	ctx.r3.s64 = ctx.r31.s64 + 176;
	// bl 0x82119f88
	ctx.lr = 0x8211D3F8;
	sub_82119F88(ctx, base);
	// b 0x8211d470
	goto loc_8211D470;
loc_8211D3FC:
	// lwz r10,1164(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1164);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r10,1164(r31)
	REX_STORE_U32(ctx.r31.u32 + 1164, ctx.r10.u32);
	// lwz r10,56(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 56);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lwz r9,64(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 64);
	// beq cr6,0x8211d478
	if (ctx.cr6.eq) goto loc_8211D478;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// subf r10,r9,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r9.u64;
	// blt cr6,0x8211d434
	if (ctx.cr6.lt) goto loc_8211D434;
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// b 0x8211d438
	goto loc_8211D438;
loc_8211D434:
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
loc_8211D438:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8211d478
	if (ctx.cr6.lt) goto loc_8211D478;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x8211d470
	if (ctx.cr6.eq) goto loc_8211D470;
	// lis r11,-32646
	ctx.r11.s64 = -2139488256;
	// stb r29,1145(r31)
	REX_STORE_U8(ctx.r31.u32 + 1145, ctx.r29.u8);
	// li r10,3
	ctx.r10.s64 = 3;
	// stb r29,1144(r31)
	REX_STORE_U8(ctx.r31.u32 + 1144, ctx.r29.u8);
	// ori r11,r11,4103
	ctx.r11.u64 = ctx.r11.u64 | 4103;
	// stw r10,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// bl 0x8211a3b8
	ctx.lr = 0x8211D470;
	sub_8211A3B8(ctx, base);
loc_8211D470:
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// b 0x8211d5a0
	goto loc_8211D5A0;
loc_8211D478:
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8211d4a4
	if (ctx.cr6.eq) goto loc_8211D4A4;
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
loc_8211D4A4:
	// addi r3,r31,664
	ctx.r3.s64 = ctx.r31.s64 + 664;
	// bl 0x82125390
	ctx.lr = 0x8211D4AC;
	sub_82125390(ctx, base);
	// lhz r11,336(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 336);
	// rlwinm. r11,r11,0,0,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF8000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8211d510
	if (!ctx.cr0.eq) goto loc_8211D510;
	// lis r4,-32646
	ctx.r4.s64 = -2139488256;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// ori r4,r4,4108
	ctx.r4.u64 = ctx.r4.u64 | 4108;
	// bl 0x82121b08
	ctx.lr = 0x8211D4C8;
	sub_82121B08(ctx, base);
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r9,12(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// addi r11,r30,8
	ctx.r11.s64 = ctx.r30.s64 + 8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r9,12(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// stw r11,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// bl 0x821180d8
	ctx.lr = 0x8211D4F4;
	sub_821180D8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821180d8
	ctx.lr = 0x8211D4FC;
	sub_821180D8(ctx, base);
	// lhz r11,1042(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1042);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,1042(r31)
	REX_STORE_U16(ctx.r31.u32 + 1042, ctx.r11.u16);
	// b 0x8211d5a0
	goto loc_8211D5A0;
loc_8211D510:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211a158
	ctx.lr = 0x8211D518;
	sub_8211A158(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8211a1e0
	ctx.lr = 0x8211D528;
	sub_8211A1E0(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r6,r31,872
	ctx.r6.s64 = ctx.r31.s64 + 872;
	// lhz r5,1032(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 1032);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821217d0
	ctx.lr = 0x8211D540;
	sub_821217D0(ctx, base);
	// lhz r11,1040(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1040);
	// clrlwi r10,r28,16
	ctx.r10.u64 = ctx.r28.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8211d55c
	if (ctx.cr6.lt) goto loc_8211D55C;
	// lwz r11,1148(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1148);
	// oris r11,r11,512
	ctx.r11.u64 = ctx.r11.u64 | 33554432;
	// stw r11,1148(r31)
	REX_STORE_U32(ctx.r31.u32 + 1148, ctx.r11.u32);
loc_8211D55C:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8211d578
	if (ctx.cr6.eq) goto loc_8211D578;
	// lbz r11,1144(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1144);
	// addi r3,r31,296
	ctx.r3.s64 = ctx.r31.s64 + 296;
	// andi. r11,r11,239
	ctx.r11.u64 = ctx.r11.u64 & 239;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r11,1144(r31)
	REX_STORE_U8(ctx.r31.u32 + 1144, ctx.r11.u8);
	// bl 0x82122310
	ctx.lr = 0x8211D578;
	sub_82122310(ctx, base);
loc_8211D578:
	// lwz r11,1156(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1156);
	// ld r10,1176(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 1176);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,1156(r31)
	REX_STORE_U32(ctx.r31.u32 + 1156, ctx.r11.u32);
	// lwz r11,32(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// lwz r9,24(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// std r11,1176(r31)
	REX_STORE_U64(ctx.r31.u32 + 1176, ctx.r11.u64);
loc_8211D5A0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
