/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <assert.h>
#include <stdio.h>

// constraints
#define MAXN 10000
#define MAXM 50000
#define MAXC 100

// input data
int N, M, C_0, a, b, c, i;
int P[MAXN];

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

  assert(3 == scanf("%d %d %d", &N, &M, &C_0));
  for (i = 0; i < N; i++) {
    assert(1 == scanf("%d", &P[i]));
  }
  for (i = 0; i < M; i++) {
    assert(3 == scanf("%d %d %d", &a, &b, &c));
    // TODO: going from a to b gains c coins
  }

  // insert your code here

  printf("%d\n", 42); // print the result
  return 0;
}
