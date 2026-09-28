DEFINE_REX_FUNC(sub_82104320) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82104328;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// cmpwi cr6,r11,4097
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4097, ctx.xer);
	// bgt cr6,0x82104a9c
	if (ctx.cr6.gt) goto loc_82104A9C;
	// beq cr6,0x82104a94
	if (ctx.cr6.eq) goto loc_82104A94;
	// cmplwi cr6,r11,25
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 25, ctx.xer);
	// bgt cr6,0x82104abc
	if (ctx.cr6.gt) goto loc_82104ABC;
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// addi r12,r12,-21168
	ctx.r12.s64 = ctx.r12.s64 + -21168;
	// rlwinm r0,r11,1,0,30
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U16(ctx.r12.u32 + ctx.r0.u32);
	// lis r12,-32240
	ctx.r12.s64 = -2112880640;
	// addi r12,r12,17272
	ctx.r12.s64 = ctx.r12.s64 + 17272;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// nop 
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82104378;
	case 1:
		goto loc_821043D0;
	case 2:
		goto loc_82104458;
	case 3:
		goto loc_82104ABC;
	case 4:
		goto loc_82104ABC;
	case 5:
		goto loc_82104ABC;
	case 6:
		goto loc_821044E0;
	case 7:
		goto loc_82104570;
	case 8:
		goto loc_82104600;
	case 9:
		goto loc_82104690;
	case 10:
		goto loc_82104748;
	case 11:
		goto loc_82104760;
	case 12:
		goto loc_82104ABC;
	case 13:
		goto loc_82104ABC;
	case 14:
		goto loc_821047A0;
	case 15:
		goto loc_821047D0;
	case 16:
		goto loc_821047DC;
	case 17:
		goto loc_8210488C;
	case 18:
		goto loc_82104900;
	case 19:
		goto loc_8210495C;
	case 20:
		goto loc_8210495C;
	case 21:
		goto loc_821049F4;
	case 22:
		goto loc_8210495C;
	case 23:
		goto loc_8210495C;
	case 24:
		goto loc_82104A54;
	case 25:
		goto loc_82104A54;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82104378:
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// beq cr6,0x821043b4
	if (ctx.cr6.eq) goto loc_821043B4;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821046c8
	if (!ctx.cr6.eq) goto loc_821046C8;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x820b6ca0
	ctx.lr = 0x8210439C;
	sub_820B6CA0(ctx, base);
	// stw r3,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82104b04
	if (!ctx.cr0.eq) goto loc_82104B04;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x82104b08
	goto loc_82104B08;
