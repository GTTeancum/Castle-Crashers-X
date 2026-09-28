import sys
p = r'D:\Programming\GitHub\Castle-Crashers-X\runtime021\bodies.inc'
s = open(p, 'rb').read().decode('latin1')
anchor = '#include "generated/sub_820A7470.inc"'
assert anchor in s
for name in sys.argv[1:]:
    inc = '#include "generated/%s.inc"' % name
    if inc in s:
        print('already wired', name)
        continue
    s = s.replace(anchor, anchor + '\n' + inc, 1)
    print('wired', name)
open(p, 'wb').write(s.encode('latin1'))
