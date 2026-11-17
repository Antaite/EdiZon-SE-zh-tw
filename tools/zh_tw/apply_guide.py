# 套用快速入門的繁中內容：python3 apply_guide.py <原始碼目錄> <guide_zh.py>
import sys, os, json, importlib.util
src, trf = sys.argv[1], sys.argv[2]
spec = importlib.util.spec_from_file_location('g', trf); g = importlib.util.module_from_spec(spec); spec.loader.exec_module(g)
base = os.path.join(src, 'romfs/guide')
for page in sorted(os.listdir(base)):
    for sub in sorted(os.listdir(os.path.join(base, page))):
        d = os.path.join(base, page, sub); key = f'{page}/{sub}'
        cfg = json.load(open(os.path.join(d, 'config.json'), encoding='utf8'))
        for im in cfg.get('images', []):
            im['title'] = g.IMAGE_TITLES.get(im['title'], im['title'])
        if key in g.GUIDE:
            titles, texts = g.GUIDE[key]
            for i, t in enumerate(cfg['text']):
                t['title'] = titles[i]
                body = g.GUIDE_1_2[i] if texts is None else texts[t['path']]
                open(os.path.join(d, t['path']), 'w', encoding='utf8').write(body + '\n')
        json.dump(cfg, open(os.path.join(d, 'config.json'), 'w', encoding='utf8'), ensure_ascii=False, indent='\t')
        print('已處理', key)
