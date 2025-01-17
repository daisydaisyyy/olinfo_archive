#include "Computational_Geometry/point_in_polygon.hpp"

using namespace std;

int main() {
  Vector2D<double> p = {5, 0.1};
  vector<Vector2D<double>> poly = {{0, 0}, {10, 0}, {10, 10}, {5, 15}, {0, 10}, {0, 0}};
  assert(point_in_polygon(p, poly) == 1);
  return 0;
}
