#include <bits/stdc++.h>
using namespace std;

void solve() {
	ifstream cin("input0.txt");
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> edges(m);
        vector<vector<int>> adj(n + 1);
        
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            edges[i] = {u, v};
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> assigned(m);
        bool cycle = false;

        // BFS to detect cycles
		vector<int> visited(n + 1, -1);
        function<void(int)> bfs = [&](int start) {
            queue<int> q;
            q.push(start);
            visited[start] = 1;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (visited[v] == -1) { // not visited
                        visited[v] = 3 - visited[u];
                        q.push(v);
                    } else if (visited[v] == visited[u]) cycle = true;
                    
                }
            }
        };

        bfs(1);

        int k = cycle ? 4 : 3;
        cout << k << '\n';
        for (int i = 0; i < m; ++i) {
            if (cycle) {
                assigned[i] = (i % k) + 1;
            } else {
                int u = edges[i].first, v = edges[i].second;
                assigned[i] = (visited[u] != visited[v]) ? 1 : 2;
            }
        }

        for (int i = 0; i < m; ++i) {
            cout << assigned[i] << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
