#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;
// without segment tree

int main() {
    int N, K;
    // ifstream cin("input1.txt");
    cin >> N >> K;
    
    vector<int> T(N);
    for (int i = 0; i < N; ++i)
        cin >> T[i];

    // precompute min beauty
    vector<vector<int>> minB(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            minB[i][j] = (i == j) ? T[i] : min(minB[i][j-1], T[j]);
        }
    }

    // dp
    vector<vector<long long>> dp(N+1, vector<long long>(K+1, LLONG_MIN));
    dp[0][0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int k = 1; k <= K; ++k) {
            for (int j = 0; j < i; ++j) {
                dp[i][k] = max(dp[i][k], dp[j][k-1] + minB[j][i-1]); // start a new boquet or take tulip
            }
        }
    }

    cout << dp[N][K] << endl;


    return 0;
}
