#!/usr/bin/env bash
set -u
cd /d/Programming/GitHub/Castle-Crashers-X/nxdk-widget011
/c/nxdk/tools/cxbe/cxbe.exe -OUT:bin/default.xbe '-TITLE:CastleCrashersW011' main.exe
echo "rc=$?"
ls -l bin/default.xbe 2>&1
