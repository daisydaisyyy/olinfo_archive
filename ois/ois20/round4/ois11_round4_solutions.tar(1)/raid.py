#!/usr/bin/env python3
# maintains a queue of the houses that will be destroyed by the next plane,
# using the fact that they must be adjacent to those just destroyed


# input data
N, P = list(map(int, input().strip().split()))
H = list(map(int, input().strip().split())) + [0] # convenient for representing terrain

now = []
next = []
for i in range(N):
    if (i==0 or H[i] > H[i-1]) and (i==N-1 or H[i] > H[i+1]):
        next.append(i)
K = 0
for _ in range(P):
    now = next
    next = []
    if len(now) == 0:
        break
    for i in now:
        H[i] = 0
        K += 1
        if i >= 1 and H[i-1] > H[i-2] and (len(next) == 0 or next[-1] != i-1):
            next.append(i-1)
        if i < N-1 and H[i+1] > H[i+2]:
            next.append(i+1)


print(K)  # print the result
