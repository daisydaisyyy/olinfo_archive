#!/usr/bin/env python3
# COMPLEXITY: O(K log N)
# IDEA: I keep a priority queue (heapq, but an ordered set would also work)
# with the increments in expected value for each possible bug-shot.

import heapq
import math

# input data
T = int(input().strip())
for _ in range(T):
    N, K = map(int, input().strip().split())
    probs = list(map(float, input().strip().split()))

    result = 0.0
   
    pq = []
    heapq.heapify(pq)
    for prob in probs:
        heapq.heappush(pq, [-prob, -(1.0 - prob)])

    for _ in range(K):
        chance, multiplier = [-x for x in heapq.heappop(pq)]
        result += chance
        chance *= multiplier
        heapq.heappush(pq, [-chance, -multiplier])

    result = math.floor(result * 10**6) / 10**6
    print("{:.6f}".format(result))

