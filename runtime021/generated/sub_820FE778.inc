DEFINE_REX_FUNC(sub_820FE778) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x820FE780;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x820fe9b4
	if (ctx.cr6.eq) goto loc_820FE9B4;
	// lwz r3,84(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 84);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820fe7ac
	if (!ctx.cr6.eq) goto loc_820FE7AC;
	// lwz r3,88(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fe7b8
	if (ctx.cr6.eq) goto loc_820FE7B8;
loc_820FE7AC:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x820fd148
	ctx.lr = 0x820FE7B4;
	sub_820FD148(ctx, base);
	// b 0x820fe8a4
	goto loc_820FE8A4;
loc_820FE7B8:
	// addi r11,r31,680
	ctx.r11.s64 = ctx.r31.s64 + 680;
	// addi r8,r30,296
	ctx.r8.s64 = ctx.r30.s64 + 296;
	// addi r9,r31,584
	ctx.r9.s64 = ctx.r31.s64 + 584;
	// addi r10,r30,168
	ctx.r10.s64 = ctx.r30.s64 + 168;
	// li r7,4
	ctx.r7.s64 = 4;
loc_820FE7CC:
	// ld r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r10.u32 + 0);
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ld r5,-32(r9)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r9.u32 + -32);
	// ld r4,-64(r10)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r10.u32 + -64);
	// add r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 + ctx.r6.u64;
	// ld r5,0(r9)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r9.u32 + 0);
	// add r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 + ctx.r4.u64;
	// std r6,-32(r9)
	REX_STORE_U64(ctx.r9.u32 + -32, ctx.r6.u64);
	// ld r4,-32(r10)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r10.u32 + -32);
	// ld r6,32(r10)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r10.u32 + 32);
	// add r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 + ctx.r6.u64;
	// add r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 + ctx.r4.u64;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// std r6,0(r9)
	REX_STORE_U64(ctx.r9.u32 + 0, ctx.r6.u64);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// lwz r4,-32(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + -32);
	// lwz r6,0(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r5,-16(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + -16);
	// add r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 + ctx.r6.u64;
	// add r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 + ctx.r4.u64;
	// lwz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r6,-16(r11)
	REX_STORE_U32(ctx.r11.u32 + -16, ctx.r6.u32);
	// lwz r4,-16(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + -16);
	// lwz r6,16(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// add r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 + ctx.r6.u64;
	// add r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 + ctx.r4.u64;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// stw r6,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bne 0x820fe7cc
	if (!ctx.cr0.eq) goto loc_820FE7CC;
	// ld r9,248(r30)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r30.u32 + 248);
	// ld r11,632(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 632);
	// ld r7,232(r30)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r30.u32 + 232);
	// add r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 + ctx.r9.u64;
	// ld r10,640(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 640);
	// lwz r9,704(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 704);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lwz r11,708(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 708);
	// std r8,632(r31)
	REX_STORE_U64(ctx.r31.u32 + 632, ctx.r8.u64);
	// ld r7,256(r30)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r30.u32 + 256);
	// ld r8,240(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 240);
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// std r10,640(r31)
	REX_STORE_U64(ctx.r31.u32 + 640, ctx.r10.u64);
	// lwz r10,336(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 336);
	// lwz r8,328(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,704(r31)
	REX_STORE_U32(ctx.r31.u32 + 704, ctx.r10.u32);
	// lwz r9,340(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 340);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r10,332(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 332);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,708(r31)
	REX_STORE_U32(ctx.r31.u32 + 708, ctx.r11.u32);
