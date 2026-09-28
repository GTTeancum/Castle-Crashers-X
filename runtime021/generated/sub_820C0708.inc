DEFINE_REX_FUNC(sub_820C0708) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x820C0710;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8214a6e4
	ctx.lr = 0x820C071C;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x820c0730
	if (!ctx.cr6.eq) goto loc_820C0730;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1480(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1480);
	// b 0x820c0738
	goto loc_820C0738;
loc_820C0730:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1484(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1484);
loc_820C0738:
	// lwz r31,0(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r26,r31,16712
	ctx.r26.s64 = ctx.r31.s64 + 16712;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8214a754
	ctx.lr = 0x820C0748;
	__imp__KfAcquireSpinLock(ctx, base);
	// lwz r10,16564(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16564);
	// lwz r11,21556(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21556);
	// rlwinm r29,r30,24,28,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 24) & 0xF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r27,r30,24
	ctx.r27.u64 = ctx.r30.u32 & 0xFF;
	// rlwinm r28,r30,0,0,19
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xFFFFF000;
	// stw r10,16564(r31)
	REX_STORE_U32(ctx.r31.u32 + 16564, ctx.r10.u32);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// bne cr6,0x820c0778
	if (!ctx.cr6.eq) goto loc_820C0778;
	// li r30,60
	ctx.r30.s64 = 60;
loc_820C0778:
	// mftb r11
	ctx.r11.u64 = REX_QUERY_TIMEBASE();
	// lwz r10,16552(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16552);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// subf r24,r10,r11
	ctx.r24.u64 = ctx.r11.u64 - ctx.r10.u64;
	// bl 0x8214a574
	ctx.lr = 0x820C078C;
	__imp__KeQueryPerformanceFrequency(ctx, base);
	// rotlwi r11,r3,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// mulli r10,r24,100
	ctx.r10.s64 = static_cast<int64_t>(ctx.r24.u64 * static_cast<uint64_t>(100));
	// divwu r11,r11,r30
	ctx.r11.u64 = uint32_t(ctx.r30.u32 ? ctx.r11.u32 / ctx.r30.u32 : 0);
	// twllei r30,0
	if (ctx.r30.s32 == 0 || ctx.r30.u32 < 0u) ppc_trap(ctx, base, 0);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r11,r10,r11
	ctx.r11.u64 = uint32_t(ctx.r11.u32 ? ctx.r10.u32 / ctx.r11.u32 : 0);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r7,100
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 100, ctx.xer);
	// ble cr6,0x820c07b4
	if (!ctx.cr6.gt) goto loc_820C07B4;
	// li r7,100
	ctx.r7.s64 = 100;
loc_820C07B4:
	// lwz r8,16556(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 16556);
	// lwz r10,16548(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16548);
	// add r11,r8,r29
	ctx.r11.u64 = ctx.r8.u64 + ctx.r29.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x820c07e0
	if (ctx.cr6.gt) goto loc_820C07E0;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820c07e0
	if (ctx.cr6.eq) goto loc_820C07E0;
	// cmplw cr6,r7,r27
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r27.u32, ctx.xer);
	// ble cr6,0x820c07e0
	if (!ctx.cr6.gt) goto loc_820C07E0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_820C07E0:
	// lwz r9,16540(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 16540);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820c0824
	if (ctx.cr6.eq) goto loc_820C0824;
	// cntlzw r6,r28
	ctx.r6.u64 = ctx.r28.u32 == 0 ? 32 : __builtin_clz(ctx.r28.u32);
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// lwz r5,16564(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 16564);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r6,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r8,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// stw r7,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820C0820;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
loc_820C0824:
	// lwz r10,16548(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16548);
	// stw r11,16556(r31)
	REX_STORE_U32(ctx.r31.u32 + 16556, ctx.r11.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x820c0868
	if (ctx.cr6.eq) goto loc_820C0868;
	// lwz r10,16564(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16564);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// beq cr6,0x820c0868
	if (ctx.cr6.eq) goto loc_820C0868;
	// lwz r10,16704(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16704);
	// rlwinm r10,r10,3,25,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0x78;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// addi r9,r10,16572
	ctx.r9.s64 = ctx.r10.s64 + 16572;
	// stw r11,16576(r10)
	REX_STORE_U32(ctx.r10.u32 + 16576, ctx.r11.u32);
	// stw r28,16572(r10)
	REX_STORE_U32(ctx.r10.u32 + 16572, ctx.r28.u32);
	// lwz r11,16704(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16704);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,16704(r31)
	REX_STORE_U32(ctx.r31.u32 + 16704, ctx.r11.u32);
	// b 0x820c08a4
	goto loc_820C08A4;
loc_820C0868:
	// lwz r11,16568(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16568);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,16568(r31)
	REX_STORE_U32(ctx.r31.u32 + 16568, ctx.r11.u32);
	// beq cr6,0x820c0890
	if (ctx.cr6.eq) goto loc_820C0890;
	// lis r11,32712
	ctx.r11.s64 = 2143813632;
	// stw r28,24848(r11)
	REX_MM_STORE_U32(ctx.r11.u32 + 24848, ctx.r28.u32);
	// eieio 
	// sync 
	// b 0x820c089c
	goto loc_820C089C;
loc_820C0890:
	// lwz r11,10900(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10900);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,4(r11)
	REX_MM_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_820C089C:
	// mftb r11
	ctx.r11.u64 = REX_QUERY_TIMEBASE();
	// stw r11,23376(r31)
	REX_STORE_U32(ctx.r31.u32 + 23376, ctx.r11.u32);
loc_820C08A4:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8214a744
	ctx.lr = 0x820C08B0;
	__imp__KfReleaseSpinLock(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
