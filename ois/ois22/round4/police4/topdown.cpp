#include <bits/stdc++.h>

using namespace std;

// input data
int N, R, T, L;
vector<int> X;
vector<vector<vector<int>>> memo;

int solve(int idx, int r, int t) {
    if (idx == N) {
        return 0;
    }
    if (r >= N - idx) {
        return L - X[idx];
    }
    t = t % (T * 2);

    if (memo[idx][r][t] != -1) {
        return memo[idx][r][t];
    }

    bool red = (t >= T);

    int skip = X[idx + 1] - X[idx];
    if (!red) { // green, no need to wait
        memo[idx][r][t] = solve(idx + 1, r, (t + skip) % (T * 2)) + skip;
    } else { 
        int taken = skip + (2 * T - t);
        if (r > 0) { // still has skips
            memo[idx][r][t] = min(solve(idx + 1, r - 1, (t + skip) % (T * 2)) + skip,
                                   solve(idx + 1, r, (t + taken) % (T * 2)) + taken);
        } else { // no skips
            memo[idx][r][t] = solve(idx + 1, r, (t + taken) % (T * 2)) + taken;
        }
    }
    return memo[idx][r][t];
}

int main() {
    ifstream cin("input0.txt");

    cin >> N >> R >> T >> L;
    X.resize(N + 1);
    for (int i = 0; i < N; i++)
        cin >> X[i];
    X[N] = L;

    memo.assign(N + 1, vector<vector<int>>(R + 1, vector<int>(2 * T, -1)));

    cout << solve(0, R, X[0]) + X[0] << endl; 
    return 0;
}
