DEFINE_REX_FUNC(sub_82130990) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82130998;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// rlwinm. r11,r29,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// clrlwi r28,r29,27
	ctx.r28.u64 = ctx.r29.u32 & 0x1F;
	// beq 0x821309d0
	if (ctx.cr0.eq) goto loc_821309D0;
	// rlwinm. r11,r27,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821309d0
	if (ctx.cr0.eq) goto loc_821309D0;
	// lis r3,8192
	ctx.r3.s64 = 536870912;
	// bl 0x82130f54
	ctx.lr = 0x821309C8;
	sub_82130F54(ctx, base);
	// rlwinm r28,r28,0,29,27
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// b 0x82130bb4
	goto loc_82130BB4;
loc_821309D0:
	// rlwinm. r11,r29,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821309f0
	if (ctx.cr0.eq) goto loc_821309F0;
	// rlwinm. r11,r27,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821309f0
	if (ctx.cr0.eq) goto loc_821309F0;
	// lis r3,1024
	ctx.r3.s64 = 67108864;
	// bl 0x82130f54
	ctx.lr = 0x821309E8;
	sub_82130F54(ctx, base);
	// rlwinm r28,r28,0,30,28
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// b 0x82130bb4
	goto loc_82130BB4;
loc_821309F0:
	// clrlwi. r11,r29,31
	ctx.r11.u64 = ctx.r29.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82130abc
	if (ctx.cr0.eq) goto loc_82130ABC;
	// rlwinm. r11,r27,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82130abc
	if (ctx.cr0.eq) goto loc_82130ABC;
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// bl 0x82130f54
	ctx.lr = 0x82130A08;
	sub_82130F54(ctx, base);
	// clrlwi r11,r27,30
	ctx.r11.u64 = ctx.r27.u32 & 0x3;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82130a84
	if (ctx.cr6.lt) goto loc_82130A84;
	// beq cr6,0x82130a64
	if (ctx.cr6.eq) goto loc_82130A64;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82130a44
	if (ctx.cr6.lt) goto loc_82130A44;
	// bne cr6,0x82130ab4
	if (!ctx.cr6.eq) goto loc_82130AB4;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfd f13,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// lfd f0,-27816(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + -27816);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82130aa4
	if (!ctx.cr6.gt) goto loc_82130AA4;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lfd f0,32120(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 32120);
	// b 0x82130ab0
	goto loc_82130AB0;
loc_82130A44:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfd f13,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// lfd f0,-27816(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + -27816);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x82130a98
	if (ctx.cr6.gt) goto loc_82130A98;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lfd f0,32120(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 32120);
	// b 0x82130aac
	goto loc_82130AAC;
loc_82130A64:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfd f13,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// lfd f0,-27816(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + -27816);
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// lfd f0,32120(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 32120);
	// bgt cr6,0x82130ab0
	if (ctx.cr6.gt) goto loc_82130AB0;
	// b 0x82130aac
	goto loc_82130AAC;
loc_82130A84:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfd f13,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// lfd f0,-27816(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + -27816);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82130aa4
	if (!ctx.cr6.gt) goto loc_82130AA4;
loc_82130A98:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lfd f0,32104(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 32104);
	// b 0x82130ab0
	goto loc_82130AB0;
loc_82130AA4:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lfd f0,32104(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 32104);
loc_82130AAC:
	// fneg f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
loc_82130AB0:
	// stfd f0,0(r30)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.f0.u64);
loc_82130AB4:
	// rlwinm r28,r28,0,0,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFE;
	// b 0x82130bb4
	goto loc_82130BB4;
loc_82130ABC:
	// rlwinm. r11,r29,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82130bb4
	if (ctx.cr0.eq) goto loc_82130BB4;
	// rlwinm. r11,r27,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82130bb4
	if (ctx.cr0.eq) goto loc_82130BB4;
	// rlwinm. r11,r29,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r31,0
	ctx.r31.s64 = 0;
	// beq 0x82130adc
	if (ctx.cr0.eq) goto loc_82130ADC;
	// li r31,1
	ctx.r31.s64 = 1;
