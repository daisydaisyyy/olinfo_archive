#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N = int(input().strip())
P = list(map(int, input().strip().split()))
totsum = sum(P)
maxr = totsum
maxl = totsum

# insert your code here
for i in range(N-1):
    left = sum(P[:i])
    right = sum(P[i+1:])
    if left < maxl or right < maxr:
        maxl = left
        maxr = right
        pos = i
        d = max(maxl,maxr)
        
print(d-P[pos])  # print the result
