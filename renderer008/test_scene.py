#!/usr/bin/env python3
"""Converter boundary tests; integration conversion is exercised by build_scene008.sh."""
from pathlib import Path
import copy, struct, unittest
from compile_scene import compact,context,local
class ConverterTests(unittest.TestCase):
 def valid(self):
  m=bytearray(4096);m[18:22]=b'\1'*4;w=bytearray(4096);w[18:22]=b'\1'*4
  return [0x1000],bytes(range(256))*16,bytes(reversed(range(256)))*16,bytes(m),bytes(w),0x80000000
 def test_preserves_actual_bytes(self):
  x=self.valid();rs,b,a,w=compact(*x);self.assertEqual(rs,[(0x1010,16,0)]);self.assertEqual(b,x[1][16:32]);self.assertEqual(a,x[2][16:32]);self.assertEqual(sum(w),4)
 def test_empty(self):
  with self.assertRaises(ValueError):compact([],b'',b'',b'',b'',0x80000000)
 def test_duplicate(self):
  x=list(self.valid());x[0]=[0x1000,0x1000]
  with self.assertRaises(ValueError):compact(*x)
 def test_unaligned(self):
  x=list(self.valid());x[0]=[0x1001]
  with self.assertRaises(ValueError):compact(*x)
 def test_outside_guest(self):
  x=list(self.valid());x[0]=[1<<32]
  with self.assertRaises(ValueError):compact(*x)
 def test_bad_lengths(self):
  for i in (1,2,3,4):
   x=list(self.valid());x[i]=x[i][:-1]
   with self.assertRaises(ValueError):compact(*x)
 def test_bad_masks(self):
  for i in (3,4):
   x=list(self.valid());x[i]=b'\2'+x[i][1:]
   with self.assertRaises(ValueError):compact(*x)
 def test_absent_pages_never_filled(self):
  pages=[0x1000+8192*i for i in range(33)];b=bytes(len(pages)*4096);m=bytearray(b)
  for i in range(33):m[4096*i]=1
  with self.assertRaises(ValueError):compact(pages,b,b,bytes(m),b,0x80000000)
 def test_contiguous_fragment_compaction(self):
  b=bytes(4096);m=bytearray(b)
  for i in range(80):m[i*48]=1
  rs,bb,_,_=compact([0x1000],b,b,bytes(m),b,0x80000000)
  self.assertLessEqual(len(rs),32);self.assertLessEqual(len(bb),4096)
 def test_stack_scratch_excluded_from_state_oracle(self):
  pages=[0x8000];b=bytes(4096);w=bytearray(b);w[0x700]=1
  rs,_,_,ws=compact(pages,b,b,bytes(w),bytes(w),0x8900);self.assertEqual(sum(ws),0);self.assertTrue(rs)
 def test_context(self):
  m=dict(gpr=[0]*32,fpr=[0]*32,cr=[0]*8,xer=[0]*3,lr=0,ctr=0,fpscr=0);self.assertEqual(len(context(m)),544)
  for key,bad in [('gpr',[0]),('fpr',[0]),('cr',[16]*8),('xer',[2]*3)]:
   b=copy.deepcopy(m);b[key]=bad
   with self.assertRaises(ValueError):context(b)
 def test_unsafe_filename(self):
  for name in ('../x','/etc/passwd','a/b','a\\b',None):
   with self.assertRaises(ValueError):local(Path('.'),name)
if __name__=='__main__':unittest.main()
