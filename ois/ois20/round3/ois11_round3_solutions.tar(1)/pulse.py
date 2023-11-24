#!/usr/bin/env python3
# visit the graph whose nodes are (cells, times).

import math
import functools
import collections

# input data
N, P = list(map(int, input().strip().split()))
X = [None for _ in range(P)]
Y = [None for _ in range(P)]
R = [None for _ in range(P)]
for i in range(P):
    X[i], Y[i], R[i] = list(map(int, input().strip().split()))
    X[i] -= 1 # shift indexes from 1..N to 0..N-1
    Y[i] -= 1 # shift indexes from 1..N to 0..N-1


# maximum communication radius
MAXR = max(R)
# least common multiple
math.lcm = lambda x,y : x*y//math.gcd(x,y)
# maximum period after which everything repeats
MAXT = functools.reduce(math.lcm, set(R))

# whether a cell is valid
def valid(x,y):
    return 0 <= x < N and 0 <= y < N

# distance from closest radar of a given radius
D = [[[r+1 for r in range(MAXR)] for y in range(N)] for x in range(N)]
for i in range(P):
    for x in range(-R[i]+1, R[i]):
        for y in range(-R[i]+abs(x)+1, R[i]-abs(x)):
            if valid(X[i]+x, Y[i]+y):
                D[X[i]+x][Y[i]+y][R[i]-1] = min(D[X[i]+x][Y[i]+y][R[i]-1], abs(x)+abs(y))

# visited nodes of the graph
V = [[[False for r in range(MAXT)] for y in range(N)] for x in range(N)]
# stack of cells to visit
queue = collections.deque([(0,0,0)])

# whether a certain cell is ok at a certain time
def ok(x,y,t):
    if not valid(x, y) or V[x][y][t%MAXT]:
        return False
    V[x][y][t%MAXT] = True
    for r in range(MAXR):
        if t%(r+1) >= D[x][y][r]:
            return False
    queue.appendleft((x, y, t))
    return x == N-1 and y == N-1

# BFS
while len(queue) > 0:
    x,y,t = queue.pop()
    t += 1
    for dx,dy in [(-1,0),(0,-1),(0,0),(0,1),(1,0)]:
        if ok(x+dx, y+dy, t):
            print(t) # print the result
            exit(0) # we are done
    

print("No solution")
