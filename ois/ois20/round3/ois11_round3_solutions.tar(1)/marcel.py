#!/usr/bin/env pypy3

MOD = 10**9+7

# input data
N, X = map(int, input().strip().split())
M = [list(map(int, input().strip().split())) for _ in range(N)]

pref = [[0 for _ in range(N)] for _ in range(N)]
pref[0][0] = M[0][0]
for i in range(1, N):
    pref[0][i] = pref[0][i-1] + M[0][i]
    pref[i][0] = pref[i-1][0] + M[i][0]
for i in range(1, N):
    for j in range(1, N):
        pref[i][j] = pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1] + M[i][j]

def get_sum(l1, c1, l2, c2):
    if l1 == 0:
        if c1 == 0:
            return pref[l2][c2]
        else:
            return pref[l2][c2] - pref[l2][c1-1]
    if c1 == 0:
        return pref[l2][c2] - pref[l1 - 1][c2]
    return pref[l2][c2] - pref[l1-1][c2] - pref[l2][c1-1] + pref[l1-1][c1-1]


dp = [[[[0 for _ in range(N)] for _ in range(N)] for _ in range(N)] for _ in range(2)]

def update(l1, c1, l2, c2):
    if l1 > l2 or c1 > c2:
        return 1
    else:
        return dp[l1 & 1][l2][c1][c2]

for l1 in range(N-1, -1, -1):
    for l2 in range(l1, N):
        for c1 in range(N-1, -1, -1):
            for c2 in range(c1, N):
                dp[l1 & 1][l2][c1][c2] = 1
                # print("get_sum(l1, c1, l2, c2) -> ", get_sum(l1, c1, l2, c2))
                if get_sum(l1, c1, l1, c2) >= X:
                    dp[l1 & 1][l2][c1][c2] += update(l1 + 1, c1, l2, c2)
                if get_sum(l1, c1, l2, c1) >= X:
                    dp[l1 & 1][l2][c1][c2] += update(l1, c1 + 1, l2, c2)
                if get_sum(l2, c1, l2, c2) >= X:
                    dp[l1 & 1][l2][c1][c2] += update(l1, c1, l2 - 1, c2)
                if get_sum(l1, c2, l2, c2) >= X:
                    dp[l1 & 1][l2][c1][c2] += update(l1, c1, l2, c2 - 1)
                dp[l1 & 1][l2][c1][c2] %= MOD
                # print(l1, l2, c1, c2, "->", dp[l1 & 1][l2][c1][c2])
print(dp[0][N-1][0][N-1])
