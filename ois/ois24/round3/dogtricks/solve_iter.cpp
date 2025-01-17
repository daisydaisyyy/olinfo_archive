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

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input0.txt");
    // ofstream cout("output.txt");
    cin >> N >> K;
    //dp = vector<vector<vector<int>>>(N + 1, vector<vector<int>>(K, vector<int>(3, -1)));

	
	//for(int i = 0; i <= K; i++) dp[0][i] = 0;
    
    int a;
    
    for (int i = 0; i < N; ++i) {
        cin >> a;
        T.push_back(a);
    }    
    
    int M;
    cin >> M;
    int b;
    vector<set<int>> known(K+1); 
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        known[a].insert(b);
    }
    
    int P = 0;

    // cout << "call solve";
    vector<int> dp(N + 1, -1e9); 
	dp[N] = 0;

	//bottom up iterative approach
	for(int i = N-1; i >= 0; i--) {
		//cout << i << endl;
		if(T[i] == K+1) {
			//cout << i << " not known" << endl;
			continue;
		}
		if(i+1 == N or (i+1 < N and known[T[i]].count(T[i+1]))) dp[i] = max(dp[i],1+dp[i+1]);
		if(i+2 == N or (i+2 < N and known[T[i]].count(T[i+2]))) dp[i] = max(dp[i],1+dp[i+2]); // skip trick
		//cout << "i: " << i << " dp: " << dp[i] << endl;
	}

	cout << max({dp[0],dp[1],0}) << endl;
    return 0;
}

