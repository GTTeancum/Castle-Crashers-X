DEFINE_REX_FUNC(sub_820D57F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e0
	ctx.lr = 0x820D57F8;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r20,r4
	ctx.r20.u64 = ctx.r4.u64;
	// li r11,-1
	ctx.r11.s64 = -1;
	// rlwinm r10,r20,0,14,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0x20000;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// cmpldi cr6,r10,0
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, 0, ctx.xer);
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// mr r14,r11
	ctx.r14.u64 = ctx.r11.u64;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r15,r11
	ctx.r15.u64 = ctx.r11.u64;
	// mr r19,r11
	ctx.r19.u64 = ctx.r11.u64;
	// beq cr6,0x820d5834
	if (ctx.cr6.eq) goto loc_820D5834;
	// bl 0x820d40a0
	ctx.lr = 0x820D5830;
	sub_820D40A0(ctx, base);
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
loc_820D5834:
	// lwz r31,12696(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 12696);
	// lwz r21,11820(r30)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r30.u32 + 11820);
	// lwz r29,12692(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 12692);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820d6074
	if (ctx.cr6.eq) goto loc_820D6074;
	// lwz r11,896(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 896);
	// lis r10,-16383
	ctx.r10.s64 = -1073676288;
	// li r24,0
	ctx.r24.s64 = 0;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// li r22,5
	ctx.r22.s64 = 5;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// ori r16,r10,9984
	ctx.r16.u64 = ctx.r10.u64 | 9984;
	// addi r25,r11,872
	ctx.r25.s64 = ctx.r11.s64 + 872;
	// bne cr6,0x820d5950
	if (!ctx.cr6.eq) goto loc_820D5950;
	// lbz r11,10943(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 10943);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d58b0
	if (ctx.cr0.eq) goto loc_820D58B0;
	// lwz r11,56(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 56);
	// lwz r3,48(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820d5890
	if (!ctx.cr6.gt) goto loc_820D5890;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820c7228
	ctx.lr = 0x820D5890;
	sub_820C7228(ctx, base);
loc_820D5890:
	// li r11,1480
	ctx.r11.s64 = 1480;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lbz r11,10943(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 10943);
	// rlwinm r11,r11,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r3,48(r30)
	REX_STORE_U32(ctx.r30.u32 + 48, ctx.r3.u32);
	// stb r11,10943(r30)
	REX_STORE_U8(ctx.r30.u32 + 10943, ctx.r11.u8);
loc_820D58B0:
	// lwz r11,872(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 872);
	// li r28,0
	ctx.r28.s64 = 0;
	// li r18,0
	ctx.r18.s64 = 0;
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r17,0
	ctx.r17.s64 = 0;
	// beq 0x820d58d8
	if (ctx.cr0.eq) goto loc_820D58D8;
	// lwz r11,904(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 904);
	// li r24,1
	ctx.r24.s64 = 1;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r25,r11,872
	ctx.r25.s64 = ctx.r11.s64 + 872;
loc_820D58D8:
	// lwz r11,10580(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 10580);
	// clrlwi r10,r11,29
	ctx.r10.u64 = ctx.r11.u32 & 0x7;
	// cmplwi cr6,r10,5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 5, ctx.xer);
	// beq cr6,0x820d591c
	if (ctx.cr6.eq) goto loc_820D591C;
	// lbz r10,10943(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 10943);
	// rlwimi r11,r22,0,29,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 0) & 0x7) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFF8);
	// oris r20,r20,8
	ctx.r20.u64 = ctx.r20.u64 | 524288;
	// rlwinm. r10,r10,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,10580(r30)
	REX_STORE_U32(ctx.r30.u32 + 10580, ctx.r11.u32);
	// ori r20,r20,8
	ctx.r20.u64 = ctx.r20.u64 | 8;
	// beq 0x820d591c
	if (ctx.cr0.eq) goto loc_820D591C;
	// lwz r11,10372(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 10372);
	// li r12,1
	ctx.r12.s64 = 1;
	// rldicr r12,r12,56,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// rlwinm r11,r11,0,16,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
	// or r20,r20,r12
	ctx.r20.u64 = ctx.r20.u64 | ctx.r12.u64;
	// stw r11,10372(r30)
	REX_STORE_U32(ctx.r30.u32 + 10372, ctx.r11.u32);
