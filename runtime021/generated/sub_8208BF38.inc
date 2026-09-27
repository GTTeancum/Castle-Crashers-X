DEFINE_REX_FUNC(sub_8208BF38) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8208bfa8
	if (ctx.cr6.eq) goto loc_8208BFA8;
	// lis r12,7
	ctx.r12.s64 = 458752;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// and r10,r11,r12
	ctx.r10.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8208bfa8
	if (ctx.cr6.eq) goto loc_8208BFA8;
	// lhz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208bfa8
	if (ctx.cr6.eq) goto loc_8208BFA8;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8208bf9c
	if (!ctx.cr6.eq) goto loc_8208BF9C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8208BF9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8208BF9C:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82066ea8
	ctx.lr = 0x8208BFA8;
	sub_82066EA8(ctx, base);
loc_8208BFA8:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// beq cr6,0x8208c004
	if (ctx.cr6.eq) goto loc_8208C004;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// bgt cr6,0x8208c064
	if (ctx.cr6.gt) goto loc_8208C064;
	// beq cr6,0x8208c04c
	if (ctx.cr6.eq) goto loc_8208C04C;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x8208c028
	if (ctx.cr6.gt) goto loc_8208C028;
	// beq cr6,0x8208c010
	if (ctx.cr6.eq) goto loc_8208C010;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8208c004
	if (ctx.cr6.eq) goto loc_8208C004;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x8208c0a8
	if (ctx.cr6.eq) goto loc_8208C0A8;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8208c098
	if (!ctx.cr6.eq) goto loc_8208C098;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82082670
	ctx.lr = 0x8208BFFC;
	sub_82082670(ctx, base);
	// stb r3,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r3.u8);
	// b 0x8208c0f0
	goto loc_8208C0F0;
loc_8208C004:
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// b 0x8208c0f0
	goto loc_8208C0F0;
loc_8208C010:
	// li r11,4
	ctx.r11.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bl 0x82082bb0
	ctx.lr = 0x8208C020;
	sub_82082BB0(ctx, base);
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// b 0x8208c0f0
	goto loc_8208C0F0;
loc_8208C028:
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// beq cr6,0x8208c04c
	if (ctx.cr6.eq) goto loc_8208C04C;
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// bne cr6,0x8208c098
	if (!ctx.cr6.eq) goto loc_8208C098;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82082700
	ctx.lr = 0x8208C044;
	sub_82082700(ctx, base);
	// stfs f1,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// b 0x8208c0f0
	goto loc_8208C0F0;
loc_8208C04C:
	// li r11,8
	ctx.r11.s64 = 8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bl 0x82082890
	ctx.lr = 0x8208C05C;
	sub_82082890(ctx, base);
	// sth r3,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r3.u16);
	// b 0x8208c0f0
	goto loc_8208C0F0;
loc_8208C064:
	// cmpwi cr6,r11,1024
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1024, ctx.xer);
	// bgt cr6,0x8208c088
	if (ctx.cr6.gt) goto loc_8208C088;
	// beq cr6,0x8208c0a8
	if (ctx.cr6.eq) goto loc_8208C0A8;
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// beq cr6,0x8208c0a8
	if (ctx.cr6.eq) goto loc_8208C0A8;
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// beq cr6,0x8208c0a8
	if (ctx.cr6.eq) goto loc_8208C0A8;
	// cmpwi cr6,r11,512
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 512, ctx.xer);
	// b 0x8208c094
	goto loc_8208C094;
loc_8208C088:
	// cmpwi cr6,r11,16384
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16384, ctx.xer);
	// beq cr6,0x8208c0a8
	if (ctx.cr6.eq) goto loc_8208C0A8;
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
loc_8208C094:
	// beq cr6,0x8208c0a8
	if (ctx.cr6.eq) goto loc_8208C0A8;
loc_8208C098:
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// b 0x8208c0f4
	goto loc_8208C0F4;
loc_8208C0A8:
	// lis r12,7
	ctx.r12.s64 = 458752;
	// li r11,1
	ctx.r11.s64 = 1;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// and r9,r11,r12
	ctx.r9.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8208c0e0
	if (!ctx.cr6.eq) goto loc_8208C0E0;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8208c0e4
	if (ctx.cr6.eq) goto loc_8208C0E4;
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// beq cr6,0x8208c0e0
	if (ctx.cr6.eq) goto loc_8208C0E0;
	// cmplwi cr6,r11,8192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8192, ctx.xer);
	// bne cr6,0x8208c0e4
	if (!ctx.cr6.eq) goto loc_8208C0E4;
loc_8208C0E0:
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
loc_8208C0E4:
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82066ea8
	ctx.lr = 0x8208C0F0;
	sub_82066EA8(ctx, base);
loc_8208C0F0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8208C0F4:
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
