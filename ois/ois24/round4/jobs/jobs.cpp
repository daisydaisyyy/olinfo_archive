#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

long long N, M;
using namespace std;
vector<pair<long long, long long>> jobs;

long long solve() {
    vector<vector<long long>> dp(2, vector<long long>(M + 1, 0));

    for (long long i = 1; i <= N; ++i) {
        for (long long j = 1; j <= M; ++j) {
            dp[i % 2][j] = dp[(i - 1) % 2][j];

            if (jobs[i - 1].first <= j) {
                dp[i % 2][j] = max(dp[i % 2][j], dp[i % 2][j - jobs[i - 1].first] + jobs[i - 1].second);
            }
        }
    }

    return dp[N % 2][M];
}

int main() {
    // ifstream cin("input1.txt");

    cin >> N >> M;
    long long t, p;

    for (long long i = 0; i < N; ++i) {
        cin >> t;
        jobs.push_back({t, 0});
    }

    for (long long i = 0; i < N; ++i) {
        cin >> p;
        jobs[i].second = p;
    }

    long long maxMoney = solve();

    cout << maxMoney << endl;

    return 0;
}
