#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cost_col(n, vector<int>(n, 0));
    for (int k = 0; k < m; k++) {
        int i, j, a, b;
        cin >> i >> j >> a >> b;
        i--; j--;
        cost_col[j][i] = a;
        cost_col[i][j] = b;
    }

    vector<int> dp(1 << n, 2e9);
    dp[0] = 0;
    for (int s = 1; s < (1 << n); s++) {
        for (int j = 0; j < n; j++) {
            if (s & (1 << j)) {
                int s0 = s ^ (1 << j);
                int total = 0;
                int temp = s0;
                while (temp) {
                    int i = __builtin_ctz(temp);
                    total += cost_col[j][i];
                    temp -= temp & -temp;
                }
                if (dp[s] > dp[s0] + total) {
                    dp[s] = dp[s0] + total;
                }
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}