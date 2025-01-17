#include "geocomp.hpp"

template <typename T> pair<Vector2D<T>, Vector2D<T>> closest_pair(vector<Vector2D<T>> pts) {
  sort(pts.begin(), pts.end(), [](auto& a, auto& b){ return abs(a.x - b.x) > T(EPS) ? a.x < b.x : a.y < b.y; });
  auto cmpy = [](const Vector2D<T>& a, const Vector2D<T>& b){ return abs(a.y - b.y) > T(EPS) ? a.y < b.y : a.x < b.x; };
  auto cur = set<Vector2D<T>, decltype(cmpy)>(cmpy);

  T mn = INF<T>;
  pair<Vector2D<T>, Vector2D<T>> ans;
  for(int i = 0, l = 0; i < pts.size(); ++i) {
    while(pts[i].x - pts[l].x > mn)
      cur.erase(pts[l++]);
    auto it = cur.lower_bound({-INF<T>, pts[i].y - mn});
    auto jt = cur.upper_bound({INF<T>, pts[i].y + mn});
    while(it != jt) {
      auto dist = (*it - pts[i]).norm();
      if (dist < mn) {
        mn = dist;
        ans = {*it, pts[i]};
      }
      ++it;
    }
    cur.insert(pts[i]);
  }
  return ans;
}
