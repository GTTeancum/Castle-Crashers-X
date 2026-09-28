DEFINE_REX_FUNC(sub_82085858) {
	REX_FUNC_PROLOGUE();
	// lwz r10,92(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 92);
	// addic. r11,r3,96
	ctx.xer.ca = ctx.r3.u32 > 4294967199;
	ctx.r11.s64 = ctx.r3.s64 + 96;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,92(r4)
	REX_STORE_U32(ctx.r4.u32 + 92, ctx.r10.u32);
	// beq 0x8208588c
	if (ctx.cr0.eq) goto loc_8208588C;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r4,96
	ctx.r10.s64 = ctx.r4.s64 + 96;
	// stw r9,96(r4)
	REX_STORE_U32(ctx.r4.u32 + 96, ctx.r9.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r8,100(r4)
	REX_STORE_U32(ctx.r4.u32 + 100, ctx.r8.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r7,104(r4)
	REX_STORE_U32(ctx.r4.u32 + 104, ctx.r7.u32);
	// lwz r6,12(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r6,108(r4)
	REX_STORE_U32(ctx.r4.u32 + 108, ctx.r6.u32);
loc_8208588C:
	// b 0x82083550
	sub_82083550(ctx, base);
	return;
}
