// insert brief description of the solution here

#include <assert.h>
#include <stdio.h>

// input data
long long R, C, K;

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

  assert(3 == scanf("%lld %lld %lld", &R, &C, &K));
  printf("%lld\n", ((R + K - 1) / K) * ((C + K - 1) / K));
  return 0;
}
