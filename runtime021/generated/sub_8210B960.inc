DEFINE_REX_FUNC(sub_8210B960) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x8210B968;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r24,r10
	ctx.r24.u64 = ctx.r10.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,-20880
	ctx.r11.s64 = ctx.r11.s64 + -20880;
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// bl 0x82109548
	ctx.lr = 0x8210B9A8;
	sub_82109548(ctx, base);
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// std r29,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r29.u64);
	// bl 0x82129fa0
	ctx.lr = 0x8210B9C0;
	sub_82129FA0(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r28,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r28.u32);
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// addi r7,r31,344
	ctx.r7.s64 = ctx.r31.s64 + 344;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// li r8,15
	ctx.r8.s64 = 15;
	// stw r11,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// li r6,15
	ctx.r6.s64 = 15;
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// addi r11,r31,92
	ctx.r11.s64 = ctx.r31.s64 + 92;
	// stw r30,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// stw r30,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// stw r30,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// std r30,104(r31)
	REX_STORE_U64(ctx.r31.u32 + 104, ctx.r30.u64);
	// std r30,112(r31)
	REX_STORE_U64(ctx.r31.u32 + 112, ctx.r30.u64);
	// std r30,120(r31)
	REX_STORE_U64(ctx.r31.u32 + 120, ctx.r30.u64);
	// std r30,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r30.u64);
	// std r30,136(r31)
	REX_STORE_U64(ctx.r31.u32 + 136, ctx.r30.u64);
	// std r30,144(r31)
	REX_STORE_U64(ctx.r31.u32 + 144, ctx.r30.u64);
	// std r30,152(r31)
	REX_STORE_U64(ctx.r31.u32 + 152, ctx.r30.u64);
	// std r30,160(r31)
	REX_STORE_U64(ctx.r31.u32 + 160, ctx.r30.u64);
	// std r30,168(r31)
	REX_STORE_U64(ctx.r31.u32 + 168, ctx.r30.u64);
	// std r30,176(r31)
	REX_STORE_U64(ctx.r31.u32 + 176, ctx.r30.u64);
	// std r30,184(r31)
	REX_STORE_U64(ctx.r31.u32 + 184, ctx.r30.u64);
	// std r30,192(r31)
	REX_STORE_U64(ctx.r31.u32 + 192, ctx.r30.u64);
	// std r30,200(r31)
	REX_STORE_U64(ctx.r31.u32 + 200, ctx.r30.u64);
	// std r30,208(r31)
	REX_STORE_U64(ctx.r31.u32 + 208, ctx.r30.u64);
	// std r30,216(r31)
	REX_STORE_U64(ctx.r31.u32 + 216, ctx.r30.u64);
	// std r30,224(r31)
	REX_STORE_U64(ctx.r31.u32 + 224, ctx.r30.u64);
	// std r30,232(r31)
	REX_STORE_U64(ctx.r31.u32 + 232, ctx.r30.u64);
	// std r30,240(r31)
	REX_STORE_U64(ctx.r31.u32 + 240, ctx.r30.u64);
	// std r30,248(r31)
	REX_STORE_U64(ctx.r31.u32 + 248, ctx.r30.u64);
	// std r30,256(r31)
	REX_STORE_U64(ctx.r31.u32 + 256, ctx.r30.u64);
	// std r30,264(r31)
	REX_STORE_U64(ctx.r31.u32 + 264, ctx.r30.u64);
	// std r30,272(r31)
	REX_STORE_U64(ctx.r31.u32 + 272, ctx.r30.u64);
	// std r30,280(r31)
	REX_STORE_U64(ctx.r31.u32 + 280, ctx.r30.u64);
	// std r30,288(r31)
	REX_STORE_U64(ctx.r31.u32 + 288, ctx.r30.u64);
	// std r30,296(r31)
	REX_STORE_U64(ctx.r31.u32 + 296, ctx.r30.u64);
	// std r30,304(r31)
	REX_STORE_U64(ctx.r31.u32 + 304, ctx.r30.u64);
	// std r30,312(r31)
	REX_STORE_U64(ctx.r31.u32 + 312, ctx.r30.u64);
	// std r30,320(r31)
	REX_STORE_U64(ctx.r31.u32 + 320, ctx.r30.u64);
	// stw r30,328(r31)
	REX_STORE_U32(ctx.r31.u32 + 328, ctx.r30.u32);
	// stw r30,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r30.u32);
	// stw r30,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r30.u32);
	// stw r30,340(r31)
	REX_STORE_U32(ctx.r31.u32 + 340, ctx.r30.u32);
	// bl 0x82136f70
	ctx.lr = 0x8210BA94;
	sub_82136F70(ctx, base);
	// cntlzw r11,r26
	ctx.r11.u64 = ctx.r26.u32 == 0 ? 32 : __builtin_clz(ctx.r26.u32);
	// cntlzw r10,r25
	ctx.r10.u64 = ctx.r25.u32 == 0 ? 32 : __builtin_clz(ctx.r25.u32);
	// sth r30,374(r31)
	REX_STORE_U16(ctx.r31.u32 + 374, ctx.r30.u16);
	// rlwinm r11,r11,28,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0x2;
	// lwz r9,252(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 252);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r8,244(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 244);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// xori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 ^ 2;
	// addi r6,r7,-20896
	ctx.r6.s64 = ctx.r7.s64 + -20896;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// cntlzw r5,r24
	ctx.r5.u64 = ctx.r24.u32 == 0 ? 32 : __builtin_clz(ctx.r24.u32);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,-20896(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + -20896);
	// rlwinm r7,r5,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// stw r10,376(r31)
	REX_STORE_U32(ctx.r31.u32 + 376, ctx.r10.u32);
	// lwz r10,4(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// xori r7,r7,1
	ctx.r7.u64 = ctx.r7.u64 ^ 1;
	// stw r10,380(r31)
	REX_STORE_U32(ctx.r31.u32 + 380, ctx.r10.u32);
	// cntlzw r10,r9
	ctx.r10.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lwz r9,8(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// or r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 | ctx.r7.u64;
	// stw r9,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r9.u32);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r9,12(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,388(r31)
	REX_STORE_U32(ctx.r31.u32 + 388, ctx.r9.u32);
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// cntlzw r9,r8
	ctx.r9.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// stb r30,392(r31)
	REX_STORE_U8(ctx.r31.u32 + 392, ctx.r30.u8);
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stb r30,393(r31)
	REX_STORE_U8(ctx.r31.u32 + 393, ctx.r30.u8);
	// rlwinm r10,r9,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// rlwinm r11,r11,22,0,9
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 22) & 0xFFC00000;
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// li r9,255
	ctx.r9.s64 = 255;
	// or r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 | ctx.r10.u64;
	// addi r11,r31,376
	ctx.r11.s64 = ctx.r31.s64 + 376;
	// stb r9,394(r31)
	REX_STORE_U8(ctx.r31.u32 + 394, ctx.r9.u8);
	// rlwinm r11,r10,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
