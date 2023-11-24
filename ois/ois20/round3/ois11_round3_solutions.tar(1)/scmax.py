#!/usr/bin/env pypy3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N = int(input().strip())
A = list(map(int, input().strip().split()))
T = [None] + list(map(int, input().strip().split()))

best = [0] * (N+1)
ft = [0] * (N+1)

def update(i, v):
    global N
    i = N-i+1
    while i <= N:
        ft[i] = max(ft[i], v)
        i += i&-i

def get(i):
    global N
    i = N-i+1
    res = 0
    while i > 0:
        res = max(res, ft[i])
        i -= i&-i
    return res



# WARNING! T is indexed from 1!
# In particular T[i] is the preferred number of i.

# insert your code here

for i in range(N-1, -1, -1):
    best[A[i]] = max(best[A[i]], best[T[A[i]]]+1)
    best[A[i]] = max(best[A[i]], get(A[i]+1)+1)
    update(A[i], best[A[i]])


print(max(best))  # print the result
