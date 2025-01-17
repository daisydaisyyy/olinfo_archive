#include <bits/stdc++.h>
using namespace std;

/*
strat: dijkstra using priority queue (this is a sparse graph -> few edges)

*/


int main() {
	//ifstream cin("input0.txt");
    int N, M, L; cin >> N >> M >> L;

    set<int> adj[N];
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    vector<int> C(L);
    for (auto &x : C) cin >> x;

    priority_queue<pair<int, int>> q;
    q.push({0, 0});
    vector<bool> visited(N);

    while (!q.empty()) {
        auto [dst, node] = q.top(); 
        q.pop();
        if (visited[node]) continue;

        // c++ priority_queue is a max queue (largest elements at the top)
        // in this case to find min path we want the smaller at the top 
        // to ensure that, do d *= -1 so that the min path will be at the top
        dst *= -1;

        // traversed all nodes
        if (node == N - 1) {
            cout << dst << endl;
            return 0;
        }

        visited[node] = true;

        for (auto neighbor: adj[node]) {
            if (!visited[neighbor]) {
                if (C[(dst + 1) % L] != neighbor) { // if guards aren't on next node
                    q.push({-(dst + 1), neighbor}); // -(dst+1), move to the node the next minute
                } else { // guards on next node
                    q.push({-(dst + 2), neighbor}); // -(dst+1+1), wait 1 minute for the guards to move and then move to the node the next minute
                }
            }
        }
    }

    cout << -1 << endl;  // path not found
    return 0;
}
