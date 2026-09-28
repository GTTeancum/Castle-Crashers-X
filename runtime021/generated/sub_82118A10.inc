DEFINE_REX_FUNC(sub_82118A10) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82118A18;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r10,r31,280
	ctx.r10.s64 = ctx.r31.s64 + 280;
	// stw r29,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// stw r29,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// lwz r11,280(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82118a44
	if (!ctx.cr6.eq) goto loc_82118A44;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// b 0x82118a64
	goto loc_82118A64;
loc_82118A44:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
loc_82118A64:
	// addi r10,r11,-8
	ctx.r10.s64 = ctx.r11.s64 + -8;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r10,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r10.u32);
	// lwz r5,36(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r4,32(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// bl 0x82120960
	ctx.lr = 0x82118A7C;
	sub_82120960(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r8,12(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r11,34
	ctx.r11.s64 = 34;
	// lwz r7,288(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r11,200(r31)
	REX_STORE_U32(ctx.r31.u32 + 200, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r9,204(r31)
	REX_STORE_U32(ctx.r31.u32 + 204, ctx.r9.u32);
	// addi r4,r31,230
	ctx.r4.s64 = ctx.r31.s64 + 230;
	// stw r10,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r10.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r8,212(r31)
	REX_STORE_U32(ctx.r31.u32 + 212, ctx.r8.u32);
	// addi r30,r31,200
	ctx.r30.s64 = ctx.r31.s64 + 200;
	// lwz r11,20(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 20);
	// stw r11,216(r31)
	REX_STORE_U32(ctx.r31.u32 + 216, ctx.r11.u32);
	// lhz r11,18(r7)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r7.u32 + 18);
	// sth r11,220(r31)
	REX_STORE_U16(ctx.r31.u32 + 220, ctx.r11.u16);
	// bl 0x821209a0
	ctx.lr = 0x82118AC4;
	sub_821209A0(ctx, base);
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82118ad8
	if (!ctx.cr6.eq) goto loc_82118AD8;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82118AD8:
	// stw r11,222(r31)
	REX_STORE_U32(ctx.r31.u32 + 222, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,226(r31)
	REX_STORE_U32(ctx.r31.u32 + 226, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
