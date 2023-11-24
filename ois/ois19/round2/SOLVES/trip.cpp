/* Minor variation over the standard Dijkstra algorithm
 */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

struct edge_t {
    int end;
    int t0;
    int t1;
};


int main() {
    int N, M, S, E;

    cin >> N;
    cin >> S >> E;

    cin >> M;
    vector<vector<edge_t>> adj(N);
    for (int i=0; i<M; i++) {
        int start, t0, end, t1;
        cin >> start >> t0 >> end >> t1;

        adj[start].push_back({end, t0, t1});
    }

    vector<int> dist(N, numeric_limits<int>::max());
    dist[S] = 0;

    priority_queue<pair<int, int>> q;
    q.push({-dist[S], S});

    while (!q.empty()) {
        auto t = q.top();
        q.pop();

        int w = -t.first;
        int u = t.second;

        for (edge_t v: adj[u]) {
            if (w <= v.t0) {
                if (dist[v.end] > v.t1) {
                    dist[v.end] = v.t1;
                    q.push({-dist[v.end], v.end});
                }
            }
        }
    }

    if (dist[E] < numeric_limits<int>::max())
        cout << dist[E] << endl;
    else
        cout << "IMPOSSIBLE" << endl;
}
