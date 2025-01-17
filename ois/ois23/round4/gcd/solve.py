#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N = int(input().strip())
D = int(input().strip())


# insert your code here
min_floor = (10 ** (N-1) + D - 1) // D 
min_mult = min_floor * D 
next_mult = (min_floor+1) * D
if next_mult >= 10 ** N:
	print(0, 0)
else:
	print(min_mult, next_mult)  # print the result

