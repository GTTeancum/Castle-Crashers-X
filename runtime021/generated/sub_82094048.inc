DEFINE_REX_FUNC(sub_82094048) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x82094050;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// bl 0x820869b0
	ctx.lr = 0x82094060;
	sub_820869B0(ctx, base);
	// lis r29,-32215
	ctx.r29.s64 = -2111242240;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r9,r10,-2800
	ctx.r9.s64 = ctx.r10.s64 + -2800;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lbz r7,-22601(r29)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// li r8,125
	ctx.r8.s64 = 125;
	// stw r9,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// addi r26,r11,-1768
	ctx.r26.s64 = ctx.r11.s64 + -1768;
	// stw r31,268(r30)
	REX_STORE_U32(ctx.r30.u32 + 268, ctx.r31.u32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r31,264(r30)
	REX_STORE_U32(ctx.r30.u32 + 264, ctx.r31.u32);
	// stw r31,260(r30)
	REX_STORE_U32(ctx.r30.u32 + 260, ctx.r31.u32);
	// stw r31,256(r30)
	REX_STORE_U32(ctx.r30.u32 + 256, ctx.r31.u32);
	// stw r31,288(r30)
	REX_STORE_U32(ctx.r30.u32 + 288, ctx.r31.u32);
	// sth r8,100(r30)
	REX_STORE_U16(ctx.r30.u32 + 100, ctx.r8.u16);
	// bne cr6,0x820940b8
	if (!ctx.cr6.eq) goto loc_820940B8;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820940B8;
	sub_820A71E8(ctx, base);
loc_820940B8:
	// bl 0x820b5eb8
	ctx.lr = 0x820940BC;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r11,29632
	ctx.r28.s64 = ctx.r11.s64 + 29632;
	// li r4,28
	ctx.r4.s64 = 28;
	// lwzx r3,r10,r28
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r28.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820940D4;
	sub_8209BDD8(ctx, base);
	// li r27,1
	ctx.r27.s64 = 1;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8209410c
	if (ctx.cr6.eq) goto loc_8209410C;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r31,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r31.u32);
	// stw r31,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r9,r10,-2516
	ctx.r9.s64 = ctx.r10.s64 + -2516;
	// stw r31,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r31.u32);
	// stw r27,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r27.u32);
	// stb r31,20(r3)
	REX_STORE_U8(ctx.r3.u32 + 20, ctx.r31.u8);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// sth r31,24(r3)
	REX_STORE_U16(ctx.r3.u32 + 24, ctx.r31.u16);
	// b 0x82094110
	goto loc_82094110;
loc_8209410C:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_82094110:
	// lbz r10,-22601(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// stw r11,284(r30)
	REX_STORE_U32(ctx.r30.u32 + 284, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82094134
	if (!ctx.cr6.eq) goto loc_82094134;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82094134;
	sub_820A71E8(ctx, base);
loc_82094134:
	// bl 0x820b5eb8
	ctx.lr = 0x82094138;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,28
	ctx.r4.s64 = 28;
	// lwzx r3,r11,r28
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82094148;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8209417c
	if (ctx.cr6.eq) goto loc_8209417C;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r31,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r31.u32);
	// stw r31,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r9,r10,-2560
	ctx.r9.s64 = ctx.r10.s64 + -2560;
	// stw r31,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r31.u32);
	// stw r27,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r27.u32);
	// stb r31,20(r3)
	REX_STORE_U8(ctx.r3.u32 + 20, ctx.r31.u8);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// sth r31,24(r3)
	REX_STORE_U16(ctx.r3.u32 + 24, ctx.r31.u16);
	// b 0x82094180
	goto loc_82094180;
loc_8209417C:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_82094180:
	// stw r11,280(r30)
	REX_STORE_U32(ctx.r30.u32 + 280, ctx.r11.u32);
	// addi r11,r30,248
	ctx.r11.s64 = ctx.r30.s64 + 248;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82094190:
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x82094190
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82094190;
	// stw r25,156(r30)
	REX_STORE_U32(ctx.r30.u32 + 156, ctx.r25.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r25,160(r30)
	REX_STORE_U32(ctx.r30.u32 + 160, ctx.r25.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