loc_82130ADC:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfd f1,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// lfd f31,-27816(r11)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r11.u32 + -27816);
	// fcmpu cr6,f1,f31
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// beq cr6,0x82130b9c
	if (ctx.cr6.eq) goto loc_82130B9C;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8212dee8
	ctx.lr = 0x82130AF8;
	sub_8212DEE8(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stfd f1,80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// addi r11,r11,-1536
	ctx.r11.s64 = ctx.r11.s64 + -1536;
	// cmpwi cr6,r11,-1074
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1074, ctx.xer);
	// bge cr6,0x82130b18
	if (!ctx.cr6.lt) goto loc_82130B18;
	// fmul f0,f1,f31
	ctx.f0.f64 = ctx.f1.f64 * ctx.f31.f64;
	// li r31,1
	ctx.r31.s64 = 1;
	// b 0x82130b94
	goto loc_82130B94;
loc_82130B18:
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// li r8,1
	ctx.r8.s64 = 1;
	// blt cr6,0x82130b28
	if (ctx.cr6.lt) goto loc_82130B28;
	// li r8,0
	ctx.r8.s64 = 0;
loc_82130B28:
	// lhz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,-1021
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1021, ctx.xer);
	// clrlwi r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	// ori r10,r10,16
	ctx.r10.u64 = ctx.r10.u64 | 16;
	// sth r10,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r10.u16);
	// bge cr6,0x82130b84
	if (!ctx.cr6.lt) goto loc_82130B84;
	// subfic r9,r11,-1021
	ctx.xer.ca = ctx.r11.u32 <= 4294966275;
	ctx.r9.u64 = static_cast<uint64_t>(-1021) - ctx.r11.u64;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_82130B4C:
	// clrlwi. r7,r11,31
	ctx.r7.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x82130b60
	if (ctx.cr0.eq) goto loc_82130B60;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne cr6,0x82130b60
	if (!ctx.cr6.eq) goto loc_82130B60;
	// li r31,1
	ctx.r31.s64 = 1;
loc_82130B60:
	// clrlwi. r7,r10,31
	ctx.r7.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// beq 0x82130b70
	if (ctx.cr0.eq) goto loc_82130B70;
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
loc_82130B70:
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// bne 0x82130b4c
	if (!ctx.cr0.eq) goto loc_82130B4C;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_82130B84:
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82130b94
	if (ctx.cr6.eq) goto loc_82130B94;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
loc_82130B94:
	// stfd f0,0(r30)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.f0.u64);
	// b 0x82130ba0
	goto loc_82130BA0;
loc_82130B9C:
	// li r31,1
	ctx.r31.s64 = 1;
loc_82130BA0:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq cr6,0x82130bb0
	if (ctx.cr6.eq) goto loc_82130BB0;
	// lis r3,2048
	ctx.r3.s64 = 134217728;
	// bl 0x82130f54
	ctx.lr = 0x82130BB0;
	sub_82130F54(ctx, base);
loc_82130BB0:
	// rlwinm r28,r28,0,31,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
loc_82130BB4:
	// rlwinm. r11,r29,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82130bd0
	if (ctx.cr0.eq) goto loc_82130BD0;
	// rlwinm. r11,r27,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82130bd0
	if (ctx.cr0.eq) goto loc_82130BD0;
	// lis r3,512
	ctx.r3.s64 = 33554432;
	// bl 0x82130f54
	ctx.lr = 0x82130BCC;
	sub_82130F54(ctx, base);
	// rlwinm r28,r28,0,28,26
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
loc_82130BD0:
	// cntlzw r11,r28
	ctx.r11.u64 = ctx.r28.u32 == 0 ? 32 : __builtin_clz(ctx.r28.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
