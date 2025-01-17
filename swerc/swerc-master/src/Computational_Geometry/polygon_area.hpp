#include "geocomp.hpp"

/// An n-gon is represented by a vector P[0..n] of n+1 consecutive points, where P[0] = P[n].
template <typename T /* floating type */>
T polygon_area(vector<Vector2D<T>>& polygon) {
  T area = T(0);
  for(size_t i = 0; i < polygon.size(); ++i) {
    area += polygon[i] ^ polygon[i + 1];
  }
  return T(fabs(area)) / T(2);
}
