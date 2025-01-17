#include "Computational_Geometry/polygon_area.hpp"

using namespace std;

int main() {
  vector<Vector2D<double>> poly = {{0, 0}, {10, 0}, {10, 10}, {5, 15}, {0, 10}, {0, 0}};
  assert(polygon_area(poly) == 125);
  return 0;
}
