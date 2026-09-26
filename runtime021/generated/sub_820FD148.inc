DEFINE_REX_FUNC(sub_820FD148) {
	REX_FUNC_PROLOGUE();
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r10,r3,312
	ctx.r10.s64 = ctx.r3.s64 + 312;
	// addi r8,r4,264
	ctx.r8.s64 = ctx.r4.s64 + 264;
	// addi r11,r3,200
	ctx.r11.s64 = ctx.r3.s64 + 200;
	// addi r9,r4,104
	ctx.r9.s64 = ctx.r4.s64 + 104;
	// li r7,4
	ctx.r7.s64 = 4;
loc_820FD160:
	// ld r5,0(r9)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r9.u32 + 0);
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ld r6,64(r9)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r9.u32 + 64);
	// ld r31,-32(r11)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r11.u32 + -32);
	// add r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 + ctx.r5.u64;
	// ld r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// add r6,r6,r31
	ctx.r6.u64 = ctx.r6.u64 + ctx.r31.u64;
	// std r6,-32(r11)
	REX_STORE_U64(ctx.r11.u32 + -32, ctx.r6.u64);
	// ld r31,32(r9)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r9.u32 + 32);
	// ld r6,96(r9)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r9.u32 + 96);
	// add r6,r6,r31
	ctx.r6.u64 = ctx.r6.u64 + ctx.r31.u64;
	// add r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 + ctx.r5.u64;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// std r6,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r6.u64);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// lwz r31,-16(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + -16);
	// lwz r5,0(r8)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r6,32(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 32);
	// add r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 + ctx.r5.u64;
	// lwz r5,0(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// add r6,r6,r31
	ctx.r6.u64 = ctx.r6.u64 + ctx.r31.u64;
	// stw r6,-16(r10)
	REX_STORE_U32(ctx.r10.u32 + -16, ctx.r6.u32);
	// lwz r6,48(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 48);
	// lwz r31,16(r8)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// add r6,r6,r31
	ctx.r6.u64 = ctx.r6.u64 + ctx.r31.u64;
	// add r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 + ctx.r5.u64;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// stw r6,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x820fd160
	if (!ctx.cr0.eq) goto loc_820FD160;
	// ld r9,232(r4)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r4.u32 + 232);
	// ld r11,248(r4)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r4.u32 + 248);
	// ld r10,248(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 248);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// ld r8,256(r3)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r3.u32 + 256);
	// lwz r9,336(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 336);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,340(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 340);
	// std r11,248(r3)
	REX_STORE_U64(ctx.r3.u32 + 248, ctx.r11.u64);
	// ld r11,256(r4)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r4.u32 + 256);
	// ld r7,240(r4)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r4.u32 + 240);
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// std r11,256(r3)
	REX_STORE_U64(ctx.r3.u32 + 256, ctx.r11.u64);
	// lwz r8,328(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 328);
	// lwz r11,336(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 336);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r11,336(r3)
	REX_STORE_U32(ctx.r3.u32 + 336, ctx.r11.u32);
	// lwz r11,340(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 340);
	// lwz r9,332(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 332);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,340(r3)
	REX_STORE_U32(ctx.r3.u32 + 340, ctx.r11.u32);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}
