#!/usr/bin/env pypy3
# COMPLEXITY: O(N)
# IDEA: Just scan the vector while keeping the accumulating sum and current maximum value possessed.

N = int(input().strip())
V = map(int, input().strip().split())

last = 0
tot = 0
for v in V:
    if v > last:
        last = v
        tot += v

print(tot)  # print the result
