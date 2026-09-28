DEFINE_REX_FUNC(sub_820AB6A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x820AB6B0;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	ctx.r28.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r23,r4
	ctx.r23.u64 = ctx.r4.u64;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// li r26,2
	ctx.r26.s64 = 2;
	// ori r30,r9,65535
	ctx.r30.u64 = ctx.r9.u64 | 65535;
	// li r24,1
	ctx.r24.s64 = 1;
	// addi r25,r11,15080
	ctx.r25.s64 = ctx.r11.s64 + 15080;
	// addi r27,r10,15592
	ctx.r27.s64 = ctx.r10.s64 + 15592;
loc_820AB6E4:
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// cmplwi cr6,r11,262
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 262, ctx.xer);
	// bge cr6,0x820ab714
	if (!ctx.cr6.lt) goto loc_820AB714;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820aaeb0
	ctx.lr = 0x820AB6F8;
	sub_820AAEB0(ctx, base);
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// cmplwi cr6,r11,262
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 262, ctx.xer);
	// bge cr6,0x820ab70c
	if (!ctx.cr6.lt) goto loc_820AB70C;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// beq cr6,0x820ab9ec
	if (ctx.cr6.eq) goto loc_820AB9EC;
loc_820AB70C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820abaf0
	if (ctx.cr6.eq) goto loc_820ABAF0;
