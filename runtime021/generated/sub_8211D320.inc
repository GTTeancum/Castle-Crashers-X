DEFINE_REX_FUNC(sub_8211D320) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8211d37c
	if (ctx.cr6.eq) goto loc_8211D37C;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8211d368
	if (!ctx.cr6.eq) goto loc_8211D368;
	// lwz r11,1148(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1148);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8211d37c
	if (ctx.cr0.eq) goto loc_8211D37C;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,3
	ctx.r10.s64 = 3;
	// stb r11,1145(r3)
	REX_STORE_U8(ctx.r3.u32 + 1145, ctx.r11.u8);
	// stw r10,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// stb r11,1144(r3)
	REX_STORE_U8(ctx.r3.u32 + 1144, ctx.r11.u8);
	// bl 0x8211a3b8
	ctx.lr = 0x8211D364;
	sub_8211A3B8(ctx, base);
	// b 0x8211d37c
	goto loc_8211D37C;
loc_8211D368:
	// lis r11,-32646
	ctx.r11.s64 = -2139488256;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r11,r11,4113
	ctx.r11.u64 = ctx.r11.u64 | 4113;
	// stw r11,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// bl 0x8211c0e8
	ctx.lr = 0x8211D37C;
	sub_8211C0E8(ctx, base);
loc_8211D37C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
