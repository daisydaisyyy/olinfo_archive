template <typename T> T gcd(T a, T b, T& x, T& y) {
  if(b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  T d = gcd(b, a % b, x, y);
  x -= a / b * y;
  swap(x, y);
  return d;
}

