DEFINE_REX_FUNC(sub_82094EF0) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r11,r31,104
	ctx.r11.s64 = ctx.r31.s64 + 104;
	// addi r10,r30,104
	ctx.r10.s64 = ctx.r30.s64 + 104;
	// li r9,5
	ctx.r9.s64 = 5;
	// lhz r8,150(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 150);
	// sth r8,150(r30)
	REX_STORE_U16(ctx.r30.u32 + 150, ctx.r8.u16);
	// lwz r7,92(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// stw r7,92(r30)
	REX_STORE_U32(ctx.r30.u32 + 92, ctx.r7.u32);
	// lwz r6,136(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// stw r6,136(r30)
	REX_STORE_U32(ctx.r30.u32 + 136, ctx.r6.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82094F34:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82094f34
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82094F34;
	// lwz r8,156(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// addi r11,r31,124
	ctx.r11.s64 = ctx.r31.s64 + 124;
	// addi r10,r30,124
	ctx.r10.s64 = ctx.r30.s64 + 124;
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r8,156(r30)
	REX_STORE_U32(ctx.r30.u32 + 156, ctx.r8.u32);
	// lbz r7,102(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 102);
	// stb r7,102(r30)
	REX_STORE_U8(ctx.r30.u32 + 102, ctx.r7.u8);
	// lhz r6,148(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 148);
	// sth r6,148(r30)
	REX_STORE_U16(ctx.r30.u32 + 148, ctx.r6.u16);
	// lhz r5,98(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 98);
	// sth r5,98(r30)
	REX_STORE_U16(ctx.r30.u32 + 98, ctx.r5.u16);
	// lhz r4,96(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 96);
	// sth r4,96(r30)
	REX_STORE_U16(ctx.r30.u32 + 96, ctx.r4.u16);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82094F80:
	// lhz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// sth r9,0(r10)
	REX_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// bdnz 0x82094f80
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82094F80;
	// lfs f0,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 164);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,164(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 164, temp.u32);
	// lhz r11,160(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 160);
	// sth r11,160(r30)
	REX_STORE_U16(ctx.r30.u32 + 160, ctx.r11.u16);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,140(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// bl 0x82094858
	ctx.lr = 0x82094FB4;
	sub_82094858(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,152(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// bl 0x820953c0
	ctx.lr = 0x82094FC0;
	sub_820953C0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82083550
	ctx.lr = 0x82094FCC;
	sub_82083550(ctx, base);
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
