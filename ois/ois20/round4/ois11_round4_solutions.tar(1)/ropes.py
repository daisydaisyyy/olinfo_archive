#!/usr/bin/env python3

# input data
N = int(input().strip())
P = list(map(int, input().strip().split()))
T = list(map(int, input().strip().split()))

sol = 0
mostc = [0 for _ in range(N+1)]
for p, t in zip(P, T):
    if t >= mostc[p]:
        sol += mostc[p]
        mostc[p] = t
    else:
        sol += t
print(sol)
