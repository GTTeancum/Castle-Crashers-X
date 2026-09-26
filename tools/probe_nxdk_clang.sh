#!/usr/bin/env bash
set -u
echo 'int main(){char16_t c=0;(void)c;return 0;}' > /tmp/t.cpp
echo '--- default ---'
/clang64/bin/clang -target i386-pc-win32 -std=c++20 -fsyntax-only /tmp/t.cpp 2>&1
echo '--- with ms-compat 19.29 ---'
/clang64/bin/clang -target i386-pc-win32 -std=c++20 -fms-compatibility-version=19.29 -fsyntax-only /tmp/t.cpp 2>&1
echo '--- clang version ---'
/clang64/bin/clang --version | head -1
