/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <assert.h>
#include <stdio.h>

// constraints
#define MAXN 100000

// input data
int N, K, i;
int V[MAXN + 1];

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

  assert(2 == scanf("%d %d", &N, &K));
  for (i = 1; i <= N; i++) assert(1 == scanf("%d", &V[i]));

  // insert your code here
  //

  int p = 1, count = 0;
  while (p != K && V[p] != -1) {
      int old = p;
      p = V[p];
      V[old] = -1;
      count++;
  }

  printf("%d\n", (p == K ? count : -1));  // print the result
  return 0;
}
