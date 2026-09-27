DEFINE_REX_FUNC(sub_8207DEB8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8207DEC0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,156(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// addi r31,r11,10372
	ctx.r31.s64 = ctx.r11.s64 + 10372;
	// lwz r11,15396(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 15396);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,5024(r31)
	REX_STORE_U32(ctx.r31.u32 + 5024, ctx.r11.u32);
	// lwzx r30,r9,r31
	ctx.r30.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// and r7,r8,r12
	ctx.r7.u64 = ctx.r8.u64 & ctx.r12.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x8207df3c
	if (ctx.cr6.eq) goto loc_8207DF3C;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lhz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207df3c
	if (ctx.cr6.eq) goto loc_8207DF3C;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8207df30
	if (!ctx.cr6.eq) goto loc_8207DF30;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207DF30;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8207DF30:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x82066ea8
	ctx.lr = 0x8207DF3C;
	sub_82066EA8(ctx, base);
loc_8207DF3C:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// lwz r10,5024(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 5024);
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,76(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwzx r28,r9,r31
	ctx.r28.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// lwz r11,156(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 156);
	// addi r31,r11,10372
	ctx.r31.s64 = ctx.r11.s64 + 10372;
	// lwz r11,15396(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 15396);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,5024(r31)
	REX_STORE_U32(ctx.r31.u32 + 5024, ctx.r11.u32);
	// lwzx r30,r7,r31
	ctx.r30.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r31.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// and r5,r6,r12
	ctx.r5.u64 = ctx.r6.u64 & ctx.r12.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x8207dfbc
	if (ctx.cr6.eq) goto loc_8207DFBC;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lhz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207dfbc
	if (ctx.cr6.eq) goto loc_8207DFBC;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8207dfb0
	if (!ctx.cr6.eq) goto loc_8207DFB0;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207DFB0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8207DFB0:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x82066ea8
	ctx.lr = 0x8207DFBC;
	sub_82066EA8(ctx, base);
loc_8207DFBC:
	// lwz r11,5024(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 5024);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r10,r31
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82082890
	ctx.lr = 0x8207DFD0;
	sub_82082890(ctx, base);
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwz r8,76(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r11,156(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 156);
	// lwz r10,10180(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 10180);
	// addi r7,r10,2513
	ctx.r7.s64 = ctx.r10.s64 + 2513;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r6,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8207e008
	if (ctx.cr6.eq) goto loc_8207E008;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x8208c2a0
	ctx.lr = 0x8207E004;
	sub_8208C2A0(ctx, base);
	// b 0x8207e028
	goto loc_8207E028;
loc_8207E008:
	// lwz r10,8248(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8248);
	// addi r10,r10,1998
	ctx.r10.s64 = ctx.r10.s64 + 1998;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,16(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8207E028;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8207E028:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,8(r28)
	REX_STORE_U8(ctx.r28.u32 + 8, ctx.r11.u8);
	// stw r11,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r11.u32);
	// stb r11,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r11.u8);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
