#!/usr/bin/env python3

# input data
N, K = map(int, input().strip().split())
V = [-1] + list(map(int, input().strip().split()))
vis = [False] * (N+1)

pos = 1
sol = 0
while pos != K and not vis[pos]:
    vis[pos] = True
    pos = V[pos]
    sol += 1

if pos == K:
    print(sol)
else:
    print(-1)
