#include <bits/stdc++.h>

using namespace std;

// s = p$t, matches = {i-|p|-1 >= 0 : z[i] == |p|}
vector<size_t> z_values(const string& s) {
  size_t n = s.size();
  vector<size_t> z(n);
  size_t l = 0, r = 0;
  z[0] = n; // usually not defined
  for(size_t i = 1; i < n; ++i) {
    if(i <= r)
      z[i] = min(z[i - l], r - i + 1);
    while(i + z[i] < n && s[z[i]] == s[i + z[i]])
      ++z[i];
    if(i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}
