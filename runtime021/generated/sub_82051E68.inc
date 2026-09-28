DEFINE_REX_FUNC(sub_82051E68) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f8
	ctx.lr = 0x82051E70;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r20,r5
	ctx.r20.u64 = ctx.r5.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lhz r11,14(r20)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r20.u32 + 14);
	// cmplwi cr6,r11,300
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 300, ctx.xer);
	// bgt cr6,0x82051f9c
	if (ctx.cr6.gt) goto loc_82051F9C;
	// bl 0x820fbf88
	ctx.lr = 0x82051E90;
	sub_820FBF88(ctx, base);
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// li r26,0
	ctx.r26.s64 = 0;
	// li r21,0
	ctx.r21.s64 = 0;
	// li r25,0
	ctx.r25.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82051f50
	if (!ctx.cr6.gt) goto loc_82051F50;
	// lis r11,4096
	ctx.r11.s64 = 268435456;
	// lis r10,8192
	ctx.r10.s64 = 536870912;
	// lis r8,16384
	ctx.r8.s64 = 1073741824;
	// lis r7,4096
	ctx.r7.s64 = 268435456;
	// li r30,0
	ctx.r30.s64 = 0;
	// ori r28,r11,25
	ctx.r28.u64 = ctx.r11.u64 | 25;
	// ori r22,r10,33031
	ctx.r22.u64 = ctx.r10.u64 | 33031;
	// ori r23,r8,33033
	ctx.r23.u64 = ctx.r8.u64 | 33033;
	// ori r24,r7,26
	ctx.r24.u64 = ctx.r7.u64 | 26;
loc_82051ED4:
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r28
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x82051ef0
	if (!ctx.cr6.eq) goto loc_82051EF0;
	// li r21,1
	ctx.r21.s64 = 1;
	// b 0x82051f3c
	goto loc_82051F3C;
loc_82051EF0:
	// cmplw cr6,r10,r22
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r22.u32, ctx.xer);
	// bne cr6,0x82051f08
	if (!ctx.cr6.eq) goto loc_82051F08;
	// ld r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 16);
	// li r26,1
	ctx.r26.s64 = 1;
	// std r11,32(r29)
	REX_STORE_U64(ctx.r29.u32 + 32, ctx.r11.u64);
	// b 0x82051f3c
	goto loc_82051F3C;
loc_82051F08:
	// cmplw cr6,r10,r23
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r23.u32, ctx.xer);
	// bne cr6,0x82051f28
	if (!ctx.cr6.eq) goto loc_82051F28;
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r5,20(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82127648
	ctx.lr = 0x82051F20;
	sub_82127648(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// b 0x82051f3c
	goto loc_82051F3C;
loc_82051F28:
	// cmplw cr6,r10,r24
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x82051f3c
	if (!ctx.cr6.eq) goto loc_82051F3C;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// li r25,1
	ctx.r25.s64 = 1;
	// stw r11,48(r29)
	REX_STORE_U32(ctx.r29.u32 + 48, ctx.r11.u32);
loc_82051F3C:
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r30,r30,24
	ctx.r30.s64 = ctx.r30.s64 + 24;
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82051ed4
	if (ctx.cr6.lt) goto loc_82051ED4;
loc_82051F50:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// clrlwi r10,r26,24
	ctx.r10.u64 = ctx.r26.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r11,44(r29)
	REX_STORE_U32(ctx.r29.u32 + 44, ctx.r11.u32);
	// beq cr6,0x82051f9c
	if (ctx.cr6.eq) goto loc_82051F9C;
	// clrlwi r11,r21,24
	ctx.r11.u64 = ctx.r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82051f9c
	if (ctx.cr6.eq) goto loc_82051F9C;
	// clrlwi r11,r25,24
	ctx.r11.u64 = ctx.r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82051f9c
	if (ctx.cr6.eq) goto loc_82051F9C;
	// clrlwi r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82051f9c
	if (ctx.cr6.eq) goto loc_82051F9C;
	// lhz r11,14(r20)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r20.u32 + 14);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,40(r29)
	REX_STORE_U32(ctx.r29.u32 + 40, ctx.r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
loc_82051F9C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
}
