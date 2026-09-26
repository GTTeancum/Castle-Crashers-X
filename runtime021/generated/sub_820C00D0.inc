DEFINE_REX_FUNC(sub_820C00D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820C00D8;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// std r27,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r27.u64);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// std r27,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r27.u64);
	// lhz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 0);
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
	// b 0x820c0128
	goto loc_820C0128;
loc_820C0104:
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820c0110
	if (ctx.cr6.gt) goto loc_820C0110;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
loc_820C0110:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// li r8,255
	ctx.r8.s64 = 255;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// stbx r8,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r8.u8);
	// lhz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
loc_820C0128:
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// bne cr6,0x820c0104
	if (!ctx.cr6.eq) goto loc_820C0104;
	// mulli r11,r30,12
	ctx.r11.s64 = static_cast<int64_t>(ctx.r30.u64 * static_cast<uint64_t>(12));
	// addi r5,r11,56
	ctx.r5.s64 = ctx.r11.s64 + 56;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82129fa0
	ctx.lr = 0x820C0144;
	sub_82129FA0(ctx, base);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// lis r9,16
	ctx.r9.s64 = 1048576;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// ori r9,r9,5
	ctx.r9.u64 = ctx.r9.u64 | 5;
	// stw r28,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r28.u32);
	// lis r7,-1
	ctx.r7.s64 = -65536;
	// stw r8,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stw r7,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// stw r27,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r27.u32);
	// std r11,32(r31)
	REX_STORE_U64(ctx.r31.u32 + 32, ctx.r11.u64);
	// std r10,40(r31)
	REX_STORE_U64(ctx.r31.u32 + 40, ctx.r10.u64);
	// beq cr6,0x820c01b4
	if (ctx.cr6.eq) goto loc_820C01B4;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// addi r10,r31,52
	ctx.r10.s64 = ctx.r31.s64 + 52;
loc_820C018C:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// bne 0x820c018c
	if (!ctx.cr0.eq) goto loc_820C018C;
loc_820C01B4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
