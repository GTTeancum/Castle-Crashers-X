DEFINE_REX_FUNC(sub_82098F50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82098F58;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r29,15
	ctx.r29.s64 = 15;
	// stw r31,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r29,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r29.u32);
	// li r5,18
	ctx.r5.s64 = 18;
	// stb r31,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// addi r4,r11,-6960
	ctx.r4.s64 = ctx.r11.s64 + -6960;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82053380
	ctx.lr = 0x82098F84;
	sub_82053380(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r29,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r29.u32);
	// addi r30,r11,9412
	ctx.r30.s64 = ctx.r11.s64 + 9412;
	// stw r31,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r31.u32);
	// addi r9,r10,9132
	ctx.r9.s64 = ctx.r10.s64 + 9132;
	// stb r31,124(r1)
	REX_STORE_U8(ctx.r1.u32 + 124, ctx.r31.u8);
	// stw r30,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r30.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r9,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x82052fa0
	ctx.lr = 0x82098FBC;
	sub_82052FA0(ctx, base);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r8,r10,9412
	ctx.r8.s64 = ctx.r10.s64 + 9412;
	// stw r8,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// lwz r10,23208(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 23208);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82098fe8
	if (ctx.cr6.eq) goto loc_82098FE8;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82098FE8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82098FE8:
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82098FFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82127468
	ctx.lr = 0x82099004;
	sub_82127468(ctx, base);
	// lwz r11,144(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// stw r30,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r30.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82099024
	if (ctx.cr6.lt) goto loc_82099024;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// lwz r4,124(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x82084ac8
	ctx.lr = 0x82099024;
	sub_82084AC8(ctx, base);
loc_82099024:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// stw r29,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r29.u32);
	// addi r9,r10,9388
	ctx.r9.s64 = ctx.r10.s64 + 9388;
	// stw r31,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r31.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// stb r31,124(r1)
	REX_STORE_U8(ctx.r1.u32 + 124, ctx.r31.u8);
	// stw r9,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// blt cr6,0x82099058
	if (ctx.cr6.lt) goto loc_82099058;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82084ac8
	ctx.lr = 0x82099058;
	sub_82084AC8(ctx, base);
loc_82099058:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
