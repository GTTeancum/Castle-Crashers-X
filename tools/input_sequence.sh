#!/usr/bin/env bash
set -eu
root="$(cd "$(dirname "$0")/.." && pwd)"
sleep 12
python3 "$root/tools/send_x11_keys.py" Return space
sleep 12
python3 "$root/tools/send_x11_keys.py" Return space
sleep 12
python3 "$root/tools/send_x11_keys.py" space space
