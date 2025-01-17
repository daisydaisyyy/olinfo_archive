#include<bits/stdc++.h>
using namespace std;


// bfs to explore the graph  
// better solve than plain bfs by using precomputation 
// still using too much memory (80/100 points)

queue<int> q;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input0.txt");
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
	
 

	vector<vector<int>> d(N,vector<int>(N , -1)); 
	
	for(int s = 0; s < N; ++s) {
		vector<bool> used(N);
		//vector<int> p(N);
		q.push(s);
		used[s] = true;
		d[s][s] = 0;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int u : adj[v]) {
				if (!used[u]) {
					used[u] = true;
					q.push(u);
					d[s][u] = d[s][v] + 1;
			        //p[u] = v;
				}
			}
		}	
			
	}

	for(auto &query : queries) {
		int s = query.first; int t = query.second;
		int ans = d[s][t]; // if never visited, then the s and t are not connected
		cout << ans << " ";


	}

		
	cout << endl;

    return 0;
}
