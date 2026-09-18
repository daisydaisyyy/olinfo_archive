#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> left(n), right(n);

        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[st.top()] <= a[i]) st.pop();
            st.push(i);
            left[i] = st.size();
        }

        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[st.top()] <= a[i]) st.pop();
            st.push(i);
            right[i] = st.size();
        }

        int ans = -1;
        for (int l = 0; l < n; l++) {
            int mx = 0;
            for (int r = l; r < n; r++) {
                // count visible from left in a[l..r]
                int visL = 1, m = a[l];
                for (int i = l + 1; i <= r; i++) if (a[i] > m) m = a[i], visL++;
                // count visible from right in a[l..r]
                int visR = 1; m = a[r];
                for (int i = r - 1; i >= l; i--) if (a[i] > m) m = a[i], visR++;

                if (visL == k1 && visR == k2) mx = max(mx, r - l + 1);
            }
            if (mx) ans = max(ans, mx);
        }
        cout << ans << '\n';
    }
}
