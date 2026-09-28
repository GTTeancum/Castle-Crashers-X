DEFINE_REX_FUNC(sub_820A3050) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820A3058;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r31,-6628(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a3174
	if (ctx.cr6.eq) goto loc_820A3174;
	// lbz r11,180(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 180);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a3174
	if (ctx.cr6.eq) goto loc_820A3174;
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820a3098
	if (ctx.cr6.eq) goto loc_820A3098;
	// bl 0x820a7400
	ctx.lr = 0x820A3094;
	sub_820A7400(ctx, base);
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
loc_820A3098:
	// lwz r11,184(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// bl 0x820a4328
	ctx.lr = 0x820A30AC;
	sub_820A4328(ctx, base);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// li r28,1
	ctx.r28.s64 = 1;
	// lwz r9,184(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// addi r5,r31,20
	ctx.r5.s64 = ctx.r31.s64 + 20;
	// lwz r8,12(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r6,4
	ctx.r6.s64 = 4;
	// slw r7,r28,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r9.u8 & 0x3F));
	// or r4,r3,r7
	ctx.r4.u64 = ctx.r3.u64 | ctx.r7.u64;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// stw r4,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r4.u32);
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r10,120(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A30EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// stw r30,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,120(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 120);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820A3110;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r5,120(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// addi r6,r31,188
	ctx.r6.s64 = ctx.r31.s64 + 188;
	// lwz r4,112(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820A3130;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stb r30,180(r31)
	REX_STORE_U8(ctx.r31.u32 + 180, ctx.r30.u8);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x820a3160
	if (!ctx.cr6.lt) goto loc_820A3160;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,4040
	ctx.r3.s64 = ctx.r11.s64 + 4040;
	// bl 0x8208c5d8
	ctx.lr = 0x820A314C;
	sub_8208C5D8(ctx, base);
	// stw r28,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r28.u32);
	// stw r30,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820A3160:
	// stw r30,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r30,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r30.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820A3174:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,3988
	ctx.r3.s64 = ctx.r11.s64 + 3988;
	// bl 0x8208c5d8
	ctx.lr = 0x820A3180;
	sub_8208C5D8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r9,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r9.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
