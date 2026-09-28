DEFINE_REX_FUNC(sub_820C05F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x820C05F8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r31,16712
	ctx.r30.s64 = ctx.r31.s64 + 16712;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a754
	ctx.lr = 0x820C060C;
	__imp__KfAcquireSpinLock(ctx, base);
	// lwz r11,16548(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16548);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,16548(r31)
	REX_STORE_U32(ctx.r31.u32 + 16548, ctx.r11.u32);
	// mftb r11
	ctx.r11.u64 = REX_QUERY_TIMEBASE();
	// lwz r10,16704(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16704);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,16700(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 16700);
	// stw r11,16552(r31)
	REX_STORE_U32(ctx.r31.u32 + 16552, ctx.r11.u32);
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x820c06b0
	if (ctx.cr6.eq) goto loc_820C06B0;
loc_820C0638:
	// lwz r11,16700(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16700);
	// lwz r8,16548(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 16548);
	// rlwinm r11,r11,3,25,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x78;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r10,r11,16572
	ctx.r10.s64 = ctx.r11.s64 + 16572;
	// lwz r10,16576(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16576);
	// lwz r11,16572(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16572);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bgt cr6,0x820c06b0
	if (ctx.cr6.gt) goto loc_820C06B0;
	// lwz r10,16568(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16568);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,16568(r31)
	REX_STORE_U32(ctx.r31.u32 + 16568, ctx.r10.u32);
	// bne cr6,0x820c067c
	if (!ctx.cr6.eq) goto loc_820C067C;
	// lwz r11,10900(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10900);
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// b 0x820c068c
	goto loc_820C068C;
loc_820C067C:
	// lis r10,32712
	ctx.r10.s64 = 2143813632;
	// stw r11,24848(r10)
	REX_MM_STORE_U32(ctx.r10.u32 + 24848, ctx.r11.u32);
	// eieio 
	// sync 
loc_820C068C:
	// mftb r10
	ctx.r10.u64 = REX_QUERY_TIMEBASE();
	// lwz r11,16700(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16700);
	// stw r10,23376(r31)
	REX_STORE_U32(ctx.r31.u32 + 23376, ctx.r10.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,16700(r31)
	REX_STORE_U32(ctx.r31.u32 + 16700, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r10,16704(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16704);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820c0638
	if (!ctx.cr6.eq) goto loc_820C0638;
loc_820C06B0:
	// lwz r11,16544(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16544);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820c06dc
	if (ctx.cr6.eq) goto loc_820C06DC;
	// lwz r10,16568(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16568);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r8,16548(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 16548);
	// stw r9,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820C06DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820C06DC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820b6d48
	ctx.lr = 0x820C06E4;
	sub_820B6D48(ctx, base);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// sradi r11,r11,10
	ctx.xer.ca = (ctx.r11.s64 < 0) & ((ctx.r11.u64 & 0x3FF) != 0);
	ctx.r11.s64 = ctx.r11.s64 >> 10;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,21676(r31)
	REX_STORE_U32(ctx.r31.u32 + 21676, ctx.r11.u32);
	// bl 0x8214a744
	ctx.lr = 0x820C06FC;
	__imp__KfReleaseSpinLock(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
