#!/usr/bin/env python3
"""Find code in .text that no generated function covers: gaps that start right after a
return / tail jump and begin with a plausible instruction. Function extents come from the
per-instruction disassembly comments codegen writes.
usage: scan_gaps.py <basefile.exe> <generated_dir>"""
import struct, sys, glob, re
b = open(sys.argv[1], 'rb').read(); B = 0x82000000
w = lambda a: struct.unpack('>I', b[a-B:a-B+4])[0]
e = struct.unpack('<I', b[0x3c:0x40])[0]; ns = struct.unpack('<H', b[e+6:e+8])[0]; oh = struct.unpack('<H', b[e+20:e+22])[0]
text = []
for i in range(ns):
    s = b[e+24+oh+i*40:e+24+oh+i*40+40]; vs, va = struct.unpack('<II', s[8:16])
    if struct.unpack('<I', s[36:40])[0] & 0x20: text.append((B+va, B+va+vs))
cover = {}
for f in glob.glob(sys.argv[2] + '/*.cpp'):
    cur = None; n = 0
    for line in open(f):
        m = re.match(r'^DEFINE_REX_FUNC\(sub_([0-9A-F]+)\)', line)
        if m:
            if cur is not None: cover[cur] = max(cover.get(cur, 0), n)
            cur = int(m.group(1), 16); n = 0
        elif cur is not None and re.match(r'^\t// [a-z]', line):
            n += 1
    if cur is not None: cover[cur] = max(cover.get(cur, 0), n)
starts = sorted(cover)
term = lambda x: x in (0x4E800020, 0x4E800420) or ((x >> 26) == 18 and (x & 1) == 0)
out = []
for k, s in enumerate(starts):
    end = s + 4 * cover[s]
    nxt = starts[k+1] if k + 1 < len(starts) else None
    if nxt is None or not any(lo <= end < hi for lo, hi in text): continue
    a = end
    while a < nxt and w(a) == 0: a += 4          # alignment padding
    if a >= nxt or a <= end - 4: continue
    if not (term(w(end - 4)) or w(a - 4) == 0): continue
    first = w(a)
    if first == 0 or (first >> 26) in (0, 1, 5, 6, 56, 57, 60, 61): continue  # not real code
    out.append((a, nxt - a))
print('# %d uncovered code gaps' % len(out))
for a, n in out: print('0x%08X  # %d bytes' % (a, n))