loc_821043B4:
	// lwz r3,16(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821046c8
	if (ctx.cr6.eq) goto loc_821046C8;
	// bl 0x82136f68
	ctx.lr = 0x821043C4;
	sub_82136F68(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// b 0x82104b04
	goto loc_82104B04;
loc_821043D0:
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82104444
	if (ctx.cr6.eq) goto loc_82104444;
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// beq cr6,0x821043fc
	if (ctx.cr6.eq) goto loc_821043FC;
	// cmpwi cr6,r10,6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 6, ctx.xer);
	// beq cr6,0x821043fc
	if (ctx.cr6.eq) goto loc_821043FC;
loc_821043F0:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,1609
	ctx.r3.u64 = ctx.r3.u64 | 1609;
	// b 0x82104b08
	goto loc_82104B08;
loc_821043FC:
	// lwz r10,720(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r10,r10,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8210476c
	if (ctx.cr0.eq) goto loc_8210476C;
	// lbz r30,168(r31)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r31.u32 + 168);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x821046c8
	if (ctx.cr6.eq) goto loc_821046C8;
	// lbz r10,170(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 170);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8210449c
	if (ctx.cr6.lt) goto loc_8210449C;
	// stb r11,168(r31)
	REX_STORE_U8(ctx.r31.u32 + 168, ctx.r11.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82102940
	ctx.lr = 0x82104434;
	sub_82102940(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82104b04
	if (!ctx.cr0.lt) goto loc_82104B04;
	// stb r30,168(r31)
	REX_STORE_U8(ctx.r31.u32 + 168, ctx.r30.u8);
	// b 0x82104b08
	goto loc_82104B08;
loc_82104444:
	// lbz r10,168(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 168);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x821046c8
	if (ctx.cr6.eq) goto loc_821046C8;
	// stb r11,168(r31)
	REX_STORE_U8(ctx.r31.u32 + 168, ctx.r11.u8);
	// b 0x82104b04
	goto loc_82104B04;
loc_82104458:
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x821044cc
	if (ctx.cr6.eq) goto loc_821044CC;
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// beq cr6,0x82104478
	if (ctx.cr6.eq) goto loc_82104478;
	// cmpwi cr6,r10,6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 6, ctx.xer);
	// bne cr6,0x821043f0
	if (!ctx.cr6.eq) goto loc_821043F0;
loc_82104478:
	// lwz r10,720(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r10,r10,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8210476c
	if (ctx.cr0.eq) goto loc_8210476C;
	// lbz r30,169(r31)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r31.u32 + 169);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x821046c8
	if (ctx.cr6.eq) goto loc_821046C8;
	// lbz r10,171(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 171);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x821044a8
	if (!ctx.cr6.lt) goto loc_821044A8;
loc_8210449C:
	// lis r3,-32747
	ctx.r3.s64 = -2146107392;
	// ori r3,r3,20994
	ctx.r3.u64 = ctx.r3.u64 | 20994;
	// b 0x82104b08
	goto loc_82104B08;
loc_821044A8:
	// stb r11,169(r31)
	REX_STORE_U8(ctx.r31.u32 + 169, ctx.r11.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82102940
	ctx.lr = 0x821044BC;
	sub_82102940(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82104b04
	if (!ctx.cr0.lt) goto loc_82104B04;
	// stb r30,169(r31)
	REX_STORE_U8(ctx.r31.u32 + 169, ctx.r30.u8);
	// b 0x82104b08
	goto loc_82104B08;
loc_821044CC:
	// lbz r10,169(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 169);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x821046c8
	if (ctx.cr6.eq) goto loc_821046C8;
	// stb r11,169(r31)
	REX_STORE_U8(ctx.r31.u32 + 169, ctx.r11.u8);
	// b 0x82104b04
	goto loc_82104B04;
loc_821044E0:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x821043f0
	if (!ctx.cr6.eq) goto loc_821043F0;
	// lwz r30,0(r4)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x821046c8
	if (ctx.cr6.eq) goto loc_821046C8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82104510
	if (ctx.cr6.eq) goto loc_82104510;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x82104514
	if (!ctx.cr6.eq) goto loc_82104514;
loc_82104510:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82104514:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x82104528
	if (ctx.cr6.eq) goto loc_82104528;
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x8210452c
	if (!ctx.cr6.eq) goto loc_8210452C;
loc_82104528:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8210452C:
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x8210454c
	if (ctx.cr6.eq) goto loc_8210454C;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// addi r3,r31,424
	ctx.r3.s64 = ctx.r31.s64 + 424;
	// rlwinm r4,r11,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// bl 0x82109020
	ctx.lr = 0x82104544;
	sub_82109020(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82104b08
	if (ctx.cr0.lt) goto loc_82104B08;
loc_8210454C:
	// cmpwi cr6,r30,3
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 3, ctx.xer);
	// bne cr6,0x82104568
	if (!ctx.cr6.eq) goto loc_82104568;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r10,r11,0,17,17
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82104568
	if (ctx.cr0.eq) goto loc_82104568;
	// rlwinm r11,r11,0,18,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFBFFF;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
loc_82104568:
	// stw r30,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
	// b 0x82104b04
	goto loc_82104B04;
loc_82104570:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82104588
	if (ctx.cr6.eq) goto loc_82104588;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210476c
	if (ctx.cr0.eq) goto loc_8210476C;
loc_82104588:
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r10,r11,0,2,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x821045d0
	if (ctx.cr6.eq) goto loc_821045D0;
	// bne 0x821046c8
	if (!ctx.cr0.eq) goto loc_821046C8;
	// oris r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 536870912;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82102940
	ctx.lr = 0x821045BC;
	sub_82102940(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82104b08
	if (!ctx.cr0.lt) goto loc_82104B08;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm r11,r11,0,3,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFDFFFFFFF;
	// b 0x82104884
	goto loc_82104884;
loc_821045D0:
	// beq 0x821046c8
	if (ctx.cr0.eq) goto loc_821046C8;
	// rlwinm r11,r11,0,3,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFDFFFFFFF;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82102940
	ctx.lr = 0x821045EC;
	sub_82102940(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82104b08
	if (!ctx.cr0.lt) goto loc_82104B08;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// oris r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 536870912;
	// b 0x82104884
	goto loc_82104884;
loc_82104600:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82104618
	if (ctx.cr6.eq) goto loc_82104618;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210476c
	if (ctx.cr0.eq) goto loc_8210476C;
loc_82104618:
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r10,r11,0,3,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82104660
	if (ctx.cr6.eq) goto loc_82104660;
	// bne 0x821046c8
	if (!ctx.cr0.eq) goto loc_821046C8;
	// oris r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 268435456;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82102940
	ctx.lr = 0x8210464C;
	sub_82102940(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82104b08
	if (!ctx.cr0.lt) goto loc_82104B08;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm r11,r11,0,4,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// b 0x82104884
	goto loc_82104884;
loc_82104660:
	// beq 0x821046c8
	if (ctx.cr0.eq) goto loc_821046C8;
	// rlwinm r11,r11,0,4,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82102940
	ctx.lr = 0x8210467C;
	sub_82102940(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82104b08
	if (!ctx.cr0.lt) goto loc_82104B08;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// oris r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 268435456;
	// b 0x82104884
	goto loc_82104884;
loc_82104690:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821046a8
	if (ctx.cr6.eq) goto loc_821046A8;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210476c
	if (ctx.cr0.eq) goto loc_8210476C;
loc_821046A8:
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// li r30,1
	ctx.r30.s64 = 1;
	// rlwinm. r10,r11,0,4,4
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x821046bc
	if (!ctx.cr0.eq) goto loc_821046BC;
	// rlwinm r30,r11,7,30,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 7) & 0x2;
loc_821046BC:
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmpw cr6,r10,r30
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r30.s32, ctx.xer);
	// bne cr6,0x821046d0
	if (!ctx.cr6.eq) goto loc_821046D0;
loc_821046C8:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82104b08
	goto loc_82104B08;
loc_821046D0:
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x821046f4
	if (ctx.cr6.eq) goto loc_821046F4;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x821046e8
	if (ctx.cr6.eq) goto loc_821046E8;
	// rlwinm r11,r11,0,6,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFF3FFFFFF;
	// b 0x821046fc
	goto loc_821046FC;
loc_821046E8:
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwimi r11,r10,26,4,5
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0xC000000) | (ctx.r11.u64 & 0xFFFFFFFFF3FFFFFF);
	// b 0x821046fc
	goto loc_821046FC;
loc_821046F4:
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwimi r11,r10,27,4,5
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0xC000000) | (ctx.r11.u64 & 0xFFFFFFFFF3FFFFFF);
loc_821046FC:
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82102940
	ctx.lr = 0x82104710;
	sub_82102940(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82104b08
	if (!ctx.cr0.lt) goto loc_82104B08;
	// addi r11,r30,-1
	ctx.r11.s64 = ctx.r30.s64 + -1;
	// lwz r10,720(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// addi r9,r30,-2
	ctx.r9.s64 = ctx.r30.s64 + -2;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r11,r11,28,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0x2;
	// rlwinm r9,r9,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// rlwinm r10,r10,0,6,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFF3FFFFFF;
	// or r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 | ctx.r9.u64;
	// rlwinm r11,r11,26,0,5
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFC000000;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// b 0x82104884
	goto loc_82104884;
loc_82104748:
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x821046c8
	if (ctx.cr6.eq) goto loc_821046C8;
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// b 0x82104b04
	goto loc_82104B04;
loc_82104760:
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82104778
	if (!ctx.cr0.eq) goto loc_82104778;
loc_8210476C:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,1314
	ctx.r3.u64 = ctx.r3.u64 | 1314;
	// b 0x82104b08
	goto loc_82104B08;
loc_82104778:
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fcfb0
	ctx.lr = 0x82104784;
	sub_820FCFB0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82104b08
	if (ctx.cr0.lt) goto loc_82104B08;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82102940
	ctx.lr = 0x8210479C;
	sub_82102940(ctx, base);
	// b 0x82104b08
	goto loc_82104B08;
loc_821047A0:
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r10,r11,0,14,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x821047c4
	if (ctx.cr6.eq) goto loc_821047C4;
	// bne 0x821046c8
	if (!ctx.cr0.eq) goto loc_821046C8;
	// oris r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 131072;
loc_821047BC:
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// b 0x82104b04
	goto loc_82104B04;
loc_821047C4:
	// beq 0x821046c8
	if (ctx.cr0.eq) goto loc_821046C8;
	// rlwinm r11,r11,0,15,13
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFDFFFF;
	// b 0x821047bc
	goto loc_821047BC;
loc_821047D0:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16385
	ctx.r3.u64 = ctx.r3.u64 | 16385;
	// b 0x82104b08
	goto loc_82104B08;
loc_821047DC:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821043f0
	if (ctx.cr6.eq) goto loc_821043F0;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r10,r11,0,15,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82104844
	if (ctx.cr6.eq) goto loc_82104844;
	// bne 0x821046c8
	if (!ctx.cr0.eq) goto loc_821046C8;
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// oris r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 65536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// beq cr6,0x82104b04
	if (ctx.cr6.eq) goto loc_82104B04;
	// li r8,4
	ctx.r8.s64 = 4;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,26
	ctx.r6.s64 = 26;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82108ed8
	ctx.lr = 0x82104830;
	sub_82108ED8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82104b04
	if (!ctx.cr0.lt) goto loc_82104B04;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm r11,r11,0,16,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFEFFFF;
	// b 0x82104884
	goto loc_82104884;
loc_82104844:
	// beq 0x821046c8
	if (ctx.cr0.eq) goto loc_821046C8;
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// rlwinm r11,r11,0,16,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFEFFFF;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// beq cr6,0x82104b04
	if (ctx.cr6.eq) goto loc_82104B04;
	// li r8,4
	ctx.r8.s64 = 4;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,26
	ctx.r6.s64 = 26;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82108ed8
	ctx.lr = 0x82104874;
	sub_82108ED8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82104b04
	if (!ctx.cr0.lt) goto loc_82104B04;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// oris r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 65536;
loc_82104884:
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// b 0x82104b08
	goto loc_82104B08;
loc_8210488C:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x821043f0
	if (!ctx.cr6.eq) goto loc_821043F0;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// blt cr6,0x821048d4
	if (ctx.cr6.lt) goto loc_821048D4;
	// rlwinm. r10,r11,0,16,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x821048c4
	if (ctx.cr6.eq) goto loc_821048C4;
	// bne 0x821048bc
	if (!ctx.cr0.eq) goto loc_821048BC;
	// rlwinm. r10,r11,0,17,17
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x821046c8
	if (ctx.cr0.eq) goto loc_821046C8;
loc_821048BC:
	// rlwinm r11,r11,0,18,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFF3FFF;
	// b 0x821047bc
	goto loc_821047BC;
loc_821048C4:
	// bne 0x821046c8
	if (!ctx.cr0.eq) goto loc_821046C8;
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwimi r11,r10,15,16,17
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0xC000) | (ctx.r11.u64 & 0xFFFFFFFFFFFF3FFF);
	// b 0x821047bc
	goto loc_821047BC;
loc_821048D4:
	// rlwinm. r10,r11,0,17,17
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x821046c8
	if (!ctx.cr0.eq) goto loc_821046C8;
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// bne cr6,0x821048f4
	if (!ctx.cr6.eq) goto loc_821048F4;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,117
	ctx.r3.u64 = ctx.r3.u64 | 117;
	// b 0x82104b08
	goto loc_82104B08;
loc_821048F4:
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwimi r11,r10,14,16,17
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 14) & 0xC000) | (ctx.r11.u64 & 0xFFFFFFFFFFFF3FFF);
	// b 0x821047bc
	goto loc_821047BC;
loc_82104900:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x821043f0
	if (!ctx.cr6.eq) goto loc_821043F0;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// blt cr6,0x82104948
	if (ctx.cr6.lt) goto loc_82104948;
	// rlwinm. r10,r11,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82104938
	if (ctx.cr6.eq) goto loc_82104938;
	// bne 0x82104930
	if (!ctx.cr0.eq) goto loc_82104930;
	// rlwinm. r10,r11,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x821046c8
	if (ctx.cr0.eq) goto loc_821046C8;
loc_82104930:
	// rlwinm r11,r11,0,20,17
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFCFFF;
	// b 0x821047bc
	goto loc_821047BC;
loc_82104938:
	// bne 0x821046c8
	if (!ctx.cr0.eq) goto loc_821046C8;
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwimi r11,r10,13,18,19
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 13) & 0x3000) | (ctx.r11.u64 & 0xFFFFFFFFFFFFCFFF);
	// b 0x821047bc
	goto loc_821047BC;
loc_82104948:
	// rlwinm. r10,r11,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x821046c8
	if (!ctx.cr0.eq) goto loc_821046C8;
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwimi r11,r10,12,18,19
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0x3000) | (ctx.r11.u64 & 0xFFFFFFFFFFFFCFFF);
	// b 0x821047bc
	goto loc_821047BC;
loc_8210495C:
	// cmpwi cr6,r11,19
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 19, ctx.xer);
	// bne cr6,0x82104974
	if (!ctx.cr6.eq) goto loc_82104974;
	// addi r30,r31,532
	ctx.r30.s64 = ctx.r31.s64 + 532;
	// li r11,18
	ctx.r11.s64 = 18;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x82104988
	goto loc_82104988;