loc_820D591C:
	// lwz r11,20(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 20);
	// clrlwi r11,r11,27
	ctx.r11.u64 = ctx.r11.u32 & 0x1F;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r27,r11,1
	ctx.r27.u64 = ctx.r11.u64 ^ 1;
loc_820D5930:
	// lwz r11,13504(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 13504);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d5ab0
	if (!ctx.cr6.eq) goto loc_820D5AB0;
	// lwz r11,872(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 872);
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d5ab0
	if (ctx.cr0.eq) goto loc_820D5AB0;
	// li r3,245
	ctx.r3.s64 = 245;
	// bl 0x8214a954
	ctx.lr = 0x820D5950;
	__imp__KeBugCheck(ctx, base);
loc_820D5950:
	// lwz r11,64(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 64);
	// lis r10,4096
	ctx.r10.s64 = 268435456;
	// lbz r9,10942(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 10942);
	// rlwinm r8,r20,0,11,11
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0x100000;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lbz r7,10943(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 10943);
	// cmpldi cr6,r8,0
	ctx.cr6.compare<uint64_t>(ctx.r8.u64, 0, ctx.xer);
	// addi r28,r11,40
	ctx.r28.s64 = ctx.r11.s64 + 40;
	// lwz r18,48(r11)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// lwz r17,52(r11)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// rlwinm r11,r18,0,1,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 0) & 0x70000000;
	// subfc r11,r11,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r11.u32;
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// rlwinm r10,r11,3,21,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x7F8;
	// or r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 | ctx.r7.u64;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwimi r11,r7,0,24,30
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFE) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF01);
	// rlwimi r9,r10,0,28,28
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFF7);
	// stb r11,10943(r30)
	REX_STORE_U8(ctx.r30.u32 + 10943, ctx.r11.u8);
	// stb r9,10942(r30)
	REX_STORE_U8(ctx.r30.u32 + 10942, ctx.r9.u8);
	// beq cr6,0x820d5a74
	if (ctx.cr6.eq) goto loc_820D5A74;
	// addi r4,r29,40
	ctx.r4.s64 = ctx.r29.s64 + 40;
	// lwz r5,24(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d5568
	ctx.lr = 0x820D59B8;
	sub_820D5568(ctx, base);
	// lwz r3,48(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// lwz r11,56(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 56);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820d59d0
	if (!ctx.cr6.gt) goto loc_820D59D0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820c7228
	ctx.lr = 0x820D59D0;
	sub_820C7228(ctx, base);
loc_820D59D0:
	// mr r11,r16
	ctx.r11.u64 = ctx.r16.u64;
	// ori r20,r20,16384
	ctx.r20.u64 = ctx.r20.u64 | 16384;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// lwz r11,64(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 64);
	// lwz r10,24(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFF;
	// rlwinm r11,r11,0,3,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1FFFFFFE;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// lwz r11,64(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 64);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// lwz r11,10580(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 10580);
	// clrlwi r10,r11,29
	ctx.r10.u64 = ctx.r11.u32 & 0x7;
	// stw r3,48(r30)
	REX_STORE_U32(ctx.r30.u32 + 48, ctx.r3.u32);
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// lwz r10,24(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 24);
	// stw r10,10536(r30)
	REX_STORE_U32(ctx.r30.u32 + 10536, ctx.r10.u32);
	// beq cr6,0x820d5a74
	if (ctx.cr6.eq) goto loc_820D5A74;
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r10,10943(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 10943);
	// oris r20,r20,8
	ctx.r20.u64 = ctx.r20.u64 | 524288;
	// rlwimi r11,r9,2,29,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFF8);
	// ori r20,r20,8
	ctx.r20.u64 = ctx.r20.u64 | 8;
	// rlwinm. r10,r10,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,10580(r30)
	REX_STORE_U32(ctx.r30.u32 + 10580, ctx.r11.u32);
	// beq 0x820d5a74
	if (ctx.cr0.eq) goto loc_820D5A74;
	// lwz r11,12440(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12440);
	// li r12,1
	ctx.r12.s64 = 1;
	// rldicr r12,r12,56,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// or r20,r20,r12
	ctx.r20.u64 = ctx.r20.u64 | ctx.r12.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// stw r11,10372(r30)
	REX_STORE_U32(ctx.r30.u32 + 10372, ctx.r11.u32);
