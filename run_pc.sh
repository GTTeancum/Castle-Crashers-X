#!/usr/bin/env bash
set -euo pipefail
source "$(dirname "$0")/env.sh"
mkdir -p "$CC_WORK/pc-user"
export DISPLAY="${CC_DISPLAY:-:99}" SDL_VIDEODRIVER=x11 SDL_AUDIODRIVER="${CC_AUDIO_DRIVER:-alsa}"
export ALSA_CONFIG_PATH="$CC_WORK/alsa-null.conf"
export LIBGL_ALWAYS_SOFTWARE=1
export VK_ICD_FILENAMES="${VK_ICD_FILENAMES:-/usr/lib/chromium/vk_swiftshader_icd.json}"
pc_build="${CC_PC_BUILD:-$CC_WORK/pc/build011}"
cd "$pc_build"
exec "$pc_build/castle_crashers" "--game_data_root=$CC_WORK/castle-crashers-port/extracted" \
  --user_data_root="$CC_WORK/pc-user" "$@"
