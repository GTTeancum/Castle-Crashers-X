DEFINE_REX_FUNC(sub_82088A08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82088A10;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lbz r11,140(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 140);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82088bb8
	if (ctx.cr6.eq) goto loc_82088BB8;
	// lwz r11,156(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 156);
	// li r27,0
	ctx.r27.s64 = 0;
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
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
	// stwx r30,r7,r9
	REX_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r30.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r5,124(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 124);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82088A64;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82088af8
	if (ctx.cr6.eq) goto loc_82088AF8;
	// lhz r11,146(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 146);
	// lhz r10,148(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 148);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// sth r8,146(r30)
	REX_STORE_U16(ctx.r30.u32 + 146, ctx.r8.u16);
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82088ad8
	if (!ctx.cr6.gt) goto loc_82088AD8;
	// lwz r4,104(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 104);
	// li r28,1
	ctx.r28.s64 = 1;
	// addi r29,r30,104
	ctx.r29.s64 = ctx.r30.s64 + 104;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// sth r28,146(r30)
	REX_STORE_U16(ctx.r30.u32 + 146, ctx.r28.u16);
	// beq cr6,0x82088ad8
	if (ctx.cr6.eq) goto loc_82088AD8;
loc_82088AA4:
	// lhz r11,84(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 84);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x82088ac4
	if (ctx.cr6.eq) goto loc_82088AC4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r31,88(r4)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r4.u32 + 88);
	// bl 0x82084d18
	ctx.lr = 0x82088ABC;
	sub_82084D18(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x82088ad0
	goto loc_82088AD0;
loc_82088AC4:
	// lhz r11,144(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 144);
	// sth r11,82(r4)
	REX_STORE_U16(ctx.r4.u32 + 82, ctx.r11.u16);
	// lwz r4,88(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + 88);
loc_82088AD0:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82088aa4
	if (!ctx.cr6.eq) goto loc_82088AA4;
loc_82088AD8:
	// lhz r11,146(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 146);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// sth r11,144(r30)
	REX_STORE_U16(ctx.r30.u32 + 144, ctx.r11.u16);
	// lwz r9,92(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 92);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82088AF8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82088AF8:
	// lwz r31,104(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 104);
	// addi r29,r30,104
	ctx.r29.s64 = ctx.r30.s64 + 104;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82088b90
	if (ctx.cr6.eq) goto loc_82088B90;
	// clrlwi r28,r28,24
	ctx.r28.u64 = ctx.r28.u32 & 0xFF;
loc_82088B0C:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82088b34
	if (ctx.cr6.eq) goto loc_82088B34;
	// lhz r11,144(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 144);
	// lhz r10,82(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 82);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82088b34
	if (ctx.cr6.eq) goto loc_82088B34;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x82084c78
	ctx.lr = 0x82088B30;
	sub_82084C78(ctx, base);
	// b 0x82088b84
	goto loc_82088B84;
loc_82088B34:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// sth r27,82(r31)
	REX_STORE_U16(ctx.r31.u32 + 82, ctx.r27.u16);
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82088B4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82088b84
	if (ctx.cr6.eq) goto loc_82088B84;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,148(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 148);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82088B70;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,84(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 84);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82088B84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82088B84:
	// lwz r31,88(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82088b0c
	if (!ctx.cr6.eq) goto loc_82088B0C;
loc_82088B90:
	// lwz r11,156(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 156);
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
	// stwx r27,r7,r9
	REX_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r27.u32);
	// lwz r11,8248(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8248);
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// stw r6,8248(r9)
	REX_STORE_U32(ctx.r9.u32 + 8248, ctx.r6.u32);
loc_82088BB8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
