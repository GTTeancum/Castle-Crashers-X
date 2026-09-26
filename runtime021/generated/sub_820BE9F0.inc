DEFINE_REX_FUNC(sub_820BE9F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x820BE9F8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r11,4
	ctx.r11.s64 = 4;
	// lwz r29,0(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cctpl 
loc_820BEA0C:
	// db16cyc 
	// db16cyc 
	// db16cyc 
	// db16cyc 
	// db16cyc 
	// db16cyc 
	// db16cyc 
	// db16cyc 
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820bea0c
	if (!ctx.cr0.eq) goto loc_820BEA0C;
	// cctpm 
	// lbz r11,10941(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 10941);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820beabc
	if (!ctx.cr0.eq) goto loc_820BEABC;
	// lwz r11,10896(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 10896);
	// lwz r10,256(r13)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r13.u32 + 256);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r30,88(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 88);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x820bea6c
	if (ctx.cr6.eq) goto loc_820BEA6C;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r30,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_820BEA6C:
	// bl 0x82136728
	ctx.lr = 0x820BEA70;
	sub_82136728(ctx, base);
	// lwz r11,10888(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 10888);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x820bea8c
	if (!ctx.cr6.eq) goto loc_820BEA8C;
	// lwz r11,11004(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 11004);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820bea8c
	if (ctx.cr6.eq) goto loc_820BEA8C;
	// stw r30,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
loc_820BEA8C:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// subf r11,r11,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r11.u64;
	// cmplwi cr6,r11,5000
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5000, ctx.xer);
	// bge cr6,0x820beaa4
	if (!ctx.cr6.lt) goto loc_820BEAA4;
loc_820BEA9C:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820beac0
	goto loc_820BEAC0;
loc_820BEAA4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820cb7f8
	ctx.lr = 0x820BEAAC;
	sub_820CB7F8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x820beabc
	if (!ctx.cr0.eq) goto loc_820BEABC;
	// stw r30,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// b 0x820bea9c
	goto loc_820BEA9C;
loc_820BEABC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820BEAC0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
