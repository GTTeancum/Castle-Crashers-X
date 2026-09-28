DEFINE_REX_FUNC(sub_820A4E08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x820A4E10;
	__savegprlr_29(ctx, base);
	// stwu r1,-944(r1)
	ea = -944 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stb r9,130(r1)
	REX_STORE_U8(ctx.r1.u32 + 130, ctx.r9.u8);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a4e54
	if (!ctx.cr6.eq) goto loc_820A4E54;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,5464
	ctx.r3.s64 = ctx.r11.s64 + 5464;
	// bl 0x8208c5d8
	ctx.lr = 0x820A4E3C;
	sub_8208C5D8(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r9.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r10,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r10.u32);
	// addi r1,r1,944
	ctx.r1.s64 = ctx.r1.s64 + 944;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_820A4E54:
	// lwz r10,1188(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1188);
	// lwz r8,112(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a4e84
	if (ctx.cr6.eq) goto loc_820A4E84;
	// addi r11,r31,1192
	ctx.r11.s64 = ctx.r31.s64 + 1192;
loc_820A4E68:
	// ld r7,8(r11)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r11.u32 + 8);
	// cmpld cr6,r7,r5
	ctx.cr6.compare<uint64_t>(ctx.r7.u64, ctx.r5.u64, ctx.xer);
	// bne cr6,0x820a4e78
	if (!ctx.cr6.eq) goto loc_820A4E78;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
loc_820A4E78:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
	// bne 0x820a4e68
	if (!ctx.cr0.eq) goto loc_820A4E68;
loc_820A4E84:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820a4f70
	if (ctx.cr6.eq) goto loc_820A4F70;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r9,-6652(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + -6652);
	// lbz r10,4(r9)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820a4eac
	if (!ctx.cr6.eq) goto loc_820A4EAC;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// b 0x820a4ebc
	goto loc_820A4EBC;
loc_820A4EAC:
	// lbz r11,20(r8)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r8.u32 + 20);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r9
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
loc_820A4EBC:
	// lwz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// clrlwi r7,r11,31
	ctx.r7.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x820a4f5c
	if (!ctx.cr6.eq) goto loc_820A4F5C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lbz r4,20(r8)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r8.u32 + 20);
	// addi r3,r11,5540
	ctx.r3.s64 = ctx.r11.s64 + 5540;
	// bl 0x8208c5d8
	ctx.lr = 0x820A4EDC;
	sub_8208C5D8(ctx, base);
	// addi r7,r1,157
	ctx.r7.s64 = ctx.r1.s64 + 157;
	// addi r6,r1,151
	ctx.r6.s64 = ctx.r1.s64 + 151;
	// addi r5,r1,139
	ctx.r5.s64 = ctx.r1.s64 + 139;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// ld r8,8(r8)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r8.u32 + 8);
	// li r12,131
	ctx.r12.s64 = 131;
	// stdx r8,r1,r12
	REX_STORE_U64(ctx.r1.u32 + ctx.r12.u32, ctx.r8.u64);
	// lbz r9,24(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 24);
	// lbz r11,102(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 102);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
	// stb r11,163(r1)
	REX_STORE_U8(ctx.r1.u32 + 163, ctx.r11.u8);
	// bl 0x8209bb30
	ctx.lr = 0x820A4F14;
	sub_8209BB30(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r4,112(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,64(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820A4F2C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r7,5
	ctx.r7.s64 = 5;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820a5478
	ctx.lr = 0x820A4F44;
	sub_820A5478(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x820a4f5c
	if (ctx.cr6.eq) goto loc_820A4F5C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,5592
	ctx.r3.s64 = ctx.r11.s64 + 5592;
	// bl 0x8208c5d8
	ctx.lr = 0x820A4F5C;
	sub_8208C5D8(ctx, base);
loc_820A4F5C:
	// stw r30,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r30,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r30.u32);
	// addi r1,r1,944
	ctx.r1.s64 = ctx.r1.s64 + 944;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_820A4F70:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r9,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r9.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r11,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// addi r1,r1,944
	ctx.r1.s64 = ctx.r1.s64 + 944;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
