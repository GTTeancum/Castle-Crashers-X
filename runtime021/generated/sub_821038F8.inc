DEFINE_REX_FUNC(sub_821038F8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82103900;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x8210392c
	if (!ctx.cr6.lt) goto loc_8210392C;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// b 0x82103c10
	goto loc_82103C10;
loc_8210392C:
	// lwz r10,20(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// cmpwi cr6,r10,8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 8, ctx.xer);
	// bne cr6,0x82103944
	if (!ctx.cr6.eq) goto loc_82103944;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,1235
	ctx.r31.u64 = ctx.r31.u64 | 1235;
	// b 0x82103c10
	goto loc_82103C10;
loc_82103944:
	// lwz r10,720(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 720);
	// rlwinm. r10,r10,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x821039a4
	if (!ctx.cr0.eq) goto loc_821039A4;
	// li r3,260
	ctx.r3.s64 = 260;
	// lwz r4,184(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 184);
	// bl 0x82108f60
	ctx.lr = 0x8210395C;
	sub_82108F60(ctx, base);
	// stw r28,184(r30)
	REX_STORE_U32(ctx.r30.u32 + 184, ctx.r28.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,31
	ctx.r4.s64 = 31;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82100538
	ctx.lr = 0x82103974;
	sub_82100538(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82103c00
	if (ctx.cr0.lt) goto loc_82103C00;
	// lwz r11,720(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 720);
	// rlwinm. r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82103c40
	if (ctx.cr0.eq) goto loc_82103C40;
	// rlwinm r11,r11,0,23,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFDFF;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,720(r30)
	REX_STORE_U32(ctx.r30.u32 + 720, ctx.r11.u32);
	// bl 0x821015d0
	ctx.lr = 0x82103998;
	sub_821015D0(ctx, base);
loc_82103998:
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82103c00
	if (ctx.cr0.lt) goto loc_82103C00;
	// b 0x82103c40
	goto loc_82103C40;
loc_821039A4:
	// lwz r10,248(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// addi r29,r30,248
	ctx.r29.s64 = ctx.r30.s64 + 248;
	// cmplw cr6,r10,r29
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x82103aac
	if (ctx.cr6.eq) goto loc_82103AAC;
	// mr r31,r10
	ctx.r31.u64 = ctx.r10.u64;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82103aac
	if (ctx.cr0.eq) goto loc_82103AAC;
loc_821039C0:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r6,r31,-92
	ctx.r6.s64 = ctx.r31.s64 + -92;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x821039d8
	if (ctx.cr6.eq) goto loc_821039D8;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
loc_821039D8:
	// lwz r11,184(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 184);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// ld r3,16(r6)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r6.u32 + 16);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82103a54
	if (ctx.cr6.eq) goto loc_82103A54;
	// addi r5,r11,16
	ctx.r5.s64 = ctx.r11.s64 + 16;
loc_821039F8:
	// lwz r7,-4(r5)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r5.u32 + -4);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82103a40
	if (ctx.cr6.eq) goto loc_82103A40;
	// lwz r8,0(r5)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
loc_82103A10:
	// ld r27,0(r9)
	ctx.r27.u64 = REX_LOAD_U64(ctx.r9.u32 + 0);
	// cmpld cr6,r27,r3
	ctx.cr6.compare<uint64_t>(ctx.r27.u64, ctx.r3.u64, ctx.xer);
	// beq cr6,0x82103a30
	if (ctx.cr6.eq) goto loc_82103A30;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x82103a10
	if (ctx.cr6.lt) goto loc_82103A10;
	// b 0x82103a40
	goto loc_82103A40;
loc_82103A30:
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r10,1
	ctx.r10.s64 = 1;
	// stdx r28,r11,r8
	REX_STORE_U64(ctx.r11.u32 + ctx.r8.u32, ctx.r28.u64);
loc_82103A40:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r5,r5,24
	ctx.r5.s64 = ctx.r5.s64 + 24;
	// bne 0x821039f8
	if (!ctx.cr0.eq) goto loc_821039F8;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x82103aa0
	if (!ctx.cr6.eq) goto loc_82103AA0;
loc_82103A54:
	// lwz r11,396(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 396);
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82103b10
	if (!ctx.cr0.eq) goto loc_82103B10;
	// lwz r10,92(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 92);
	// addi r11,r6,92
	ctx.r11.s64 = ctx.r6.s64 + 92;
	// lwz r9,96(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 96);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,96(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 96);
	// lwz r9,92(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 92);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,92(r6)
	REX_STORE_U32(ctx.r6.u32 + 92, ctx.r11.u32);
	// stw r11,96(r6)
	REX_STORE_U32(ctx.r6.u32 + 96, ctx.r11.u32);
	// stw r8,92(r6)
	REX_STORE_U32(ctx.r6.u32 + 92, ctx.r8.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stw r10,96(r6)
	REX_STORE_U32(ctx.r6.u32 + 96, ctx.r10.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_82103AA0:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x821039c0
	if (!ctx.cr6.eq) goto loc_821039C0;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_82103AAC:
	// lwz r4,184(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 184);
	// lwz r6,0(r4)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,4(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82103b00
	if (ctx.cr6.eq) goto loc_82103B00;
	// addi r8,r10,12
	ctx.r8.s64 = ctx.r10.s64 + 12;
loc_82103AC4:
	// lwz r7,0(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82103af4
	if (ctx.cr6.eq) goto loc_82103AF4;
	// lwz r9,4(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
loc_82103AD8:
	// ld r5,0(r9)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r9.u32 + 0);
	// cmpldi cr6,r5,0
	ctx.cr6.compare<uint64_t>(ctx.r5.u64, 0, ctx.xer);
	// bne cr6,0x82103b1c
	if (!ctx.cr6.eq) goto loc_82103B1C;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x82103ad8
	if (ctx.cr6.lt) goto loc_82103AD8;
loc_82103AF4:
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// addi r8,r8,24
	ctx.r8.s64 = ctx.r8.s64 + 24;
	// bne 0x82103ac4
	if (!ctx.cr0.eq) goto loc_82103AC4;
loc_82103B00:
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x82108f60
	ctx.lr = 0x82103B08;
	sub_82108F60(ctx, base);
	// stw r28,184(r30)
	REX_STORE_U32(ctx.r30.u32 + 184, ctx.r28.u32);
	// b 0x82103b84
	goto loc_82103B84;
loc_82103B10:
	// lis r31,-32747
	ctx.r31.s64 = -2146107392;
	// ori r31,r31,10
	ctx.r31.u64 = ctx.r31.u64 | 10;
	// b 0x82103c00
	goto loc_82103C00;
loc_82103B1C:
	// lis r31,-32747
	ctx.r31.s64 = -2146107392;
	// ori r31,r31,10
	ctx.r31.u64 = ctx.r31.u64 | 10;
	// b 0x82103c04
	goto loc_82103C04;
loc_82103B28:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82103b3c
	if (!ctx.cr6.eq) goto loc_82103B3C;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// b 0x82103b60
	goto loc_82103B60;
loc_82103B3C:
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_82103B60:
	// addi r31,r11,-92
	ctx.r31.s64 = ctx.r11.s64 + -92;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x820fe6c8
	ctx.lr = 0x82103B70;
	sub_820FE6C8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821071f8
	ctx.lr = 0x82103B7C;
	sub_821071F8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82103c00
	if (ctx.cr0.lt) goto loc_82103C00;
loc_82103B84:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82103b28
	if (!ctx.cr6.eq) goto loc_82103B28;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,47
	ctx.r4.s64 = 47;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82100538
	ctx.lr = 0x82103BA8;
	sub_82100538(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82103c00
	if (ctx.cr0.lt) goto loc_82103C00;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821037d0
	ctx.lr = 0x82103BB8;
	sub_821037D0(ctx, base);
	// b 0x82103998
	goto loc_82103998;
loc_82103BBC:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82103bd0
	if (!ctx.cr6.eq) goto loc_82103BD0;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// b 0x82103bf4
	goto loc_82103BF4;
loc_82103BD0:
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_82103BF4:
	// addi r4,r11,-92
	ctx.r4.s64 = ctx.r11.s64 + -92;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820fe6c8
	ctx.lr = 0x82103C00;
	sub_820FE6C8(ctx, base);
loc_82103C00:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_82103C04:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82103bbc
	if (!ctx.cr6.eq) goto loc_82103BBC;
loc_82103C10:
	// li r3,260
	ctx.r3.s64 = 260;
	// lwz r4,184(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 184);
	// bl 0x82108f60
	ctx.lr = 0x82103C1C;
	sub_82108F60(ctx, base);
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// stw r28,184(r30)
	REX_STORE_U32(ctx.r30.u32 + 184, ctx.r28.u32);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// beq cr6,0x82103c40
	if (ctx.cr6.eq) goto loc_82103C40;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82105c40
	ctx.lr = 0x82103C40;
	sub_82105C40(ctx, base);
loc_82103C40:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
