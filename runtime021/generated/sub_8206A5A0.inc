DEFINE_REX_FUNC(sub_8206A5A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x8206A5A8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lis r27,-32218
	ctx.r27.s64 = -2111438848;
	// lwz r11,48(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// lwz r3,-6628(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + -6628);
	// lhz r10,10(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// extsh r26,r10
	ctx.r26.s64 = ctx.r10.s16;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x820a39f0
	ctx.lr = 0x8206A5CC;
	sub_820A39F0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8206a834
	if (ctx.cr6.eq) goto loc_8206A834;
	// lwz r3,-6628(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + -6628);
	// li r29,0
	ctx.r29.s64 = 0;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r31,72
	ctx.r31.s64 = 72;
loc_8206A5E8:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x820a39f0
	ctx.lr = 0x8206A5F0;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// lwz r3,-6628(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + -6628);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206a63c
	if (ctx.cr6.eq) goto loc_8206A63C;
	// lhzx r11,r31,r3
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + ctx.r3.u32);
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// cmplwi cr6,r10,9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 9, ctx.xer);
	// bne cr6,0x8206a620
	if (!ctx.cr6.eq) goto loc_8206A620;
	// rlwinm r11,r11,0,24,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xC0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x8206a624
	if (!ctx.cr6.eq) goto loc_8206A624;
loc_8206A620:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8206A624:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206a63c
	if (!ctx.cr6.eq) goto loc_8206A63C;
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r29,r11,16
	ctx.r29.u64 = ctx.r11.u32 & 0xFFFF;
loc_8206A63C:
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r31,104
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 104, ctx.xer);
	// blt cr6,0x8206a5e8
	if (ctx.cr6.lt) goto loc_8206A5E8;
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bgt cr6,0x8206a748
	if (ctx.cr6.gt) goto loc_8206A748;
	// addi r11,r26,9
	ctx.r11.s64 = ctx.r26.s64 + 9;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lhzx r11,r10,r3
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r3.u32);
	// clrlwi r9,r11,28
	ctx.r9.u64 = ctx.r11.u32 & 0xF;
	// cmplwi cr6,r9,9
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 9, ctx.xer);
	// bne cr6,0x8206a680
	if (!ctx.cr6.eq) goto loc_8206A680;
	// rlwinm r11,r11,0,24,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xC0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x8206a684
	if (!ctx.cr6.eq) goto loc_8206A684;
loc_8206A680:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8206A684:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206a748
	if (!ctx.cr6.eq) goto loc_8206A748;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206a6d4
	if (ctx.cr6.eq) goto loc_8206A6D4;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206A6B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206a6d0
	if (ctx.cr6.eq) goto loc_8206A6D0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206A6D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8206A6D0:
	// lwz r3,-6628(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + -6628);
loc_8206A6D4:
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206a700
	if (ctx.cr6.eq) goto loc_8206A700;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206A6F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x8206a704
	if (!ctx.cr6.eq) goto loc_8206A704;
loc_8206A700:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8206A704:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r7,r11,-22464
	ctx.r7.s64 = ctx.r11.s64 + -22464;
	// beq cr6,0x8206a738
	if (ctx.cr6.eq) goto loc_8206A738;
	// li r6,39
	ctx.r6.s64 = 39;
	// bl 0x82054c38
	ctx.lr = 0x8206A730;
	sub_82054C38(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_8206A738:
	// li r6,40
	ctx.r6.s64 = 40;
	// bl 0x82054c38
	ctx.lr = 0x8206A740;
	sub_82054C38(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_8206A748:
	// lhz r11,30(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 30);
	// cmpw cr6,r26,r11
	ctx.cr6.compare<int32_t>(ctx.r26.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x8206a774
	if (!ctx.cr6.eq) goto loc_8206A774;
	// lhz r11,72(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 72);
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// lhz r11,80(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 80);
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// lhz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 88);
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// lhz r11,96(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 96);
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
loc_8206A774:
	// li r31,0
	ctx.r31.s64 = 0;
	// li r30,72
	ctx.r30.s64 = 72;
loc_8206A77C:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x820a39f0
	ctx.lr = 0x8206A784;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// lwz r3,-6628(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + -6628);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206a814
	if (ctx.cr6.eq) goto loc_8206A814;
	// cmplw cr6,r26,r31
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x8206a7f0
	if (ctx.cr6.eq) goto loc_8206A7F0;
	// ldx r10,r30,r3
	ctx.r10.u64 = REX_LOAD_U64(ctx.r30.u32 + ctx.r3.u32);
	// rldicl r11,r10,16,48
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u64, 16) & 0xFFFF;
	// clrlwi r9,r11,28
	ctx.r9.u64 = ctx.r11.u32 & 0xF;
	// cmplwi cr6,r9,9
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 9, ctx.xer);
	// bne cr6,0x8206a7c0
	if (!ctx.cr6.eq) goto loc_8206A7C0;
	// rlwinm r11,r11,0,24,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xC0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x8206a7c4
	if (!ctx.cr6.eq) goto loc_8206A7C4;
loc_8206A7C0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8206A7C4:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206a7f0
	if (ctx.cr6.eq) goto loc_8206A7F0;
	// addi r11,r26,9
	ctx.r11.s64 = ctx.r26.s64 + 9;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r11,1
	ctx.r11.s64 = 1;
	// ldx r8,r9,r3
	ctx.r8.u64 = REX_LOAD_U64(ctx.r9.u32 + ctx.r3.u32);
	// xor r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 ^ ctx.r10.u64;
	// clrldi r6,r7,16
	ctx.r6.u64 = ctx.r7.u64 & 0xFFFFFFFFFFFF;
	// cmpldi cr6,r6,0
	ctx.cr6.compare<uint64_t>(ctx.r6.u64, 0, ctx.xer);
	// beq cr6,0x8206a7f4
	if (ctx.cr6.eq) goto loc_8206A7F4;
loc_8206A7F0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8206A7F4:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206a814
	if (ctx.cr6.eq) goto loc_8206A814;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820a32c0
	ctx.lr = 0x8206A810;
	sub_820A32C0(ctx, base);
	// lwz r3,-6628(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + -6628);
loc_8206A814:
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplwi cr6,r30,104
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 104, ctx.xer);
	// blt cr6,0x8206a77c
	if (ctx.cr6.lt) goto loc_8206A77C;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820a32c0
	ctx.lr = 0x8206A834;
	sub_820A32C0(ctx, base);
loc_8206A834:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
