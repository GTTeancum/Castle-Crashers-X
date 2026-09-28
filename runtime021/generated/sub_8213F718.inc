DEFINE_REX_FUNC(sub_8213F718) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8213F720;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32768
	ctx.r28.s64 = -2147483648;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// ori r28,r28,16389
	ctx.r28.u64 = ctx.r28.u64 | 16389;
	// bl 0x8213f098
	ctx.lr = 0x8213F734;
	sub_8213F098(ctx, base);
	// li r27,0
	ctx.r27.s64 = 0;
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8213f88c
	if (ctx.cr0.eq) goto loc_8213F88C;
	// lwz r29,372(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 372);
	// addi r31,r30,372
	ctx.r31.s64 = ctx.r30.s64 + 372;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8213f888
	if (ctx.cr6.eq) goto loc_8213F888;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// ld r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r30.u32 + 16);
	// ld r9,24(r10)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r10.u32 + 24);
	// cmpld cr6,r9,r11
	ctx.cr6.compare<uint64_t>(ctx.r9.u64, ctx.r11.u64, ctx.xer);
	// beq cr6,0x8213f804
	if (ctx.cr6.eq) goto loc_8213F804;
	// lwz r11,316(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 316);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,316(r30)
	REX_STORE_U32(ctx.r30.u32 + 316, ctx.r11.u32);
	// lwz r11,352(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 352);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8213f880
	if (ctx.cr6.eq) goto loc_8213F880;
	// lwz r31,364(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 364);
	// addi r29,r30,364
	ctx.r29.s64 = ctx.r30.s64 + 364;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8213f8c0
	if (ctx.cr6.eq) goto loc_8213F8C0;
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8213f79c
	if (!ctx.cr6.eq) goto loc_8213F79C;
	// stw r27,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r27.u32);
loc_8213F79C:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r4,r30,340
	ctx.r4.s64 = ctx.r30.s64 + 340;
	// li r5,10
	ctx.r5.s64 = 10;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// stw r27,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x82129a70
	ctx.lr = 0x8213F7BC;
	sub_82129A70(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r11,10
	ctx.r11.s64 = 10;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8213f608
	ctx.lr = 0x8213F7D4;
	sub_8213F608(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bge 0x8213f878
	if (!ctx.cr0.lt) goto loc_8213F878;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r27,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r27.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r31,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r31.u32);
	// bne cr6,0x8213f8a0
	if (!ctx.cr6.eq) goto loc_8213F8A0;
	// stw r31,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
	// b 0x8213f8a0
	goto loc_8213F8A0;
loc_8213F804:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8213f82c
	if (ctx.cr6.eq) goto loc_8213F82C;
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8213f820
	if (!ctx.cr6.eq) goto loc_8213F820;
	// stw r27,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
loc_8213F820:
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stw r27,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r27.u32);
loc_8213F82C:
	// addi r3,r30,340
	ctx.r3.s64 = ctx.r30.s64 + 340;
	// lwz r5,12(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r4,8(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82129a70
	ctx.lr = 0x8213F83C;
	sub_82129A70(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,352(r30)
	REX_STORE_U32(ctx.r30.u32 + 352, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8213f608
	ctx.lr = 0x8213F850;
	sub_8213F608(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bge 0x8213f894
	if (!ctx.cr0.lt) goto loc_8213F894;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8213f8a0
	if (!ctx.cr6.eq) goto loc_8213F8A0;
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// b 0x8213f8a0
	goto loc_8213F8A0;
loc_8213F878:
	// stw r27,352(r30)
	REX_STORE_U32(ctx.r30.u32 + 352, ctx.r27.u32);
	// b 0x8213f8a0
	goto loc_8213F8A0;
loc_8213F880:
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
	// b 0x8213f8a0
	goto loc_8213F8A0;
loc_8213F888:
	// stw r27,72(r30)
	REX_STORE_U32(ctx.r30.u32 + 72, ctx.r27.u32);
loc_8213F88C:
	// std r27,56(r30)
	REX_STORE_U64(ctx.r30.u32 + 56, ctx.r27.u64);
	// b 0x8213f8a0
	goto loc_8213F8A0;
loc_8213F894:
	// ld r11,56(r30)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r30.u32 + 56);
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// std r11,56(r30)
	REX_STORE_U64(ctx.r30.u32 + 56, ctx.r11.u64);
loc_8213F8A0:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// blt cr6,0x8213f8c0
	if (ctx.cr6.lt) goto loc_8213F8C0;
	// ld r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r30.u32 + 16);
	// lwz r10,320(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 320);
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// std r11,16(r30)
	REX_STORE_U64(ctx.r30.u32 + 16, ctx.r11.u64);
	// stw r10,320(r30)
	REX_STORE_U32(ctx.r30.u32 + 320, ctx.r10.u32);
loc_8213F8C0:
	// ld r11,56(r30)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r30.u32 + 56);
	// cmpdi cr6,r11,0
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 0, ctx.xer);
	// ble cr6,0x8213f8d4
	if (!ctx.cr6.gt) goto loc_8213F8D4;
	// addi r11,r11,-20
	ctx.r11.s64 = ctx.r11.s64 + -20;
	// std r11,56(r30)
	REX_STORE_U64(ctx.r30.u32 + 56, ctx.r11.u64);
loc_8213F8D4:
	// lwz r31,380(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 380);
	// addi r29,r30,380
	ctx.r29.s64 = ctx.r30.s64 + 380;
	// b 0x8213f97c
	goto loc_8213F97C;
loc_8213F8E0:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r11,259
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 259, ctx.xer);
	// beq cr6,0x8213f984
	if (ctx.cr6.eq) goto loc_8213F984;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8213f918
	if (ctx.cr6.eq) goto loc_8213F918;
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8213f90c
	if (!ctx.cr6.eq) goto loc_8213F90C;
	// stw r27,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r27.u32);
loc_8213F90C:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// stw r27,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r27.u32);
loc_8213F918:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r27,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r27.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r5,12(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x82136c88
	ctx.lr = 0x8213F954;
	sub_82136C88(ctx, base);
	// stw r27,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// addi r11,r30,364
	ctx.r11.s64 = ctx.r30.s64 + 364;
	// lwz r10,368(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 368);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8213f970
	if (ctx.cr6.eq) goto loc_8213F970;
	// stw r31,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r31.u32);
	// b 0x8213f974
	goto loc_8213F974;
loc_8213F970:
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
loc_8213F974:
	// stw r31,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
	// lwz r31,0(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
loc_8213F97C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8213f8e0
	if (!ctx.cr6.eq) goto loc_8213F8E0;
loc_8213F984:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
