DEFINE_REX_FUNC(sub_82075410) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82075418;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r8,r9,-7912
	ctx.r8.s64 = ctx.r9.s64 + -7912;
	// lfs f0,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// li r7,8
	ctx.r7.s64 = 8;
	// lfs f13,9868(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9868);
	ctx.f13.f64 = double(temp.f32);
	// li r29,1
	ctx.r29.s64 = 1;
	// stfs f0,12(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// addi r11,r31,136
	ctx.r11.s64 = ctx.r31.s64 + 136;
	// stfs f13,16(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 16, temp.u32);
	// stfs f0,20(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// stb r30,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r30.u8);
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// li r10,19
	ctx.r10.s64 = 19;
	// stb r30,9(r31)
	REX_STORE_U8(ctx.r31.u32 + 9, ctx.r30.u8);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// stw r7,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r7.u32);
	// stw r30,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// stw r30,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// stw r30,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// stw r30,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r30.u32);
	// stb r29,60(r31)
	REX_STORE_U8(ctx.r31.u32 + 60, ctx.r29.u8);
	// stb r30,68(r31)
	REX_STORE_U8(ctx.r31.u32 + 68, ctx.r30.u8);
	// stb r30,69(r31)
	REX_STORE_U8(ctx.r31.u32 + 69, ctx.r30.u8);
	// stb r30,71(r31)
	REX_STORE_U8(ctx.r31.u32 + 71, ctx.r30.u8);
	// stw r30,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r30.u32);
loc_82075494:
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stb r30,4(r11)
	REX_STORE_U8(ctx.r11.u32 + 4, ctx.r30.u8);
	// addi r11,r11,76
	ctx.r11.s64 = ctx.r11.s64 + 76;
	// bge 0x82075494
	if (!ctx.cr0.lt) goto loc_82075494;
	// stw r30,1656(r31)
	REX_STORE_U32(ctx.r31.u32 + 1656, ctx.r30.u32);
	// addi r28,r31,1672
	ctx.r28.s64 = ctx.r31.s64 + 1672;
	// stw r30,1660(r31)
	REX_STORE_U32(ctx.r31.u32 + 1660, ctx.r30.u32);
	// sth r30,1664(r31)
	REX_STORE_U16(ctx.r31.u32 + 1664, ctx.r30.u16);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r30,1668(r31)
	REX_STORE_U32(ctx.r31.u32 + 1668, ctx.r30.u32);
	// bl 0x82073ed0
	ctx.lr = 0x820754C4;
	sub_82073ED0(ctx, base);
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// lis r11,0
	ctx.r11.s64 = 0;
	// stw r30,1684(r31)
	REX_STORE_U32(ctx.r31.u32 + 1684, ctx.r30.u32);
	// stb r30,1688(r31)
	REX_STORE_U8(ctx.r31.u32 + 1688, ctx.r30.u8);
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// lbz r9,-22601(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + -22601);
	// sth r11,1752(r31)
	REX_STORE_U16(ctx.r31.u32 + 1752, ctx.r11.u16);
	// sth r11,1754(r31)
	REX_STORE_U16(ctx.r31.u32 + 1754, ctx.r11.u16);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r30,1760(r31)
	REX_STORE_U32(ctx.r31.u32 + 1760, ctx.r30.u32);
	// stw r30,1764(r31)
	REX_STORE_U32(ctx.r31.u32 + 1764, ctx.r30.u32);
	// stb r29,1772(r31)
	REX_STORE_U8(ctx.r31.u32 + 1772, ctx.r29.u8);
	// stw r29,1776(r31)
	REX_STORE_U32(ctx.r31.u32 + 1776, ctx.r29.u32);
	// stb r29,28(r31)
	REX_STORE_U8(ctx.r31.u32 + 28, ctx.r29.u8);
	// bne cr6,0x82075518
	if (!ctx.cr6.eq) goto loc_82075518;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r3,r11,-1768
	ctx.r3.s64 = ctx.r11.s64 + -1768;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82075518;
	sub_820A71E8(ctx, base);
