DEFINE_REX_FUNC(sub_82120A28) {
	REX_FUNC_PROLOGUE();
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r30,3
	ctx.r30.s64 = 3;
	// li r3,34
	ctx.r3.s64 = 34;
	// sth r7,5(r11)
	REX_STORE_U16(ctx.r11.u32 + 5, ctx.r7.u16);
	// li r7,2
	ctx.r7.s64 = 2;
	// sth r8,7(r11)
	REX_STORE_U16(ctx.r11.u32 + 7, ctx.r8.u16);
	// addi r8,r11,33
	ctx.r8.s64 = ctx.r11.s64 + 33;
	// stb r7,2(r11)
	REX_STORE_U8(ctx.r11.u32 + 2, ctx.r7.u8);
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// stw r9,29(r11)
	REX_STORE_U32(ctx.r11.u32 + 29, ctx.r9.u32);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// sth r6,3(r11)
	REX_STORE_U16(ctx.r11.u32 + 3, ctx.r6.u16);
	// stw r4,9(r11)
	REX_STORE_U32(ctx.r11.u32 + 9, ctx.r4.u32);
	// stw r5,13(r11)
	REX_STORE_U32(ctx.r11.u32 + 13, ctx.r5.u32);
	// stw r31,17(r11)
	REX_STORE_U32(ctx.r11.u32 + 17, ctx.r31.u32);
	// stw r31,21(r11)
	REX_STORE_U32(ctx.r11.u32 + 21, ctx.r31.u32);
	// stw r30,25(r11)
	REX_STORE_U32(ctx.r11.u32 + 25, ctx.r30.u32);
	// stb r31,33(r11)
	REX_STORE_U8(ctx.r11.u32 + 33, ctx.r31.u8);
	// addi r11,r11,34
	ctx.r11.s64 = ctx.r11.s64 + 34;
loc_82120A80:
	// lhz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq 0x82120ab0
	if (ctx.cr0.eq) goto loc_82120AB0;
	// li r6,1
	ctx.r6.s64 = 1;
	// lbz r5,0(r8)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// addi r3,r3,2
	ctx.r3.s64 = ctx.r3.s64 + 2;
	// slw r6,r6,r9
	ctx.r6.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r9.u8 & 0x3F));
	// or r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stb r6,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r6.u8);
	// lhz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// sth r6,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r6.u16);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
loc_82120AB0:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// blt cr6,0x82120a80
	if (ctx.cr6.lt) goto loc_82120A80;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// sth r11,0(r7)
	REX_STORE_U16(ctx.r7.u32 + 0, ctx.r11.u16);
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}