loc_820AB714:
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x820ab77c
	if (ctx.cr6.lt) goto loc_820AB77C;
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,64(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r7,80(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r6,76(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// slw r5,r9,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r7.u8 & 0x3F));
	// lwz r4,44(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lbz r3,2(r8)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r8.u32 + 2);
	// and r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 & ctx.r11.u64;
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// xor r9,r5,r3
	ctx.r9.u64 = ctx.r5.u64 ^ ctx.r3.u64;
	// lwz r8,56(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// and r6,r9,r6
	ctx.r6.u64 = ctx.r9.u64 & ctx.r6.u64;
	// rlwinm r5,r6,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r6,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r6.u32);
	// lhzx r29,r5,r10
	ctx.r29.u64 = REX_LOAD_U16(ctx.r5.u32 + ctx.r10.u32);
	// sthx r29,r7,r8
	REX_STORE_U16(ctx.r7.u32 + ctx.r8.u32, ctx.r29.u16);
	// lwz r3,100(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r10,64(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r3,r9,r11
	REX_STORE_U16(ctx.r9.u32 + ctx.r11.u32, ctx.r3.u16);
loc_820AB77C:
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// lwz r10,104(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// stw r26,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r26.u32);
	// stw r11,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// stw r10,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// beq cr6,0x820ab814
	if (ctx.cr6.eq) goto loc_820AB814;
	// lwz r10,120(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x820ab814
	if (!ctx.cr6.lt) goto loc_820AB814;
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r10,100(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// addi r9,r11,-262
	ctx.r9.s64 = ctx.r11.s64 + -262;
	// subf r8,r29,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r29.u64;
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x820ab814
	if (ctx.cr6.gt) goto loc_820AB814;
	// lwz r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x820ab7dc
	if (ctx.cr6.eq) goto loc_820AB7DC;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820aacb8
	ctx.lr = 0x820AB7D8;
	sub_820AACB8(ctx, base);
	// stw r3,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
loc_820AB7DC:
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bgt cr6,0x820ab814
	if (ctx.cr6.gt) goto loc_820AB814;
	// lwz r10,128(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x820ab810
	if (ctx.cr6.eq) goto loc_820AB810;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x820ab814
	if (!ctx.cr6.eq) goto loc_820AB814;
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r10,104(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// subf r9,r10,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplwi cr6,r9,4096
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 4096, ctx.xer);
	// ble cr6,0x820ab814
	if (!ctx.cr6.gt) goto loc_820AB814;
loc_820AB810:
	// stw r26,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r26.u32);
loc_820AB814:
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x820ab9f8
	if (ctx.cr6.lt) goto loc_820AB9F8;
	// lwz r10,88(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820ab9f8
	if (ctx.cr6.gt) goto loc_820AB9F8;
	// addi r10,r11,253
	ctx.r10.s64 = ctx.r11.s64 + 253;
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r9,92(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// lwz r8,5784(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 5784);
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// subf r6,r9,r11
	ctx.r6.u64 = ctx.r11.u64 - ctx.r9.u64;
	// lwz r10,108(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r5,5788(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 5788);
	// rlwinm r4,r8,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r6,r30
	ctx.r3.u64 = ctx.r6.u64 + ctx.r30.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// addi r8,r11,-3
	ctx.r8.s64 = ctx.r11.s64 + -3;
	// sthx r10,r4,r5
	REX_STORE_U16(ctx.r4.u32 + ctx.r5.u32, ctx.r10.u16);
	// add r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 + ctx.r30.u64;
	// lwz r6,5784(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 5784);
	// lwz r5,5776(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 5776);
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// stbx r7,r5,r6
	REX_STORE_U8(ctx.r5.u32 + ctx.r6.u32, ctx.r7.u8);
	// lwz r10,5784(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 5784);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// stw r4,5784(r31)
	REX_STORE_U32(ctx.r31.u32 + 5784, ctx.r4.u32);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,256
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 256, ctx.xer);
	// lbzx r11,r7,r27
	ctx.r11.u64 = REX_LOAD_U8(ctx.r7.u32 + ctx.r27.u32);
	// addi r3,r11,292
	ctx.r3.s64 = ctx.r11.s64 + 292;
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lhzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r31.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r10,r11,r31
	REX_STORE_U16(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u16);
	// bge cr6,0x820ab8b0
	if (!ctx.cr6.lt) goto loc_820AB8B0;
	// lbzx r11,r9,r25
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r25.u32);
	// b 0x820ab8bc
	goto loc_820AB8BC;
loc_820AB8B0:
	// rlwinm r11,r9,25,7,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1FFFFFF;
	// addi r10,r25,256
	ctx.r10.s64 = ctx.r25.s64 + 256;
	// lbzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
loc_820AB8BC:
	// addi r11,r11,608
	ctx.r11.s64 = ctx.r11.s64 + 608;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r31.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r10,r11,r31
	REX_STORE_U16(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u16);
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// lwz r7,108(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r6,5784(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 5784);
	// lwz r10,5780(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 5780);
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// subf r10,r11,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r11.u64;
	// subf r4,r6,r5
	ctx.r4.u64 = ctx.r5.u64 - ctx.r6.u64;
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// cntlzw r10,r4
	ctx.r10.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// addi r7,r11,-2
	ctx.r7.s64 = ctx.r11.s64 + -2;
	// stw r3,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r3.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stw r7,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r7.u32);
loc_820AB904:
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bgt cr6,0x820ab974
	if (ctx.cr6.gt) goto loc_820AB974;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r7,64(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r5,80(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// slw r3,r7,r5
	ctx.r3.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r5.u8 & 0x3F));
	// lwz r4,76(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// lbz r7,2(r6)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r6.u32 + 2);
	// and r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 & ctx.r11.u64;
	// lwz r5,60(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// xor r3,r3,r7
	ctx.r3.u64 = ctx.r3.u64 ^ ctx.r7.u64;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// and r7,r3,r4
	ctx.r7.u64 = ctx.r3.u64 & ctx.r4.u64;
	// rlwinm r6,r7,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r7,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r7.u32);
	// lhzx r29,r6,r5
	ctx.r29.u64 = REX_LOAD_U16(ctx.r6.u32 + ctx.r5.u32);
	// sthx r29,r10,r11
	REX_STORE_U16(ctx.r10.u32 + ctx.r11.u32, ctx.r29.u16);
	// lwz r3,64(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r4,60(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r10,100(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// sthx r10,r11,r4
	REX_STORE_U16(ctx.r11.u32 + ctx.r4.u32, ctx.r10.u16);
loc_820AB974:
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// bne 0x820ab904
	if (!ctx.cr0.eq) goto loc_820AB904;
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r28,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r28.u32);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// stw r26,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r26.u32);
	// stw r10,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r10.u32);
	// beq cr6,0x820ab6e4
	if (ctx.cr6.eq) goto loc_820AB6E4;
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x820ab9b8
	if (ctx.cr6.lt) goto loc_820AB9B8;
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// b 0x820ab9bc
	goto loc_820AB9BC;
loc_820AB9B8:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
loc_820AB9BC:
	// li r6,0
	ctx.r6.s64 = 0;
	// subf r5,r11,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r11.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820af600
	ctx.lr = 0x820AB9CC;
	sub_820AF600(ctx, base);
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// bl 0x820aabf8
	ctx.lr = 0x820AB9DC;
	sub_820AABF8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
loc_820AB9E8:
	// bne cr6,0x820ab6e4
	if (!ctx.cr6.eq) goto loc_820AB6E4;
loc_820AB9EC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820AB9F0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
loc_820AB9F8:
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820abad0
	if (ctx.cr6.eq) goto loc_820ABAD0;
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,5784(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 5784);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r7,5788(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 5788);
	// rlwinm r6,r9,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r5,-1(r8)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r8.u32 + -1);
	// sthx r28,r6,r7
	REX_STORE_U16(ctx.r6.u32 + ctx.r7.u32, ctx.r28.u16);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// lwz r4,5784(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 5784);
	// lwz r3,5776(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 5776);
	// addi r11,r11,35
	ctx.r11.s64 = ctx.r11.s64 + 35;
	// stbx r5,r3,r4
	REX_STORE_U8(ctx.r3.u32 + ctx.r4.u32, ctx.r5.u8);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,5784(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 5784);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,5784(r31)
	REX_STORE_U32(ctx.r31.u32 + 5784, ctx.r10.u32);
	// lhzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r31.u32);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// sthx r9,r11,r31
	REX_STORE_U16(ctx.r11.u32 + ctx.r31.u32, ctx.r9.u16);
	// lwz r7,5784(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 5784);
	// lwz r11,5780(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 5780);
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// cmplw cr6,r7,r6
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x820abaa8
	if (!ctx.cr6.eq) goto loc_820ABAA8;
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x820aba80
	if (ctx.cr6.lt) goto loc_820ABA80;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x820aba84
	goto loc_820ABA84;
loc_820ABA80:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
loc_820ABA84:
	// lwz r10,100(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// subf r5,r11,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r11.u64;
	// bl 0x820af600
	ctx.lr = 0x820ABA98;
	sub_820AF600(ctx, base);
	// lwz r9,100(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r9,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r9.u32);
	// bl 0x820aabf8
	ctx.lr = 0x820ABAA8;
	sub_820AABF8(ctx, base);
loc_820ABAA8:
	// lwz r10,100(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// stw r8,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r8.u32);
	// stw r7,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r7.u32);
	// lwz r6,16(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// b 0x820ab9e8
	goto loc_820AB9E8;
loc_820ABAD0:
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// stw r24,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r24.u32);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r10,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r10.u32);
	// stw r9,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r9.u32);
	// b 0x820ab6e4
	goto loc_820AB6E4;
loc_820ABAF0:
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820abb50
	if (ctx.cr6.eq) goto loc_820ABB50;
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,5784(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 5784);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r7,5788(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 5788);
	// rlwinm r6,r9,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r5,-1(r8)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r8.u32 + -1);
	// sthx r28,r6,r7
	REX_STORE_U16(ctx.r6.u32 + ctx.r7.u32, ctx.r28.u16);
	// lwz r10,5784(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 5784);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// lwz r4,5776(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 5776);
	// addi r3,r11,35
	ctx.r3.s64 = ctx.r11.s64 + 35;
	// stbx r5,r4,r10
	REX_STORE_U8(ctx.r4.u32 + ctx.r10.u32, ctx.r5.u8);
	// lwz r10,5784(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 5784);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r9,5784(r31)
	REX_STORE_U32(ctx.r31.u32 + 5784, ctx.r9.u32);
	// lhzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r31.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// sthx r8,r11,r31
	REX_STORE_U16(ctx.r11.u32 + ctx.r31.u32, ctx.r8.u16);
	// stw r28,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r28.u32);
loc_820ABB50:
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x820abb68
	if (ctx.cr6.lt) goto loc_820ABB68;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x820abb6c
	goto loc_820ABB6C;
loc_820ABB68:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
loc_820ABB6C:
	// addi r10,r23,-4
	ctx.r10.s64 = ctx.r23.s64 + -4;
	// lwz r9,100(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// subf r5,r11,r9
	ctx.r5.u64 = ctx.r9.u64 - ctx.r11.u64;
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// bl 0x820af600
	ctx.lr = 0x820ABB88;
	sub_820AF600(ctx, base);
	// lwz r7,100(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r7,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r7.u32);
	// bl 0x820aabf8
	ctx.lr = 0x820ABB98;
	sub_820AABF8(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r5,16(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 16);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x820abbbc
	if (!ctx.cr6.eq) goto loc_820ABBBC;
	// addi r11,r23,-4
	ctx.r11.s64 = ctx.r23.s64 + -4;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r10,28,30,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x2;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
loc_820ABBBC:
	// cmpwi cr6,r23,4
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 4, ctx.xer);
	// li r3,3
	ctx.r3.s64 = 3;
	// beq cr6,0x820ab9f0
	if (ctx.cr6.eq) goto loc_820AB9F0;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
