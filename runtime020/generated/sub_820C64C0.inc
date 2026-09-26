DEFINE_REX_FUNC(sub_820C64C0) {
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
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// lbz r11,10941(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10941);
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820c64ec
	if (ctx.cr0.eq) goto loc_820C64EC;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820c6594
	goto loc_820C6594;
loc_820C64EC:
	// lwz r3,13516(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 13516);
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// bne cr6,0x820c6514
	if (!ctx.cr6.eq) goto loc_820C6514;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c6290
	ctx.lr = 0x820C6510;
	sub_820C6290(ctx, base);
	// b 0x820c6530
	goto loc_820C6530;
loc_820C6514:
	// lwz r11,152(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 152);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820c652c
	if (ctx.cr6.eq) goto loc_820C652C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c7988
	ctx.lr = 0x820C6528;
	sub_820C7988(ctx, base);
	// b 0x820c6530
	goto loc_820C6530;
loc_820C652C:
	// bl 0x820c7bf8
	ctx.lr = 0x820C6530;
	sub_820C7BF8(ctx, base);
loc_820C6530:
	// lwz r11,14932(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14932);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,14936(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 14936);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,14932(r31)
	REX_STORE_U32(ctx.r31.u32 + 14932, ctx.r11.u32);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x820c6580
	if (!ctx.cr6.gt) goto loc_820C6580;
	// lwz r11,13232(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 13232);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820c6580
	if (!ctx.cr6.eq) goto loc_820C6580;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r10,14924(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 14924);
	// lwz r9,14904(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 14904);
	// addi r8,r11,160
	ctx.r8.s64 = ctx.r11.s64 + 160;
	// stw r8,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r8.u32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// beq cr6,0x820c6580
	if (ctx.cr6.eq) goto loc_820C6580;
	// lwz r11,14908(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14908);
	// stw r11,14916(r31)
	REX_STORE_U32(ctx.r31.u32 + 14916, ctx.r11.u32);
loc_820C6580:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820c6594
	if (!ctx.cr6.eq) goto loc_820C6594;
	// lbz r11,10941(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10941);
	// ori r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 32;
	// stb r11,10941(r31)
	REX_STORE_U8(ctx.r31.u32 + 10941, ctx.r11.u8);
loc_820C6594:
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
