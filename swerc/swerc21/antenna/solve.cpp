#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> p;
constexpr ll INF = 1e8;
ll bfs(vector<vector<ll>> &adj, ll n, ll source, ll target) {
    queue<ll> q;
    vector<bool> vis(n, false); // Keeps track of visited nodes
    vector<ll> dist(n, INF);   // Stores the shortest distance to each node

    vis[source] = true; 
    dist[source] = 0;
    q.push(source);

    while (!q.empty()) {
        ll curr = q.front();
        q.pop();

        // iter adjacent nodes
        for (ll x : adj[curr]) {
            if (!vis[x]) {
                vis[x] = true;
                dist[x] = dist[curr] + 1; // update
                //cout << "dist from " << curr << " to " << x <<": " << dist[x] <<endl;
				q.push(x);
            }
        }
    }

    return dist[target] == INF ? -1 : dist[target]; // Return -1 if target is unreachable
}

int main() {
	ifstream cin("input0.txt"); 
	ll t; cin >> t; 

	while(t--) {
		ll n, source, dest; cin >> n >> source >> dest; 
		vector<vector<ll>> adj(n);
		p.resize(n);
		for(auto &x : p) cin >> x;
		for(int i = 0; i < n; i++) {
			for(int j= i+1; j < n; j++) {
				if(abs(i-j) <= min(p[i],p[j])) {
					adj[i].push_back(j);
					adj[j].push_back(i);

				}
			}
		}

		/*
		for(int i = 0; i < n; i++ ){
			cout << i+1 << ": ";
			for(auto x : adj[i]) cout << x+1 << "\t";
			cout << endl;
		}
		*/
		cout << bfs(adj, n, source-1, dest-1) << endl;
	}

	return 0;

}
