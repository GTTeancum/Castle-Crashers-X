DEFINE_REX_FUNC(sub_820FCAA8) {
	REX_FUNC_PROLOGUE();
	// lwz r10,28(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// blt cr6,0x820fcb94
	if (ctx.cr6.lt) goto loc_820FCB94;
	// beq cr6,0x820fcb3c
	if (ctx.cr6.eq) goto loc_820FCB3C;
	// li r11,46
	ctx.r11.s64 = 46;
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// bne cr6,0x820fcad0
	if (!ctx.cr6.eq) goto loc_820FCAD0;
	// li r11,62
	ctx.r11.s64 = 62;
	// b 0x820fcae0
	goto loc_820FCAE0;
loc_820FCAD0:
	// lwz r10,720(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 720);
	// rlwinm. r10,r10,0,17,17
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820fcae0
	if (ctx.cr0.eq) goto loc_820FCAE0;
	// li r11,42
	ctx.r11.s64 = 42;
loc_820FCAE0:
	// lwz r10,720(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 720);
	// rlwinm. r9,r10,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820fcaf4
	if (ctx.cr0.eq) goto loc_820FCAF4;
	// rlwinm r11,r11,0,31,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// b 0x820fcb1c
	goto loc_820FCB1C;
loc_820FCAF4:
	// rlwinm. r9,r10,0,3,3
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820fcb00
	if (!ctx.cr0.eq) goto loc_820FCB00;
	// ori r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 256;
loc_820FCB00:
	// rlwinm. r9,r10,0,4,4
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820fcb1c
	if (!ctx.cr0.eq) goto loc_820FCB1C;
	// rlwinm. r9,r10,0,5,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820fcb18
	if (ctx.cr0.eq) goto loc_820FCB18;
	// ori r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 2048;
	// b 0x820fcb1c
	goto loc_820FCB1C;
loc_820FCB18:
	// ori r11,r11,512
	ctx.r11.u64 = ctx.r11.u64 | 512;
loc_820FCB1C:
	// rlwinm. r9,r10,0,1,1
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820fcbd0
	if (ctx.cr0.eq) goto loc_820FCBD0;
	// rlwinm. r9,r10,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820fcbd0
	if (!ctx.cr0.eq) goto loc_820FCBD0;
	// rlwinm. r9,r10,0,23,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x100;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820fcbd0
	if (!ctx.cr0.eq) goto loc_820FCBD0;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// b 0x820fcbd0
	goto loc_820FCBD0;
loc_820FCB3C:
	// lwz r10,720(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 720);
	// li r11,32
	ctx.r11.s64 = 32;
	// rlwinm. r9,r10,0,16,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820fcb50
	if (ctx.cr0.eq) goto loc_820FCB50;
	// li r11,36
	ctx.r11.s64 = 36;
loc_820FCB50:
	// rlwinm. r9,r10,0,18,18
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820fcb84
	if (ctx.cr0.eq) goto loc_820FCB84;
	// rlwinm. r9,r10,0,2,2
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ori r11,r11,770
	ctx.r11.u64 = ctx.r11.u64 | 770;
	// bne 0x820fcb68
	if (!ctx.cr0.eq) goto loc_820FCB68;
	// ori r11,r11,1024
	ctx.r11.u64 = ctx.r11.u64 | 1024;
loc_820FCB68:
	// rlwinm. r9,r10,0,1,1
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820fcbdc
	if (ctx.cr0.eq) goto loc_820FCBDC;
	// rlwinm. r9,r10,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820fcbdc
	if (!ctx.cr0.eq) goto loc_820FCBDC;
	// rlwinm. r10,r10,0,23,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x100;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820fcbdc
	if (!ctx.cr0.eq) goto loc_820FCBDC;
	// b 0x820fcb8c
	goto loc_820FCB8C;
loc_820FCB84:
	// rlwinm. r10,r10,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820fcbdc
	if (ctx.cr0.eq) goto loc_820FCBDC;
loc_820FCB8C:
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// b 0x820fcbdc
	goto loc_820FCBDC;
loc_820FCB94:
	// lwz r10,720(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 720);
	// rlwinm. r9,r10,0,16,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820fcbb0
	if (!ctx.cr0.eq) goto loc_820FCBB0;
	// rlwinm. r9,r10,0,17,17
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820fcbb4
	if (!ctx.cr0.eq) goto loc_820FCBB4;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x820fcbb4
	if (ctx.cr6.eq) goto loc_820FCBB4;
loc_820FCBB0:
	// li r11,5
	ctx.r11.s64 = 5;
loc_820FCBB4:
	// rlwinm. r9,r10,0,18,18
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820fcbcc
	if (!ctx.cr0.eq) goto loc_820FCBCC;
	// rlwinm. r9,r10,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820fcbdc
	if (!ctx.cr0.eq) goto loc_820FCBDC;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x820fcbdc
	if (ctx.cr6.eq) goto loc_820FCBDC;
loc_820FCBCC:
	// ori r11,r11,770
	ctx.r11.u64 = ctx.r11.u64 | 770;
loc_820FCBD0:
	// rlwinm. r10,r10,0,2,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820fcbdc
	if (!ctx.cr0.eq) goto loc_820FCBDC;
	// ori r11,r11,1024
	ctx.r11.u64 = ctx.r11.u64 | 1024;
loc_820FCBDC:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}