loc_820D5A74:
	// lwz r11,20(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 20);
	// lwz r10,20(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 20);
	// lwz r9,13504(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 13504);
	// xor r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 ^ ctx.r10.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// clrlwi r11,r11,13
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFF;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r27,r11,1
	ctx.r27.u64 = ctx.r11.u64 ^ 1;
	// bne cr6,0x820d5930
	if (!ctx.cr6.eq) goto loc_820D5930;
	// lwz r11,40(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 40);
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d5930
	if (ctx.cr0.eq) goto loc_820D5930;
	// li r3,245
	ctx.r3.s64 = 245;
	// bl 0x8214a954
	ctx.lr = 0x820D5AB0;
	__imp__KeBugCheck(ctx, base);
loc_820D5AB0:
	// lwz r11,8(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// lbz r10,10940(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 10940);
	// lwz r26,10580(r30)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r30.u32 + 10580);
	// lwz r23,12(r25)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r25.u32 + 12);
	// rlwinm. r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// beq 0x820d5b48
	if (ctx.cr0.eq) goto loc_820D5B48;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x820d5af8
	if (ctx.cr6.eq) goto loc_820D5AF8;
	// lwz r11,10556(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 10556);
	// rlwinm. r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820d5afc
	if (!ctx.cr0.eq) goto loc_820D5AFC;
	// lwz r11,28(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 28);
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820d5afc
	if (!ctx.cr0.eq) goto loc_820D5AFC;
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820d5afc
	if (!ctx.cr0.eq) goto loc_820D5AFC;
loc_820D5AF8:
	// rlwimi r29,r22,0,29,31
	ctx.r29.u64 = (__builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 0) & 0x7) | (ctx.r29.u64 & 0xFFFFFFFFFFFFFFF8);
loc_820D5AFC:
	// lwz r11,12700(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12700);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820d5b14
	if (!ctx.cr6.eq) goto loc_820D5B14;
	// rlwinm r11,r20,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0x8;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x820d5b48
	if (ctx.cr6.eq) goto loc_820D5B48;
loc_820D5B14:
	// lbz r11,10943(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 10943);
	// ori r20,r20,8
	ctx.r20.u64 = ctx.r20.u64 | 8;
	// stw r29,12700(r30)
	REX_STORE_U32(ctx.r30.u32 + 12700, ctx.r29.u32);
	// mr r14,r29
	ctx.r14.u64 = ctx.r29.u64;
	// rlwinm. r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d5b48
	if (ctx.cr0.eq) goto loc_820D5B48;
	// clrlwi r10,r29,29
	ctx.r10.u64 = ctx.r29.u32 & 0x7;
	// lwz r11,10372(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 10372);
	// cmplwi cr6,r10,5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 5, ctx.xer);
	// bne cr6,0x820d5b40
	if (!ctx.cr6.eq) goto loc_820D5B40;
	// rlwinm r11,r11,0,16,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
loc_820D5B40:
	// mr r22,r11
	ctx.r22.u64 = ctx.r11.u64;
	// b 0x820d5b4c
	goto loc_820D5B4C;
loc_820D5B48:
	// lwz r22,84(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_820D5B4C:
	// lbz r11,10942(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 10942);
	// rlwinm. r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820d5c64
	if (!ctx.cr0.eq) goto loc_820D5C64;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne cr6,0x820d5c64
	if (!ctx.cr6.eq) goto loc_820D5C64;
	// rlwinm r11,r20,0,12,12
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0x80000;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x820d5cac
	if (ctx.cr6.eq) goto loc_820D5CAC;
	// addi r27,r31,872
	ctx.r27.s64 = ctx.r31.s64 + 872;
	// lwz r5,32(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x820d5568
	ctx.lr = 0x820D5B80;
	sub_820D5568(ctx, base);
	// lbz r11,10942(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 10942);
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// andi. r11,r11,191
	ctx.r11.u64 = ctx.r11.u64 & 191;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r11,10942(r30)
	REX_STORE_U8(ctx.r30.u32 + 10942, ctx.r11.u8);
	// beq cr6,0x820d5c44
	if (ctx.cr6.eq) goto loc_820D5C44;
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// rlwinm. r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820d5c44
	if (!ctx.cr0.eq) goto loc_820D5C44;
	// lbz r11,10940(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 10940);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// rlwinm. r11,r11,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d5bb8
	if (ctx.cr0.eq) goto loc_820D5BB8;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x820d5c90
	goto loc_820D5C90;
