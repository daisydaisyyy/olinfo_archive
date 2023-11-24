#!/usr/bin/env python3

N = int(input().strip())
C = list(map(int, input().strip().split()))

sol = C[0]
for i in range(1, len(C)):
    diff = C[i] - C[i-1]
    sol = max(sol, diff)

print(sol)
