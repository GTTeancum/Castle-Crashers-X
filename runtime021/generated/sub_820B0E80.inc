DEFINE_REX_FUNC(sub_820B0E80) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x820B0E88;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// li r24,0
	ctx.r24.s64 = 0;
	// addi r28,r11,-22680
	ctx.r28.s64 = ctx.r11.s64 + -22680;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
	// li r27,1
	ctx.r27.s64 = 1;
	// lis r30,-32215
	ctx.r30.s64 = -2111242240;
	// lis r26,-32215
	ctx.r26.s64 = -2111242240;
	// addi r25,r11,-22712
	ctx.r25.s64 = ctx.r11.s64 + -22712;
loc_820B0EB4:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8214a434
	ctx.lr = 0x820B0EBC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820b0ed0
	if (ctx.cr6.eq) goto loc_820B0ED0;
	// lwz r11,-22684(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -22684);
	// stw r31,-22684(r26)
	REX_STORE_U32(ctx.r26.u32 + -22684, ctx.r31.u32);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_820B0ED0:
	// lwz r31,-22672(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + -22672);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820b0eec
	if (ctx.cr6.eq) goto loc_820B0EEC;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stbx r27,r28,r29
	REX_STORE_U8(ctx.r28.u32 + ctx.r29.u32, ctx.r27.u8);
	// stw r11,-22672(r30)
	REX_STORE_U32(ctx.r30.u32 + -22672, ctx.r11.u32);
	// b 0x820b0ef0
	goto loc_820B0EF0;
loc_820B0EEC:
	// stbx r24,r28,r29
	REX_STORE_U8(ctx.r28.u32 + ctx.r29.u32, ctx.r24.u8);
loc_820B0EF0:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8214a444
	ctx.lr = 0x820B0EF8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820b0f0c
	if (ctx.cr6.eq) goto loc_820B0F0C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b1478
	ctx.lr = 0x820B0F08;
	sub_820B1478(ctx, base);
	// b 0x820b0eb4
	goto loc_820B0EB4;
loc_820B0F0C:
	// li r3,30
	ctx.r3.s64 = 30;
	// bl 0x820b6068
	ctx.lr = 0x820B0F14;
	sub_820B6068(ctx, base);
	// b 0x820b0eb4
	goto loc_820B0EB4;
}
