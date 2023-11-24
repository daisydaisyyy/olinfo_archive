#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
constexpr int MOD = 1e9 + 7;

int main() {
    // uncomment the two following lines if you want to read/write from files
    //ifstream cin("input0.txt");
    // std::ofstream cout("output.txt");
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

    auto isValid = [&](int x, int y) { // is valid position
        return x >= 0 && x < R && y >= 0 && y < C && chessboard[x * C + y];
    };

    // dfs to find connected pieces
    auto dfs = [&](int v) {
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
                    if (isValid(i, j)) {
                        st.push_back(i * C + j);
                    }
                }

                for (int j = 0; j < C; ++j) {
                    int i = row;
                    if (isValid(i, j)) {
                        st.push_back(i * C + j);
                    }
                }

                for (int i = 0; i < R; ++i) {
                    int j = col + (i - row);
                    if (j >= 0 && j < C && isValid(i, j)) {
                        st.push_back(i * C + j);
                    }
                    j = col - (i - row);
                    if (j >= 0 && j < C && isValid(i, j)) {
                        st.push_back(i * C + j);
                    }
                }
            }
        }
    };

    auto find_comps = [&]() {
        fill(used.begin(), used.end(), false);
        for (int v = 0; v < R * C; ++v) {
            if (!used[v] && chessboard[v]) { // start dfs on every not visited node
                dfs(v);
                sol = (sol * 2) % MOD; // possible chessboard configurations (2**groups of connected pieces)
            }
        }   
    };

    find_comps();

    // if more pieces are connected, each group has 2 possible configurations (all rooks or bishops)
    // else, a piece not connected can be either rook and bishop

    cout << sol << endl;

    return 0;
}
