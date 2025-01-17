#include <bits/stdc++.h>

using namespace std;

template <typename T> constexpr T INF = numeric_limits<T>::max();
constexpr double EPS = 1e-6;

template <typename T>
class Vector2D {
public:
  T x, y;

  Vector2D() {
    x = y = 0;
  }

  Vector2D(T _x, T _y): x(_x), y(_y) {}

  T norm() const {
    return hypot(x, y);
  }

  void normalize() {
    T d = norm();
    x /= d;
    y /= d;
  }

  T operator*(const Vector2D<T>& o) const {
    return x * o.x + y * o.y;
  }

  Vector2D<T> operator*(const T& o) const {
    return {x * o, y * o};
  }

  Vector2D<T> operator/(const T& o) const {
    return {x / o, y / o};
  }

  T operator^(const Vector2D<T>& o) const {
    return x * o.y - y * o.x;
  }

  Vector2D<T> normalized() const {
    auto v = *this;
    v.normalize();
    return v;
  }

  Vector2D<T> operator+(const Vector2D<T>& o) const {
    return {x + o.x, y + o.y};
  }

  Vector2D<T> operator-(const Vector2D<T>& o) const {
    return {x - o.x, y - o.y};
  }

  T phase() const {
    return atan2(y, x);
  }

  Vector2D<T> rotated(T rad) {
    return {x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)};
  }

  void rotate(T rad) {
    *this = rotated(rad);
  }

  bool operator==(const Vector2D<T>& o) const {
    return (*this - o).norm() <= T(EPS);
  }

  bool operator!=(const Vector2D<T>& o) const {
    return !(*this == o);
  }
};

template<typename T> T distancepp(const Vector2D<T>& a, const Vector2D<T>& b) {
  return (a - b).norm();
}

template<typename T> T distancepl(const Vector2D<T>& p, const Vector2D<T>& c0, const Vector2D<T>& d0) {
  auto p0 = p - c0;
  auto d0n = d0.normalized();
  auto offset = p0 * d0n;
  auto proj = d0n * offset;
  return (p0 - proj).norm();
}

template<typename T> T angle(const Vector2D<T>& a, const Vector2D<T>& b) {
  return acos((a * b) / (a.norm() * b.norm()));
}

template<typename T> bool ccw(const Vector2D<T>& o, const Vector2D<T>& a, const Vector2D<T>& b, bool strict = false) {
  auto v = (a - o) ^ (b - o);
  return strict ? (v > T(0)) : (v >= T(0));
}
