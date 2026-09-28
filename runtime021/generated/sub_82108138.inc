DEFINE_REX_FUNC(sub_82108138) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f8
	ctx.lr = 0x82108140;
	__savegprlr_20(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cntlzw r11,r6
	ctx.r11.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// stw r4,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// stw r6,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// li r31,0
	ctx.r31.s64 = 0;
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// li r21,0
	ctx.r21.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_82108170:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwzx r6,r7,r11
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// lwzx r11,r7,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82108224
	if (ctx.cr6.eq) goto loc_82108224;
	// addi r8,r11,16
	ctx.r8.s64 = ctx.r11.s64 + 16;
loc_82108190:
	// lbz r11,-8(r8)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r8.u32 + -8);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x82108218
	if (!ctx.cr0.gt) goto loc_82108218;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// ble cr6,0x8210820c
	if (!ctx.cr6.gt) goto loc_8210820C;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x821081d0
	if (ctx.cr6.eq) goto loc_821081D0;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x8210820c
	if (ctx.cr6.eq) goto loc_8210820C;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// beq cr6,0x821081c8
	if (ctx.cr6.eq) goto loc_821081C8;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// beq cr6,0x8210820c
	if (ctx.cr6.eq) goto loc_8210820C;
	// b 0x82108218
	goto loc_82108218;
loc_821081C8:
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// b 0x82108200
	goto loc_82108200;
loc_821081D0:
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8210824c
	if (!ctx.cr0.eq) goto loc_8210824C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821081fc
	if (ctx.cr6.eq) goto loc_821081FC;
	// lwz r10,4(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// rlwinm r9,r11,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lhz r10,-2(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + -2);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82108200
	if (ctx.cr0.eq) goto loc_82108200;
loc_821081FC:
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
loc_82108200:
	// cmplwi cr6,r11,1024
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1024, ctx.xer);
	// bgt cr6,0x8210824c
	if (ctx.cr6.gt) goto loc_8210824C;
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
loc_8210820C:
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// addi r31,r31,24
	ctx.r31.s64 = ctx.r31.s64 + 24;
	// addi r8,r8,24
	ctx.r8.s64 = ctx.r8.s64 + 24;
loc_82108218:
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmplw cr6,r5,r6
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x82108190
	if (ctx.cr6.lt) goto loc_82108190;
loc_82108224:
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmplwi cr6,r7,8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 8, ctx.xer);
	// blt cr6,0x82108170
	if (ctx.cr6.lt) goto loc_82108170;
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// bne cr6,0x82108244
	if (!ctx.cr6.eq) goto loc_82108244;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x821080e0
	ctx.lr = 0x82108240;
	sub_821080E0(ctx, base);
	// b 0x82108458
	goto loc_82108458;
loc_82108244:
	// cmplwi cr6,r21,1024
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 1024, ctx.xer);
	// ble cr6,0x82108258
	if (!ctx.cr6.gt) goto loc_82108258;
loc_8210824C:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// b 0x8210845c
	goto loc_8210845C;
loc_82108258:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x82108f48
	ctx.lr = 0x82108264;
	sub_82108F48(ctx, base);
	// mr. r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// bne 0x82108278
	if (!ctx.cr0.eq) goto loc_82108278;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x8210845c
	goto loc_8210845C;
loc_82108278:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82129fa0
	ctx.lr = 0x82108288;
	sub_82129FA0(ctx, base);
	// mulli r11,r21,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r21.u64 * static_cast<uint64_t>(24));
	// mr r26,r24
	ctx.r26.u64 = ctx.r24.u64;
	// add r27,r11,r24
	ctx.r27.u64 = ctx.r11.u64 + ctx.r24.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r23,0
	ctx.r23.s64 = 0;
