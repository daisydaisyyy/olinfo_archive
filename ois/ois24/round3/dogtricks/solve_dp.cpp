#include <bits/stdc++.h>
using namespace std;

/*
M = number of pairs
N = number of tricks
K = end tricks
*/

#define MAXN 200000
#define MAXK 200000
#define MAXM 200000

int N, K;
vector<int> T;
vector<long long> memo;
vector<set<int>> known_pairs;


/*
top down recursive approach: worse solution than top down iterative for complexity 
TODO: currently isnt covering all testcases, update to cover them (checker error? apparently testcase1 is wrong)
*/ 
long long solve(int i) {
    if (i >= N) return 0;


    if (memo[i] != -1e9) return memo[i];

    long long curr_max = -1e9;

    
    if (T[i] == K + 1) { // not known, skip
        curr_max = max(curr_max, solve(i + 1));
    } else {
        
        if (i + 1 == N || (i + 1 < N && known_pairs[T[i]].count(T[i + 1]))) { // take it if known
            curr_max = max(curr_max, 1 + solve(i + 1));
        }

        
        if (i + 2 == N || (i + 2 < N && known_pairs[T[i]].count(T[i + 2]))) { // skip next and perform curr trick + 2
            curr_max = max(curr_max, 1 + solve(i + 2));
        }
    }
    // do nothing
    if (curr_max == -1e9) curr_max = 0;

    return memo[i] = curr_max;
}

int main() {
    // Uncomment the following lines if you want to read/write from files
    ifstream cin("input1.txt");
    // ofstream cout("output.txt");

    // Read N and K
    cin >> N >> K;

    T.reserve(N);
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        T.push_back(a);
    }

    int M;
    cin >> M;
    known_pairs.assign(K + 1, set<int>()); 
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        if (a <= K) { 
            known_pairs[a].insert(b);
        }
    }
    memo.assign(N + 1, -1e9);

    long long result0 = solve(0);
    long long result1 = solve(1);

    long long final_answer = max({result0, result1, 0LL});

    cout << final_answer << endl;
    return 0;
}

/*
old code: wrong because dp state depends only on current trick and if its the 1st elem of a known pair, we dont need to save the last trick 


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

*/