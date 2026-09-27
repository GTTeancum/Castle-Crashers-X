DEFINE_REX_FUNC(sub_8208A688) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8208A690;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// li r28,1
	ctx.r28.s64 = 1;
loc_8208A6A4:
	// lhz r11,146(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 146);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208a6b8
	if (!ctx.cr6.eq) goto loc_8208A6B8;
	// sth r28,146(r31)
	REX_STORE_U16(ctx.r31.u32 + 146, ctx.r28.u16);
	// sth r28,144(r31)
	REX_STORE_U16(ctx.r31.u32 + 144, ctx.r28.u16);
loc_8208A6B8:
	// lwz r11,156(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,156(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// lwz r11,8248(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8248);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r8,r11,1998
	ctx.r8.s64 = ctx.r11.s64 + 1998;
	// stw r11,8248(r9)
	REX_STORE_U32(ctx.r9.u32 + 8248, ctx.r11.u32);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r31,r7,r9
	REX_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r31.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r5,44(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 44);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8208A6F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8208a728
	if (ctx.cr6.eq) goto loc_8208A728;
	// addi r3,r31,108
	ctx.r3.s64 = ctx.r31.s64 + 108;
	// lwz r5,128(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// lhz r4,146(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 146);
	// bl 0x820936b0
	ctx.lr = 0x8208A70C;
	sub_820936B0(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,92(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8208A724;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_8208A728:
	// lwz r11,156(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,156(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// lwz r11,8248(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8248);
	// addi r8,r11,1998
	ctx.r8.s64 = ctx.r11.s64 + 1998;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r7,r9
	REX_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r29.u32);
	// lwz r11,8248(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8248);
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// stw r6,8248(r9)
	REX_STORE_U32(ctx.r9.u32 + 8248, ctx.r6.u32);
	// bne cr6,0x8208a770
	if (!ctx.cr6.eq) goto loc_8208A770;
	// lhz r11,146(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 146);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r10,146(r31)
	REX_STORE_U16(ctx.r31.u32 + 146, ctx.r10.u16);
	// sth r10,144(r31)
	REX_STORE_U16(ctx.r31.u32 + 144, ctx.r10.u16);
	// b 0x8208a6a4
	goto loc_8208A6A4;
loc_8208A770:
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// bne cr6,0x8208a6a4
	if (!ctx.cr6.eq) goto loc_8208A6A4;
	// lhz r11,146(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 146);
	// li r3,1
	ctx.r3.s64 = 1;
	// sth r29,146(r31)
	REX_STORE_U16(ctx.r31.u32 + 146, ctx.r29.u16);
	// addis r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 65536;
	// sth r29,144(r31)
	REX_STORE_U16(ctx.r31.u32 + 144, ctx.r29.u16);
	// stw r29,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r29.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,148(r31)
	REX_STORE_U16(ctx.r31.u32 + 148, ctx.r10.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
