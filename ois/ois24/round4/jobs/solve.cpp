#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

long long N, M;
using namespace std;
vector<pair<long long, long long>> jobs;
vector<vector<long long>> dp;

long long solve(int idx, long long time) {
    if (idx == N || time == 0)
        return 0;

    if (dp[idx][time] != -1)
        return dp[idx][time];

    long long exclude = solve(idx + 1, time);

    if (jobs[idx].first <= time) {
        long long include = solve(idx, time - jobs[idx].first) + jobs[idx].second;
        dp[idx][time] = max(include, exclude);
    } else {
        dp[idx][time] = exclude;
    }

    return dp[idx][time];
}

int main() {
    ifstream cin("input0.txt");

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

    dp.assign(N, vector<long long>(M + 1, -1));

    long long maxMoney = solve(0, M);

    cout << maxMoney << endl;

    return 0;
}

