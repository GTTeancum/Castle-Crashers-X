DEFINE_REX_FUNC(sub_8210E290) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x8210E298;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,-20668
	ctx.r11.s64 = ctx.r11.s64 + -20668;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// bl 0x82116318
	ctx.lr = 0x8210E2CC;
	sub_82116318(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r11,r11,-20608
	ctx.r11.s64 = ctx.r11.s64 + -20608;
	// addi r10,r10,-20660
	ctx.r10.s64 = ctx.r10.s64 + -20660;
	// addi r9,r28,32
	ctx.r9.s64 = ctx.r28.s64 + 32;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r9,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r3,r31,56
	ctx.r3.s64 = ctx.r31.s64 + 56;
	// bl 0x821153d8
	ctx.lr = 0x8210E2F8;
	sub_821153D8(ctx, base);
	// stw r28,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r28.u32);
	// addi r3,r31,104
	ctx.r3.s64 = ctx.r31.s64 + 104;
	// bl 0x8214a424
	ctx.lr = 0x8210E304;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lis r11,-32646
	ctx.r11.s64 = -2139488256;
	// stw r26,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r26.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// ori r11,r11,4107
	ctx.r11.u64 = ctx.r11.u64 | 4107;
	// stw r30,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r30.u32);
	// stw r30,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r30.u32);
	// stw r11,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// addi r11,r31,160
	ctx.r11.s64 = ctx.r31.s64 + 160;
	// stw r30,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r30.u32);
	// stw r30,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
	// stw r27,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r27.u32);
	// beq cr6,0x8210e348
	if (ctx.cr6.eq) goto loc_8210E348;
	// lhz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r29.u32 + 0);
	// sth r10,160(r31)
	REX_STORE_U16(ctx.r31.u32 + 160, ctx.r10.u16);
	// lhz r11,2(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 2);
	// sth r11,162(r31)
	REX_STORE_U16(ctx.r31.u32 + 162, ctx.r11.u16);
	// b 0x8210e354
	goto loc_8210E354;
loc_8210E348:
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r10,160(r31)
	REX_STORE_U16(ctx.r31.u32 + 160, ctx.r10.u16);
	// sth r10,162(r31)
	REX_STORE_U16(ctx.r31.u32 + 162, ctx.r10.u16);
loc_8210E354:
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r30,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r30.u32);
	// li r5,512
	ctx.r5.s64 = 512;
	// stw r30,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
	// addi r3,r31,176
	ctx.r3.s64 = ctx.r31.s64 + 176;
	// bl 0x82129fa0
	ctx.lr = 0x8210E374;
	sub_82129FA0(ctx, base);
	// addi r11,r31,712
	ctx.r11.s64 = ctx.r31.s64 + 712;
	// addi r10,r31,720
	ctx.r10.s64 = ctx.r31.s64 + 720;
	// stw r30,688(r31)
	REX_STORE_U32(ctx.r31.u32 + 688, ctx.r30.u32);
	// stw r30,692(r31)
	REX_STORE_U32(ctx.r31.u32 + 692, ctx.r30.u32);
	// addi r9,r31,728
	ctx.r9.s64 = ctx.r31.s64 + 728;
	// stw r30,696(r31)
	REX_STORE_U32(ctx.r31.u32 + 696, ctx.r30.u32);
	// li r5,68
	ctx.r5.s64 = 68;
	// stw r30,700(r31)
	REX_STORE_U32(ctx.r31.u32 + 700, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,704(r31)
	REX_STORE_U32(ctx.r31.u32 + 704, ctx.r30.u32);
	// addi r3,r31,740
	ctx.r3.s64 = ctx.r31.s64 + 740;
	// stw r30,708(r31)
	REX_STORE_U32(ctx.r31.u32 + 708, ctx.r30.u32);
	// stw r11,712(r31)
	REX_STORE_U32(ctx.r31.u32 + 712, ctx.r11.u32);
	// stw r11,716(r31)
	REX_STORE_U32(ctx.r31.u32 + 716, ctx.r11.u32);
	// stw r10,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r10.u32);
	// stw r10,724(r31)
	REX_STORE_U32(ctx.r31.u32 + 724, ctx.r10.u32);
	// stw r9,728(r31)
	REX_STORE_U32(ctx.r31.u32 + 728, ctx.r9.u32);
	// stw r9,732(r31)
	REX_STORE_U32(ctx.r31.u32 + 732, ctx.r9.u32);
	// stw r30,736(r31)
	REX_STORE_U32(ctx.r31.u32 + 736, ctx.r30.u32);
	// bl 0x82129fa0
	ctx.lr = 0x8210E3C4;
	sub_82129FA0(ctx, base);
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// stw r30,820(r31)
	REX_STORE_U32(ctx.r31.u32 + 820, ctx.r30.u32);
	// stw r30,808(r31)
	REX_STORE_U32(ctx.r31.u32 + 808, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,812(r31)
	REX_STORE_U32(ctx.r31.u32 + 812, ctx.r30.u32);
	// stw r30,816(r31)
	REX_STORE_U32(ctx.r31.u32 + 816, ctx.r30.u32);
	// lwz r11,30100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 30100);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,20,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 20) & 0x2000000;
	// xoris r11,r11,512
	ctx.r11.u64 = ctx.r11.u64 ^ 33554432;
	// stw r11,820(r31)
	REX_STORE_U32(ctx.r31.u32 + 820, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
