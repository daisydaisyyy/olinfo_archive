#!/usr/bin/env pypy3
# NOTE: it is recommended to use this even if you don't understand the following code.

# input data
R, C = map(int, input().strip().split())
M = [None] * R
for i in range(R):
    M[i] = list(map(int, input().strip().split()))

def valid(r, c):
    global R
    global C
    return (0 <= r < R) and (0 <= c < C)

def dfs(r, c):
    global M
    if not valid(r, c) or M[r][c] == 0:
        return
    queue = [(r, c)]
    M[r][c] = 0
    while len(queue) > 0:
        r, c = queue.pop()
        for i, j in zip([-1, 1, 0, 0], [0, 0, 1, -1]):
                if not valid(r+i, c+j) or M[r+i][c+j] == 0:
                    continue
                M[r+i][c+j] = 0
                queue.append((r+i, c+j))

for i in range(R):
    dfs(i, 0)
    dfs(i, C-1)

for j in range(C):
    dfs(0, j)
    dfs(R-1, j)

count = 0
for i in range(R):
    for j in range(C):
        if M[i][j] == 1:
            dfs(i, j)
            count += 1

print(count)  # print the result