loc_82104974:
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x821049dc
	if (!ctx.cr6.eq) goto loc_821049DC;
	// li r5,0
	ctx.r5.s64 = 0;
loc_82104980:
	// li r11,19
	ctx.r11.s64 = 19;
	// addi r30,r31,544
	ctx.r30.s64 = ctx.r31.s64 + 544;
loc_82104988:
	// lwz r29,0(r4)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r29,1
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 1, ctx.xer);
	// blt cr6,0x82104abc
	if (ctx.cr6.lt) goto loc_82104ABC;
	// li r10,-1
	ctx.r10.s64 = -1;
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82104abc
	if (ctx.cr6.gt) goto loc_82104ABC;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x821046c8
	if (ctx.cr6.eq) goto loc_821046C8;
	// lwz r10,400(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821049d4
	if (ctx.cr6.eq) goto loc_821049D4;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fcd60
	ctx.lr = 0x821049CC;
	sub_820FCD60(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82104b08
	if (ctx.cr0.lt) goto loc_82104B08;
loc_821049D4:
	// stw r29,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r29.u32);
	// b 0x82104b04
	goto loc_82104B04;
loc_821049DC:
	// cmpwi cr6,r11,22
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 22, ctx.xer);
	// li r5,1
	ctx.r5.s64 = 1;
	// bne cr6,0x82104980
	if (!ctx.cr6.eq) goto loc_82104980;
	// addi r30,r31,540
	ctx.r30.s64 = ctx.r31.s64 + 540;
	// li r11,18
	ctx.r11.s64 = 18;
	// b 0x82104988
	goto loc_82104988;
