#!/usr/bin/env pypy3
# NOTE: it is recommended to use this even if you don't understand the following code.

import sys
#sys.setrecursionlimit(200100)


# input data
D, P, E = map(int, input().strip().split())
A = list(map(int, input().strip().split()))
T = [None] * E 
ID = [None] * E
for i in range(E):
    T[i], ID[i] = map(int, input().strip().split())

adj = [[] for i in range(D+P)]
left = [0] * (D+P)
right = [0] * (D+P)

for i in range(1, D+P):
    adj[A[i]].append(i)


t = 0
#def calc_times(u):
#    global t
#    left[u] = t;
#    t += 1
#    for v in adj[u]:
#        calc_times(v)
#    right[u] = t-1

open_nodes = [(0, None)]
while len(open_nodes) > 0:
    v, i = open_nodes.pop()
    if i is None:
        left[v] = t
        t += 1
        open_nodes.append((v, 0))
    else:
        if i < len(adj[v]):
            open_nodes.append((v, i+1))
            open_nodes.append((adj[v][i], None))
        else:
            right[v] = t-1


#calc_times(0)

st = [-1] * 4*(D+P)

def propagate(i):
    global st
    if st[i] != 0:
        st[i*2] = st[i*2+1] = st[i]
    st[i] = 0

def update(active, b, e, l, r, i):
    global st
    if e < l or b > r:
        return
    if l >= b and r <= e:
        st[i] = active
        return
    propagate(i)
    update(active, b, e, l, (l+r)//2, i*2)
    update(active, b, e, (l+r)//2+1, r, i*2+1)

def get(v, l, r, i):
    global st
    while l != r:
        propagate(i)
        if v <= (l+r)//2:
            r = (l+r)//2
            i *= 2
        else:
            l = (l+r)//2+1
            i = i*2+1
    return st[i]


for i in range(E):
    if T[i] == 2:
        res = get(left[ID[i]], 0, D+P-1, 1)
        print(1 if res == 1 else 0)
    else:
        update(-1 if T[i] == 0 else 1, left[ID[i]], right[ID[i]], 0, D+P-1, 1)
