#!/usr/bin/env python3

import sys

# se preferisci leggere e scrivere da file
# ti basta decommentare le seguenti due righe:

# sys.stdin = open('input.txt')
# sys.stdout = open('output.txt', 'w')


def solve(t):
    input() # prima riga vuota

    x1, y1 = map(int, input().strip().split())
    x2, y2 = map(int, input().strip().split())
    x3, y3 = map(int, input().strip().split())

    # aggiungi codice...
    x4 = x1 ^ x2 ^ x3
    y4 = y1 ^ y2 ^ y3
    
    print(f"Case #{t}: {x4} {y4}")


T = int(input().strip())

for t in range(1, T + 1):
    solve(t)

sys.stdout.close()