loc_8210829C:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// lwzx r11,r23,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + ctx.r11.u32);
	// lwzx r25,r23,r10
	ctx.r25.u64 = REX_LOAD_U32(ctx.r23.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82108438
	if (ctx.cr6.eq) goto loc_82108438;
	// addi r31,r26,16
	ctx.r31.s64 = ctx.r26.s64 + 16;
	// addi r30,r25,16
	ctx.r30.s64 = ctx.r25.s64 + 16;
	// mr r22,r11
	ctx.r22.u64 = ctx.r11.u64;
loc_821082C0:
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// addi r29,r30,4
	ctx.r29.s64 = ctx.r30.s64 + 4;
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
	// lbz r11,-8(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + -8);
	// stb r11,-8(r31)
	REX_STORE_U8(ctx.r31.u32 + -8, ctx.r11.u8);
	// lbz r11,-8(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + -8);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82108410
	if (ctx.cr6.eq) goto loc_82108410;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82108400
	if (ctx.cr6.eq) goto loc_82108400;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x821083f0
	if (ctx.cr6.eq) goto loc_821083F0;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x82108368
	if (ctx.cr6.eq) goto loc_82108368;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x8210835c
	if (ctx.cr6.eq) goto loc_8210835C;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// beq cr6,0x82108328
	if (ctx.cr6.eq) goto loc_82108328;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x82108430
	if (!ctx.cr6.eq) goto loc_82108430;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r11,r28,8
	ctx.r11.s64 = ctx.r28.s64 + 8;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// b 0x8210841c
	goto loc_8210841C;
loc_82108328:
	// stw r27,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r5,0(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r4,0(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x82129a70
	ctx.lr = 0x82108344;
	sub_82129A70(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// add r27,r10,r27
	ctx.r27.u64 = ctx.r10.u64 + ctx.r27.u64;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// b 0x8210841c
	goto loc_8210841C;
loc_8210835C:
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// b 0x82108418
	goto loc_82108418;
loc_82108368:
	// stw r27,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r5,0(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r4,0(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x82129a70
	ctx.lr = 0x82108384;
	sub_82129A70(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// add r27,r11,r27
	ctx.r27.u64 = ctx.r11.u64 + ctx.r27.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821083ac
	if (ctx.cr6.eq) goto loc_821083AC;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r11,r11,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lhz r11,-2(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + -2);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x821083b0
	if (ctx.cr0.eq) goto loc_821083B0;
loc_821083AC:
	// addi r27,r27,2
	ctx.r27.s64 = ctx.r27.s64 + 2;
loc_821083B0:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r3,r3,65001
	ctx.r3.u64 = ctx.r3.u64 | 65001;
	// addi r29,r28,2
	ctx.r29.s64 = ctx.r28.s64 + 2;
	// bl 0x82136e98
	ctx.lr = 0x821083E4;
	sub_82136E98(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// b 0x8210841c
	goto loc_8210841C;
loc_821083F0:
	// lfd f0,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// addi r11,r28,8
	ctx.r11.s64 = ctx.r28.s64 + 8;
	// stfd f0,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.f0.u64);
	// b 0x8210841c
	goto loc_8210841C;
loc_82108400:
	// ld r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// addi r11,r28,8
	ctx.r11.s64 = ctx.r28.s64 + 8;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// b 0x8210841c
	goto loc_8210841C;
loc_82108410:
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
loc_82108418:
	// addi r11,r28,4
	ctx.r11.s64 = ctx.r28.s64 + 4;
loc_8210841C:
	// addi r28,r11,5
	ctx.r28.s64 = ctx.r11.s64 + 5;
	// addi r25,r25,24
	ctx.r25.s64 = ctx.r25.s64 + 24;
	// addi r30,r30,24
	ctx.r30.s64 = ctx.r30.s64 + 24;
	// addi r26,r26,24
	ctx.r26.s64 = ctx.r26.s64 + 24;
	// addi r31,r31,24
	ctx.r31.s64 = ctx.r31.s64 + 24;
loc_82108430:
	// addic. r22,r22,-1
	ctx.xer.ca = ctx.r22.u32 > 0;
	ctx.r22.s64 = ctx.r22.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// bne 0x821082c0
	if (!ctx.cr0.eq) goto loc_821082C0;
loc_82108438:
	// addi r23,r23,4
	ctx.r23.s64 = ctx.r23.s64 + 4;
	// cmplwi cr6,r23,8
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 8, ctx.xer);
	// blt cr6,0x8210829c
	if (ctx.cr6.lt) goto loc_8210829C;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x821080e0
	ctx.lr = 0x8210844C;
	sub_821080E0(ctx, base);
	// stw r24,4(r20)
	REX_STORE_U32(ctx.r20.u32 + 4, ctx.r24.u32);
	// stw r21,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r21.u32);
	// stw r28,8(r20)
	REX_STORE_U32(ctx.r20.u32 + 8, ctx.r28.u32);
loc_82108458:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8210845C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
}
