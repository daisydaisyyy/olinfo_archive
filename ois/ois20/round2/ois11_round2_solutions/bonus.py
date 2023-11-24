#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N = int(input().strip())
S = [None] * N
P = [None] * N
for i in range(N):
    S[i], P[i] = map(int, input().strip().split())

sumS = sum(S)
sumP = sum(P)
best = 0

for i in range(N):
    if (sumS - S[i]) * (sumP - P[best]) > (sumS - S[best]) * (sumP - P[i]):
        best = i

print(best)  # print the result
