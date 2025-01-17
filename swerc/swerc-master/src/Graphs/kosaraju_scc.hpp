#include <functional>
#include <stack>
#include <vector>

using namespace std;

/// The graph represented by adjacency list adj is directed.
/// Returns vector of SCCs, where an SCC is represented by a
/// vector of its nodes
vector<vector<size_t>> kosaraju(vector<vector<size_t>>& adj,
                                vector<vector<size_t>>& adjT) {
  vector<bool> visited(adj.size());
  vector<vector<size_t>> SCCs;
  stack<size_t> topo;

  function<void(size_t)> toposort = [&toposort, &adj, &visited,
                                     &topo](size_t u) {
    visited[u] = true;
    for(auto v : adj[u]) {
      if(!visited[v]) {
        toposort(v);
      }
    }
    topo.push(u);
  };

  function<vector<size_t>(size_t)> dfs = [&dfs, &adjT, &visited](size_t u) {
    visited[u] = true;
    vector<size_t> ans = {u};
    for(auto v : adjT[u]) {
      if(!visited[v]) {
        auto next_dfs = dfs(v);
        ans.insert(ans.end(), next_dfs.begin(), next_dfs.end());
      }
    }
    return ans;
  };

  for(size_t i = 0; i < adj.size(); ++i) {
    if(!visited[i]) {
      toposort(i);
    }
  }

  visited.assign(adj.size(), false);
  while(!topo.empty()) {
    auto v = topo.top();
    topo.pop();
    if(!visited[v]) {
      SCCs.push_back(dfs(v));
    }
  }

  return SCCs;
}
