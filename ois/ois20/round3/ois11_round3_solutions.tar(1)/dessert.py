#!/usr/bin/env python3
# Keep track of the number of friends (deg) that already took the dessert.
# Once this number reaches the limit L for a member,
# it is added to a stack of people waiting to order the dessert.


# input data
N = int(input().strip())
M = [None for _ in range(N)]
L = [None for _ in range(N)]
F = [None for _ in range(N)]
for i in range(N):
    M[i], L[i] = list(map(int, input().strip().split()))
    F[i] = list(map(int, input().strip().split()))


adj = [[] for _ in range(N)]
for i in range(N):
    for f in F[i]:
        adj[f].append(i)
deg = [0 for _ in range(N)]

R = 0
stack = [i for i in range(N) if L[i] == 0]
while len(stack) > 0:
    R += 1
    i = stack.pop()
    for f in adj[i]:
        deg[f] += 1
        if deg[f] == L[f]:
            stack.append(f)

print(R)  # print the result
