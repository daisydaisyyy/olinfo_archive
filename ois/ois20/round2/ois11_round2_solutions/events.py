#!/usr/bin/env python3

N, V = map(int, input().split())
prices = list(map(int, input().split()))
vouchers = list(map(int, input().split()))

prices.sort()
vouchers.sort()

prices_idx = 0
matched = 0
for vouchers_idx in range(V):
    if prices_idx == N:
        break
    if vouchers[vouchers_idx] >= prices[prices_idx]:
        matched += 1
        prices_idx += 1
    
print(matched)
