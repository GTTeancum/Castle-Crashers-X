DEFINE_REX_FUNC(sub_8211AB48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8211AB50;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8211acdc
	if (!ctx.cr6.eq) goto loc_8211ACDC;
	// lwz r3,416(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 416);
	// bl 0x821180d8
	ctx.lr = 0x8211AB6C;
	sub_821180D8(ctx, base);
	// lhz r10,1042(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 1042);
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r30,416(r31)
	REX_STORE_U32(ctx.r31.u32 + 416, ctx.r30.u32);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// sth r10,1042(r31)
	REX_STORE_U16(ctx.r31.u32 + 1042, ctx.r10.u16);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// lwz r29,420(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 420);
	// lwz r10,1148(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1148);
	// stw r30,420(r31)
	REX_STORE_U32(ctx.r31.u32 + 420, ctx.r30.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// rlwinm. r10,r10,0,5,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8211ac30
	if (ctx.cr0.eq) goto loc_8211AC30;
	// li r28,1
	ctx.r28.s64 = 1;
	// stw r28,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// beq cr6,0x8211abe8
	if (ctx.cr6.eq) goto loc_8211ABE8;
	// stw r30,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r30,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// lwz r5,44(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 44);
	// lwz r4,40(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 40);
	// bl 0x82120af0
	ctx.lr = 0x8211ABC4;
	sub_82120AF0(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82120b30
	ctx.lr = 0x8211ABD4;
	sub_82120B30(ctx, base);
	// lwz r9,96(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8211abe8
	if (!ctx.cr6.eq) goto loc_8211ABE8;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8211ABE8:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// li r8,40
	ctx.r8.s64 = 40;
	// lwz r7,12(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r6,7
	ctx.r6.s64 = 7;
	// lbz r5,660(r31)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r31.u32 + 660);
	// addi r4,r31,660
	ctx.r4.s64 = ctx.r31.s64 + 660;
	// stw r11,1088(r31)
	REX_STORE_U32(ctx.r31.u32 + 1088, ctx.r11.u32);
	// addi r11,r31,1096
	ctx.r11.s64 = ctx.r31.s64 + 1096;
	// stw r8,1060(r31)
	REX_STORE_U32(ctx.r31.u32 + 1060, ctx.r8.u32);
	// stw r6,1064(r31)
	REX_STORE_U32(ctx.r31.u32 + 1064, ctx.r6.u32);
	// stw r10,1068(r31)
	REX_STORE_U32(ctx.r31.u32 + 1068, ctx.r10.u32);
	// stw r7,1072(r31)
	REX_STORE_U32(ctx.r31.u32 + 1072, ctx.r7.u32);
	// stw r30,1076(r31)
	REX_STORE_U32(ctx.r31.u32 + 1076, ctx.r30.u32);
	// stw r28,1080(r31)
	REX_STORE_U32(ctx.r31.u32 + 1080, ctx.r28.u32);
	// stw r30,1084(r31)
	REX_STORE_U32(ctx.r31.u32 + 1084, ctx.r30.u32);
	// stw r9,1092(r31)
	REX_STORE_U32(ctx.r31.u32 + 1092, ctx.r9.u32);
	// stb r5,1096(r31)
	REX_STORE_U8(ctx.r31.u32 + 1096, ctx.r5.u8);
	// b 0x8211acbc
	goto loc_8211ACBC;
loc_8211AC30:
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r8,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// beq cr6,0x8211ac74
	if (ctx.cr6.eq) goto loc_8211AC74;
	// lwz r11,44(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 44);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// lwz r10,40(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 40);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// blt cr6,0x8211ac64
	if (ctx.cr6.lt) goto loc_8211AC64;
	// lhz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// addi r6,r11,-2
	ctx.r6.s64 = ctx.r11.s64 + -2;
	// cmplw cr6,r7,r6
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8211ac64
	if (!ctx.cr6.eq) goto loc_8211AC64;
	// addi r9,r11,-7
	ctx.r9.s64 = ctx.r11.s64 + -7;
loc_8211AC64:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// addi r11,r10,7
	ctx.r11.s64 = ctx.r10.s64 + 7;
	// bne cr6,0x8211ac74
	if (!ctx.cr6.eq) goto loc_8211AC74;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8211AC74:
	// lwz r7,16(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// li r6,40
	ctx.r6.s64 = 40;
	// lwz r5,12(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// addi r10,r31,660
	ctx.r10.s64 = ctx.r31.s64 + 660;
	// lbz r28,660(r31)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r31.u32 + 660);
	// addi r10,r31,1096
	ctx.r10.s64 = ctx.r31.s64 + 1096;
	// stw r6,1060(r31)
	REX_STORE_U32(ctx.r31.u32 + 1060, ctx.r6.u32);
	// stw r4,1064(r31)
	REX_STORE_U32(ctx.r31.u32 + 1064, ctx.r4.u32);
	// stw r7,1068(r31)
	REX_STORE_U32(ctx.r31.u32 + 1068, ctx.r7.u32);
	// stw r5,1072(r31)
	REX_STORE_U32(ctx.r31.u32 + 1072, ctx.r5.u32);
	// stw r30,1076(r31)
	REX_STORE_U32(ctx.r31.u32 + 1076, ctx.r30.u32);
	// stw r8,1080(r31)
	REX_STORE_U32(ctx.r31.u32 + 1080, ctx.r8.u32);
	// stw r3,1084(r31)
	REX_STORE_U32(ctx.r31.u32 + 1084, ctx.r3.u32);
	// stw r11,1088(r31)
	REX_STORE_U32(ctx.r31.u32 + 1088, ctx.r11.u32);
	// stw r9,1092(r31)
	REX_STORE_U32(ctx.r31.u32 + 1092, ctx.r9.u32);
	// stb r28,1096(r31)
	REX_STORE_U8(ctx.r31.u32 + 1096, ctx.r28.u8);
loc_8211ACBC:
	// lbz r11,661(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 661);
	// stb r11,1097(r31)
	REX_STORE_U8(ctx.r31.u32 + 1097, ctx.r11.u8);
	// lbz r11,662(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 662);
	// stb r11,1098(r31)
	REX_STORE_U8(ctx.r31.u32 + 1098, ctx.r11.u8);
	// lbz r11,663(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 663);
	// stb r11,1099(r31)
	REX_STORE_U8(ctx.r31.u32 + 1099, ctx.r11.u8);
	// stw r29,1136(r31)
	REX_STORE_U32(ctx.r31.u32 + 1136, ctx.r29.u32);
	// b 0x8211ad7c
	goto loc_8211AD7C;
loc_8211ACDC:
	// lwz r7,24(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// li r11,40
	ctx.r11.s64 = 40;
	// lbz r6,660(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 660);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r5,7
	ctx.r5.s64 = 7;
	// stw r11,1060(r31)
	REX_STORE_U32(ctx.r31.u32 + 1060, ctx.r11.u32);
	// addi r11,r31,660
	ctx.r11.s64 = ctx.r31.s64 + 660;
	// stw r30,1088(r31)
	REX_STORE_U32(ctx.r31.u32 + 1088, ctx.r30.u32);
	// stw r30,1092(r31)
	REX_STORE_U32(ctx.r31.u32 + 1092, ctx.r30.u32);
	// addi r11,r31,1096
	ctx.r11.s64 = ctx.r31.s64 + 1096;
	// stw r7,1084(r31)
	REX_STORE_U32(ctx.r31.u32 + 1084, ctx.r7.u32);
	// stw r5,1064(r31)
	REX_STORE_U32(ctx.r31.u32 + 1064, ctx.r5.u32);
	// bne cr6,0x8211ad38
	if (!ctx.cr6.eq) goto loc_8211AD38;
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// li r8,2
	ctx.r8.s64 = 2;
	// lwz r9,12(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r8,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// stw r8,1080(r31)
	REX_STORE_U32(ctx.r31.u32 + 1080, ctx.r8.u32);
	// stw r10,1068(r31)
	REX_STORE_U32(ctx.r31.u32 + 1068, ctx.r10.u32);
	// stw r9,1072(r31)
	REX_STORE_U32(ctx.r31.u32 + 1072, ctx.r9.u32);
	// b 0x8211ad58
	goto loc_8211AD58;
loc_8211AD38:
	// lwz r9,16(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// li r10,3
	ctx.r10.s64 = 3;
	// lwz r8,12(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r4,2
	ctx.r4.s64 = 2;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r10,1080(r31)
	REX_STORE_U32(ctx.r31.u32 + 1080, ctx.r10.u32);
	// stw r9,1068(r31)
	REX_STORE_U32(ctx.r31.u32 + 1068, ctx.r9.u32);
	// stw r8,1072(r31)
	REX_STORE_U32(ctx.r31.u32 + 1072, ctx.r8.u32);
loc_8211AD58:
	// stw r4,1076(r31)
	REX_STORE_U32(ctx.r31.u32 + 1076, ctx.r4.u32);
	// stb r6,1096(r31)
	REX_STORE_U8(ctx.r31.u32 + 1096, ctx.r6.u8);
	// lbz r11,661(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 661);
	// stb r11,1097(r31)
	REX_STORE_U8(ctx.r31.u32 + 1097, ctx.r11.u8);
	// lbz r11,662(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 662);
	// stb r11,1098(r31)
	REX_STORE_U8(ctx.r31.u32 + 1098, ctx.r11.u8);
	// lbz r11,663(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 663);
	// stb r11,1099(r31)
	REX_STORE_U8(ctx.r31.u32 + 1099, ctx.r11.u8);
	// stw r30,1136(r31)
	REX_STORE_U32(ctx.r31.u32 + 1136, ctx.r30.u32);
loc_8211AD7C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
