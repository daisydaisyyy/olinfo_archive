// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>
using namespace std;

/*
 * solve:  
 * dfs to explore tree 
 * binary search to find the longest subset of nodes 
 */


int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input0.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;
	vector<vector<int>> adj(N); 
	

    for (int i = 0; i < N - 1; ++i) {
		int u, v;
        cin >> u >> v; 
		u--; v--; 
		adj[u].push_back(v);
		adj[v].push_back(u); // bidirectional edge
	}

    function<int(int, int, int)> dfs = [&](int node, int parent, int m) -> int {
		vector<int> child_paths;
		for(auto child : adj[node]) {
			if(child == parent) continue;
			int p = dfs(child, node, m); // set path 
			if(p == -1) return -1; // not found
			child_paths.push_back(p + 1); // add path
		}
		sort(child_paths.begin(), child_paths.end());
		
		if(node == 0) {
			multiset<int> values(child_paths.begin(), child_paths.end());
			while (!values.empty()) {
				int val = *values.begin(); 
				values.erase(values.begin()); 
				auto it = values.lower_bound(m - val); // find shortest path 
				if (it == values.end()) return 0; // not found 
				else values.erase(it); // remove path already evaluated
			}
			return 1;
		}

		int l = -1, r = child_paths.size(); 
	
		// binary search
		while(l < r - 1) {
			int mid  = (l + r) / 2; 
	
			vector<int> paths = child_paths; 
			paths.erase(paths.begin() + mid); 

			multiset<int> values(paths.begin(), paths.end()); 

			while(!values.empty()) {
				int val = *values.begin(); 
				values.erase(values.begin()); 
				auto it = values.lower_bound(m - val); 
				if(it == values.end()) {
					r = mid;
					goto next;
				}
				else values.erase(it); 
			}
			l = mid; 
			next:;
		}


		if(l != -1) return child_paths[l];
		if(child_paths.size() & 1) return -1; // size is odd 
	

		for(int i = 0; i < child_paths.size() / 2; i++) {
			if(child_paths[i] + child_paths[child_paths.size() - i - 1] < m) return -1;
		}
		return 0;
	};

	int l = 0, r = N;
	while(l < r - 1) {
		int mid = (l + r) / 2; 
		if(dfs(0, -1, mid) == 1) l = mid; 
		else r = mid; 
	}
    
    
    cout << l << endl;

    return 0;
}
