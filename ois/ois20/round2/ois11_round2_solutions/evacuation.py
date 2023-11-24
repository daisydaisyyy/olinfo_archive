#!/usr/bin/env python3

# input data
N = int(input().strip())
E = list(map(int, input().strip().split())) # evacuation directions
A = list(map(int, input().strip().split())) # arrogance

adj = [[] for _ in range(N)]
for i in range(1,N):
    adj[E[i]].append(i)

com = [-1 for _ in range(N+1)] # competing persons as priority queue
L = 0
A.append(10**9) # dummy value

def push(x):
    global L, com
    L += 1 # place at end
    com[L] = x
    i = L
    while True:
        nxt = i//2 # parent
        if A[com[i]] < A[com[nxt]]: # property is restored
            break
        com[i], com[nxt] = com[nxt], com[i] # swap with next
        i = nxt

def pop():
    global L, com
    top = com[1] # save top
    com[1] = com[L] # replace with last element
    L -= 1
    i = 1
    while L > 0:
        nxt = 2*i if 2*i >= L or A[com[2*i]] > A[com[2*i+1]] else 2*i+1 # most arrogant children
        if nxt > L or A[com[i]] > A[com[nxt]]: # property is restored
            break
        com[i], com[nxt] = com[nxt], com[i] # swap with next
        i = nxt
    return top

push(0)
while L > 0:
    n = pop()
    print(n, end=" ")
    for i in adj[n]:
        push(i)
print()
