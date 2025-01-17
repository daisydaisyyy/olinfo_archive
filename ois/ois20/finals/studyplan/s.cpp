/*
 * Optimal solution for studyplan
 * Using DP on acyclic graph, it is calculated the minimum time at
 * which each subject can start. By using this it is calculate the time
 * of the end of the studyplan.
 * Using another DP it is calculated the delta from the end.
 *
 * Complexity: O(N+M)
 */

#include <assert.h>
#include <stdio.h>
#include <vector>

using namespace std;

// constraints
#define MAXN 100000

// input data
int N, i, j;
int H[MAXN];

vector<vector<int>> adj, rev;
vector<int> mint, delta_end;

int minTime(int x) {
    if (mint[x] != -1) {
        return mint[x];
    }
    mint[x] = 0;
    for (int v : rev[x]) {
        mint[x] = max(mint[x], minTime(v) + H[v]);
    }
    return mint[x];
}

int maxDeltaEnd(int x) {
    if (delta_end[x] != -1) {
        return delta_end[x];
    }
    delta_end[x] = H[x];
    for (int v : adj[x]) {
        delta_end[x] = max(delta_end[x], maxDeltaEnd(v) + H[x]);
    }
    return delta_end[x];
}

int main() {
  //  uncomment the following lines if you want to read/write from files
  freopen("input0.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

  assert(1 == scanf("%d", &N));
  adj.resize(N);
  rev.resize(N);
  for (i = 0; i < N; i++)
    assert(1 == scanf("%d", &H[i]));
  for (i = 0; i < N; i++) {
    int k;
    assert(1 == scanf("%d", &k));
    for (j = 0; j < k; j++) {
      int s;
      assert(1 == scanf("%d", &s));
      // TODO: process dependency s --> i
      adj[s].push_back(i);
      rev[i].push_back(s);
    }
  }

  // insert your code here

  int M = 0;
  mint.assign(N, -1);
  delta_end.assign(N, -1);
  for (int i = 0; i < N; i++) M = max(M, minTime(i) + H[i]);
  for (int i = 0; i < N; i++) {
      printf("%d ", M - maxDeltaEnd(i));
  }

  return 0;
}

