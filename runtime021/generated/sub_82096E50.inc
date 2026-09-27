DEFINE_REX_FUNC(sub_82096E50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r6,-6612(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + -6612);
	// lbz r10,0(r6)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r6.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82096e98
	if (!ctx.cr6.eq) goto loc_82096E98;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-920
	ctx.r3.s64 = ctx.r11.s64 + -920;
	// bl 0x8208c5d8
	ctx.lr = 0x82096E84;
	sub_8208C5D8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// b 0x82096fac
	goto loc_82096FAC;
loc_82096E98:
	// lwz r11,128(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 128);
	// addi r8,r6,124
	ctx.r8.s64 = ctx.r6.s64 + 124;
	// lwz r9,132(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 132);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x82096eb0
	if (!ctx.cr6.gt) goto loc_82096EB0;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82096EB0:
	// lwz r7,4(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r10,8(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
loc_82096EB8:
	// cmplw cr6,r7,r10
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82096ec4
	if (!ctx.cr6.gt) goto loc_82096EC4;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82096EC4:
	// cmplw cr6,r8,r8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x82096ed0
	if (ctx.cr6.eq) goto loc_82096ED0;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82096ED0:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82096f9c
	if (ctx.cr6.eq) goto loc_82096F9C;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82096ee4
	if (ctx.cr6.lt) goto loc_82096EE4;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82096EE4:
	// lhz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r3,r5
	ctx.r3.s64 = ctx.r5.s16;
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// cmpw cr6,r4,r3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, ctx.xer);
	// beq cr6,0x82096f0c
	if (ctx.cr6.eq) goto loc_82096F0C;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82096f04
	if (ctx.cr6.lt) goto loc_82096F04;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82096F04:
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// b 0x82096eb8
	goto loc_82096EB8;
loc_82096F0C:
	// lwz r9,8(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82096f48
	if (ctx.cr6.eq) goto loc_82096F48;
	// addi r10,r11,-12
	ctx.r10.s64 = ctx.r11.s64 + -12;
loc_82096F20:
	// lwz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r7,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r4,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// stw r3,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r3.u32);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82096f20
	if (!ctx.cr6.eq) goto loc_82096F20;
loc_82096F48:
	// lwz r10,8(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// addi r10,r10,-12
	ctx.r10.s64 = ctx.r10.s64 + -12;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lwz r10,4(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// blt cr6,0x82096f9c
	if (ctx.cr6.lt) goto loc_82096F9C;
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// bge cr6,0x82096f9c
	if (!ctx.cr6.lt) goto loc_82096F9C;
	// addi r11,r11,192
	ctx.r11.s64 = ctx.r11.s64 + 192;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82096f90
	if (ctx.cr6.eq) goto loc_82096F90;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820d8370
	ctx.lr = 0x82096F90;
	sub_820D8370(ctx, base);
loc_82096F90:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// b 0x82096fa8
	goto loc_82096FA8;
loc_82096F9C:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
loc_82096FA8:
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82096FAC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
