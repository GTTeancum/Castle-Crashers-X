DEFINE_REX_FUNC(sub_820A6260) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820A6268;
	__savegprlr_28(ctx, base);
	// stwu r1,-960(r1)
	ea = -960 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A6290;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820a6484
	if (!ctx.cr6.eq) goto loc_820A6484;
	// lbz r4,2(r29)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r29.u32 + 2);
	// cmplwi cr6,r4,5
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 5, ctx.xer);
	// bgt cr6,0x820a6478
	if (ctx.cr6.gt) goto loc_820A6478;
	// lis r12,-32246
	ctx.r12.s64 = -2113273856;
	// addi r12,r12,25276
	ctx.r12.s64 = ctx.r12.s64 + 25276;
	// rlwinm r0,r4,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r4.u32) {
	case 0:
		goto loc_820A62D4;
	case 1:
		goto loc_820A63A8;
	case 2:
		goto loc_820A6390;
	case 3:
		goto loc_820A62F0;
	case 4:
		goto loc_820A63C4;
	case 5:
		goto loc_820A6410;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_820A62D4:
	// addi r6,r29,3
	ctx.r6.s64 = ctx.r29.s64 + 3;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820a4c60
	ctx.lr = 0x820A62E8;
	sub_820A4C60(ctx, base);
	// addi r1,r1,960
	ctx.r1.s64 = ctx.r1.s64 + 960;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820A62F0:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A6304;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820a6484
	if (!ctx.cr6.eq) goto loc_820A6484;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A6320;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r9,6008
	ctx.r3.s64 = ctx.r9.s64 + 6008;
	// bl 0x8208c5d8
	ctx.lr = 0x820A6330;
	sub_8208C5D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r7,12(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820A6344;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lbz r6,21(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 21);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x820a6380
	if (!ctx.cr6.eq) goto loc_820A6380;
	// lbz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 20);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// li r6,768
	ctx.r6.s64 = 768;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// addi r5,r29,3
	ctx.r5.s64 = ctx.r29.s64 + 3;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-6596(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -6596);
	// li r4,768
	ctx.r4.s64 = 768;
	// lwzx r7,r8,r11
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// lwz r3,4(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x821274b0
	ctx.lr = 0x820A6380;
	sub_821274B0(ctx, base);
loc_820A6380:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,21(r31)
	REX_STORE_U8(ctx.r31.u32 + 21, ctx.r11.u8);
	// addi r1,r1,960
	ctx.r1.s64 = ctx.r1.s64 + 960;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820A6390:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820a5230
	ctx.lr = 0x820A63A0;
	sub_820A5230(ctx, base);
	// addi r1,r1,960
	ctx.r1.s64 = ctx.r1.s64 + 960;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820A63A8:
	// addi r6,r29,3
	ctx.r6.s64 = ctx.r29.s64 + 3;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820a4f88
	ctx.lr = 0x820A63BC;
	sub_820A4F88(ctx, base);
	// addi r1,r1,960
	ctx.r1.s64 = ctx.r1.s64 + 960;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820A63C4:
	// lbz r11,1376(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 1376);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a6484
	if (ctx.cr6.eq) goto loc_820A6484;
	// lbz r11,1375(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 1375);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a6484
	if (ctx.cr6.eq) goto loc_820A6484;
	// lbz r11,3(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 3);
	// li r10,5
	ctx.r10.s64 = 5;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r5,0(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stb r10,146(r1)
	REX_STORE_U8(ctx.r1.u32 + 146, ctx.r10.u8);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stb r11,147(r1)
	REX_STORE_U8(ctx.r1.u32 + 147, ctx.r11.u8);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820a5540
	ctx.lr = 0x820A6408;
	sub_820A5540(ctx, base);
	// addi r1,r1,960
	ctx.r1.s64 = ctx.r1.s64 + 960;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820A6410:
	// lbz r11,1376(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 1376);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a6484
	if (ctx.cr6.eq) goto loc_820A6484;
	// lbz r11,1375(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 1375);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a6484
	if (ctx.cr6.eq) goto loc_820A6484;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A643C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820a6484
	if (!ctx.cr6.eq) goto loc_820A6484;
	// lbz r11,1360(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 1360);
	// lbz r10,3(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 3);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820a6484
	if (!ctx.cr6.eq) goto loc_820A6484;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A6468;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,1364(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1364);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,32(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// addi r1,r1,960
	ctx.r1.s64 = ctx.r1.s64 + 960;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820A6478:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,6688
	ctx.r3.s64 = ctx.r11.s64 + 6688;
	// bl 0x8208c5d8
	ctx.lr = 0x820A6484;
	sub_8208C5D8(ctx, base);
loc_820A6484:
	// addi r1,r1,960
	ctx.r1.s64 = ctx.r1.s64 + 960;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
