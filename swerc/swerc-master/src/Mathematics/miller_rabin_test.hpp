template <class T> T mod_pow(T b, T e, T m) {
  T res = T(1);
  while(e) {
    if(e & T(1))
      res = smod(res * b, m);
    b = ((b * b) % m + m) % m, e >>= T(1);
  }
  return res;
}

// Check for a = 2,3,5,7,11,13,17,19,23,29,31,37,41 for
// deterministic variant (works with all 64-bit integers)
bool is_probable_prime(long long n, int k) {
  if(~n & 1)
    return n == 2;
  if(n <= 3)
    return n == 3;
  int s = 0;
  long long d = n - 1;
  while(~d & 1)
    d >>= 1, s++;
  while(k--) {
    long long a = (n - 3) * rand() / RAND_MAX + 2;
    long long x = mod_pow(a, d, n);
    if(x == 1 || x == n - 1)
      continue;
    bool ok = false;
    for(int i = 0; i < s - 1; ++i) {
      x = (x * x) % n;
      if(x == 1)
        return false;
      if(x == n - 1) {
        ok = true;
        break;
      }
    }
    if(!ok)
      return false;
  }
  return true;
}
