// NOTE: it is recommended to use this even if you don't understand the following code.

#include<bits/stdc++.h> 
using namespace std;

/*
M = n pairs
N = num tricks
K = end tricks
*/

#define MAXN 200000
#define MAXK 200000
#define MAXM 200000

int N, K;
vector<int> T;
vector<vector<int>> dp; // round, last trick, points
set<pair<int,int>> known; // A, B


int solve(int n, int last, int skipped) {
    if (skipped == 2) return -1; // out: skip 2 tricks (0 points)
    if (n == N) return 0; // rounds end

    cout << "n: " << n << "\tlast: " << last << "\tskipped: " << skipped << endl;
    if (dp[n][last] != -1) return dp[n][last];

    int perform = -1;
    
    if (T[n] <= K && (last == 0 || known.find({last, T[n]}) != known.end())) {
        perform = solve(n + 1, T[n], 0) + 1; // do trick
    }

    // skip trick
    int skip = solve(n + 1, last, skipped + 1);

    cout << "perform: " << perform << "\tskip: " << skip << endl;
    if (perform == -1 && skip == -1) return dp[n][last] = -1; // out (0 points)
    return dp[n][last] = max(perform, skip); // calc max
}



int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input1.txt");
    // ofstream cout("output.txt");
    cin >> N >> K;
    dp = vector<vector<int>>(N + 1, vector<int>(K + 1, -1));
    
    int a;
    
    for (int i = 0; i < N; ++i) {
        cin >> a;
        T.push_back(a);
    }    
    
    int M;
    cin >> M;
    int b;
    
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        known.insert({a,b});
    }
    
    int P = 0;
    // cout << "call solve";
    P = solve(0, 0, 0);  
    cout << P << endl;

    return 0;
}
