/*
 * Muffin's solution by edomora97
 * We need to find the _slice_ of size K of the vector that has the maximum
 * sum. With a _sliding window_ of size K it's possible to enumerate all the
 * possible slices, namely: [0, K-1], [1, K], ..., [N-K, N-1]
 * Knowing the sum of [i, i+K], it's easy to compute the sum of [i+1, i+K+1]:
 * sum[i, i+K] - T[i] + T[i+K+1]
 */
#include <algorithm>
#include <iostream>

#define MAXN 1000000

int T[MAXN];

int main() {
  int N, K, i;

  std::cin >> N >> K;
  for (i = 0; i < N; i++) std::cin >> T[i];

  int sol = 0;
  for (int i = 0; i < K; i++) sol += T[i];
  int current_sum = sol;
  for (int i = K; i < N; i++) {
    current_sum += T[i];
    current_sum -= T[i - K];
    sol = std::max(sol, current_sum);
  }

  std::cout << sol << std::endl;
  return 0;
}
