#include "Computational_Geometry/closest_pair.hpp"

using namespace std;

int main() {
  auto ans = closest_pair<double>({{0, 0}, {3, 0}, {3, 3}, {0, 4}, {5, 4}, {7, 2}});
  assert(ans.first.x == 3 && ans.first.y == 3 && ans.second.x == 5 && ans.second.y == 4);
  return 0;
}
