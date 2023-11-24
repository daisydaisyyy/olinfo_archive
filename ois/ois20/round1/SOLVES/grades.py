#!/usr/bin/env pypy3
# COMPLEXITY: O(N)
# IDEA: With a scansion of the array I find the first insufficient and last sufficient votes.
# If they exist and are not in swapped order, I found an interval.

N = int(input())
first_ins, last_suf = -1, -1

for i, g in enumerate(map(int, input().split())):
    if g < 6 and first_ins == -1:
        first_ins = i
    elif g >= 6:
        last_suf = i

if first_ins == -1 or last_suf == -1 or first_ins > last_suf:
    print(-1)
else:
    print(last_suf - first_ins + 1)
