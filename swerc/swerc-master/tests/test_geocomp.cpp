#include "Computational_Geometry/geocomp.hpp"

using namespace std;

int main() {
  Vector2D<float> p(1, 2), c0(2, 1), d0(1, 1);
  assert(distancepl(p, c0, d0) - 1.41421 < 1e9);
  assert(angle(Vector2D<float>(3, 0), Vector2D<float>(0.5, 0.5)) - 0.785398 < 1e9);
  assert(ccw(Vector2D<float>(), c0, p) == 1);
  assert(ccw(Vector2D<float>(), p, c0) == 0);
  assert(ccw(Vector2D<float>(), p, p, true) == 0);
  return 0;
}
