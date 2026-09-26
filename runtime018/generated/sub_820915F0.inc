DEFINE_REX_FUNC(sub_820915F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x820915F8;
	__savegprlr_25(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lbz r11,10345(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 10345);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209168c
	if (!ctx.cr6.eq) goto loc_8209168C;
	// lbz r11,10346(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 10346);
	// li r31,1
	ctx.r31.s64 = 1;
	// stb r31,10344(r29)
	REX_STORE_U8(ctx.r29.u32 + 10344, ctx.r31.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82091644
	if (!ctx.cr6.eq) goto loc_82091644;
	// addi r4,r29,10348
	ctx.r4.s64 = ctx.r29.s64 + 10348;
	// lwz r3,72(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 72);
	// bl 0x82094420
	ctx.lr = 0x8209162C;
	sub_82094420(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82091ab8
	if (ctx.cr6.eq) goto loc_82091AB8;
	// stb r31,10346(r29)
	REX_STORE_U8(ctx.r29.u32 + 10346, ctx.r31.u8);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_82091644:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r3,-6600(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6600);
	// bl 0x820b0f18
	ctx.lr = 0x82091650;
	sub_820B0F18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82091ab8
	if (ctx.cr6.eq) goto loc_82091AB8;
	// lwz r3,72(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 72);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82091670;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x82084be8
	ctx.lr = 0x82091674;
	sub_82084BE8(ctx, base);
	// li r25,0
	ctx.r25.s64 = 0;
	// stb r31,10345(r29)
	REX_STORE_U8(ctx.r29.u32 + 10345, ctx.r31.u8);
	// stb r25,10344(r29)
	REX_STORE_U8(ctx.r29.u32 + 10344, ctx.r25.u8);
	// stb r25,10346(r29)
	REX_STORE_U8(ctx.r29.u32 + 10346, ctx.r25.u8);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_8209168C:
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lfs f0,10340(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 10340);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f13,10340(r29)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r29.u32 + 10340, temp.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820916AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x820916c4
	if (!ctx.cr6.eq) goto loc_820916C4;
	// lwz r11,10336(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 10336);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,10336(r29)
	REX_STORE_U32(ctx.r29.u32 + 10336, ctx.r11.u32);
loc_820916C4:
	// lbz r11,10333(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 10333);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82091ab8
	if (!ctx.cr6.eq) goto loc_82091AB8;
	// lwz r3,72(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 72);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,84(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820916E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,72(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 72);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,88(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 88);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820916FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,7984(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 7984);
	// lwz r7,7988(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 7988);
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x82091814
	if (ctx.cr6.eq) goto loc_82091814;
loc_82091714:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r11,r29
	ctx.r31.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lwz r3,4924(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4924);
	// lhz r10,24(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 24);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82091750
	if (!ctx.cr6.eq) goto loc_82091750;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82091744;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82091798
	if (!ctx.cr6.eq) goto loc_82091798;
loc_82091750:
	// lwz r3,4924(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4924);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,140(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82091764;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,4928(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4928);
	// cmplw cr6,r3,r9
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82091798
	if (!ctx.cr6.eq) goto loc_82091798;
	// lwz r11,4924(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4924);
	// lbz r10,140(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 140);
	// ori r9,r10,4
	ctx.r9.u64 = ctx.r10.u64 | 4;
	// stb r9,140(r11)
	REX_STORE_U8(ctx.r11.u32 + 140, ctx.r9.u8);
	// lwz r3,4924(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4924);
	// lhz r4,4932(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 4932);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,88(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 88);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82091798;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82091798:
	// lwz r11,7984(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 7984);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,7984(r29)
	REX_STORE_U32(ctx.r29.u32 + 7984, ctx.r11.u32);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// bne cr6,0x820917b0
	if (!ctx.cr6.eq) goto loc_820917B0;
	// stw r25,7984(r29)
	REX_STORE_U32(ctx.r29.u32 + 7984, ctx.r25.u32);
loc_820917B0:
	// lwz r11,7984(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 7984);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820917d0
	if (ctx.cr6.eq) goto loc_820917D0;
	// lwz r9,7988(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 7988);
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82091714
	if (!ctx.cr6.eq) goto loc_82091714;
	// b 0x82091814
	goto loc_82091814;
loc_820917D0:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-3036
	ctx.r3.s64 = ctx.r11.s64 + -3036;
	// bl 0x8208c5d8
	ctx.lr = 0x820917DC;
	sub_8208C5D8(ctx, base);
	// lwz r10,7984(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 7984);
	// lwz r9,7988(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 7988);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82091814
	if (ctx.cr6.eq) goto loc_82091814;
loc_820917EC:
	// lwz r11,7984(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 7984);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,7984(r29)
	REX_STORE_U32(ctx.r29.u32 + 7984, ctx.r11.u32);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// bne cr6,0x82091804
	if (!ctx.cr6.eq) goto loc_82091804;
	// stw r25,7984(r29)
	REX_STORE_U32(ctx.r29.u32 + 7984, ctx.r25.u32);
loc_82091804:
	// lwz r11,7984(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 7984);
	// lwz r10,7988(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 7988);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820917ec
	if (!ctx.cr6.eq) goto loc_820917EC;
loc_82091814:
	// lwz r11,4920(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4920);
	// lwz r10,4916(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4916);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82091ab0
	if (ctx.cr6.eq) goto loc_82091AB0;
loc_82091824:
	// lwz r11,4916(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4916);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r11,r29
	ctx.r31.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lwz r3,116(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// lhz r10,24(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 24);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82091a68
	if (ctx.cr6.eq) goto loc_82091A68;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,140(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82091858;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,120(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// cmplw cr6,r3,r9
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82091a68
	if (!ctx.cr6.eq) goto loc_82091A68;
	// lhz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 124);
	// lwz r10,10316(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 10316);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209187c
	if (!ctx.cr6.eq) goto loc_8209187C;
	// addi r4,r10,12
	ctx.r4.s64 = ctx.r10.s64 + 12;
	// b 0x82091888
	goto loc_82091888;
loc_8209187C:
	// lwz r10,28(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_82091888:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82053a00
	ctx.lr = 0x82091890;
	sub_82053A00(ctx, base);
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820918A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x82091ab0
	if (ctx.cr6.eq) goto loc_82091AB0;
	// lbz r11,10345(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 10345);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82091ab0
	if (ctx.cr6.eq) goto loc_82091AB0;
	// lwz r30,116(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,156(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820918D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,72(r26)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r26.u32 + 72);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,56(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820918F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lbz r6,140(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 140);
	// lwz r27,0(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// ori r5,r6,16
	ctx.r5.u64 = ctx.r6.u64 | 16;
	// stb r5,140(r31)
	REX_STORE_U8(ctx.r31.u32 + 140, ctx.r5.u8);
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,72(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8209191C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,76(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 76);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82091930;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,28(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r9.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r27,0(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r7,156(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 156);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82091950;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,148(r27)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r27.u32 + 148);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82091964;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r5,0(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,24(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 24);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x82091978;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,86(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 86);
	// sth r3,80(r31)
	REX_STORE_U16(ctx.r31.u32 + 80, ctx.r3.u16);
	// clrlwi r10,r11,25
	ctx.r10.u64 = ctx.r11.u32 & 0x7F;
	// stb r10,86(r31)
	REX_STORE_U8(ctx.r31.u32 + 86, ctx.r10.u8);
	// lbz r9,86(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 86);
	// rlwinm r8,r9,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82091a0c
	if (ctx.cr6.eq) goto loc_82091A0C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82083658
	ctx.lr = 0x820919A0;
	sub_82083658(ctx, base);
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,36(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// lfs f13,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,40(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 40, temp.u32);
	// lfs f12,8(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,44(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// lfs f11,16(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,52(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 52, temp.u32);
	// lfs f10,20(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,56(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
	// lfs f9,24(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,60(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r31.u32 + 60, temp.u32);
	// lfs f8,28(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,64(r31)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// lfs f7,32(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,68(r31)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// lfs f6,36(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,72(r31)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// lbz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 12);
	// stb r11,48(r31)
	REX_STORE_U8(ctx.r31.u32 + 48, ctx.r11.u8);
	// lbz r10,13(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 13);
	// stb r10,49(r31)
	REX_STORE_U8(ctx.r31.u32 + 49, ctx.r10.u8);
	// lbz r9,14(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 14);
	// stb r9,50(r31)
	REX_STORE_U8(ctx.r31.u32 + 50, ctx.r9.u8);
	// lbz r8,86(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 86);
	// ori r7,r8,128
	ctx.r7.u64 = ctx.r8.u64 | 128;
	// stb r7,86(r31)
	REX_STORE_U8(ctx.r31.u32 + 86, ctx.r7.u8);
loc_82091A0C:
	// stw r25,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r25.u32);
	// lwz r11,32(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82091a20
	if (ctx.cr6.eq) goto loc_82091A20;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
loc_82091A20:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82091A34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82084d18
	ctx.lr = 0x82091A3C;
	sub_82084D18(ctx, base);
	// lwz r9,0(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82091A50;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82084db8
	ctx.lr = 0x82091A5C;
	sub_82084DB8(ctx, base);
	// lwz r7,76(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 76);
	// stw r7,76(r26)
	REX_STORE_U32(ctx.r26.u32 + 76, ctx.r7.u32);
	// b 0x82091a88
	goto loc_82091A88;
loc_82091A68:
	// lwz r3,116(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// lhz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82091a88
	if (ctx.cr6.eq) goto loc_82091A88;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,140(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82091A88;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82091A88:
	// lwz r11,4916(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4916);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r11,400
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 400, ctx.xer);
	// stw r11,4916(r29)
	REX_STORE_U32(ctx.r29.u32 + 4916, ctx.r11.u32);
	// bne cr6,0x82091aa0
	if (!ctx.cr6.eq) goto loc_82091AA0;
	// stw r25,4916(r29)
	REX_STORE_U32(ctx.r29.u32 + 4916, ctx.r25.u32);
loc_82091AA0:
	// lwz r11,4916(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4916);
	// lwz r10,4920(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4920);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82091824
	if (!ctx.cr6.eq) goto loc_82091824;
loc_82091AB0:
	// lwz r3,72(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 72);
	// bl 0x8208ae78
	ctx.lr = 0x82091AB8;
	sub_8208AE78(ctx, base);
loc_82091AB8:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
