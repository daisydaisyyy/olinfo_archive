#include <bits/stdc++.h>

using namespace std;

void test_sat(vector<vector<u32>> clauses, vector<bool> assignment, bool issat) {
  assert(assignment.empty() == !issat);
  if(!issat) return;
  for(const auto& c: clauses) {
    bool sat = false;
    for(const auto& t: c) {
      sat |= (t & 1) ? ~assignment[t >> 1] : assignment[t >> 1];
    }
    assert(sat);
  }
}
