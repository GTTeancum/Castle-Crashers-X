DEFINE_REX_FUNC(sub_820C7B48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x820C7B50;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,34
	ctx.r4.s64 = 34;
	// lwz r29,13532(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 13532);
	// bl 0x820c64c0
	ctx.lr = 0x820C7B68;
	sub_820C64C0(ctx, base);
	// lbz r11,10941(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 10941);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820c7b80
	if (ctx.cr0.eq) goto loc_820C7B80;
	// lwz r31,16728(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 16728);
	// b 0x820c7bdc
	goto loc_820C7BDC;
loc_820C7B80:
	// rlwinm r11,r31,12,20,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 12) & 0xFFF;
	// stw r31,13532(r30)
	REX_STORE_U32(ctx.r30.u32 + 13532, ctx.r31.u32);
	// clrlwi r10,r31,3
	ctx.r10.u64 = ctx.r31.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	ctx.r11.s64 = ctx.r11.s64 + 512;
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r11,r11,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addis r3,r11,-16384
	ctx.r3.s64 = ctx.r11.s64 + -1073741824;
	// bne cr6,0x820c7bb8
	if (!ctx.cr6.eq) goto loc_820C7BB8;
	// lwz r11,13516(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 13516);
	// stw r3,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r3.u32);
	// b 0x820c7bd0
	goto loc_820C7BD0;
loc_820C7BB8:
	// stw r3,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// lwz r11,13536(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 13536);
	// subf r11,r29,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r29.u64;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// srawi r11,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 3;
	// stw r11,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
loc_820C7BD0:
	// addi r4,r3,136
	ctx.r4.s64 = ctx.r3.s64 + 136;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x820d6470
	ctx.lr = 0x820C7BDC;
	sub_820D6470(ctx, base);
loc_820C7BDC:
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// addi r11,r31,136
	ctx.r11.s64 = ctx.r31.s64 + 136;
	// stw r3,13536(r30)
	REX_STORE_U32(ctx.r30.u32 + 13536, ctx.r3.u32);
	// stw r11,13540(r30)
	REX_STORE_U32(ctx.r30.u32 + 13540, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
