#include<bits/stdc++.h>
using namespace std;



int main() {
	ifstream cin("input0.txt"); 
	int n; cin >> n;

	vector<vector<int>> adj(n);

	for(int i = 0; i < n-1; ++i) {
		int a, b; 
		cin >> a; 
		--a; // 1-indexed -> 0-indexed
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> visited(n);


	return 0;

}
