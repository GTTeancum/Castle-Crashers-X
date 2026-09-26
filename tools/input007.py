#!/usr/bin/env python3
"""Local Xvfb test input using the SDK's normal keyboard-controller mapping."""
import argparse,ctypes,json,os,re,subprocess,sys,time
from PIL import ImageGrab
from pathlib import Path
x=ctypes.CDLL('libX11.so.6');xt=ctypes.CDLL('libXtst.so.6')
x.XOpenDisplay.argtypes=[ctypes.c_char_p];x.XOpenDisplay.restype=ctypes.c_void_p
x.XStringToKeysym.argtypes=[ctypes.c_char_p];x.XStringToKeysym.restype=ctypes.c_ulong
x.XKeysymToKeycode.argtypes=[ctypes.c_void_p,ctypes.c_ulong];x.XKeysymToKeycode.restype=ctypes.c_uint
x.XSetInputFocus.argtypes=[ctypes.c_void_p,ctypes.c_ulong,ctypes.c_int,ctypes.c_ulong]
x.XFlush.argtypes=[ctypes.c_void_p];x.XCloseDisplay.argtypes=[ctypes.c_void_p]
xt.XTestFakeKeyEvent.argtypes=[ctypes.c_void_p,ctypes.c_uint,ctypes.c_int,ctypes.c_ulong]
ap=argparse.ArgumentParser(); ap.add_argument('keys',nargs='+'); ap.add_argument('--hold',type=float,default=1.0); ap.add_argument('--after',type=float,default=2.0); ap.add_argument('--label',default='input'); ap.add_argument('--repeat',type=int,default=1); ap.add_argument('--gap',type=float,default=.2); a=ap.parse_args()
if not (0<a.hold<=120 and 0<=a.after<=120 and 1<=a.repeat<=200 and 0<=a.gap<=10): raise ValueError('Invalid input duration')
out=Path(__file__).resolve().parents[1]/'logs/checkpoint007/pc-session'; out.mkdir(parents=True,exist_ok=True)
stamp=time.time(); prefix=f'{stamp:.3f}-{a.label}'
display=os.getenv('CC_DISPLAY',':99');d=x.XOpenDisplay(display.encode())
if not d:raise SystemExit('Cannot open test X display')
try:
 output=subprocess.check_output(['xwininfo','-display',display,'-root','-tree'],text=True)
 matches=re.findall(r'(0x[0-9a-f]+) "castle_crashers',output)
 if len(matches)!=1:raise RuntimeError('Expected exactly one Castle Crashers window')
 x.XSetInputFocus(d,int(matches[0],16),1,0);x.XFlush(d)
 ImageGrab.grab(xdisplay=display).save(out/f'{prefix}-before.png')
 codes=[]
 for key in a.keys:
  k=x.XKeysymToKeycode(d,x.XStringToKeysym(key.encode()))
  if not k:raise ValueError(f'Unknown X key {key}')
  codes.append(k)
 for pulse in range(a.repeat):
  try:
   for k in codes:xt.XTestFakeKeyEvent(d,k,1,0)
   x.XFlush(d);time.sleep(a.hold)
  finally:
   for k in codes:xt.XTestFakeKeyEvent(d,k,0,0)
   x.XFlush(d)
  if pulse+1<a.repeat:time.sleep(a.gap)
 time.sleep(a.after)
 ImageGrab.grab(xdisplay=display).save(out/f'{prefix}-after.png')
 record={'unix_time':stamp,'keys':a.keys,'hold_seconds':a.hold,'after_seconds':a.after,'label':a.label,'repeat':a.repeat,'gap_seconds':a.gap,'before':f'{prefix}-before.png','after':f'{prefix}-after.png'}
 with (out/'inputs.jsonl').open('a') as f:f.write(json.dumps(record)+'\n')
 print(json.dumps(record))
finally:x.XCloseDisplay(d)
