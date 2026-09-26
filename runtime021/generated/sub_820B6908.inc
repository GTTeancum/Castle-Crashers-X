DEFINE_REX_FUNC(sub_820B6908) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820b6990
	if (ctx.cr6.eq) goto loc_820B6990;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r10,1900
	ctx.r10.s64 = ctx.r10.s64 + 1900;
loc_820B691C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// beq 0x820b6940
	if (ctx.cr0.eq) goto loc_820B6940;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820b691c
	if (ctx.cr6.eq) goto loc_820B691C;
loc_820B6940:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820b6950
	if (!ctx.cr0.eq) goto loc_820B6950;
	// ori r4,r4,2
	ctx.r4.u64 = ctx.r4.u64 | 2;
	// b 0x820b698c
	goto loc_820B698C;
loc_820B6950:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r10,2780
	ctx.r10.s64 = ctx.r10.s64 + 2780;
loc_820B695C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// beq 0x820b6980
	if (ctx.cr0.eq) goto loc_820B6980;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820b695c
	if (ctx.cr6.eq) goto loc_820B695C;
loc_820B6980:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820b6990
	if (!ctx.cr0.eq) goto loc_820B6990;
	// ori r4,r4,256
	ctx.r4.u64 = ctx.r4.u64 | 256;
loc_820B698C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820B6990:
	// b 0x8214a354
	__imp__XamLoaderLaunchTitle(ctx, base);
	return;
}
