#!/usr/bin/env python3
# just simulates the process


# input data
N, M = list(map(int, input().strip().split()))
P = list(map(int, input().strip().split()))
C = list(map(int, input().strip().split()))


K = 0
for i in range(N):
    if P[i] > M:
        M += C[i]
    else:
        M -= P[i]
        K += 1


print(K, M)  # print the result