loc_82075518:
	// bl 0x820b5eb8
	ctx.lr = 0x8207551C;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,29632
	ctx.r9.s64 = ctx.r11.s64 + 29632;
	// li r4,20
	ctx.r4.s64 = 20;
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82075534;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82075564
	if (ctx.cr6.eq) goto loc_82075564;
	// li r9,-1
	ctx.r9.s64 = -1;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// stw r9,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// addi r10,r11,-6632
	ctx.r10.s64 = ctx.r11.s64 + -6632;
	// stw r30,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r30,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// stw r30,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// b 0x82075570
	goto loc_82075570;
loc_82075564:
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// addi r10,r10,-6632
	ctx.r10.s64 = ctx.r10.s64 + -6632;
loc_82075570:
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// addi r10,r31,140
	ctx.r10.s64 = ctx.r31.s64 + 140;
	// stw r11,1756(r31)
	REX_STORE_U32(ctx.r31.u32 + 1756, ctx.r11.u32);
	// li r9,20
	ctx.r9.s64 = 20;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_82075584:
	// rotlwi r8,r30,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r30.u32, 0);
	// stw r30,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r30.u32);
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r30,4(r8)
	REX_STORE_U8(ctx.r8.u32 + 4, ctx.r30.u8);
	// sth r30,68(r11)
	REX_STORE_U16(ctx.r11.u32 + 68, ctx.r30.u16);
	// addi r11,r11,76
	ctx.r11.s64 = ctx.r11.s64 + 76;
	// bne 0x82075584
	if (!ctx.cr0.eq) goto loc_82075584;
	// li r7,5
	ctx.r7.s64 = 5;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r7,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,-8184
	ctx.r11.s64 = ctx.r11.s64 + -8184;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_820755C4:
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r8,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r8.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bdnz 0x820755c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820755C4;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// li r8,7
	ctx.r8.s64 = 7;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r31,216
	ctx.r11.s64 = ctx.r31.s64 + 216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// addi r10,r10,-8176
	ctx.r10.s64 = ctx.r10.s64 + -8176;
	// stb r30,4(r6)
	REX_STORE_U8(ctx.r6.u32 + 4, ctx.r30.u8);
	// stw r8,216(r31)
	REX_STORE_U32(ctx.r31.u32 + 216, ctx.r8.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_82075600:
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r8,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r8.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bdnz 0x82075600
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82075600;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r5,4
	ctx.r5.s64 = 4;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r3,r6,-8168
	ctx.r3.s64 = ctx.r6.s64 + -8168;
	// addi r11,r31,368
	ctx.r11.s64 = ctx.r31.s64 + 368;
	// addi r10,r31,292
	ctx.r10.s64 = ctx.r31.s64 + 292;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stb r30,4(r4)
	REX_STORE_U8(ctx.r4.u32 + 4, ctx.r30.u8);
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// stw r5,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r5.u32);
	// addi r9,r9,-8160
	ctx.r9.s64 = ctx.r9.s64 + -8160;
	// lbz r6,-8168(r6)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r6.u32 + -8168);
	// stb r6,372(r31)
	REX_STORE_U8(ctx.r31.u32 + 372, ctx.r6.u8);
	// lbz r5,1(r3)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// stb r5,373(r31)
	REX_STORE_U8(ctx.r31.u32 + 373, ctx.r5.u8);
	// lbz r4,2(r3)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r3.u32 + 2);
	// stb r4,374(r31)
	REX_STORE_U8(ctx.r31.u32 + 374, ctx.r4.u8);
	// lbz r3,3(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 3);
	// stb r3,375(r31)
	REX_STORE_U8(ctx.r31.u32 + 375, ctx.r3.u8);
	// lwz r6,368(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 368);
	// add r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 + ctx.r11.u64;
	// stb r30,4(r11)
	REX_STORE_U8(ctx.r11.u32 + 4, ctx.r30.u8);
	// stw r7,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r7.u32);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_82075678:
	// lbz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stb r11,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r11.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// bdnz 0x82075678
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82075678;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r31,88
	ctx.r11.s64 = ctx.r31.s64 + 88;
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// li r10,48
	ctx.r10.s64 = 48;
	// stb r30,4(r8)
	REX_STORE_U8(ctx.r8.u32 + 4, ctx.r30.u8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820756A8:
	// stb r9,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x820756a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820756A8;
	// li r11,223
	ctx.r11.s64 = 223;
	// stb r30,76(r31)
	REX_STORE_U8(ctx.r31.u32 + 76, ctx.r30.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r11,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r11.u16);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82052ea8
	ctx.lr = 0x820756CC;
	sub_82052EA8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
