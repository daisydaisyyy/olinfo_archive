#!/usr/bin/env python3
# COMPLEXITY: O(T)
# IDEA: Either the bugs go directly for each other, or they meet in the center of the bed.

import math

def dist(A, B):
    x = A[0]-B[0]
    y = A[1]-B[1]
    return math.sqrt(x*x + y*y)

# input data
T = int(input().strip())

for _ in range(T):
    Xa, Ya, Xb, Yb, Xc, Yc, R = map(float, input().strip().split())

    A = (Xa, Ya)
    B = (Xb, Yb)
    C = (Xc, Yc)

    distAB = dist(A, B) # bugs going directly for each other
    distAC = max(0.0, dist(A, C) - R) # bug A goes for the bed
    distBC = max(0.0, dist(B, C) - R) # bug B goes for the bed

    result = min(distAB, distAC + distBC)

    # print result (round down and print six decimals)
    # DO NOT EDIT!
    result = math.floor(result * 10**6) / 10**6
    print("{:.6f}".format(result))
