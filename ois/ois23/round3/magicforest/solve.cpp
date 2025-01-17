// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;

#define MAXN 500'001

/*
 * magical walk if ci +1 = c_(i+1) ex. 3,4,5,6... 
 * different if the sequence of edges is different (-> different ctot?) 
 * a -> b with weight c 
 */
const int MOD = 1e9 + 7;
map<int,int> memo[MAXN]; // source, cost 
int main() {
    // uncomment the following lines if you want to read/write from files
    ifstream cin("input1.txt");
    // ofstream cout("output.txt");

    int N, M;
    cin >> N >> M;
    vector<tuple<int,int,int>> trails(M);

    for (auto &[c,a,b]: trails) cin >> a >> b >> c;
	
	sort(trails.rbegin(), trails.rend()); // ordering giving the cost
    // calc for every node, the possible paths with different cost 
	for(auto [c,a,b] : trails) { 
		// cost for source and dest (bidirectional)
		memo[a][c-1] = (memo[a][c-1] + memo[b][c] + 1) % MOD; 
		memo[b][c-1] = (memo[b][c-1] + memo[a][c] + 1) % MOD;
	}

	int tot = 0; 
	for(int i = 0; i <= N; i++) 
		for(auto [_, n]: memo[i]) 
			tot = (tot + n) % MOD; // all paths
	
    cout << (tot - M + MOD) % MOD << endl; // remove duplicates
    return 0;
}
