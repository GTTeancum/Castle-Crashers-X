DEFINE_REX_FUNC(sub_820C2B70) {
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
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x820c2c80
	if (!ctx.cr6.eq) goto loc_820C2C80;
	// lwz r7,12440(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 12440);
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// cmplwi r7,0
	ctx.cr0.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne 0x820c2b9c
	if (!ctx.cr0.eq) goto loc_820C2B9C;
	// lwz r11,12456(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12456);
loc_820C2B9C:
	// lwz r9,36(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// li r5,0
	ctx.r5.s64 = 0;
	// lbz r11,10940(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 10940);
	// rlwinm r10,r9,14,18,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 14) & 0x3FFF;
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// rlwinm r9,r9,29,17,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x7FFF;
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm. r31,r11,0,27,27
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// beq 0x820c2bd8
	if (ctx.cr0.eq) goto loc_820C2BD8;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x820c2c64
	goto loc_820C2C64;
loc_820C2BD8:
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820c2c5c
	if (ctx.cr0.eq) goto loc_820C2C5C;
	// lwz r11,12728(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12728);
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x820c2bf4
	if (ctx.cr6.eq) goto loc_820C2BF4;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x820c2c5c
	if (!ctx.cr6.eq) goto loc_820C2C5C;
loc_820C2BF4:
	// lwz r11,12444(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12444);
	// lwz r10,12732(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12732);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820c2c0c
	if (ctx.cr6.eq) goto loc_820C2C0C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820c2c5c
	if (!ctx.cr6.eq) goto loc_820C2C5C;
loc_820C2C0C:
	// lwz r11,12448(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12448);
	// lwz r10,12736(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12736);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820c2c24
	if (ctx.cr6.eq) goto loc_820C2C24;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820c2c5c
	if (!ctx.cr6.eq) goto loc_820C2C5C;
loc_820C2C24:
	// lwz r11,12452(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12452);
	// lwz r10,12740(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12740);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820c2c3c
	if (ctx.cr6.eq) goto loc_820C2C3C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820c2c5c
	if (!ctx.cr6.eq) goto loc_820C2C5C;
loc_820C2C3C:
	// lwz r11,12456(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12456);
	// lwz r10,12744(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12744);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820c2c54
	if (ctx.cr6.eq) goto loc_820C2C54;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820c2c5c
	if (!ctx.cr6.eq) goto loc_820C2C5C;
loc_820C2C54:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x820c2c60
	goto loc_820C2C60;
loc_820C2C5C:
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
loc_820C2C60:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
loc_820C2C64:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820c2c7c
	if (ctx.cr0.eq) goto loc_820C2C7C;
	// lwz r11,13180(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 13180);
	// lwz r10,13184(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 13184);
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r10,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
loc_820C2C7C:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
loc_820C2C80:
	// bl 0x820c24c0
	ctx.lr = 0x820C2C84;
	sub_820C24C0(ctx, base);
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
