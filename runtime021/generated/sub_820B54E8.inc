DEFINE_REX_FUNC(sub_820B54E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x820B54F0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// ble cr6,0x820b5690
	if (!ctx.cr6.gt) goto loc_820B5690;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r31,r4,120
	ctx.r31.s64 = ctx.r4.s64 + 120;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lis r27,-32215
	ctx.r27.s64 = -2111242240;
	// addi r28,r10,29632
	ctx.r28.s64 = ctx.r10.s64 + 29632;
	// addi r26,r11,-1768
	ctx.r26.s64 = ctx.r11.s64 + -1768;
loc_820B5518:
	// lwz r11,-120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -120);
	// addi r11,r11,-16
	ctx.r11.s64 = ctx.r11.s64 + -16;
	// cmplwi cr6,r11,49
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 49, ctx.xer);
	// bgt cr6,0x820b5684
	if (ctx.cr6.gt) goto loc_820B5684;
	// lis r12,-32245
	ctx.r12.s64 = -2113208320;
	// addi r12,r12,21824
	ctx.r12.s64 = ctx.r12.s64 + 21824;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_820B5608;
	case 1:
		goto loc_820B5684;
	case 2:
		goto loc_820B5608;
	case 3:
		goto loc_820B5684;
	case 4:
		goto loc_820B5684;
	case 5:
		goto loc_820B5684;
	case 6:
		goto loc_820B5684;
	case 7:
		goto loc_820B5684;
	case 8:
		goto loc_820B5684;
	case 9:
		goto loc_820B5684;
	case 10:
		goto loc_820B5684;
	case 11:
		goto loc_820B5684;
	case 12:
		goto loc_820B5684;
	case 13:
		goto loc_820B5684;
	case 14:
		goto loc_820B5684;
	case 15:
		goto loc_820B5684;
	case 16:
		goto loc_820B5684;
	case 17:
		goto loc_820B5684;
	case 18:
		goto loc_820B5684;
	case 19:
		goto loc_820B5684;
	case 20:
		goto loc_820B5684;
	case 21:
		goto loc_820B5684;
	case 22:
		goto loc_820B5684;
	case 23:
		goto loc_820B5684;
	case 24:
		goto loc_820B5684;
	case 25:
		goto loc_820B5684;
	case 26:
		goto loc_820B5684;
	case 27:
		goto loc_820B5684;
	case 28:
		goto loc_820B5684;
	case 29:
		goto loc_820B5684;
	case 30:
		goto loc_820B5684;
	case 31:
		goto loc_820B5684;
	case 32:
		goto loc_820B5684;
	case 33:
		goto loc_820B5684;
	case 34:
		goto loc_820B5684;
	case 35:
		goto loc_820B5684;
	case 36:
		goto loc_820B5684;
	case 37:
		goto loc_820B5684;
	case 38:
		goto loc_820B5684;
	case 39:
		goto loc_820B5684;
	case 40:
		goto loc_820B5684;
	case 41:
		goto loc_820B5684;
	case 42:
		goto loc_820B5684;
	case 43:
		goto loc_820B5684;
	case 44:
		goto loc_820B5684;
	case 45:
		goto loc_820B5684;
	case 46:
		goto loc_820B5684;
	case 47:
		goto loc_820B5684;
	case 48:
		goto loc_820B564C;
	case 49:
		goto loc_820B564C;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_820B5608:
	// lwz r30,-32(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + -32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820b5684
	if (ctx.cr6.eq) goto loc_820B5684;
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820b5634
	if (!ctx.cr6.eq) goto loc_820B5634;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820B5634;
	sub_820A71E8(ctx, base);
loc_820B5634:
	// bl 0x820b5eb8
	ctx.lr = 0x820B5638;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r3,r11,r28
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// bl 0x8209bf18
	ctx.lr = 0x820B5648;
	sub_8209BF18(ctx, base);
	// b 0x820b5684
	goto loc_820B5684;
loc_820B564C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820b5684
	if (ctx.cr6.eq) goto loc_820B5684;
	// lwz r3,28(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820b5674
	if (ctx.cr6.eq) goto loc_820B5674;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820b5674
	if (ctx.cr6.eq) goto loc_820B5674;
	// bl 0x820a7400
	ctx.lr = 0x820B5674;
	sub_820A7400(ctx, base);
loc_820B5674:
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820b5684
	if (ctx.cr6.eq) goto loc_820B5684;
	// bl 0x820a7400
	ctx.lr = 0x820B5684;
	sub_820A7400(ctx, base);
loc_820B5684:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,180
	ctx.r31.s64 = ctx.r31.s64 + 180;
	// bne 0x820b5518
	if (!ctx.cr0.eq) goto loc_820B5518;
loc_820B5690:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
