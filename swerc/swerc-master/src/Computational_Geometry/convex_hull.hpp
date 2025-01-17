#include "geocomp.hpp"

template <typename T>
vector<Vector2D<T>> convex_hull(vector<Vector2D<T>> points, bool keep_aligned_points = false) {
  sort(begin(points), end(points), [](auto& a, auto& b){ return tie(a.x, a.y) < tie(b.x, b.y); });
  vector<Vector2D<T>> hull;
  hull.reserve(points.size() + 1);
  for(int phase = 0; phase < 2; ++phase) {
    auto start = hull.size();
    for(auto& point : points) {
      while(hull.size() >= start + 2 && ccw(hull.back(), point, hull[hull.size() - 2], keep_aligned_points))
        hull.pop_back();
      hull.push_back(point);
    }
    hull.pop_back();
    reverse(begin(points), end(points));
  }
  if(hull.size() == 2 && hull[0] == hull[1])
    hull.pop_back();
  return hull;
}
