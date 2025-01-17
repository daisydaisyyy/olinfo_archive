from os import walk, path
def beautify(s):
	return ' '.join(x[0].upper() + x[1:] for x in s.split('_'))

for d, _, files in walk('_src'):
	d = d[5:]
	print ('\\section{%s}' % (beautify(d) if len(d) > 0 else ''))
	for f in sorted(files):
		print ('\t\\subsection{%s}\n\t\t\\%scode{%s}\n' %\
			(beautify(f[:-4]), 'bash' if f[-3:] == '.sh' else '', path.join(d, f)))
