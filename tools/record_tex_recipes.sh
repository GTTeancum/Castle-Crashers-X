#!/bin/bash
# Output: game-data/texrecipes/<run>.rcp (git-ignored: they hold shape bytes), then
# tools/texrecipe_locate.py --order <pack> game-data/extracted installer/textures.txr game-data/texrecipes/*.rcp
# Record texture recipes for all levels: eager 4P, play 4P, play 1P, plus the plain scripted run.
cd /d/Programming/GitHub/Castle-Crashers-X
EXE=.claude/worktrees/integ/renderer021/build-bake/cc_update_boundary_tests.exe
# (the startup capture argument is not opened by these builds)
ARGS="game-data/none.cct castle-crashers-port/reference/default.image.bin game-data/extracted"
O=game-data/texrecipes; mkdir -p $O; rm -f $O/*
jobs_list=()
for L in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 40 41 42 43 44 45 46 47 48 49 50 51 53 54 55 56 57 58 59 60; do
  jobs_list+=("e$L:CC_TEX_EAGER=1 CC_4P=1 CC_LEVEL=$L CC_FRAME_BUDGET=9000")
  jobs_list+=("p$L:CC_4P=1 CC_LEVEL=$L CC_FRAME_BUDGET=20000")
  jobs_list+=("s$L:CC_LEVEL=$L CC_FRAME_BUDGET=20000")
done
jobs_list+=("run4:CC_4P=1 CC_FRAME_BUDGET=30000" "run1:CC_FRAME_BUDGET=30000")
running=0
for j in "${jobs_list[@]}"; do
  n=${j%%:*}; e=${j#*:}
  (env $e CC_TEX_BAKE=$O/$n.pak CC_TEX_RECIPE=$O/$n.rcp $EXE $ARGS > $O/$n.txt 2>&1; rm -f $O/$n.pak) &
  running=$((running+1))
  if [ $running -ge 12 ]; then wait -n; running=$((running-1)); fi
done
wait
echo "recorded $(ls $O/*.rcp | wc -l) recipe files"
grep -l -a 'FAIL' $O/*.txt | head
