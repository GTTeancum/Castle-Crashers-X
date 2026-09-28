DEFINE_REX_FUNC(sub_820AEA68) {
	REX_FUNC_PROLOGUE();
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lhz r7,2(r4)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r4.u32 + 2);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r11,7
	ctx.r11.s64 = 7;
	// li r9,4
	ctx.r9.s64 = 4;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x820aea90
	if (!ctx.cr6.eq) goto loc_820AEA90;
	// li r11,138
	ctx.r11.s64 = 138;
	// li r9,3
	ctx.r9.s64 = 3;
loc_820AEA90:
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// li r31,-1
	ctx.r31.s64 = -1;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// sth r31,6(r10)
	REX_STORE_U16(ctx.r10.u32 + 6, ctx.r31.u16);
	// blt cr6,0x820aeb88
	if (ctx.cr6.lt) goto loc_820AEB88;
	// addi r4,r4,6
	ctx.r4.s64 = ctx.r4.s64 + 6;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
loc_820AEAB0:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// lhz r7,0(r4)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r4.u32 + 0);
	// cmpw cr6,r8,r11
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x820aeacc
	if (!ctx.cr6.lt) goto loc_820AEACC;
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// beq cr6,0x820aeb7c
	if (ctx.cr6.eq) goto loc_820AEB7C;
loc_820AEACC:
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x820aeaec
	if (!ctx.cr6.lt) goto loc_820AEAEC;
	// addi r11,r10,669
	ctx.r11.s64 = ctx.r10.s64 + 669;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhzx r9,r11,r3
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r3.u32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// sthx r9,r11,r3
	REX_STORE_U16(ctx.r11.u32 + ctx.r3.u32, ctx.r9.u16);
	// b 0x820aeb44
	goto loc_820AEB44;
loc_820AEAEC:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820aeb20
	if (ctx.cr6.eq) goto loc_820AEB20;
	// cmpw cr6,r10,r6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, ctx.xer);
	// beq cr6,0x820aeb10
	if (ctx.cr6.eq) goto loc_820AEB10;
	// addi r11,r10,669
	ctx.r11.s64 = ctx.r10.s64 + 669;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhzx r9,r11,r3
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r3.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// sthx r9,r11,r3
	REX_STORE_U16(ctx.r11.u32 + ctx.r3.u32, ctx.r9.u16);
loc_820AEB10:
	// lhz r11,2740(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 2740);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,2740(r3)
	REX_STORE_U16(ctx.r3.u32 + 2740, ctx.r11.u16);
	// b 0x820aeb44
	goto loc_820AEB44;
loc_820AEB20:
	// cmpwi cr6,r8,10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 10, ctx.xer);
	// bgt cr6,0x820aeb38
	if (ctx.cr6.gt) goto loc_820AEB38;
	// lhz r11,2744(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 2744);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,2744(r3)
	REX_STORE_U16(ctx.r3.u32 + 2744, ctx.r11.u16);
	// b 0x820aeb44
	goto loc_820AEB44;
loc_820AEB38:
	// lhz r11,2748(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 2748);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,2748(r3)
	REX_STORE_U16(ctx.r3.u32 + 2748, ctx.r11.u16);
loc_820AEB44:
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x820aeb60
	if (!ctx.cr6.eq) goto loc_820AEB60;
	// li r11,138
	ctx.r11.s64 = 138;
	// li r9,3
	ctx.r9.s64 = 3;
	// b 0x820aeb7c
	goto loc_820AEB7C;
loc_820AEB60:
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// bne cr6,0x820aeb74
	if (!ctx.cr6.eq) goto loc_820AEB74;
	// li r11,6
	ctx.r11.s64 = 6;
	// li r9,3
	ctx.r9.s64 = 3;
	// b 0x820aeb7c
	goto loc_820AEB7C;
loc_820AEB74:
	// li r11,7
	ctx.r11.s64 = 7;
	// li r9,4
	ctx.r9.s64 = 4;
loc_820AEB7C:
	// addic. r5,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// bne 0x820aeab0
	if (!ctx.cr0.eq) goto loc_820AEAB0;
loc_820AEB88:
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}
