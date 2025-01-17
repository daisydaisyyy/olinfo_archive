#!/usr/bin/env python3
# @check-accepted: task

d, n = map(int, input().split())

ans = d
for i in range(2, n + 1):
    ans = 2 * ans + sum(int(x) for x in str(i))

print(ans)
