DEFINE_REX_FUNC(sub_821208B8) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x821208C0;
	__savegprlr_29(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r30,1
	ctx.r30.s64 = 1;
	// li r29,3
	ctx.r29.s64 = 3;
	// li r3,26
	ctx.r3.s64 = 26;
	// sth r6,5(r11)
	REX_STORE_U16(ctx.r11.u32 + 5, ctx.r6.u16);
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// sth r7,7(r11)
	REX_STORE_U16(ctx.r11.u32 + 7, ctx.r7.u16);
	// addi r7,r11,25
	ctx.r7.s64 = ctx.r11.s64 + 25;
	// stw r8,21(r11)
	REX_STORE_U32(ctx.r11.u32 + 21, ctx.r8.u32);
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
	// stw r31,17(r11)
	REX_STORE_U32(ctx.r11.u32 + 17, ctx.r31.u32);
	// stb r31,25(r11)
	REX_STORE_U8(ctx.r11.u32 + 25, ctx.r31.u8);
	// sth r5,3(r11)
	REX_STORE_U16(ctx.r11.u32 + 3, ctx.r5.u16);
	// stb r30,2(r11)
	REX_STORE_U8(ctx.r11.u32 + 2, ctx.r30.u8);
	// stw r4,13(r11)
	REX_STORE_U32(ctx.r11.u32 + 13, ctx.r4.u32);
	// stw r29,9(r11)
	REX_STORE_U32(ctx.r11.u32 + 9, ctx.r29.u32);
	// addi r11,r11,26
	ctx.r11.s64 = ctx.r11.s64 + 26;
loc_82120908:
	// lhz r5,0(r9)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r9.u32 + 0);
	// cmplwi r5,0
	ctx.cr0.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq 0x82120934
	if (ctx.cr0.eq) goto loc_82120934;
	// lbz r5,0(r7)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// slw r4,r30,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r8.u8 & 0x3F));
	// or r5,r4,r5
	ctx.r5.u64 = ctx.r4.u64 | ctx.r5.u64;
	// addi r3,r3,2
	ctx.r3.s64 = ctx.r3.s64 + 2;
	// stb r5,0(r7)
	REX_STORE_U8(ctx.r7.u32 + 0, ctx.r5.u8);
	// lhz r5,0(r9)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r9.u32 + 0);
	// sth r5,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r5.u16);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
loc_82120934:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// cmplwi cr6,r8,2
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 2, ctx.xer);
	// blt cr6,0x82120908
	if (ctx.cr6.lt) goto loc_82120908;
	// add r11,r3,r10
	ctx.r11.u64 = ctx.r3.u64 + ctx.r10.u64;
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// sth r11,0(r6)
	REX_STORE_U16(ctx.r6.u32 + 0, ctx.r11.u16);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
