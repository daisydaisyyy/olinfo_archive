#include "Computational_Geometry/convex_hull.hpp"

using namespace std;

int main() {
  auto hull = convex_hull<double>({{0, 0}, {0, 4}, {1, 2}, {2, 4}, {2, 5}, {3, 0}, {3, 3}, {5, 1}, {5, 3}, {5, 4}, {7, 2}},
                true);

   vector<Vector2D<double>> ans = {
    Vector2D<double>(0.0, 0.0),
    Vector2D<double>(0.0, 4.0),
    Vector2D<double>(2.0, 5.0),
    Vector2D<double>(5.0, 4.0),
    Vector2D<double>(7.0, 2.0),
    Vector2D<double>(5.0, 1.0),
    Vector2D<double>(3.0, 0.0),
  };
  assert(hull.size() == ans.size());
  for (int i = 0; i < hull.size(); i++)
    assert(hull[i] == ans[i]);
  return 0;
}
