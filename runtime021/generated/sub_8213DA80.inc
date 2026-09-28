DEFINE_REX_FUNC(sub_8213DA80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x8213DA88;
	__savegprlr_21(ctx, base);
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r23,0
	ctx.r23.s64 = 0;
	// li r22,1
	ctx.r22.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// stb r23,128(r1)
	REX_STORE_U8(ctx.r1.u32 + 128, ctx.r23.u8);
	// lfs f0,9536(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// li r8,3
	ctx.r8.s64 = 3;
	// lwz r10,76(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 76);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stb r22,136(r1)
	REX_STORE_U8(ctx.r1.u32 + 136, ctx.r22.u8);
	// stb r9,144(r1)
	REX_STORE_U8(ctx.r1.u32 + 144, ctx.r9.u8);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// stb r8,152(r1)
	REX_STORE_U8(ctx.r1.u32 + 152, ctx.r8.u8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stb r7,88(r1)
	REX_STORE_U8(ctx.r1.u32 + 88, ctx.r7.u8);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stb r23,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r23.u8);
	// stw r6,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// stb r22,104(r1)
	REX_STORE_U8(ctx.r1.u32 + 104, ctx.r22.u8);
	// stw r5,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r5.u32);
	// bne cr6,0x8213dcd0
	if (!ctx.cr6.eq) goto loc_8213DCD0;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lwz r30,68(r28)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r28.u32 + 68);
	// stw r22,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r22.u32);
	// li r31,1112
	ctx.r31.s64 = 1112;
	// stw r22,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r22.u32);
	// addi r21,r11,-1112
	ctx.r21.s64 = ctx.r11.s64 + -1112;
	// stw r22,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r22.u32);
	// stw r22,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r22.u32);
loc_8213DB24:
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lwzx r10,r31,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8213db5c
	if (ctx.cr6.eq) goto loc_8213DB5C;
	// lwzx r9,r31,r11
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// lwz r9,196(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 196);
	// rlwinm r9,r9,0,12,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xF0000;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// beq cr6,0x8213db60
	if (ctx.cr6.eq) goto loc_8213DB60;
loc_8213DB5C:
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
loc_8213DB60:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8213dbb8
	if (ctx.cr6.eq) goto loc_8213DBB8;
	// lwzx r10,r31,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// lwz r10,196(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 196);
	// rlwinm. r10,r10,0,12,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xF0000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8213dbb4
	if (ctx.cr0.eq) goto loc_8213DBB4;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8213db88
	if (!ctx.cr6.eq) goto loc_8213DB88;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x8213dbb8
	if (ctx.cr6.eq) goto loc_8213DBB8;
loc_8213DB88:
	// stw r23,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r23.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x8214a254
	ctx.lr = 0x8213DBA8;
	__imp__XamUserAreUsersFriends(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8213dbb8
	if (!ctx.cr6.eq) goto loc_8213DBB8;
loc_8213DBB4:
	// stwx r23,r21,r31
	REX_STORE_U32(ctx.r21.u32 + ctx.r31.u32, ctx.r23.u32);
loc_8213DBB8:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r31,1128
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1128, ctx.xer);
	// blt cr6,0x8213db24
	if (ctx.cr6.lt) goto loc_8213DB24;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r26,r23
	ctx.r26.u64 = ctx.r23.u64;
	// addi r25,r1,132
	ctx.r25.s64 = ctx.r1.s64 + 132;
	// li r31,1112
	ctx.r31.s64 = 1112;
	// addi r24,r28,-1076
	ctx.r24.s64 = ctx.r28.s64 + -1076;
	// lfs f31,9540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9540);
	ctx.f31.f64 = double(temp.f32);
loc_8213DBDC:
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lwzx r10,r31,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8213dc00
	if (ctx.cr6.eq) goto loc_8213DC00;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r27,r22
	ctx.r27.u64 = ctx.r22.u64;
	// lwz r9,192(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 192);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8213dc04
	if (!ctx.cr6.eq) goto loc_8213DC04;
loc_8213DC00:
	// mr r27,r23
	ctx.r27.u64 = ctx.r23.u64;
loc_8213DC04:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8213dc94
	if (ctx.cr6.eq) goto loc_8213DC94;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// lwz r11,196(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 196);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8213dc24
	if (!ctx.cr0.eq) goto loc_8213DC24;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne cr6,0x8213dc94
	if (!ctx.cr6.eq) goto loc_8213DC94;
loc_8213DC24:
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
	// addi r29,r1,112
	ctx.r29.s64 = ctx.r1.s64 + 112;
loc_8213DC2C:
	// cmplw cr6,r30,r26
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x8213dc84
	if (ctx.cr6.eq) goto loc_8213DC84;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8213dc84
	if (!ctx.cr6.eq) goto loc_8213DC84;
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// lwz r11,196(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 196);
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8213dc80
	if (ctx.cr0.eq) goto loc_8213DC80;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x8213dc80
	if (ctx.cr6.eq) goto loc_8213DC80;
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// lwz r10,196(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 196);
	// rlwinm r10,r10,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stw r10,196(r11)
	REX_STORE_U32(ctx.r11.u32 + 196, ctx.r10.u32);
	// lwz r3,8(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lwzx r4,r31,r3
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r3.u32);
	// bl 0x82139f10
	ctx.lr = 0x8213DC7C;
	sub_82139F10(ctx, base);
	// b 0x8213dc84
	goto loc_8213DC84;
loc_8213DC80:
	// stwx r23,r31,r21
	REX_STORE_U32(ctx.r31.u32 + ctx.r21.u32, ctx.r23.u32);
loc_8213DC84:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x8213dc2c
	if (ctx.cr6.lt) goto loc_8213DC2C;
loc_8213DC94:
	// lwzx r11,r31,r21
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r21.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8213dcb0
	if (ctx.cr6.eq) goto loc_8213DCB0;
	// lwzx r11,r24,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + ctx.r31.u32);
	// cmplwi cr6,r11,65535
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65535, ctx.xer);
	// bgt cr6,0x8213dcb0
	if (ctx.cr6.gt) goto loc_8213DCB0;
	// stfs f31,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r25.u32 + 0, temp.u32);
loc_8213DCB0:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r25,r25,8
	ctx.r25.s64 = ctx.r25.s64 + 8;
	// cmplwi cr6,r31,1128
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1128, ctx.xer);
	// blt cr6,0x8213dbdc
	if (ctx.cr6.lt) goto loc_8213DBDC;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r3,72(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 72);
	// bl 0x820d81b8
	ctx.lr = 0x8213DCD0;
	sub_820D81B8(ctx, base);
loc_8213DCD0:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
