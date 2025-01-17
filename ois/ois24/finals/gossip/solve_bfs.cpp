#include<bits/stdc++.h>
using namespace std;


// slow solve: bfs to explore the graph  
// update distances and check if target node is visited

queue<int> q;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input1.txt");
    // ofstream cout("output.txt");

    int N, x;
    cin >> N;
    //vector<int> P(N);
	vector<vector<int>> adj(N); 
	for (int i = 0; i < N; ++i) {
        cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}

    int Q;
    cin >> Q;

    vector<pair<int,int>> queries(Q);
	
    for (int i = 0; i < Q; ++i)
        cin >> queries[i].first >> queries[i].second;

	int s, t;
	for(int i = 0; i < Q; ++i) {
		vector<bool> used(N);
		vector<int> d(N,0), p(N);

		s = queries[i].first; 
		t = queries[i].second;
		q.push(s);
		used[s] = true;
		p[s] = -1;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int u : adj[v]) {
				if (!used[u]) {
					used[u] = true;
					q.push(u);
					d[u] = d[v] + 1;
			        p[u] = v;
				}
			}
		}	
		int ans = used[t] ? d[t] : -1; // if never visited, then the s and t are not connected
		cout << ans << " ";
		
	}

		
	cout << endl;

    return 0;
}
