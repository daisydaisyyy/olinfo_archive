#include "geocomp.hpp"

/// An n-gon is represented by a vector P[0..n] of n+1 consecutive points, where P[0] = P[n].
template <typename T> bool point_in_polygon(Vector2D<T>& p, vector<Vector2D<T>>& polygon) {
  size_t n_vert = polygon.size();
  if(n_vert < 4) // At least a triangle
    return false;

  T angles_sum = T(0);
  for(size_t i = 0; i < n_vert - 1; ++i) {
    if(ccw(p, polygon[i], polygon[i + 1], true))
      angles_sum += angle(polygon[i] - p, polygon[i + 1] - p);
    else
      angles_sum -= angle(polygon[i] - p, polygon[i + 1] - p);
  }

  return fabs(fabs(angles_sum) / (2.0 * M_PI)) > T(EPS);
}
