DEFINE_REX_FUNC(sub_82091DF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f4
	ctx.lr = 0x82091DF8;
	__savegprlr_19(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// lbz r11,10345(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 10345);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82091e18
	if (ctx.cr6.eq) goto loc_82091E18;
loc_82091E0C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129944
	__restgprlr_19(ctx, base);
	return;
loc_82091E18:
	// lbz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// addi r31,r4,4
	ctx.r31.s64 = ctx.r4.s64 + 4;
	// lbz r10,1(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 1);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,2(r4)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r4.u32 + 2);
	// lbz r7,3(r4)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r4.u32 + 3);
	// li r5,16
	ctx.r5.s64 = 16;
	// or r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 | ctx.r10.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// rlwinm r11,r6,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r11,r8
	ctx.r10.u64 = ctx.r11.u64 | ctx.r8.u64;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r9,r7
	ctx.r8.u64 = ctx.r9.u64 | ctx.r7.u64;
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lbz r9,82(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r6,81(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r8,83(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// xor r11,r7,r8
	ctx.r11.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// xor r10,r6,r9
	ctx.r10.u64 = ctx.r6.u64 ^ ctx.r9.u64;
	// clrlwi r7,r11,24
	ctx.r7.u64 = ctx.r11.u32 & 0xFF;
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// xor r11,r7,r8
	ctx.r11.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// xor r10,r6,r9
	ctx.r10.u64 = ctx.r6.u64 ^ ctx.r9.u64;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// xor r9,r11,r7
	ctx.r9.u64 = ctx.r11.u64 ^ ctx.r7.u64;
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// xor r8,r10,r6
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r6.u64;
	// stb r10,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r10.u8);
	// stb r9,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r9.u8);
	// stb r8,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r8.u8);
	// lwz r28,80(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82129a70
	ctx.lr = 0x82091EA4;
	sub_82129A70(ctx, base);
	// lbz r3,99(r1)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r1.u32 + 99);
	// lbz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// lbz r8,103(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 103);
	// xor r5,r10,r3
	ctx.r5.u64 = ctx.r10.u64 ^ ctx.r3.u64;
	// lbz r7,98(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 98);
	// lbz r11,97(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 97);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// lbz r6,100(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 100);
	// clrlwi r27,r5,24
	ctx.r27.u64 = ctx.r5.u32 & 0xFF;
	// lbz r4,102(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 102);
	// xor r5,r11,r7
	ctx.r5.u64 = ctx.r11.u64 ^ ctx.r7.u64;
	// lbz r9,107(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 107);
	// xor r11,r6,r10
	ctx.r11.u64 = ctx.r6.u64 ^ ctx.r10.u64;
	// xor r3,r27,r3
	ctx.r3.u64 = ctx.r27.u64 ^ ctx.r3.u64;
	// lwz r21,96(r26)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r26.u32 + 96);
	// clrlwi r25,r11,24
	ctx.r25.u64 = ctx.r11.u32 & 0xFF;
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// stb r11,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r11.u8);
	// lbz r8,101(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 101);
	// lbz r30,104(r1)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r1.u32 + 104);
	// xor r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r4.u64;
	// lbz r29,106(r1)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r1.u32 + 106);
	// xor r6,r30,r9
	ctx.r6.u64 = ctx.r30.u64 ^ ctx.r9.u64;
	// lbz r3,111(r1)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r1.u32 + 111);
	// clrlwi r30,r5,24
	ctx.r30.u64 = ctx.r5.u32 & 0xFF;
	// lbz r22,109(r1)
	ctx.r22.u64 = REX_LOAD_U8(ctx.r1.u32 + 109);
	// clrlwi r24,r8,24
	ctx.r24.u64 = ctx.r8.u32 & 0xFF;
	// clrlwi r23,r6,24
	ctx.r23.u64 = ctx.r6.u32 & 0xFF;
	// xor r6,r25,r10
	ctx.r6.u64 = ctx.r25.u64 ^ ctx.r10.u64;
	// xor r7,r30,r7
	ctx.r7.u64 = ctx.r30.u64 ^ ctx.r7.u64;
	// xor r5,r24,r4
	ctx.r5.u64 = ctx.r24.u64 ^ ctx.r4.u64;
	// xor r4,r23,r9
	ctx.r4.u64 = ctx.r23.u64 ^ ctx.r9.u64;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// lbz r29,108(r1)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r1.u32 + 108);
	// clrlwi r9,r6,24
	ctx.r9.u64 = ctx.r6.u32 & 0xFF;
	// lbz r6,105(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 105);
	// clrlwi r10,r7,24
	ctx.r10.u64 = ctx.r7.u32 & 0xFF;
	// lbz r7,110(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 110);
	// xor r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r8.u64;
	// stb r9,103(r1)
	REX_STORE_U8(ctx.r1.u32 + 103, ctx.r9.u8);
	// xor r29,r29,r3
	ctx.r29.u64 = ctx.r29.u64 ^ ctx.r3.u64;
	// stb r10,98(r1)
	REX_STORE_U8(ctx.r1.u32 + 98, ctx.r10.u8);
	// xor r22,r22,r7
	ctx.r22.u64 = ctx.r22.u64 ^ ctx.r7.u64;
	// clrlwi r20,r6,24
	ctx.r20.u64 = ctx.r6.u32 & 0xFF;
	// clrlwi r29,r29,24
	ctx.r29.u64 = ctx.r29.u32 & 0xFF;
	// clrlwi r22,r22,24
	ctx.r22.u64 = ctx.r22.u32 & 0xFF;
	// xor r6,r20,r8
	ctx.r6.u64 = ctx.r20.u64 ^ ctx.r8.u64;
	// xor r19,r22,r7
	ctx.r19.u64 = ctx.r22.u64 ^ ctx.r7.u64;
	// xor r3,r29,r3
	ctx.r3.u64 = ctx.r29.u64 ^ ctx.r3.u64;
	// clrlwi r8,r5,24
	ctx.r8.u64 = ctx.r5.u32 & 0xFF;
	// clrlwi r7,r4,24
	ctx.r7.u64 = ctx.r4.u32 & 0xFF;
	// clrlwi r6,r6,24
	ctx.r6.u64 = ctx.r6.u32 & 0xFF;
	// stb r8,102(r1)
	REX_STORE_U8(ctx.r1.u32 + 102, ctx.r8.u8);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// stb r7,107(r1)
	REX_STORE_U8(ctx.r1.u32 + 107, ctx.r7.u8);
	// clrlwi r4,r19,24
	ctx.r4.u64 = ctx.r19.u32 & 0xFF;
	// stb r6,106(r1)
	REX_STORE_U8(ctx.r1.u32 + 106, ctx.r6.u8);
	// stb r5,111(r1)
	REX_STORE_U8(ctx.r1.u32 + 111, ctx.r5.u8);
	// xor r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r30.u64;
	// stb r4,110(r1)
	REX_STORE_U8(ctx.r1.u32 + 110, ctx.r4.u8);
	// xor r5,r5,r29
	ctx.r5.u64 = ctx.r5.u64 ^ ctx.r29.u64;
	// xor r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 ^ ctx.r27.u64;
	// stb r10,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r10.u8);
	// xor r9,r9,r25
	ctx.r9.u64 = ctx.r9.u64 ^ ctx.r25.u64;
	// stb r5,108(r1)
	REX_STORE_U8(ctx.r1.u32 + 108, ctx.r5.u8);
	// xor r8,r8,r24
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r24.u64;
	// stb r11,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r11.u8);
	// xor r7,r7,r23
	ctx.r7.u64 = ctx.r7.u64 ^ ctx.r23.u64;
	// stb r9,100(r1)
	REX_STORE_U8(ctx.r1.u32 + 100, ctx.r9.u8);
	// xor r6,r6,r20
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r20.u64;
	// stb r8,101(r1)
	REX_STORE_U8(ctx.r1.u32 + 101, ctx.r8.u8);
	// xor r4,r4,r22
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r22.u64;
	// stb r7,104(r1)
	REX_STORE_U8(ctx.r1.u32 + 104, ctx.r7.u8);
	// stb r6,105(r1)
	REX_STORE_U8(ctx.r1.u32 + 105, ctx.r6.u8);
	// addi r30,r26,80
	ctx.r30.s64 = ctx.r26.s64 + 80;
	// addi r29,r31,16
	ctx.r29.s64 = ctx.r31.s64 + 16;
	// stb r4,109(r1)
	REX_STORE_U8(ctx.r1.u32 + 109, ctx.r4.u8);
	// cmplw cr6,r28,r21
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r21.u32, ctx.xer);
	// bgt cr6,0x82092018
	if (ctx.cr6.gt) goto loc_82092018;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r10,r28,-1
	ctx.r10.s64 = ctx.r28.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82092004
	if (ctx.cr6.eq) goto loc_82092004;
	// lwz r9,8(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// subf r8,r11,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r11.u64;
	// srawi r9,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r8.s32 >> 2;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82092008
	if (ctx.cr6.lt) goto loc_82092008;
loc_82092004:
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82092008:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r11
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82091e0c
	if (!ctx.cr6.eq) goto loc_82091E0C;
loc_82092018:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r3,-6648(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6648);
	// bl 0x8208f930
	ctx.lr = 0x82092024;
	sub_8208F930(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82066ea8
	ctx.lr = 0x82092030;
	sub_82066EA8(ctx, base);
	// clrlwi r10,r29,27
	ctx.r10.u64 = ctx.r29.u32 & 0x1F;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82092054
	if (ctx.cr6.eq) goto loc_82092054;
loc_82092040:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// clrlwi r11,r29,27
	ctx.r11.u64 = ctx.r29.u32 & 0x1F;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82092040
	if (!ctx.cr6.eq) goto loc_82092040;
loc_82092054:
	// lwz r3,72(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 72);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82092068;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// subfic r9,r27,-20
	ctx.xer.ca = ctx.r27.u32 <= 4294967276;
	ctx.r9.u64 = static_cast<uint64_t>(-20) - ctx.r27.u64;
	// add r4,r3,r9
	ctx.r4.u64 = ctx.r3.u64 + ctx.r9.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82095840
	ctx.lr = 0x82092078;
	sub_82095840(ctx, base);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r11,r31,96
	ctx.r11.s64 = ctx.r31.s64 + 96;
	// stw r3,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r7,0(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r6,4(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r5,8(r8)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r11,12(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// stw r7,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r7.u32);
	// stw r6,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r6.u32);
	// stw r5,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r5.u32);
	// stw r11,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// sth r28,80(r31)
	REX_STORE_U16(ctx.r31.u32 + 80, ctx.r28.u16);
	// bl 0x82084448
	ctx.lr = 0x820920B4;
	sub_82084448(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82066ea8
	ctx.lr = 0x820920C0;
	sub_82066EA8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129944
	__restgprlr_19(ctx, base);
	return;
}
