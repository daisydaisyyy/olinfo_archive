#!/usr/bin/env python3

# input data
N, M = map(int, input().strip().split())
C = list(map(int, input().strip().split()))

candies_left = M % sum(C)

if candies_left == 0:
    # Print the LAST kid who takes at least 1 candy
    print(max(i for i in range(N) if C[i] != 0))
else:
    for i in range(N):
        if candies_left <= C[i]:
            print(i)
            break
        else:
            candies_left -= C[i]
