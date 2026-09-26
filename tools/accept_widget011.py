#!/usr/bin/env python3
"""Accept only the matching native ISO plus complete telemetry AND visual checks.
Does not boot an emulator or mutate guest state. Run after the bounded xemu harness.
"""
from pathlib import Path
import argparse,hashlib,json,sys
R=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(R/'tools/xemu011'))
from telemetry import decode,validate_complete
from compare_captures import compare

def accept(run,reference,images,iso):
 result=json.loads((run/'result.json').read_text())
 if result.get('error') or not result.get('requested_termination'):raise ValueError('Run failed or lacks bounded stop')
 measured=json.loads((run/'inputs.json').read_text())['files']['iso']['sha256']
 actual=hashlib.sha256(iso.read_bytes()).hexdigest()
 if measured!=actual:raise ValueError('ISO differs from the one executed')
 status=validate_complete(decode((run/'telemetry.bin').read_bytes()))
 if result.get('telemetry_validation')!=status:raise ValueError('Saved acceptance disagrees with actual wire record')
 visual=compare(run,reference,images)
 return dict(result='passed',iso_sha256=actual,telemetry=status,visual_states={k:v for k,v in visual['selected'].items()},visual_nonmatches=visual['nonmatches'],scope='Full acceptance of the captured-state widget diagnostic, not live game update/input or physical hardware.')
if __name__=='__main__':
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--run',type=Path,required=True);p.add_argument('--reference',type=Path,required=True);p.add_argument('--images',type=Path,required=True);p.add_argument('--iso',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
 result=accept(a.run,a.reference,a.images,a.iso);a.output.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2))
