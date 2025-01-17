#!/usr/bin/env python3

import sys

# se preferisci leggere e scrivere da file
# ti basta decommentare le seguenti due righe:

#sys.stdin = open('in.txt')
#sys.stdout = open('output.txt', 'w')

# dp iterative approach
# non posso avere + di 3 file consecutive con fin chiusi da un lato 
# ogni 4 finestrini devo avere: 
# LLR / RRL / LRL / RLR 
# calcolo tutte le configurazioni possibili (quelle elencate) 
# per ogni subproblem di 4 finestrini (ogni volta slide di una posizione)
# simile a sliding window ma con un modo piu' intelligente (senza array/memory ecc..)
def solve(t):
    input()

    N = int(input().strip())
    LL, RR, LR, RL = 0, 0, 0, 0

    for i in range(N):
        L, R = map(int, input().strip().split())

        LL, LR, RL, RR = ( 
            RL + L, 
            min(RL,LL) + R, 
            min(LR,RR) + L, 
            LR + R
        )

    print(f"Case #{t}: {min(LL,RR,RL,LR)}")


T = int(input().strip())

for t in range(1, T+1):
    solve(t)

sys.stdout.close()

