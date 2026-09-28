DEFINE_REX_FUNC(sub_820CC3E8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cc410
	if (ctx.cr6.eq) goto loc_820CC410;
	// bl 0x820bee18
	ctx.lr = 0x820CC410;
	sub_820BEE18(ctx, base);
loc_820CC410:
	// lbz r11,10940(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10940);
	// rlwinm. r11,r11,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820cc52c
	if (!ctx.cr0.eq) goto loc_820CC52C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cb8b8
	ctx.lr = 0x820CC424;
	sub_820CB8B8(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cc434
	if (ctx.cr6.eq) goto loc_820CC434;
	// bl 0x820c74d0
	ctx.lr = 0x820CC434;
	sub_820C74D0(ctx, base);
loc_820CC434:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cc368
	ctx.lr = 0x820CC43C;
	sub_820CC368(ctx, base);
	// bl 0x8214a6e4
	ctx.lr = 0x820CC440;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x820cc450
	if (ctx.cr6.eq) goto loc_820CC450;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d3b58
	ctx.lr = 0x820CC450;
	sub_820D3B58(ctx, base);
loc_820CC450:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cde68
	ctx.lr = 0x820CC458;
	sub_820CDE68(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8214a7f4
	ctx.lr = 0x820CC460;
	__imp__VdSetSystemCommandBufferGpuIdentifierAddress(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cbe40
	ctx.lr = 0x820CC468;
	sub_820CBE40(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820bec50
	ctx.lr = 0x820CC470;
	sub_820BEC50(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d7888
	ctx.lr = 0x820CC478;
	sub_820D7888(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820bfa60
	ctx.lr = 0x820CC480;
	sub_820BFA60(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r11,1676(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1676);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cc4a0
	if (ctx.cr6.eq) goto loc_820CC4A0;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// b 0x820cc4a4
	goto loc_820CC4A4;
loc_820CC4A0:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_820CC4A4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cc4c8
	if (ctx.cr6.eq) goto loc_820CC4C8;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// ble cr6,0x820cc4c0
	if (!ctx.cr6.gt) goto loc_820CC4C0;
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// stw r30,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r30.u32);
loc_820CC4C0:
	// stw r30,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r30.u32);
	// stw r30,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r30.u32);
loc_820CC4C8:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8214a894
	ctx.lr = 0x820CC4D4;
	__imp__VdSetGraphicsInterruptCallback(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c7548
	ctx.lr = 0x820CC4E0;
	sub_820C7548(ctx, base);
	// bl 0x8214a6e4
	ctx.lr = 0x820CC4E4;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x820cc51c
	if (ctx.cr6.eq) goto loc_820CC51C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,2272
	ctx.r3.s64 = ctx.r10.s64 + 2272;
	// lwz r11,1484(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1484);
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
	// bl 0x8214a844
	ctx.lr = 0x820CC508;
	__imp__ExRegisterTitleTerminateNotification(ctx, base);
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,2288
	ctx.r3.s64 = ctx.r11.s64 + 2288;
	// bl 0x8214a844
	ctx.lr = 0x820CC518;
	__imp__ExRegisterTitleTerminateNotification(ctx, base);
	// b 0x820cc528
	goto loc_820CC528;
loc_820CC51C:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1480(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1480);
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_820CC528:
	// bl 0x8214a854
	ctx.lr = 0x820CC52C;
	__imp__VdShutdownEngines(ctx, base);
loc_820CC52C:
	// lwz r3,16728(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16728);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820cc540
	if (ctx.cr6.eq) goto loc_820CC540;
	// lis r4,-20096
	ctx.r4.s64 = -1317011456;
	// bl 0x82136708
	ctx.lr = 0x820CC540;
	sub_82136708(ctx, base);
loc_820CC540:
	// lwz r3,21572(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 21572);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820cc550
	if (ctx.cr6.eq) goto loc_820CC550;
	// bl 0x820cbef0
	ctx.lr = 0x820CC550;
	sub_820CBEF0(ctx, base);
loc_820CC550:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
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
