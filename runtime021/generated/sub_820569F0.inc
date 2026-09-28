DEFINE_REX_FUNC(sub_820569F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r6,1
	ctx.r6.s64 = 1;
	// lhz r5,52(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// lhz r4,10(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// bl 0x82053c70
	ctx.lr = 0x82056A28;
	sub_82053C70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82056b14
	if (ctx.cr6.eq) goto loc_82056B14;
	// lhz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82056a8c
	if (ctx.cr6.lt) goto loc_82056A8C;
	// beq cr6,0x82056a6c
	if (ctx.cr6.eq) goto loc_82056A6C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x82056a98
	if (!ctx.cr6.eq) goto loc_82056A98;
	// lhz r11,14(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 14);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82056a64
	if (!ctx.cr6.eq) goto loc_82056A64;
	// li r4,29
	ctx.r4.s64 = 29;
	// b 0x82056a94
	goto loc_82056A94;
loc_82056A64:
	// li r4,28
	ctx.r4.s64 = 28;
	// b 0x82056a94
	goto loc_82056A94;
loc_82056A6C:
	// lhz r11,14(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 14);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82056a84
	if (!ctx.cr6.eq) goto loc_82056A84;
	// li r4,31
	ctx.r4.s64 = 31;
	// b 0x82056a94
	goto loc_82056A94;
loc_82056A84:
	// li r4,30
	ctx.r4.s64 = 30;
	// b 0x82056a94
	goto loc_82056A94;
loc_82056A8C:
	// li r4,27
	ctx.r4.s64 = 27;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82056A94:
	// bl 0x82053bc8
	ctx.lr = 0x82056A98;
	sub_82053BC8(ctx, base);
loc_82056A98:
	// lhz r8,14(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 14);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r7,4
	ctx.r7.s64 = 4;
	// stb r9,20(r31)
	REX_STORE_U8(ctx.r31.u32 + 20, ctx.r9.u8);
	// sth r10,18(r31)
	REX_STORE_U16(ctx.r31.u32 + 18, ctx.r10.u16);
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// sth r7,16(r31)
	REX_STORE_U16(ctx.r31.u32 + 16, ctx.r7.u16);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82056ad0
	if (ctx.cr6.eq) goto loc_82056AD0;
	// lwz r8,48(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r11,2
	ctx.r11.s64 = 2;
	// lwz r7,24(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 24);
	// sth r10,102(r7)
	REX_STORE_U16(ctx.r7.u32 + 102, ctx.r10.u16);
loc_82056AD0:
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r8,48(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r7,2
	ctx.r7.s64 = 2;
	// addi r6,r10,5
	ctx.r6.s64 = ctx.r10.s64 + 5;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r5,r8
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// sth r7,102(r4)
	REX_STORE_U16(ctx.r4.u32 + 102, ctx.r7.u16);
	// lhz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x82056b14
	if (ctx.cr6.eq) goto loc_82056B14;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r10
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// sth r9,102(r6)
	REX_STORE_U16(ctx.r6.u32 + 102, ctx.r9.u16);
loc_82056B14:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
