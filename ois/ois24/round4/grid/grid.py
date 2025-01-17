#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.

import sys

# uncomment the two following lines if you want to read/write from files
sys.stdin = open('input0.txt')
# sys.stdout = open('output.txt', 'w')

def solve(n, m):
	if swap := n < m: 
		n, m = m, n 

	i = j = 0 
	p = lambda i, j: (j, i) if swap else (i,j)
	while(True): # riempi righe due a due 
		while j >= m:
			i += 1 
			j = i & 1 
		if i >= n:
			break
		yield p(i,j)
		j += 2
	
	i, j = 0,1
	while(True):  # riempi righe rimaste
		while j >= m:
			i += 1 
			j = (i & 1) ^ 1 
		if i >= n:
			break
		yield p(i,j) 
		j += 2




N, M, R, G, B = map(int, input().strip().split())

grid = [[None] * M for _ in range(N)]

if max(R,G,B) > (N*M+1) // 2:
	print("NO")

else:
	print('YES')
	
	# setto inizio righe come r, b, g come nel testo del problema
	order = sorted("RGB" ,key = lambda c: globals()[c], reverse=True)
	order[1], order[2] = order[1], order[2] # r,g,b

	order = "".join(globals()[c] * c for c in order)

	for c, (i,j) in zip(order, solve(N,M)):
		grid[i][j] = c

for r in grid:
	print(''.join(r))

sys.stdout.close()
