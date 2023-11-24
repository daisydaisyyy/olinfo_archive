#!/usr/bin/env python3

C, D, Y = map(int, input().strip().split())
M = [0] + list(map(int, input().strip().split()))
P = [0] + list(map(int, input().strip().split()))

maint = [0 for _ in range(D+1)]
for i in range(1, D+1):
    maint[i] = maint[i-1] + M[i]
for i in range(1, D+1):
    maint[i] -= P[i]
    maint[i] += C

DP = [0 for _ in range(D+1)]
Ds = []
y = 1
while y <= Y and y <= D:
    best = 10**18
    bestd = -1
    for d in range(1, y+1):
        cost = maint[d] + DP[(y-d) % (D+1)]
        if cost < best:
            best = cost
            bestd = d
    DP[y % (D + 1)] = best
    if bestd == y:
        Ds.append(bestd)
    y += 1
while y <= Y:
    best = 10**18
    for d in Ds:
        cost = maint[d] + DP[(y-d) % (D+1)]
        if cost <= best:
            best = cost
    DP[y % (D + 1)] = best
    y += 1

print(DP[Y % (D + 1)])
