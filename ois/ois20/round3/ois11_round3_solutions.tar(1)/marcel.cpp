/*
    Code by: Andrei Constantinescu (Andrei1998)
    O(N^4), iterative, less memory.
*/
#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000000 + 7;
inline void add(int& where, const int& val) {
    where += val;
    if (where >= MOD) {
        where -= MOD;
    }
}

const int NMAX = 120 + 1;

int N, X, mat[NMAX][NMAX];
int s_part[NMAX][NMAX];

inline int get_sum(int l1, int c1, int l2, int c2) {
    return s_part[l2][c2] - s_part[l1 - 1][c2] - s_part[l2][c1 - 1] + s_part[l1 - 1][c1 - 1];
}

int dp[2][NMAX][NMAX][NMAX]; // dp[l1][c1][l2][c2]

inline int dp_(const int& l1, const int& c1, const int& l2, const int& c2) {
    if (l1 > l2 || c1 > c2) {
        // We can always just do nothing.
        return 1;
    } else {
        return dp[l1 & 1][c1][l2][c2];
    }
}

int main() {
/*#ifndef INFOARENA
    freopen("data.in", "r", stdin);
    cerr << "Consumes " << sizeof(dp) / 1024.0 / 1024.0 << " MB." << endl;
#else
    freopen("marcel.in", "r", stdin);
    freopen("marcel.out", "w", stdout);
#endif // INFOARENA
*/
    cin >> N >> X;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> mat[i][j];
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            s_part[i][j] = mat[i][j] + s_part[i - 1][j] + s_part[i][j - 1] - s_part[i - 1][j - 1];
        }
    }

    for (int l1 = N; l1; --l1) {
        memset(dp[l1 & 1], 0, sizeof dp[l1 & 1]);
        for (int l2 = l1; l2 <= N; ++l2) {
            for (int c1 = N; c1; --c1) {
                for (int c2 = c1; c2 <= N; ++c2) {
                    // Do nothing.
                    dp[l1 & 1][c1][l2][c2] = 1;
                    // Increase l1.
                    if (get_sum(l1, c1, l1, c2) >= X) {
                        add(dp[l1 & 1][c1][l2][c2], dp_(l1 + 1, c1, l2, c2));
                    }
                    // Decrease l2.
                    if (get_sum(l2, c1, l2, c2) >= X) {
                        add(dp[l1 & 1][c1][l2][c2], dp_(l1, c1, l2 - 1, c2));
                    }
                    // Increase c1.
                    if (get_sum(l1, c1, l2, c1) >= X) {
                        add(dp[l1 & 1][c1][l2][c2], dp_(l1, c1 + 1, l2, c2));
                    }
                    // Decrease c2.
                    if (get_sum(l1, c2, l2, c2) >= X) {
                        add(dp[l1 & 1][c1][l2][c2], dp_(l1, c1, l2, c2 - 1));
                    }
                    // cerr << l1 << " " << l2 << " " << c1 << " " << c2 << " -> " << dp[l1 & 1][c1][l2][c2] << endl;
                }
            }
        }
    }
    cout << dp[1][1][N][N] << endl;
    return 0;
}
