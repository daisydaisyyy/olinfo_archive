#!/usr/bin/env python3
# Same as soluzione.cpp: computes the GCD among all numbers, then
# prints all its divisors checking up to the square root.

from math import gcd

# input data
N = int(input().strip())
C = list(map(int, input().strip().split()))

sol = C[0]
for c in C[1:]:
    sol = gcd(sol, c)

divisors = []
div = 1
while div * div <= sol:
    if sol % div == 0:
        divisors.append(div)
        if sol // div != div:
            divisors.append(sol // div)
    div += 1

for div in sorted(divisors):
    print(div, end=" ")
print()
