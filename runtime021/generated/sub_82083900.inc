DEFINE_REX_FUNC(sub_82083900) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x82083908;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// sth r11,4(r31)
	REX_STORE_U16(ctx.r31.u32 + 4, ctx.r11.u16);
	// ori r8,r10,65535
	ctx.r8.u64 = ctx.r10.u64 | 65535;
	// lbz r9,0(r27)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r27.u32 + 0);
	// li r29,2
	ctx.r29.s64 = 2;
	// lbz r7,1(r27)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r27.u32 + 1);
	// rotlwi r6,r7,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// or r28,r6,r9
	ctx.r28.u64 = ctx.r6.u64 | ctx.r9.u64;
	// cmplw cr6,r28,r8
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r8.u32, ctx.xer);
	// rlwinm r30,r28,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// ble cr6,0x8208394c
	if (!ctx.cr6.gt) goto loc_8208394C;
	// li r30,-1
	ctx.r30.s64 = -1;
loc_8208394C:
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lbz r10,-22601(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82083974
	if (!ctx.cr6.eq) goto loc_82083974;
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
	ctx.lr = 0x82083974;
	sub_820A71E8(ctx, base);
loc_82083974:
	// bl 0x820b5eb8
	ctx.lr = 0x82083978;
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
	// bl 0x8209bdd8
	ctx.lr = 0x82083990;
	sub_8209BDD8(ctx, base);
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// ble cr6,0x820839f8
	if (!ctx.cr6.gt) goto loc_820839F8;
loc_8208399C:
	// add r30,r29,r27
	ctx.r30.u64 = ctx.r29.u64 + ctx.r27.u64;
	// lwz r3,10316(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 10316);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8209d948
	ctx.lr = 0x820839AC;
	sub_8209D948(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// rotlwi r8,r10,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// sthx r3,r8,r9
	REX_STORE_U16(ctx.r8.u32 + ctx.r9.u32, ctx.r3.u16);
loc_820839C0:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820839c0
	if (!ctx.cr6.eq) goto loc_820839C0;
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
	// lhz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// sth r10,4(r31)
	REX_STORE_U16(ctx.r31.u32 + 4, ctx.r10.u16);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
	// bne 0x8208399c
	if (!ctx.cr0.eq) goto loc_8208399C;
loc_820839F8:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
