DEFINE_REX_FUNC(sub_820A40E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x820A40F0;
	__savegprlr_26(ctx, base);
	// stwu r1,-512(r1)
	ea = -512 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// lwz r31,-6628(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820a413c
	if (!ctx.cr6.eq) goto loc_820A413C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,4960
	ctx.r3.s64 = ctx.r11.s64 + 4960;
	// bl 0x8208c5d8
	ctx.lr = 0x820A4120;
	sub_8208C5D8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r9,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r9.u32);
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_820A413C:
	// li r27,0
	ctx.r27.s64 = 0;
	// stw r30,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r30.u32);
	// addi r8,r1,120
	ctx.r8.s64 = ctx.r1.s64 + 120;
	// stw r27,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r27.u32);
	// addi r7,r1,116
	ctx.r7.s64 = ctx.r1.s64 + 116;
	// stb r27,272(r31)
	REX_STORE_U8(ctx.r31.u32 + 272, ctx.r27.u8);
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82051ce0
	ctx.lr = 0x820A4168;
	sub_82051CE0(ctx, base);
	// lhz r11,2(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 2);
	// li r29,1
	ctx.r29.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r5,r31,20
	ctx.r5.s64 = ctx.r31.s64 + 20;
	// slw r30,r29,r30
	ctx.r30.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r29.u32 << (ctx.r30.u8 & 0x3F));
	// li r11,3
	ctx.r11.s64 = 3;
	// beq cr6,0x820a4188
	if (ctx.cr6.eq) goto loc_820A4188;
	// li r11,2
	ctx.r11.s64 = 2;
loc_820A4188:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,120(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A41A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r3,r9,5020
	ctx.r3.s64 = ctx.r9.s64 + 5020;
	// bl 0x8208c5d8
	ctx.lr = 0x820A41B4;
	sub_8208C5D8(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r4,112(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// addi r11,r31,276
	ctx.r11.s64 = ctx.r31.s64 + 276;
	// addi r31,r1,128
	ctx.r31.s64 = ctx.r1.s64 + 128;
	// lwz r10,116(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// lwz r8,120(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r26,0(r3)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r6,112(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// lwz r11,36(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820A41F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x820a4220
	if (!ctx.cr6.lt) goto loc_820A4220;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,5048
	ctx.r3.s64 = ctx.r11.s64 + 5048;
	// bl 0x8208c5d8
	ctx.lr = 0x820A420C;
	sub_8208C5D8(ctx, base);
	// stw r29,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r29.u32);
	// stw r27,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r27.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_820A4220:
	// stw r27,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r27.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r27,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r27.u32);
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
