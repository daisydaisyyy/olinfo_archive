#include <iostream>
#include <vector>
#include <climits>
#include<fstream>

using namespace std;

// Precomputed minimum values for each range [i, j]
vector<vector<int>> minInRange;

// Recursive function to compute dp[i][k]
void computeDP(int i, int k, int l, int r, int optl, int optr, vector<vector<long long>>& dp) {
    if (l > r) return;

    int mid = (l + r) / 2;
    pair<long long, int> best = {LLONG_MIN, -1};

    for (int j = optl; j <= min(mid, optr); j++) {
        long long val = dp[j][k-1] + minInRange[j][mid];
        if (val > best.first) {
            best = {val, j};
        }
    }

    dp[mid][k] = best.first;
    computeDP(i, k, l, mid-1, optl, best.second, dp);
    computeDP(i, k, mid+1, r, best.second, optr, dp);
}

int main() {
    int N, K;
    ifstream cin("input0.txt");
    cin >> N >> K;

    vector<int> T(N);
    for (int i = 0; i < N; ++i)
        cin >> T[i];

    // Compute the minimum values for each range [i, j]
    vector<vector<long long>> dp(N+1, vector<long long>(K+1, LLONG_MIN));
    dp[0][0] = 0;

    for (int k = 1; k <= K; ++k) {
        computeDP(N, k, 1, N, 0, N-1, dp);
    }

    cout << dp[N][K] << endl;

    return 0;
}
