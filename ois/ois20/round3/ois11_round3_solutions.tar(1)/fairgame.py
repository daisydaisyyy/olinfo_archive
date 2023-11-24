#!/usr/bin/env pypy3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N, K, M, P, Q = map(int, input().strip().split())

# insert your code here
A = []
B = []
A.append((0, Q-P))

for i in range(1, N+1):
    while A and A[0][0] + K < i:
        A = A[1:]
    while B and B[0][0] + K < i:
        B = B[1:]

    best = -10**9
    if A:
        best = max(best, -A[0][1] - (i&1)*M)
    if B:
        best = max(best, -B[0][1] - (1 - (i&1))*M)

    if i&1:
        while B and B[-1][1] >= best:
            B = B[:-1]
        B.append((i, best))
    else:
        while A and A[-1][1] >= best:
            A = A[:-1]
        A.append((i, best))

print(B[-1][1] if N&1 else A[-1][1])  # print the result
