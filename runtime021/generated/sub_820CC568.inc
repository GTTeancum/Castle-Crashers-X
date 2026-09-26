DEFINE_REX_FUNC(sub_820CC568) {
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
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// bne cr6,0x820cc66c
	if (!ctx.cr6.eq) goto loc_820CC66C;
	// lbz r10,10940(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 10940);
	// stw r9,12716(r31)
	REX_STORE_U32(ctx.r31.u32 + 12716, ctx.r9.u32);
	// rlwinm. r11,r10,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820cc658
	if (!ctx.cr0.eq) goto loc_820CC658;
	// rlwinm. r11,r10,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820cc658
	if (!ctx.cr0.eq) goto loc_820CC658;
	// lbz r11,12187(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 12187);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x820cc658
	if (!ctx.cr0.eq) goto loc_820CC658;
	// rlwinm. r11,r10,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820cc5bc
	if (ctx.cr0.eq) goto loc_820CC5BC;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x820cc64c
	goto loc_820CC64C;
loc_820CC5BC:
	// rlwinm. r11,r10,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820cc644
	if (ctx.cr0.eq) goto loc_820CC644;
	// lwz r11,12440(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12440);
	// lwz r8,12728(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 12728);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820cc5dc
	if (ctx.cr6.eq) goto loc_820CC5DC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820cc644
	if (!ctx.cr6.eq) goto loc_820CC644;
loc_820CC5DC:
	// lwz r11,12444(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12444);
	// lwz r8,12732(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 12732);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820cc5f4
	if (ctx.cr6.eq) goto loc_820CC5F4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820cc644
	if (!ctx.cr6.eq) goto loc_820CC644;
loc_820CC5F4:
	// lwz r11,12448(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12448);
	// lwz r8,12736(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 12736);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820cc60c
	if (ctx.cr6.eq) goto loc_820CC60C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820cc644
	if (!ctx.cr6.eq) goto loc_820CC644;
loc_820CC60C:
	// lwz r11,12452(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12452);
	// lwz r8,12740(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 12740);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820cc624
	if (ctx.cr6.eq) goto loc_820CC624;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820cc644
	if (!ctx.cr6.eq) goto loc_820CC644;
loc_820CC624:
	// lwz r11,12456(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12456);
	// lwz r8,12744(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 12744);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820cc63c
	if (ctx.cr6.eq) goto loc_820CC63C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820cc644
	if (!ctx.cr6.eq) goto loc_820CC644;
loc_820CC63C:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x820cc648
	goto loc_820CC648;
loc_820CC644:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_820CC648:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
loc_820CC64C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne 0x820cc65c
	if (!ctx.cr0.eq) goto loc_820CC65C;
loc_820CC658:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_820CC65C:
	// rlwimi r11,r10,0,24,30
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFE) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF01);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,12708(r31)
	REX_STORE_U32(ctx.r31.u32 + 12708, ctx.r10.u32);
	// b 0x820cc680
	goto loc_820CC680;
loc_820CC66C:
	// lbz r11,10940(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10940);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r4,12708(r31)
	REX_STORE_U32(ctx.r31.u32 + 12708, ctx.r4.u32);
	// rlwinm r11,r11,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,12716(r31)
	REX_STORE_U32(ctx.r31.u32 + 12716, ctx.r10.u32);
loc_820CC680:
	// stb r11,10940(r31)
	REX_STORE_U8(ctx.r31.u32 + 10940, ctx.r11.u8);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// stw r9,12712(r31)
	REX_STORE_U32(ctx.r31.u32 + 12712, ctx.r9.u32);
	// stw r4,10932(r31)
	REX_STORE_U32(ctx.r31.u32 + 10932, ctx.r4.u32);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// stw r9,10936(r31)
	REX_STORE_U32(ctx.r31.u32 + 10936, ctx.r9.u32);
	// ble cr6,0x820cc6a8
	if (!ctx.cr6.gt) goto loc_820CC6A8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c7228
	ctx.lr = 0x820CC6A8;
	sub_820C7228(ctx, base);
loc_820CC6A8:
	// lis r11,-16384
	ctx.r11.s64 = -1073741824;
	// ori r11,r11,24576
	ctx.r11.u64 = ctx.r11.u64 | 24576;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// lwz r11,12708(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12708);
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r3.u32);
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
