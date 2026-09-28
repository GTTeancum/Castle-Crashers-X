DEFINE_REX_FUNC(sub_8212BC08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-2816(r1)
	ea = -2816 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32235
	ctx.r31.s64 = -2112552960;
	// lwz r11,31268(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 31268);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212bc30
	if (ctx.cr0.eq) goto loc_8212BC30;
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x8212c368
	ctx.lr = 0x8212BC30;
	sub_8212C368(ctx, base);
loc_8212BC30:
	// bl 0x821321b8
	ctx.lr = 0x8212BC34;
	sub_821321B8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8212bc44
	if (ctx.cr0.eq) goto loc_8212BC44;
	// li r3,22
	ctx.r3.s64 = 22;
	// bl 0x821321d0
	ctx.lr = 0x8212BC44;
	sub_821321D0(ctx, base);
loc_8212BC44:
	// lwz r11,31268(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 31268);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212bcb0
	if (ctx.cr0.eq) goto loc_8212BCB0;
	// li r5,2624
	ctx.r5.s64 = 2624;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82129fa0
	ctx.lr = 0x8212BC60;
	sub_82129FA0(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,10
	ctx.r10.s64 = 10;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8212BC70:
	// std r9,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r9.u64);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// bdnz 0x8212bc70
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212BC70;
	// lwz r10,2808(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 2808);
	// lis r11,16384
	ctx.r11.s64 = 1073741824;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// ori r11,r11,21
	ctx.r11.u64 = ctx.r11.u64 | 21;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// stw r10,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x820b5df0
	ctx.lr = 0x8212BCA8;
	sub_820B5DF0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820b5ec0
	ctx.lr = 0x8212BCB0;
	sub_820B5EC0(ctx, base);
loc_8212BCB0:
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x8212a260
	ctx.lr = 0x8212BCB8;
	sub_8212A260(ctx, base);
}
