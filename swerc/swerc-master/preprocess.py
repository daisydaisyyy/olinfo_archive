import os
import hashlib
import re

MARGIN = 100 - 40 - 8 + 7


def mkhash(dat):
    conc = ""
    for i in dat:
        conc += re.sub('\s*', '', i) + "\n"
        yield hashlib.md5(conc.encode('utf8')).hexdigest()[:2]

for path, dirs, files in os.walk('./_src'):
    for f in files:
        if f[f.rfind('.')+1:] in ['cpp', 'hpp', 'java', 'sh']:
            p = os.path.join(path, f)

            with open(p) as file:
                text = file.read()
            if not f.endswith('.sh'):
                text = re.sub(r'\n?[ \t]*(?<!/)//[^/].+', '', text)
            #text = re.sub(r'\n?[ \t]*//[^/].+', '', text)
            #dat = [ line for line in text.splitlines() if not line.startswith('// vim: ') and not line.startswith('# vim: ') ]
            dat = text.splitlines()
            out = open(p, 'w')

            warning = False
            error = False
            last = False
            for dat, hash in zip(dat, mkhash(dat)):
                last = False
                s = dat.lstrip(' ')
                add = len(dat) - len(s)
                if add > 0:
                    s = ' ' + s
                    add -= 1
                s = ' '*add + s
                if(len(s) > MARGIN):
                    print>>out, s
                    warning = True
                    last = True
                    if len(s) > MARGIN+4:
                        error = True
                        print (len(s), MARGIN)
                        print (repr(s))
                else:
                    if len(s) < MARGIN:
                        s = s+' '
                    print(s.ljust(MARGIN, ' ') + "//" + hash, file=out)

            if last:
                error = True
            if error:
                print('ERROR: Code too wide: %s' % p)
            elif warning:
                print('WARNING: Code (almost) too wide: %s' % p)
