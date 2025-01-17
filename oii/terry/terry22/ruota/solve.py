#!/usr/bin/env python3

import sys

# se preferisci leggere e scrivere da file
# ti basta decommentare le seguenti due righe:

sys.stdin = open('in.txt')
sys.stdout = open('output.txt', 'w')

def solve(t):
    input() # prima riga vuota

    N = int(input().strip())

    V = list(map(int, input().strip().split()))
    G = list(map(int, input().strip().split()))
    assert len(V) == len(G) == N

    # aggiungi codice...
    risposta = 10**100
    for off in range(N): 
        sum = 0
        for j in range(N):
            sum += V[j] * G[(j - off)]
        risposta = min(sum, risposta)

    print(f"Case #{t}: {risposta}")


T = int(input().strip())

for t in range(1, T+1):
    solve(t)

sys.stdout.close()

