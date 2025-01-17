#include <algorithm>

#define INF 2000000000

using namespace std;

// Assumption: the given graph is undirected.
// Assumption: being the graph small (no more than 16 nodes
// for acceptable runtime), the graph structure is given as
// adjacency matrix (e.g. usually a complete graph of nodes
// on a plane, having cartesian coordinates). In this case
// the adjacency matrix is named dist. When there is no
// connection between two nodes u and v, it is assumed that
// dist[u][v] = INF. Otherwise, if the graph is given as ad
// adjacency list (or other usual structure where the graph
// is not necessarily complete), you can check only the
// neighbours of pos. Another difference would be for the
// INF value, returned where there is no hamiltonian path
// from pos back to source.
template <typename C>
C tsp(size_t pos, size_t source, vector<vector<C>>& dist, size_t bitmask = 0) {
  if(bitmask == (1 << dist.size()) - 1)
    return dist[pos][source];

  C tsp_cost = INF;
  for(size_t next = 0; next < dist.size(); ++next) {
    if(next != pos && !(bitmask & (1 << next)) && dist[pos][next] < INF) {
      C next_tsp_cost = tsp(next, source, dist, bitmask | (1 << next));
      if(next_tsp_cost < INF)
        tsp_cost = min(tsp_cost, dist[pos][next] + next_tsp_cost);
    }
  }
  return tsp_cost;
}
