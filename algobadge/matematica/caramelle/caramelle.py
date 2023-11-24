#! /usr/bin/env python3
import sys
from sage.arith.functions import LCM_list

with open('output.txt', 'a') as output_file:
    def solve(t, N, V):
        # print(LCM_list(V))
        
        print(LCM_list(V), file=output_file)
        # print(f"Case #{t}: 42")

    # calcola lcm (minimo comune multiplo)

    with open('caramelle_input_3.txt', 'r') as file:
        
        T = int(file.readline().strip())

        for t in range(1, T+1):
            file.readline()
            N = int(file.readline().strip())
            V = list(map(int, file.readline().strip().split()))
            solve(t, N, V)

    output_file.close()
