DEFINE_REX_FUNC(sub_820D3EF8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r5,r11,6160
	ctx.r5.s64 = ctx.r11.s64 + 6160;
	// lbz r11,262(r5)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r5.u32 + 262);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x820d3fd8
	if (ctx.cr0.eq) goto loc_820D3FD8;
	// lbz r11,23968(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23968);
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820d3fb4
	if (!ctx.cr0.eq) goto loc_820D3FB4;
	// bl 0x820d3b88
	ctx.lr = 0x820D3F28;
	sub_820D3B88(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820d3f38
	if (ctx.cr0.eq) goto loc_820D3F38;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x820d3f40
	goto loc_820D3F40;
loc_820D3F38:
	// lis r6,-32768
	ctx.r6.s64 = -2147483648;
	// ori r6,r6,16389
	ctx.r6.u64 = ctx.r6.u64 | 16389;
loc_820D3F40:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r5,r11,22444
	ctx.r5.s64 = ctx.r11.s64 + 22444;
	// addi r4,r10,22432
	ctx.r4.s64 = ctx.r10.s64 + 22432;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8214a804
	ctx.lr = 0x820D3F58;
	__imp__sprintf(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1488(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1488);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820d3f88
	if (ctx.cr6.eq) goto loc_820D3F88;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d3fd8
	if (ctx.cr6.eq) goto loc_820D3FD8;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d3fd8
	if (ctx.cr6.eq) goto loc_820D3FD8;
	// b 0x820d3fa0
	goto loc_820D3FA0;
loc_820D3F88:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1676(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1676);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d3fd8
	if (ctx.cr6.eq) goto loc_820D3FD8;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
loc_820D3FA0:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,27
	ctx.r3.s64 = 27;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820D3FB0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820d3fd8
	goto loc_820D3FD8;
loc_820D3FB4:
	// lbz r11,260(r5)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r5.u32 + 260);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x820d3fc8
	if (ctx.cr0.eq) goto loc_820D3FC8;
	// bl 0x820d2e58
	ctx.lr = 0x820D3FC4;
	sub_820D2E58(ctx, base);
	// b 0x820d3fd8
	goto loc_820D3FD8;
loc_820D3FC8:
	// lbz r11,261(r5)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r5.u32 + 261);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x820d3fd8
	if (ctx.cr0.eq) goto loc_820D3FD8;
	// bl 0x820d3280
	ctx.lr = 0x820D3FD8;
	sub_820D3280(ctx, base);
loc_820D3FD8:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
