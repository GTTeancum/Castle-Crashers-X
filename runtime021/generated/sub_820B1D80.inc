DEFINE_REX_FUNC(sub_820B1D80) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820B1D88;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r28,1
	ctx.r28.s64 = 1;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// rlwinm r27,r11,5,0,26
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// beq cr6,0x820b1dc4
	if (ctx.cr6.eq) goto loc_820B1DC4;
	// lwz r11,12(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820b1dc4
	if (ctx.cr6.eq) goto loc_820B1DC4;
	// lwz r11,16(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820b1dc4
	if (!ctx.cr6.eq) goto loc_820B1DC4;
	// li r28,0
	ctx.r28.s64 = 0;
loc_820B1DC4:
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820b1fa8
	if (ctx.cr6.eq) goto loc_820B1FA8;
loc_820B1DD0:
	// lwz r11,36(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820b1fa8
	if (ctx.cr6.eq) goto loc_820B1FA8;
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x820b1f9c
	if (ctx.cr6.lt) goto loc_820B1F9C;
	// lwz r10,28(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 28);
	// srawi r6,r10,8
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFF) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 8;
	// cmpw cr6,r6,r27
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r27.s32, ctx.xer);
	// bgt cr6,0x820b1fa8
	if (ctx.cr6.gt) goto loc_820B1FA8;
	// addi r10,r28,3
	ctx.r10.s64 = ctx.r28.s64 + 3;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r29
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r29.u32);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820b1f9c
	if (ctx.cr6.eq) goto loc_820B1F9C;
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r10,65
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 65, ctx.xer);
	// bgt cr6,0x820b1f9c
	if (ctx.cr6.gt) goto loc_820B1F9C;
	// lis r12,-32245
	ctx.r12.s64 = -2113208320;
	// addi r12,r12,7728
	ctx.r12.s64 = ctx.r12.s64 + 7728;
	// rlwinm r0,r10,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r10.u32) {
	case 0:
		goto loc_820B1F38;
	case 1:
		goto loc_820B1F9C;
	case 2:
		goto loc_820B1F9C;
	case 3:
		goto loc_820B1F9C;
	case 4:
		goto loc_820B1F9C;
	case 5:
		goto loc_820B1F9C;
	case 6:
		goto loc_820B1F9C;
	case 7:
		goto loc_820B1F9C;
	case 8:
		goto loc_820B1F9C;
	case 9:
		goto loc_820B1F9C;
	case 10:
		goto loc_820B1F9C;
	case 11:
		goto loc_820B1F9C;
	case 12:
		goto loc_820B1F9C;
	case 13:
		goto loc_820B1F9C;
	case 14:
		goto loc_820B1F9C;
	case 15:
		goto loc_820B1F9C;
	case 16:
		goto loc_820B1F70;
	case 17:
		goto loc_820B1F9C;
	case 18:
		goto loc_820B1F7C;
	case 19:
		goto loc_820B1F9C;
	case 20:
		goto loc_820B1F9C;
	case 21:
		goto loc_820B1F9C;
	case 22:
		goto loc_820B1F9C;
	case 23:
		goto loc_820B1F9C;
	case 24:
		goto loc_820B1F9C;
	case 25:
		goto loc_820B1F9C;
	case 26:
		goto loc_820B1F9C;
	case 27:
		goto loc_820B1F9C;
	case 28:
		goto loc_820B1F9C;
	case 29:
		goto loc_820B1F9C;
	case 30:
		goto loc_820B1F9C;
	case 31:
		goto loc_820B1F9C;
	case 32:
		goto loc_820B1F9C;
	case 33:
		goto loc_820B1F9C;
	case 34:
		goto loc_820B1F9C;
	case 35:
		goto loc_820B1F9C;
	case 36:
		goto loc_820B1F9C;
	case 37:
		goto loc_820B1F9C;
	case 38:
		goto loc_820B1F9C;
	case 39:
		goto loc_820B1F9C;
	case 40:
		goto loc_820B1F9C;
	case 41:
		goto loc_820B1F9C;
	case 42:
		goto loc_820B1F9C;
	case 43:
		goto loc_820B1F9C;
	case 44:
		goto loc_820B1F9C;
	case 45:
		goto loc_820B1F9C;
	case 46:
		goto loc_820B1F9C;
	case 47:
		goto loc_820B1F9C;
	case 48:
		goto loc_820B1F9C;
	case 49:
		goto loc_820B1F9C;
	case 50:
		goto loc_820B1F9C;
	case 51:
		goto loc_820B1F9C;
	case 52:
		goto loc_820B1F9C;
	case 53:
		goto loc_820B1F9C;
	case 54:
		goto loc_820B1F9C;
	case 55:
		goto loc_820B1F9C;
	case 56:
		goto loc_820B1F9C;
	case 57:
		goto loc_820B1F9C;
	case 58:
		goto loc_820B1F9C;
	case 59:
		goto loc_820B1F9C;
	case 60:
		goto loc_820B1F9C;
	case 61:
		goto loc_820B1F9C;
	case 62:
		goto loc_820B1F9C;
	case 63:
		goto loc_820B1F9C;
	case 64:
		goto loc_820B1F64;
	case 65:
		goto loc_820B1F64;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_820B1F38:
	// lwz r10,20(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// srawi r7,r11,8
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r11.s32 >> 8;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x820b1f5c
	if (ctx.cr6.eq) goto loc_820B1F5C;
	// lwz r9,24(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// b 0x820b1f94
	goto loc_820B1F94;
loc_820B1F5C:
	// lwz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// b 0x820b1f94
	goto loc_820B1F94;
loc_820B1F64:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// b 0x820b1f88
	goto loc_820B1F88;
loc_820B1F70:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// b 0x820b1f84
	goto loc_820B1F84;
loc_820B1F7C:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
loc_820B1F84:
	// addi r4,r4,12
	ctx.r4.s64 = ctx.r4.s64 + 12;
loc_820B1F88:
	// srawi r7,r11,8
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r11.s32 >> 8;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820B1F94:
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820B1F9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820B1F9C:
	// lwz r29,36(r29)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x820b1dd0
	if (!ctx.cr6.eq) goto loc_820B1DD0;
loc_820B1FA8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
