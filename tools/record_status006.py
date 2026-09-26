#!/usr/bin/env python3
"""Assemble checkpoint status from actual retained build, capture and target evidence."""
from pathlib import Path
import hashlib,json,re
w=Path(__file__).resolve().parents[1]
def read(p):return json.loads((w/p).read_text())
def digest(p):return hashlib.sha256(p.read_bytes()).hexdigest()
boot=read('logs/checkpoint006/boot006-acceptance/result.json');telemetry=read('logs/checkpoint006/boot006-acceptance/telemetry.json');audit=read('logs/checkpoint006/final-build/target-audit.json');inputs=read('logs/checkpoint006/boot006-acceptance/inputs.json');video=read('logs/checkpoint006/video-audit.json')
if boot['error'] or boot['telemetry_validation']['result']!='passed':raise ValueError('No successful final target evidence')
iso=w/'nxdk-bridge006/CastleCrashers-GameQuadBridge006.iso'
if digest(iso)!=inputs['files']['iso']['sha256'] or digest(iso)!=audit['xiso_sha256']:raise ValueError('Final ISO does not match actually tested ISO')
if digest(w/'nxdk-bridge006/bin/default.xbe')!=audit['xbe_sha256']:raise ValueError('XBE changed')
for cfg in ['asan','release']:
 t=(w/f'logs/checkpoint006/final-build/runtime-{cfg}-tests.log').read_text()
 if '47062 assertions, 381 real input/output matches, 4000 malformed fixture mutations' not in t or '100% tests passed' not in t:raise ValueError('Missing new host tests '+cfg)
 for scene in ['menu','book']:
  text=(w/f'logs/checkpoint006/final-build/frame-{cfg}-{scene}.log').read_text()
  if 'PASS: corrupted output oracle refused without fallback' not in text:raise ValueError('Missing no-fallback test')
for scene in ['menu','book']:
 for phase in range(3):
  ps=[w/f'logs/checkpoint006/final-build/preview-{cfg}-{scene}/phase-{phase}.ppm' for cfg in ['asan','release']]
  if digest(ps[0])!=digest(ps[1]):raise ValueError('Preview build mismatch')
files=['pc/build004/castle_crashers','nxdk-bridge006/bin/default.xbe','nxdk-bridge006/CastleCrashers-GameQuadBridge006.iso','renderer006/menu.ccq','renderer006/book.ccq','renderer006/menu.ccr','renderer006/book.ccr']
status={
 'checkpoint':'CastleCrashers-Checkpoint-006',
 'result':'Original game quad routine and four exact generated helpers execute through bounded scalar/guest-memory support, regenerate vertices from captured caller state, and feed the native Xbox GPU backend in xemu.',
 'critical_scope':{'full_original_xbox_game_built':False,'xbox_gameplay_verified':False,'original_game_update_loop_running':False,'caller_state_source':'per-call snapshots observed in PC reference','position_and_opacity_controls':'synthetic diagnostic inputs, not original game input/animation','shader_contract':[0,5],'full_powerpc_or_platform_runtime':False,'physical_hardware_tested':False},
 'source_revisions':{'rexglue':'f5337cdc947ff6d4c4196737e2c807a48f2a1fc2','nxdk':'58427c078b4ccb0121f359b6b6c536b3b2914976','llvm':'20.1.8','rexglue_sdk':'0.10.0','xemu':'0.8.136'},
 'original_container_sha256':'2863b8019806a300dc2449b84cf5599fc4a7a949e61b2817ddbda5a2cdf5ca1c',
 'provenance':read('logs/checkpoint006/final-build/provenance.json'),
 'pc_capture':{'new_pc_gameplay_test':False,'normal_input':'Return key opened local-game book','observer_counters':read('renderer006/captures/status.json'),'input_output_pairs':381,'frame_draws':{'988':262,'1304':119},'max_guest_regions_per_call':20,'max_copied_guest_bytes_per_call':1121,'scope':'Read-only capture extension; original rendering calls retained; original Xbox-side runtime not used on PC reference'},
 'host_tests':{'new_bridge_assertions':47062,'real_pairs':381,'fixture_format_mutations':4000,'mutated_fixture_scope':'accepted mutations parsed/restored, not arbitrary mutated machine-state execution','configurations':['Debug ASan/UBSan','Release'],'independent_coordinate_and_color_oracle':'passed','six_preview_images_byte_identical':True,'no_replay_vertex_fallback':'staging poisoned before generation; corrupted oracle refused','new_converter_tests':15,'telemetry_helper_tests':14,'earlier_converter_tests':18,'switch_repair_tests':6,'earlier_guest_memory_regression':'40072 assertions / 10000 trials / 4096 original-leaf inputs; ASan/UBSan','earlier_loader_regression':'70190-assertion real-fixture suite including unit subset; ASan/UBSan'},
 'target_test':{'result':'passed','elapsed_seconds':boot['elapsed_seconds'],'periodic_screenshots':len(boot['captures']),'extra_completion_screenshot':True,'returncode':boot['emulator_returncode'],'termination':'Requested after completion record; not game completion','acceptance':boot['telemetry_validation'],'events':telemetry['events'],'video':{'duration_seconds':float(video['probe']['streams'][0]['duration']),'captured_frames':int(video['probe']['streams'][0]['nb_frames']),'capture_fps':10,'full_decode_returncode':video['full_decode_returncode'],'sha256':video['sha256'],'scope':'No speed alteration. Recording rate, not performance measure.'}},
 'visual_comparison':read('screenshots006/comparison.json'),
 'target_container_audit':audit,
 'artifacts':{p:{'bytes':(w/p).stat().st_size,'sha256':digest(w/p)}for p in files},
 'next_observed_callers':read('renderer006/caller_candidates.json'),
 'reproduction':'build_quad006.sh executed, including final incremental rerun; exact final ISO accepted in xemu. Full historical PC regeneration/empty-machine provisioning not replayed as one operation.'
}
(w/'build-status.json').write_text(json.dumps(status,indent=2)+'\n')
print('PASS: current artifacts, host evidence, preview equality and accepted target ISO verified.')