loc_820FE8A4:
	// li r29,0
	ctx.r29.s64 = 0;
	// std r29,104(r30)
	REX_STORE_U64(ctx.r30.u32 + 104, ctx.r29.u64);
	// std r29,112(r30)
	REX_STORE_U64(ctx.r30.u32 + 112, ctx.r29.u64);
	// std r29,120(r30)
	REX_STORE_U64(ctx.r30.u32 + 120, ctx.r29.u64);
	// std r29,128(r30)
	REX_STORE_U64(ctx.r30.u32 + 128, ctx.r29.u64);
	// std r29,136(r30)
	REX_STORE_U64(ctx.r30.u32 + 136, ctx.r29.u64);
	// std r29,144(r30)
	REX_STORE_U64(ctx.r30.u32 + 144, ctx.r29.u64);
	// std r29,152(r30)
	REX_STORE_U64(ctx.r30.u32 + 152, ctx.r29.u64);
	// std r29,160(r30)
	REX_STORE_U64(ctx.r30.u32 + 160, ctx.r29.u64);
	// std r29,168(r30)
	REX_STORE_U64(ctx.r30.u32 + 168, ctx.r29.u64);
	// std r29,176(r30)
	REX_STORE_U64(ctx.r30.u32 + 176, ctx.r29.u64);
	// std r29,184(r30)
	REX_STORE_U64(ctx.r30.u32 + 184, ctx.r29.u64);
	// std r29,192(r30)
	REX_STORE_U64(ctx.r30.u32 + 192, ctx.r29.u64);
	// std r29,200(r30)
	REX_STORE_U64(ctx.r30.u32 + 200, ctx.r29.u64);
	// std r29,208(r30)
	REX_STORE_U64(ctx.r30.u32 + 208, ctx.r29.u64);
	// std r29,216(r30)
	REX_STORE_U64(ctx.r30.u32 + 216, ctx.r29.u64);
	// std r29,224(r30)
	REX_STORE_U64(ctx.r30.u32 + 224, ctx.r29.u64);
	// std r29,264(r30)
	REX_STORE_U64(ctx.r30.u32 + 264, ctx.r29.u64);
	// std r29,272(r30)
	REX_STORE_U64(ctx.r30.u32 + 272, ctx.r29.u64);
	// std r29,280(r30)
	REX_STORE_U64(ctx.r30.u32 + 280, ctx.r29.u64);
	// std r29,288(r30)
	REX_STORE_U64(ctx.r30.u32 + 288, ctx.r29.u64);
	// std r29,296(r30)
	REX_STORE_U64(ctx.r30.u32 + 296, ctx.r29.u64);
	// std r29,304(r30)
	REX_STORE_U64(ctx.r30.u32 + 304, ctx.r29.u64);
	// std r29,312(r30)
	REX_STORE_U64(ctx.r30.u32 + 312, ctx.r29.u64);
	// std r29,320(r30)
	REX_STORE_U64(ctx.r30.u32 + 320, ctx.r29.u64);
	// lwz r11,396(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 396);
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820fe9b4
	if (ctx.cr0.eq) goto loc_820FE9B4;
	// lwz r26,248(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r27,r31,248
	ctx.r27.s64 = ctx.r31.s64 + 248;
	// lwz r28,24(r30)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// b 0x820fe934
	goto loc_820FE934;
loc_820FE924:
	// addi r3,r26,-92
	ctx.r3.s64 = ctx.r26.s64 + -92;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x820fd240
	ctx.lr = 0x820FE930;
	sub_820FD240(ctx, base);
	// lwz r26,0(r26)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
loc_820FE934:
	// cmplw cr6,r26,r27
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x820fe944
	if (ctx.cr6.eq) goto loc_820FE944;
	// cmplwi r26,0
	ctx.cr0.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne 0x820fe924
	if (!ctx.cr0.eq) goto loc_820FE924;
loc_820FE944:
	// addi r11,r28,69
	ctx.r11.s64 = ctx.r28.s64 + 69;
	// ld r7,632(r31)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r31.u32 + 632);
	// addi r10,r28,73
	ctx.r10.s64 = ctx.r28.s64 + 73;
	// ld r6,640(r31)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r31.u32 + 640);
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r5,704(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 704);
	// addi r11,r28,166
	ctx.r11.s64 = ctx.r28.s64 + 166;
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r28,170
	ctx.r4.s64 = ctx.r28.s64 + 170;
	// ldx r11,r8,r31
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + ctx.r31.u32);
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// std r7,632(r31)
	REX_STORE_U64(ctx.r31.u32 + 632, ctx.r7.u64);
	// ldx r7,r9,r31
	ctx.r7.u64 = REX_LOAD_U64(ctx.r9.u32 + ctx.r31.u32);
	// add r6,r7,r6
	ctx.r6.u64 = ctx.r7.u64 + ctx.r6.u64;
	// std r6,640(r31)
	REX_STORE_U64(ctx.r31.u32 + 640, ctx.r6.u64);
	// lwzx r6,r10,r31
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// add r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 + ctx.r5.u64;
	// stw r6,704(r31)
	REX_STORE_U32(ctx.r31.u32 + 704, ctx.r6.u32);
	// lwz r7,708(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 708);
	// lwzx r6,r11,r31
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stw r7,708(r31)
	REX_STORE_U32(ctx.r31.u32 + 708, ctx.r7.u32);
	// stdx r29,r8,r31
	REX_STORE_U64(ctx.r8.u32 + ctx.r31.u32, ctx.r29.u64);
	// stdx r29,r9,r31
	REX_STORE_U64(ctx.r9.u32 + ctx.r31.u32, ctx.r29.u64);
	// stwx r29,r10,r31
	REX_STORE_U32(ctx.r10.u32 + ctx.r31.u32, ctx.r29.u32);
	// stwx r29,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r29.u32);
loc_820FE9B4:
	// lwz r10,92(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 92);
	// addi r11,r30,92
	ctx.r11.s64 = ctx.r30.s64 + 92;
	// lwz r9,96(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 96);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,96(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 96);
	// lwz r9,92(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 92);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,92(r30)
	REX_STORE_U32(ctx.r30.u32 + 92, ctx.r11.u32);
	// stw r11,96(r30)
	REX_STORE_U32(ctx.r30.u32 + 96, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