loc_820D5BB8:
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// mr r5,r21
	ctx.r5.u64 = ctx.r21.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x820d56b0
	ctx.lr = 0x820D5BC8;
	sub_820D56B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820d5bd8
	if (ctx.cr0.eq) goto loc_820D5BD8;
	// mr r19,r24
	ctx.r19.u64 = ctx.r24.u64;
	// b 0x820d5bfc
	goto loc_820D5BFC;
loc_820D5BD8:
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d5408
	ctx.lr = 0x820D5BFC;
	sub_820D5408(ctx, base);
loc_820D5BFC:
	// xor r11,r29,r26
	ctx.r11.u64 = ctx.r29.u64 ^ ctx.r26.u64;
	// clrlwi. r11,r11,29
	ctx.r11.u64 = ctx.r11.u32 & 0x7;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d5cac
	if (ctx.cr0.eq) goto loc_820D5CAC;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d5cac
	if (ctx.cr0.eq) goto loc_820D5CAC;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r21
	ctx.r5.u64 = ctx.r21.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d56b0
	ctx.lr = 0x820D5C28;
	sub_820D56B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820d5cac
	if (ctx.cr0.eq) goto loc_820D5CAC;
	// lbz r11,10942(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 10942);
loc_820D5C34:
	// ori r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 64;
	// li r15,1
	ctx.r15.s64 = 1;
	// stb r11,10942(r30)
	REX_STORE_U8(ctx.r30.u32 + 10942, ctx.r11.u8);
	// b 0x820d5cac
	goto loc_820D5CAC;
loc_820D5C44:
	// xor r10,r29,r26
	ctx.r10.u64 = ctx.r29.u64 ^ ctx.r26.u64;
	// mr r19,r24
	ctx.r19.u64 = ctx.r24.u64;
	// clrlwi. r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820d5cac
	if (ctx.cr0.eq) goto loc_820D5CAC;
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// rlwinm. r10,r10,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820d5cac
	if (ctx.cr0.eq) goto loc_820D5CAC;
	// b 0x820d5c34
	goto loc_820D5C34;
