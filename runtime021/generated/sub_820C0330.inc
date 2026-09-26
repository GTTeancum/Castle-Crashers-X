DEFINE_REX_FUNC(sub_820C0330) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820C0338;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r10,908(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 908);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820c036c
	if (ctx.cr6.eq) goto loc_820C036C;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820C035C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x820c036c
	if (!ctx.cr0.eq) goto loc_820C036C;
loc_820C0364:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820c0438
	goto loc_820C0438;
loc_820C036C:
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// lwz r28,8(r29)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// add r27,r11,r29
	ctx.r27.u64 = ctx.r11.u64 + ctx.r29.u64;
	// subfic r10,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r10.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// andi. r10,r10,832
	ctx.r10.u64 = ctx.r10.u64 & 832;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x82136670
	ctx.lr = 0x820C039C;
	sub_82136670(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x820c0364
	if (ctx.cr0.eq) goto loc_820C0364;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r5,4(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// std r30,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r30.u64);
	// addi r3,r31,40
	ctx.r3.s64 = ctx.r31.s64 + 40;
	// std r30,8(r31)
	REX_STORE_U64(ctx.r31.u32 + 8, ctx.r30.u64);
	// std r30,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r30.u64);
	// std r30,24(r31)
	REX_STORE_U64(ctx.r31.u32 + 24, ctx.r30.u64);
	// std r30,32(r31)
	REX_STORE_U64(ctx.r31.u32 + 32, ctx.r30.u64);
	// bl 0x82136390
	ctx.lr = 0x820C03CC;
	sub_82136390(ctx, base);
	// lis r4,-19072
	ctx.r4.s64 = -1249902592;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82136670
	ctx.lr = 0x820C03D8;
	sub_82136670(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x820c03f0
	if (!ctx.cr0.eq) goto loc_820C03F0;
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82136708
	ctx.lr = 0x820C03EC;
	sub_82136708(ctx, base);
	// b 0x820c0364
	goto loc_820C0364;
loc_820C03F0:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82129a70
	ctx.lr = 0x820C0400;
	sub_82129A70(ctx, base);
	// std r30,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r30.u64);
	// lis r11,16
	ctx.r11.s64 = 1048576;
	// std r30,8(r31)
	REX_STORE_U64(ctx.r31.u32 + 8, ctx.r30.u64);
	// std r30,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r30.u64);
	// li r10,1
	ctx.r10.s64 = 1;
	// std r30,24(r31)
	REX_STORE_U64(ctx.r31.u32 + 24, ctx.r30.u64);
	// lis r9,-1
	ctx.r9.s64 = -65536;
	// ori r11,r11,7
	ctx.r11.u64 = ctx.r11.u64 | 7;
	// std r30,32(r31)
	REX_STORE_U64(ctx.r31.u32 + 32, ctx.r30.u64);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// stw r29,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r29.u32);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_820C0438:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
