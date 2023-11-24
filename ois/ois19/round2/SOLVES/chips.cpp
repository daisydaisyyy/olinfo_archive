// Solution of chips
// Author: edomora97
// There are 3 possibile solutions, try each of them and choose the best one.

#include <assert.h>
#include <stdio.h>
#include <algorithm>

int main() {
  int T;
  assert(1 == scanf("%d", &T));
  while (T--) {
    auto score = [](int A, int C, int r, int g, int b) {
      return A * (r * r + g * g + b * b) + C * std::min(r, std::min(b, g));
    };
    int A, C, r, g, b;
    assert(5 == scanf("%d %d %d %d %d", &A, &C, &r, &g, &b));
    int red = score(A, C, r + 1, g, b);
    int green = score(A, C, r, g + 1, b);
    int blue = score(A, C, r, g, b + 1);
    int sol = std::max(red, std::max(green, blue));
    if (red == sol)
      printf("RED\n");
    else if (green == sol)
      printf("GREEN\n");
    else if (blue == sol)
      printf("BLUE\n");
  }
}
