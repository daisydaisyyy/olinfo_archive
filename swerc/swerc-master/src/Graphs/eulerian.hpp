#include <limits>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

using adjl_t = vector<unordered_map<size_t, bool>>; // (neighbour,
                                                    // taken)

const size_t NAN = numeric_limits<size_t>::max();

static void dfs(size_t node, adjl_t& adj, vector<bool>& visited) {
  visited[node] = true;
  for(auto& v : adj[node]) {
    size_t u = v.first;
    if(!visited[u])
      dfs(u, adj, visited);
  }
}

/// Returns true when graph described by adj is connected
/// Vertices with degree = 0 are excluded
/// The first vertex wth non-zero degree is written in node;
/// otherwise, node = 0.
static bool is_connected(adjl_t& adj, size_t& node) {
  vector<bool> visited(adj.size());
  node = 0;

  size_t src;
  for(src = 0; src < adj.size(); ++src) {
    if(adj[src].size() > 0)
      break;
  }

  // If there are no vertices with non-zero degree, the
  // graph is considered to be connected
  if(src == adj.size())
    return true;
  node = src;

  dfs(src, adj, visited);

  // After the DFS, if there exists a non-visited node with
  // non-zero degree, then the graph is not connected.
  // Otherwise, the graph is connected.
  for(src = 0; src < adj.size(); ++src) {
    if(!visited[src] && adj[src].size() > 0)
      return false;
  }
  return true;
}

/// Checks whether the undirected graph described by adj is
/// Eulerian or not. Returns:
///  0 The graph is not Eulerian
///  1 The graph has an Eulerian path (Semi-Eulerian)
///  2 The graph has an Eulerian cycle (Eulerian)
/// If graph is semi-Eulerian, the first-encountered
/// odd-degree node (if any) is written in node; if it is
/// Eulerian, the first-encountered node with non-zero
/// degree is written in node; otherwise, node = NAN.
size_t is_eulerian(adjl_t& adj, size_t& node) {
  if(!is_connected(adj, node))
    return 0;

  size_t odd_degree = 0, odd_node = NAN;
  for(size_t v = node; v < adj.size(); ++v) {
    if(adj[v].size() & 1) {
      ++odd_degree;
      if(odd_node == NAN)
        odd_node = v;
    }
  }
  if(odd_node != NAN)
    node = odd_node;

  return (odd_degree) ? ((odd_degree == 2) ? 1 : 0) : 2;
}

static void euler_path(size_t node, adjl_t& adj, list<size_t>& ans,
                       list<size_t>::iterator it) {
  for(auto& v : adj[node]) {
    if(v.second)
      continue;

    v.second = true;
    size_t next = v.first;
    auto x = adj[next].find(node);
    if(x == adj[next].end() || x->second)
      return;
    x->second = true;
    euler_path(next, adj, ans, ans.insert(it, next));
  }
}

/// If the graph is Eulerian (or semi-Eulerian), return the
/// vector of nodes which describes the Eulerian cycle (or
/// path). Otherwise, return an empty vector. The source
/// node is arbitrarily chosen.
list<size_t> euler(adjl_t& adj) {
  size_t src;
  list<size_t> euler;
  if(is_eulerian(adj, src)) {
    euler.insert(euler.begin(), src);
    euler_path(src, adj, euler, euler.begin());
  }
  return euler;
}
