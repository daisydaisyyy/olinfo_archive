#!/usr/bin/env python3
# COMPLEXITY: O(N log V)
# IDEA: Binary search on the solution. To test a number of days, count the minimum number of
# uses of the most powerful diffuser you need at minimum, and check whether it fits the bounds.


# input data
N, K = map(int, input().strip().split())
P, Q = map(int, input().strip().split())
V = list(map(int, input().strip().split()))

if P > Q:
    P, Q = Q, P
    K = N-K

mV = max(V)
a = (mV-1)//Q + 1 # this I definitely need
b = (mV-1)//P + 1 # and with this I am definitely fine

while a < b:
    c = (a+b)//2 # let's try c days
    extra = sum((max(x - c*P, 0) + Q-P-1) // (Q-P) for x in V) # need of extra sprays
    if extra > (N-K)*c: # c is not enough
        a = c+1
    else:
        b = c


print(a)  # print the result
