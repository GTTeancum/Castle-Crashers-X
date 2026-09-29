#!/usr/bin/env bash
# Back-to-back XEMU runs of several disc images with periodic window captures
# (the on-screen counters give fps / ms / update / render per screen).
# Usage: tools/xemu_ab.sh <out dir> <seconds> <iso>...
# Only kills the XEMU processes it started.
set -u
OUT="$1"; SECS="$2"; shift 2
mkdir -p "$OUT"
for ISO in "$@"; do
  NAME=$(basename "$ISO" .iso)
  PID=$(powershell.exe -NoProfile -Command "(Start-Process -FilePath 'C:\Games\Emulators\Xemu\xemu.exe' -ArgumentList '-dvd_path','$(cygpath -w "$ISO")' -WorkingDirectory 'C:\Games\Emulators\Xemu' -PassThru).Id" | tr -d '\r')
  echo "$NAME pid=$PID"
  T=0
  while [ "$T" -lt "$SECS" ]; do
    sleep 15; T=$((T + 15))
    powershell.exe -NoProfile -ExecutionPolicy Bypass -File "$(cygpath -w "$(dirname "$0")/capture_window.ps1")" \
      -Process xemu -ProcessId "$PID" -Out "$(cygpath -w "$OUT")\\${NAME}_$(printf %03d $T).png" > /dev/null || true
  done
  taskkill //F //PID "$PID" > /dev/null 2>&1
  sleep 3
done
echo done
