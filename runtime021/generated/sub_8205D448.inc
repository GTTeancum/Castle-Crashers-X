DEFINE_REX_FUNC(sub_8205D448) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,15
	ctx.r5.s64 = 15;
	// lhz r4,10(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// bl 0x82053c70
	ctx.lr = 0x8205D480;
	sub_82053C70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8205d590
	if (ctx.cr6.eq) goto loc_8205D590;
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053bc8
	ctx.lr = 0x8205D498;
	sub_82053BC8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8205d4b8
	if (ctx.cr6.eq) goto loc_8205D4B8;
	// lhz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x8205d4c0
	goto loc_8205D4C0;
loc_8205D4B8:
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r11,0
	ctx.r11.s64 = 0;
loc_8205D4C0:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8205d590
	if (ctx.cr6.eq) goto loc_8205D590;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// blt cr6,0x8205d550
	if (ctx.cr6.lt) goto loc_8205D550;
	// beq cr6,0x8205d518
	if (ctx.cr6.eq) goto loc_8205D518;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bne cr6,0x8205d588
	if (!ctx.cr6.eq) goto loc_8205D588;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lis r9,30583
	ctx.r9.s64 = 2004287488;
	// li r6,2
	ctx.r6.s64 = 2;
	// ori r7,r9,30719
	ctx.r7.u64 = ctx.r9.u64 | 30719;
	// lis r8,-1
	ctx.r8.s64 = -65536;
	// lhz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// ori r5,r8,255
	ctx.r5.u64 = ctx.r8.u64 | 255;
	// addi r4,r11,5
	ctx.r4.s64 = ctx.r11.s64 + 5;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r3,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// stw r7,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
	// sth r6,8(r10)
	REX_STORE_U16(ctx.r10.u32 + 8, ctx.r6.u16);
	// lwz r10,28(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// b 0x8205d584
	goto loc_8205D584;
loc_8205D518:
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lis r9,30583
	ctx.r9.s64 = 2004287488;
	// li r6,3
	ctx.r6.s64 = 3;
	// ori r7,r9,30719
	ctx.r7.u64 = ctx.r9.u64 | 30719;
	// lis r8,-1
	ctx.r8.s64 = -65536;
	// lhz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// ori r5,r8,255
	ctx.r5.u64 = ctx.r8.u64 | 255;
	// addi r4,r11,5
	ctx.r4.s64 = ctx.r11.s64 + 5;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r3,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// stw r7,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
	// sth r6,8(r10)
	REX_STORE_U16(ctx.r10.u32 + 8, ctx.r6.u16);
	// lwz r10,32(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// b 0x8205d584
	goto loc_8205D584;
loc_8205D550:
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lis r9,30583
	ctx.r9.s64 = 2004287488;
	// li r8,1
	ctx.r8.s64 = 1;
	// ori r7,r9,30719
	ctx.r7.u64 = ctx.r9.u64 | 30719;
	// lis r6,-1
	ctx.r6.s64 = -65536;
	// lhz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// ori r5,r6,255
	ctx.r5.u64 = ctx.r6.u64 | 255;
	// addi r4,r11,5
	ctx.r4.s64 = ctx.r11.s64 + 5;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r3,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// stw r7,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
	// sth r8,8(r10)
	REX_STORE_U16(ctx.r10.u32 + 8, ctx.r8.u16);
	// lwz r10,24(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
loc_8205D584:
	// stw r5,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r5.u32);
loc_8205D588:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820606d8
	ctx.lr = 0x8205D590;
	sub_820606D8(ctx, base);
loc_8205D590:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
