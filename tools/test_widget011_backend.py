#!/usr/bin/env python3
"""Guard the native backend contract and reject the accidental rename mutation."""
import re,unittest
from pathlib import Path
R=Path(__file__).resolve().parents[1]
def validate(text):
 if 'cmd.blend==0x07010701?' not in text:raise ValueError('Incorrect premultiplied blend control')
 if 'NV097_SET_COLOR_MASK,0x01010101' not in text:raise ValueError('Incorrect RGBA write mask')
 if 'NV097_SET_TEXTURE_FORMAT,0x0001122a' not in text:raise ValueError('Unexpected linear ARGB texture state')
 return True
class Tests(unittest.TestCase):
 def test_actual_contract(self):self.assertTrue(validate((R/'nxdk-widget011/backend.inc').read_text()))
 def test_unchanged_backend(self):self.assertEqual((R/'nxdk-widget011/backend.inc').read_bytes(),(R/'nxdk-owner010/backend.inc').read_bytes())
 def test_rename_mutation_rejected(self):
  with self.assertRaises(ValueError):validate((R/'nxdk-owner010/backend.inc').read_text().replace('010','011'))
 def test_reject_wrong_blend(self):
  with self.assertRaises(ValueError):validate((R/'nxdk-widget011/backend.inc').read_text().replace('0x07010701','0x07011701'))
 def test_reject_wrong_mask(self):
  with self.assertRaises(ValueError):validate((R/'nxdk-widget011/backend.inc').read_text().replace('0x01010101','0x01110111'))
 def test_raw_vs_compiler_names(self):
  # Only explicitly replaced packet hashes may differ in the native inputs.
  for n in ('main.cpp','backend.inc','ps.ps.cg','vs.vs.cg'):
   with self.subTest(file=n):
    a=(R/'nxdk-owner010'/n).read_text();b=(R/'nxdk-widget011'/n).read_text()
    self.assertEqual(re.findall(r'0x[0-9a-fA-F]+',a),re.findall(r'0x[0-9a-fA-F]+',b))
if __name__=='__main__':unittest.main(verbosity=2)
