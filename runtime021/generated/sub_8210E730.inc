DEFINE_REX_FUNC(sub_8210E730) {
	REX_FUNC_PROLOGUE();
	// lwz r11,712(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 712);
	// addi r8,r3,712
	ctx.r8.s64 = ctx.r3.s64 + 712;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8210e7c8
	if (ctx.cr6.eq) goto loc_8210E7C8;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8210e7c8
	if (ctx.cr0.eq) goto loc_8210E7C8;
	// lwz r5,64(r4)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r4.u32 + 64);
loc_8210E754:
	// lwz r11,60(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 60);
	// addi r10,r7,-4
	ctx.r10.s64 = ctx.r7.s64 + -4;
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// ble cr6,0x8210e798
	if (!ctx.cr6.gt) goto loc_8210E798;
	// lwz r9,168(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 168);
	// rlwinm. r4,r9,0,0,0
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne 0x8210e798
	if (!ctx.cr0.eq) goto loc_8210E798;
	// rlwinm. r4,r9,0,6,6
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne 0x8210e798
	if (!ctx.cr0.eq) goto loc_8210E798;
	// rlwinm. r9,r9,0,8,8
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x800000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8210e798
	if (!ctx.cr0.eq) goto loc_8210E798;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x8210e794
	if (ctx.cr6.eq) goto loc_8210E794;
	// lwz r9,64(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 64);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8210e798
	if (!ctx.cr6.lt) goto loc_8210E798;
loc_8210E794:
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
loc_8210E798:
	// lwz r11,0(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8210e7b0
	if (ctx.cr6.eq) goto loc_8210E7B0;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8210e754
	if (!ctx.cr0.eq) goto loc_8210E754;
loc_8210E7B0:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x8210e7c8
	if (ctx.cr6.eq) goto loc_8210E7C8;
	// lwz r11,168(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r10,64(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 64);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8210e7cc
	if (ctx.cr6.lt) goto loc_8210E7CC;
loc_8210E7C8:
	// li r6,-1
	ctx.r6.s64 = -1;
loc_8210E7CC:
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// blr 
	return;
}
