DEFINE_REX_FUNC(sub_8208A228) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8208A230;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// lbz r10,86(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 86);
	// lbz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 140);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// rlwinm r8,r11,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// stb r9,86(r31)
	REX_STORE_U8(ctx.r31.u32 + 86, ctx.r9.u8);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8208a264
	if (!ctx.cr6.eq) goto loc_8208A264;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8208A264:
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8208a280
	if (ctx.cr6.eq) goto loc_8208A280;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// sth r4,144(r31)
	REX_STORE_U16(ctx.r31.u32 + 144, ctx.r4.u16);
	// ori r10,r11,64
	ctx.r10.u64 = ctx.r11.u64 | 64;
	// stb r10,140(r31)
	REX_STORE_U8(ctx.r31.u32 + 140, ctx.r10.u8);
loc_8208A280:
	// lhz r10,144(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 144);
	// li r11,1
	ctx.r11.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8208a294
	if (!ctx.cr6.eq) goto loc_8208A294;
	// sth r11,144(r31)
	REX_STORE_U16(ctx.r31.u32 + 144, ctx.r11.u16);
loc_8208A294:
	// lhz r10,146(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 146);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8208a2a4
	if (!ctx.cr6.eq) goto loc_8208A2A4;
	// sth r11,146(r31)
	REX_STORE_U16(ctx.r31.u32 + 146, ctx.r11.u16);
loc_8208A2A4:
	// lwz r11,156(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// addi r30,r31,160
	ctx.r30.s64 = ctx.r31.s64 + 160;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
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
	// lbz r6,140(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 140);
	// rlwinm r5,r6,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8208a2e8
	if (ctx.cr6.eq) goto loc_8208A2E8;
	// bl 0x8207bae8
	ctx.lr = 0x8208A2E4;
	sub_8207BAE8(ctx, base);
	// b 0x8208a2f8
	goto loc_8208A2F8;
loc_8208A2E8:
	// bl 0x8207b8b8
	ctx.lr = 0x8208A2EC;
	sub_8207B8B8(ctx, base);
	// lbz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 140);
	// ori r10,r11,8
	ctx.r10.u64 = ctx.r11.u64 | 8;
	// stb r10,140(r31)
	REX_STORE_U8(ctx.r31.u32 + 140, ctx.r10.u8);
loc_8208A2F8:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,124(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8208A30C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8208a338
	if (ctx.cr6.eq) goto loc_8208A338;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,92(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8208A330;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207b630
	ctx.lr = 0x8208A338;
	sub_8207B630(ctx, base);
loc_8208A338:
	// lbz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 140);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8208a354
	if (!ctx.cr6.eq) goto loc_8208A354;
	// lhz r10,148(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 148);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x8208a360
	if (!ctx.cr6.eq) goto loc_8208A360;
loc_8208A354:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r11,r11,0,30,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stb r11,140(r31)
	REX_STORE_U8(ctx.r31.u32 + 140, ctx.r11.u8);
loc_8208A360:
	// lwz r30,104(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8208a3f4
	if (ctx.cr6.eq) goto loc_8208A3F4;
loc_8208A36C:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8208A380;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8208a3d4
	if (ctx.cr6.eq) goto loc_8208A3D4;
	// lbz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 140);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8208a3ac
	if (ctx.cr6.eq) goto loc_8208A3AC;
	// lhz r11,82(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 82);
	// lhz r10,144(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 144);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8208a3c8
	if (!ctx.cr6.eq) goto loc_8208A3C8;
loc_8208A3AC:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,88(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8208A3C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// or r29,r3,r29
	ctx.r29.u64 = ctx.r3.u64 | ctx.r29.u64;
loc_8208A3C8:
	// lbz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 140);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	// b 0x8208a3dc
	goto loc_8208A3DC;
loc_8208A3D4:
	// lbz r11,86(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 86);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
loc_8208A3DC:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8208a3e8
	if (ctx.cr6.eq) goto loc_8208A3E8;
	// ori r29,r29,1
	ctx.r29.u64 = ctx.r29.u64 | 1;
loc_8208A3E8:
	// lwz r30,88(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8208a36c
	if (!ctx.cr6.eq) goto loc_8208A36C;
loc_8208A3F4:
	// clrlwi r11,r29,31
	ctx.r11.u64 = ctx.r29.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208a410
	if (!ctx.cr6.eq) goto loc_8208A410;
	// lbz r11,86(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 86);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,86(r31)
	REX_STORE_U8(ctx.r31.u32 + 86, ctx.r10.u8);
loc_8208A410:
	// lbz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 140);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,156(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// clrlwi r8,r11,24
	ctx.r8.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r8,r8,0,26,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stb r8,140(r31)
	REX_STORE_U8(ctx.r31.u32 + 140, ctx.r8.u8);
	// lwz r7,76(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r6,156(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 156);
	// lwz r11,8248(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 8248);
	// addi r5,r11,1998
	ctx.r5.s64 = ctx.r11.s64 + 1998;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r4,r6
	REX_STORE_U32(ctx.r4.u32 + ctx.r6.u32, ctx.r10.u32);
	// lwz r11,8248(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 8248);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,8248(r6)
	REX_STORE_U32(ctx.r6.u32 + 8248, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