loc_820D5C64:
	// rlwinm r10,r20,0,11,12
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0x180000;
	// cmpldi cr6,r10,0
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, 0, ctx.xer);
	// beq cr6,0x820d5cac
	if (ctx.cr6.eq) goto loc_820D5CAC;
	// andi. r11,r11,191
	ctx.r11.u64 = ctx.r11.u64 & 191;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r11,10942(r30)
	REX_STORE_U8(ctx.r30.u32 + 10942, ctx.r11.u8);
	// addi r4,r31,872
	ctx.r4.s64 = ctx.r31.s64 + 872;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r5,32(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x820d5568
	ctx.lr = 0x820D5C88;
	sub_820D5568(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_820D5C90:
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x820d5408
	ctx.lr = 0x820D5CAC;
	sub_820D5408(ctx, base);
loc_820D5CAC:
	// rlwinm r11,r20,0,11,12
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0x180000;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x820d5d00
	if (ctx.cr6.eq) goto loc_820D5D00;
	// or r10,r23,r17
	ctx.r10.u64 = ctx.r23.u64 | ctx.r17.u64;
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lbz r11,10942(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 10942);
	// oris r20,r20,1
	ctx.r20.u64 = ctx.r20.u64 | 65536;
	// stw r10,10532(r30)
	REX_STORE_U32(ctx.r30.u32 + 10532, ctx.r10.u32);
	// or r10,r9,r18
	ctx.r10.u64 = ctx.r9.u64 | ctx.r18.u64;
	// ori r20,r20,32768
	ctx.r20.u64 = ctx.r20.u64 | 32768;
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,10528(r30)
	REX_STORE_U32(ctx.r30.u32 + 10528, ctx.r10.u32);
	// beq 0x820d5d00
	if (ctx.cr0.eq) goto loc_820D5D00;
	// lwz r11,904(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 904);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r10,r11,872
	ctx.r10.s64 = ctx.r11.s64 + 872;
	// lwz r10,880(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 880);
	// lwz r11,884(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 884);
	// or r29,r10,r18
	ctx.r29.u64 = ctx.r10.u64 | ctx.r18.u64;
	// or r28,r11,r17
	ctx.r28.u64 = ctx.r11.u64 | ctx.r17.u64;
	// b 0x820d5d08
	goto loc_820D5D08;
loc_820D5D00:
	// lwz r28,88(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r29,92(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
loc_820D5D08:
	// lbz r11,10940(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 10940);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d5ff4
	if (ctx.cr0.eq) goto loc_820D5FF4;
	// lwz r11,56(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 56);
	// lwz r3,48(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820d5d2c
	if (!ctx.cr6.gt) goto loc_820D5D2C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820c7228
	ctx.lr = 0x820D5D2C;
	sub_820C7228(ctx, base);
loc_820D5D2C:
	// lis r11,-16384
	ctx.r11.s64 = -1073741824;
	// lis r10,5461
	ctx.r10.s64 = 357892096;
	// ori r7,r11,24576
	ctx.r7.u64 = ctx.r11.u64 | 24576;
	// ori r11,r10,21845
	ctx.r11.u64 = ctx.r10.u64 | 21845;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// lis r9,-16384
	ctx.r9.s64 = -1073741824;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r9,r9,24832
	ctx.r9.u64 = ctx.r9.u64 | 24832;
	// rlwinm r8,r20,0,28,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0x8;
	// cmpldi cr6,r8,0
	ctx.cr6.compare<uint64_t>(ctx.r8.u64, 0, ctx.xer);
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// beq cr6,0x820d5d84
	if (ctx.cr6.eq) goto loc_820D5D84;
	// li r10,8712
	ctx.r10.s64 = 8712;
	// li r12,-9
	ctx.r12.s64 = -9;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// lwz r10,10580(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 10580);
	// and r20,r20,r12
	ctx.r20.u64 = ctx.r20.u64 & ctx.r12.u64;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
loc_820D5D84:
	// cmpwi cr6,r14,-1
	ctx.cr6.compare<int32_t>(ctx.r14.s32, -1, ctx.xer);
	// beq cr6,0x820d5da8
	if (ctx.cr6.eq) goto loc_820D5DA8;
	// lis r10,-16383
	ctx.r10.s64 = -1073676288;
	// lis r9,4
	ctx.r9.s64 = 262144;
	// ori r10,r10,11521
	ctx.r10.u64 = ctx.r10.u64 | 11521;
	// ori r9,r9,520
	ctx.r9.u64 = ctx.r9.u64 | 520;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// stwu r14,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r14.u32);
	ctx.r11.u32 = ea;
loc_820D5DA8:
	// li r12,1
	ctx.r12.s64 = 1;
	// rldicr r12,r12,56,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// and r10,r20,r12
	ctx.r10.u64 = ctx.r20.u64 & ctx.r12.u64;
	// cmpldi cr6,r10,0
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, 0, ctx.xer);
	// beq cr6,0x820d5dd8
	if (ctx.cr6.eq) goto loc_820D5DD8;
	// li r10,8193
	ctx.r10.s64 = 8193;
	// li r12,-2
	ctx.r12.s64 = -2;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// lwz r10,10372(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 10372);
	// rldicr r12,r12,56,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// and r20,r20,r12
	ctx.r20.u64 = ctx.r20.u64 & ctx.r12.u64;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
loc_820D5DD8:
	// cmpwi cr6,r22,-1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, -1, ctx.xer);
	// beq cr6,0x820d5dfc
	if (ctx.cr6.eq) goto loc_820D5DFC;
	// lis r10,-16383
	ctx.r10.s64 = -1073676288;
	// lis r9,4
	ctx.r9.s64 = 262144;
	// ori r10,r10,11521
	ctx.r10.u64 = ctx.r10.u64 | 11521;
	// ori r9,r9,1
	ctx.r9.u64 = ctx.r9.u64 | 1;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// stwu r22,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r22.u32);
	ctx.r11.u32 = ea;
loc_820D5DFC:
	// rlwinm r10,r20,0,15,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0x10000;
	// cmpldi cr6,r10,0
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, 0, ctx.xer);
	// beq cr6,0x820d5e30
	if (ctx.cr6.eq) goto loc_820D5E30;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r12,-2
	ctx.r12.s64 = -131072;
	// ori r10,r10,8576
	ctx.r10.u64 = ctx.r10.u64 | 8576;
	// ori r12,r12,32767
	ctx.r12.u64 = ctx.r12.u64 | 32767;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// lwz r10,10528(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 10528);
	// and r20,r20,r12
	ctx.r20.u64 = ctx.r20.u64 & ctx.r12.u64;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// lwz r10,10532(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 10532);
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
loc_820D5E30:
	// cmpwi cr6,r29,-1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, -1, ctx.xer);
	// beq cr6,0x820d5e58
	if (ctx.cr6.eq) goto loc_820D5E58;
	// lis r10,-16382
	ctx.r10.s64 = -1073610752;
	// lis r9,4
	ctx.r9.s64 = 262144;
	// ori r10,r10,11521
	ctx.r10.u64 = ctx.r10.u64 | 11521;
	// ori r9,r9,384
	ctx.r9.u64 = ctx.r9.u64 | 384;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// stwu r29,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r29.u32);
	ctx.r11.u32 = ea;
	// stwu r28,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r28.u32);
	ctx.r11.u32 = ea;
