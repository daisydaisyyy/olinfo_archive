#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF_NEG = (ll)-9e18;

ll solve_orientation(const vector<ll>& a, int n, int k) {
    vector<ll> dp0(k+1, INF_NEG), dp1(k+1, INF_NEG);
    dp0[0] = 0;
    for (int idx = 0; idx < n; ++idx) {
        ll x = a[idx];
        // update dp1 (we must iterate backwards)
        for (int j = k-1; j >= 0; --j) {
            if (dp1[j] != INF_NEG) {
                dp1[j+1] = max(dp1[j+1], dp1[j] - x);
            }

            if (j >= 1 && dp0[j] != INF_NEG) {
                dp1[j+1] = max(dp1[j+1], dp0[j] - x);
            }
        }
        // update dp0 (backwards)
        for (int j = k-1; j >= 0; --j) {
            if (dp0[j] != INF_NEG) {
                dp0[j+1] = max(dp0[j+1], dp0[j] + x);
            }
        }
    }
    return dp1[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll ans1 = solve_orientation(a, n, k);

    for (int i = 0; i < n; ++i) a[i] = -a[i];
    ll ans2 = solve_orientation(a, n, k);

    cout << max(ans1, ans2) << "\n";
    return 0;
}
