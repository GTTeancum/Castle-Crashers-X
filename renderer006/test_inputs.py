#!/usr/bin/env python3
"""Collector/fixture contract tests. Real fixture data is linked read-only into temporary roots."""
import json,os,struct,tempfile,unittest
from pathlib import Path
from unittest.mock import patch
from compile_inputs import compile_inputs
W=Path(__file__).resolve().parents[1]
CAP=W/'renderer006/captures/frame-000988'
class TestInputs(unittest.TestCase):
 @classmethod
 def setUpClass(cls):cls.real=(W/'renderer006/menu.ccr').read_bytes();cls.scene=json.loads((W/'renderer006/menu.scene.json').read_text())
 def setUp(self):
  self.tmp=tempfile.TemporaryDirectory();self.root=Path(self.tmp.name)
  for p in CAP.iterdir():
   if p.is_file():os.link(p,self.root/p.name)
  self.first=self.root/'input-00000.json';self.meta=json.loads(self.first.read_text())
 def tearDown(self):self.tmp.cleanup()
 def change(self,name,content):
  p=self.root/name;p.unlink(missing_ok=True);p.write_text(content)
 def metadata(self,change):
  change(self.meta);self.change('input-00000.json',json.dumps(self.meta))
 def invoke(self):
  # Existing 004 converter is tested separately; isolate the new pre-call serializer here.
  with patch('compile_inputs.compile_frame',return_value=(self.real,self.scene)):return compile_inputs(self.root)
 def fails(self):
  with self.assertRaises((ValueError,KeyError,TypeError,struct.error)):self.invoke()
 def test_real(self):self.assertEqual(self.invoke()[0],(W/'renderer006/menu.ccq').read_bytes())
 def test_wrong_magic(self):self.metadata(lambda m:m.update(format='bad'));self.fails()
 def test_wrong_index(self):self.metadata(lambda m:m.update(index=1));self.fails()
 def test_shader_mismatch(self):self.metadata(lambda m:m.update(shader=10));self.fails()
 def test_register_count(self):self.metadata(lambda m:m['gpr'].pop());self.fails()
 def test_negative_gpr(self):self.metadata(lambda m:m['gpr'].__setitem__(0,-1));self.fails()
 def test_bad_xer(self):self.metadata(lambda m:m['xer'].__setitem__(0,3));self.fails()
 def test_bad_cr(self):self.metadata(lambda m:m['cr'].__setitem__(0,17));self.fails()
 def test_range_overlap(self):self.metadata(lambda m:m['ranges'][1].update(address=m['ranges'][0]['address']));self.fails()
 def test_range_wrap(self):self.metadata(lambda m:m['ranges'][-1].update(address=2**32-1,bytes=5));self.fails()
 def test_discontinuous_backing(self):self.metadata(lambda m:m['ranges'][0].update(offset=1));self.fails()
 def test_empty_range(self):self.metadata(lambda m:m['ranges'][0].update(bytes=0));self.fails()
 def test_unpaired(self):self.change('input-04000.json','{}');self.fails()
 def test_duplicate_pair(self):
  ds=[json.loads(x)for x in (self.root/'draws.jsonl').read_text().splitlines()];ds[2]['input_index']=ds[1]['input_index'];self.change('draws.jsonl','\n'.join(map(json.dumps,ds)));self.fails()
 def test_unsafe_expected_path(self):
  ds=[json.loads(x)for x in (self.root/'draws.jsonl').read_text().splitlines()];ds[1]['vertices_file']='../bad.bin';self.change('draws.jsonl','\n'.join(map(json.dumps,ds)));self.fails()
if __name__=='__main__':unittest.main(verbosity=2)
