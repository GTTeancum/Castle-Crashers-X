#!/usr/bin/env python3
"""Converter contract tests against read-only links to a real captured scene."""
import json,os,struct,tempfile,unittest
from pathlib import Path
from unittest.mock import patch
from compile_callers import compile_callers
W=Path(__file__).resolve().parents[1]
CAP=W/'renderer007/captures/frame-001548'
class Tests(unittest.TestCase):
 @classmethod
 def setUpClass(cls):cls.scene=(W/'renderer007/menu.ccr').read_bytes();cls.meta=json.loads((W/'renderer007/menu.scene.json').read_text())
 def setUp(self):
  self.tmp=tempfile.TemporaryDirectory();self.root=Path(self.tmp.name)
  for p in CAP.iterdir():
   if p.is_file():os.link(p,self.root/p.name)
  self.m=json.loads((self.root/'parent-00000.json').read_text())
 def tearDown(self):self.tmp.cleanup()
 def write(self,n,s):
  p=self.root/n;p.unlink(missing_ok=True);p.write_text(s)
 def change(self,fn):fn(self.m);self.write('parent-00000.json',json.dumps(self.m))
 def invoke(self):
  with patch('compile_callers.compile_frame',return_value=(self.scene,self.meta)):return compile_callers(self.root)
 def fails(self):
  with self.assertRaises((ValueError,KeyError,TypeError,struct.error,FileNotFoundError)):self.invoke()
 def test_real(self):self.assertEqual(self.invoke()[0],(W/'renderer007/menu.ccp').read_bytes())
 def test_wrong_magic(self):self.change(lambda m:m.update(format='bad'));self.fails()
 def test_wrong_index(self):self.change(lambda m:m.update(index=1));self.fails()
 def test_unknown_entry(self):self.change(lambda m:m.update(entry=0x12345678));self.fails()
 def test_unknown_shader(self):self.change(lambda m:m.update(shader=7));self.fails()
 def test_shader_mismatch(self):self.change(lambda m:m.update(shader=5));self.fails()
 def test_register_count(self):self.change(lambda m:m['gpr'].pop());self.fails()
 def test_negative_register(self):self.change(lambda m:m['gpr'].__setitem__(0,-1));self.fails()
 def test_xer(self):self.change(lambda m:m['xer'].__setitem__(0,7));self.fails()
 def test_cr(self):self.change(lambda m:m['cr'].__setitem__(0,17));self.fails()
 def test_overlap(self):self.change(lambda m:m['ranges'][1].update(address=m['ranges'][0]['address']));self.fails()
 def test_wrap(self):self.change(lambda m:m['ranges'][-1].update(address=2**32-1,bytes=8));self.fails()
 def test_empty_range(self):self.change(lambda m:m['ranges'][0].update(bytes=0));self.fails()
 def test_offset(self):self.change(lambda m:m['ranges'][0].update(offset=1));self.fails()
 def test_missing_exit(self):(self.root/'parent-00000-post.json').unlink();self.fails()
 def test_counter(self):
  p=self.root/'parent-00000-post.json';m=json.loads(p.read_text());m['counter']+=4;self.write(p.name,json.dumps(m));self.fails()
 def test_duplicate_draw_parent(self):
  rows=[json.loads(x)for x in(self.root/'draws.jsonl').read_text().splitlines()];rows[2]['parent_index']=rows[1]['parent_index'];self.write('draws.jsonl','\n'.join(map(json.dumps,rows)));self.fails()
 def test_unsafe_vertices(self):
  rows=[json.loads(x)for x in(self.root/'draws.jsonl').read_text().splitlines()];rows[1]['vertices_file']='../outside.bin';self.write('draws.jsonl','\n'.join(map(json.dumps,rows)));self.fails()
 def test_bad_return(self):
  p=self.root/'parent-00000-post.json';m=json.loads(p.read_text());m['r3']=-1;self.write(p.name,json.dumps(m));self.fails()
if __name__=='__main__':unittest.main(verbosity=2)
