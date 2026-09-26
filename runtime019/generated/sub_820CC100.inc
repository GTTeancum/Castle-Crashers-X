DEFINE_REX_FUNC(sub_820CC100) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r3,r31,14944
	ctx.r3.s64 = ctx.r31.s64 + 14944;
	// bl 0x8214a424
	ctx.lr = 0x820CC124;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// addi r3,r31,14972
	ctx.r3.s64 = ctx.r31.s64 + 14972;
	// bl 0x8214a424
	ctx.lr = 0x820CC12C;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lbz r11,10942(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10942);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// stb r11,10942(r31)
	REX_STORE_U8(ctx.r31.u32 + 10942, ctx.r11.u8);
	// bl 0x820cbff0
	ctx.lr = 0x820CC140;
	sub_820CBFF0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x820cc150
	if (!ctx.cr0.eq) goto loc_820CC150;
loc_820CC148:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820cc2fc
	goto loc_820CC2FC;
loc_820CC150:
	// bl 0x8214a6e4
	ctx.lr = 0x820CC154;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x820cc168
	if (ctx.cr6.eq) goto loc_820CC168;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1484(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1484);
	// b 0x820cc170
	goto loc_820CC170;
loc_820CC168:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1480(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1480);
loc_820CC170:
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// sth r11,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r11.u16);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r31,16716
	ctx.r5.s64 = ctx.r31.s64 + 16716;
	// li r4,10
	ctx.r4.s64 = 10;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x8214a554
	ctx.lr = 0x820CC194;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820cc148
	if (ctx.cr0.lt) goto loc_820CC148;
	// addi r4,r30,72
	ctx.r4.s64 = ctx.r30.s64 + 72;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c7548
	ctx.lr = 0x820CC1A8;
	sub_820C7548(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x820cc148
	if (!ctx.cr0.eq) goto loc_820CC148;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820beac8
	ctx.lr = 0x820CC1B8;
	sub_820BEAC8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820cc148
	if (ctx.cr0.eq) goto loc_820CC148;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d7708
	ctx.lr = 0x820CC1C8;
	sub_820D7708(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820cc148
	if (ctx.cr0.eq) goto loc_820CC148;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820bf930
	ctx.lr = 0x820CC1D8;
	sub_820BF930(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820cc148
	if (ctx.cr0.eq) goto loc_820CC148;
	// li r11,-1
	ctx.r11.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,21560(r31)
	REX_STORE_U32(ctx.r31.u32 + 21560, ctx.r11.u32);
	// stw r11,21564(r31)
	REX_STORE_U32(ctx.r31.u32 + 21564, ctx.r11.u32);
	// bl 0x820d7920
	ctx.lr = 0x820CC1F4;
	sub_820D7920(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cbbf0
	ctx.lr = 0x820CC200;
	sub_820CBBF0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820cc148
	if (ctx.cr0.eq) goto loc_820CC148;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cb988
	ctx.lr = 0x820CC210;
	sub_820CB988(ctx, base);
	// lis r4,-20096
	ctx.r4.s64 = -1317011456;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82136708
	ctx.lr = 0x820CC21C;
	sub_82136708(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1676(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1676);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cc238
	if (ctx.cr6.eq) goto loc_820CC238;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// b 0x820cc23c
	goto loc_820CC23C;
loc_820CC238:
	// li r11,0
	ctx.r11.s64 = 0;
loc_820CC23C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cc270
	if (ctx.cr6.eq) goto loc_820CC270;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// ble cr6,0x820cc260
	if (!ctx.cr6.gt) goto loc_820CC260;
	// addi r10,r31,16720
	ctx.r10.s64 = ctx.r31.s64 + 16720;
	// addi r9,r31,16724
	ctx.r9.s64 = ctx.r31.s64 + 16724;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r9,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
loc_820CC260:
	// addi r10,r31,16560
	ctx.r10.s64 = ctx.r31.s64 + 16560;
	// addi r9,r31,21576
	ctx.r9.s64 = ctx.r31.s64 + 21576;
	// stw r10,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// stw r9,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r9.u32);
loc_820CC270:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c7228
	ctx.lr = 0x820CC278;
	sub_820C7228(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x820b6d10
	ctx.lr = 0x820CC280;
	sub_820B6D10(ctx, base);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,9540(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stfs f13,21588(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 21588, temp.u32);
	// fdivs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// stfs f0,21592(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 21592, temp.u32);
	// bl 0x820cdd68
	ctx.lr = 0x820CC2A8;
	sub_820CDD68(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d19e8
	ctx.lr = 0x820CC2B8;
	sub_820D19E8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820bde48
	ctx.lr = 0x820CC2C4;
	sub_820BDE48(ctx, base);
	// lis r30,-32221
	ctx.r30.s64 = -2111635456;
	// lwz r11,928(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 928);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820cc2e4
	if (!ctx.cr6.eq) goto loc_820CC2E4;
	// bl 0x8214a8b4
	ctx.lr = 0x820CC2D8;
	__imp__VdIsHSIOTrainingSucceeded(ctx, base);
	// cntlzw r11,r3
	ctx.r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// stw r11,928(r30)
	REX_STORE_U32(ctx.r30.u32 + 928, ctx.r11.u32);
loc_820CC2E4:
	// bl 0x8214a6e4
	ctx.lr = 0x820CC2E8;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x820cc2f8
	if (ctx.cr6.eq) goto loc_820CC2F8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d1c08
	ctx.lr = 0x820CC2F8;
	sub_820D1C08(ctx, base);
loc_820CC2F8:
	// li r3,1
	ctx.r3.s64 = 1;
loc_820CC2FC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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
