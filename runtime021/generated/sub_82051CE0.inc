DEFINE_REX_FUNC(sub_82051CE0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82051CE8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// ori r9,r11,32778
	ctx.r9.u64 = ctx.r11.u64 | 32778;
	// lis r10,0
	ctx.r10.s64 = 0;
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// stw r9,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// ori r8,r10,32779
	ctx.r8.u64 = ctx.r10.u64 | 32779;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// lhz r6,2(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 2);
	// stw r6,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r6.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r8,8(r5)
	REX_STORE_U32(ctx.r5.u32 + 8, ctx.r8.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// lhz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// stw r4,12(r5)
	REX_STORE_U32(ctx.r5.u32 + 12, ctx.r4.u32);
	// lhz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// stw r9,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// stw r10,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
	// blt cr6,0x82051d60
	if (ctx.cr6.lt) goto loc_82051D60;
	// beq cr6,0x82051d58
	if (ctx.cr6.eq) goto loc_82051D58;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x82051d50
	if (ctx.cr6.eq) goto loc_82051D50;
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x82051d68
	goto loc_82051D68;
loc_82051D50:
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x82051d64
	goto loc_82051D64;
loc_82051D58:
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x82051d68
	goto loc_82051D68;
loc_82051D60:
	// li r11,4
	ctx.r11.s64 = 4;
loc_82051D64:
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_82051D68:
	// bl 0x820fbf88
	ctx.lr = 0x82051D6C;
	sub_820FBF88(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lis r9,4096
	ctx.r9.s64 = 268435456;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// ori r8,r9,25
	ctx.r8.u64 = ctx.r9.u64 | 25;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwinm r10,r7,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r6,-32221
	ctx.r6.s64 = -2111635456;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + ctx.r29.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// stw r3,24824(r6)
	REX_STORE_U32(ctx.r6.u32 + 24824, ctx.r3.u32);
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stb r9,8(r10)
	REX_STORE_U8(ctx.r10.u32 + 8, ctx.r9.u8);
	// stw r3,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r3.u32);
	// lbz r5,20(r31)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r31.u32 + 20);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x82051e5c
	if (!ctx.cr6.eq) goto loc_82051E5C;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhz r7,4(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r10,r6,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r4,r5,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + ctx.r29.u64;
	// ori r8,r3,26
	ctx.r8.u64 = ctx.r3.u64 | 26;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwx r8,r4,r29
	REX_STORE_U32(ctx.r4.u32 + ctx.r29.u32, ctx.r8.u32);
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// stb r9,8(r10)
	REX_STORE_U8(ctx.r10.u32 + 8, ctx.r9.u8);
	// stw r7,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r7.u32);
	// lhz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// cmplwi cr6,r7,1
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 1, ctx.xer);
	// beq cr6,0x82051e5c
	if (ctx.cr6.eq) goto loc_82051E5C;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r31,8(r31)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r31.u32 + 8);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r7,r8,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r6,4096
	ctx.r6.s64 = 268435456;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// ori r5,r6,27
	ctx.r5.u64 = ctx.r6.u64 | 27;
	// li r4,211
	ctx.r4.s64 = 211;
	// stwx r5,r7,r29
	REX_STORE_U32(ctx.r7.u32 + ctx.r29.u32, ctx.r5.u32);
	// lis r3,-32218
	ctx.r3.s64 = -2111438848;
	// sth r4,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r4.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r9,8(r11)
	REX_STORE_U8(ctx.r11.u32 + 8, ctx.r9.u8);
	// stw r31,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r31.u32);
	// lwz r11,-6624(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x82051E4C;
	sub_82052EA8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r31,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_82051E5C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
