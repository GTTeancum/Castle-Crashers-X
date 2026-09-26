#!/usr/bin/env python3
"""Check generated C++ local labels, counts, and selected callback registration."""
import json,re,sys
from pathlib import Path
root=Path(__file__).resolve().parents[1];g=root/'pc/generated/default';errors=[];names=[]
for p in sorted(g.glob('*_recomp.*.cpp')):
 for name,body in re.findall(r'DEFINE_REX_FUNC\((\w+)\) \{(.*?)(?=\nDEFINE_REX_FUNC\(|\Z)',p.read_text(),re.S):
  names.append(name);refs=set(re.findall(r'goto (loc_[0-9A-F]+)',body));labels=set(re.findall(r'\b(loc_[0-9A-F]+):',body))
  if refs-labels:errors.append({'file':p.name,'function':name,'missing':sorted(refs-labels)})
result={'recompiled_function_definitions':len(names),'unresolved_local_goto_labels':errors,
 'verified_entries_present':{n:n in names for n in ['sub_820E15E8','sub_82112BC0','sub_82114E20','sub_82114E38']}}
(root/'logs/generated-label-audit.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2))
sys.exit(bool(errors) or not all(result['verified_entries_present'].values()))
