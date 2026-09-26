#!/usr/bin/env python3
"""Bounded real PC run, periodic X11 screenshots and Linux process measurements."""
import argparse,json,os,signal,subprocess,time
from pathlib import Path
from PIL import ImageGrab
ap=argparse.ArgumentParser(); ap.add_argument('--seconds',type=float,default=900); a=ap.parse_args()
w=Path(__file__).resolve().parents[1]; out=w/'logs/checkpoint008/pc-session'; out.mkdir(parents=True,exist_ok=True)
if (out/'launch.json').exists(): raise RuntimeError('Refusing to overwrite a prior PC session')
cmd=['bash',str(w/'run_pc.sh'),'--gpu_plugin=xenos','--vulkan_require_geometry_shader=false','--vulkan_require_fill_mode_non_solid=false','--mnk_mode=true','--video_mode_width=640','--video_mode_height=480','--window_width=640','--window_height=480','--log_level=info',f'--log_file={out}/runtime.log']
start=time.monotonic(); frames=[]; samples=[]; why='natural exit'
with (out/'console.log').open('wb') as f:
 p=subprocess.Popen(cmd,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
 (out/'pid').write_text(str(p.pid))
 (out/'launch.json').write_text(json.dumps({'command':cmd,'pid':p.pid,'start_unix':time.time()},indent=2))
 try:
  while p.poll() is None:
   elapsed=time.monotonic()-start
   if elapsed>=a.seconds or (out/'STOP').exists():
    why='harness timeout' if elapsed>=a.seconds else 'requested stop'; os.killpg(p.pid,signal.SIGTERM); break
   path=out/f'frame-{int(elapsed):05d}.png'
   try: ImageGrab.grab(xdisplay=os.getenv('CC_DISPLAY',':97')).save(path); frames.append(path.name)
   except Exception as e: print('capture error',e,flush=True)
   sample={'elapsed_seconds':round(elapsed,3)}
   try:
    for line in Path(f'/proc/{p.pid}/status').read_text().splitlines():
     if line.startswith(('VmPeak:','VmSize:','VmHWM:','VmRSS:','RssAnon:','RssFile:','Threads:')):
      key,value=line.split(':',1); sample[key]=value.strip()
    sample['stat']=Path(f'/proc/{p.pid}/stat').read_text().strip()
   except OSError: pass
   samples.append(sample)
   (out/'samples.json').write_text(json.dumps(samples,indent=2))
   time.sleep(10)
  try: p.wait(timeout=10)
  except subprocess.TimeoutExpired: why+='; kill after termination timeout'; os.killpg(p.pid,signal.SIGKILL); p.wait()
 finally:
  if p.poll() is None: os.killpg(p.pid,signal.SIGKILL);p.wait()
 (out/'result.json').write_text(json.dumps({'returncode':p.returncode,'stop_reason':why,'elapsed_seconds':round(time.monotonic()-start,3),'frames':frames},indent=2))
