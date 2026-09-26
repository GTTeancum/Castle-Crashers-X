DEFINE_REX_FUNC(sub_820CBF48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x820cbfbc
	if (ctx.cr6.eq) goto loc_820CBFBC;
	// lwz r11,64(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 64);
	// li r10,0
	ctx.r10.s64 = 0;
	// clrlwi r11,r11,26
	ctx.r11.u64 = ctx.r11.u32 & 0x3F;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// beq cr6,0x820cbf80
	if (ctx.cr6.eq) goto loc_820CBF80;
	// cmplwi cr6,r11,54
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 54, ctx.xer);
	// bne cr6,0x820cbf84
	if (!ctx.cr6.eq) goto loc_820CBF84;
loc_820CBF80:
	// lis r10,2048
	ctx.r10.s64 = 134217728;
loc_820CBF84:
	// lwz r11,68(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 68);
	// lis r9,16384
	ctx.r9.s64 = 1073741824;
	// lwz r8,0(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// rlwimi r9,r11,28,2,3
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0x30000000) | (ctx.r9.u64 & 0xFFFFFFFFCFFFFFFF);
	// cmplwi cr6,r8,720
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 720, ctx.xer);
	// or r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 | ctx.r10.u64;
	// bne cr6,0x820cbfb8
	if (!ctx.cr6.eq) goto loc_820CBFB8;
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,480
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 480, ctx.xer);
	// beq cr6,0x820cbfb4
	if (ctx.cr6.eq) goto loc_820CBFB4;
	// cmplwi cr6,r11,576
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 576, ctx.xer);
	// bne cr6,0x820cbfb8
	if (!ctx.cr6.eq) goto loc_820CBFB8;
loc_820CBFB4:
	// ori r3,r3,2
	ctx.r3.u64 = ctx.r3.u64 | 2;
loc_820CBFB8:
	// bl 0x8214a884
	ctx.lr = 0x820CBFBC;
	__imp__VdSetDisplayMode(ctx, base);
loc_820CBFBC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8214a874
	ctx.lr = 0x820CBFC4;
	__imp__VdGetCurrentDisplayInformation(ctx, base);
	// lhz r11,152(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 152);
	// lhz r10,154(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 154);
	// lhz r9,166(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 166);
	// stw r11,21544(r31)
	REX_STORE_U32(ctx.r31.u32 + 21544, ctx.r11.u32);
	// stw r10,21548(r31)
	REX_STORE_U32(ctx.r31.u32 + 21548, ctx.r10.u32);
	// stw r9,21552(r31)
	REX_STORE_U32(ctx.r31.u32 + 21552, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
