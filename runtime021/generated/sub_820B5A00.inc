DEFINE_REX_FUNC(sub_820B5A00) {
	REX_FUNC_PROLOGUE();
	// b 0x8214a244
	__imp__XamUserGetSigninState(ctx, base);
	return;
}
