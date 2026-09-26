DEFINE_REX_FUNC(sub_820FC8B0) {
	REX_FUNC_PROLOGUE();
	// b 0x8214ab94
	__imp__NetDll_WSAGetLastError(ctx, base);
	return;
}
