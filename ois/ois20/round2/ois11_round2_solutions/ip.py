#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
A = list(map(int, input().split(".")))
B = list(map(int, input().split(".")))

# at this point, the arrays A and B contain four elements each with the individual IP octects
# for example: 192.168.1.1 creates an array [192, 168, 1, 1] with 192 at index 0

ans = 0
exp = 0
for i in range(3, -1, -1):
    diff = B[i] - A[i]
    # Note: this works even when diff is less than 0
    ans += diff * (256 ** exp)
    if exp == 0:
        ans += 1
    exp += 1

print(ans)
