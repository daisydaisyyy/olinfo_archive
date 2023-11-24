#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


def solve(a,b):
    # insert your code here
    neg = 0
    if 0 in range(a,b+1):
        return 0
    for i in range(a,b+1):
        if i < 0:
            neg += 1
            
    if neg % 2 == 0:
        return '+'
    return '-'


# input data
T = int(input().strip())
for i in range(T):
    A, B = map(int, input().strip().split())
    print(solve(A, B))
