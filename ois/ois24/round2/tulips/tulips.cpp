// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;
vector<vector<long long>> dp;
int N, K;
vector<int> T;
void buildTree(const vector<int>& T, vector<int>& segTree, int l, int r, int pos) {
    if (l == r) {
        segTree[pos] = T[l];
        return;
    }

    int mid = (l + r) / 2;
    buildTree(T, segTree, l, mid, 2 * pos + 1);
    buildTree(T, segTree, mid + 1, r, 2 * pos + 2);
    segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}

// Function to query the segment tree for minimum beauty in range [ql, qr]
int queryTree(const vector<int>& segTree, int l, int r, int ql, int qr, int pos) {
    if (ql <= l && qr >= r) // Total overlap
        return segTree[pos];
    if (ql > r || qr < l) // No overlap
        return INT_MAX;

    int mid = (l + r) / 2;
    return min(queryTree(segTree, l, mid, ql, qr, 2 * pos + 1),
               queryTree(segTree, mid + 1, r, ql, qr, 2 * pos + 2));
}

long long solve(const vector<int>& T, int N, int K) {
    vector<vector<long long>> dp(N + 1, vector<long long>(K + 1, 0));
    vector<int> segTree(4 * N); // Segment tree for minimum queries
    buildTree(T, segTree, 0, N - 1, 0);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= min(i, K); ++j) {
            dp[i][j] = 0;
            for (int x = j; x <= i; ++x) {
                long long currentBeauty = queryTree(segTree, 0, N - 1, x - 1, i - 1, 0);
                if (j == 1) {
                    dp[i][j] = max(dp[i][j], currentBeauty);
                } else {
                    dp[i][j] = max(dp[i][j], dp[x - 1][j - 1] + currentBeauty);
                }
            }
        }
    }

    return dp[N][K];
}





int main() {
    // uncomment the two following lines if you want to read/write from files
     ifstream cin("input1.txt");
    // ofstream cout("output.txt");

    
    cin >> N >> K;
    
    T.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> T[i];
    
    long long M = 0;
    
    
    // INSERT YOUR CODE HERE
//    dp = vector<vector<int>>(N, vector<int>(K, 0));
    M = solve(T, N, K);
    
    cout << M << endl;

    return 0;
}