loc_820D5E58:
	// cmpwi cr6,r15,-1
	ctx.cr6.compare<int32_t>(ctx.r15.s32, -1, ctx.xer);
	// beq cr6,0x820d5f5c
	if (ctx.cr6.eq) goto loc_820D5F5C;
	// addi r10,r15,112
	ctx.r10.s64 = ctx.r15.s64 + 112;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// lis r11,-16383
	ctx.r11.s64 = -1073676288;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// ori r11,r11,9985
	ctx.r11.u64 = ctx.r11.u64 | 9985;
	// mulli r9,r15,416
	ctx.r9.s64 = static_cast<int64_t>(ctx.r15.u64 * static_cast<uint64_t>(416));
	// stwu r11,4(r6)
	ea = 4 + ctx.r6.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r6.u32 = ea;
	// lwz r8,32(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lwzx r11,r10,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r5,r9,r31
	ctx.r5.u64 = ctx.r9.u64 + ctx.r31.u64;
	// cmpwi cr6,r19,-1
	ctx.cr6.compare<int32_t>(ctx.r19.s32, -1, ctx.xer);
	// lwz r11,872(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 872);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r9,r11,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r11,r11,3
	ctx.r11.u64 = ctx.r11.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stwu r11,4(r6)
	ea = 4 + ctx.r6.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r6.u32 = ea;
	// lwzx r11,r10,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r11,876(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 876);
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// lwz r9,10908(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 10908);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// stw r9,64(r5)
	REX_STORE_U32(ctx.r5.u32 + 64, ctx.r9.u32);
	// beq cr6,0x820d5fcc
	if (ctx.cr6.eq) goto loc_820D5FCC;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// addi r8,r19,112
	ctx.r8.s64 = ctx.r19.s64 + 112;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// lis r9,10922
	ctx.r9.s64 = 715784192;
	// rlwinm r10,r8,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// ori r9,r9,43690
	ctx.r9.u64 = ctx.r9.u64 | 43690;
	// lis r6,-16383
	ctx.r6.s64 = -1073676288;
	// mulli r11,r19,416
	ctx.r11.s64 = static_cast<int64_t>(ctx.r19.u64 * static_cast<uint64_t>(416));
	// stwu r9,4(r8)
	ea = 4 + ctx.r8.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r8.u32 = ea;
	// ori r9,r6,9985
	ctx.r9.u64 = ctx.r6.u64 | 9985;
	// add r6,r11,r31
	ctx.r6.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stwu r9,4(r8)
	ea = 4 + ctx.r8.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r8.u32 = ea;
	// lwzx r11,r10,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// lwz r9,32(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// lwz r11,872(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 872);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r11,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r11,r11,3
	ctx.r11.u64 = ctx.r11.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stwu r11,4(r8)
	ea = 4 + ctx.r8.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r8.u32 = ea;
	// lwzx r11,r10,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// lwz r11,876(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 876);
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// lwz r9,10908(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 10908);
	// stw r9,64(r6)
	REX_STORE_U32(ctx.r6.u32 + 64, ctx.r9.u32);
	// b 0x820d5fc8
	goto loc_820D5FC8;
