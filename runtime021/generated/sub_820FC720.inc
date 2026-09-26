DEFINE_REX_FUNC(sub_820FC720) {
	REX_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8214aae4
	__imp__NetDll_WSACleanup(ctx, base);
	return;
}
