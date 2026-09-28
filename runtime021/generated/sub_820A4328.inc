DEFINE_REX_FUNC(sub_820A4328) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820A4330;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r31,1
	ctx.r31.s64 = 1;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r27,-32218
	ctx.r27.s64 = -2111438848;
loc_820A4348:
	// lwz r11,36(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// and r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 & ctx.r31.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a43c8
	if (ctx.cr6.eq) goto loc_820A43C8;
	// lwz r11,-6632(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -6632);
	// lwzx r3,r30,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// lbz r10,884(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 884);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820a43c8
	if (!ctx.cr6.eq) goto loc_820A43C8;
	// bl 0x82078d90
	ctx.lr = 0x820A4370;
	sub_82078D90(ctx, base);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a4394
	if (ctx.cr6.eq) goto loc_820A4394;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A4390;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820a4398
	goto loc_820A4398;
loc_820A4394:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820A4398:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a43c8
	if (ctx.cr6.eq) goto loc_820A43C8;
	// lwz r11,104(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 104);
	// and r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 & ctx.r31.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a43c8
	if (ctx.cr6.eq) goto loc_820A43C8;
	// lwz r11,108(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 108);
	// and r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 & ctx.r31.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a43c8
	if (ctx.cr6.eq) goto loc_820A43C8;
	// or r28,r31,r28
	ctx.r28.u64 = ctx.r31.u64 | ctx.r28.u64;
loc_820A43C8:
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// rotlwi r31,r31,1
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r31.u32, 1);
	// cmplwi cr6,r30,16
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 16, ctx.xer);
	// blt cr6,0x820a4348
	if (ctx.cr6.lt) goto loc_820A4348;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
