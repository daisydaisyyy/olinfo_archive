#!/usr/bin/env python3
# @check-memory-limit-exceeded: task

d, n = map(int, input().split())

s = str(d)
for i in range(2, n + 1):
    s = s + str(i) + s

print(sum(int(x) for x in s))
