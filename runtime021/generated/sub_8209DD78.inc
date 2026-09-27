DEFINE_REX_FUNC(sub_8209DD78) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8209DD80;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r10,r11,1084
	ctx.r10.s64 = ctx.r11.s64 + 1084;
	// lwz r30,96(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8209ddec
	if (ctx.cr6.eq) goto loc_8209DDEC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82090448
	ctx.lr = 0x8209DDA8;
	sub_82090448(ctx, base);
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lbz r10,-22601(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8209ddd0
	if (!ctx.cr6.eq) goto loc_8209DDD0;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r3,r11,-1768
	ctx.r3.s64 = ctx.r11.s64 + -1768;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209DDD0;
	sub_820A71E8(ctx, base);
loc_8209DDD0:
	// bl 0x820b5eb8
	ctx.lr = 0x8209DDD4;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,29632
	ctx.r9.s64 = ctx.r11.s64 + 29632;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8209DDEC;
	sub_8209BF18(ctx, base);
loc_8209DDEC:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r4,100(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r30,-6656(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + -6656);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82096530
	ctx.lr = 0x8209DE00;
	sub_82096530(ctx, base);
	// addi r30,r30,14516
	ctx.r30.s64 = ctx.r30.s64 + 14516;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a434
	ctx.lr = 0x8209DE10;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820967b0
	ctx.lr = 0x8209DE18;
	sub_820967B0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a444
	ctx.lr = 0x8209DE20;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-6612(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + -6612);
	// bl 0x82096a30
	ctx.lr = 0x8209DE34;
	sub_82096A30(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r8,r9,480
	ctx.r8.s64 = ctx.r9.s64 + 480;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// bl 0x8209cba8
	ctx.lr = 0x8209DE48;
	sub_8209CBA8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
