#include <bits/stdc++.h> 
using namespace std;

//input data
int N, R, T,L; 
vector<int> X;
vector<vector<vector<int>>> dp;

void solve() {
    dp.assign(N + 1, vector<vector<int>>(R + 1, vector<int>(2 * T, INT_MAX)));

    // Base case: when we are at the last semaphore (idx == N)
    for (int r = 0; r <= R; r++) {
        for (int t = 0; t < 2 * T; t++) {
            dp[N][r][t] = 0;  // At the last semaphore, no more time is needed to reach the destination.
        }
    }

    // Fill the DP table from idx = N-1 to 0
    for (int idx = N - 1; idx >= 0; idx--) {
        for (int r = 0; r <= R; r++) {
            for (int t = 0; t < 2 * T; t++) {
                // Calculate the time to reach the next semaphore
                int skip = X[idx + 1] - X[idx];
                int newTime = (t + skip) % (2 * T);

                bool red = (t >= T);  // Check if the current semaphore is red

                if (!red) {
                    // Green light: we can pass without waiting
                    dp[idx][r][t] = dp[idx + 1][r][newTime] + skip;
                } else {
                    // Red light: we either wait or skip if we have skips left
                    int waitTime = skip + (2 * T - t);  // Time including the wait for green

                    if (r > 0) {
                        // Option to skip the red light
                        dp[idx][r][t] = min(dp[idx + 1][r - 1][newTime] + skip,
                                            dp[idx + 1][r][(t + waitTime) % (2 * T)] + waitTime);
                    } else {
                        // No skips left, we must wait for the green light
                        dp[idx][r][t] = dp[idx + 1][r][(t + waitTime) % (2 * T)] + waitTime;
                    }
                }
            }
        }
    }
}

int main() {
	ifstream cin("input1.txt");

    cin >> N >> R >> T >> L;
    X.resize(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    X[N] = L;

    solve();

    // The result is stored in dp[0][R][X[0] % (2 * T)], starting at semaphore 0, with R skips and X[0] time
    cout << dp[0][R][X[0] % (2 * T)] + X[0] << endl;

    return 0;
}