loc_821049F4:
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// blt cr6,0x82104abc
	if (ctx.cr6.lt) goto loc_82104ABC;
	// li r10,-1
	ctx.r10.s64 = -1;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82104abc
	if (ctx.cr6.gt) goto loc_82104ABC;
	// lwz r10,548(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 548);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x821046c8
	if (ctx.cr6.eq) goto loc_821046C8;
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82104a4c
	if (ctx.cr6.eq) goto loc_82104A4C;
	// li r8,4
	ctx.r8.s64 = 4;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// li r6,20
	ctx.r6.s64 = 20;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82108ed8
	ctx.lr = 0x82104A40;
	sub_82108ED8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82104b08
	if (ctx.cr0.lt) goto loc_82104B08;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_82104A4C:
	// stw r11,548(r31)
	REX_STORE_U32(ctx.r31.u32 + 548, ctx.r11.u32);
	// b 0x82104b04
	goto loc_82104B04;
loc_82104A54:
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x821043f0
	if (!ctx.cr6.eq) goto loc_821043F0;
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82104a78
	if (ctx.cr6.eq) goto loc_82104A78;
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// bne cr6,0x82104a7c
	if (!ctx.cr6.eq) goto loc_82104A7C;
loc_82104A78:
	// li r10,1
	ctx.r10.s64 = 1;
