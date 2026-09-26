from pathlib import Path
import json
r=Path(__file__).resolve().parents[1]
h='version bytes record_count frame scene phase completed error allocations frees roots draws visits matches raw_hash failed_root detail_address quad_error dispatches binds resident_frames resident_restores restore_total tests'.split()
e='id phase scene frame roots draws visits matches raw_hash error available total allocations frees resident_frames resident_restores expected_hash loops checks'.split()
m={'header_fields':h,'event_fields':e,'size':8+4*len(h)+32*4*len(e),'magic':'CCT008'}
(r/'tools/xemu008').mkdir(exist_ok=True)
(r/'tools/xemu008/layout.json').write_text(json.dumps(m,indent=2)+'\n')
s='''// SPDX-License-Identifier: MIT
#pragma once
#include <stdint.h>
struct Event008 {uint32_t '''+', '.join(e)+''';};
struct Status008 {
 char magic[8]={'C','C','T','0','0','8',0,0};
'''
for x in h:s+=f' uint32_t {x}={1 if x=="version" else 0};\n'
s+=' Event008 records[32]{};\n};\n'+f'static_assert(sizeof(Status008)=={m["size"]});\n'+f'static_assert(sizeof(Event008)=={4*len(e)});\n'+'extern "C" {extern volatile Status008 g_cc_status008;}\n'
(r/'nxdk-scene008/telemetry.h').write_text(s)
print(m)
