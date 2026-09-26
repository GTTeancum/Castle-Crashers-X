#!/usr/bin/env python3
import contextlib,hashlib,importlib.util,io,tempfile,unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('repair_switch',ROOT/'tools/repair_switch.py')
module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
FIXTURE=(ROOT/'tests/switch_original_fixture.cpp.txt').read_text()
class RepairTests(unittest.TestCase):
 def setUp(self):
  self.tmp=tempfile.TemporaryDirectory();self.root=Path(self.tmp.name)
  self.d=self.root/'generated/default';self.d.mkdir(parents=True)
  self.p=self.d/'test_recomp.0.cpp';self.p.write_text(FIXTURE)
 def tearDown(self):self.tmp.cleanup()
 def run_repair(self):
  with contextlib.redirect_stdout(io.StringIO()):module.repair(self.root)
 def test_known_seed_repairs(self):
  self.run_repair();s=self.p.read_text();self.assertIn('switch (ctx.ctr.u32)',s)
  self.assertIn('REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);',s)
  body=s.split('DEFINE_REX_FUNC(sub_82112BC0) {',1)[1]
  self.assertEqual(hashlib.sha256(body.encode()).hexdigest(),module.PATCHED_SHA)
 def test_repair_is_idempotent(self):
  self.run_repair();old=self.p.read_bytes();self.run_repair();self.assertEqual(old,self.p.read_bytes())
 def test_altered_original_rejected(self):
  self.p.write_text(FIXTURE.replace('ctx.r12.u64 = ctx.lr;','ctx.r12.u64 = 0;'))
  with self.assertRaises(ValueError):self.run_repair()
 def test_altered_patched_rejected(self):
  self.run_repair();self.p.write_text(self.p.read_text().replace('ctx.r12.u64 = ctx.lr;','ctx.r12.u64 = 0;'))
  with self.assertRaises(ValueError):self.run_repair()
 def test_duplicate_definition_rejected(self):
  (self.d/'test_recomp.1.cpp').write_text(FIXTURE)
  with self.assertRaises(ValueError):self.run_repair()
 def test_missing_definition_rejected(self):
  self.p.unlink()
  with self.assertRaises(ValueError):self.run_repair()
if __name__=='__main__':unittest.main(verbosity=2)
