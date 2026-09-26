# Castle Crashers port checkpoint

Current checkpoint: **019**. Start with `CHECKPOINT-019.md` and `README-019.md`.

Checkpoint 019 advances exact original graphics initialization through `sub_820CBBF0`, including the observed 640×480 resource-creation path, and stops fail-closed at `sub_820CB988`. The outer renderer device pointer is still unpublished.

Run host acceptance with `./build_update019.sh` using Clang. Checkpoint 011 remains the latest actual nxdk/xemu acceptance; private boot inputs and the external nxdk toolchain are deliberately not packaged.
