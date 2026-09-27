DEFINE_REX_FUNC(sub_820B0F18) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x820B0F20;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// li r25,1
	ctx.r25.s64 = 1;
	// addi r24,r11,-22712
	ctx.r24.s64 = ctx.r11.s64 + -22712;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x8214a434
	ctx.lr = 0x820B0F38;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lwz r11,-22672(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -22672);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820b0f50
	if (ctx.cr6.eq) goto loc_820B0F50;
	// li r25,0
	ctx.r25.s64 = 0;
	// b 0x820b0f78
	goto loc_820B0F78;
loc_820B0F50:
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,-22680
	ctx.r10.s64 = ctx.r10.s64 + -22680;
loc_820B0F5C:
	// lbzx r9,r11,r10
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820b0f6c
	if (ctx.cr6.eq) goto loc_820B0F6C;
	// li r25,0
	ctx.r25.s64 = 0;
loc_820B0F6C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x820b0f5c
	if (ctx.cr6.lt) goto loc_820B0F5C;
loc_820B0F78:
	// clrlwi r11,r25,24
	ctx.r11.u64 = ctx.r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820b0ff4
	if (ctx.cr6.eq) goto loc_820B0FF4;
	// lis r26,-32215
	ctx.r26.s64 = -2111242240;
	// lwz r30,-22684(r26)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r26.u32 + -22684);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820b0fec
	if (ctx.cr6.eq) goto loc_820B0FEC;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lis r29,-32215
	ctx.r29.s64 = -2111242240;
	// addi r28,r10,29632
	ctx.r28.s64 = ctx.r10.s64 + 29632;
	// addi r27,r11,-1768
	ctx.r27.s64 = ctx.r11.s64 + -1768;
loc_820B0FA8:
	// lbz r11,-22601(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820b0fcc
	if (!ctx.cr6.eq) goto loc_820B0FCC;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820B0FCC;
	sub_820A71E8(ctx, base);
loc_820B0FCC:
	// bl 0x820b5eb8
	ctx.lr = 0x820B0FD0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r3,r11,r28
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// bl 0x8209bf18
	ctx.lr = 0x820B0FE0;
	sub_8209BF18(ctx, base);
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x820b0fa8
	if (!ctx.cr6.eq) goto loc_820B0FA8;
loc_820B0FEC:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-22684(r26)
	REX_STORE_U32(ctx.r26.u32 + -22684, ctx.r11.u32);
loc_820B0FF4:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x8214a444
	ctx.lr = 0x820B0FFC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
