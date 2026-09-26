DEFINE_REX_FUNC(sub_820CF858) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x821368c0
	ctx.lr = 0x820CF874;
	sub_821368C0(ctx, base);
	// rlwinm. r11,r3,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820cf884
	if (ctx.cr0.eq) goto loc_820CF884;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cd258
	ctx.lr = 0x820CF884;
	sub_820CD258(ctx, base);
loc_820CF884:
	// li r5,60
	ctx.r5.s64 = 60;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x82129fa0
	ctx.lr = 0x820CF894;
	sub_82129FA0(ctx, base);
	// lbz r11,10943(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10943);
	// lis r30,-32256
	ctx.r30.s64 = -2113929216;
	// lwz r9,16560(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 16560);
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// stw r31,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r31.u32);
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// stb r11,10943(r31)
	REX_STORE_U8(ctx.r31.u32 + 10943, ctx.r11.u8);
	// lis r11,-32243
	ctx.r11.s64 = -2113077248;
	// addi r8,r8,-9336
	ctx.r8.s64 = ctx.r8.s64 + -9336;
	// lwz r10,1676(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 1676);
	// addi r11,r11,-12536
	ctx.r11.s64 = ctx.r11.s64 + -12536;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// li r9,7645
	ctx.r9.s64 = 7645;
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// stw r8,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// stw r11,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r11.u32);
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// stw r9,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r11,r5,-4848
	ctx.r11.s64 = ctx.r5.s64 + -4848;
	// addi r8,r7,-14432
	ctx.r8.s64 = ctx.r7.s64 + -14432;
	// stw r4,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// addi r9,r6,-14296
	ctx.r9.s64 = ctx.r6.s64 + -14296;
	// stw r11,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r11.u32);
	// stw r8,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r8.u32);
	// stw r9,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cf930
	if (ctx.cr6.eq) goto loc_820CF930;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,82
	ctx.r3.s64 = 82;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CF928;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,1676(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 1676);
	// b 0x820cf934
	goto loc_820CF934;
loc_820CF930:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820CF934:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820cf98c
	if (!ctx.cr6.eq) goto loc_820CF98C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1488(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1488);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820cf96c
	if (ctx.cr6.eq) goto loc_820CF96C;
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cf98c
	if (ctx.cr6.eq) goto loc_820CF98C;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cf98c
	if (ctx.cr6.eq) goto loc_820CF98C;
	// b 0x820cf97c
	goto loc_820CF97C;
loc_820CF96C:
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cf98c
	if (ctx.cr6.eq) goto loc_820CF98C;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
loc_820CF97C:
	// lwz r4,16560(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 16560);
	// li r3,46
	ctx.r3.s64 = 46;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CF98C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CF98C:
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lbz r10,10943(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 10943);
	// lwz r9,21536(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 21536);
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r8,124(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// andi. r10,r10,253
	ctx.r10.u64 = ctx.r10.u64 & 253;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwimi r9,r11,30,1,1
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x40000000) | (ctx.r9.u64 & 0xFFFFFFFFBFFFFFFF);
	// stb r10,10943(r31)
	REX_STORE_U8(ctx.r31.u32 + 10943, ctx.r10.u8);
	// stw r8,21540(r31)
	REX_STORE_U32(ctx.r31.u32 + 21540, ctx.r8.u32);
	// stw r9,21536(r31)
	REX_STORE_U32(ctx.r31.u32 + 21536, ctx.r9.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
