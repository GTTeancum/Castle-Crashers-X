#!/usr/bin/env python3
import json,struct,tempfile,unittest
from pathlib import Path
from compile_capture import compile_frame,decode_texture
class CompileTests(unittest.TestCase):
 def setUp(self):
  self.temp=tempfile.TemporaryDirectory();self.root=Path(self.temp.name);self.write_texture(1,b'\xff\x12\x34\x56')
  self.draw={'event':'draw','index':0,'primitive':13,'count':4,'stride':24,'shader':0,'blend_control':0x07010701,'texture_file':'tex','vertices_file':'draw.bin','matrix_words':[struct.unpack('>I',struct.pack('>f',f))[0] for f in (1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1)]}
  (self.root/'draw.bin').write_bytes(b''.join(struct.pack('>5fI',x,y,0,u,v,0xffffffff) for x,y,u,v in ((-1,1,0,0),(1,1,1,0),(1,-1,1,1),(-1,-1,0,1))))
  self.records=[{'event':'begin','frame':7},self.draw,{'event':'end','draws':1,'read_failures':0}];self.save()
 def tearDown(self):self.temp.cleanup()
 def save(self):(self.root/'draws.jsonl').write_text('\n'.join(json.dumps(x) for x in self.records)+'\n')
 def write_texture(self,fmt,raw):
  (self.root/'tex.json').write_text(json.dumps({'padded_width':1,'padded_height':1,'format':fmt,'bytes':len(raw)}));(self.root/'tex.bin').write_bytes(raw)
 def test_argb(self):self.assertEqual(decode_texture(self.root,'tex')[2],b'\x12\x34\x56\xff')
 def test_4444(self):
  self.write_texture(5,b'\x81\x23');self.assertEqual(decode_texture(self.root,'tex')[2],b'\x11\x22\x33\x88')
 def test_layout(self):
  b,m=compile_frame(self.root,8,8);self.assertEqual(len(b),160);self.assertEqual(b[:8],b'CCRP004\0');self.assertEqual(struct.unpack_from('<5fI',b,60),(0,0,0,0,0,0xffffffff));self.assertEqual(m['triangles'],2);self.assertEqual(b[-4:],b'\x12\x34\x56\xff')
 def test_incomplete(self):
  self.records.pop();self.save()
  with self.assertRaises(ValueError):compile_frame(self.root)
 def test_read_failure(self):
  self.records[-1]['read_failures']=1;self.save()
  with self.assertRaises(ValueError):compile_frame(self.root)
 def test_unsupported_shader(self):
  self.draw['shader']=2;self.save()
  with self.assertRaises(ValueError):compile_frame(self.root)
 def test_unsupported_primitive(self):
  self.draw['primitive']=4;self.save()
  with self.assertRaises(ValueError):compile_frame(self.root)
 def test_unsupported_format(self):
  self.write_texture(7,b'12345678')
  with self.assertRaises(ValueError):compile_frame(self.root)
 def test_unsupported_blend(self):
  self.draw['blend_control']=0;self.save()
  with self.assertRaises(ValueError):compile_frame(self.root)
 def test_zero_matrix(self):
  self.draw['matrix_words']=[0]*16;self.save()
  with self.assertRaises(ValueError):compile_frame(self.root)
 def test_perspective(self):
  self.draw['matrix_words'][15]=struct.unpack('>I',struct.pack('>f',2))[0];self.save()
  with self.assertRaises(ValueError):compile_frame(self.root)
 def test_missing_texture(self):
  self.draw['texture_file']='';self.save()
  with self.assertRaises(ValueError):compile_frame(self.root)
 def test_unsafe_path(self):
  self.draw['texture_file']='../tex';self.save()
  with self.assertRaises(ValueError):compile_frame(self.root)
 def test_bad_size(self):
  (self.root/'tex.bin').write_bytes(b'')
  with self.assertRaises(ValueError):compile_frame(self.root)
 def test_nonsequential(self):
  self.draw['index']=7;self.save()
  with self.assertRaises(ValueError):compile_frame(self.root)
 def test_unknown_event(self):
  self.records.insert(1,{'event':'clear'});self.save()
  with self.assertRaises(ValueError):compile_frame(self.root)
 def test_escape_symlink(self):
  (self.root/'tex.bin').unlink();(self.root/'tex.bin').symlink_to(self.root.parent/'outside.bin')
  with self.assertRaises(ValueError):compile_frame(self.root)
 def test_nan_vertex(self):
  b=bytearray((self.root/'draw.bin').read_bytes());b[:4]=struct.pack('>f',float('nan'));(self.root/'draw.bin').write_bytes(b)
  with self.assertRaises(ValueError):compile_frame(self.root)
if __name__=='__main__':unittest.main(verbosity=2)
