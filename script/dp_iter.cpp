int N, K;
vector<int> T;

int main() {
    cin >> N >> K;
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

    vector<int> dp(N + 1, -1e9); 
	dp[N] = 0;

	//bottom up iterative approach
	for(int i = N-1; i >= 0; i--) {
		//cout << i << endl;
		if(T[i] == K+1) continue;
		if(i+1 == N or (i+1 < N and known[T[i]].count(T[i+1]))) dp[i] = max(dp[i],1+dp[i+1]);
		if(i+2 == N or (i+2 < N and known[T[i]].count(T[i+2]))) dp[i] = max(dp[i],1+dp[i+2]); // skip trick
	}
	cout << max({dp[0],dp[1],0}) << endl;
}

