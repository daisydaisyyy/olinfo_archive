// Modified DFS visit of the graph. At every step, keeps track whether this node
// has been reached in a "good" state (i.e., even number of edges) or not.
// At the end, it just counts vertices reached in a good state.

#include <iostream>
#include <vector>

std::vector< std::vector<int> > graph;
std::vector<bool> visited[2];

void dfs(int u, bool good) {
    visited[good][u] = true;
    for (auto v: graph[u])
        if (!visited[!good][v])
            dfs(v, !good);
}

int main() {
    int N, M;
    std::cin >> N >> M;
    visited[0].resize(N, false);
    visited[1].resize(N, false);
    graph.resize(N);
    int u, v;
    for (int i = 0; i < M; i++) {
        std::cin >> u >> v;
        graph[u].push_back(v);
    }
    dfs(0, true);

    int reachable = 0;
    for (int i = 0; i < N; i++)
        reachable += (visited[1][i] == true);

    std::cout << reachable << std::endl; 
    return 0;
}
