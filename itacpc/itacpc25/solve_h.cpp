#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, k;
    cin >> m >> k;
    string n;
    cin >> n;

    vector<int> pw(m);
    pw[m - 1] = 1 % k;
    for (int i = m - 2; i >= 0; --i)
        pw[i] = (1LL * pw[i + 1] * 10) % k;

    int base = 0;
    for (int i = 0; i < m; ++i)
        base = (base + 1LL * (n[i] - '0') * pw[i]) % k;

    unordered_map<int, string> seen;
    seen.reserve(200000);
    seen.max_load_factor(0.7);

    string s = n;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(0, m - 1);

    for (int tries = 0; tries < 3000; ++tries) {
        int i = dist(rng), j = dist(rng);
        if (i == j) continue;
        swap(s[i], s[j]);
        if (s[0] == '0') { swap(s[i], s[j]); continue; }

        int modv = 0;
        for (int t = 0; t < m; ++t)
            modv = (modv + 1LL * (s[t] - '0') * pw[t]) % k;

        if (seen.count(modv)) {
            if (seen[modv] != s) {
                cout << seen[modv] << "\n" << s << "\n";
                return 0;
            }
        } else seen[modv] = s;
        swap(s[i], s[j]);
    }

    cout << -1 << "\n";
}
