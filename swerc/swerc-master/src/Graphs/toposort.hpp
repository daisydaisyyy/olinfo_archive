#include <queue>
#include <stack>
#include <vector>

using namespace std;

/// Input must be a DAG

// Algorithm #1 (Tarjan), DFS-based
void toposort1(vector<vector<size_t>>& adj, vector<bool>& visited, size_t node,
               stack<size_t>& ans) {
  visited[node] = true;

  for(auto v : adj[node])
    if(!visited[v])
      toposort1(adj, visited, v, ans);

  ans.push(node);
}

// Algorithm #2 (Kahn's algorithm), BFS-based
void toposort2(vector<vector<size_t>>& adj, vector<size_t>& in_degree, size_t n,
               vector<size_t>& ans) {
  queue<size_t> q;
  vector<bool> visited(adj.size());
  size_t v;

  for(size_t i = 0; i < n; ++i)
    if(!in_degree[i])
      q.push(i);

  while(!q.empty()) {
    v = q.front(), q.pop();
    ans.push_back(v);

    for(auto u : adj[v])
      if(visited[u] || --in_degree[u])
        continue;
      else
        q.push(u), visited[u] = true;
  }
}
