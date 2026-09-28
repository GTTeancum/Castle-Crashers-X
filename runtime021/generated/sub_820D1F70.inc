DEFINE_REX_FUNC(sub_820D1F70) {
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
	// addi r31,r3,23360
	ctx.r31.s64 = ctx.r3.s64 + 23360;
	// lwz r3,23952(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 23952);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820d1fb8
	if (ctx.cr6.eq) goto loc_820D1FB8;
	// lwz r11,612(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 612);
	// rlwinm. r11,r11,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820d1fb0
	if (!ctx.cr0.eq) goto loc_820D1FB0;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8214a504
	ctx.lr = 0x820D1FAC;
	__imp__MmFreePhysicalMemory(ctx, base);
	// b 0x820d1fb8
	goto loc_820D1FB8;
loc_820D1FB0:
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// bl 0x82136708
	ctx.lr = 0x820D1FB8;
	sub_82136708(ctx, base);
loc_820D1FB8:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r30,-20096
	ctx.r30.s64 = -1317011456;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820d1ff4
	if (ctx.cr6.eq) goto loc_820D1FF4;
	// lwz r11,612(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 612);
	// srawi r11,r11,30
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 30;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x820d1fe8
	if (ctx.cr6.lt) goto loc_820D1FE8;
	// bne cr6,0x820d1ff4
	if (!ctx.cr6.eq) goto loc_820D1FF4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82136708
	ctx.lr = 0x820D1FE4;
	sub_82136708(ctx, base);
	// b 0x820d1ff4
	goto loc_820D1FF4;
loc_820D1FE8:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8214a504
	ctx.lr = 0x820D1FF4;
	__imp__MmFreePhysicalMemory(ctx, base);
loc_820D1FF4:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820d2030
	if (ctx.cr6.eq) goto loc_820D2030;
	// lwz r11,612(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 612);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r11,r11,30
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 30;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x820d2024
	if (ctx.cr6.lt) goto loc_820D2024;
	// bne cr6,0x820d2030
	if (!ctx.cr6.eq) goto loc_820D2030;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82136708
	ctx.lr = 0x820D2020;
	sub_82136708(ctx, base);
	// b 0x820d2030
	goto loc_820D2030;
loc_820D2024:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8214a504
	ctx.lr = 0x820D2030;
	__imp__MmFreePhysicalMemory(ctx, base);
loc_820D2030:
	// li r5,620
	ctx.r5.s64 = 620;
	// lwz r30,616(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 616);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82129fa0
	ctx.lr = 0x820D2044;
	sub_82129FA0(ctx, base);
	// addi r11,r31,20
	ctx.r11.s64 = ctx.r31.s64 + 20;
	// stw r30,616(r31)
	REX_STORE_U32(ctx.r31.u32 + 616, ctx.r30.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r10,41
	ctx.r10.s64 = 41;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820D2058:
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x820d2058
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D2058;
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
