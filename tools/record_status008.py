#!/usr/bin/env python3
"""Record measured 008 results; require the actual accepted target and matching ISO."""
from pathlib import Path
import hashlib,json
R=Path(__file__).resolve().parents[1]
def read(p):return json.loads((R/p).read_text())
def sha(p):
 h=hashlib.sha256()
 with p.open('rb')as f:
  for b in iter(lambda:f.read(4*1024*1024),b''):h.update(b)
 return h.hexdigest()
def main():
 if (R/'logs/checkpoint008/combined-build.exit').read_text().strip()!='0':raise RuntimeError('Build suite did not pass')
 run=read('logs/checkpoint008/xemu-final/result.json');inputs=read('logs/checkpoint008/xemu-final/inputs.json');audit=read('logs/checkpoint008/final-build/target-audit.json');telemetry=read('logs/checkpoint008/xemu-final/telemetry.json');provenance=read('logs/checkpoint008/final-build/provenance.json')
 if run['error'] or run['telemetry_validation']['result']!='passed':raise RuntimeError('Target did not pass')
 artifacts={}
 for name in ('nxdk-scene008/bin/default.xbe','nxdk-scene008/CastleCrashers-SceneOwner008.iso','pc/build008/castle_crashers','renderer008/menu.cct','renderer008/book.cct','renderer008/menu.ccr','renderer008/book.ccr','logs/checkpoint008/xemu-final/target-scene008.mp4'):
  p=R/name;artifacts[name]=dict(bytes=p.stat().st_size,sha256=sha(p))
 if artifacts['nxdk-scene008/CastleCrashers-SceneOwner008.iso']['sha256']!=inputs['files']['iso']['sha256'] or audit['xiso_sha256']!=inputs['files']['iso']['sha256']:raise RuntimeError('Different ISO than the accepted target')
 states=[]
 for e in telemetry['events']:
  if e['phase']in(1,2,3):states.append(dict(phase=e['phase'],scene=e['scene'],available_pages=e['available'],available_mib=e['available']/256,allocations=e['allocations'],frees=e['frees']))
 status=dict(checkpoint='CastleCrashers-Checkpoint-008',scope='Original scene traversal with one persistent captured subtree; remaining roots and textures remain capture-driven. Synthetic child-list detach/reattach, not original game update/menu/input/animation.',
  source_revisions={'rexglue':'f5337cdc947ff6d4c4196737e2c807a48f2a1fc2','nxdk':'58427c078b4ccb0121f359b6b6c536b3b2914976'},tools={'rexglue_sdk':'0.10.0','llvm':'20.1.8','xemu':'0.8.136'},
  original_generated_bodies={'unique_entries':provenance['unique_original_entries'],'new_entries_vs007':provenance['new_entry_count'],'provenance':'passed; original extents, generated PC bodies and copied bodies match','unsupported_direct':['sub_82085C70','sub_8208C5D8','sub_82127FB0'],'count_scope':'Compiler helper ranges overlap; not a percentage of game coverage'},
  pc_capture={'elapsed_seconds':read('logs/checkpoint008/pc-session/result.json')['elapsed_seconds'],'stop_reason':'requested stop','observer_counters':read('renderer008/captures/status.json'),'accepted_frames':[1105,1829],'root_cases':241,'emitted_quads':381,'original_scene_visits':73,'checked_non_stack_store_bytes':38657,'new_combat_test':False},
  host_tests={'debug_asan_ubsan':True,'separate_optimized_release':True,'original_case_assertions_per_suite':1940,'original_cases':241,'draws':381,'control_cases_per_scene':9,'control_masks':[511,511],'fixture_assertions_per_suite':7841,'mutated_fixture_trials':4000,'mutations_accepted_restore_only':1237,'mutations_rejected':2763,'mutated_machine_state_executed':False,'converter_tests':12,'telemetry_tests':18,'no_fallback_test':'corrupt reference output refused; old vertices and commands poisoned','resident_fixture_ownership_test':'different fixture backing rejected','host_preview_states_per_scene':4,'preview_variants':['ASan/system FMA','ASan/target software FMA','Release/system FMA','Release/target software FMA'],'preview_byte_equality':True,'prior_caller_assertions':32458,'prior_fma_cases':112202,'prior_memory_assertions':40072,'prior_loader_assertions_real_suite':70190,'prior_converter_tests':18,'prior_switch_tests':6},
  target={'run':run,'status_header':telemetry['header'],'memory_states':states,'audit':audit,'pass_is_emulator_only':True},visual=read('screenshots008/comparison.json'),video=read('logs/checkpoint008/video-probe.json'),video_full_decode_pass=(R/'logs/checkpoint008/video-decode.exit').read_text().strip()=='0',artifacts=artifacts,
  limits={'live_xbox_gameplay':False,'original_update_timeline':False,'original_interactive_menu':False,'physical_xbox_test':False,'audible_audio_test':False,'whole_game_ram_fit':False,'new_pc_combat_test':False,'existing_inputs_sufficient':True})
 (R/'build-status008.json').write_text(json.dumps(status,indent=2)+'\n')
 print(json.dumps({'result':'passed','artifacts':artifacts,'memory_states':states},indent=2))
if __name__=='__main__':main()