loc_820D5F5C:
	// cmpwi cr6,r19,-1
	ctx.cr6.compare<int32_t>(ctx.r19.s32, -1, ctx.xer);
	// beq cr6,0x820d5fcc
	if (ctx.cr6.eq) goto loc_820D5FCC;
	// addi r10,r19,112
	ctx.r10.s64 = ctx.r19.s64 + 112;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// mulli r9,r19,416
	ctx.r9.s64 = static_cast<int64_t>(ctx.r19.u64 * static_cast<uint64_t>(416));
	// stwu r16,4(r6)
	ea = 4 + ctx.r6.u32;
	REX_STORE_U32(ea, ctx.r16.u32);
	ctx.r6.u32 = ea;
	// lwzx r11,r10,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// lwz r8,32(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// add r5,r9,r31
	ctx.r5.u64 = ctx.r9.u64 + ctx.r31.u64;
	// lwz r11,872(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 872);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r9,r11,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r11,r11,3
	ctx.r11.u64 = ctx.r11.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stwu r11,4(r6)
	ea = 4 + ctx.r6.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r6.u32 = ea;
	// lwzx r11,r10,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// lwz r11,876(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 876);
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// lwz r9,10908(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 10908);
	// stw r9,64(r5)
	REX_STORE_U32(ctx.r5.u32 + 64, ctx.r9.u32);
loc_820D5FC8:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820D5FCC:
	// stwu r7,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r7.u32);
	ctx.r11.u32 = ea;
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// lwz r9,12708(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 12708);
	// ori r10,r10,24832
	ctx.r10.u64 = ctx.r10.u64 | 24832;
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// lwz r10,12712(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 12712);
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// stw r11,48(r30)
	REX_STORE_U32(ctx.r30.u32 + 48, ctx.r11.u32);
	// b 0x820d6074
	goto loc_820D6074;
loc_820D5FF4:
	// cmpwi cr6,r19,-1
	ctx.cr6.compare<int32_t>(ctx.r19.s32, -1, ctx.xer);
	// beq cr6,0x820d6074
	if (ctx.cr6.eq) goto loc_820D6074;
	// lwz r11,56(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 56);
	// lwz r3,48(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820d6014
	if (!ctx.cr6.gt) goto loc_820D6014;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820c7228
	ctx.lr = 0x820D6014;
	sub_820C7228(ctx, base);
loc_820D6014:
	// addi r11,r19,112
	ctx.r11.s64 = ctx.r19.s64 + 112;
	// stwu r16,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r16.u32);
	ctx.r3.u32 = ea;
	// lwz r8,32(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// mulli r9,r19,416
	ctx.r9.s64 = static_cast<int64_t>(ctx.r19.u64 * static_cast<uint64_t>(416));
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r9,r31
	ctx.r7.u64 = ctx.r9.u64 + ctx.r31.u64;
	// lwzx r11,r10,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// lwz r11,872(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 872);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r9,r11,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r8,r11,3
	ctx.r8.u64 = ctx.r11.u32 & 0x1FFFFFFF;
	// addi r11,r9,512
	ctx.r11.s64 = ctx.r9.s64 + 512;
	// rlwinm r11,r11,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// lwzx r11,r10,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// lwz r11,876(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 876);
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// lwz r11,10908(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 10908);
	// stw r11,64(r7)
	REX_STORE_U32(ctx.r7.u32 + 64, ctx.r11.u32);
	// stw r3,48(r30)
	REX_STORE_U32(ctx.r30.u32 + 48, ctx.r3.u32);
loc_820D6074:
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
}
