DEFINE_REX_FUNC(sub_8210CB20) {
	REX_FUNC_PROLOGUE();
	// lwz r9,0(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwinm. r11,r9,0,11,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1F0000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210cbf0
	if (ctx.cr0.eq) goto loc_8210CBF0;
	// rlwinm. r11,r9,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210cb44
	if (ctx.cr0.eq) goto loc_8210CB44;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8210cb4c
	goto loc_8210CB4C;
loc_8210CB44:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
loc_8210CB4C:
	// rlwinm. r8,r9,0,15,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x10000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8210cb6c
	if (ctx.cr0.eq) goto loc_8210CB6C;
	// lwz r8,76(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 76);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r7,4(r5)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x8210cb6c
	if (ctx.cr6.eq) goto loc_8210CB6C;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
loc_8210CB6C:
	// rlwinm. r8,r9,0,14,14
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8210cb8c
	if (ctx.cr0.eq) goto loc_8210CB8C;
	// lwz r8,76(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 76);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r7,4(r5)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x8210cb8c
	if (!ctx.cr6.eq) goto loc_8210CB8C;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
loc_8210CB8C:
	// rlwinm. r8,r9,0,13,13
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8210cbac
	if (ctx.cr0.eq) goto loc_8210CBAC;
	// lwz r8,76(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 76);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r7,4(r5)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// and. r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 & ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8210cbac
	if (!ctx.cr0.eq) goto loc_8210CBAC;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
loc_8210CBAC:
	// rlwinm. r8,r9,0,12,12
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8210cbcc
	if (ctx.cr0.eq) goto loc_8210CBCC;
	// lwz r8,76(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 76);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r7,4(r5)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// or. r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8210cbcc
	if (!ctx.cr0.eq) goto loc_8210CBCC;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
loc_8210CBCC:
	// rlwinm. r8,r9,0,11,11
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x100000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8210cbf0
	if (ctx.cr0.eq) goto loc_8210CBF0;
	// lwz r8,4(r5)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r7,76(r4)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r4.u32 + 76);
	// and r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 & ctx.r8.u64;
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8210cbf0
	if (ctx.cr6.eq) goto loc_8210CBF0;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
loc_8210CBF0:
	// lwz r7,12(r5)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r5.u32 + 12);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// clrlwi. r11,r9,31
	ctx.r11.u64 = ctx.r9.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210cc10
	if (ctx.cr0.eq) goto loc_8210CC10;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x8210cc18
	goto loc_8210CC18;
loc_8210CC10:
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
loc_8210CC18:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8210cc50
	if (ctx.cr6.eq) goto loc_8210CC50;
	// lwz r9,60(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 60);
	// lwz r11,8(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
loc_8210CC2C:
	// lwz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r9,r5
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x8210cc4c
	if (ctx.cr6.eq) goto loc_8210CC4C;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x8210cc2c
	if (ctx.cr6.lt) goto loc_8210CC2C;
	// b 0x8210cc50
	goto loc_8210CC50;
loc_8210CC4C:
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
loc_8210CC50:
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// blr 
	return;
}
