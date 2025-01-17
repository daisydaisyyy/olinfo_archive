#include <bits/stdc++.h>
#include "Graphs/kosaraju_scc.hpp"

using namespace std;

using u32 = uint32_t;

/// Returns assignment, empty -> not satisfiable
vector<bool> twosat(const vector<vector<u32>>& clauses) {
  u32 n = clauses.size();
  u32 terms = 0;
  for(const auto& c: clauses) {
    terms = max(terms, max(c[0] | 1, c[1] | 1) + 1);
  }

  vector<vector<size_t>> g(terms);
  vector<vector<size_t>> gT(terms);
  for(const auto& c: clauses) {
    g[c[0]^1].push_back(c[1]);
    gT[c[1]].push_back(c[0]^1);
    g[c[1]^1].push_back(c[0]);
    gT[c[0]].push_back(c[1]^1);
  }

  vector<u32> comp(terms);
  auto SCCs = kosaraju(g, gT);
  for(int c = 0; c < SCCs.size(); ++c) {
    for(const auto& t: SCCs[c]) {
      comp[t] = c;
    }
  }

  vector<bool> assignment(terms >> 1);
  for(u32 t = 0; t < terms; t += 2) {
    if(comp[t] == comp[t ^ 1])
      return vector<bool>();
    assignment[t >> 1] = comp[t] > comp[t ^ 1];
  }
  return assignment;
}
