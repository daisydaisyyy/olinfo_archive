#!/usr/bin/env python3

R, C, K = map(int, input().strip().split())

print(((R + K - 1) // K) * ((C + K - 1) // K))
