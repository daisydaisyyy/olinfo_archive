/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <assert.h>
#include <stdio.h>
#include <limits>
#include <vector>

using namespace std;

// constraints
#define MAXD 1000

// input data
int C, D, Y, i;
int M[MAXD + 1];
int P[MAXD + 1];

const int INF = numeric_limits<int>::max();

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

  assert(3 == scanf("%d %d %d", &C, &D, &Y));
  M[0] = 0;
  P[0] = 0;
  // warning! M and P are 1-based
  for (i = 1; i <= D; i++) assert(1 == scanf("%d", &M[i]));
  for (i = 1; i <= D; i++) assert(1 == scanf("%d", &P[i]));

  // calculate cumulative cost for i years
  vector<int> cumulative(D+1);
  for (int i = 1; i <= D; i++) {
      cumulative[i] = cumulative[i-1] + M[i];
  }
  for (int i = 1; i <= D; i++) {
      cumulative[i] += C;
      cumulative[i] -= P[i];
  }

  vector<int> DP(Y+1, INF);
  // only keep useful years
  vector<int> useful;
  DP[0] = 0;
  for (int i = 0; i <= D && i < Y; i++) {
      for (int j = 1; j <= D && i+j <= Y; j++) {
          DP[i+j] = min(DP[i+j], DP[i] + cumulative[j]);
      }

      if (DP[i] == cumulative[i]) {
          // This year is useful
          useful.push_back(i);
      }
  }

  // compute remaining years
  for (int i = D; i < Y; i++) {
      for (int j : useful) {
          if (i+j <= Y) {
              DP[i+j] = min(DP[i+j], DP[i] + cumulative[j]);
          }
      }
  }

  printf("%d\n", DP[Y]);  // print the result
  return 0;
}
