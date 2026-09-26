# Primary format/tool references

Consulted on 2026-09-21. Online source was readable through the browser; repositories were not cloned into scratch. The measured reports come from the user's supplied bytes and locally executed tools, not these pages. Upstream branches may change; preserve exact revisions when acquiring the real build tools.

- Xenia STFS on-disk structures: https://raw.githubusercontent.com/xenia-project/xenia/master/src/xenia/vfs/devices/stfs_xbox.h
- Xenia STFS reader and physical/hash block addressing: https://raw.githubusercontent.com/xenia-project/xenia/master/src/xenia/vfs/devices/stfs_container_device.cc
- Xenia XEX structures: https://raw.githubusercontent.com/xenia-project/xenia/master/src/xenia/kernel/util/xex2_info.h
- Xenia XEX loader, public retail XEX key and normal-LZX framing: https://raw.githubusercontent.com/xenia-project/xenia/master/src/xenia/cpu/xex_module.cc
- Xenia PE definitions: https://raw.githubusercontent.com/xenia-project/xenia/master/third_party/pe/pe_image.h
- Ruffle standard SWF tag identifiers: https://raw.githubusercontent.com/ruffle-rs/ruffle/master/swf/src/tag_code.rs
- ReXGlue code-generation configuration: https://github.com/rexglue/rexglue-sdk/wiki/rexglue-CLI-Configuration-File
- ReXGlue setup documentation: https://github.com/rexglue/rexglue-sdk/wiki/Getting-Started
- nxdk: https://github.com/XboxDev/nxdk

Interpretation boundaries: tag names come from standard SWF definitions, while the observed COK6 wrapper and unknown tags require game-specific work. None of these references proves this title runs under ReXGlue or on original Xbox. No complete third-party source repository is redistributed in the compact archive.
