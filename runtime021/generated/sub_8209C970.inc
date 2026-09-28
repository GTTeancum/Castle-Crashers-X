DEFINE_REX_FUNC(sub_8209C970) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x8209C978;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r11,16(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209c9a0
	if (ctx.cr6.eq) goto loc_8209C9A0;
loc_8209C98C:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8209c8b8
	ctx.lr = 0x8209C994;
	sub_8209C8B8(ctx, base);
	// lwz r11,16(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209c98c
	if (!ctx.cr6.eq) goto loc_8209C98C;
loc_8209C9A0:
	// lwz r30,8(r28)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lis r27,-32215
	ctx.r27.s64 = -2111242240;
	// addi r26,r10,29632
	ctx.r26.s64 = ctx.r10.s64 + 29632;
	// addi r25,r11,-1768
	ctx.r25.s64 = ctx.r11.s64 + -1768;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8209ca1c
	if (ctx.cr6.eq) goto loc_8209CA1C;
	// rlwinm r31,r30,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
loc_8209C9C4:
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// addi r31,r31,-4
	ctx.r31.s64 = ctx.r31.s64 + -4;
	// addi r30,r30,-1
	ctx.r30.s64 = ctx.r30.s64 + -1;
	// lwzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8209ca14
	if (ctx.cr6.eq) goto loc_8209CA14;
	// lbz r10,-22601(r27)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// lwzx r29,r11,r31
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8209ca00
	if (!ctx.cr6.eq) goto loc_8209CA00;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209CA00;
	sub_820A71E8(ctx, base);
loc_8209CA00:
	// bl 0x820b5eb8
	ctx.lr = 0x8209CA04;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r3,r11,r26
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8209CA14;
	sub_8209BF18(ctx, base);
loc_8209CA14:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8209c9c4
	if (!ctx.cr6.eq) goto loc_8209C9C4;
loc_8209CA1C:
	// lwz r31,4(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8209ca5c
	if (ctx.cr6.eq) goto loc_8209CA5C;
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209ca48
	if (!ctx.cr6.eq) goto loc_8209CA48;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209CA48;
	sub_820A71E8(ctx, base);
loc_8209CA48:
	// bl 0x820b5eb8
	ctx.lr = 0x8209CA4C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwzx r3,r11,r26
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8209CA5C;
	sub_8209BF18(ctx, base);
loc_8209CA5C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r11.u32);
	// stw r11,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
