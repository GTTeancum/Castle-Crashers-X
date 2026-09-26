DEFINE_REX_FUNC(sub_820A6A40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x820A6A48;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820a6a64
	if (ctx.cr6.eq) goto loc_820A6A64;
	// addi r3,r31,32
	ctx.r3.s64 = ctx.r31.s64 + 32;
	// bl 0x820b6ca8
	ctx.lr = 0x820A6A64;
	sub_820B6CA8(ctx, base);
loc_820A6A64:
	// lwz r30,60(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// lis r28,-32215
	ctx.r28.s64 = -2111242240;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// addi r29,r11,29632
	ctx.r29.s64 = ctx.r11.s64 + 29632;
	// addi r26,r10,-1768
	ctx.r26.s64 = ctx.r10.s64 + -1768;
	// beq cr6,0x820a6ab8
	if (ctx.cr6.eq) goto loc_820A6AB8;
	// lbz r11,-22601(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a6aa4
	if (!ctx.cr6.eq) goto loc_820A6AA4;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820A6AA4;
	sub_820A71E8(ctx, base);
loc_820A6AA4:
	// bl 0x820b5eb8
	ctx.lr = 0x820A6AA8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// bl 0x8209bf18
	ctx.lr = 0x820A6AB8;
	sub_8209BF18(ctx, base);
loc_820A6AB8:
	// lwz r30,72(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820a6b00
	if (ctx.cr6.eq) goto loc_820A6B00;
	// lbz r11,-22601(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a6ae8
	if (!ctx.cr6.eq) goto loc_820A6AE8;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820A6AE8;
	sub_820A71E8(ctx, base);
loc_820A6AE8:
	// bl 0x820b5eb8
	ctx.lr = 0x820A6AEC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// bl 0x8209bf18
	ctx.lr = 0x820A6AFC;
	sub_8209BF18(ctx, base);
	// stw r27,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r27.u32);
loc_820A6B00:
	// lwz r30,76(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820a6b44
	if (ctx.cr6.eq) goto loc_820A6B44;
	// lbz r11,-22601(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a6b2c
	if (!ctx.cr6.eq) goto loc_820A6B2C;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820A6B2C;
	sub_820A71E8(ctx, base);
loc_820A6B2C:
	// bl 0x820b5eb8
	ctx.lr = 0x820A6B30;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// bl 0x8209bf18
	ctx.lr = 0x820A6B40;
	sub_8209BF18(ctx, base);
	// stw r27,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r27.u32);
loc_820A6B44:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x820a6b54
	if (ctx.cr6.eq) goto loc_820A6B54;
	// bl 0x820b6498
	ctx.lr = 0x820A6B54;
	sub_820B6498(ctx, base);
loc_820A6B54:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
