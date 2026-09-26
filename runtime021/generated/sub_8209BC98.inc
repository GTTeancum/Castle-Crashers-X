DEFINE_REX_FUNC(sub_8209BC98) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8209BCA0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r6,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r6.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8209bcd0
	if (ctx.cr6.eq) goto loc_8209BCD0;
	// bl 0x820b6190
	ctx.lr = 0x8209BCCC;
	sub_820B6190(ctx, base);
	// stw r27,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
loc_8209BCD0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8209bd2c
	if (!ctx.cr6.eq) goto loc_8209BD2C;
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r28,1
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 1, ctx.xer);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// addi r3,r11,-1
	ctx.r3.s64 = ctx.r11.s64 + -1;
	// beq cr6,0x8209bd04
	if (ctx.cr6.eq) goto loc_8209BD04;
	// cmpwi cr6,r28,2
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 2, ctx.xer);
	// beq cr6,0x8209bcfc
	if (ctx.cr6.eq) goto loc_8209BCFC;
	// bl 0x82128f70
	ctx.lr = 0x8209BCF8;
	sub_82128F70(ctx, base);
	// b 0x8209bd14
	goto loc_8209BD14;
loc_8209BCFC:
	// li r6,1028
	ctx.r6.s64 = 1028;
	// b 0x8209bd08
	goto loc_8209BD08;
loc_8209BD04:
	// li r6,4
	ctx.r6.s64 = 4;
loc_8209BD08:
	// li r5,4096
	ctx.r5.s64 = 4096;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x820b6108
	ctx.lr = 0x8209BD14;
	sub_820B6108(ctx, base);
loc_8209BD14:
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8209bd28
	if (!ctx.cr6.eq) goto loc_8209BD28;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8209BD28:
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
loc_8209BD2C:
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r29,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stb r9,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r9.u8);
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// andc r11,r7,r8
	ctx.r11.u64 = ctx.r7.u64 & ~ctx.r8.u64;
	// add r6,r11,r29
	ctx.r6.u64 = ctx.r11.u64 + ctx.r29.u64;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r6,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r6.u32);
	// beq cr6,0x8209bdcc
	if (ctx.cr6.eq) goto loc_8209BDCC;
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// addi r3,r31,36
	ctx.r3.s64 = ctx.r31.s64 + 36;
	// stw r27,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r27.u32);
	// li r5,1024
	ctx.r5.s64 = 1024;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r27,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r27.u32);
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// stw r27,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r27.u32);
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r8,16(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// addi r6,r11,15
	ctx.r6.s64 = ctx.r11.s64 + 15;
	// andc r11,r6,r7
	ctx.r11.u64 = ctx.r6.u64 & ~ctx.r7.u64;
	// subf r10,r11,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r11.u64;
	// stw r10,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// bl 0x82129fa0
	ctx.lr = 0x8209BDAC;
	sub_82129FA0(ctx, base);
	// li r5,636
	ctx.r5.s64 = 636;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,1060
	ctx.r3.s64 = ctx.r31.s64 + 1060;
	// bl 0x82129fa0
	ctx.lr = 0x8209BDBC;
	sub_82129FA0(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r27,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r27.u32);
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r11,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
loc_8209BDCC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