loc_82104A7C:
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// addi r3,r31,424
	ctx.r3.s64 = ctx.r31.s64 + 424;
	// bl 0x821091c8
	ctx.lr = 0x82104A90;
	sub_821091C8(ctx, base);
	// b 0x82104b08
	goto loc_82104B08;
loc_82104A94:
	// li r6,1
	ctx.r6.s64 = 1;
	// b 0x82104ae4
	goto loc_82104AE4;
loc_82104A9C:
	// cmpwi cr6,r11,4098
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4098, ctx.xer);
	// beq cr6,0x82104ae0
	if (ctx.cr6.eq) goto loc_82104AE0;
	// cmpwi cr6,r11,4099
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4099, ctx.xer);
	// beq cr6,0x82104ad8
	if (ctx.cr6.eq) goto loc_82104AD8;
	// cmpwi cr6,r11,4100
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4100, ctx.xer);
	// beq cr6,0x82104ad0
	if (ctx.cr6.eq) goto loc_82104AD0;
	// cmpwi cr6,r11,4101
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4101, ctx.xer);
	// beq cr6,0x82104ac8
	if (ctx.cr6.eq) goto loc_82104AC8;
loc_82104ABC:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// b 0x82104b08
	goto loc_82104B08;
loc_82104AC8:
	// li r6,3
	ctx.r6.s64 = 3;
	// b 0x82104ae4
	goto loc_82104AE4;
loc_82104AD0:
	// li r6,6
	ctx.r6.s64 = 6;
	// b 0x82104ae4
	goto loc_82104AE4;
loc_82104AD8:
	// li r6,5
	ctx.r6.s64 = 5;
	// b 0x82104ae4
	goto loc_82104AE4;
loc_82104AE0:
	// li r6,2
	ctx.r6.s64 = 2;
loc_82104AE4:
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// li r8,4
	ctx.r8.s64 = 4;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82108ed8
	ctx.lr = 0x82104AFC;
	sub_82108ED8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82104b08
	if (ctx.cr0.lt) goto loc_82104B08;
loc_82104B04:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82104B08:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
