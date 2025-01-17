#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;


struct Edge {
    int to, cost;
    bool explodes;
    Edge(int to, int cost, bool explodes) : to(to), cost(cost), explodes(explodes) {}
};


typedef pair<int, int> p;
vector<vector<Edge>> graph;

int dijkstra(int N, int T) {
	// cout << "explodes at: " << T << endl;
    vector<int> dist(N, INT_MAX);
    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push(p(0, 0));
    dist[0] = 0;

    while (!pq.empty()) {
        p top = pq.top();
        int curr_cost = top.first, u = top.second;
        pq.pop();
        if (curr_cost > dist[u]) continue;

        for (Edge &e : graph[u]) {
            int next_u = e.to;
            int travel_cost = e.cost;

        
			// cout  << "explodes: " << e.explodes << " total cost: " << curr_cost + travel_cost << endl;
			// skip node if road explodes while on it
            if (e.explodes && curr_cost + travel_cost > T) continue;
				
            int next_cost = travel_cost + curr_cost;
            if (next_cost < dist[next_u]) {
                dist[next_u] = next_cost;
                pq.push(p(next_cost, next_u));
				// cout << "taking: " << next_u << " with cost: " << next_cost << endl;
            }
        }
    }
    return dist[N-1] == INT_MAX ? -1 : dist[N-1];
}

int main() {
    // Uncomment the following lines if you want to read/write from files
	// ifstream cin("input00.txt");
    // ofstream cout("output.txt");

    int N, M, T;
	
    cin >> N >> M >> T;

	graph.resize(N);
    int a, b, c, e;

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c >> e;
        graph[a].emplace_back(Edge(b, c, e == 1));
     
    }

    int res = dijkstra(N, T);

    cout << res << endl;

    return 0;
}

