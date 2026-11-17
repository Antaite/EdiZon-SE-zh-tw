# 套用 EdiZon SE 繁中翻譯：python3 apply_edz.py <原始碼目錄> <翻譯表>
import sys, os, glob, re, importlib.util
src, trf = sys.argv[1], sys.argv[2]
spec = importlib.util.spec_from_file_location('t', trf); m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
files = [f for f in glob.glob(os.path.join(src, 'source/**/*.c*'), recursive=True) if f.endswith(('.c', '.cpp'))]
files += glob.glob(os.path.join(src, 'include/**/*.h*'), recursive=True)
data = {f: open(f, encoding='utf8', newline='').read() for f in files}
miss = []
for k, v in m.T.items():
    q = '"' + k + '"'; n = 0
    for f in data:
        c = data[f].count(q)
        if c: data[f] = data[f].replace(q, '"' + v + '"'); n += c
    if n == 0: miss.append(k)
for k, v in m.ALIGNED.items():
    q = '"' + k + '", ALIGNED_'; n = 0
    for f in data:
        c = data[f].count(q)
        if c: data[f] = data[f].replace(q, '"' + v + '", ALIGNED_'); n += c
    if n == 0: miss.append('[標籤] ' + k)
bad = 0
for f, old, new, want in m.RAW:
    p = os.path.join(src, f); c = data[p].count(old)
    if c != want: print(f'[程式碼未對到] {f}: {old!r} 出現 {c} 次（預期 {want}）'); bad += 1; continue
    data[p] = data[p].replace(old, new)
for f, s in data.items():
    open(f, 'w', encoding='utf8', newline='').write(s)
for k in miss: print('[未對到]', k[:90])
print(f'翻譯 {len(m.T)} 條、標籤 {len(m.ALIGNED)} 條，未對到 {len(miss)} 條，程式碼修改失敗 {bad} 處')
