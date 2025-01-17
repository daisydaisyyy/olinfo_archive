#include<bits/stdc++.h>
using namespace std;


pair<int,int> dfs(int curr, int prev, int depth, vector<vector<int>> &edges) {

	pair<int,int> res = {-1,-1};

	if(edges[curr].size() <= 1)
		res.first = curr;

	if(depth % 2 == 0) res.second = curr; // player b can take  
	else res.first = curr; // player a

	vector<int> memo; 
	if(depth > 0) memo.push_back(edges.size()-1);

	for(int next : edges[curr]) {
		if(next != prev) { 
			pair<int,int> tmp = dfs(next, curr, depth+1, edges); // visit ancestor, increase depth 
			
			// update best result
			res.first = max(res.first, tmp.first); 
			res.second = max(res.second, tmp.second);
			if(tmp.second != -1) memo.push_back(tmp.second);
		}
	}

	sort(memo.begin(), memo.end(), greater<int>());
	if(depth % 2 == 0 and memo.size() > 2) res.first = max(res.first, memo[2]);

	return res;
}

int main()
{
	ifstream cin("input0.txt");
	int n; cin >> n;
  
	vector<vector<int>> edges(n);
	for (int i=0; i<n-1; i++) {
		int a, b; cin >> a >> b;
		edges[a-1].push_back(b-1);
		edges[b-1].push_back(a-1);
	}

	if (n % 2 == 1) cout << dfs(n-1, -1, 0, edges).first+1 << endl;
	else cout << n << endl;
}

