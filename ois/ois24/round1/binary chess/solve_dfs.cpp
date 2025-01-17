#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

constexpr int MOD = 1e9 + 7;
using namespace std;
bool isValid(int x, int y, int R, int C, const std::vector<bool>& chessboard) {
    return x >= 0 && x < R && y >= 0 && y < C && chessboard[x * C + y];
}

void dfs(int v, int R, int C, vector<bool>& used, vector<int>& st, const vector<bool>& chessboard) {
    st.push_back(v);

    while (!st.empty()) {
        int curr = st.back();
        st.pop_back();
        if (!used[curr]) {
            used[curr] = true;

            int row = curr / C;
            int col = curr % C;

            // check row, column, and diagonal
            for (int i = 0; i < R; ++i) {
                int j = col;
                if (isValid(i, j, R, C, chessboard)) {
                    st.push_back(i * C + j);
                }
            }

            for (int j = 0; j < C; ++j) {
                int i = row;
                if (isValid(i, j, R, C, chessboard)) {
                    st.push_back(i * C + j);
                }
            }

            for (int i = 0; i < R; ++i) {
                int j = col + (i - row);
                if (j >= 0 && j < C && isValid(i, j, R, C, chessboard)) {
                    st.push_back(i * C + j);
                }
                j = col - (i - row);
                if (j >= 0 && j < C && isValid(i, j, R, C, chessboard)) {
                    st.push_back(i * C + j);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	ifstream cin("input0.txt");

    int sol = 1;
    int R, C, N;
    cin >> R >> C >> N;

    vector<int> rr(N), cc(N);
    for (int i = 0; i < N; ++i)
        cin >> rr[i] >> cc[i];

    vector<bool> chessboard(R * C, false);
    vector<bool> used(R * C, false);
    vector<int> st;

    // build chessboard
    for (int i = 0; i < N; ++i) {
        int r = rr[i] - 1;
        int c = cc[i] - 1;
        chessboard[r * C + c] = true; // mark as occupied
    }

    for (int v = 0; v < R * C; ++v) {
        if (!used[v] && chessboard[v]) { // start dfs on every not visited node
            dfs(v, R, C, used, st, chessboard);
            sol = (sol << 1) % MOD; // calculate powers of 2 modulo MOD
        }
    }

    cout << sol << "\n";

    return 0;
}
